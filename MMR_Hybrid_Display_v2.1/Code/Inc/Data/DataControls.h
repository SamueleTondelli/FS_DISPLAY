#ifndef DATA_DATACONTROLS_H_
#define DATA_DATACONTROLS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Data.h"

/*
 * DataControls Struct (Stores data about controls)
 * @attr batteryVoltage
 * @attr launchControlStatus
 * @attr pedal					->throttle pedal position (0 - 100)
 * @attr brake
 * @attr brakeRear
 */
typedef struct {
	Data batteryVoltage;
	Data launchControlStatus;
	Data pedal;
	Data brake;
	Data brakeRear;
} DataControls;

/*
 * Initialize DataControls Struct
 * @param dataMechanics	-> DataMechanics Struct
 */
void initializeDataControls(DataControls* dataControls);

/*
 * Unset Flag Updated to All Datas include in this Dataset
 * @param dataControls	-> DataControls Struct
 */
void setFlagNotUpdatedDataControls(DataMechanics* dataControls);

#ifdef __cplusplus
}
#endif

#endif /* DATA_DATACONTROLS_H_ */
