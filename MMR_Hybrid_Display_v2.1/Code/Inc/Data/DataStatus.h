#ifndef DATA_STATUS_H
#define DATA_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

// START
#include "main.h"
#include "string.h"
// END

#define DATA_STATUS_DEFAUL_DEFINE_LENGTH 20 //TODO Controllare se sufficiente
#define DATA_STATUS_ERROR "ERROR"
#define DATA_STATUS_ERROR_LENGTH 5
#define DATA_STATUS_ERROR_VALUE -1
#define DATA_STATUS_DEFAULT_VALUE -1

// TODO valutare se aggiungere NotUpdate a DataStatus

/*
 *	DataStatus Struct (Store data about Enumeration Data)
 *	@attr status
 *	@attr *statusDef[DATA_STATUS_DEFAUL_DEFINE_LENGTH]	-> Matrix containing Enumeration Value
 *	@attr statusDefLength
 */
typedef struct {
	int8_t status;
	char* statusDef[DATA_STATUS_DEFAUL_DEFINE_LENGTH];	
	uint8_t statusDefLength;
} DataStatus;
/*
 * Initialize DataStatus Struct
 * @param *dataStatus 		-> DataStatus Struct
 */
void initializeDataStatus(DataStatus *dataStatus);
/*
 * Set DataStatus new Value
 * @param *dataStatus 	-> DataStatus Struct
 * @param newStatus 	-> New Value Status
 */
void setDataStatus(DataStatus *dataStatus, int8_t newStatus);
/*
 * Get DataStatus Enumeration Value 
 * @param *dataStatus 		-> DataStatus Struct
 * @return 					-> Def string
 */
char* getCurrentDataStatus(DataStatus * dataStatus);
/*
 * Get length of the current Status Def string
 * @param *dataStatus 		-> DataStatus Struct
 * @return 					-> Def string length
 */
uint8_t getCurrentDataStatusLength(DataStatus *dataStatus);
/*
 *	Get the number of arrays contained in the statusDef array
 *	@param *dataStatus		-> DataStatus Struct
 *	@return 				-> statusDefLength value
 */
uint8_t getDataStatusDefLength(DataStatus *dataStatus);
/*
 * Get DataStatus Value
 * @param *dataStatus 		-> DataStatus Struct
 */
int8_t getDataStatus(DataStatus* dataStatus);

#ifdef __cplusplus
}
#endif

#endif /* DATA_STATUS_H */
