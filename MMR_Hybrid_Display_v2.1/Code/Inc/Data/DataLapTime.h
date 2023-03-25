#ifndef DATA_LAP_TIME_H
#define DATA_LAP_TIME_H

#ifdef __cplusplus
extern "C" {
#endif

// START
#include "main.h"
#include "stdio.h"
#include "string.h"
// END

#define DATALAPTIME_DEFAULT_VALUE 0

/*
 *	DataLapTime Struct (Store data about Car Lap Time)
 *	@attr minutes;
 *	@attr seconds;
 *	@attr milliSeconds;
 */
typedef struct {
	uint8_t minutes;
	uint8_t seconds;
	uint8_t milliSeconds;
} DataLapTime;
/*
 * Initialize DataLapTime Struct
 * @param *dataLapTime 		-> DataLapTime Struct
 */
void initializeDataLapTime(DataLapTime* dataLapTime);
/*
 * Set DataLapTime from a existing DataLapTime
 * @param *dataLapTime 		-> DataLapTime Struct
 * @param newDataLapTime 	-> Existing DataLapTime
 */
void setDataLapTime(DataLapTime *dataLapTime, DataLapTime newDataLapTime);
/*
 * Set DataLapTime from Minutes, Seconds, milliSeconds
 * @param *dataLapTime 		-> DataLapTime Struct
 * @param newDataLapTime 	-> Existing DataLapTime
 */
void setDataDataLapTime(DataLapTime *dataLapTime, uint8_t minutes, uint8_t seconds, uint8_t milliSeconds);
/*
 * Get DataLapTime Minutes
 * @param  *dataLapTime 		-> DataLapTime Struct
 * @return Minutes DataLapTime
 */
uint8_t getMinutesDataLapTime(DataLapTime* dataLapTime);
/*
 * Get DataLapTime Seconds
 * @param  *dataLapTime 		-> DataLapTime Struct
 * @return Seconds DataLapTime
 */
uint8_t getSecondsDataLapTime(DataLapTime* dataLapTime);
/*
 * Get DataLapTime MilliSeconds
 * @param  *dataLapTime 		-> DataLapTime Struct
 * @return MilliSeconds DataLapTime
 */
uint16_t getmilliSecondsDataLapTime(DataLapTime* dataLapTime);
/*
 * Get DataLapTime as String in format (MM:SS.sss)
 * @param *dataLapTime 		 -> DataLapTime Struct
 * @param *dataLapTimeString -> Chart Array
 */
void getLapTimeDataLapTime(DataLapTime* dataLapTime, char* dataLapTimeString);

#ifdef __cplusplus
}
#endif

#endif /* DATA_LAP_TIME_H */
