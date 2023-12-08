#include "script_component.hpp"


class CfgPatches {
	class ADDON {
		name = COMPONENT_NAME;
		units[] = {};
		weapons[] = {};
		requiredVersion = REQUIRED_VERSION;
		requiredAddons[] = {
			"A3_Data_F_Tank_Loadorder",
			"cba_main",
			"ace_main"
		};
		author = "Katalam (Modified by Rat)";
		url = CSTRING(URL);
		VERSION_CONFIG;
	};
};

class CfgMods {
	class PREFIX {
		dir = "@rat_aceAdvMedical";
		name = "RAT - Advancedish Medical";
		picture = "A3\Ui_f\data\Logos\arma3_expansion_alpha_ca";
		hidePicture = "true";
		hideName = "true";
		actionName = "Website";
		action = CSTRING(URL);
		description = "Issue Tracker: https://github.com/StephyPancakes/RAT-Advancedish-Medical/issues";
	};
};
