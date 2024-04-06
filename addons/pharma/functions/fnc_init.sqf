#include "..\script_component.hpp"
/*
 * Author: Katalam
 * Initializes unit variables.
 *
 * Arguments:
 * 0: Unit <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player] call kat_pharma_fnc_init;
 *
 * Public: No
 */

params ["_unit", ["_isRespawn", true]];

if (!local _unit) exitWith {};

//_unit setVariable [QGVAR(IV), [0,0,0,0,0,0], true];
//_unit setVariable [QGVAR(IVpfh), [0,0,0,0,0,0], true];

/*
* 0 = No IV
* 1 = IO
* 2 = IV
* 3 = IV w/ Block
* 4 = IV w/ Flush
*/

[_unit] call FUNC(fullHealLocal);

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

		if (_medication in ["Epinephrine", "Phenylephrine", "Nitroglycerin", "Norepinephrine"]) exitWith {
			_action = true;
		};
	} forEach (_medicationArray);

	if !(_action) then {
		ACEGVAR(medical,const_minCardiacOutput) = (_unit getVariable [QGVAR(alphaAction), 1]) * EGVAR(circulation,cardiacArrestBleedRate);
		_unit setVariable [QGVAR(alphaAction), 1];
	};
}, 180, [_unit]] call CBA_fnc_addPerFrameHandler;
