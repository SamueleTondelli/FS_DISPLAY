#ifndef INC_DATA_DATATYRES_H_
#define INC_DATA_DATATYRES_H_

#include "Data/Data.h"

typedef struct {
	float temperature;
	int8_t tempSectors[16];
	uint16_t tempSectorsUpdated; //every bit corresponds to a sector, if it's 1 then it's updated
} Tyre;

typedef struct {
	Tyre FR;
	Tyre FL;
	Tyre RR;
	Tyre RL;
} DataTyres;

void initializeTyre(Tyre* tyre);
void setFirst8Sectors(Tyre* tyre, int8_t* sectors0to7);
void setLast8Sectors(Tyre* tyre, int8_t* sectors8to15);
void updateTyreTemp(Tyre* tyre, int8_t* sectors0to7, int8_t* sectors8to15);
/*
* Initialize DataTyres Struct
* @param dataTyres -> DataTyres Struct
*/
void initializeDataTyres(DataTyres* dataTyres);

#endif /* INC_DATA_DATATYRES_H_ */
