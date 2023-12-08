class CfgWeapons {
	class ACE_ItemCore;
	class CBA_MiscItem_ItemInfo;

	class rat_PainkillerItem: ACE_ItemCore {
		scope = 2; //This item is not actually used and it is replaced by ace_common_fnc_registerItemReplacement 
		author = "Katalam";
		displayName = CSTRING(Painkillers_Box_Display);
		picture = QPATHTOF(ui\icon_painkillers.paa);
        ACE_isMedicalItem = 1;
		class ItemInfo: CBA_MiscItem_ItemInfo {
			mass = 1;
		};
	};
	class rat_CarbonateItem: ACE_ItemCore {
		scope = 2; //This item is not actually used and it is replaced by ace_common_fnc_registerItemReplacement 
		author = "Mazinski.H";
		displayName = CSTRING(Carbonate_Box_Display);
		picture = QPATHTOF(ui\icon_Carbonate.paa);
        ACE_isMedicalItem = 1;
		class ItemInfo: CBA_MiscItem_ItemInfo {
			mass = 1;
		};
	};
	class rat_PervitinItem: ACE_ItemCore {
		scope = 2; //This item is not actually used and it is replaced by ace_common_fnc_registerItemReplacement 
		author = "Miss Heda";
		displayName = CSTRING(Pervitin_Capsule_Display);
		picture = QPATHTOF(ui\icon_Pervitin.paa);
		descriptionShort = CSTRING(Pervitin_Capsule_DescShort);
        ACE_isMedicalItem = 1;
		class ItemInfo: CBA_MiscItem_ItemInfo {
			mass = 0.1;
		}; 
	};
	class rat_CaffeineItem: ACE_ItemCore {
		scope = 2; //This item is not actually used and it is replaced by ace_common_fnc_registerItemReplacement 
		author = "Miss Heda";
		displayName = CSTRING(Caffeine_Bottle_Display);
		picture = QPATHTOF(ui\icon_Caffeine.paa);
		descriptionShort = CSTRING(Caffeine_Bottle_DescShort);
        ACE_isMedicalItem = 1;
		class ItemInfo: CBA_MiscItem_ItemInfo {
			mass = 0.1;
		}; 
	};
    class rat_PenthroxItem: ACE_ItemCore {
        scope = 2; //This item is not actually used and it is replaced by ace_common_fnc_registerItemReplacement 
        author = "Blue";
        displayName = CSTRING(Penthrox_Display);
        picture = QPATHTOF(ui\icon_penthrox.paa);
        ACE_isMedicalItem = 1;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 1;
        };
    };
	class rat_naloxone: ACE_ItemCore {
		scope = 2;
		displayName = CSTRING(Naloxone_Box_Display);
		picture = QPATHTOF(ui\icon_Naloxone.paa);
		model = "\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
		descriptionShort = CSTRING(Naloxone_DescShort);
        ACE_isMedicalItem = 1;
		class ItemInfo: CBA_MiscItem_ItemInfo {
			mass = 0.5;
		}; 
	};
	class rat_TXA: ACE_ItemCore {
		scope = 2;
		displayName = CSTRING(TXA_Box_Display);
		picture = QPATHTOF(ui\icon_TXA.paa);
		model = "\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
		descriptionShort = CSTRING(TXA_DescShort);
        ACE_isMedicalItem = 1;
		class ItemInfo: CBA_MiscItem_ItemInfo {
			mass = 0.5;
		}; 
	};
	class rat_norepinephrine: ACE_ItemCore {
		scope = 2;
		displayName = CSTRING(Norep_Box_Display);
		picture = QPATHTOF(ui\norep.paa);
		model = "\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
		descriptionShort = CSTRING(Norep_DescShort);
        ACE_isMedicalItem = 1;
		class ItemInfo: CBA_MiscItem_ItemInfo {
			mass = 0.5;
		}; 
	};
	class rat_phenylephrine: ACE_ItemCore {
		scope = 2;
		displayName = CSTRING(Phenyl_Box_Display);
		picture = QPATHTOF(ui\phen.paa);
		model = "\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
		descriptionShort = CSTRING(Phenyl_DescShort);
        ACE_isMedicalItem = 1;
		class ItemInfo: CBA_MiscItem_ItemInfo {
			mass = 0.5;
		}; 
	};
	class rat_nitroglycerin: ACE_ItemCore {
		scope = 2;
		displayName = CSTRING(Nitro_Box_Display);
		picture = QPATHTOF(ui\nitro.paa);
		model = "\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
		descriptionShort = CSTRING(Nitro_DescShort);
        ACE_isMedicalItem = 1;
		class ItemInfo: CBA_MiscItem_ItemInfo {
			mass = 0.5;
		}; 
	};
		class rat_atropine: ACE_ItemCore {
		scope = 2;
		displayName = CSTRING(Atropine_Box_Display);
		picture = QPATHTOF(ui\icon_Atropine.paa);
		model = "\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
		descriptionShort = CSTRING(Atropine_DescShort);
        ACE_isMedicalItem = 1;
		class ItemInfo: CBA_MiscItem_ItemInfo {
			mass = 0.5;
		}; 
	};
	class rat_ketamine: ACE_ItemCore {
		scope = 2;
		displayName = CSTRING(Ketamine_Box_Display);
		picture = QPATHTOF(ui\icon_Ketamine.paa);
		model = "\A3\Structures_F_EPA\Items\Medical\Painkillers_F.p3d";
		descriptionShort = CSTRING(Ketamine_DescShort);
        ACE_isMedicalItem = 1;
		class ItemInfo: CBA_MiscItem_ItemInfo {
			mass = 0.5;
		}; 
	};
};
