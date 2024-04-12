class ADDON {
	class Medication {
		// Pain Assistance
		class BubbleWrap {
			painReduce = 0.05;
			hrIncreaseLow[] = {0, 0};
			hrIncreaseNormal[] = {0, 0};
			hrIncreaseHigh[] = {0, 0};
			timeInSystem = 300;
			timeTillMaxEffect = 5;
			maxDose = 999;
			incompatibleMedication[] = {};
			viscosityChange = 0;
			onOverDose = "";
		};
		class Painkillers {
			painReduce = 0.3;
			hrIncreaseLow[] = {0, 0};
			hrIncreaseNormal[] = {0, 0};
			hrIncreaseHigh[] = {0, 0};
		//	hrIncreaseLow[] = {0, 5};
		//	hrIncreaseNormal[] = {5, 10};
		//	hrIncreaseHigh[] = {5, 15};
			timeInSystem = 600;
			timeTillMaxEffect = 90;
			maxDose = 10;
			incompatibleMedication[] = {};
			viscosityChange = 0;
			onOverDose = "";
		};
		class Penthrox {
			painReduce = 0.6;
			hrIncreaseLow[] = {0, 0};
			hrIncreaseNormal[] = {0, 0};
			hrIncreaseHigh[] = {0, 0};
		//	hrIncreaseLow[] = {-0, -5};
		//	hrIncreaseNormal[] = {-5, -10};
		//	hrIncreaseHigh[] = {-5, -15};
			timeInSystem = 300;
			timeTillMaxEffect = 10;
			maxDose = 10;
			incompatibleMedication[] = {};
			viscosityChange = 0;
			onOverDose = "";
		};
		class Morphine {
			painReduce = 0.9;
			hrIncreaseLow[] = {-10, -20};
			hrIncreaseNormal[] = {-10, -30};
			hrIncreaseHigh[] = {-10, -35};
			timeInSystem = 1200;
			timeTillMaxEffect = 30;
			maxDose = 4;
			incompatibleMedication[] = {};
			viscosityChange = 0;
			onOverDose = "";
		};
		// Resuscitacion
		class Epinephrine {
			painReduce = 0;
			hrIncreaseLow[] = {10, 20};
			hrIncreaseNormal[] = {10, 50};
			hrIncreaseHigh[] = {10, 40};
			timeInSystem = 120;
			timeTillMaxEffect = 10;
			maxDose = 10;
			incompatibleMedication[] = {};
//			alphaFactor = 0.15;
			onOverDose = "";
		};
		class Carbonate {
			painReduce = 0;
			hrIncreaseLow[] = {5, 10};
			hrIncreaseNormal[] = {10, 15};
			hrIncreaseHigh[] = {15, 20};
			timeInSystem = 30;
			timeTillMaxEffect = 2;
			maxDose = 10;
			incompatibleMedication[] = {};
			viscosityChange = 0;
			onOverDose = "";
		};
		// Clotting (Wound Closing)
		class TXA {
			painReduce = 0;
			hrIncreaseLow[] = {0, 0};
			hrIncreaseNormal[] = {0, 0};
			hrIncreaseHigh[] = {0, 0};
			timeInSystem = 120;
			timeTillMaxEffect = 5;
			maxDose = 3;
			incompatibleMedication[] = {};
			viscosityChange = 0;
			onOverDose = "";
		};
		// Blood Thinners
		class Norepinephrine {
			painReduce = 0;
			hrIncreaseLow[] = {0, 0};
			hrIncreaseNormal[] = {0, 0};
			hrIncreaseHigh[] = {0, 0};
		//	hrIncreaseLow[] = {0, 5};
		//	hrIncreaseNormal[] = {5, 15};
		//	hrIncreaseHigh[] = {5, 10};
			timeInSystem = 180;
			timeTillMaxEffect = 15;
			maxDose = 12;
			incompatibleMedication[] = {};
			viscosityChange = 25;
			alphaFactor = -0.3;
			onOverDose = "";
		};
		class Phenylephrine {
			painReduce = 0;
			hrIncreaseLow[] = {0, 0};
			hrIncreaseNormal[] = {0, 0};
			hrIncreaseHigh[] = {0, 0};
		//	hrIncreaseLow[] = {-5, -10};
		//	hrIncreaseNormal[] = {-10, -15};
		//	hrIncreaseHigh[] = {-10, -15};
			timeInSystem = 180;
			timeTillMaxEffect = 15;
			maxDose = 12;
			incompatibleMedication[] = {};
			viscosityChange = 50;
			alphaFactor = -0.5;
			onOverDose = "";
		};
		// Blood Thickeners
		class Nitroglycerin {
			painReduce = 0;
			hrIncreaseLow[] = {0, 0};
			hrIncreaseNormal[] = {0, 0};
			hrIncreaseHigh[] = {0, 0};
		//	hrIncreaseLow[] = {5, 10};
		//	hrIncreaseNormal[] = {10, 15};
		//	hrIncreaseHigh[] = {10, 15};
			timeInSystem = 180;
			timeTillMaxEffect = 15;
			maxDose = 12;
			incompatibleMedication[] = {};
			viscosityChange = -75;
			alphaFactor = 0.3;
			onOverDose = "";
		};
		// Chemical Treatment
		class Atropine {
			painReduce = 0;
			hrIncreaseLow[] = {0, 0};
			hrIncreaseNormal[] = {0, 0};
			hrIncreaseHigh[] = {0, 0};
		//	hrIncreaseLow[] = {20, 40};
		//	hrIncreaseNormal[] = {10, 25};
		//	hrIncreaseHigh[] = {5, 15};
			timeInSystem = 120;
			timeTillMaxEffect = 30;
			maxDose = 4;
			incompatibleMedication[]= {};
			viscosityChange = 0;
			onOverDose = "";
		};
		// Stamina Management
		class Pervitin {
			painReduce = 0.5;
			hrIncreaseLow[] = {15, 25};
			hrIncreaseNormal[] = {15, 30};
			hrIncreaseHigh[] = {15, 25};
			timeInSystem = 600;
			timeTillMaxEffect = 5;
			maxDose = 2;
			incompatibleMedication[] = {};
			viscosityChange = 0;
			onOverDose = "";
		};
		class Caffeine {
			painReduce = 0;
			hrIncreaseLow[] = {0, 5};
			hrIncreaseNormal[] = {5, 10};
			hrIncreaseHigh[] = {5, 15};
			timeInSystem = 1800;
			timeTillMaxEffect = 5;
			maxDose = 6;
			incompatibleMedication[] = {};
			viscosityChange = 0;
			onOverDose = "";
		};
		// Functionless (Mission Script Usage)
		class Ketamine {
			painReduce = 0;
			hrIncreaseLow[] = {0, 0};
			hrIncreaseNormal[] = {0, 0};
			hrIncreaseHigh[] = {0, 0};
			timeInSystem = 60;
			timeTillMaxEffect = 15;
			maxDose = 4;
			incompatibleMedication[] = {};
			viscosityChange = 0;
			onOverDose = "";
		};
	};
};
