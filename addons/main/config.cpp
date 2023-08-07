#define _ARMA_

class CfgPatches
{
	class rat_main
	{
		name = "RAT - Main";
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.88;
		requiredAddons[] = {"A3_Data_F_Tank_Loadorder","cba_main","ace_main"};
		author = "Rat";
		url = "$STR_rat_main_URL";
		version = 0.0.0.1;
		versionStr = "0.0.0.1";
		versionAr[] = {0,0,0,1};
	};
};
class CfgMods
{
	class rat
	{
		dir = "@rat_aceAdvMedical";
		name = "RAT - Advancedish Medical";
		picture = "A3\Ui_f\data\Logos\arma3_expansion_alpha_ca";
		hidePicture = "true";
		hideName = "true";
		actionName = "Website";
		action = "$STR_rat_main_URL";
		description = "Issue Tracker: https://github.com/Tomcat-SG/KAM/issues";
	};
};
