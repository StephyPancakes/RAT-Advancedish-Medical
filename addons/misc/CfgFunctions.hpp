class CfgFunctions {
    class ADDON {
        tag = "ace_interaction";
        class ace_interaction {
            class addPassengersActions {
                file = QPATHTOF(functions\fnc_addPassengersActions.sqf);
            };
        };
    };
	class overwrite_ace_dragging {
        tag = "ace_dragging";
        class ace_dragging {
            class carryObject {
                file = QPATHTOF(functions\fnc_carryObject.sqf);
            };
            class handleUnconscious {
                file = QPATHTOF(functions\fnc_handleUnconscious.sqf);
            };
        };
    };
    class overwrite_medical_treatment {
        tag = "ace_medical_treatment";
        class ace_medical_treatment {
            class hasItem {
                file = QPATHTOF(functions\fnc_hasItem.sqf);
            };
            class useItem {
                file = QPATHTOF(functions\fnc_useItem.sqf);
            };
        };
    };
};
