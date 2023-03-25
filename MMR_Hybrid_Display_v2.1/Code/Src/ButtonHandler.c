// START
#include "ButtonHandler.h"
#include "Data/Dataset.h"
// END

void buttonsActionHandler(Dataset* dataset, uint16_t GPIO_Pin) {

	if (GPIO_Pin == BTN_SCREEN_Pin) {
		changeScreenButton(dataset);
	} else if(GPIO_Pin == BTN_CLEAR_Pin) {
		clearButton(dataset);
	}
}

void changeScreenButton(Dataset* dataset) {
	// Not change screen during presentation
	if (dataset->screen.introductionPresentationFlag == 0) {
		incrementCurrentScreen(&(dataset->screen));
	}
}

void clearButton(Dataset* dataset) {
	// Clear all Notifications and/or Alarms
	if (dataset->screen.alarmFlag == 1) {
		dataset->screen.alarmFlag = 0;
	}
	if (dataset->screen.notificationFlag == 1) {
		dataset->screen.notificationFlag = 0;
	}
}
