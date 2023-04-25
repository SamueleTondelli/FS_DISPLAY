#include "Data/DataControls.h"
#include "Data/DataConstant.h"
#include "DisplayConstant.h"

#include "main.h"
#include "adc.h"

void initializeDataControls(DataControls* dataControls) {
	initializeData(&(dataControls->batteryVoltage), EMPTY_VALUE, BATTERY_VOLTAGE_CONVERSION_FACTOR);
	initializeData(&(dataControls->launchControlStatus), EMPTY_VALUE, LAUNCH_CONTROL_STATUS_CONVERSION_FACTOR);
	initializeData(&(dataControls->pedal), EMPTY_VALUE, PEDAL_CONVERSION_FACTOR);
	initializeData(&(dataControls->brake), EMPTY_VALUE, BRAKE_CONVERSION_FACTOR);
	initializeData(&(dataControls->brakeRear), EMPTY_VALUE, BRAKE_REAR_CONVERSION_FACTOR);
	dataControls->tractionControl = 0;
}

void setFlagNotUpdatedDataControls(DataControls* dataControls) {
	setNotUpdateData(&(dataControls->batteryVoltage));
	setNotUpdateData(&(dataControls->launchControlStatus));
	setNotUpdateData(&(dataControls->pedal));
	setNotUpdateData(&(dataControls->brake));
	setNotUpdateData(&(dataControls->brakeRear));
}

void readTractionControlData(DataControls* dataControls) {
	HAL_ADC_Start(&hadc3); //start adc conversion
	//add time check?
	while (HAL_ADC_PollForConversion(&hadc3, 1) != HAL_OK) {} //wait for available data

	uint16_t rawData = HAL_ADC_GetValue(&hadc3);

	if (rawData <= TRACTION_OFF_UPPER_VALUE) {
		dataControls->tractionControl = 0;
	}
	else if (rawData <= TRACTION_1_UPPER_VALUE) {
		dataControls->tractionControl = 1;
	}
	else if (rawData <= TRACTION_2_UPPER_VALUE) {
		dataControls->tractionControl = 2;
	}
	else if (rawData <= TRACTION_3_UPPER_VALUE) {
		dataControls->tractionControl = 3;
	}
	else {
		dataControls->tractionControl = 4;
	}
}











