// START
#include "Data/DataLapTime.h"
// END

void initializeDataLapTime(DataLapTime* dataLapTime) {
	dataLapTime->minutes	 	= DATALAPTIME_DEFAULT_VALUE;
	dataLapTime->seconds	 	= DATALAPTIME_DEFAULT_VALUE;
	dataLapTime->milliSeconds	= DATALAPTIME_DEFAULT_VALUE;
}

void setDataLapTime(DataLapTime* dataLapTime, DataLapTime newDataLapTime) {
	if (newDataLapTime.minutes >= 0 && newDataLapTime.seconds >= 0 && newDataLapTime.milliSeconds >= 0) {
		dataLapTime->minutes	 	= newDataLapTime.minutes;
		dataLapTime->seconds	 	= newDataLapTime.seconds;
		dataLapTime->milliSeconds	= newDataLapTime.milliSeconds;
	}
}

void setDataDataLapTime(DataLapTime* dataLapTime, uint8_t minutes, uint8_t seconds, uint8_t milliSeconds) {
	if (minutes >= 0 && seconds >= 0 && milliSeconds >= 0) {
		dataLapTime->minutes	 	= minutes;
		dataLapTime->seconds	 	= seconds;
		dataLapTime->milliSeconds	= milliSeconds;
	}
}

uint8_t getMinutesDataLapTime(DataLapTime* dataLapTime) {
	return dataLapTime->minutes;
}

uint8_t getSecondsDataLapTime(DataLapTime* dataLapTime) {
	return dataLapTime->seconds;
}

uint16_t getmilliSecondsDataLapTime(DataLapTime* dataLapTime) {
	return dataLapTime->milliSeconds;
}

void getLapTimeDataLapTime(DataLapTime *dataLapTime, char * dataLapTimeString) {
	sprintf(dataLapTimeString, "%d:%02d.%03d", dataLapTime->minutes, dataLapTime->seconds, dataLapTime->milliSeconds);
}
