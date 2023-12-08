#include "..\script_component.hpp"
/*
 * Author: YetheSamartaka
 * Ensures proper initial values reset on respawn
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Corpse <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [alive, body] call kat_misc_fnc_handleRespawn;
 *
 * Public: No
 */

params ["_unit","_dead"];
TRACE_2("handleRespawn",_unit,_dead);

if (!local _unit) exitWith {};

// KAT Circulation

//_unit setVariable [QEGVAR(circulation,X), false, true];
//_unit setVariable ["rat_AEDXPatient_PFH", nil];
//_unit setVariable [QEGVAR(circulation,AED_X_Volume), true, true];
//_unit setVariable [QEGVAR(circulation,AED_X_VolumePatient), false, true];
_unit setVariable [QEGVAR(circulation,use), false, true];
//_unit setVariable [QEGVAR(circulation,returnedAED), false, true];
_unit setVariable [QEGVAR(circulation,CPRcount), 2, true];
//_unit setVariable [QEGVAR(circulation,AEDinUse), false, true];


// KAT Misc
_unit setVariable [QEGVAR(misc,isLeftArmFree), true, true];
_unit setVariable [QEGVAR(misc,isRightArmFree), true, true];
_unit setVariable [QEGVAR(misc,isLeftLegFree), true, true];
_unit setVariable [QEGVAR(misc,isRightLegFree), true, true];

_unit setVariable [QGVAR(Tourniquet_ArmNecrosis), 0];
_unit setVariable [QGVAR(Tourniquet_LegNecrosis), 0];
_unit setVariable [QGVAR(Tourniquet_PFH), -1];
_unit setVariable [QGVAR(Tourniquet_LegNecrosis_Threshold), 0, true];

// KAT Pharmacy
_unit setVariable [QEGVAR(pharma,alphaAction), 1, true];
//_unit setVariable [QEGVAR(pharma,IV), [0,0,0,0,0,0], true];
//_unit setVariable [QEGVAR(pharma,IVpfh), [0,0,0,0,0,0], true];
_unit setVariable [QEGVAR(pharma,active), false, true];
//_unit setVariable [QEGVAR(pharma,IVPharma_PFH), nil, true];
_unit setVariable [QEGVAR(pharma,pervStartTime), 0];
_unit setVariable [QEGVAR(pharma,pervStage), 0];
_unit setVariable [QEGVAR(pharma,pervPFH), -1];

//KAT Chemical
_unit setVariable [QEGVAR(chemical,enteredPoison), false, true];
_unit setVariable [QEGVAR(chemical,timeleft), missionNamespace getVariable [QEGVAR(chemical,infectionTime),60], true];
_unit setVariable [QEGVAR(chemical,poisonType), "", true];
_unit setVariable [QEGVAR(chemical,airPoisoning), false, true];
_unit setVariable [QEGVAR(chemical,CS), false, true];
_unit setVariable [QEGVAR(chemical,gasmask_durability), 10, true];

"kat_CHEM_DETECTOR" cutRsc ["RscWeaponChemicalDetector", "PLAIN", 1, false];
private _ui = uiNamespace getVariable "RscWeaponChemicalDetector";
private _obj = _ui displayCtrl 101;
_obj ctrlAnimateModel ["Threat_Level_Source", 0, true];
if (_unit getVariable [QEGVAR(chemical,painEffect),0] != 0) then {
	KAT_PAIN_EFFECT ppEffectEnable false;
};

[{
	params ["_args", "_idPFH"];
	_args params ["_unit"];

	private _alive = alive _unit;

	if (!_alive) exitWith {
		[_idPFH] call CBA_fnc_removePerFrameHandler;
	};

	private _medicationArray = _unit getVariable [QACEGVAR(medical,medications), []];
	private _action = false;

	{
		_x params ["_medication"];

		if (_medication in ["Epinephrine", "Phenylephrine", "Nitroglycerin", "Lidocaine", "Norepinephrine"]) exitWith {
			_action = true;
		};
	} forEach (_medicationArray);

	if !(_action) then {
		_unit setVariable [QEGVAR(pharma,alphaAction), 1];
	};
}, 180, [_unit]] call CBA_fnc_addPerFrameHandler;


/// Clear Stamina & weapon sway
if (ACEGVAR(advanced_fatigue,enabled)) then {

	["rat_PDF"] call ACEFUNC(advanced_fatigue,removeDutyFactor);
	["rat_EDF"] call ACEFUNC(advanced_fatigue,removeDutyFactor);
	["rat_LSDF"] call ACEFUNC(advanced_fatigue,removeDutyFactor);
	ACEGVAR(advanced_fatigue,swayFactor) = EGVAR(pharma,originalSwayFactor);

} else {

	_unit enableStamina true;
	_unit setAnimSpeedCoef 1;
	_unit setCustomAimCoef 1;

};

/// Clear chroma effect & camera shake

resetCamShake;
["ChromAberration", 200, [ 0, 0, true ]] spawn
{
	params["_name", "_priority", "_effect", "_handle"];
	while
	{
		_handle = ppEffectCreate[_name, _priority];
		_handle < 0
	}
	do
	{
		_priority = _priority + 1;
	};
	_handle ppEffectEnable true;
	_handle ppEffectAdjust _effect;
	_handle ppEffectCommit 0;
	[
		{
			params["_handle"];
			ppEffectCommitted _handle
		},
		{
			params["_handle"];
			_handle ppEffectEnable false;
			ppEffectDestroy _handle;
		},
	[_handle]] call CBA_fnc_waitUntilAndExecute;
};

// Reenable ace fatige animationspeed override

if (!isNil QACEGVAR(advanced_fatigue,setAnimExclusions)) then {
	_index = ACEGVAR(advanced_fatigue,setAnimExclusions) find "PervitinOverride";
	if (_index != -1) then {
		ACEGVAR(advanced_fatigue,setAnimExclusions) deleteAt _index;
	};
};
