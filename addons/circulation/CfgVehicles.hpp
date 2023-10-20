#define QQPATHTOF(var1) QUOTE(QPATHTOF(var1))

class CfgVehicles {
    class Item_Base_F;
    class Items_base_F;
    class WeaponHolder_Single_limited_item_F;
    class NATO_Box_Base;
    class ACE_medicalSupplyCrate: NATO_Box_Base {
        class TransportItems;
        class TransportMagazines;
    };

    class Land_Defibrillator_F: Items_base_F {
        ace_dragging_canCarry = 1;
        ace_dragging_carryPosition[] = {0,1,1};
        ace_dragging_carryDirection = 270;
        ace_cargo_size = 1;
        ace_cargo_canLoad = 1;
    };

    class rat_AEDItem: Item_Base_F {
        scope = 2;
        scopeCurator = 2;
        displayName = CSTRING(AED_DISPLAYNAME);
        author = "Katalam";
        vehicleClass = "Items";
        model = "\A3\Structures_F_EPA\Items\Medical\Defibrillator_F.p3d";
        class TransportItems {
            MACRO_ADDITEM(rat_AED,1);
        };
        ACEGVAR(dragging,canDrag) = 1;
        ACEGVAR(dragging,canCarry) = 1;
        ACEGVAR(dragging,dragPosition)[] = {0,1.1,1};
        ACEGVAR(dragging,carryPosition)[] = {0,1.1,1};
    };
	
    class rat_X_AEDItem: rat_AEDItem {
        displayName = CSTRING(X_Display);
        model = QPATHTOF(models\aedx\aedx.p3d);
        class TransportItems {
            MACRO_ADDITEM(rat_X_AED,1);
        };
    };

    class ACE_medicalSupplyCrate_advanced: ACE_medicalSupplyCrate {
        class TransportItems: TransportItems {
            MACRO_ADDITEM(rat_X_AED,1);
            MACRO_ADDITEM(rat_AED,1);
            MACRO_ADDITEM(RAT_Empty_bloodIV_500,10);
            MACRO_ADDITEM(RAT_Empty_bloodIV_250,20);
        };
        class TransportMagazines: TransportMagazines {
            MACRO_ADDMAGAZINE(rat_Painkiller,10);
        };
    };

    class Man;
    class CAManBase: Man {
        class ACE_Actions {
            class ACE_Head {
                class CheckBloodPressure {}; // Remove the ability to check blood pressure at the head
            };
        };
        class ACE_SelfActions {
            class Medical {
                class ACE_Head {
                    class CheckBloodPressure {};
                };
            };
            class ACE_Equipment {
                class AED_X_removeSound {
                    displayName = CSTRING(X_Action_removeSound);
                    condition = QUOTE('rat_X_AED' in (items _player) && (_player getVariable [ARR_2(QQGVAR(AED_X_Volume), false])));
                    statement = QUOTE(_player setVariable [ARR_3(QQGVAR(AED_X_Volume), false, true)]);
                    showDisabled = 0;
                    exceptions[] = {"isNotInside", "isNotSitting"};
                    icon = QPATHTOF(ui\X_Series-Device_W.paa);
                };
                class AED_X_addSound : AED_X_removeSound {
                    displayName = CSTRING(X_Action_addSound);
                    condition = QUOTE('rat_X_AED' in (items _player) && !(_player getVariable [ARR_2(QQGVAR(AED_X_Volume), false])));
                    statement = QUOTE(_player setVariable [ARR_3(QQGVAR(AED_X_Volume), true, true)]);
                };
                class openCrossPanel {
                    displayName = CSTRING(open_crosspanel);
                    condition = "('rat_crossPanel' in (uniformItems _player)) || ('rat_crossPanel' in (vestItems _player))";
                    statement = QUOTE(createDialog QQGVAR(CrossPanel_Dialog));
                    showDisabled = 0;
                    exceptions[] = {"isNotInside", "isNotSitting"};
                    icon = "";
                };
                class placeAED {
                    displayName=CSTRING(place_AED);
                    condition="'rat_AED' in (items ACE_player)";
                    exceptions[]=
                    {
                        "notOnMap",
                        "isNotInside",
                        "isNotHandcuffed",
                        "isNotSurrendering",
                        "isNotSwimming",
                        "isNotOnLadder"
                    };
                    statement="call rat_circulation_fnc_placeAED";
                    icon="";
                    showDisabled=0;
                };
            };
        };
    };
};
