//mef_inv_cam_update_heading


//constants for the gui
#include "\vbs2\customer\people\mef_invisible_camera\data\scripts\mef_inv_cam_projectdefines.hpp"
#include "\vbs2\customer\people\mef_invisible_camera\data\scripts\mef_inv_cam_defines.hpp"

//development variables
#ifdef MEF_INV_CAM_USE_MISSION_SCRIPTS
	_projectDataFolder = "P:\vbs2\customer\people\mef_invisible_camera\data\";
#else
	_projectDataFolder = "\vbs2\customer\people\mef_invisible_camera\data\";
#endif


//init variables
_display = MEF_INV_CAM_HUD;
_ctrlHeight = 0.015;
_ctrlLine_scPos_y = 0.934;

_dirto_left_edge = 0;
_startDir = 0;
MEF_INV_CAM_LINES_OLD = 300;
_wantedDir = 0;


//get screen FOV
_cam_fov_deg = MEF_INV_CAM_FOV;	//deg
_total_fov_deg = _cam_fov_deg +10;	//deg
_total_fov_mils = _total_fov_deg * DEGREES_TO_MILS; //mils

//get cam dir
_cam_Array = [TRUE] call fn_vbs_getCameraDir;
_camDir_deg = _cam_Array select 0;   //deg grid

//compensate if GM angle is used.
if (MEF_INV_CAM_DIR_TYPE == "Mag") then
{
	_camDir_deg = _camDir_deg - getDeclination;  //mag direction
};

//calculate direction to left edge
_dirto_left_edge_deg = _camDir_deg - (_total_fov_deg/2); //deg
_dirto_left_edge_deg = [_dirto_left_edge_deg] call fn_vbs_wrapAngle; //deg

//find nearest value in degrees or mils and determine number of lines to draw
if (MEF_INV_CAM_DIR_UNITS == "Mils") then
{
	//calculate nearest mils
	_dirto_left_edge = _dirto_left_edge_deg * DEGREES_TO_MILS; //mils

	//find nearest value 
	_startDir = (round (_dirto_left_edge/MEF_INV_CAM_NEAR_VAL))*MEF_INV_CAM_NEAR_VAL;  //mils
	_total_fov = _total_fov_mils+(_dirto_left_edge - _startDir);  //mils
	
	//calculate lines to update
	MEF_INV_CAM_LINES_NEW = round (_total_fov/MEF_INV_CAM_TAPE_INTERVAL);
}
else
{
	//calculate nearest deg
	_dirto_left_edge = _dirto_left_edge_deg;

	//find nearest value 
	_startDir = (round (_dirto_left_edge/5))*5;  //deg
	_total_fov = _total_fov_deg+(_dirto_left_edge - _startDir);  //deg
	
	//calculate lines to update
	MEF_INV_CAM_LINES_NEW = round (_total_fov/MEF_INV_CAM_TAPE_INTERVAL);
};


//calculate world position
_camPos = getPos VBS_CAMERA;

//update lines
for "_i" from 0 to MEF_INV_CAM_LINES_NEW do
{
	//baller script to get ctrl dynamically!
	_ctrlLine = MEF_INV_CAM_HUD call compile format ["_this displayCtrl %1", _i + 12000];  
	
	_ctrlLine ctrlShow TRUE;
	
	//this direction will be displayed
	_outputDir = _startDir+(_i*MEF_INV_CAM_TAPE_INTERVAL);  
	
	//calculate direction at each interval
	if (MEF_INV_CAM_TAPE_INTERVAL == 10) then
	{
		//direction is in mils, convert to degrees for math step
		_wantedDir = (_startDir+(_i*MEF_INV_CAM_TAPE_INTERVAL))*MILS_TO_DEGREES;
	}
	else
	{
		//degrees
		_wantedDir = _startDir+(_i*MEF_INV_CAM_TAPE_INTERVAL);
	};

	//account for GM angle
	if (MEF_INV_CAM_DIR_TYPE == "Mag") then
	{
		_wantedDir = _wantedDir + getDeclination;  //mag direction
	};
	
	//calculate world position	
	_pos = [_camPos, MEF_INV_CAM_DIS, _wantedDir] call fn_vbs_relPos;

	//calculate screen position
	_scPos_Array = worldToScreen (_pos);
	_ctrlText_scPos = +_scPos_Array;
	
	//only execute if screen pos is returned
	if ((count _scPos_Array)>0) then
	{
		//adjust height
		//major  h=0.035;		100 mils
		//minor  h=0.025;		50 mils
		//inc  h=0.015;		10 mils
		
		if (MEF_INV_CAM_TAPE_INTERVAL == 10) then
		{
			//mils
			if ((_outputDir % 100)==0) then 
			{
				//value is multiple of 100 mils, set line height
				_ctrlHeight = 0.035;
				_ctrlLine_scPos_y = 0.934;
				
				//update text control position and text
				[_outputDir,_ctrlText_scPos, _i, 0] call fn_inv_cam_line_setPos;  //0=maj, 1= min
			}
			elseif ((_outputDir % 50)==0) then
			{
				//value is multiple of 50 mils, set line height
				_ctrlHeight = 0.025;	
				_ctrlLine_scPos_y = 0.939;
				
				//update text control position and text
				[_outputDir,_ctrlText_scPos, _i, 1] call fn_inv_cam_line_setPos;  //0=maj, 1= min
			}
			else
			{
				//default line height
				_ctrlHeight = 0.015;
				_ctrlLine_scPos_y = 0.943;
			};		
		}
		else
		{
			//deg
			if ((_outputDir % 10)==0) then 
			{
				//value is multiple of 10 degrees, set line height
				_ctrlHeight = 0.035;
				_ctrlLine_scPos_y = 0.934;
				
				//update text control position and text
				[_outputDir,_ctrlText_scPos, _i, 0] call fn_inv_cam_line_setPos;  //0=maj, 1= min
			}
			elseif ((_outputDir % 5)==0) then
			{
				//value is multiple of 5 degrees, set line height
				_ctrlHeight = 0.025;	
				_ctrlLine_scPos_y = 0.939;
				
				//update text control position and text
				[_outputDir,_ctrlText_scPos, _i, 1] call fn_inv_cam_line_setPos;  //0=maj, 1= min
			}
			else
			{
				//default line height
				_ctrlHeight = 0.015;
				_ctrlLine_scPos_y = 0.943;
			};	
		};
		
		//resave array into new variable
		_ctrlLine_scPos = +_scPos_Array;

		_ctrlLine_scPos set [1, _ctrlLine_scPos_y]; //force y value
		
		//add width and height to line position array
		_ctrlLine_scPos set [2, 0]; //width
		_ctrlLine_scPos set [3, _ctrlHeight]; //height
		
		//commit changes
		_ctrlLine ctrlSetPosition _ctrlLine_scPos;
		_ctrlLine ctrlCommit 0;

		waitUntil {ctrlCommitted _ctrlLine};
	};
};

if (MEF_INV_CAM_LINES_NEW < MEF_INV_CAM_LINES_OLD) then
{
	for "_i" from (MEF_INV_CAM_LINES_NEW+1) to MEF_INV_CAM_LINES_OLD do
	{
		_ctrlText = MEF_INV_CAM_HUD call compile format ["_this displayCtrl %1", _i+11000];  
		_ctrlLine = MEF_INV_CAM_HUD call compile format ["_this displayCtrl %1", _i+12000];
		
		{_x ctrlShow FALSE} forEach [_ctrlText, _ctrlLine];
	};
};






















