// START
#include "TimersList.h"
#include "SimulationMode.h"
#include "Data/Dataset.h"
#include "Data/DataScreen.h"
#include "Data/DataNotification.h"
#include "SDcardHandler.h"
// END

void startSimulationMode(Dataset* dataset, DataScreen* dataScreen, TimersList* timers) {

	char fileName[] = SIMULATION_MODE_FILE_NAME;
	int res = 0;

	if ((dataset->screen.simulationFlag == 1 && dataset->screen.isSimulationModeEnabled == 1) ||
		(dataset->screen.simulationFlag == 1 && dataset->screen.isSimulationModeEnabled == 0)) {
		return;
	}
	if((res = initializeSDCard(fileName)) == 0) {
	//if((res = example()) >= 0) {	// DEBUG
		dataset->screen.isSimulationModeEnabled = 1;
		inizializeDataset(dataset);
		setMessageTypeDataNotification(&(dataset->messageErrors.driverMessage), 0);
		setMessageLengthDataNotification(&(dataset->messageErrors.driverMessage), 24);
		setMessageDataNotification(&(dataset->messageErrors.driverMessage), "Message\nSimulator\nStart!", 24, 0, 23);
		checkForNotificationActivated(dataset, timers);
	} else {
		char message[DATA_NOTIFICATION_LENGHT] = {0};
		sprintf(message, "Message\nSimulator\nError: %d", res);
		uint8_t messageLenght = strlen(message);
		setMessageTypeDataNotification(&(dataset->messageErrors.driverMessage), 0);
		setMessageLengthDataNotification(&(dataset->messageErrors.driverMessage), 24);
		setMessageDataNotification(&(dataset->messageErrors.driverMessage), message, messageLenght, 0, messageLenght - 1);
		checkForNotificationActivated(dataset, timers);
	}
}

void stopSimulationMode(Dataset* dataset, TimersList* timers, int error) {
	if(dataset->screen.simulationFlag == 1 && dataset->screen.isSimulationModeEnabled == 0) {
		dataset->screen.simulationFlag = 0;
		dataset->screen.isSimulationModeEnabled = 1;
		char message[DATA_NOTIFICATION_LENGHT] = {0};
		if(error == 0) {	// Error Handler
			sprintf(message, "Message\nSimulator\nEnd!");
		} else {
			sprintf(message, "Message\nSimulator\nError: %d", error);
		}
		uint8_t messageLenght = strlen(message);
		setMessageTypeDataNotification(&(dataset->messageErrors.driverMessage), 0);
		setMessageLengthDataNotification(&(dataset->messageErrors.driverMessage), 24);
		setMessageDataNotification(&(dataset->messageErrors.driverMessage), message, messageLenght, 0, messageLenght - 1);
		checkForNotificationActivated(dataset, timers);
		inizializeDataset(dataset);
	}
}


