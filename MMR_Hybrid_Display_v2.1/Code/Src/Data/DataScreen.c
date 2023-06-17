// START
#include "Data/DataScreen.h"
#include "DisplayConstant.h"
// END

void initializeDataScreen(DataScreen *dataScreen) {
	dataScreen->screen = STARTING_SCREEN;

	dataScreen->fps = 0;

	dataScreen->updateFlag = 0;								// updateFlag
	// Flag for Screen Name Message Enable
	dataScreen->blinkFlag = 0;								// animationFlag
	// Counter of frames displayed
	dataScreen->frameCounter = 0;							// frameCounter


	dataScreen->invalidateCurrentAlarmFlag = 0;
}

uint8_t getCurrentScreen(DataScreen *dataScreen) {
	return dataScreen->screen;
}

void incrementCurrentScreen(DataScreen *dataScreen) {
	dataScreen->screen = (dataScreen->screen + 1) % NUMBER_OF_SCREENS;
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
