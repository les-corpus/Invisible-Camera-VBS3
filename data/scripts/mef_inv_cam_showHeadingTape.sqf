
//show heading tape for custom mef unit

//key codes
#include "\vbs2\headers\dikCodes.hpp"

//special defines
#include "\vbs2\customer\people\mef_invisible_camera\data\scripts\mef_inv_cam_projectdefines.hpp"
#include "\vbs2\customer\people\mef_invisible_camera\data\scripts\mef_inv_cam_defines.hpp"

#ifdef MEF_INV_CAM_USE_MISSION_SCRIPTS
	_projectDataFolder = "P:\vbs2\customer\people\mef_invisible_camera\data\";
#else
	_projectDataFolder = "\vbs2\customer\people\mef_invisible_camera\data\";
#endif


//wait for mission to start
waitUntil {applicationState select 0 && (applicationState select 1) != "OME"};

//passed from eventhandlers init
_unit = _this select 0;
_unit allowDammage FALSE;

//wait for player to join unit
waitUntil
{
	sleep .1;

	isPlayer _unit
};

//execute where local
if (local _unit) then
{
	//load function library
	_fn_library = [] execVM format ["%1scripts\mef_inv_cam_fn_library.sqf", _projectDataFolder];

	//future use
	//KEYID_J = DIK_J bindKey format ["nul = ['DIK_J'] execVM '%1scripts\mef_inv_cam_bindKey_actions.sqf'", _projectDataFolder];
	//KEYID_K = DIK_K bindKey format ["nul = ['DIK_K'] execVM '%1scripts\mef_inv_cam_bindKey_actions.sqf'", _projectDataFolder];	

	//toggle center line
	KEYID_L = DIK_L bindKey format ["nul = ['DIK_L'] execVM '%1scripts\mef_inv_cam_bindKey_actions.sqf'", _projectDataFolder];	

	//set FOV
	KEYID_1 = DIK_1 bindKey format ["nul = ['DIK_1'] execVM '%1scripts\mef_inv_cam_bindKey_actions.sqf'", _projectDataFolder];
	KEYID_2 = DIK_2 bindKey format ["nul = ['DIK_2'] execVM '%1scripts\mef_inv_cam_bindKey_actions.sqf'", _projectDataFolder];
	KEYID_3 = DIK_3 bindKey format ["nul = ['DIK_3'] execVM '%1scripts\mef_inv_cam_bindKey_actions.sqf'", _projectDataFolder];
	
	//toggle deg or mils, grid or mag
	KEYID_4 = DIK_4 bindKey format ["nul = ['DIK_4'] execVM '%1scripts\mef_inv_cam_bindKey_actions.sqf'", _projectDataFolder];
	KEYID_5 = DIK_5 bindKey format ["nul = ['DIK_5'] execVM '%1scripts\mef_inv_cam_bindKey_actions.sqf'", _projectDataFolder];
	
	//init variables
	MEF_INV_CAM_DIS = 2000;	//distance to calculate heading tape
	MEF_INV_CAM_TAPE_INTERVAL = 10;		//increment each 10 mils
	
	if (isNil "MEF_INV_CAM_DIR_UNITS") then
	{
		MEF_INV_CAM_DIR_UNITS = "Mils";	
	};
	if (isNil "MEF_INV_CAM_DIR_TYPE") then
	{
		MEF_INV_CAM_DIR_TYPE = "Grid"; //0= grid, getDeclination = mag
	};	
	
	//ghetto way to start the camera from the action menu
	DIK_LBRACKET setAction 1;
	sleep .1;
	DIK_LBRACKET setAction 1;
	sleep .1;
	DIK_RETURN setAction 1;

	//show tape and wait for cam to start
	cutRsc["MEF_INV_CAM_HEADING_TAPE", "PLAIN"];
	
	waitUntil
	{
		sleep .1;
		!(isNil "VBS_CAMERA")
	};

	//get current field of view
	[] call fn_inv_cam_getCamFrustrum;
	
	MEF_INV_CAM_FOV_MSG = [-1,2000] diagMessage format["FOV = %1 deg || -%2 to +%2",MEF_INV_CAM_FOV, MEF_INV_CAM_FOV/2];			
	
	//display settings
	_ctrl_tapeSettings = MEF_INV_CAM_HUD displayCtrl IDC_TAPE_SETTINGS;
	_ctrl_tapeSettings ctrlSetText format ["%1 %2", MEF_INV_CAM_DIR_UNITS, MEF_INV_CAM_DIR_TYPE];

	//get controls and hide grid
	_display = MEF_INV_CAM_HUD;
	_ctrl_array = [];

	//find all ctrls
	for "_i" from 0 to 11 do
	{
		_ctrlLine = _display call compile format ["_this displayCtrl %1", _i + IDC_CENTER_LINE];
		_ctrlLine ctrlShow FALSE;
		_ctrl_array = _ctrl_array + [_ctrlLine];
	};

	DIK_L setAction 1;  //hide center circle

	while {isPlayer _unit} do
	{
		//update the heading tape
		nul = [] execVM (_projectDataFolder + "scripts\mef_inv_cam_update_heading.sqf");
		
		//show hide grid
		if (isNil "MEF_INV_CAM_HIDE_HUD") then
		{
			{_x ctrlShow FALSE} forEach _ctrl_array;
		}
		else
		{
			{_x ctrlShow TRUE} forEach _ctrl_array;
		};
		
		//player opened RTE
		if (!((applicationState select 1) in ["MISSION", "OME_PREVIEW"])) then
		{
			//wait for the the mission to continue
			waitUntil {sleep .1; (applicationState select 1) in ["MISSION", "OME_PREVIEW"]};
			
			//reload the hud
			cutRsc["MEF_INV_CAM_HEADING_TAPE", "PLAIN"];
			
			//reassign controls
			_display = MEF_INV_CAM_HUD;
			for "_i" from 0 to 11 do
			{
				_ctrlLine = _display call compile format ["_this displayCtrl %1", _i + IDC_CENTER_LINE];
				_ctrl_array = _ctrl_array + [_ctrlLine];
			};
			
				//display settings
			_ctrl_tapeSettings = MEF_INV_CAM_HUD displayCtrl IDC_TAPE_SETTINGS;
			_ctrl_tapeSettings ctrlSetText format ["%1 %2", MEF_INV_CAM_DIR_UNITS, MEF_INV_CAM_DIR_TYPE];
		};	
		
		sleep .01;
	};

	[-1,5000] diagMessage "heading tape stopped";
	cutRsc["default", "PLAIN"];
};
	
	
	
	
	
	
	
	
	
	