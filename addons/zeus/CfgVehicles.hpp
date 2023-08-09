class cfgVehicles {
    class Module_F;

    class GVAR(baseModule): Module_F {
        author   = "DiGi";
        category = QGVAR(RAT);
        function = QFUNC(emptyFunction);
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        scope = 1;
        scopeCurator = 2;
        side=7; 
    };

    class GVAR(checkmedical_module): GVAR(baseModule) {
        curatorCanAttach = 1;
        displayName = CSTRING(checkmedical_Module_displayname);
        function = QFUNC(openMedicalMenu);
        icon = "\z\ace\addons\medical_gui\data\categories\triage_card.paa";
    };

};