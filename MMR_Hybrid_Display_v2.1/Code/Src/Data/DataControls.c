#include "Data/DataControls.h"
#include "Data/DataConstant.h"
#include "DisplayConstant.h"

void initializeDataControls(DataControls* dataControls) {
	intializeData(&(dataMechanics->batteryVoltage), EMPTY_VALUE, BATTERY_VOLTAGE_CONVERSION_FACTOR);
	intializeData(&(dataMechanics->batteryVoltage), EMPTY_VALUE, BATTERY_VOLTAGE_CONVERSION_FACTOR);
}

void setFlagNotUpdatedDataControls(DataControls* dataControls) {
}
