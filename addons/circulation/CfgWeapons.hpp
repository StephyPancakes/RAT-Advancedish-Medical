class CfgWeapons {
    class ACE_ItemCore;
    class CBA_MiscItem_ItemInfo;
    class ACE_bloodIV;

    class rat_bloodIV_O: ACE_bloodIV {
        displayName = CSTRING(BloodIV_O);
    };
    class rat_bloodIV_O_N: ACE_bloodIV {
        displayName = CSTRING(BloodIV_O_N);
    };
    class rat_bloodIV_A: ACE_bloodIV {
        displayName = CSTRING(BloodIV_A);
    };
    class rat_bloodIV_A_N: ACE_bloodIV {
        displayName = CSTRING(BloodIV_A_N);
    };
    class rat_bloodIV_B: ACE_bloodIV {
        displayName = CSTRING(BloodIV_B);
    };
    class rat_bloodIV_B_N: ACE_bloodIV {
        displayName = CSTRING(BloodIV_B_N);
    };
    class rat_bloodIV_AB: ACE_bloodIV {
        displayName = CSTRING(BloodIV_AB);
    };
    class rat_bloodIV_AB_N: ACE_bloodIV {
        displayName = CSTRING(BloodIV_AB_N);
    };
    class ACE_bloodIV_500;
    class rat_bloodIV_O_500: ACE_bloodIV_500 {
        displayName = CSTRING(BloodIV_O_500);
    };
    class rat_bloodIV_O_N_500: ACE_bloodIV_500 {
        displayName = CSTRING(BloodIV_O_500_N);
    };
    class rat_bloodIV_A_500: ACE_bloodIV_500 {
        displayName = CSTRING(BloodIV_A_500);
    };
    class rat_bloodIV_A_N_500: ACE_bloodIV_500 {
        displayName = CSTRING(BloodIV_A_500_N);
    };
    class rat_bloodIV_B_500: ACE_bloodIV_500 {
        displayName = CSTRING(BloodIV_B_500);
    };
    class rat_bloodIV_B_N_500: ACE_bloodIV_500 {
        displayName = CSTRING(BloodIV_B_500_N);
    };
    class rat_bloodIV_AB_500: ACE_bloodIV_500 {
        displayName = CSTRING(BloodIV_AB_500);
    };
    class rat_bloodIV_AB_N_500: ACE_bloodIV_500 {
        displayName = CSTRING(BloodIV_AB_500_N);
    };
    class ACE_bloodIV_250;
    class rat_bloodIV_O_250: ACE_bloodIV_250 {
        displayName = CSTRING(BloodIV_O_250);
    };
    class rat_bloodIV_O_N_250: ACE_bloodIV_250 {
        displayName = CSTRING(BloodIV_O_250_N);
    };
    class rat_bloodIV_A_250: ACE_bloodIV_250 {
        displayName = CSTRING(BloodIV_A_250);
    };
    class rat_bloodIV_A_N_250: ACE_bloodIV_250 {
        displayName = CSTRING(BloodIV_A_250_N);
    };
    class rat_bloodIV_B_250: ACE_bloodIV_250 {
        displayName = CSTRING(BloodIV_B_250);
    };
    class rat_bloodIV_B_N_250: ACE_bloodIV_250 {
        displayName = CSTRING(BloodIV_B_250_N);
    };
    class rat_bloodIV_AB_250: ACE_bloodIV_250 {
        displayName = CSTRING(BloodIV_AB_250);
    };
    class rat_bloodIV_AB_N_250: ACE_bloodIV_250 {
        displayName = CSTRING(BloodIV_AB_250_N);
    };
    class RAT_Empty_bloodIV_500: ACE_bloodIV
    {
        displayName = CSTRING(FieldBloodTK500_Display);
        descriptionShort = CSTRING(FieldBloodTK_Desc);
        picture = QPATHTOF(ui\bloodIV_empty_ca.paa);
        author = "Battlekeeper";
        hiddenSelectionsTextures[] = {QPATHTOF(ui\IVBag_blood_500ml_empty_ca.paa)};
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 2;
        };
    };
    class RAT_Empty_bloodIV_250: ACE_bloodIV
    {
        displayName = CSTRING(FieldBloodTK250_Display);
        descriptionShort = CSTRING(FieldBloodTK_Desc);
        picture = QPATHTOF(ui\bloodIV_empty_ca.paa);
        author = "Battlekeeper";
        hiddenSelectionsTextures[] = {QPATHTOF(ui\IVBag_blood_500ml_empty_ca.paa)};
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };
    class rat_AED: ACE_ItemCore {
        scope = 2;
        author = "Katalam";
        displayName = CSTRING(AED_DISPLAYNAME);
        picture = QPATHTOF(ui\defib.paa);
        model = "\A3\Structures_F_EPA\Items\Medical\Defibrillator_F.p3d";
        descriptionShort = CSTRING(AED_DESCRIPTION);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 30;
        };
    };
    class rat_X_AED: rat_AED {
        scope = 2;
        displayName = CSTRING(X_Display);
        picture = QPATHTOF(ui\x-series.paa);
        model = QPATHTOF(models\aedx\aedx.p3d);
        descriptionShort = CSTRING(X_Desc);
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 40;
        };
    };
    class rat_crossPanel: ACE_ItemCore {
        scope = 2;
        author = "Katalam";
        displayName = CSTRING(crosspanel);
        descriptionShort = CSTRING(desc_crosspanel);
        picture = QPATHTOF(ui\crosspanel.paa);
        icon = "";
        mapSize = 0.034;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 0.1;
        };
    };
};
