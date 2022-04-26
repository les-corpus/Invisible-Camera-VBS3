//always include the defines common to all configs at the top of the file
#include "\vbs2\basic_defines.hpp"
#include "\vbs2\ui\external_UI_include.h"
#include "\vbs2\people\people_defines.hpp"

//--------------------------------------------------------------------
//constants for the invisible camera
#include "\vbs2\customer\people\mef_invisible_camera\data\scripts\mef_inv_cam_projectdefines.hpp"
#include "\vbs2\customer\people\mef_invisible_camera\data\scripts\mef_inv_cam_defines.hpp"

//development variables
#ifdef MEF_INV_CAM_USE_MISSION_SCRIPTS
	__EXEC(_projectDataFolder = "P:\vbs2\customer\people\mef_invisible_camera\data\");
#else
	__EXEC(_projectDataFolder = "\vbs2\customer\people\mef_invisible_camera\data\");
#endif

//always change this to be the path (without drive) to the directory you are working in!
#define __CurrentDir__ \vbs2\customer\people\mef_invisible_camera


class CfgPatches									// Super class declaration, this is an addon.
{
	class mef_invisible_camera								// Define the class name with the same name as the addon folder.
	{
		units[]            = {};
		weapons[]          = {};
		requiredVersion    = 2.00; 					// Requires VBS2 2.0
		requiredAddons[]   = 
		{
			
		};									//required addons to use to load before this addon
	};
};

//--------------------------------------------------------------------

//this is the heading tape at the bottom of the screen
class RscTitles
{
	#include "\vbs2\customer\people\mef_invisible_camera\data\scripts\mef_inv_cam_heading_tape.hpp"
};


//tell simulation we are creating categories for the listing of objects in the editor
class CfgVehicleClasses
{
	class mef_custom_models                     	// Class name for this category, which is referenced later in the config.
	{
		displayname = "[I MEF] Models";    			// Display name for this category that shows up in editor.
	};
};

class CfgVehicles
{
	class vbs2_invisible_man_adminCamera;
	
	//*****************************************************************************
	//config entry for Artillery Rockets Mortar Naval Gunfire Interface Tool
	
	class mef_invisible_man_adminCamera : vbs2_invisible_man_adminCamera
	{
		vehicleClass="mef_custom_models";
		displayName="Invisible Camera w/Heading Tape v19.08.23";
		preview =	__CurrentDir__\data\ico\preview_mef_invisible_camera_ca;  //image in object properties
		side=1;		//bluefor
	
		//execute script on mission start
		class eventhandlers
		{	
			init = __EVAL("_this execVM '"+_projectDataFolder+"scripts\mef_inv_cam_showHeadingTape.sqf'");
		};
	};
};








