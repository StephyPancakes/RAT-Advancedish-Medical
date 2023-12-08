#include "..\script_component.hpp"
/*
 * Author: Miss Heda
 * Attaches a armband to the according limb.
 *
 * Arguments:
 * 0: Player <OBJECT>
 * 1: String
 * 2: Number
 *
 * Return Value:
 * None
 *
 * Example:
 * [player, "rat_armband_red_cross", 0] call rat_misc_fnc_slingArmband;
 *
 * Public: No
 */

params ["_unit", "_armbandItem", "_limbNumber"];

private _str = missionNamespace getVariable [QGVAR(armbandSlingLeftArm), ""];
private _array = [_str, ","" ", true] call FUNC(stringToArray);
_unit setVariable [QGVAR(armbandSlingLeftArmPos), _array, true];

private _str = missionNamespace getVariable [QGVAR(armbandSlingRightArm), ""];
private _array = [_str, ","" ", true] call FUNC(stringToArray);
_unit setVariable [QGVAR(armbandSlingRightArmPos), _array, true];

private _str = missionNamespace getVariable [QGVAR(armbandSlingLeftLeg), ""];
private _array = [_str, ","" ", true] call FUNC(stringToArray);
_unit setVariable [QGVAR(armbandSlingLeftLegPos), _array, true];

private _str = missionNamespace getVariable [QGVAR(armbandSlingRightLeg), ""];
private _array = [_str, ","" ", true] call FUNC(stringToArray);
_unit setVariable [QGVAR(armbandSlingRightLegPos), _array, true];

private _str = missionNamespace getVariable [QGVAR(armbandSlingLeftArmRotation), ""];
private _array = [_str, ","" ", true] call FUNC(stringToArray);
_unit setVariable [QGVAR(armbandSlingLeftArmRot), _array, true];

private _str = missionNamespace getVariable [QGVAR(armbandSlingRightArmRotation), ""];
private _array = [_str, ","" ", true] call FUNC(stringToArray);
_unit setVariable [QGVAR(armbandSlingRightArmRot), _array, true];

private _str = missionNamespace getVariable [QGVAR(armbandSlingLeftLegRotation), ""];
private _array = [_str, ","" ", true] call FUNC(stringToArray);
_unit setVariable [QGVAR(armbandSlingLeftLegRot), _array, true];

private _str = missionNamespace getVariable [QGVAR(armbandSlingRightLegRotation), ""];
private _array = [_str, ","" ", true] call FUNC(stringToArray);
_unit setVariable [QGVAR(armbandSlingRightLegRot), _array, true];

switch (_limbNumber) do
{
	// Attach to left arm
	case 0: {
		switch (_armbandItem) do
		{
			case "rat_armband_red_cross": {
				_armbandLA = "Rat_armbandRC" createVehicle position _unit;
				_armbandLA attachTo [_unit, _unit getVariable [QGVAR(armbandSlingLeftArmPos), [0, 0, 0]], "leftforearm", true];
				[_armbandLA, _unit getVariable [QGVAR(armbandSlingLeftArmRot), [0, 0, 0]]] call BIS_fnc_setObjectRotation;

				_unit removeItem _armbandItem;
				_unit setVariable [QGVAR(isLeftArmFree), false, true];
				_unit setVariable [QGVAR(whichArmabndisSlingedLA), _armbandLA, true];
			};

			case "rat_armband_medic": {
				_armbandLA = "Rat_armbandRCM" createVehicle position _unit;
				_armbandLA attachTo [_unit, _unit getVariable [QGVAR(armbandSlingLeftArmPos), [0, 0, 0]], "leftforearm", true];
				[_armbandLA, _unit getVariable [QGVAR(armbandSlingLeftArmRot), [0, 0, 0]]] call BIS_fnc_setObjectRotation;

				_unit removeItem _armbandItem;
				_unit setVariable [QGVAR(isLeftArmFree), false, true];
				_unit setVariable [QGVAR(whichArmabndisSlingedLA), _armbandLA, true];
			};

			case "rat_armband_doctor": {
				_armbandLA = "Rat_armbandRCD" createVehicle position _unit;
				_armbandLA attachTo [_unit, _unit getVariable [QGVAR(armbandSlingLeftArmPos), [0, 0, 0]], "leftforearm", true];
				[_armbandLA, _unit getVariable [QGVAR(armbandSlingLeftArmRot), [0, 0, 0]]] call BIS_fnc_setObjectRotation;

				_unit removeItem _armbandItem;
				_unit setVariable [QGVAR(isLeftArmFree), false, true];
				_unit setVariable [QGVAR(whichArmabndisSlingedLA), _armbandLA, true];
			};
		};
	};
	
	// Attach to right arm
	case 1: { 
		switch (_armbandItem) do 
		{
			case "rat_armband_red_cross": { 
				_armbandRA = "Rat_armbandRC" createVehicle position _unit;
				_armbandRA attachTo [_unit, _unit getVariable [QGVAR(armbandSlingRightArmPos), [0, 0, 0]], "rightforearm", true];
				[_armbandRA, _unit getVariable [QGVAR(armbandSlingRightArmRot), [0, 0, 0]]] call BIS_fnc_setObjectRotation;

				_unit removeItem _armbandItem;
				_unit setVariable [QGVAR(isRightArmFree), false, true];
				_unit setVariable [QGVAR(whichArmabndisSlingedRA), _armbandRA, true];
			};

			case "rat_armband_medic": {
				_armbandRA = "Rat_armbandRCM" createVehicle position _unit;
				_armbandRA attachTo [_unit, _unit getVariable [QGVAR(armbandSlingRightArmPos), [0, 0, 0]], "rightforearm", true];
				[_armbandRA, _unit getVariable [QGVAR(armbandSlingRightArmRot), [0, 0, 0]]] call BIS_fnc_setObjectRotation;

				_unit removeItem _armbandItem;
				_unit setVariable [QGVAR(isRightArmFree), false, true];
				_unit setVariable [QGVAR(whichArmabndisSlingedRA), _armbandRA, true];
			};

			case "rat_armband_doctor": {
				_armbandRA = "Rat_armbandRCD" createVehicle position _unit;
				_armbandRA attachTo [_unit, _unit getVariable [QGVAR(armbandSlingRightArmPos), [0, 0, 0]], "rightforearm", true];
				[_armbandRA, _unit getVariable [QGVAR(armbandSlingRightArmRot), [0, 0, 0]]] call BIS_fnc_setObjectRotation;

				_unit removeItem _armbandItem;
				_unit setVariable [QGVAR(isRightArmFree), false, true];
				_unit setVariable [QGVAR(whichArmabndisSlingedRA), _armbandRA, true];
			};
		};
	};

	// Attach to left leg
	case 2: { 
		switch (_armbandItem) do 
		{
			case "rat_armband_red_cross": { 
				_armbandLL = "Rat_armbandRC" createVehicle position _unit;
				_armbandLL attachTo [_unit, _unit getVariable [QGVAR(armbandSlingLeftLegPos), [0, 0, 0]], "LeftUpLeg", true];  
				[_armbandLL, _unit getVariable [QGVAR(armbandSlingLeftLegRot), [0, 0, 0]]] call BIS_fnc_setObjectRotation;

				_unit removeItem _armbandItem;
				_unit setVariable [QGVAR(isLeftLegFree), false, true];
				_unit setVariable [QGVAR(whichArmabndisSlingedLL), _armbandLL, true];
			};

			case "rat_armband_medic": {
				_armbandLL = "Rat_armbandRCM" createVehicle position _unit;
				_armbandLL attachTo [_unit, _unit getVariable [QGVAR(armbandSlingLeftLegPos), [0, 0, 0]], "LeftUpLeg", true];  
				[_armbandLL, _unit getVariable [QGVAR(armbandSlingLeftLegRot), [0, 0, 0]]] call BIS_fnc_setObjectRotation;

				_unit removeItem _armbandItem;
				_unit setVariable [QGVAR(isLeftLegFree), false, true];
				_unit setVariable [QGVAR(whichArmabndisSlingedLL), _armbandLL, true];
			};

			case "rat_armband_doctor": {
				_armbandLL = "Rat_armbandRCD" createVehicle position _unit;
				_armbandLL attachTo [_unit, _unit getVariable [QGVAR(armbandSlingLeftLegPos), [0, 0, 0]], "LeftUpLeg", true];  
				[_armbandLL, _unit getVariable [QGVAR(armbandSlingLeftLegRot), [0, 0, 0]]] call BIS_fnc_setObjectRotation;

				_unit removeItem _armbandItem;
				_unit setVariable [QGVAR(isLeftLegFree), false, true];
				_unit setVariable [QGVAR(whichArmabndisSlingedLL), _armbandLL, true];
			};
		};
	};

	// Attach to right leg
	case 3: { 
		switch (_armbandItem) do 
		{
			case "rat_armband_red_cross": { 
				_armbandRL = "Rat_armbandRC" createVehicle position _unit;
				_armbandRL attachTo [_unit, _unit getVariable [QGVAR(armbandSlingRightLegPos), [0, 0, 0]], "RightUpLeg", true];
				[_armbandRL, _unit getVariable [QGVAR(armbandSlingRightLegRot), [0, 0, 0]]] call BIS_fnc_setObjectRotation;

				_unit removeItem _armbandItem;
				_unit setVariable [QGVAR(isRightLegFree), false, true];
				_unit setVariable [QGVAR(whichArmabndisSlingedRL), _armbandRL, true];
			};

			case "rat_armband_medic": {
				_armbandRL = "Rat_armbandRCM" createVehicle position _unit;
				_armbandRL attachTo [_unit, _unit getVariable [QGVAR(armbandSlingRightLegPos), [0, 0, 0]], "RightUpLeg", true];
				[_armbandRL, _unit getVariable [QGVAR(armbandSlingRightLegRot), [0, 0, 0]]] call BIS_fnc_setObjectRotation;

				_unit removeItem _armbandItem;
				_unit setVariable [QGVAR(isRightLegFree), false, true];
				_unit setVariable [QGVAR(whichArmabndisSlingedRL), _armbandRL, true];
			};

			case "rat_armband_doctor": {
				_armbandRL = "Rat_armbandRCD" createVehicle position _unit;
				_armbandRL attachTo [_unit, _unit getVariable [QGVAR(armbandSlingRightLegPos), [0, 0, 0]], "RightUpLeg", true];
				[_armbandRL, _unit getVariable [QGVAR(armbandSlingRightLegRot), [0, 0, 0]]] call BIS_fnc_setObjectRotation;

				_unit removeItem _armbandItem;
				_unit setVariable [QGVAR(isRightLegFree), false, true];
				_unit setVariable [QGVAR(whichArmabndisSlingedRL), _armbandRL, true];
			};
		};
	};
};
