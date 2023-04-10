// START
#include "Data/DataThermalAereodinamics.h"
#include "Data/DataConstant.h"
#include "DisplayConstant.h"
// END

void initializeDataThermalAerodynamics(DataThermalAerodynamics* dataThermalAerodynamics) {
	initializeData(&(dataThermalAerodynamics->coolantTemperatureEV), EMPTY_VALUE, COOLANT_TEMPERATURE_EV_CONVERSION_FACTOR);
	initializeData(&(dataThermalAerodynamics->coolantFan1), EMPTY_VALUE, COOLANT_FAN1_CONVERSION_FACTOR);
	initializeData(&(dataThermalAerodynamics->coolantFan1TemperatureLimit), EMPTY_VALUE, COOLANT_FAN1_TEMPERATURE_LIMIT_CONVERSION_FACTOR);
	initializeData(&(dataThermalAerodynamics->coolantFan2), EMPTY_VALUE, COOLANT_FAN2_CONVERSION_FACTOR);
	initializeData(&(dataThermalAerodynamics->coolantFan2TemperatureLimit), EMPTY_VALUE, COOLANT_FAN2_TEMPERATURE_LIMIT_CONVERSION_FACTOR);
	initializeData(&(dataThermalAerodynamics->brakeTemperatureFrontRight), EMPTY_VALUE, BRAKE_TEMPERATURE_FRONT_RIGHT_CONVERSION_FACTOR);
	initializeData(&(dataThermalAerodynamics->brakeTemperatureFrontLeft), EMPTY_VALUE, BRAKE_TEMPERATURE_FRONT_LEFT_CONVERSION_FACTOR);
	initializeData(&(dataThermalAerodynamics->brakeTemperatureRearRight), EMPTY_VALUE, BRAKE_TEMPERATURE_REAR_RIGHT_CONVERSION_FACTOR);
	initializeData(&(dataThermalAerodynamics->brakeTemperatureRearLeft), EMPTY_VALUE, BRAKE_TEMPERATURE_REAR_LEFT_CONVERSION_FACTOR);
	initializeData(&(dataThermalAerodynamics->brakeTermocouple0), EMPTY_VALUE, BRAKE_THERMOCOUPLE_0_CONVERSION_FACTOR);
	initializeData(&(dataThermalAerodynamics->brakeTermocouple1), EMPTY_VALUE, BRAKE_THERMOCOUPLE_1_CONVERSION_FACTOR);
	initializeData(&(dataThermalAerodynamics->brakeTermocouple2), EMPTY_VALUE, BRAKE_THERMOCOUPLE_2_CONVERSION_FACTOR);
	initializeData(&(dataThermalAerodynamics->brakeTermocouple3), EMPTY_VALUE, BRAKE_THERMOCOUPLE_3_CONVERSION_FACTOR);
	
	initializeDataStatus(&(dataThermalAerodynamics->coolantFanInputMode));
	dataThermalAerodynamics->coolantFanInputMode.statusDef[0] = "Auto";
	dataThermalAerodynamics->coolantFanInputMode.statusDef[1] = "Manual";
	dataThermalAerodynamics->coolantFanInputMode.statusDefLength = 2;

	initializeDataStatus(&(dataThermalAerodynamics->coolantPumpHVState));
	dataThermalAerodynamics->coolantPumpHVState.statusDef[0] = "Error";
	dataThermalAerodynamics->coolantPumpHVState.statusDef[1] = "Timeout";
	dataThermalAerodynamics->coolantPumpHVState.statusDef[2] = "Disabled";
	dataThermalAerodynamics->coolantPumpHVState.statusDef[3] = "Enabled";
	dataThermalAerodynamics->coolantPumpHVState.statusDefLength = 4;
}

void setFlagNotUpdatedDataThermalAerodynamics(DataThermalAerodynamics* dataThermalAerodynamics) {
	setNotUpdateData(&(dataThermalAerodynamics->coolantTemperatureEV));
	setNotUpdateData(&(dataThermalAerodynamics->coolantFan1));
	setNotUpdateData(&(dataThermalAerodynamics->coolantFan1TemperatureLimit));
	setNotUpdateData(&(dataThermalAerodynamics->coolantFan2));
	setNotUpdateData(&(dataThermalAerodynamics->coolantFan2TemperatureLimit));
	setNotUpdateData(&(dataThermalAerodynamics->brakeTemperatureFrontRight));
	setNotUpdateData(&(dataThermalAerodynamics->brakeTemperatureFrontLeft));
	setNotUpdateData(&(dataThermalAerodynamics->brakeTemperatureRearRight));
	setNotUpdateData(&(dataThermalAerodynamics->brakeTemperatureRearLeft));
	setNotUpdateData(&(dataThermalAerodynamics->brakeTermocouple0));
	setNotUpdateData(&(dataThermalAerodynamics->brakeTermocouple1));
	setNotUpdateData(&(dataThermalAerodynamics->brakeTermocouple2));
	setNotUpdateData(&(dataThermalAerodynamics->brakeTermocouple3));
}
