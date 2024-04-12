#include "script_component.hpp"

[QACEGVAR(medical_gui,updateBodyImage), LINKFUNC(gui_updateBodyImage)] call CBA_fnc_addEventHandler;
[QACEGVAR(medical_treatment,fullHealLocalMod), LINKFUNC(fullHealLocal)] call CBA_fnc_addEventHandler;

//["ace_cardiacArrest", LINKFUNC(handleCardiacArrest)] call CBA_fnc_addEventHandler;

//GVAR(AEDX_MonitorTarget) = objNull;

["isNotPerformingCPR", {!((_this select 0) getVariable [QGVAR(isPerformingCPR), false])}] call ACEFUNC(common,addCanInteractWithCondition);
/*
[QGVAR(setPreferredBloodType), {
	params ["_unit"];
	_unit setVariable [QGVAR(bloodTypePlayer), (profileNamespace getVariable [QGVAR(preferredBloodType), "O_N"]), true];
}] call CBA_fnc_addEventHandler;
*/

[QEGVAR(misc,handleRespawn), LINKFUNC(handleRespawn)] call CBA_fnc_addEventHandler;