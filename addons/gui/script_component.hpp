#define COMPONENT gui
#define COMPONENT_BEAUTIFIED RAT GUI
#include "\x\rat\addons\main\script_mod.hpp"

// #define DEBUG_MODE_FULL
// #define DISABLE_COMPILE_CACHE
// #define ENABLE_PERFORMANCE_COUNTERS

#ifdef DEBUG_ENABLED_GUI
    #define DEBUG_MODE_FULL
#endif

#ifdef DEBUG_SETTINGS_GUI
    #define DEBUG_SETTINGS DEBUG_SETTINGS_GUI
#endif

#include "\z\ace\addons\medical_engine\script_macros_medical.hpp"
#include "\x\rat\addons\main\script_macros.hpp"

#include "\a3\ui_f\hpp\defineResincl.inc"
#include "\a3\ui_f\hpp\defineDIKCodes.inc"
#include "\a3\ui_f\hpp\defineCommonGrids.inc"
#include "\a3\ui_f\hpp\defineCommonColors.inc"

#define POS_X(N) ((N) * GUI_GRID_W + GUI_GRID_CENTER_X)
#define POS_Y(N) ((N) * GUI_GRID_H + GUI_GRID_CENTER_Y)
#define POS_W(N) ((N) * GUI_GRID_W)
#define POS_H(N) ((N) * GUI_GRID_H)

#define PATIENT_INFO_IGUI_BASE_X (safeZoneX + POS_W(2))
#define PATIENT_INFO_IGUI_BASE_Y (safeZoneY + POS_H(1))
#define PATIENT_INFO_IGUI_X (profilenamespace getVariable ['TRIPLES(IGUI,GVAR(patientInfo),X)', 0])
#define PATIENT_INFO_IGUI_Y (profilenamespace getVariable ['TRIPLES(IGUI,GVAR(patientInfo),Y)', 0])
#define PATIENT_INFO_IGUI_OFFSET_X (PATIENT_INFO_IGUI_X - PATIENT_INFO_IGUI_BASE_X)
#define PATIENT_INFO_IGUI_OFFSET_Y (PATIENT_INFO_IGUI_Y - PATIENT_INFO_IGUI_BASE_Y)

#define MED_LOG_VARNAME(type) (format ["ace_medical_log_%1", type])

#define IDD_MEDICAL_MENU 38580

#define IDC_TITLE 1200
#define IDC_NAME 1210
#define IDC_TRIAGE 1300
#define IDC_EXAMINE 1310
#define IDC_BANDAGE 1320
#define IDC_MEDICATION 1330
#define IDC_AIRWAY 1340
#define IDC_ADVANCED 1350
#define IDC_DRAG 1360
#define IDC_TOGGLE 1370
#define IDC_SURGERY 1385
#define IDC_TRIAGE_DIVIDER 1380
#define IDC_TOGGLE_DIVIDER 1390

#define IDC_TRIAGE_CARD 1400
#define IDC_INJURIES 1410
#define IDC_ACTIVITY 1420
#define IDC_QUICKVIEW 1430
						
#define IDC_ACTION_BUTTON_GROUP 1599

#define IDC_BODY_GROUP      6000
#define IDC_BODY_HEAD       6005
#define IDC_BODY_TORSO      6010
#define IDC_BODY_ARMLEFT    6015
#define IDC_BODY_ARMRIGHT   6020
#define IDC_BODY_LEGLEFT    6025
#define IDC_BODY_LEGRIGHT   6030
#define IDC_BODY_ARMLEFT_T  6035
#define IDC_BODY_ARMRIGHT_T 6040
#define IDC_BODY_LEGLEFT_T  6045
#define IDC_BODY_LEGRIGHT_T 6050
#define IDC_BODY_ARMLEFT_B  6055
#define IDC_BODY_ARMRIGHT_B 6060
#define IDC_BODY_LEGLEFT_B  6065
#define IDC_BODY_LEGRIGHT_B 6070
#define IDC_BODY_GROUP_S    6075
#define IDC_BODY_HEAD_S     6080
#define IDC_BODY_TORSO_S    6085
#define IDC_BODY_ARMLEFT_S  6090
#define IDC_BODY_ARMRIGHT_S 6095
#define IDC_BODY_LEGLEFT_S  6100
#define IDC_BODY_LEGRIGHT_S 6105

#define IDC_SIDE_LABEL_RIGHT 7001
#define IDC_SIDE_LABEL_LEFT 7002

#define IDC_TRIAGE_STATUS 7000
#define IDC_TRIAGE_SELECT 7100


#define IDC_BODY_TORSO_I             70100

#define IDC_BODY_HEAD_GUEDELTUBE     70110
#define IDC_BODY_HEAD_KINGLT         70111

#define IDC_BODY_TORSO_AED_PADS      70120
#define IDC_BODY_TORSO_CHESTSEAL     70121
#define IDC_BODY_TORSO_PNEUMOTHORAX  70122
#define IDC_BODY_TORSO_IO            70123

#define IDC_BODY_RIGHTARM_AED_VITALS 70130
#define IDC_BODY_LEFTARM_AED_VITALS  70131
#define IDC_BODY_RIGHTARM_PULSEOX    70132
#define IDC_BODY_LEFTARM_PULSEOX     70133
#define IDC_BODY_RIGHTARM_IV         70134
#define IDC_BODY_LEFTARM_IV          70135

#define IDC_BODY_RIGHTLEG_IV         70141
#define IDC_BODY_LEFTLEG_IV          70142