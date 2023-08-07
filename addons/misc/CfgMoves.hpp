class CfgMovesBasic {
    class ManActions {
        rat_stretcher = "kat_stretcher";
    };
};

class CfgMovesMaleSdr: CfgMovesBasic {
    class States {
        class Crew;
        class rat_stretcher: crew {
            file = "a3\anims_f\data\anim\sdr\inj\ainjppnemstpsnonwnondnon.rtm";
            interpolateTo[] = {"Unconscious", 0.02};
            leftHandIKCurve[] = {};
            rightHandIKCurve[] = {};
        };
    };
};
