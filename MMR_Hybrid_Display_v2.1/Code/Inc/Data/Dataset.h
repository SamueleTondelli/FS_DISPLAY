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
#include "DataMessage.h"
#include "Button.h"
#include "DataTyres.h"
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
	DataTyres tyres;
	DataScreen screen;

	DataMessage telemetryMessage[3];

	Button dispBtn;
	Button okBtn;
	Button markBtn;
	Button mapBtn;

	/*variables for lap timer*/
	float						lapStartLat;
	float						lapStartLon;
	int32_t						bestLapTime;
	int32_t						lapTime;
	int32_t						lapTimeDelta;
	int32_t						lapNumber;
	int32_t						lapSector;
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
