#ifndef DATAMECHANICS_H_
#define DATAMECHANICS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Data.h"

/*
 * DataMechanics Struct (Stores data about mechanical parameters)
 * @attr rpm
 * @attr gear
 * @attr slip
 * @attr speed
 * @attr tps
 */
typedef struct {
	Data rpm;
	Data gear;
	Data slip;
	Data speed;
	Data tps;
	Data carHeightFR;
	Data carHeightFL;
	Data carHeightRR;
	Data carHeightRL;
} DataMechanics;

/*
 * Initialize DataMechanics Struct
 * @param dataMechanics	-> DataMechanics Struct
 */
void initializeDataMechanics(DataMechanics* dataMechanics);

/*
 * Unset Flag Updated to All Datas include in this Dataset
 * @param dataMehcanics	-> DataMechanics Struct
 */
void setFlagNotUpdatedDataMechanics(DataMechanics* dataMechanics);

#ifdef __cplusplus
}
#endif

#endif /* DATAMECHANICS_H_ */
