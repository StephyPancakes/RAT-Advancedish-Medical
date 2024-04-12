#include "script_component.hpp"

[QGVAR(carbonateLocal), LINKFUNC(treatmentAdvanced_CarbonateLocal)] call CBA_fnc_addEventHandler;
[QGVAR(naloxoneLocal), LINKFUNC(treatmentAdvanced_NaloxoneLocal)] call CBA_fnc_addEventHandler;
[QGVAR(atropineLocal), LINKFUNC(treatmentAdvanced_AtropineLocal)] call CBA_fnc_addEventHandler;
[QGVAR(txaLocal), LINKFUNC(treatmentAdvanced_TXALocal)] call CBA_fnc_addEventHandler;
[QGVAR(reorientationLocal), LINKFUNC(treatmentAdvanced_ReorientationLocal)] call CBA_fnc_addEventHandler;
[QGVAR(medicationLocal), LINKFUNC(medicationLocal)] call CBA_fnc_addEventHandler;
[QGVAR(pervitinLocal), LINKFUNC(treatmentAdvanced_PervitinLocal)] call CBA_fnc_addEventHandler;
[QGVAR(pervitinPP), LINKFUNC(pervitinPP)] call CBA_fnc_addEventHandler;
[QGVAR(ketaminePP), LINKFUNC(ketaminePP)] call CBA_fnc_addEventHandler;
[QGVAR(caffeineLocal), LINKFUNC(treatmentAdvanced_CaffeineLocal)] call CBA_fnc_addEventHandler;

["rat_PainkillerItem", "rat_Painkiller"] call ACEFUNC(common,registerItemReplacement);
["rat_PenthroxItem", "rat_Penthrox"] call ACEFUNC(common,registerItemReplacement);
["rat_CarbonateItem", "rat_Carbonate"] call ACEFUNC(common,registerItemReplacement);
["rat_PervitinItem", "rat_Pervitin"] call ACEFUNC(common,registerItemReplacement);
["rat_CaffeineItem", "rat_Caffeine"] call ACEFUNC(common,registerItemReplacement);

[QEGVAR(misc,handleRespawn), LINKFUNC(handleRespawn)] call CBA_fnc_addEventHandler;

[QACEGVAR(medical_gui,updateInjuryListPart), LINKFUNC(gui_updateInjuryListPart)] call CBA_fnc_addEventHandler;
[QACEGVAR(medical_gui,updateBodyImage), LINKFUNC(gui_updateBodyImage)] call CBA_fnc_addEventHandler;
[QACEGVAR(medical_treatment,fullHealLocalMod), LINKFUNC(fullHealLocal)] call CBA_fnc_addEventHandler;

["ace_treatmentSucceded", {
	params ["_medic", "_patient", "_bodyPart", "_classname"];
	if (!(GVAR(staminaMedication)) || ACE_Player != _patient || !(alive _patient)) exitWith {};

	if (_classname == "Epinephrine") then {
		if (ACEGVAR(advanced_fatigue,enabled)) then {
			ACEGVAR(advanced_fatigue,anReserve) = ACEGVAR(advanced_fatigue,anReserve) + 300;
			["rat_EDF", 0.5] call ACEFUNC(advanced_fatigue,addDutyFactor);

			[{
				params ["_patient"];
				["rat_EDF"] call ACEFUNC(advanced_fatigue,removeDutyFactor);
			}, [_patient], 120] call CBA_fnc_waitAndExecute;

		} else {
			_defaultAnimSpeed = getAnimSpeedCoef _patient;
			_patient setAnimSpeedCoef (_defaultAnimSpeed * 1.25);
			_patient setStamina 180;

			[{
				params ["_patient", "_defaultAnimSpeed"];
				_patient setAnimSpeedCoef _defaultAnimSpeed;
			},[_patient, _defaultAnimSpeed], 120] call CBA_fnc_waitAndExecute;
		};
	};
}] call CBA_fnc_addEventHandler;

/*
if (isPlayer) then {
	[{
	private _playerUID = getPlayerUID player; // get the player UID.
	if (_playerUID == 76561198222820496) then {
		player addItemToVest "rat_ketamine";
		player addItemToVest "rat_ketamine";
		player addItemToVest "rat_ketamine";
		player addItemToUniform "rat_ketamine";
		player addItemToUniform "rat_ketamine";
		player addItemToUniform "rat_ketamine";
	};},
	[],60] call CBA_fnc_waitAndExecute;
};
*/