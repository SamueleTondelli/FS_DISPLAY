// START
#include "Data/DataHVElectronicsInverter.h"
#include "Data/DataConstant.h"
#include "DisplayConstant.h"
// END

void initializeDataHVElectronicsInverter(DataHVElectronicsInverter* dataHVElectronicsInverter) {
	inizializeData(&(dataHVElectronicsInverter->electricMotorSpeed), EMPTY_VALUE, ELECTRIC_MOTOR_SPEED_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsInverter->electricMotorTorque), EMPTY_VALUE, ELECTRIC_MOTOR_TORQUE_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsInverter->electricMotorTemperature), EMPTY_VALUE, ELECTRIC_MOTOR_TEMPERATURE_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsInverter->targetID), EMPTY_VALUE, TARGET_ID_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsInverter->targetIQ), EMPTY_VALUE, TARGET_IQ_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsInverter->currentID), EMPTY_VALUE, ID_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsInverter->currentIQ), EMPTY_VALUE, IQ_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsInverter->inverterCapacitorVoltage), EMPTY_VALUE, INVERTER_CAPACITOR_VOLTAGE_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsInverter->inverterTemperature), EMPTY_VALUE, INVERTER_TEMPERATURE_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsInverter->inverterBatteryCurrent), EMPTY_VALUE, INVERTER_BATTERY_CURRENT_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsInverter->inverterBatteryVoltage), EMPTY_VALUE, INVERTER_BATTERY_VOLTAGE_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsInverter->inverterTorqueMax), EMPTY_VALUE, INVERTER_MAX_TORQUE_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsInverter->inverterSpeedMax), EMPTY_VALUE, INVERTER_MAX_SPEED_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsInverter->batteryDischargeCurrentMax), EMPTY_VALUE, BATTERY_DISCHARGE_CURRENT_MAX_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsInverter->batteryChargeCurrentMax), EMPTY_VALUE, BATTERY_CHARGE_CURRENT_MAX_CONVERSION_FACTOR);
	inizializeData(&(dataHVElectronicsInverter->actualPowerProvidedElectric), EMPTY_VALUE, ACTUAL_POWER_PROVIDED_ELECTRIC_CONVERSION_FACTOR);
}

void setFlagNotUpdatedDataHVElectronicsInverter(DataHVElectronicsInverter* dataHVElectronicsInverter) {
	setNotUpdateData(&(dataHVElectronicsInverter->electricMotorSpeed));
	setNotUpdateData(&(dataHVElectronicsInverter->electricMotorTorque));
	setNotUpdateData(&(dataHVElectronicsInverter->electricMotorTemperature));
	setNotUpdateData(&(dataHVElectronicsInverter->targetID));
	setNotUpdateData(&(dataHVElectronicsInverter->targetIQ));
	setNotUpdateData(&(dataHVElectronicsInverter->currentID));
	setNotUpdateData(&(dataHVElectronicsInverter->currentIQ));
	setNotUpdateData(&(dataHVElectronicsInverter->inverterCapacitorVoltage));
	setNotUpdateData(&(dataHVElectronicsInverter->inverterTemperature));
	setNotUpdateData(&(dataHVElectronicsInverter->inverterBatteryCurrent));
	setNotUpdateData(&(dataHVElectronicsInverter->inverterBatteryVoltage));
	setNotUpdateData(&(dataHVElectronicsInverter->inverterTorqueMax));
	setNotUpdateData(&(dataHVElectronicsInverter->inverterSpeedMax));
	setNotUpdateData(&(dataHVElectronicsInverter->batteryDischargeCurrentMax));
	setNotUpdateData(&(dataHVElectronicsInverter->batteryChargeCurrentMax));
	setNotUpdateData(&(dataHVElectronicsInverter->actualPowerProvidedElectric));
}
