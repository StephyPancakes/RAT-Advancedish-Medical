class CfgMovesBasic {
	class Default;
};

class CfgMovesMaleSdr: CfgMovesBasic {
	class States {
		//class AinvPknlMstpSnonWnonDr_medic0;
		class rat_CPR: Default {
			file = "a3\anims_f\data\anim\sdr\inj\healing\ainvpknlmstpsnonwnondr_medic0.rtm";
			speed = 0.11;
			looped = 1;
			disableWeapons = 1;
			disableWeaponsLong = 1;
			showWeaponAim = 0;
			canPullTrigger = 0;
			duty = 0.2;
			limitGunMovement = 0;
			aiming = "empty";
			aimingBody = "empty";
			ConnectFrom[] = {
				"rat_CPR", 
				0.1
			};
			//ConnectAs = "";
			ConnectTo[] = {
				"rat_CPR", 
				0.1
			};
			forceAim = 1;
			//InterpolateFrom[] = {};
			//InterpolateWith[] = {};
			InterpolateTo[]=
			{
				"rat_CPR", 
				0.1,
				"AinvPknlMstpSnonWnonDnon_medic",
				0.1,
				"AinvPknlMstpSnonWnonDr_medic0S",
				0.1,
				"Unconscious",
				0.02,
				"AinvPknlMstpSnonWnonDnon_medicEnd",
				0.2
			};
		};
	};
};