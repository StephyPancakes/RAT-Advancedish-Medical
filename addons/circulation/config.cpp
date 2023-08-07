#include "script_component.hpp"

class CfgPatches {
    class ADDON    {
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        units[] = {
            "rat_X_AEDItem",
            "rat_bloodBankCrate"
        };
        weapons[] = {
            "rat_bloodIV_O",
            "rat_bloodIV_O_N",
            "rat_bloodIV_A",
            "rat_bloodIV_A_N",
            "rat_bloodIV_B",
            "rat_bloodIV_B_N",
            "rat_bloodIV_AB",
            "rat_bloodIV_AB_N",
            "rat_bloodIV_O_500",
            "rat_bloodIV_O_N_500",
            "rat_bloodIV_A_500",
            "rat_bloodIV_A_N_500",
            "rat_bloodIV_B_500",
            "rat_bloodIV_B_N_500",
            "rat_bloodIV_AB_500",
            "rat_bloodIV_AB_N_500",
            "rat_bloodIV_O_250",
            "rat_bloodIV_O_N_250",
            "rat_bloodIV_A_250",
            "rat_bloodIV_A_N_250",
            "rat_bloodIV_B_250",
            "rat_bloodIV_B_N_250",
            "rat_bloodIV_AB_250",
            "rat_bloodIV_AB_N_250",
            "rat_X_AED",
            "rat_crossPanel",
            "RAT_Empty_bloodIV_500",
            "RAT_Empty_bloodIV_250"
        };
        magazines[] = { };
        requiredAddons[] = {
            "ace_medical",
            "ace_medical_ai",
            "ace_medical_blood",
            "ace_medical_damage",
            "ace_medical_engine",
            "ace_medical_feedback",
            "ace_medical_gui",
            "ace_medical_statemachine",
            "ace_medical_status",
            "ace_medical_treatment",
            "ace_medical_vitals",
            "ace_dogtags",
            "cba_settings",
            "rat_main"
        };
        author = "Katalam";
        authors[] = {"Katalam"};
        url = ECSTRING(main,URL);
        VERSION_CONFIG;
    };
};

#include "CfgFunctions.hpp"
#include "CfgEventHandlers.hpp"
#include "CfgSounds.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
#include "ACE_Medical_Treatment.hpp"
#include "ACE_Medical_Treatment_Actions.hpp"
#include "ui\CrossPanel_Dialog.hpp"
