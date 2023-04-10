#ifndef DATA_H
#define DATA_H

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

#define DATA_UPDATED_COUNTER_LIMIT 2

/*
 * Data Struct Data Struct is the smallest unit of data
 * @attr value					-> stored value
 * @attr conversionFactorA		-> numerator conversion factor
 * @attr flag updated			-> flag used as counter to check if this value has been updated
 */
typedef struct {
	float value;
	float conversionFactor;
	uint8_t isUpdated;
} Data;
/*
 * Initialize Data Struct
 * @param *data		-> Data Struct
 * @param  value	-> default value
 * @param *convA	-> conversionFactor
 */
void initializeData(Data *data, float value, float conv);
/*
 * Get converted value from Data Struct
 * @param *data		-> Data Struct
 * @return			-> converted stored value
 */
float getValueData(Data *data);
/*
 * Set value in the Data Struct
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

#ifdef __cplusplus
}
#endif

#endif	/* DATA_H */
