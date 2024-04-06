#include "script_component.hpp"

class CfgPatches {
	class ADDON	{
		name = COMPONENT_NAME;
		requiredVersion = REQUIRED_VERSION;
		units[] = { };
		weapons[] = {
			"RAT_Empty_bloodIV_500",
			"RAT_Empty_bloodIV_250"
		};
		magazines[] = { };
		requiredAddons[] = {
			"rat_main",
			"ace_medical",
			"ace_medical_ai",
			"ace_medical_blood",
			"ace_medical_damage",
			"ace_medical_engine",
			"ace_medical_feedback",
			"ace_medical_gui",
			"ace_medical_statemachine",
			"ace_medical_status",
			"ace_medical_treatment",
			"ace_medical_vitals",
			"ace_dogtags",
			"cba_settings"
		};
		author = "Katalam, (Modified by Rat)";
		authors[] = {"Katalam, (Modified by Rat)"};
		url = ECSTRING(main,URL);
		VERSION_CONFIG;
	};
};

#include "CfgFunctions.hpp"
#include "CfgMoves.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
#include "ACE_Medical_Treatment_Actions.hpp"
