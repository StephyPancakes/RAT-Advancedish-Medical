#include "..\script_component.hpp"
/*
 * Author: Glowbal
 * Modified: Tomcat, Blue
 * Overwrites the cprLocal of ACE to add the success chance for CPR/AED/AED-X
 *
 * Arguments:
 * 0: Medic <OBJECT>
 * 1: Patient <OBJECT>
 * 2: Used Revive Object <STRING>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player, cursorObject, "AED"] call kat_circulation_fnc_cprLocal
 *
 * Public: No
 */

params ["_medic", "_patient", "_reviveObject"];

private _chance = 0;
private _random = random 100;
private _epiBoost = 1;
private _CPRcount = _patient getVariable [QGVAR(cprCount), 0];

{
	_x params ["_medication"];

	switch(_medication) do
	{
		case "Epinephrine":
		{
			_epiBoost = 1.5;
		};
	};
} forEach (_patient getVariable [QACEGVAR(medical,medications), []]);

switch (_reviveObject) do {
	case "CPR": {
		if (GVAR(enable_CPR_Chances)) then {
			switch (_medic getVariable [QACEGVAR(medical,medicClass),0]) do {
				case 0: {
					_chance = linearConversion [BLOOD_VOLUME_CLASS_4_HEMORRHAGE, BLOOD_VOLUME_CLASS_2_HEMORRHAGE, GET_BLOOD_VOLUME(_patient), GVAR(CPR_MinChance_Default), GVAR(CPR_MaxChance_Default), true];
				};
				case 1: {
					_chance = linearConversion [BLOOD_VOLUME_CLASS_4_HEMORRHAGE, BLOOD_VOLUME_CLASS_2_HEMORRHAGE, GET_BLOOD_VOLUME(_patient), GVAR(CPR_MinChance_RegularMedic), GVAR(CPR_MaxChance_RegularMedic), true];
				};
				case 2: {
					_chance = linearConversion [BLOOD_VOLUME_CLASS_4_HEMORRHAGE, BLOOD_VOLUME_CLASS_2_HEMORRHAGE, GET_BLOOD_VOLUME(_patient), GVAR(CPR_MinChance_Doctor), GVAR(CPR_MaxChance_Doctor), true];
				};
			};
		};
	};
};

if !(GVAR(enable_CPR_Chances)) then {
	private _min = ACEGVAR(medical_treatment,cprSuccessChanceMin);
	private _max = ACEGVAR(medical_treatment,cprSuccessChanceMax);
	_chance = linearConversion [BLOOD_VOLUME_CLASS_4_HEMORRHAGE, BLOOD_VOLUME_CLASS_2_HEMORRHAGE, GET_BLOOD_VOLUME(_patient), _min, _max, true];
	// ACE Medical settings are percentages (decimals, 0 <= x <= 1) instead of integers

	if ((random 1) <= _chance) then {
		[QACEGVAR(medical,CPRSucceeded), _patient] call CBA_fnc_localEvent;
	};
} else {
	if (_epiBoost isEqualTo 1.5) then {
		_chance = _chance + (2 ^ _CPRcount);

		_CPRcount = _CPRcount + 1;
		_patient setVariable [QGVAR(cprCount), _CPRcount, true];
	};

	if (_random <= _chance) then {
		 [QACEGVAR(medical,CPRSucceeded), _patient] call CBA_fnc_localEvent;
		_patient setVariable [QGVAR(cprCount), 2, true];
	} else {
		_CPRcount = _CPRcount + 1;
		_patient setVariable [QGVAR(cprCount), _CPRcount, true];
	};
};
