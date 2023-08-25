#include "script_component.hpp"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

#define CBA_SETTINGS_CAT "RAT - ADVish Medical: Pharmacy"

// =============================================
// Reorientation Settings Category
// =============================================
[
    QGVAR(Reorientation_Enable),
    "CHECKBOX",
    [LLSTRING(SETTING_Reorientation_Enable), LLSTRING(SETTING_Reorientation_Enable_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Reorientation)],
    [true],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(medLvl_Reorientation),
    "LIST",
    [LLSTRING(SETTING_Allow_Reorientation),LLSTRING(SETTING_Allow_Reorientation_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Reorientation)],
    [[0, 1, 2], [ACELSTRING(medical_treatment,Anyone), ACELSTRING(medical_treatment,Medics), ACELSTRING(medical_treatment,Doctors)], 0],
    true
] call CBA_settings_fnc_init;

[
    QGVAR(treatmentTime_Reorientation),
    "SLIDER",
    [LLSTRING(treatmentTime_Reorientation)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Reorientation)],
    [0.1, 10, 2, 1],
    true
] call CBA_Settings_fnc_init;


[
    QGVAR(Reorientation_Slap),
    "CHECKBOX",
    [LLSTRING(SETTING_Reorientation_Slap), LLSTRING(SETTING_Reorientation_Slap_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Reorientation)],
    [true],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(reorientationChance),
    "SLIDER",
    LLSTRING(SETTING_reorientationChance),
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Reorientation)],
    [0, 100, 100, 0],
    true
] call CBA_Settings_fnc_init;

// =============================================
// Carbonate Settings Category
// =============================================
[
    QGVAR(medLvl_Carbonate),
    "LIST",
    [LLSTRING(medLvl_Carbonate)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Carbonate)],
    [[0, 1, 2], [ACELSTRING(medical_treatment,Anyone), ACELSTRING(medical_treatment,Medics), ACELSTRING(medical_treatment,Doctors)], 0],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(treatmentTime_Carbonate),
    "SLIDER",
    [LLSTRING(treatmentTime_Carbonate)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Carbonate)],
    [0.1, 10, 7, 1],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(carbonateChance),
    "SLIDER",
    LLSTRING(SETTING_carbonateChance),
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Carbonate)],
    [0, 100, 100, 0],
    true
] call CBA_Settings_fnc_init;

// =============================================
// Naloxone Settings Category
// =============================================
[
    QGVAR(medLvl_Naloxone),
    "LIST",
    [LLSTRING(medLvl_Naloxone)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Naloxone)],
    [[0, 1, 2], [ACELSTRING(medical_treatment,Anyone), ACELSTRING(medical_treatment,Medics), ACELSTRING(medical_treatment,Doctors)], 0],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(treatmentTime_Naloxone),
    "SLIDER",
    [LLSTRING(treatmentTime_Naloxone)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Naloxone)],
    [0.1, 10, 7, 1],
    true
] call CBA_Settings_fnc_init;

// =============================================
// Pervitin Settings Category
// =============================================
[
    QGVAR(medLvl_Pervitin),
    "LIST",
    [LLSTRING(medLvl_Pervitin)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Pervitin)],
    [[0, 1, 2], [ACELSTRING(medical_treatment,Anyone), ACELSTRING(medical_treatment,Medics), ACELSTRING(medical_treatment,Doctors)], 0],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(treatmentTime_Pervitin),
    "SLIDER",
    [LLSTRING(treatmentTime_Pervitin)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Pervitin)],
    [0.1, 10, 5, 1],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(weapon_sway_pervitin),
    "CHECKBOX",
    [LLSTRING(SETTING_Weapon_Sway_Pervitin), LLSTRING(SETTING_Weapon_Sway_Pervitin_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Pervitin)],
    [true],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(chromatic_aberration_checkbox_pervitin),
    "CHECKBOX",
    [LLSTRING(SETTING_Chromatic_Aberration_Checkbox_Pervitin), LLSTRING(SETTING_Chromatic_Aberration_Checkbox_Pervitin_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Pervitin)],
    [true],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(chromatic_aberration_slider_pervitin),
    "SLIDER",
    [LLSTRING(SETTING_Chromatic_Aberration_Slider_Pervitin), LLSTRING(SETTING_Chromatic_Aberration_Slider_Pervitin_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Pervitin)],
    [0.1, 10, 1, 1],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(pervitinSpeed),
    "SLIDER",
    [LLSTRING(SETTING_PervitinSpeed_displayName), LLSTRING(SETTING_PervitinSpeed_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Pervitin)],
    [1, 1.5, 1.15, 2],
    true
] call CBA_Settings_fnc_init;

// =============================================
// TXA Settings Category
// =============================================
[
    QGVAR(medLvl_TXA),
    "LIST",
    [LLSTRING(medLvl_TXA)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_TXA)],
    [[0, 1, 2], [ACELSTRING(medical_treatment,Anyone), ACELSTRING(medical_treatment,Medics), ACELSTRING(medical_treatment,Doctors)], 0],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(treatmentTime_TXA),
    "SLIDER",
    [LLSTRING(treatmentTime_TXA)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_TXA)],
    [0.1, 10, 7, 1],
    true
] call CBA_Settings_fnc_init;

// =============================================
// Norepinephrine Settings Category
// =============================================
[
    QGVAR(medLvl_Norepinephrine),
    "LIST",
    [LLSTRING(medLvl_Norepinephrine)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Norepinephrine)],
    [[0, 1, 2], [ACELSTRING(medical_treatment,Anyone), ACELSTRING(medical_treatment,Medics), ACELSTRING(medical_treatment,Doctors)], 0],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(treatmentTime_Norepinephrine),
    "SLIDER",
    [LLSTRING(treatmentTime_Norepinephrine)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Norepinephrine)],
    [0.1, 10, 7, 1],
    true
] call CBA_Settings_fnc_init;

// =============================================
// Phenylephrine Settings Category
// =============================================
[
    QGVAR(medLvl_Phenylephrine),
    "LIST",
    [LLSTRING(medLvl_Phenylephrine)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Phenylephrine)],
    [[0, 1, 2], [ACELSTRING(medical_treatment,Anyone), ACELSTRING(medical_treatment,Medics), ACELSTRING(medical_treatment,Doctors)], 0],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(treatmentTime_Phenylephrine),
    "SLIDER",
    [LLSTRING(treatmentTime_Phenylephrine)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Phenylephrine)],
    [0.1, 10, 7, 1],
    true
] call CBA_Settings_fnc_init;

// =============================================
// Nitroglycerin Settings Category
// =============================================
[
    QGVAR(medLvl_Nitroglycerin),
    "LIST",
    [LLSTRING(medLvl_Nitroglycerin)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Nitroglycerin)],
    [[0, 1, 2], [ACELSTRING(medical_treatment,Anyone), ACELSTRING(medical_treatment,Medics), ACELSTRING(medical_treatment,Doctors)], 0],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(treatmentTime_Nitroglycerin),
    "SLIDER",
    [LLSTRING(treatmentTime_Nitroglycerin)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Nitroglycerin)],
    [0.1, 10, 7, 1],
    true
] call CBA_Settings_fnc_init;

// =============================================
// Atropine Settings Category
// =============================================
[
    QGVAR(medLvl_Atropine),
    "LIST",
    [LLSTRING(medLvl_Atropine)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Atropine)],
    [[0, 1, 2], [ACELSTRING(medical_treatment,Anyone), ACELSTRING(medical_treatment,Medics), ACELSTRING(medical_treatment,Doctors)], 0],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(treatmentTime_Atropine),
    "SLIDER",
    [LLSTRING(treatmentTime_Atropine)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Atropine)],
    [0.1, 10, 7, 1],
    true
] call CBA_Settings_fnc_init;

// =============================================
//Ketamine Settings Category
// =============================================
[
    QGVAR(medLvl_Ketamine),
    "LIST",
    [LLSTRING(medLvl_Ketamine)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Ketamine)],
    [[0, 1, 2], [ACELSTRING(medical_treatment,Anyone), ACELSTRING(medical_treatment,Medics), ACELSTRING(medical_treatment,Doctors)], 0],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(treatmentTime_Ketamine),
    "SLIDER",
    [LLSTRING(treatmentTime_Ketamine)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Ketamine)],
    [0.1, 10, 7, 1],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(chromatic_aberration_checkbox_ketamine),
    "CHECKBOX",
    [LLSTRING(SETTING_Chromatic_Aberration_Checkbox_Ketamine), LLSTRING(SETTING_Chromatic_Aberration_Checkbox_Ketamine_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Ketamine)],
    [true],
    true
] call CBA_Settings_fnc_init;

[
    QGVAR(chromatic_aberration_slider_ketamine),
    "SLIDER",
    [LLSTRING(SETTING_Chromatic_Aberration_Slider_Ketamine), LLSTRING(SETTING_Chromatic_Aberration_Slider_Ketamine_DESC)],
    [CBA_SETTINGS_CAT, LSTRING(SubCategory_Ketamine)],
    [0.1, 10, 0.8, 1],
    true
] call CBA_Settings_fnc_init;

ADDON = true;
