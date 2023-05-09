// START
#include "Data/Data.h"
#include "DisplayConstant.h"
// END

void initializeData(Data *data, float value, float conv, uint8_t priority, float maxValue, float minValue) {
	data->value = value;
	data->conversionFactor = conv;
	data->isUpdated = 0;
	data->alarmStatus = OFF_QUEUE;
	data->priority = priority;
	data->maxValue = maxValue;
	data->minValue = minValue;
}

float getValueData(Data *data) {
	return data->value;
}

float* getPointerValueData(Data *data) {
	return &data->value;
}

void setValueData(Data *data, float newValue) {
	data->value = newValue * data->conversionFactor;
	data->isUpdated = 0;
}

void setValueDataNoConversion(Data *data, float newValue) {
	data->value = newValue;
	data->isUpdated = 0;
}

void setUpdateData(Data* data) {
	data->isUpdated = 0;
}

void setNotUpdateData(Data* data) {
	// Sanity Check to not update flag when data is lost for long time
	if(data->isUpdated < 250) {
		data->isUpdated += 1;
	}
}

uint8_t isDataUpdated(Data* data) {
	if (data->isUpdated >= DATA_UPDATED_COUNTER_LIMIT) {
		return 0;
	} else {
		return 1;
	}
}

uint8_t isDataCritical(Data* data)
{
	if ((data->value != EMPTY_VALUE) && ((data->maxValue != EMPTY_VALUE && data->value > data->maxValue) || (data->minValue != EMPTY_VALUE && data->value < data->minValue)))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void activateDataAlarm(Data* data, char* name)
{
	if (data->alarmStatus == OFF_QUEUE || (data->alarmStatus == DEACTIVATED && uwTick - data->alarmDeactivationTime >= ALARM_DEACTIVATION_TIME))
	{
		data->alarmStatus = ON;
		Alarm alarm = {.priority = data->priority,.contents = (void *)data, .type = DATA};
		strcpy(alarm.name, name);
		insertAlarmInQueue(&alarm);
	}
}
