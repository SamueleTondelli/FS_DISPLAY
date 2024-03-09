#ifndef DATA_H
#define DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"
#include "DataAlarms.h"

#define DATA_UPDATED_COUNTER_LIMIT 2

/*
 * Data Struct Data Struct is the smallest unit of data
 * @attr value					-> stored value
 * @attr conversionFactorA		-> numerator conversion factor
 * @attr flag updated			-> flag used as counter to check if this value has been updated
 * @attr priority				-> priority of the alarm, 0-5 with 0 being the highest priority
 * @attr alarmStatus			-> status of the alarm (OFF, ON, DEACTIVATED)
 * @attr maxValue				-> max value before triggering alarm
 * @attr minValue				-> min value before triggering alarm
 * @attr alarmDeactivationTime	-> time when alarm was deactivated
 */
typedef struct {
	float value;
	float conversionFactor;
	uint8_t isUpdated;
	uint8_t priority;
	ALARM_STATUS alarmStatus;
	float maxValue;
	float minValue;
	uint32_t alarmDeactivationTime;
} Data;
/*
 * Initialize Data Struct
 * @param *data		-> Data Struct
 * @param  value	-> default value
 * @param *convA	-> conversionFactor
 */
void initializeData(Data *data, float value, float conv, uint8_t priority, float maxValue, float minValue);
/*
 * Get converted value from Data Struct
 * @param *data		-> Data Struct
 * @return			-> converted stored value
 */
float getValueData(Data *data);
/*
 * Set value in the Data Struct and check if it's critical
 * @param *data		-> Data Struct
 * @param  newValue	-> new Value to store
 */
void setValueData(Data *data, float newValue);
/*
 * Set value in the Data Struct without converting it
 * @param *data		-> Data Struct
 * @param  newValue	-> new Value to store
 */
void setValueDataNoConversion(Data *data, float newValue);
/*
 * Set Flag isUpdated so the current Data is updated
 * @param *data		-> Data Struct
 */
void setUpdateData(Data* data);
/*
 * UnSet Flag isUpdated so the current Data is not updated
 * @param *data		-> Data Struct
 */
void setNotUpdateData(Data* data);
/*
 * Get Data Updated Flag. Check if the current data value is fresh and not outdated
 * @param *data		-> Data Struct
 * @return Data Updated Flag
 */
uint8_t isDataUpdated(Data* data);
/*
 * Check if current data value is critical
 * @param *data		-> Data Struct
 * @return	0 = OK, -1 = less than min, 1 = more than max
 */
int8_t isDataCritical(Data* data);

/*
 *  Activates and insert alarm in queue of data with name = name
 *  @param *data	-> Data Struct
 *  @param *name	-> name to give to the alarm
 */
void activateDataAlarm(Data* data, char* name);

#ifdef __cplusplus
}
#endif

#endif	/* DATA_H */
