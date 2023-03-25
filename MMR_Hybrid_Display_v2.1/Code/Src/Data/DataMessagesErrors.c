// START
#include "Data/DataMessagesErrors.h"
// END

void initializeDataMessagesErrors(DataMessagesErrors* dataMessagesErrors) {
	initializeDataNotification(&(dataMessagesErrors->driverMessage));
	dataMessagesErrors->driverMessage.notificationType.statusDef[0] = "Driver";
	dataMessagesErrors->driverMessage.notificationType.statusDef[1] = "Warning";
	dataMessagesErrors->driverMessage.notificationType.statusDef[2] = "Alarm";
	dataMessagesErrors->driverMessage.notificationType.statusDefLength = 3;

	initializeDataLapTime(&(dataMessagesErrors->lapTime));
	initializeDataLapTime(&(dataMessagesErrors->bestLapTime));

	initializeDataStatus(&(dataMessagesErrors->pressureOilAlarm));
	dataMessagesErrors->pressureOilAlarm.statusDef[0] = "NotActive";
	dataMessagesErrors->pressureOilAlarm.statusDef[1] = "Active";
	dataMessagesErrors->pressureOilAlarm.statusDefLength = 2;

	initializeDataStatus(&(dataMessagesErrors->oilTemperatureAlarm));
	dataMessagesErrors->oilTemperatureAlarm.statusDef[0] = "NotActive";
	dataMessagesErrors->oilTemperatureAlarm.statusDef[1] = "Active";
	dataMessagesErrors->oilTemperatureAlarm.statusDefLength = 2;

	initializeDataStatus(&(dataMessagesErrors->waterTemperatureAlarm));
	dataMessagesErrors->waterTemperatureAlarm.statusDef[0] = "NotActive";
	dataMessagesErrors->waterTemperatureAlarm.statusDef[1] = "Active";
	dataMessagesErrors->waterTemperatureAlarm.statusDefLength = 2;

	initializeDataStatus(&(dataMessagesErrors->socAlarm));
	dataMessagesErrors->socAlarm.statusDef[0] = "NotActive";
	dataMessagesErrors->socAlarm.statusDef[1] = "Active";
	dataMessagesErrors->socAlarm.statusDefLength = 2;

	initializeDataStatus(&(dataMessagesErrors->tempBatteryAlarm));
	dataMessagesErrors->tempBatteryAlarm.statusDef[0] = "NotActive";
	dataMessagesErrors->tempBatteryAlarm.statusDef[1] = "Active";
	dataMessagesErrors->tempBatteryAlarm.statusDefLength = 2;

	initializeDataStatus(&(dataMessagesErrors->warningSource));		// TODO Aggiungere
	dataMessagesErrors->warningSource.statusDef[0] = "";
	dataMessagesErrors->warningSource.statusDefLength = 1;
}

uint8_t isDataNotificationDriverType(DataMessagesErrors* dataMessagesErrors) {
	int8_t typeValue = getDataStatus(&(dataMessagesErrors->driverMessage.notificationType));
	// Check if value is not in DEFAULT mode
	if(typeValue == DATA_NOTIFICATION_TYPE_DEFAULT) {
		return 0;
	}
	// Check the length of the current type between the Driver string length
	uint8_t typeLength = strlen(dataMessagesErrors->driverMessage.notificationType.statusDef[typeValue]);
	if(typeLength != DRIVER_MESSAGE_DRIVER_TYPE_LENGTH) {
		return 0;
	} else {
		/* Check if the current type is Driver type by checking the string
		 * (In case we have multiple type with the same length)
		 */
		/*
		if(strcmp(dataMessagesErrors->driverMessage.notificationType.statusDef[typeValue], "Driver") == 0) {
			return 1;
		} else {
			return 0;
		}
		*/
		return 1;
	}
}

uint8_t isDataNotificationWarningType(DataMessagesErrors* dataMessagesErrors) {
	int8_t typeValue = getDataStatus(&(dataMessagesErrors->driverMessage.notificationType));
	// Check if value is not in DEFAULT mode
	if(typeValue == DATA_NOTIFICATION_TYPE_DEFAULT) {
		return 0;
	}
	// Check the length of the current type between the Warning string length
	uint8_t typeLength = strlen(dataMessagesErrors->driverMessage.notificationType.statusDef[typeValue]);
	if(typeLength != DRIVER_MESSAGE_WARNING_TYPE_LENGTH) {
		return 0;
	} else {

		/* Check if the current type is Warning type by checking the string
		 * (In case we have multiple type with the same length)
		 */
		/*
		if(strcmp(dataMessagesErrors->driverMessage.notificationType.statusDef[typeValue], "Warning") == 0) {
			return 1;
		} else {
			return 0;
		}
		*/
		return 1;
	}
}

uint8_t isDataNotificationAlarmType(DataMessagesErrors* dataMessagesErrors) {
	int8_t typeValue = getDataStatus(&(dataMessagesErrors->driverMessage.notificationType));
	// Check if value is not in DEFAULT mode
	if(typeValue == DATA_NOTIFICATION_TYPE_DEFAULT) {
		return 0;
	}
	// Check the length of the current type between the Alarm string length
	uint8_t typeLength = strlen(dataMessagesErrors->driverMessage.notificationType.statusDef[typeValue]);
	if(typeLength != DRIVER_MESSAGE_ALARM_TYPE_LENGTH) {
		return 0;
	} else {

		/* Check if the current type is Alarm type by checking the string
		 * (In case we have multiple type with the same length)
		 */
		/*
		if(strcmp(dataMessagesErrors->driverMessage.notificationType.statusDef[typeValue], "Alarm") == 0) {
			return 1;
		} else {
			return 0;
		}
		*/
		return 1;
	}
}
