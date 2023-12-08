#include "script_component.hpp"

class CfgPatches {
    class ADDON    {
        name = COMPONENT_NAME;
        requiredVersion = REQUIRED_VERSION;
        units[] = {
            QGVAR(checkmedical_module),
            QGVAR(toggleAIDeath_module)
        };
        weapons[] = { };
        magazines[] = { };
        requiredAddons[] = {
            "rat_main",
            "ace_zeus",
            "cba_settings"
        };
        author = "DiGi";
        authors[] = {"Katalam"};
        url = ECSTRING(main,URL);
        VERSION_CONFIG;
    };
};

#include "CfgVehicles.hpp"
#include "CfgFactionClasses.hpp"
#include "CfgEventHandlers.hpp"
#include "ui\RscAttributes.hpp"