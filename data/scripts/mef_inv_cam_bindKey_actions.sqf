//mef_inv_cam_bindKey_actions


//key codes
#include "\vbs2\headers\dikCodes.hpp"

//special defines
#include "\vbs2\customer\people\mef_invisible_camera\data\scripts\mef_inv_cam_projectdefines.hpp"
#include "\vbs2\customer\people\mef_invisible_camera\data\scripts\mef_inv_cam_defines.hpp"


//to quickly change from packed addon or P: drive
#ifdef MEF_INV_CAM_USE_MISSION_SCRIPTS
	_projectDataFolder = "P:\vbs2\customer\people\mef_invisible_camera\data\";
#else
	_projectDataFolder = "\vbs2\customer\people\mef_invisible_camera\data\";
#endif


//allow bindkey if no VBS menus open
if ((applicationState select 1) in ["MISSION", "OME_PREVIEW"]) then
{
	_bindKey = _this select 0;

	switch (_bindKey) do
	{
		case "DIK_J":
		{
			//future use
		};
		
		case "DIK_K":
		{
			//future use
		};
		
		case "DIK_L":
		{
			//toggle center line
			if (isNil "MEF_INV_CAM_HIDE_HUD")then
			{
				MEF_INV_CAM_HIDE_HUD = TRUE;
			}
			else
			{
				MEF_INV_CAM_HIDE_HUD = nil;
			};
			
		};
		case "DIK_1":
		{
			//decrease FOV
			if (MEF_INV_CAM_FOV > 5) then
			{
				MEF_INV_CAM_FOV = MEF_INV_CAM_FOV -5;
			
				setCamFrustum [true, tan (MEF_INV_CAM_FOV/2)];	

				[MEF_INV_CAM_FOV_MSG,2000] diagMessage format["FOV = %1 deg || -%2 to +%2",MEF_INV_CAM_FOV, MEF_INV_CAM_FOV/2];				
			}
			else
			{
				[MEF_INV_CAM_FOV_MSG,2000] diagMessage format["Min FOV = %1 deg || -%2 to +%2",MEF_INV_CAM_FOV, MEF_INV_CAM_FOV/2];	
			};
		};
		case "DIK_2":
		{
			//increase FOV
			if (MEF_INV_CAM_FOV < 170) then
			{
				MEF_INV_CAM_FOV = MEF_INV_CAM_FOV +5;
				
				setCamFrustum [true, tan (MEF_INV_CAM_FOV/2)]	;	
				
				[MEF_INV_CAM_FOV_MSG,2000] diagMessage format["FOV = %1 deg || -%2 to +%2",MEF_INV_CAM_FOV, MEF_INV_CAM_FOV/2];				
			}
			else
			{
				[MEF_INV_CAM_FOV_MSG,2000] diagMessage format["Max FOV = %1 deg || -%2 to +%2",MEF_INV_CAM_FOV, MEF_INV_CAM_FOV/2];
			};
		};
		case "DIK_3":
		{
			//default FOV
			
			setCamFrustum [false];
			sleep .01;
			
			[] call fn_inv_cam_getCamFrustrum;
			
			[MEF_INV_CAM_FOV_MSG,2000] diagMessage format["FOV = %1 deg || -%2 to +%2",MEF_INV_CAM_FOV, MEF_INV_CAM_FOV/2];	
		};
		case "DIK_4":
		{
			//default toggle mils and degrees
			_ctrl_tapeSettings = MEF_INV_CAM_HUD displayCtrl IDC_TAPE_SETTINGS;
			
			if (MEF_INV_CAM_DIR_UNITS == "Mils") then
			{
				//degrees
				MEF_INV_CAM_DIR_UNITS = "Degs";
				MEF_INV_CAM_TAPE_INTERVAL = 1;		//draw tick mark at each value
				
				_ctrl_tapeSettings ctrlSetText format ["Degs %1", MEF_INV_CAM_DIR_TYPE];
			}
			else
			{
				//mils
				MEF_INV_CAM_DIR_UNITS = "Mils";
				MEF_INV_CAM_TAPE_INTERVAL = 10;  //draw tick mark at each value
				
				_ctrl_tapeSettings ctrlSetText format ["Mils %1", MEF_INV_CAM_DIR_TYPE];
			};
			
			

		};
		case "DIK_5":
		{
			//default toggle mag and grid
			
			_ctrl_tapeSettings = MEF_INV_CAM_HUD displayCtrl IDC_TAPE_SETTINGS;
			
			if (MEF_INV_CAM_DIR_TYPE == "Grid") then
			{
				//mag direction
				MEF_INV_CAM_DIR_TYPE = "Mag";
				
				_ctrl_tapeSettings ctrlSetText format ["%1 Mag", MEF_INV_CAM_DIR_UNITS];
			}
			else
			{
				//grid direction
				MEF_INV_CAM_DIR_TYPE = "Grid";
				
				_ctrl_tapeSettings ctrlSetText format ["%1 Grid", MEF_INV_CAM_DIR_UNITS];
			};
		};
	};
};







