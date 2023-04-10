#include "Data/DataControls.h"
#include "Data/DataConstant.h"
#include "DisplayConstant.h"

void initializeDataControls(DataControls* dataControls) {
	initializeData(&(dataControls->batteryVoltage), EMPTY_VALUE, BATTERY_VOLTAGE_CONVERSION_FACTOR);
	initializeData(&(dataControls->launchControlStatus), EMPTY_VALUE, LAUNCH_CONTROL_STATUS_CONVERSION_FACTOR);
	initializeData(&(dataControls->pedal), EMPTY_VALUE, PEDAL_CONVERSION_FACTOR);
	initializeData(&(dataControls->brake), EMPTY_VALUE, BRAKE_CONVERSION_FACTOR);
	initializeData(&(dataControls->brakeRear), EMPTY_VALUE, BRAKE_REAR_CONVERSION_FACTOR);
}

void setFlagNotUpdatedDataControls(DataControls* dataControls) {
	setNotUpdateData(&(dataControls->batteryVoltage));
	setNotUpdateData(&(dataControls->launchControlStatus));
	setNotUpdateData(&(dataControls->pedal));
	setNotUpdateData(&(dataControls->brake));
	setNotUpdateData(&(dataControls->brakeRear));
}
