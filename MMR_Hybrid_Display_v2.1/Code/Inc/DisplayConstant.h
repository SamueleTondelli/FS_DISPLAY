#ifndef DISPLAYCONSTANT_H
#define DISPLAYCONSTANT_H

// DISPLAY CONSTANTS

	// SCREEN NAMES
#define HOME 0
#define DRAG 1
#define DRAG_2 2

	// ALARMS CONSTANTS
#define ALARM_NOT_INTERRUPTABLE_TIME	4000 //ms
#define ALARM_BONUS_TIME				3000 //ms
#define ALARM_AUTOMATIC_TIMEOUT_TIME				60000 //ms

	// ALARMS
#define POIL_ALARM 				"OIL\nPRESSURE\nLOW"
#define POIL_ALARM_LENGTH 		16
#define TOIL_ALARM 				"OIL\nTEMPERATURE\nHIGH"
#define TOIL_ALARM_LENGTH 		20
#define TWATER_ALARM 			"WATER\nTEMPERATURE\nHIGH"
#define TWATER_ALARM_LENGTH 	22
#define SOC_ALARM 				"SOC\nLOW"
#define SOC_ALARM_LENGTH 		7
#define TBATTERY_ALARM			"TEMPERATURE\nBATTERY\nHIGH"
#define TBATTERY_ALARM_LENGTH	24
	// SCREEN CONSTANTS
#define START_SCREEN 2
#define SCREEN_NUMBERS 6
#define EMPTY_VALUE -1
#define FADE_MAX 255
#define FADE_MIN 127
#define SCREEN_DISABLED 255
#define ALARM_OFF 0
#define ALARM_ON 1
#define DISPLAY_FPS 30
#define PRESENTATION_DURATION 5
	//RPM
#define MAX_RPM 11000
#define RPM_LIMIT 11000	
#define LOW_RANGE_RPM_MIN 0
#define LOW_RANGE_RPM_MAX 4000
#define MEDIUM_RANGE_RPM_MIN 4001
#define MEDIUM_RANGE_RPM_MAX 8000
#define HIGH_RANGE_RPM_MIN 8001
#define HIGH_RANGE_RPM_MAX 15000
#define RPM_CIRCLE 6000
#define BOX_RPM_WIDTH 336
#define BXRPM_MAX_WIDTH 470
	// Poil
#define LOW_POIL_MIN 0
#define LOW_POIL_MAX 1
#define MEDIUM_POIL_MIN 1.1f
#define MEDIUM_POIL_MAX 10.9f
#define HIGH_POIL_MIN 11
#define HIGH_POIL_MAX 1000
	// Toil
#define LOW_TOIL_MIN 0
#define LOW_TOIL_MAX 70
#define LOW_TOIL_WARNING_START 50
#define LOW_TOIL_WARNING_END 70
#define MEDIUM_TOIL_MIN 71
#define MEDIUM_TOIL_MAX 129.9f
#define HIGH_TOIL_WARNING_START 130
#define HIGH_TOIL_WARNING_END 140
#define HIGH_TOIL_MIN 130
#define HIGH_TOIL_MAX 200
	// TwaterC
#define LOW_TWATERC_MIN 0
#define LOW_TWATERC_MAX 70
#define LOW_TWATERC_WARNING_START 70
#define LOW_TWATERC_WARNING_END 60
#define MEDIUM_TWATERC_MIN 70.1f
#define MEDIUM_TWATERC_MAX 97.9f
#define HIGH_TWATERC_WARNING_START 98
#define HIGH_TWATERC_WARNING_END 100
#define HIGH_TWATERC_MIN 98
#define HIGH_TWATERC_MAX 200
	// SOC
#define LOW_SOC_MIN 0
#define LOW_SOC_MAX 30
#define MEDIUM_SOC_MIN 31
#define MEDIUM_SOC_MAX 70
#define HIGH_SOC_MIN 71
#define HIGH_SOC_MAX 100
#define BXSOC_Y_POSITION_MAX 4
#define BXSOC_Y_POSITION_MIN 186
	// TbatHV
#define LOW_TBATHV_MIN 0
#define LOW_TBATHV_MAX 20
#define MEDIUM_TBATHV_MIN 20.1f
#define MEDIUM_TBATHV_MAX 54.9f
#define HIGH_TBATHV_WARNING_START 54
#define HIGH_TBATHV_WARNING_END 56
#define HIGH_TBATHV_MIN 55
#define HIGH_TBATHV_MAX 200
	// TwaterE
#define LOW_TWATERE_MIN 0
#define LOW_TWATERE_MAX 20
#define MEDIUM_TWATERE_MIN 20.1f
#define MEDIUM_TWATERE_MAX 44.9f
#define HIGH_TWATERE_WARNING_START 45
#define HIGH_TWATERE_WARNING_END 50
#define HIGH_TWATERE_MIN 45
#define HIGH_TWATERE_MAX 200
	// VbatHV
#define LOW_VBATHV_MIN 0
#define LOW_VBATHV_MAX 86
#define MEDIUM_VBATHV_MIN 86.1f
#define MEDIUM_VBATHV_MAX 100
#define HIGH_VBATHV_MIN 100.1f
#define HIGH_VBATHV_MAX 300
	// VbatLV
#define LOW_VBATLV_MIN 0
#define LOW_VBATLV_MAX 9.5f
#define MEDIUM_VBATLV_MIN 9.6f
#define MEDIUM_VBATLV_MAX 14.9f
#define HIGH_VBATLV_MIN 15.1f
#define HIGH_VBATLV_MAX 100

#endif /* DISPLAYCONSTANT_H */
