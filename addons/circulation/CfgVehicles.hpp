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

	class ACE_medicalSupplyCrate_advanced: ACE_medicalSupplyCrate {
		class TransportItems: TransportItems {
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
		};
	};
};
