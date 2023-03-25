// START
#include "Data/DataHVElectronicsBMS.h"
#include "Data/DataConstant.h"
#include "DisplayConstant.h"
// END

void initializeDataHVElectronicsBMS(DataHVElectronicsBMS* dataHVElectronicsBMS) {
	inizializeData(&(dataHVElectronicsBMS->delta), EMPTY_VALUE, DELTA_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsBMS->deltaMax), EMPTY_VALUE, DELTA_MAX_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsBMS->soc), EMPTY_VALUE, SOC_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsBMS->soh), EMPTY_VALUE, SOH_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsBMS->ampereBatteryHV), EMPTY_VALUE, BATTERY_HV_CURRENT_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsBMS->ampereBatteryHVmax), EMPTY_VALUE, AMPERE_BATTERY_HV_MAX_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsBMS->voltageBatteryHV), EMPTY_VALUE, BATTERY_HV_VOLTAGE_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsBMS->batteryTMH), EMPTY_VALUE, BATTERY_HV_TMH_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsBMS->batteryTML), EMPTY_VALUE, BATTERY_HV_TML_CONVERSION_FACTOR);
}

void setFlagNotUpdatedDataHVElectronicsBMS(DataHVElectronicsBMS* dataHVElectronicsBMS) {
	setNotUpdateData(&(dataHVElectronicsBMS->delta));
	setNotUpdateData(&(dataHVElectronicsBMS->deltaMax));
	setNotUpdateData(&(dataHVElectronicsBMS->soc));
	setNotUpdateData(&(dataHVElectronicsBMS->soh));
	setNotUpdateData(&(dataHVElectronicsBMS->ampereBatteryHV));
	setNotUpdateData(&(dataHVElectronicsBMS->ampereBatteryHVmax));
	setNotUpdateData(&(dataHVElectronicsBMS->voltageBatteryHV));
	setNotUpdateData(&(dataHVElectronicsBMS->batteryTMH));
	setNotUpdateData(&(dataHVElectronicsBMS->batteryTML));
}
