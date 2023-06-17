#include "Data/DataControls.h"
#include "Data/DataConstant.h"
#include "DisplayConstant.h"

#include "main.h"
#include "adc.h"

void initializeDataControls(DataControls* dataControls) {
	initializeData(&(dataControls->batteryVoltage), EMPTY_VALUE, BATTERY_VOLTAGE_CONVERSION_FACTOR, BATTERY_VOLTAGE_ALARM_PRIORITY, BATTERY_VOLTAGE_MAX_VALUE, BATTERY_VOLTAGE_MIN_VALUE);
	initializeData(&(dataControls->launchControlStatus), EMPTY_VALUE, LAUNCH_CONTROL_STATUS_CONVERSION_FACTOR, DEFAULT_PRIORITY, EMPTY_VALUE, EMPTY_VALUE);
	initializeData(&(dataControls->pedal), EMPTY_VALUE, PEDAL_CONVERSION_FACTOR, DEFAULT_PRIORITY, EMPTY_VALUE, EMPTY_VALUE);
	initializeData(&(dataControls->brake), EMPTY_VALUE, BRAKE_CONVERSION_FACTOR, DEFAULT_PRIORITY, EMPTY_VALUE, EMPTY_VALUE);
	initializeData(&(dataControls->brakeRear), EMPTY_VALUE, BRAKE_REAR_CONVERSION_FACTOR, DEFAULT_PRIORITY, EMPTY_VALUE, EMPTY_VALUE);
	initializeData(&(dataControls->tractionControl), EMPTY_VALUE, TRACTION_CONTROL_CONVERSION_FACTOR, NOTIFICATION_PRIORITY, EMPTY_VALUE, EMPTY_VALUE);
	initializeData(&(dataControls->steer), EMPTY_VALUE, STEER_CONVERSION_FACTOR, DEFAULT_PRIORITY, EMPTY_VALUE, EMPTY_VALUE);

	dataControls->map = 0;
	writeMap(dataControls);
}

void setFlagNotUpdatedDataControls(DataControls* dataControls) {
	setNotUpdateData(&(dataControls->batteryVoltage));
	setNotUpdateData(&(dataControls->launchControlStatus));
	setNotUpdateData(&(dataControls->pedal));
	setNotUpdateData(&(dataControls->brake));
	setNotUpdateData(&(dataControls->brakeRear));
	setNotUpdateData(&(dataControls->tractionControl));
	setNotUpdateData(&(dataControls->steer));
}

void readTractionControlData(DataControls* dataControls) {
	HAL_ADC_Start(&hadc3); //start adc conversion
	//add time check?
	while (HAL_ADC_PollForConversion(&hadc3, 1) != HAL_OK) {} //wait for available data

	uint16_t rawData = HAL_ADC_GetValue(&hadc3);
	uint8_t newValue;
	if (rawData <= TRACTION_OFF_UPPER_VALUE) {
		newValue = 0;
	}
	else if (rawData <= TRACTION_1_UPPER_VALUE) {
		newValue = 1;
	}
	else if (rawData <= TRACTION_2_UPPER_VALUE) {
		newValue = 2;
	}
	else if (rawData <= TRACTION_3_UPPER_VALUE) {
		newValue = 3;
	}
	else {
		newValue = 4;
	}

	if (newValue != getValueData(&(dataControls->tractionControl)))
	{
		setValueData(&(dataControls->tractionControl), newValue);
		activateDataAlarm(&(dataControls->tractionControl), "NEW TRC");
	}
	else
	{
		dataControls->tractionControl.alarmStatus = OFF_QUEUE;
	}
}

void toggleMap(DataControls* dataControls)
{
	dataControls->map = !dataControls->map;
	writeMap(dataControls);
	Alarm a = {.priority = NOTIFICATION_PRIORITY, .contents = (void*)(&(dataControls->map)), .type = MAP};
	strcpy(a.name, "MAP");
	insertAlarmInQueue(&a);
}

void writeMap(DataControls* dataControls)
{
	HAL_GPIO_WritePin(MAP_OUT_GPIO_Port, MAP_OUT_Pin, !dataControls->map); //!map because of push pull
}
