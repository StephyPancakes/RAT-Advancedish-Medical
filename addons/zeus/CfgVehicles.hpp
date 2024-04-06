class CfgVehicles {
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
        icon = QACEPATHTOF(medical_gui,data\categories\triage_card.paa);
        scope = 2;
    };

    class GVAR(toggleAIDeath_module): GVAR(baseModule) {
        author = "Blue";
        curatorCanAttach = 1;
        displayName = CSTRING(toggleAIDeath_Module_displayname);
        function = QFUNC(toggleAIDeathModule);
        icon = QPATHTOF(ui\Icon_Module_Zeus_Prevent_AI_Death.paa);
        scope = 2;
    };
};