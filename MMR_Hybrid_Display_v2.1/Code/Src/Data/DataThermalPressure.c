#include "Data/DataThermalPressure.h"
#include "Data/DataConstant.h"

void initializeDataThermalPressure(DataThermalPressure* dataThermalPressure) {
	initializeData(&(dataThermalPressure->oilPressure), EMPTY_VALUE, OIL_PRESSURE_CONVERSION_FACTOR);
	initializeData(&(dataThermalPressure->oilTemperature), EMPTY_VALUE, OIL_TEMPERATURE_CONVERSION_FACTOR);
	initializeData(&(dataThermalPressure->fuelPressure), EMPTY_VALUE, FUEL_PRESSURE_CONVERSION_FACTOR);
	initializeData(&(dataThermalPressure->fuelTemperature), EMPTY_VALUE, FUEL_TEMPERATURE_CONVERSION_FACTOR);
	initializeData(&(dataThermalPressure->airTemperature), EMPTY_VALUE, AIR_TEMPERATURE_CONVERSION_FACTOR);
	initializeData(&(dataThermalPressure->waterTemperature), EMPTY_VALUE, WATER_TEMPERATURE_CONVERSION_FACTOR);
}

void setFlagNotUpdatedDataThermalPressure(DataThermalPressure* dataThermalPressure) {
	setNotUpdateData(&(dataThermalPressure->oilPressure));
	setNotUpdateData(&(dataThermalPressure->oilTemperature));
	setNotUpdateData(&(dataThermalPressure->fuelPressure));
	setNotUpdateData(&(dataThermalPressure->fuelTemperature));
	setNotUpdateData(&(dataThermalPressure->airTemperature));
	setNotUpdateData(&(dataThermalPressure->waterTemperature));
}
