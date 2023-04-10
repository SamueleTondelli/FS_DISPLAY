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

#ifdef __cplusplus
}
#endif

#endif /* DATA_DATACONTROLS_H_ */
