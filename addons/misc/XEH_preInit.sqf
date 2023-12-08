#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#define CBA_SETTINGS_CAT "RAT - ADVish Medical: Misc"

//Enable aceExposure things
[
	QGVAR(enable),
	"CHECKBOX",
	LLSTRING(SETTING_ENABLE),
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_Basic)],
	[true],
	true
] call CBA_Settings_fnc_init;

// Sets whether player can use items straight from vehicle inventory for treatment, and their priority
[
	QGVAR(allowSharedVehicleEquipment),
	"LIST",
	[LLSTRING(SETTING_allowSharedVehicleEquipment), LLSTRING(SETTING_allowSharedVehicleEquipment_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_Basic)],
	[[0, 1, 2, 3, 4], ["STR_ACE_Common_No", "STR_ACE_Medical_Treatment_AllowSharedEquipment_PriorityMedic", LLSTRING(SETTING_allowSharedVehicleEquipment_PriorityVehicleNoSelfTreatment), LLSTRING(SETTING_allowSharedVehicleEquipment_PriorityVehicleExceptSelfTreatment), LLSTRING(SETTING_allowSharedVehicleEquipment_PriorityVehicleAlways)], 1],
	true
] call CBA_fnc_addSetting;

[
	QGVAR(treatmentTimeDetachTourniquet),
	"SLIDER",
	[LLSTRING(SETTING_treatmentTimeDetachTourniquet)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_Tourniquet)],
	[1, 60, 7, 1],
	true
] call CBA_Settings_fnc_init;

[
	QGVAR(tourniquetEffects_Enable),
	"CHECKBOX",
	[LLSTRING(SETTING_tourniquetEffects_Enable)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_Tourniquet)],
	[true],
	true
] call CBA_Settings_fnc_init;

[
	QGVAR(tourniquetEffects_PositiveMultiplier),
	"SLIDER",
	[LLSTRING(SETTING_tourniquetEffects_PositiveMultiplier)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_Tourniquet)],
	[0.1, 10, 1, 1],
	true
] call CBA_Settings_fnc_init;

[
	QGVAR(tourniquetEffects_NegativeMultiplier),
	"SLIDER",
	[LLSTRING(SETTING_tourniquetEffects_NegativeMultiplier)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_Tourniquet)],
	[0.1, 10, 1, 1],
	true
] call CBA_Settings_fnc_init;

//Incompatibility Warning with other addons
[
	QGVAR(incompatibilityWarning),
	"CHECKBOX",
	[LLSTRING(SETTING_incompatibilityWarning), LLSTRING(SETTING_incompatibilityWarning_Desc)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_Basic)],
	[true],
	true
] call CBA_Settings_fnc_init;

//Adjust armband sling left arm (x, y, z)
[
	QGVAR(armbandSlingLeftArm),
	"EDITBOX",
	[LLSTRING(SETTING_ArmbandSlingLeftArmPos_Display), LLSTRING(SETTING_ArmbandSlingLeftArmPos_Desc)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_Armband)],
	"0.2, -0.39, -0.2",
	2
] call CBA_Settings_fnc_init;

//Adjust armband rotation left arm (yaw, pitch, roll)
[
	QGVAR(armbandSlingLeftArmRotation),
	"EDITBOX",
	[LLSTRING(SETTING_ArmbandSlingLeftArmRot_Display), LLSTRING(SETTING_ArmbandSlingLeftArmRot_Desc)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_Armband)],
	"240, 33, 26",
	2
] call CBA_Settings_fnc_init;

//Adjust armband sling right arm (x, y, z)
[
	QGVAR(armbandSlingRightArm),
	"EDITBOX",
	[LLSTRING(SETTING_ArmbandSlingRightArmPos_Display), LLSTRING(SETTING_ArmbandSlingRightArmPos_Desc)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_Armband)],
	"-0.228, -0.1, -0.43",
	2
] call CBA_Settings_fnc_init;

//Adjust armband rotation right arm (yaw, pitch, roll)
[
	QGVAR(armbandSlingRightArmRotation),
	"EDITBOX",
	[LLSTRING(SETTING_ArmbandSlingRightArmRot_Display), LLSTRING(SETTING_ArmbandSlingRightArmRot_Desc)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_Armband)],
	"5, -5, -5",
	2
] call CBA_Settings_fnc_init;

//Adjust armband sling left leg (x, y, z)
[
	QGVAR(armbandSlingLeftLeg),
	"EDITBOX",
	[LLSTRING(SETTING_ArmbandSlingLeftLegPos_Display), LLSTRING(SETTING_ArmbandSlingLeftLegPos_Desc)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_Armband)],
	"0.435, -0.075, -0.38",
	2
] call CBA_Settings_fnc_init;

//Adjust armband rotation left leg (yaw, pitch, roll)
[
	QGVAR(armbandSlingLeftLegRotation),
	"EDITBOX",
	[LLSTRING(SETTING_ArmbandSlingLeftLegRot_Display), LLSTRING(SETTING_ArmbandSlingLeftLegRot_Desc)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_Armband)],
	"-160, -5, 45",
	2
] call CBA_Settings_fnc_init;

//Adjust armband sling right leg (x, y, z)
[
	QGVAR(armbandSlingRightLeg),
	"EDITBOX",
	[LLSTRING(SETTING_ArmbandSlingRightLegPos_Display), LLSTRING(SETTING_ArmbandSlingRightLegPos_Desc)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_Armband)],
	"-0.32, -0.29, -0.42",
	2
] call CBA_Settings_fnc_init;

//Adjust armband rotation right Leg (yaw, pitch, roll)
[
	QGVAR(armbandSlingRightLegRotation),
	"EDITBOX",
	[LLSTRING(SETTING_ArmbandSlingRightLegRot_Display), LLSTRING(SETTING_ArmbandSlingRightLegRot_Desc)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_Armband)],
	"-30, -5, 38",
	2
] call CBA_Settings_fnc_init;

//IFAK Container
[
	QGVAR(IFAK_Container),
	"LIST",
	[LLSTRING(SETTING_FAK_Container), LLSTRING(SETTING_FAK_Container_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_IFAK)],
	[[0, 1, 2, 3], [LLSTRING(SETTING_Container_Default), LLSTRING(SETTING_Container_Uniform), LLSTRING(SETTING_Container_Vest), LLSTRING(SETTING_Container_Backpack)], 0],
	2
] call CBA_fnc_addSetting;

// Remove IFAK when empty
[
	QGVAR(IFAK_RemoveWhenEmpty),
	"CHECKBOX",
	LLSTRING(SETTING_FAK_RemoveWhenEmpty),
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_IFAK)],
	[true],
	true
] call CBA_fnc_addSetting;

//IFAK First Slot Item
[
	QGVAR(IFAKFirstSlotItem),
	"EDITBOX",
	[LLSTRING(SETTING_FirstSlot_Item), LLSTRING(SETTING_ItemSlot_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_IFAK)],
	"[['ACE_tourniquet', 2]]",
	1,
	{
		private _string = missionNamespace getVariable [QGVAR(IFAKFirstSlotItem), []];
		private _array = parseSimpleArray _string;
		missionNamespace setVariable [QGVAR(IFAKFirstSlotItem), _array, true];
		call FUNC(FAK_updateContents);
	}
] call CBA_Settings_fnc_init;

//IFAK Second Slot Item
[
	QGVAR(IFAKSecondSlotItem),
	"EDITBOX",
	[LLSTRING(SETTING_SecondSlot_Item), LLSTRING(SETTING_ItemSlot_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_IFAK)],
	"[['ACE_elasticBandage', 10]]",
	1,
	{
		private _string = missionNamespace getVariable [QGVAR(IFAKSecondSlotItem), []];
		private _array = parseSimpleArray _string;
		missionNamespace setVariable [QGVAR(IFAKSecondSlotItem), _array, true];
		call FUNC(FAK_updateContents);
	}
] call CBA_Settings_fnc_init;

//IFAK Third Slot Item
[
	QGVAR(IFAKThirdSlotItem),
	"EDITBOX",
	[LLSTRING(SETTING_ThirdSlot_Item), LLSTRING(SETTING_ItemSlot_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_IFAK)],
	"[['rat_Painkiller', 1], ['rat_Penthrox', 2]]",
	1,
	{
		private _string = missionNamespace getVariable [QGVAR(IFAKThirdSlotItem), []];
		private _array = parseSimpleArray _string;
		missionNamespace setVariable [QGVAR(IFAKThirdSlotItem), _array, true];
		call FUNC(FAK_updateContents);
	}
] call CBA_Settings_fnc_init;

//IFAK Fourth Item
[
	QGVAR(IFAKFourthSlotItem),
	"EDITBOX",
	[LLSTRING(SETTING_FourthSlot_Item), LLSTRING(SETTING_ItemSlot_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_IFAK)],
	"[['ACE_splint', 2], ['ACE_bloodIV_500', 2]]",
	1,
	{
		private _string = missionNamespace getVariable [QGVAR(IFAKFourthSlotItem), []];
		private _array = parseSimpleArray _string;
		missionNamespace setVariable [QGVAR(IFAKFourthSlotItem), _array, true];
		call FUNC(FAK_updateContents);
	}
] call CBA_Settings_fnc_init;

//AFAK Container
[
	QGVAR(AFAK_Container),
	"LIST",
	[LLSTRING(SETTING_FAK_Container), LLSTRING(SETTING_FAK_Container_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_AFAK)],
	[[0, 1, 2, 3], [LLSTRING(SETTING_Container_Default), LLSTRING(SETTING_Container_Uniform), LLSTRING(SETTING_Container_Vest), LLSTRING(SETTING_Container_Backpack)], 0],
	2
] call CBA_fnc_addSetting;

// Remove AFAK when empty
[
	QGVAR(AFAK_RemoveWhenEmpty),
	"CHECKBOX",
	LLSTRING(SETTING_FAK_RemoveWhenEmpty),
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_AFAK)],
	[true],
	true
] call CBA_fnc_addSetting;

//AFAK First Slot Item
[
	QGVAR(AFAKFirstSlotItem),
	"EDITBOX",
	[LLSTRING(SETTING_FirstSlot_Item), LLSTRING(SETTING_ItemSlot_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_AFAK)],
	"[['ACE_tourniquet', 4]]",
	1,
	{
		private _string = missionNamespace getVariable [QGVAR(AFAKFirstSlotItem), []];
		private _array = parseSimpleArray _string;
		missionNamespace setVariable [QGVAR(AFAKFirstSlotItem), _array, true];
		call FUNC(FAK_updateContents);
	}
] call CBA_Settings_fnc_init;

//AFAK Second Slot Item
[
	QGVAR(AFAKSecondSlotItem),
	"EDITBOX",
	[LLSTRING(SETTING_SecondSlot_Item), LLSTRING(SETTING_ItemSlot_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_AFAK)],
	"[['ACE_elasticBandage', 20]]",
	1,
	{
		private _string = missionNamespace getVariable [QGVAR(AFAKSecondSlotItem), []];
		private _array = parseSimpleArray _string;
		missionNamespace setVariable [QGVAR(AFAKSecondSlotItem), _array, true];
		call FUNC(FAK_updateContents);
	}
] call CBA_Settings_fnc_init;

//AFAK Third Slot Item
[
	QGVAR(AFAKThirdSlotItem),
	"EDITBOX",
	[LLSTRING(SETTING_ThirdSlot_Item), LLSTRING(SETTING_ItemSlot_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_AFAK)],
	"[['rat_Penthrox', 4], ['rat_Painkiller', 2]]",
	1,
	{
		private _string = missionNamespace getVariable [QGVAR(AFAKThirdSlotItem), []];
		private _array = parseSimpleArray _string;
		missionNamespace setVariable [QGVAR(AFAKThirdSlotItem), _array, true];
		call FUNC(FAK_updateContents);
	}
] call CBA_Settings_fnc_init;

//AFAK Fourth Item
[
	QGVAR(AFAKFourthSlotItem),
	"EDITBOX",
	[LLSTRING(SETTING_FourthSlot_Item), LLSTRING(SETTING_ItemSlot_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_AFAK)],
	"[['ACE_splint', 2], ['ACE_bloodIV_500', 4]]",
	1,
	{
		private _string = missionNamespace getVariable [QGVAR(AFAKFourthSlotItem), []];
		private _array = parseSimpleArray _string;
		missionNamespace setVariable [QGVAR(AFAKFourthSlotItem), _array, true];
		call FUNC(FAK_updateContents);
	}
] call CBA_Settings_fnc_init;

//AFAK Fifth Item
[
	QGVAR(AFAKFifthSlotItem),
	"EDITBOX",
	[LLSTRING(SETTING_FifthSlot_Item), LLSTRING(SETTING_ItemSlot_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_AFAK)],
	"[['rat_Caffeine', 1]]",
	1,
	{
		private _string = missionNamespace getVariable [QGVAR(AFAKFifthSlotItem), []];
		private _array = parseSimpleArray _string;
		missionNamespace setVariable [QGVAR(AFAKFifthSlotItem), _array, true];
		call FUNC(FAK_updateContents);
	}
] call CBA_Settings_fnc_init;

//AFAK Sixth Item
[
	QGVAR(AFAKSixthSlotItem),
	"EDITBOX",
	[LLSTRING(SETTING_SixthSlot_Item), LLSTRING(SETTING_ItemSlot_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_AFAK)],
	"[['ACE_morphine', 3], ['ACE_epinephrine', 3]]",
	1,
	{
		private _string = missionNamespace getVariable [QGVAR(AFAKSixthSlotItem), []];
		private _array = parseSimpleArray _string;
		missionNamespace setVariable [QGVAR(AFAKSixthSlotItem), _array, true];
		call FUNC(FAK_updateContents);
	}
] call CBA_Settings_fnc_init;

//MFAK Container
[
	QGVAR(MFAK_Container),
	"LIST",
	[LLSTRING(SETTING_FAK_Container), LLSTRING(SETTING_FAK_Container_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_MFAK)],
	[[0, 1, 2, 3], [LLSTRING(SETTING_Container_Default), LLSTRING(SETTING_Container_Uniform), LLSTRING(SETTING_Container_Vest), LLSTRING(SETTING_Container_Backpack)], 0],
	2
] call CBA_fnc_addSetting;

// Remove MFAK when empty
[
	QGVAR(MFAK_RemoveWhenEmpty),
	"CHECKBOX",
	LLSTRING(SETTING_FAK_RemoveWhenEmpty),
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_MFAK)],
	[true],
	true
] call CBA_fnc_addSetting;

//MFAK First Slot Item
[
	QGVAR(MFAKFirstSlotItem),
	"EDITBOX",
	[LLSTRING(SETTING_FirstSlot_Item), LLSTRING(SETTING_ItemSlot_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_MFAK)],
	"[['ACE_tourniquet', 8]]",
	1,
	{
		private _string = missionNamespace getVariable [QGVAR(MFAKFirstSlotItem), []];
		private _array = parseSimpleArray _string;
		missionNamespace setVariable [QGVAR(MFAKFirstSlotItem), _array, true];
		call FUNC(FAK_updateContents);
	}
] call CBA_Settings_fnc_init;

//MFAK Second Slot Item
[
	QGVAR(MFAKSecondSlotItem),
	"EDITBOX",
	[LLSTRING(SETTING_SecondSlot_Item), LLSTRING(SETTING_ItemSlot_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_MFAK)],
	"[['ACE_elasticBandage', 60]]",
	1,
	{
		private _string = missionNamespace getVariable [QGVAR(MFAKSecondSlotItem), []];
		private _array = parseSimpleArray _string;
		missionNamespace setVariable [QGVAR(MFAKSecondSlotItem), _array, true];
		call FUNC(FAK_updateContents);
	}
] call CBA_Settings_fnc_init;

//MFAK Third Slot Item
[
	QGVAR(MFAKThirdSlotItem),
	"EDITBOX",
	[LLSTRING(SETTING_ThirdSlot_Item), LLSTRING(SETTING_ItemSlot_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_MFAK)],
	"[['rat_Painkiller', 4], ['rat_Penthrox', 8]]",
	1,
	{
		private _string = missionNamespace getVariable [QGVAR(MFAKThirdSlotItem), []];
		private _array = parseSimpleArray _string;
		missionNamespace setVariable [QGVAR(MFAKThirdSlotItem), _array, true];
		call FUNC(FAK_updateContents);
	}
] call CBA_Settings_fnc_init;

//MFAK Fourth Item
[
	QGVAR(MFAKFourthSlotItem),
	"EDITBOX",
	[LLSTRING(SETTING_FourthSlot_Item), LLSTRING(SETTING_ItemSlot_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_MFAK)],
	"[['ACE_splint', 8]]",
	1,
	{
		private _string = missionNamespace getVariable [QGVAR(MFAKFourthSlotItem), []];
		private _array = parseSimpleArray _string;
		missionNamespace setVariable [QGVAR(MFAKFourthSlotItem), _array, true];
		call FUNC(FAK_updateContents);
	}
] call CBA_Settings_fnc_init;

//MFAK Fifth Item
[
	QGVAR(MFAKFifthSlotItem),
	"EDITBOX",
	[LLSTRING(SETTING_FifthSlot_Item), LLSTRING(SETTING_ItemSlot_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_MFAK)],
	"[['rat_Caffeine', 3]]",
	1,
	{
		private _string = missionNamespace getVariable [QGVAR(MFAKFifthSlotItem), []];
		private _array = parseSimpleArray _string;
		missionNamespace setVariable [QGVAR(MFAKFifthSlotItem), _array, true];
		call FUNC(FAK_updateContents);
	}
] call CBA_Settings_fnc_init;

//MFAK Sixth Item
[
	QGVAR(MFAKSixthSlotItem),
	"EDITBOX",
	[LLSTRING(SETTING_SixthSlot_Item), LLSTRING(SETTING_ItemSlot_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_MFAK)],
	"[['ACE_morphine', 8], ['ACE_epinephrine', 8]]",
	1,
	{
		private _string = missionNamespace getVariable [QGVAR(MFAKSixthSlotItem), []];
		private _array = parseSimpleArray _string;
		missionNamespace setVariable [QGVAR(MFAKSixthSlotItem), _array, true];
		call FUNC(FAK_updateContents);
	}
] call CBA_Settings_fnc_init;

//MFAK Seventh Item
[
	QGVAR(MFAKSeventhSlotItem),
	"EDITBOX",
	[LLSTRING(SETTING_SeventhSlot_Item), LLSTRING(SETTING_ItemSlot_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_MFAK)],
	"[['ACE_bloodIV_500', 10], ['ACE_bloodIV_1000', 5]]",
	1,
	{
		private _string = missionNamespace getVariable [QGVAR(MFAKSeventhSlotItem), []];
		private _array = parseSimpleArray _string;
		missionNamespace setVariable [QGVAR(MFAKSeventhSlotItem), _array, true];
		call FUNC(FAK_updateContents);
	}
] call CBA_Settings_fnc_init;

//MFAK Eighth Item
[
	QGVAR(MFAKEighthSlotItem),
	"EDITBOX",
	[LLSTRING(SETTING_EighthSlot_Item), LLSTRING(SETTING_ItemSlot_DESC)],
	[CBA_SETTINGS_CAT, LSTRING(SubCategory_MFAK)],
	"[['rat_TXA', 4], ['rat_Carbonate', 4]]",
	1,
	{
		private _string = missionNamespace getVariable [QGVAR(MFAKEighthSlotItem), []];
		private _array = parseSimpleArray _string;
		missionNamespace setVariable [QGVAR(MFAKEighthSlotItem), _array, true];
		call FUNC(FAK_updateContents);
	}
] call CBA_Settings_fnc_init;
/*
// Medical ACE Arsenal
if (GVAR(arsenalMedCategory)) then {
	[
		["rat_aatKit","rat_ncdKit","rat_accuvac","ACE_adenosine","ACE_epinephrine","rat_X_AED","ACE_elasticBandage","ACE_packingBandage","rat_crossPanel","rat_bloodIV_O","rat_bloodIV_A","rat_bloodIV_AB","ACE_bloodIV","rat_bloodIV_B","ACE_bloodIV_250","rat_bloodIV_O_250","rat_bloodIV_A_250","rat_bloodIV_AB_250","rat_bloodIV_B_250","ACE_bloodIV_500","rat_bloodIV_O_500","rat_bloodIV_A_500","rat_bloodIV_AB_500","rat_bloodIV_B_500","ACE_bodyBag","rat_Empty_bloodIV_250","rat_Empty_bloodIV_500","rat_bloodIV_O_N","rat_bloodIV_A_N","rat_bloodIV_AB_N","rat_bloodIV_B_N","rat_bloodIV_O_N_250","rat_bloodIV_A_N_250","rat_bloodIV_AB_N_250","rat_bloodIV_B_N_250","rat_bloodIV_O_N_500","rat_bloodIV_A_N_500","rat_bloodIV_AB_N_500","rat_bloodIV_B_N_500","FirstAidKit","rat_AED","rat_chestSeal","rat_larynx","ACE_fieldDressing","Medikit","ACE_morphine","rat_guedel","ACE_personalAidKit","ACE_plasmaIV","ACE_plasmaIV_250","ACE_plasmaIV_500","rat_Pulseoximeter","ACE_quikclot","ACE_salineIV_250","ACE_salineIV","ACE_salineIV_500","ACE_splint","rat_stethoscope","ACE_surgicalKit","ACE_tourniquet","Attachable_Helistretcher","rat_CarbonateItem","rat_PainkillerItem","rat_PervitinItem","rat_CaffeineItem","rat_PenthroxItem","rat_IV_16","rat_IO_FAST","rat_naloxone","rat_EACA","rat_TXA","rat_norepinephrine","rat_phenylephrine","rat_nitroglycerin","rat_amiodarone","rat_lidocaine","rat_atropine","rat_ketamine","rat_fentanyl","rat_nalbuphine","rat_lorazepam","rat_flumazenil","rat_etomidate","rat_scalpel","rat_retractor","rat_clamp","rat_plate","rat_vacuum","rat_BVM","rat_pocketBVM","rat_oxygenTank_150_Item","rat_oxygenTank_300_Item","rat_oxygenTank_150_Empty","rat_oxygenTank_300_Empty","rat_IFAK","rat_MFAK","rat_AFAK"],
		localize "STR_ACE_Medical_GUI_Medical",
		"\z\ace\addons\medical_gui\data\categories\triage_card.paa"
	] call ACEFUNC(arsenal,addRightPanelButton);
};
*/
ADDON = true;
