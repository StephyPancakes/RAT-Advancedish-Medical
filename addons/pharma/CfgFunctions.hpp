class CfgFunctions {
    class overwrite_ace_medical_status {
        tag = "ace_medical_status";
        class ace_medical_status {
            class getBloodVolumeChange {
                file = QPATHTOF(functions\fnc_getBloodVolumeChange.sqf);
            };
        };
    };
};