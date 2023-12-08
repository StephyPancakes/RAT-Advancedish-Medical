#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#define CBA_SETTINGS_CAT "RAT - ADVish Medical: Circulation"

[
	QGVAR(enable),
	"CHECKBOX",
	LLSTRING(SETTING_ENABLE),
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_Basic)],
	[true],
	true
] call CBA_Settings_fnc_init;

//Enable different CPR chances per medical level
[
	QGVAR(enable_CPR_Chances),
	"CHECKBOX",
	LLSTRING(SETTING_CPR_CHANCES),
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_CPR)],
	[true],
	true
] call CBA_Settings_fnc_init;

//Max CPR Chance for Doctors
[
	QGVAR(CPR_MaxChance_Doctor),
	"SLIDER",
	LLSTRING(CPR_MaxChance_Doctor),
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_CPR)],
	[0,100,40,0],
	true
] call CBA_Settings_fnc_init;

//Min CPR Chance for Doctors
[
	QGVAR(CPR_MinChance_Doctor),
	"SLIDER",
	LLSTRING(CPR_MinChance_Doctor),
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_CPR)],
	[0,100,20,0],
	true
] call CBA_Settings_fnc_init;

//Max CPR Chance for Regular medics
[
	QGVAR(CPR_MaxChance_RegularMedic),
	"SLIDER",
	LLSTRING(CPR_MaxChance_RegularMedic),
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_CPR)],
	[0,100,30,0],
	true
] call CBA_Settings_fnc_init;

//Min CPR Chance for Regular medics
[
	QGVAR(CPR_MinChance_RegularMedic),
	"SLIDER",
	LLSTRING(CPR_MinChance_RegularMedic),
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_CPR)],
	[0,100,15,0],
	true
] call CBA_Settings_fnc_init;

//Max CPR Chance for Default
[
	QGVAR(CPR_MaxChance_Default),
	"SLIDER",
	LLSTRING(CPR_MaxChance_Default),
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_CPR)],
	[0,100,20,0],
	true
] call CBA_Settings_fnc_init;

//Min CPR Chance for Default
[
	QGVAR(CPR_MinChance_Default),
	"SLIDER",
	LLSTRING(CPR_MinChance_Default),
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_CPR)],
	[0,100,10,0],
	true
] call CBA_Settings_fnc_init;

// Sets interval at which CPR chance is rolled
[
	QGVAR(CPR_ChanceInterval),
	"SLIDER",
	LLSTRING(SETTING_CPR_ChanceInterval),
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_CPR)],
	[1 , 3600, 15, 0],
	true
] call CBA_Settings_fnc_init;

//Enable self blood draw
[
	QGVAR(enable_selfBloodDraw),
	"LIST",
	LLSTRING(SETTING_SELF_BLOOD_DRAW),
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_BloodDraw)],
	[[0, 1], ["STR_ACE_common_No", "STR_ACE_common_Yes"], 1],
	true
] call CBA_Settings_fnc_init;

//blood draw time for 500ml kit
[
	QGVAR(blood_drawTime_500ml),
	"SLIDER",
	LLSTRING(SETTING_BLOOD_DRAWTIME_500ML),
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_BloodDraw)],
	[1,600,50,0],
	true
] call CBA_Settings_fnc_init;

//blood draw time for 250ml kit
[
	QGVAR(blood_drawTime_250ml),
	"SLIDER",
	LLSTRING(SETTING_BLOOD_DRAWTIME_250ML),
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_BloodDraw)],
	[1,600,25,0],
	true
] call CBA_Settings_fnc_init;

//Minimum acceptable blood volume for drawing blood
[
	QGVAR(blood_draw_limit),
	"SLIDER",
	[LLSTRING(SETTING_MINIMUM_SAFE_DRAW),LLSTRING(SETTING_MINIMUM_SAFE_DRAW_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_BloodDraw)],
	[0, 6, 3.6, 1], // 3.6 default matches ACE Class IV hemorrhage 
	true
] call CBA_Settings_fnc_init;
/*
[
	QGVAR(cardiacArrestBleedRate),
	"SLIDER",
	LLSTRING(SETTING_cardiacArrestBleedRate),
	[CBA_SETTINGS_CAT, ELSTRING(GUI,SubCategory_Basic)],
	[0, 0.2, 0.05, 3],
	true
] call CBA_Settings_fnc_init;
*/
ADDON = true;