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
};
