// START
#include "Data/DataScreen.h"
#include "DisplayConstant.h"
// END

void initializeDataScreen(DataScreen *dataScreen) {
	dataScreen->screen = START_SCREEN;

	dataScreen->positionScreenList = 0;

	initializeDataStatus(&(dataScreen->displayMode));	// WARNING Questi DEF devono avere la stesso indice del valore della MACRO definita nel header file
	dataScreen->displayMode.statusDef[DATA_SCREEN_DISPLAY_MODE_NORMAL] 			= "Normal";
	dataScreen->displayMode.statusDef[DATA_SCREEN_DISPLAY_MODE_RACE] 			= "Race";
	dataScreen->displayMode.statusDef[DATA_SCREEN_DISPLAY_MODE_SIMULATION]		= "Simulation";
	dataScreen->displayMode.statusDef[DATA_SCREEN_DISPLAY_MODE_PRESENTATION]	= "Presentation";
	dataScreen->displayMode.statusDefLength = 4;

	/* ATTENZIONE!
	 * Per disabilitare lo schermo in quella posizione basta inserire la macro SCREEN_DISABLED al posto
	 * dello schermo da togliere. Il modo in cui gli schermi sono presentati sono dall'inizio dell'array
	 * alla fine. Quindi il primo Screen sara alla posizione [0] e così via...
	 */
	dataScreen->screenList[0] = 2; //START_SCREEN
	dataScreen->screenList[1] = 3;
	dataScreen->screenList[2] = 5; 
	dataScreen->screenList[3] = 4; 
	dataScreen->screenList[4] = 6;
	dataScreen->screenList[5] = 1;

	dataScreen->fps = 0;

	// Flag for phase Display Introduction Presentation
	dataScreen->introductionPresentationFlag = 1;			//presentationFlag
	// Counter of frame displayed in Initial phase Display Introduction Presentation (when turn ON)
	dataScreen->counterFrameIntroductionPresentation = 0;	//counterFramePresentation
	// Flag for Update Display Screen
	dataScreen->updateFlag = 0;								// updateFlag
	// Flag for Screen Name Message Enable
	dataScreen->screenNameFlag = 0;							// screenNameFlag
	// Flag for Animation (for blinking box, value changed each 1s)
	dataScreen->blinkFlag = 0;								// animationFlag
	// Counter of frames displayed
	dataScreen->frameCounter = 0;							// frameCounter
	// Flag for Alarm Status running
	dataScreen->alarmFlag = 0;								// alarmFlag		
	// Enable/Disable Alarm Flag (Used for manual disabling Alarm Status display)
	dataScreen->isAlarmFlagEnabled = 1;
	// Flag for display Notification running
	dataScreen->notificationFlag = 0;
	// Enable/Disable Notification Flag (Used to manual display Notification management)
	dataScreen->isNotificationFlagEnabled = 1;
	// Flag for Simulation Mode Running
	dataScreen->simulationFlag = 0;							// isSimulationModeRunning
	// Enable/Disable manually Simulation Mode
	dataScreen->isSimulationModeEnabled = 1;				// isSimulationModeEnabled
	// Enable/Disable Read Datas from file
	dataScreen->simulationReadFlag = 0;
	// Flag for Presentation Mode Running
	dataScreen->presentationFlag = 0;
	// Enable/Disable Presentation Mode
	dataScreen->isPresentationModeEnabled = 1;

	dataScreen->invalidateCurrentAlarmFlag = 0;
}

uint8_t getCurrentScreen(DataScreen *dataScreen) {
	return dataScreen->screen;
}

void incrementCurrentScreen(DataScreen *dataScreen) {
	uint8_t valueNextScreenList = 0;
	uint8_t flag = 0;
	uint8_t positionNextScreenList = dataScreen->positionScreenList + 1;
	do {
		if (positionNextScreenList >= SCREEN_NUMBERS) {
			positionNextScreenList = 0;
			flag = SCREEN_DISABLED;
		} else {
			valueNextScreenList = dataScreen->screenList[positionNextScreenList];
			if (valueNextScreenList == SCREEN_DISABLED) {
				positionNextScreenList++;
				flag = SCREEN_DISABLED;
			} else {
				dataScreen->positionScreenList = positionNextScreenList;
				dataScreen->screen = valueNextScreenList;

				return;
			}
		}
	} while (flag == SCREEN_DISABLED);
}

uint8_t getFpsScreen(DataScreen *dataScreen) {
	return (dataScreen->fps);
}

void setFpsScreen(DataScreen *dataScreen, uint8_t newFps) {
	dataScreen->fps = newFps;
}

void setFpsScreenFromStruct(DataScreen* dataScreen) {
	dataScreen->fps = dataScreen->frameCounter;
}

void cleanFpsCounter(DataScreen* dataScreen) {
	dataScreen->frameCounter = 0;
}

void changeBlinkFlag(DataScreen* dataScreen) {
	dataScreen->blinkFlag = !dataScreen->blinkFlag;
}

void changeDisplayMode(DataScreen* dataScreen, uint8_t newDisplayMode) {
	uint8_t currentDisplayMode = getDataStatus(&(dataScreen->displayMode));

	if (currentDisplayMode == newDisplayMode)
		return;

	/* TODO Implementare funzione che gestise il check della modalità e lo switch di modalità
	 * -> (Per Simulation Mode quando funziona fatfs il controllo verrà fatto nel Task che si occuperà di
	 * 		tutte le operazioni di questa modalità)
	 * -> (Per tutte le altre modalità fare controllo di questi flag nel Model)
	 */

	/*
	 * dataScreen->displayMode.statusDef[0] = "Normal";
	 * dataScreen->displayMode.statusDef[1] = "Race";
	 * dataScreen->displayMode.statusDef[2] = "Simulation";
	 * dataScreen->displayMode.statusDef[3] = "Presentation";
	 */

	switch (newDisplayMode) {
		case(DATA_SCREEN_DISPLAY_MODE_NORMAL):
			// Display Mode "Normal"
			setDataStatus(&(dataScreen->displayMode), newDisplayMode);
			dataScreen->isAlarmFlagEnabled			= 1;	// Enable all Alarm to FrontEnd
			dataScreen->isSimulationModeEnabled		= 0;
			dataScreen->isPresentationModeEnabled	= 0;
			dataScreen->isNotificationFlagEnabled	= 1;
			break;
		case(DATA_SCREEN_DISPLAY_MODE_RACE):
			// Display Mode "Race" (No Alarms)
			setDataStatus(&(dataScreen->displayMode), newDisplayMode);
			dataScreen->isAlarmFlagEnabled			= 0;	// Disable all Alarm to FrontEnd
			dataScreen->isSimulationModeEnabled		= 0;
			dataScreen->isPresentationModeEnabled	= 0;
			dataScreen->isNotificationFlagEnabled	= 1;
			break;
		case(DATA_SCREEN_DISPLAY_MODE_SIMULATION):
			// Display Mode "Simulation"
			setDataStatus(&(dataScreen->displayMode), newDisplayMode);
			dataScreen->isAlarmFlagEnabled			= 1;
			dataScreen->isSimulationModeEnabled		= 1;	// Enable Simulation Mode
			dataScreen->isPresentationModeEnabled	= 0;
			dataScreen->isNotificationFlagEnabled	= 1;
			break;
		case(DATA_SCREEN_DISPLAY_MODE_PRESENTATION):
			// Display Mode "Presentation"
			setDataStatus(&(dataScreen->displayMode), newDisplayMode);
			dataScreen->isAlarmFlagEnabled			= 0;
			dataScreen->isSimulationModeEnabled		= 0;
			dataScreen->isPresentationModeEnabled	= 1;	// Enable Presentation Mode
			dataScreen->isNotificationFlagEnabled	= 0;
		default:
			return;
	}
}

uint8_t isDisplayModeNormal(DataScreen* dataScreen) {
	uint8_t currentMode = getDataStatus(&(dataScreen->displayMode));
	if(currentMode == DATA_SCREEN_DISPLAY_MODE_NORMAL) {
		return 1;
	} else {
		return 0;
	}
}

uint8_t isDiplayModeRace(DataScreen* dataScreen) {
	uint8_t currentMode = getDataStatus(&(dataScreen->displayMode));
	if(currentMode == DATA_SCREEN_DISPLAY_MODE_RACE) {
		return 1;
	} else {
		return 0;
	}
}

uint8_t isDisplayModeSimulation(DataScreen* dataScreen) {
	uint8_t currentMode = getDataStatus(&(dataScreen->displayMode));
	if(currentMode == DATA_SCREEN_DISPLAY_MODE_SIMULATION) {
		return 1;
	} else {
		return 0;
	}
}

uint8_t isDisplayModePresentation(DataScreen* dataScreen) {
	uint8_t currentMode = getDataStatus(&(dataScreen->displayMode));
	if(currentMode == DATA_SCREEN_DISPLAY_MODE_SIMULATION) {
		return 1;
	} else {
		return 0;
	}
}
