// START
#include "Data/DataStatus.h"
// END

void initializeDataStatus(DataStatus *dataStatus) {
	dataStatus->status = DATA_STATUS_DEFAULT_VALUE;
	dataStatus->statusDefLength = 0;
}

void setDataStatus(DataStatus *dataStatus, int8_t newStatus) {
	if (newStatus >= 0 && newStatus < dataStatus->statusDefLength) {
		dataStatus->status = newStatus;
	}
}

char* getCurrentDataStatus(DataStatus *dataStatus) {
	uint8_t position = dataStatus->status;
	if (position >= 0 && position < dataStatus->statusDefLength) {
		return dataStatus->statusDef[position];
	}

	return DATA_STATUS_ERROR;
}

uint8_t getCurrentDataStatusLength(DataStatus *dataStatus) {
	uint8_t position = dataStatus->status;
	if (position >= 0 && position < dataStatus->statusDefLength) {
		return strlen(dataStatus->statusDef[position]);
	}

	return DATA_STATUS_ERROR_VALUE;
}

uint8_t getDataStatusDefLength(DataStatus *dataStatus) {
	return dataStatus->statusDefLength;
}

int8_t getDataStatus(DataStatus* dataStatus) {
	return dataStatus->status;
}
