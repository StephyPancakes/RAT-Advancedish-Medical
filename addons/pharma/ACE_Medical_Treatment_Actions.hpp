class ACE_Medical_Treatment_Actions {
	class BasicBandage;
	class FieldDressing;
	class ApplyTourniquet;
	class RemoveTourniquet;
	class Morphine;
	class CheckPulse;
	class CPR;
	class Defibrillator;
	class Defibrillator_AED_X_Vehicle;

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
		callbackSuccess = QFUNC(treatmentAdvanced_medication);
	};
	class Epinephrine: Morphine {
		callbackSuccess = QFUNC(treatmentAdvanced_medication);
	};
	class Painkillers: Morphine {
		displayName = CSTRING(Inject_Box_Painkillers);
		displayNameProgress = CSTRING(Using);
		allowedSelections[] = {"Head"};
		items[] = {"rat_Painkiller"};
		callbackSuccess = QFUNC(treatmentAdvanced_Painkillers);
		litter[] = {};
		icon = QPATHTOF(ui\icon_painkillers_action.paa);
		animationPatient = "";
		animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
		animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon"};
		sounds[] = {{QPATHTO_R(sounds\take_painkillers.wav),5,1,15}};
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
		litter[] = {};
		callbackSuccess = QFUNC(treatmentAdvanced_Carbonate);
		sounds[] = {{QPATHTO_R(sounds\take_painkillers.wav),5,1,15}};
	};
	class Pervitin: Morphine {
		displayName = CSTRING(Take_Pervitin);
		displayNameProgress = CSTRING(Using);
		allowedSelections[] = {"Head"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Pervitin);
		treatmentTime = QGVAR(treatmentTime_Pervitin);
		items[] = {"rat_Pervitin"};
		litter[] = {};
		callbackSuccess = QFUNC(treatmentAdvanced_Pervitin);
		sounds[] = {{QPATHTO_R(sounds\take_painkillers.wav),5,1,15}};
	};
	class Caffeine: Morphine {
		displayName = CSTRING(Take_Caffeine);
		displayNameProgress = CSTRING(Using);
		allowedSelections[] = {"Head"};
		allowSelfTreatment = 1;
		treatmentTime = 5;
		items[] = {"rat_Caffeine"};
		litter[] = {};
		callbackSuccess = QFUNC(treatmentAdvanced_Caffeine);
		sounds[] = {{QPATHTO_R(sounds\take_painkillers.wav),5,1,15}};
	};
	class Naloxone: Carbonate {
		displayName = CSTRING(Take_Naloxone);
		allowedSelections[] = {"Head"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Naloxone);
		treatmentTime = QGVAR(treatmentTime_Naloxone);
		items[] = {"rat_naloxone"};
		condition = "true";
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
		callbackSuccess = QFUNC(treatmentAdvanced_TXA);
		sounds[] = {};
	};
	/*
	class SalineFlush: Carbonate {
		displayName = CSTRING(Saline_Flush);
		allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 1;
		medicRequired = 1;
		treatmentTime = 3;
		items[] = {};
		condition = QUOTE((_patient getVariable [ARR_2(QQGVAR(IVplaced), true)]) && FUNC(salineCheck));
		callbackSuccess = QFUNC(treatmentAdvanced_Flush);
		sounds[] = {};
	};
	*/
	class Norepinephrine: Carbonate {
		displayName = CSTRING(Take_Norep);
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Norepinephrine);
		treatmentTime = QGVAR(treatmentTime_Norepinephrine);
		items[] = {"rat_norepinephrine"};
		callbackSuccess = QFUNC(treatmentAdvanced_medication);
		sounds[] = {};
	};
	class Phenylephrine: Carbonate {
		displayName = CSTRING(Take_Phenyl);
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Phenylephrine);
		treatmentTime = QGVAR(treatmentTime_Phenylephrine);
		items[] = {"rat_phenylephrine"};
		callbackSuccess = QFUNC(treatmentAdvanced_medication);
		sounds[] = {};
	};
	class Nitroglycerin: Carbonate {
		displayName = CSTRING(Take_Nitro);
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Nitroglicerin);
		treatmentTime = QGVAR(treatmentTime_Nitroglycerin);
		items[] = {"rat_nitroglycerin"};
		callbackSuccess = QFUNC(treatmentAdvanced_medication);
		sounds[] = {};
	};
	class Atropine: Carbonate {
		displayName = CSTRING(Take_Atropine);
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Atropine);
		treatmentTime = QGVAR(treatmentTime_Atropine);
		items[] = {"rat_atropine"};
		callbackSuccess = QFUNC(treatmentAdvanced_Atropine);
		sounds[] = {};
	};
	class Ketamine: Carbonate {
		displayName = CSTRING(Take_Ketamine);
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Ketamine);
		treatmentTime = QGVAR(treatmentTime_Ketamine);
		items[] = {"rat_ketamine"};
		callbackSuccess = QFUNC(treatmentAdvanced_Ketamine);
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
//		condition = QUOTE(!([_patient] call ace_common_fnc_isAwake) && GVAR(Reorientation_Enable));
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
		condition = QFUNC(removeIV);
		callbackSuccess = QFUNC(retrieveIV);
		sounds[] = {};
	};
	/*
	class EACA: Carbonate {
		displayName = CSTRING(Take_EACA);
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_EACA);
		treatmentTime = QGVAR(treatmentTime_EACA);
		items[] = {"rat_EACA"};
		condition = QUOTE(!(GVAR(MedicationsRequireInsIV)) || FUNC(removeIV));
		callbackSuccess = QFUNC(treatmentAdvanced_EACA);
		sounds[] = {};
	};
	*/
	/*
	class Inspect: Carbonate {
		displayName = CSTRING(Inspect_Catheter);
		category = "examine";
		allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 1;
		medicRequired = 1;
		treatmentTime = 2;
		items[] = {};
		condition = QFUNC(removeIV);
		callbackSuccess = QFUNC(inspectCatheter);
		animationMedic = "";
		animationMedicProne = "";
		sounds[] = {};
	};
	*/
	/*
	class BreathCheck: Carbonate {
		displayName = CSTRING(Check_Breath);
		category = "examine";
		allowedSelections[] = {"Head"};
		allowSelfTreatment = 1;
		medicRequired = 1;
		treatmentTime = 2;
		items[] = {};
		condition = "true";
		callbackSuccess = QFUNC(inspectBreath);
		animationMedic = "";
		animationMedicProne = "";
		sounds[] = {};
	};
	*/
	/*
	class Amiodarone: EACA {
		displayName = CSTRING(Take_Amiodarone);
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Amiodarone);
		treatmentTime = QGVAR(treatmentTime_Amiodarone);
		items[] = {"rat_amiodarone"};
		callbackSuccess = QFUNC(treatmentAdvanced_Amiodarone);
		sounds[] = {};
	};
	*/
	/*
	class Lidocaine: EACA {
		displayName = CSTRING(Take_Lidocaine);
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Lidocain);
		treatmentTime = QGVAR(treatmentTime_Lidocaine);
		items[] = {"rat_lidocaine"};
		callbackSuccess = QFUNC(treatmentAdvanced_medication);
		sounds[] = {};
	};
	*/
	/*
	class Fentanyl: EACA {
		displayName = CSTRING(Take_Fentanyl);
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Fentanyl);
		treatmentTime = QGVAR(treatmentTime_Fentanyl);
		items[] = {"rat_fentanyl"};
		callbackSuccess = QFUNC(treatmentAdvanced_Fentanyl);
		sounds[] = {};
	};
	*/
	/*
	class Nalbuphine: EACA {
		displayName = CSTRING(Take_Nalbuphine);
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 1;
		medicRequired = QGVAR(medLvl_Nalbuphine);
		treatmentTime = QGVAR(treatmentTime_Nalbuphine);
		items[] = {"rat_nalbuphine"};
		callbackSuccess = QFUNC(treatmentAdvanced_medication);
		sounds[] = {};
	};
	*/
	/*
	class ApplyIV: ApplyTourniquet {
		displayName = CSTRING(Apply_IV_16);
		displayNameProgress = CSTRING(Applying_IV);
		medicRequired = QGVAR(medLvl_ApplyIV);
		category = "advanced";
		allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		items[] = {"rat_IV_16"};
		condition = QUOTE(!([ARR_3(_player, _patient, _bodyPart)] call FUNC(removeIV)));
		treatmentTime = QGVAR(treatmentTime_ApplyIV);
		callbackSuccess = QUOTE([ARR_4(_player, _patient, _bodyPart, 'rat_IV_16')] call FUNC(applyIV));
		litter[] = {};
		sounds[] = {};
	};
	*/
	/*
	class ApplyIO: ApplyIV {
		displayName = CSTRING(Apply_IO_45);
		displayNameProgress = CSTRING(Applying_IV);
		medicRequired = QGVAR(medLvl_ApplyIO);
		category = "advanced";
		allowedSelections[] = {"Body"};
		items[] = {"rat_IO_FAST"};
		condition = QUOTE(!([ARR_3(_player, _patient, _bodyPart)] call FUNC(removeIV)) && !(_patient getVariable [ARR_2(QQEGVAR(airway,recovery),false)]));
		treatmentTime = QGVAR(treatmentTime_ApplyIO);
		callbackSuccess = QUOTE([ARR_4(_player, _patient, _bodyPart, 'rat_IO_FAST')] call FUNC(applyIV));
		litter[] = {};
		sounds[] = {};
	};
	*/
	/*
	class Etomidate: EACA {
		displayName = CSTRING(Etomidate_Use);
		category = "surgery";
		treatmentLocations = 0;
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 0;
		medicRequired = QGVAR(medLvl_Etomidate);
		treatmentTime = QGVAR(treatmentTime_Etomidate);
		items[] = {"rat_etomidate"};
		callbackSuccess = QFUNC(treatmentAdvanced_medication);
		sounds[] = {};
	};
	*/
	/*
	class Lorazepam: EACA {
		displayName = CSTRING(Lorazepam_Use);
		category = "surgery";
		treatmentLocations = 0;
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 0;
		medicRequired = QGVAR(medLvl_Lorazepam);
		treatmentTime = QGVAR(treatmentTime_Lorazepam);
		items[] = {"rat_lorazepam"};
		callbackSuccess = QFUNC(treatmentAdvanced_Lorazepam);
		sounds[] = {};
	};
	*/
	/*
	class Flumazenil: EACA {
		displayName = CSTRING(Flumazenil_Use);
		category = "surgery";
		treatmentLocations = 0;
		allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		allowSelfTreatment = 0;
		medicRequired = QGVAR(medLvl_Flumezenil);
		treatmentTime = QGVAR(treatmentTime_Flumazenil);
		items[] = {"rat_flumazenil"};
		callbackSuccess = QFUNC(treatmentAdvanced_Flumazenil);
		sounds[] = {};
	};
	*/
	/*
	class Dialysis: BasicBandage {
		displayName = CSTRING(Dialysis_DisplayName);
		displayNameProgress = CSTRING(Dialysis_DisplayNameProgress);
		icon = QPATHTOF(ui\X_Series-Device_W.paa);
		category = "surgery";
		consumeItem = 0;
		items[] = {};
		medicRequired = 1;
		condition = QFUNC(vehicleCheckDialysis);
		treatmentTime = 15;
		callbackProgress = "";
		callbackStart = "";
		callbackFailure = "";
		callbackSuccess = QUOTE([ARR_2(_medic, _patient)] call FUNC(treatmentAdvanced_Dialysis));
		litter[] = {};
	};
	*/
};
