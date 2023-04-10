// START
#include "Data/Data.h"
// END

void initializeData(Data *data, float value, float conv) {
	data->value = value;
	data->conversionFactor = conv;
	data->isUpdated = 0;
}

float getValueData(Data *data) {
	return data->value;
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
