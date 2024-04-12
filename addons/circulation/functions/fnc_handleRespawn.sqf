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

_unit setVariable [QGVAR(StoredBloodPressure), [0,0], true];

[_unit] call FUNC(fullHealLocal);
