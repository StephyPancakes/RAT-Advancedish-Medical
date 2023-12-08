#include "..\script_component.hpp"
/*
 * Author: Battlekeeper, modified by YetheSamartaka
 * Refactored by Slatery
 * Handles drawing of blood into a bag
 *
 * Arguments:
 * 0: Medic <OBJECT>
 * 1: Patient <OBJECT>
 * 2: Volume of Blood to remove (in milliliters) <NUMBER>
 *
 * Return Value:
 * None
 *
 * Example:
 * [medic, medic, 500] call kat_circulation_fnc_drawBlood;
 *
 * Public: No
 */

params ["_medic", "_patient", "_volume"];

//private _modStr = "ACE_";
private _bagVolumeStr = toString _volume; 
private _volumeChange = _volume/1000;
private _bloodVolume = (_patient getVariable [QACEGVAR(medical,bloodVolume), 6.0]);
private _itemStr = format ["ACE_bloodIV_%3",_bagVolumeStr];
_medic addItem _itemStr;
_patient setVariable [QACEGVAR(medical,bloodVolume), _bloodVolume - _volumeChange,true];
