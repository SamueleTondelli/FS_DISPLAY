// START
#include "Data/Dataset.h"
#include "TimerHandler.h"
#include "SimulationMode.h"
#include "SDcardHandler.h"
// END

#define DEBUG_DATASET 1

extern TIM_HandleTypeDef htim5;

#ifdef DEBUG_DATASET
//DEBUG
extern CAN_HandleTypeDef hcan1;
extern CAN_TxHeaderTypeDef ptxHeader;
extern uint32_t txMailbox;
#endif

void initializeDataset(Dataset *dataset) {
	initializeDataPowerUnit(&(dataset->powerUnit));
	initializeDataHVElectronicsBMS(&(dataset->hvElectronicsBMS));
	initializeDataHVElectronicsInverter(&(dataset->hvElectronicsInverter));
	initializeDataLVElectronics(&(dataset->lvElectronics));
	initializeDataThermalAerodynamics(&(dataset->thermalAerodynamics));
	initializeDataDynamics(&(dataset->dynamics));
	initializeDataMessagesErrors(&(dataset->messageErrors));
	initializeDataScreen(&(dataset->screen));
}

void setFlagNotUpdatedDataset(Dataset* dataset) {
	setFlagNotUpdatedDataPowerUnit(&(dataset->powerUnit));
	setFlagNotUpdatedDataHVElectronicsBMS(&(dataset->hvElectronicsBMS));
	setFlagNotUpdatedDataHVElectronicsInverter(&(dataset->hvElectronicsInverter));
	setFlagNotUpdatedDataLVElectronics(&(dataset->lvElectronics));
	setFlagNotUpdatedDataThermalAerodynamics(&(dataset->thermalAerodynamics));
	setFlagNotUpdatedDataDynamics(&(dataset->dynamics));
}

uint8_t isPressureOilAlarmOn(Dataset* dataset) {
	if(getDataStatus(&(dataset->screen.displayMode)) != DATA_SCREEN_DISPLAY_MODE_RACE)
		return getDataStatus(&(dataset->messageErrors.pressureOilAlarm));
	else
		return 0;
}

uint8_t isOilTemperatureAlarmOn(Dataset* dataset) {
	if(getDataStatus(&(dataset->screen.displayMode)) != DATA_SCREEN_DISPLAY_MODE_RACE)
		return getDataStatus(&(dataset->messageErrors.oilTemperatureAlarm));
	else
		return 0;
}

uint8_t isWaterTemperatureAlarmOn(Dataset* dataset) {
	if(getDataStatus(&(dataset->screen.displayMode)) != DATA_SCREEN_DISPLAY_MODE_RACE)
		return getDataStatus(&(dataset->messageErrors.waterTemperatureAlarm));
	else
		return 0;
}

uint8_t isSOCAlarmOn(Dataset* dataset) {
	if (getDataStatus(&(dataset->screen.displayMode)) != DATA_SCREEN_DISPLAY_MODE_RACE)
		return getDataStatus(&(dataset->messageErrors.socAlarm));
	else
		return 0;
}

uint8_t isTemperatureBatteryAlarmOn(Dataset* dataset) {
	if (getDataStatus(&(dataset->screen.displayMode)) != DATA_SCREEN_DISPLAY_MODE_RACE)
		return getDataStatus(&(dataset->messageErrors.tempBatteryAlarm));
	else
		return 0;
}

void checkForAlarmActivated(Dataset* dataset, TimersList* timers) {
	uint8_t activate = 0;

	// Sanity Check for Display Mode
	if (dataset->screen.isAlarmFlagEnabled == 0)
		return;

	uint8_t isPoilPressureAlarmOn = getDataStatus(&(dataset->messageErrors.pressureOilAlarm));
	uint8_t isOilTemperatureAlarmOn = getDataStatus(&(dataset->messageErrors.oilTemperatureAlarm));
	uint8_t isWaterTemperatureAlarmOn = getDataStatus(&(dataset->messageErrors.waterTemperatureAlarm));
	uint8_t isSocAlarmOn = getDataStatus(&(dataset->messageErrors.socAlarm));
	uint8_t isTempBatteryAlarmOn = getDataStatus(&(dataset->messageErrors.tempBatteryAlarm));

	if(isPoilPressureAlarmOn == 1 || isOilTemperatureAlarmOn == 1 || isWaterTemperatureAlarmOn == 1 ||
			isSocAlarmOn == 1 || isTempBatteryAlarmOn == 1) {
		activate = 1;
	}

	// Activate Alarm Flag to Display the Alarm and start Alarm timer
	if (activate && dataset->screen.alarmFlag != 1) {
		dataset->screen.alarmFlag = 1;
	}
}

void checkForAlarmActivated2(Dataset* dataset) {
	uint8_t activate = 0;

	// Sanity Check for Display Mode
	if (dataset->screen.isAlarmFlagEnabled == 0) {
		return;
	}

	uint8_t isPoilPressureAlarmOn = getDataStatus(&(dataset->messageErrors.pressureOilAlarm));
	uint8_t isOilTemperatureAlarmOn = getDataStatus(&(dataset->messageErrors.oilTemperatureAlarm));
	uint8_t isWaterTemperatureAlarmOn = getDataStatus(&(dataset->messageErrors.waterTemperatureAlarm));
	uint8_t isSocAlarmOn = getDataStatus(&(dataset->messageErrors.socAlarm));
	uint8_t isTempBatteryAlarmOn = getDataStatus(&(dataset->messageErrors.tempBatteryAlarm));

	if(isPoilPressureAlarmOn == 1 || isOilTemperatureAlarmOn == 1 || isWaterTemperatureAlarmOn == 1 ||
			isSocAlarmOn == 1 || isTempBatteryAlarmOn == 1) {
		activate = 1;
	}

	// Activate Alarm Flag to Display and start Alarm timer
	if (activate && dataset->screen.alarmFlag != 1) {
		dataset->screen.alarmFlag = 1;
	}
}

void checkForAlarmDeActivated(Dataset* dataset, TimersList* timers) {
	/*
	// Sanity check for Display Mode
	if (dataset->screen.isAlarmFlagEnabled == 0) {
		dataset->screen.alarmFlag = 0;
		return;
	}
	*/
	dataset->screen.alarmFlag = 0;
}

void checkForAlarmDeActivated2(Dataset* dataset) {
	/*
	// Sanity check for Display Mode
	if (dataset->screen.isAlarmFlagEnabled == 0) {
		dataset->screen.alarmFlag = 0;
		return;
	}
	*/
	dataset->screen.alarmFlag = 0;
}

void checkForNotificationActivated(Dataset* dataset, TimersList* timers) {
	if(dataset->screen.alarmFlag == 1 ||
			dataset->screen.notificationFlag == 1 ||
			dataset->screen.isNotificationFlagEnabled == 0) {
		return;
	}
	if(isDataNotificationReady(&(dataset->messageErrors.driverMessage))) {
		// Activate Notification Flag to Display the Notification and start Notification timer
		dataset->screen.notificationFlag = 1;
		startTimer(timers->tim5sec);
		//startTimer(timers->tim2sec);
	}
}

void checkForNotificationActivated2(Dataset* dataset) {
	if(dataset->screen.alarmFlag == 1 ||
			dataset->screen.notificationFlag != 1 ||
			dataset->screen.isNotificationFlagEnabled == 0) {
		return;
	}
	if(isDataNotificationReady(&(dataset->messageErrors.driverMessage))) {
		// Activate Notification Flag to Display the Notification and start Notification timer
		dataset->screen.notificationFlag = 1;
		startTimer(&htim5);
	}
#ifdef DEBUG_DATASET
	//DEBUG
	uint8_t dummyData[8] = {0};
	dummyData[0] = dataset->screen.screenNameFlag;
	dummyData[1] = dataset->screen.notificationFlag;
	dummyData[2] = dataset->screen.alarmFlag;
	dummyData[3] = dataset->messageErrors.driverMessage.notificationType.status;
	dummyData[4] = dataset->messageErrors.driverMessage.notificationLength;
	dummyData[5] = dataset->messageErrors.driverMessage.notificationCounter;
	ptxHeader.StdId = 0x200;
	ptxHeader.DLC = 8;
	HAL_CAN_AddTxMessage(&hcan1, &ptxHeader, dummyData, &txMailbox);
#endif
}

void checkForNotificationDeActivated(Dataset* dataset, TimersList* timers) {
	// Deactivate Notification Flag, clean Notification Struct and stop timer
	dataset->screen.notificationFlag = 0;
	cleanDataNotification(&(dataset->messageErrors.driverMessage));
}

void checkForNotificationDeActivated2(Dataset* dataset) {
	// Deactivate Notification Flag, clean Notification Struct and stop timer
	dataset->screen.notificationFlag = 0;
	cleanDataNotification(&(dataset->messageErrors.driverMessage));
}

