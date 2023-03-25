#ifndef INC_SDCARDHANDLER_H_
#define INC_SDCARDHANDLER_H_

#ifdef __cplusplus
extern "C" {
#endif

// START DEBUG
#include "main.h"
#include "Data/Dataset.h"
//#include "fatfs.h"	// TODO Per SDCard
// FILE
#include "stdio.h" 
#include "string.h"
// END DEBUG

/*
 *	DataSDcard Struct (Store data about SD Card)
 *	@attr *file
 */
typedef struct {
	FILE* file;
} DataSDcard;
/*
 * (DEBUG) Example used to test SD Card 
 */
int testSDcard();
/*
 * Initialize SD Card: enable SD Card
 * @param *dataset 	-> DataSet Struct
 */
int initializeSDCard();
/*
 * Search "SimulationMode" File and open it. 
 * Before that check if the first row respects the template file pattern
 * @param *sdCard		-> DataSDcard Struct
 * @param *fileName		-> File Name 
 * @param *rowTemplate  -> First Row Template Pattern
 * @return [0 = Ok, < 0 = otherwise]
 */
int openFile(DataSDcard* sdCard, const char* fileName, const char* rowTemplate);
/*
 * Close SD Card File
 * @param *sdCard 	-> DataSDcard Struct
 */
void closeFile(DataSDcard* sdCard);
/*
 * Read a row in the "SimulationMode" File
 * @param *sdCard 		-> DataSDcard Struc
 * @param *datasset 	-> DataSet Struct
 */
int readFileRow(DataSDcard *sdCard, Dataset *dataset);
/*
 * Initialize Dataset Struct
 * @param *sdCard 		-> DataSDcard Struc
 * @param *data 		-> Readed File Row as Array of Characters
 */
int decodifyFileRow(Dataset *dataset, char *data);
/*
 * Initialize Dataset Struct
 * @param *dataset 		-> DataSet Struct
 * @param newValue 		-> New Value
 * @param dataCounter 	-> Template Row Position
 */
void insertRowDataToDataset(Dataset* dataset, float newValue, uint16_t dataCounter);

#ifdef __cplusplus
}
#endif

#endif /* INC_SDCARDHANDLER_H_ */
