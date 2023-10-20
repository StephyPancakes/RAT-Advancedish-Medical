class CfgWeapons {
    class ACE_ItemCore;
    class CBA_MiscItem_ItemInfo;
    class ACE_bloodIV;

    class RAT_Empty_bloodIV_500: ACE_bloodIV
    {
        displayName = CSTRING(FieldBloodTK500_Display);
        descriptionShort = CSTRING(FieldBloodTK_Desc);
        picture = QPATHTOF(ui\bloodIV_empty_ca.paa);
        author = "Battlekeeper";
        hiddenSelectionsTextures[] = {QPATHTOF(ui\IVBag_blood_500ml_empty_ca.paa)};
        ACE_isMedicalItem = 1;
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
        ACE_isMedicalItem = 1;
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
        ACE_isMedicalItem = 1;
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
        ACE_isMedicalItem = 1;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 40;
        };
    };
};
