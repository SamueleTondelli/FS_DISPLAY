#ifndef DATASET_H
#define DATASET_H

#ifdef __cplusplus
extern "C" {
#endif

// START
#include "DataThermalPressure.h"
#include "DataMechanics.h"
#include "DataControls.h"
#include "DataScreen.h"
// END

/*
 * Dataset Struct (Collection of all needed group of Datas)
 * @param thermalPressure		-> DataThermalPressure Struct
 * @param mechanics		-> DataMechanics Struct
 * @param controls		-> DataControls Struct
 * @param screen	-> DataScreen Struct
 */
typedef struct {
	DataThermalPressure thermalPressure;
	DataMechanics mechanics;
	DataControls controls;
	DataScreen screen;
} Dataset;
/*
 * Initialize Dataset Struct
 * @param *dataset 	-> DataSet Struct
 */
void initializeDataset(Dataset *dataset);
/*
 * Set All Datas contained in Dataset not Updated
 * @param *dataset 	-> DataSet Struct
 */
void setFlagNotUpdatedDataset(Dataset* dataset);

#ifdef __cplusplus
}
#endif

#endif /* DATASET_H */
