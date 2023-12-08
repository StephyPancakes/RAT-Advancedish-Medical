#include "script_component.hpp"

class CfgPatches {
    class ADDON    {
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        units[] = {
            "rat_sealant_Item",
            "rat_module_gas",
            "rat_module_zeus_gas",
            "RAT_Gas_TripWireMine"
        };
        weapons[] = {
            "rat_sealant",
            "rat_gasmaskFilter",
            "RAT_M7A3",
            "RAT_CAS_M43_Bomb",
            "RAT_CAS_R_80mm_GAS_POD"
        };
        ammo[] = {
            "RAT_Gas_TripWireMine_Ammo",
            "RAT_GASTripEffect",
            "RAT_GASTrip_SmokeEffect",
            "RAT_CAS_M43_Ammo",
            "RAT_CAS_M43_Ammo_sub",
            "RAT_CAS_R_80mm_GAS_AMMO"
        };
        magazines[] = {
            "RAT_CAS_M43_Mag"
        };
        requiredAddons[] = {
            "rat_main",
            "cba_settings",
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
            "ace_mk6mortar",
            "ace_csw"
        };
        author = "DiGii";
        url = ECSTRING(main,URL);
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgMagazineGroups.hpp"
#include "CfgAmmo.hpp"
#include "CfgCloudlets.hpp"
#include "CfgMagazines.hpp"
#include "CfgUIGrids.hpp"
#include "CfgWeapons.hpp"
#include "CfgVehicles.hpp"
#include "CfgSounds.hpp"
#include "ui\RscAttributes.hpp"
#include "ACE_Medical_Treatment_Actions.hpp"
#include "CfgGlasses.hpp"
