#include "script_component.hpp"
/*
 * Author: Mazinski.H
 * Analyzes the patient's heart rhythm
 *
 * Arguments:
 * 0: Unit <OBJECT>
 * 1: Target <OBJECT>
 *
 * Return Value:
 * <BOOLEAN>
 *
 * Example:
 * [player, cursorTarget] call kat_circulation_fnc_AED_analyze;
 *
 * Public: No
 */

params ["_medic", "_patient"];

private _bloodLoss = _patient getVariable [QACEGVAR(medical,bloodVolume), 6.0];
//private _asystole = _patient getVariable [QGVAR(asystole), 1];

//_patient setVariable [QGVAR(asystole), 1, true];
//_asystole = _patient getVariable [QGVAR(asystole), 1];


playsound3D [QPATHTOF_SOUND(sounds\analyse.wav), _patient, false, getPosASL _patient, 5, 1, 15];

// wait for the analyse and give the advise
if (_patient getVariable [QACEGVAR(medical,heartRate), 0] isEqualTo 0) then {
    [{
        params ["_patient"];
        playsound3D [QPATHTOF_SOUND(sounds\shock.wav), _patient, false, getPosASL _patient, 6, 1, 15];
    }, [_patient], 2] call CBA_fnc_waitAndExecute;
} else {
    [{
        params ["_patient"];
        playsound3D [QPATHTOF_SOUND(sounds\noshock.wav), _patient, false, getPosASL _patient, 6, 1, 15];
    }, [_patient], 2] call CBA_fnc_waitAndExecute;
};
