#include "script_component.hpp"
/*
 * Author: Miss Heda
 * Detaches a armband from a previously attached limb.
 *
 * Arguments:
 * 0: Player <OBJECT>
 * 1: Number
 *
 * Return Value:
 * None
 *
 * Example:
 * [player, 0] call rat_misc_fnc_unSlingArmband;
 *
 * Public: No
 */

params ["_unit", "_limbNumber"];

switch (_limbNumber) do 
{
    case 0: { 
        private _objectLA = _unit getVariable [QGVAR(whichArmabndisSlingedLA), ObjNull];

        switch (typeOf _objectLA) do
        {
            case "Rat_armbandRC": {
                [_unit, "rat_armband_red_cross"] call ACEFUNC(common,addToInventory);
                _unit setVariable [QGVAR(isLeftArmFree), true, true];
                deleteVehicle _objectLA;
            };

            case "Rat_armbandRCM": {
                [_unit, "rat_armband_medic"] call ACEFUNC(common,addToInventory);
                _unit setVariable [QGVAR(isLeftArmFree), true, true];
                deleteVehicle _objectLA;
            };

                case "Rat_armbandRCD": {
                [_unit, "rat_armband_doctor"] call ACEFUNC(common,addToInventory);
                _unit setVariable [QGVAR(isLeftArmFree), true, true];
                deleteVehicle _objectLA;
            };
        };
    };

    case 1: {
        private _objectRA = _unit getVariable [QGVAR(whichArmabndisSlingedRA), ObjNull];

        switch (typeOf _objectRA) do
        {
            case "Rat_armbandRC": {
                [_unit, "rat_armband_red_cross"] call ACEFUNC(common,addToInventory);
                _unit setVariable [QGVAR(isRightArmFree), true, true];
                deleteVehicle _objectRA;
            };

            case "Rat_armbandRCM": {
                [_unit, "rat_armband_medic"] call ACEFUNC(common,addToInventory);
                _unit setVariable [QGVAR(isRightArmFree), true, true];
                deleteVehicle _objectRA;
            };

            case "Rat_armbandRCD": {
                [_unit, "rat_armband_doctor"] call ACEFUNC(common,addToInventory);
                _unit setVariable [QGVAR(isRightArmFree), true, true];
                deleteVehicle _objectRA;
            };
        };
    };

    case 2: {
        private _objectLL = _unit getVariable [QGVAR(whichArmabndisSlingedLL), ObjNull];

        switch (typeOf _objectLL) do
        {
            case "Rat_armbandRC": {
                [_unit, "rat_armband_red_cross"] call ACEFUNC(common,addToInventory);
                _unit setVariable [QGVAR(isLeftLegFree), true, true];
                deleteVehicle _objectLL;
            };

            case "Rat_armbandRCM": {
                [_unit, "rat_armband_medic"] call ACEFUNC(common,addToInventory);
                _unit setVariable [QGVAR(isLeftLegFree), true, true];
                deleteVehicle _objectLL;
            };

            case "Rat_armbandRCD": {
                [_unit, "rat_armband_doctor"] call ACEFUNC(common,addToInventory);
                _unit setVariable [QGVAR(isLeftLegFree), true, true];
                deleteVehicle _objectLL;
            };
        };
    };

    case 3: {
        private _objectRL = _unit getVariable [QGVAR(whichArmabndisSlingedRL), ObjNull];

        switch (typeOf _objectRL) do
        {
            case "Rat_armbandRC": {
                [_unit, "rat_armband_red_cross"] call ACEFUNC(common,addToInventory);
                _unit setVariable [QGVAR(isRightLegFree), true, true];
                deleteVehicle _objectRL;
            };

            case "Rat_armbandRCM": {
                [_unit, "rat_armband_medic"] call ACEFUNC(common,addToInventory);
                _unit setVariable [QGVAR(isRightLegFree), true, true];
                deleteVehicle _objectRL;
            };

            case "Rat_armbandRCD": {
                [_unit, "rat_armband_doctor"] call ACEFUNC(common,addToInventory);
                _unit setVariable [QGVAR(isRightLegFree), true, true];
                deleteVehicle _objectRL;
            };
        };
    };
};