#include "Data/DataTyres.h"
#include "Data/DataConstantTyres.h"
#include "DisplayConstant.h"

void initializeTyre(Tyre* tyre)
{
	tyre->temperature = EMPTY_VALUE;
	tyre->tempSectorsUpdated = 0;
}

void setFirst8Sectors(Tyre* tyre, int8_t* sectors0to7)
{
	memcpy(tyre->tempSectors, sectors0to7, 8);
	tyre->tempSectorsUpdated |= 0x00FF; //set bits 0 to 7
}

void setLast8Sectors(Tyre* tyre, int8_t* sectors8to15)
{
	memcpy(tyre->tempSectors + 8, sectors8to15, 8);
	tyre->tempSectorsUpdated |= 0xFF00; //set bits 8 to 15
}

void updateTyreTemp(Tyre* tyre, int8_t* sectors0to7, int8_t* sectors8to15)
{
	if (sectors0to7 != NULL)
	{
		setFirst8Sectors(tyre, sectors0to7);
	}

	if (sectors8to15 != NULL)
	{
		setLast8Sectors(tyre, sectors8to15);
	}

	if (tyre->tempSectorsUpdated == 0xFFFF) //every bit is set, so we can calculate the mean value of the sectors
	{
		tyre->tempSectorsUpdated = 0;
		float temp = 0;
		for (int i = 0; i < 16; i++)
		{
			temp += tyre->tempSectors[i];
		}
		tyre->temperature = temp / 16;
	}
}

void initializeDataTyres(DataTyres* dataTyres)
{
	initializeTyre(&(dataTyres->FR));
	initializeTyre(&(dataTyres->FL));
	initializeTyre(&(dataTyres->RR));
	initializeTyre(&(dataTyres->RL));
}
