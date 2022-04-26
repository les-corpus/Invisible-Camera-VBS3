

//function library


//constants for the gui
#include "\vbs2\customer\people\mef_invisible_camera\data\scripts\mef_inv_cam_projectdefines.hpp"
#include "\vbs2\customer\people\mef_invisible_camera\data\scripts\mef_inv_cam_defines.hpp"

//development variables
#ifdef MEF_INV_CAM_USE_MISSION_SCRIPTS
	_projectDataFolder = "P:\vbs2\customer\people\mef_invisible_camera\data\";
#else
	_projectDataFolder = "\vbs2\customer\people\mef_invisible_camera\data\";
#endif


fn_inv_cam_line_setPos = 
{
	//update text controls position and text
	
	private ["_output", "_ctrlText_scPos", "_i", "_type", "_y_pos", "_ctrlText", "_scPos_X"];
	//passed array [_output,_ctrlText_scPos, _i, 0]
	
	//update tick mark
	_output = _this select 0;
	_ctrlText_scPos = _this select 1;
	_i = _this select 2;
	_type = _this select 3;

	//check for wrap around
	if (MEF_INV_CAM_DIR_UNITS == "Mils") then
	{
		//mils
		if (_output > 6400) then
		{
			_output = _output - 6400;
		};
	}
	else
	{
		//degrees
		if (_output > 360) then
		{
			_output = _output - 360;
		};
	};
	
	_y_pos = if (_type == 0) then {MEF_INV_CAM_MAJ_Y_POS} else {MEF_INV_CAM_MIN_Y_POS};

	//find and update text ctrl
	_ctrlText = MEF_INV_CAM_HUD call compile format ["_this displayCtrl %1", _i+11000];  
	_ctrlText ctrlShow TRUE;
	_ctrlText ctrlSetText format ["%1", _output];

	
	//find ctrl position
	_scPos_X = _ctrlText_scPos select 0;
	_scPos_X = _scPos_X - (MEF_INV_CAM_W/2);
	
	//set X and Y pos
	_ctrlText_scPos set [0, _scPos_X]; 
	_ctrlText_scPos set [1, _y_pos]; //force Y
	
	_ctrlText ctrlSetPosition _ctrlText_scPos;
	_ctrlText ctrlCommit 0;
};

fn_inv_cam_getCamFrustrum =
{
	//determine field of view based on aspect ratio
	private ["_camFrustrum", "_camFrustrum_FOV", "_camFrustrum_FOV_deg", "_init_camFrustrum_FOV_deg"];
	_camFrustrum = camFrustum;
	_camFrustrum_FOV= _camFrustrum select 1;
	_camFrustrum_FOV_deg = (atan (_camFrustrum_FOV))*2;
	
	_init_camFrustrum_FOV_deg = (round (_camFrustrum_FOV_deg/5))*5;  //nearest 5 deg
	
	MEF_INV_CAM_FOV = _init_camFrustrum_FOV_deg;
};

/*
fn_inv_cam_hideAllCtrls =
{
	//different FOV, hide all the controls
	private ["_ctrlText", "_ctrlLine", "_x"];
	
	for "_i" from 0 to 300 do
	{
		_ctrlText = MEF_INV_CAM_HUD call compile format ["_this displayCtrl %1", _i+11000];  
		_ctrlLine = MEF_INV_CAM_HUD call compile format ["_this displayCtrl %1", _i+12000];
		
		{_x ctrlShow FALSE} forEach [_ctrlText, _ctrlLine];
	};
};
*/





















