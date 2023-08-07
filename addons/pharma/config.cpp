#include "script_component.hpp"

class CfgPatches {
    class ADDON    {
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        units[] = {
            "rat_PainkillerItem",
            "rat_X_AEDItem"
        };
        weapons[] = {
            "rat_Painkiller",
            "rat_PainkillerItem",
            "rat_IV_16",
            "rat_IO_FAST",
            "rat_Carbonate",
            "rat_CarbonateItem",
            "rat_naloxone",
            "rat_EACA",
            "rat_TXA",
            "rat_X_AED",
            "rat_norepinephrine",
            "rat_phenylephrine",
            "rat_nitroglycerin",
            "rat_amiodarone",
            "rat_lidocane",
            "rat_atropine",
            "rat_ketamine",
            "rat_fentanyl",
            "rat_nalbuphine",
            "rat_flumazenil",
            "rat_lorazepam",
            "rat_etomidate"
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
            "cba_settings"
        };
        author = "Katalam";
        authors[] = {"Katalam", "2LT.Mazinski", "MiszczuZPolski"};
        url = ECSTRING(main,URL);
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgSounds.hpp"
#include "CfgWeapons.hpp"
#include "CfgMagazines.hpp"
#include "CfgVehicles.hpp"
#include "CfgFunctions.hpp"
#include "ACE_Medical_Treatment.hpp"
#include "ACE_Medical_Treatment_Actions.hpp"