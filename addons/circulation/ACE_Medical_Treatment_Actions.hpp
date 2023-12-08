class ACE_Medical_Treatment_Actions {
	class FieldDressing;
	class Morphine;
	class CheckPulse;
	class CPR {
		displayNameProgress = "";
		treatmentTime = 0.01;
		callbackStart = "";
		callbackProgress = "";
		callbackFailure = "";
		callbackSuccess = QFUNC(cprStart);
		condition = QUOTE([ARR_2(_medic,_patient)] call ACEFUNC(medical_treatment,canCPR));
		animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
		animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon"};
	};
	class CheckDogtags: CheckPulse {
		displayName = CSTRING(DogTag);
		displayNameProgress = CSTRING(DogTag_Action);
		treatmentTime = 2;
		allowedSelections[] = {"Head"};
		allowSelfTreatment = 1;
		callbackSuccess = QACEFUNC(dogtags,checkDogtag);
		condition = "true";
		animationPatient = "";
		animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
		animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon","rat_recoveryposition"};
	};
	class CheckBloodPressure: CheckPulse {
		allowedSelections[] = {"LeftArm", "RightArm", "LeftLeg", "RightLeg"};
		animationPatient = "";
		animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
		animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon","rat_recoveryposition"};
	};
	class RAT_DrawBlood500: CheckPulse {
		displayName = CSTRING(DrawBlood500_Action_Use);
		displayNameProgress = CSTRING(DrawBlood_Action_Progress);
		treatmentTime = QGVAR(blood_drawTime_500ml);
		allowedSelections[] = {"LeftArm", "RightArm"};
		allowSelfTreatment = QGVAR(enable_selfBloodDraw);
		category = "advanced";
		medicRequired = 0;
		consumeItem = 0;
		callbackSuccess = QUOTE([ARR_3(_medic, _patient,500)] call FUNC(drawBlood));
		condition = QUOTE([ARR_3(_medic, _patient,500)] call FUNC(canDraw));
		items[] = {"RAT_Empty_bloodIV_500"};
		animationPatient = "";
		animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
		animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon","rat_recoveryposition"};
	};
	class RAT_DrawBlood250: CheckPulse {
		displayName = CSTRING(DrawBlood250_Action_Use);
		displayNameProgress = CSTRING(DrawBlood_Action_Progress);
		treatmentTime = QGVAR(blood_drawTime_250ml);
		allowedSelections[] = {"LeftArm", "RightArm"};
		allowSelfTreatment = QGVAR(enable_selfBloodDraw);
		category = "advanced";
		medicRequired = 0;
		consumeItem = 0;
		callbackSuccess = QUOTE([ARR_3(_medic, _patient,250)] call FUNC(drawBlood));
		condition = QUOTE([ARR_3(_medic, _patient,250)] call FUNC(canDraw));
		items[] = {"RAT_Empty_bloodIV_250"};
		animationPatient = "";
		animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
		animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon"};
	};
};