#include "Data/DataThermalPressure.h"
#include "Data/DataConstant.h"
#include "DisplayConstant.h"

void initializeDataThermalPressure(DataThermalPressure* dataThermalPressure) {
	initializeData(&(dataThermalPressure->oilPressure), EMPTY_VALUE, OIL_PRESSURE_CONVERSION_FACTOR, OIL_PRESSURE_ALARM_PRIORITY, OIL_PRESSURE_MAX_VALUE, OIL_PRESSURE_MIN_VALUE);
	initializeData(&(dataThermalPressure->oilTemperature), EMPTY_VALUE, OIL_TEMPERATURE_CONVERSION_FACTOR, OIL_TEMPERATURE_ALARM_PRIORITY, OIL_TEMPERATURE_MAX_VALUE, OIL_TEMPERATURE_MIN_VALUE);
	initializeData(&(dataThermalPressure->fuelPressure), EMPTY_VALUE, FUEL_PRESSURE_CONVERSION_FACTOR, FUEL_PRESSURE_ALARM_PRIORITY, FUEL_PRESSURE_MAX_VALUE, FUEL_PRESSURE_MIN_VALUE);
	initializeData(&(dataThermalPressure->fuelTemperature), EMPTY_VALUE, FUEL_TEMPERATURE_CONVERSION_FACTOR, FUEL_TEMPERATURE_ALARM_PRIORITY, FUEL_TEMPERATURE_MAX_VALUE, FUEL_TEMPERATURE_MIN_VALUE);
	initializeData(&(dataThermalPressure->airTemperature), EMPTY_VALUE, AIR_TEMPERATURE_CONVERSION_FACTOR, AIR_TEMPERATURE_ALARM_PRIORITY, AIR_TEMPERATURE_MAX_VALUE, AIR_TEMPERATURE_MIN_VALUE);
	initializeData(&(dataThermalPressure->waterTemperature), EMPTY_VALUE, WATER_TEMPERATURE_CONVERSION_FACTOR, WATER_TEMPERATURE_ALARM_PRIORITY, WATER_TEMPERATURE_MAX_VALUE, WATER_TEMPERATURE_MIN_VALUE);
}

void setFlagNotUpdatedDataThermalPressure(DataThermalPressure* dataThermalPressure) {
	setNotUpdateData(&(dataThermalPressure->oilPressure));
	setNotUpdateData(&(dataThermalPressure->oilTemperature));
	setNotUpdateData(&(dataThermalPressure->fuelPressure));
	setNotUpdateData(&(dataThermalPressure->fuelTemperature));
	setNotUpdateData(&(dataThermalPressure->airTemperature));
	setNotUpdateData(&(dataThermalPressure->waterTemperature));
}
