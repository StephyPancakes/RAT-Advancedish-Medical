#include "..\script_component.hpp"
/*
 * Author: Miss Heda,
 * Contributers: YonV, MiszczuZPolski, Rat
 *
 *
 * Arguments:
 * 0: Patient <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [player] call rat_pharma_fnc_treatmentAdvanced_PervitinLocal;
 *
 * Public: No
 */

params ["_patient"];

if (ACE_Player != _patient) exitWith {};

private _startTime = time;
_patient setVariable [QGVAR(pervStage), 0];

_patient addEventHandler ["Killed", 
	{
		params ["_patient"];
		private _pervPFH =  _patient getVariable [QGVAR(pervPFH), _idPFH];
		_patient setVariable [QGVAR(pervStage), 0];
		if (GVAR(weapon_sway_pervitin)) then {
			_patient setCustomAimCoef 1;
		};
		if (ACEGVAR(advanced_fatigue,enabled)) then {
			["rat_PDF", 0] call ACEFUNC(advanced_fatigue,removeDutyFactor);
			if (!isNil QACEGVAR(advanced_fatigue,setAnimExclusions)) then {
				private _index = ACEGVAR(advanced_fatigue,setAnimExclusions) find "PervitinOverride";
				if (_index != -1) then {
					ACEGVAR(advanced_fatigue,setAnimExclusions) deleteAt _index;
				};
			};
		} else {
			_patient enableStamina true;
		};
		_patient setAnimSpeedCoef 1;
		[_pervPFH] call CBA_fnc_removePerFrameHandler;
		_patient removeEventHandler [_thisEvent, _thisEventHandler];
	}];

private _pervPFH = [{
	params ["_args", "_idPFH"];
	_args params ["_patient", "_startTime"];
	//["Pervitin Taken", 2, _patient] call ACEFUNC(common,displayTextStructured);
	
	if (!(alive _patient) || _startTime == 0) exitWith {
		_patient setVariable [QGVAR(pervStage), 0];
		_patient setAnimSpeedCoef 1;
		if (GVAR(weapon_sway_pervitin)) then {
			_patient setCustomAimCoef 1;
		};
		if (ACEGVAR(advanced_fatigue,enabled)) then {
			["rat_PDF", 0] call ACEFUNC(advanced_fatigue,removeDutyFactor);
			if (!isNil QACEGVAR(advanced_fatigue,setAnimExclusions)) then {
				private _index = ACEGVAR(advanced_fatigue,setAnimExclusions) find "PervitinOverride";
				if (_index != -1) then {
					ACEGVAR(advanced_fatigue,setAnimExclusions) deleteAt _index;
				};
			};
		} else {
			_patient enableStamina true;
		};
		[_idPFH] call CBA_fnc_removePerFrameHandler;
	};
	
	private _pervPFH = _patient getVariable [QGVAR(pervPFH), _idPFH];
	if !(_pervPFH == _idPFH) exitWith {
		[_idPFH] call CBA_fnc_removePerFrameHandler;
	};
	
	private _curTime = time;
	private _stage = _patient getVariable [QGVAR(pervStage), 0];
	
//	private _debugString = format ["%1 - %2 / %3 / %4 - %5", _startTime, _curTime, _stage, _pervPFH, _idPFH];
//	[_debugString, 2, _patient] call ACEFUNC(common,displayTextStructured);
	
	// Stage 1 - 30s - Start, Max Stamina, No sway
	if ((_startTime + 25 <= _curTime) && _stage == 0) exitWith {
		_patient setVariable [QGVAR(pervStage), 1];
		
		if (ACEGVAR(advanced_fatigue,enabled)) then {
			ACEGVAR(advanced_fatigue,anReserve) = ACEGVAR(advanced_fatigue,anReserve) + 3000;
			["rat_PDF", 0] call ACEFUNC(advanced_fatigue,addDutyFactor);
			if (!isNil QACEGVAR(advanced_fatigue,setAnimExclusions)) then {
				ACEGVAR(advanced_fatigue,setAnimExclusions) pushBack "PervitinOverride";
			};
		} else {
			_patient enableStamina false;
		};
		
		if (GVAR(weapon_sway_pervitin)) then {
			_patient setCustomAimCoef 1;
			_patient setCustomAimCoef(getCustomAimCoef _patient) - 0.7;
		};

		_patient setAnimSpeedCoef (1 * (GVAR(pervitinSpeed)));
		
		[LLSTRING(Pervitin_start), 2, _patient] call ACEFUNC(common,displayTextStructured); 
	};
	
	// Stage 2 - 60s - Aim Disruption
	if ((_startTime + 55 <= _curTime) && _stage == 1) exitWith {
		_patient setVariable [QGVAR(pervStage), 2];

		if (GVAR(weapon_sway_pervitin)) then {
			_patient setCustomAimCoef(getCustomAimCoef _patient) + 0.2;
		};
	};
	
	// Stage 3 - 90s - Aim Disruption
	if (_startTime + 89 <= _curTime && _stage == 2) exitWith {
		_patient setVariable [QGVAR(pervStage), 3];

		if (GVAR(weapon_sway_pervitin)) then {
			_patient setCustomAimCoef(getCustomAimCoef _patient) + 0.5;
		};
	};
	
	// Stage 4 - 120s - Aim Disruption
	if ((_startTime + 115 <= _curTime) && _stage == 3) exitWith {
		_patient setVariable [QGVAR(pervStage), 4];

		if (GVAR(weapon_sway_pervitin)) then {
			_patient setCustomAimCoef(getCustomAimCoef _patient) + 0.3;
		};
	};
	
	// Stage 5 - 150s - Aim Disruption
	if (_startTime + 149 <= _curTime && _stage == 4) exitWith {
		_patient setVariable [QGVAR(pervStage), 5];

		if (GVAR(weapon_sway_pervitin)) then {
			_patient setCustomAimCoef(getCustomAimCoef _patient) + 0.5;
		};
	};
	
	// Stage 6 - 180s
	if ((_startTime + 175 <= _curTime) && _stage == 5) exitWith {
		_patient setVariable [QGVAR(pervStage), 6];
		
		if (ACEGVAR(advanced_fatigue,enabled)) then {
			["rat_PDF"] call ACEFUNC(advanced_fatigue,removeDutyFactor);
			if (!isNil QACEGVAR(advanced_fatigue,setAnimExclusions)) then {
				private _index = ACEGVAR(advanced_fatigue,setAnimExclusions) find "PervitinOverride";
				if (_index != -1) then {
					ACEGVAR(advanced_fatigue,setAnimExclusions) deleteAt _index;
				};
			};
		} else {
			_patient enableStamina true;
		};
		
		if (GVAR(weapon_sway_pervitin)) then {
			_patient setCustomAimCoef(getCustomAimCoef _patient) + 0.2;
		};

		_patient setAnimSpeedCoef 1;
		
		[LLSTRING(Pervitin_mid), 2, _patient] call ACEFUNC(common,displayTextStructured);
	};
	
	// Stage 7 - 210s - Aim Disruption
	if ((_startTime + 209 <= _curTime) && _stage == 6) exitWith {
		_patient setVariable [QGVAR(pervStage), 7];

		if (GVAR(weapon_sway_pervitin)) then {
			_patient setCustomAimCoef(getCustomAimCoef _patient) + 0.3;
		};
	};
	
	// Stage 8 - 240s
	if ((_startTime + 239 <= _curTime) && _stage == 7) exitWith {
		_patient setVariable [QGVAR(pervStage), 8];
		
		if (ACEGVAR(advanced_fatigue,enabled)) then {
			ACEGVAR(advanced_fatigue,anReserve) = ACEGVAR(advanced_fatigue,anReserve) + 3000;
			["rat_PDF", 0.4] call ACEFUNC(advanced_fatigue,addDutyFactor);
		} else {
			_patient setStamina(getStamina _patient + 300);
		};
		
		if (GVAR(weapon_sway_pervitin)) then {
			_patient setCustomAimCoef(getCustomAimCoef _patient) - 0.3;
		};
		
		[LLSTRING(Pervitin_mid2), 2, _patient] call ACEFUNC(common,displayTextStructured);
	};
	
	// Stage 9 - 360s
	if ((_startTime + 359 <= _curTime) && _stage == 8) exitWith {
		_patient setVariable [QGVAR(pervStage), 9];
		
		if (ACEGVAR(advanced_fatigue,enabled)) then {
			ACEGVAR(advanced_fatigue,anReserve) = ACEGVAR(advanced_fatigue,anReserve) + 3000;
			["rat_PDF", 0.6] call ACEFUNC(advanced_fatigue,addDutyFactor);
		} else {
			_patient setStamina(getStamina _patient + 300);
		};
		
		if (GVAR(weapon_sway_pervitin)) then {
			_patient setCustomAimCoef(getCustomAimCoef _patient) - 0.2;
		};
		
		[LLSTRING(Pervitin_mid3), 2, _patient] call ACEFUNC(common,displayTextStructured);
	};
	
	// Stage 10 - 510s
	if ((_startTime + 509 <= _curTime) && _stage == 9) exitWith {
		_patient setVariable [QGVAR(pervStage), 10];
		
		if (ACEGVAR(advanced_fatigue,enabled)) then {
			["rat_PDF", 2] call ACEFUNC(advanced_fatigue,addDutyFactor);
		} else {
			_patient setStamina(getStamina _patient - 60);
		};
		
		if (GVAR(weapon_sway_pervitin)) then {
			_patient setCustomAimCoef 1;
		};
		
		[LLSTRING(Pervitin_mid4), 2, _patient] call ACEFUNC(common,displayTextStructured);
	};
	
	// Stage 11 - 600s
	if ((_startTime + 180 <= _curTime) && _stage == 10) exitWith {
		_patient setVariable [QGVAR(pervStage), 0];
		
		if (ACEGVAR(advanced_fatigue,enabled)) then {
			["rat_PDF"] call ACEFUNC(advanced_fatigue,removeDutyFactor);
		};
		
		[LLSTRING(Pervitin_end), 2, _patient] call ACEFUNC(common,displayTextStructured);
		
		[_idPFH] call CBA_fnc_removePerFrameHandler;
	};
	

}, 30, [_patient, _startTime]] call CBA_fnc_addPerFrameHandler;

_patient setVariable [QGVAR(pervPFH), _pervPFH];

// ChromAberration & CamShake effect
[QGVAR(pervitinPP), [_patient], _patient] call CBA_fnc_targetEvent;