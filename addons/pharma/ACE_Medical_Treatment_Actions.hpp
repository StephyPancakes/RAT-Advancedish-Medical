class ACE_Medical_Treatment_Actions {
	class BasicBandage;
	class FieldDressing;
	class ApplyTourniquet;
	class RemoveTourniquet;
	class Morphine;
	class CheckPulse;
	class CPR;

	/*
	class BloodIV: BasicBandage {
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		medicRequired = QUOTE(ace_medical_treatment_medicIV);
		condition = QUOTE(!(GVAR(RequireInsIV)) || FUNC(removeIV));
		callbackSuccess = "[_medic, _patient, _bodyPart, _className, _itemUser, _usedItem] call ace_medical_treatment_fnc_ivBag; [_patient, 800, 12] call rat_pharma_fnc_fluid;";
	};
	class BloodIV_500: BloodIV {
		callbackSuccess = "[_medic, _patient, _bodyPart, _className, _itemUser, _usedItem] call ace_medical_treatment_fnc_ivBag; [_patient, 400, 8] call rat_pharma_fnc_fluid;";
	};
	class BloodIV_250: BloodIV {
		callbackSuccess = "[_medic, _patient, _bodyPart, _className, _itemUser, _usedItem] call ace_medical_treatment_fnc_ivBag; [_patient, 200, 4] call rat_pharma_fnc_fluid;";
	};
	class SalineIV: BloodIV {
		callbackSuccess = "[_medic, _patient, _bodyPart, _className, _itemUser, _usedItem] call ace_medical_treatment_fnc_ivBag; [_patient, -750, 0] call rat_pharma_fnc_fluid;";
	};
	class SalineIV_500: SalineIV {
		callbackSuccess = "[_medic, _patient, _bodyPart, _className, _itemUser, _usedItem] call ace_medical_treatment_fnc_ivBag; [_patient, -350, 0] call rat_pharma_fnc_fluid;";
	};
	class SalineIV_250: SalineIV {
		callbackSuccess = "[_medic, _patient, _bodyPart, _className, _itemUser, _usedItem] call ace_medical_treatment_fnc_ivBag; [_patient, -150, 0] call rat_pharma_fnc_fluid;";
	};
	class PlasmaIV: BloodIV {
		callbackSuccess = "[_medic, _patient, _bodyPart, _className, _itemUser, _usedItem] call ace_medical_treatment_fnc_ivBag; [_patient, 500, 15] call rat_pharma_fnc_fluid;";
	};
	class PlasmaIV_500: PlasmaIV {
		callbackSuccess = "[_medic, _patient, _bodyPart, _className, _itemUser, _usedItem] call ace_medical_treatment_fnc_ivBag; [_patient, 250, 10] call rat_pharma_fnc_fluid;";
	};
	class PlasmaIV_250: PlasmaIV {
		callbackSuccess = "[_medic, _patient, _bodyPart, _className, _itemUser, _usedItem] call ace_medical_treatment_fnc_ivBag; [_patient, 100, 5] call rat_pharma_fnc_fluid;";
	};
	*/
	class Morphine: FieldDressing {
		callbackSuccess = QFUNC(medication);
	};
	class Epinephrine: Morphine {
		callbackSuccess = QFUNC(medication);
	};
	class Painkillers: Morphine {
		displayName = CSTRING(Inject_Box_Painkillers);
		displayNameProgress = CSTRING(Using);
		allowedSelections[] = {"Head"};
		items[] = {"rat_Painkiller"};
		callbackSuccess = QFUNC(treatmentAdvanced_Painkillers);
		icon = QPATHTOF(ui\icon_painkillers_action.paa);
		animationPatient = "";
		animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
		animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon","rat_recoveryposition"};
		sounds[] = {{QPATHTO_R(sounds\take_painkillers.wav),5,1,15}};
		litter[] = {};
	};
	class Carbonate: Morphine {
		displayName = CSTRING(Take_Carbonate);
		displayNameProgress = CSTRING(Using);
		category = "medication";
		treatmentLocations = 0;
		allowedSelections[] = {"Head"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Carbonate);
		treatmentTime = QGVAR(treatmentTime_Carbonate);
		items[] = {"rat_Carbonate"};
		callbackSuccess = QFUNC(treatmentAdvanced_Carbonate);
		animationPatient = "";
		animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
		animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon","rat_recoveryposition"};
		sounds[] = {{QPATHTO_R(sounds\take_painkillers.wav),5,1,15}};
		litter[] = {};
	};
	class Pervitin: Morphine {
		displayName = CSTRING(Take_Pervitin);
		displayNameProgress = CSTRING(Using);
		allowedSelections[] = {"Head"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Pervitin);
		treatmentTime = QGVAR(treatmentTime_Pervitin);
		items[] = {"rat_Pervitin"};
		callbackSuccess = QFUNC(treatmentAdvanced_Pervitin);
		animationPatient = "";
		animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
		animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon","rat_recoveryposition"};
		sounds[] = {{QPATHTO_R(sounds\take_painkillers.wav),5,1,15}};
		litter[] = {};
	};
	class Caffeine: Morphine {
		displayName = CSTRING(Take_Caffeine);
		displayNameProgress = CSTRING(Using);
		allowedSelections[] = {"Head"};
		allowSelfTreatment = 1;
		treatmentTime = 5;
		items[] = {"rat_Caffeine"};
		callbackSuccess = QFUNC(treatmentAdvanced_Caffeine);
		animationPatient = "";
		animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
		animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon","rat_recoveryposition"};
		sounds[] = {{QPATHTO_R(sounds\take_painkillers.wav),5,1,15}};
		litter[] = {};
	};
	class Penthrox: Morphine {
		displayName = CSTRING(Use_Penthrox);
		displayNameProgress = CSTRING(Using);
		allowedSelections[] = {"Head"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Penthrox);
		treatmentTime = QGVAR(treatmentTime_Penthrox);
		items[] = {};
				
		callbackSuccess = QFUNC(treatmentAdvanced_Penthrox);
		condition = QUOTE([_patient] call ACEFUNC(common,isAwake) && ([ARR_2(_medic,'rat_Penthrox')] call ACEFUNC(common,hasMagazine) || [ARR_2(_patient,'rat_Penthrox')] call ACEFUNC(common,hasMagazine)));
		animationPatient = "";
		animationPatientProne = "";
		animationMedic = "";
		animationMedicProne = "";
		animationMedicSelf = "";
		animationMedicSelfProne = "";
		sounds[] = {{QPATHTO_R(sounds\use_penthrox.wav),2,1,7}};
		litter[] = {};
	};
	class Naloxone: Carbonate {
		displayName = CSTRING(Take_Naloxone);
		allowedSelections[] = {"Head"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Naloxone);
		treatmentTime = QGVAR(treatmentTime_Naloxone);
		items[] = {"rat_naloxone"};
		callbackSuccess = QFUNC(treatmentAdvanced_Naloxone);
		sounds[] = {};
	};
	class TXA: Carbonate {
		displayName = CSTRING(Take_TXA);
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_TXA);
		treatmentTime = QGVAR(treatmentTime_TXA);
		items[] = {"rat_TXA"};
		callbackSuccess = QFUNC(medication);
		sounds[] = {};
	};
	class Norepinephrine: Carbonate {
		displayName = CSTRING(Take_Norep);
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Norepinephrine);
		treatmentTime = QGVAR(treatmentTime_Norepinephrine);
		items[] = {"rat_norepinephrine"};
		callbackSuccess = QFUNC(medication);
		sounds[] = {};
	};
	class Phenylephrine: Carbonate {
		displayName = CSTRING(Take_Phenyl);
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Phenylephrine);
		treatmentTime = QGVAR(treatmentTime_Phenylephrine);
		items[] = {"rat_phenylephrine"};
		callbackSuccess = QFUNC(medication);
		sounds[] = {};
	};
	class Nitroglycerin: Carbonate {
		displayName = CSTRING(Take_Nitro);
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Nitroglicerin);
		treatmentTime = QGVAR(treatmentTime_Nitroglycerin);
		items[] = {"rat_nitroglycerin"};
		callbackSuccess = QFUNC(medication);
		sounds[] = {};
	};
	class Atropine: Carbonate {
		displayName = CSTRING(Take_Atropine);
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Atropine);
		treatmentTime = QGVAR(treatmentTime_Atropine);
		items[] = {"rat_atropine"};
		callbackSuccess = QFUNC(medication);
		sounds[] = {};
	};
	class Ketamine: Carbonate {
		displayName = CSTRING(Take_Ketamine);
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Ketamine);
		treatmentTime = QGVAR(treatmentTime_Ketamine);
		items[] = {"rat_ketamine"};
		callbackSuccess = QFUNC(medication);
		sounds[] = {};
	};
	class Reorientation: Carbonate {
		displayName = CSTRING(Take_Reorient);
		displayNameProgress = CSTRING(Reorienting);
		allowedSelections[] = {"Head"};
		allowSelfTreatment = 0;
		medicRequired = QGVAR(medLvl_Reorientation);
		treatmentTime = QGVAR(treatmentTime_Reorientation);
		items[] = {};
	//	condition = QUOTE(!([_patient] call ace_common_fnc_isAwake) && GVAR(Reorientation_Enable));
		condition = QUOTE(GVAR(Reorientation_Enable));
		litter[] = {};
		callbackSuccess = QFUNC(treatmentAdvanced_Reorientation);
		animationMedic = "AinvPknlMstpSnonWnonDnon_medicUp4";
		animationMedicProne = "AinvPknlMstpSnonWnonDnon_medicUp4";
		sounds[] = {};
	};
	class RemoveIV: ApplyTourniquet {
		displayName = CSTRING(Remove_IV);
		displayNameProgress = CSTRING(Removing_IV);
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		treatmentTime = 3;
		items[] = {};
	//	condition = QFUNC(removeIV);
		callbackSuccess = QFUNC(retrieveIV);
		sounds[] = {};
	};
};