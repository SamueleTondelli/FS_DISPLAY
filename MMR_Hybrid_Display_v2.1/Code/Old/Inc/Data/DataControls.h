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
 * @attr tractionControl		->from 0 to 4, read from adc1
 */
typedef struct {
	Data batteryVoltage;
	Data launchControlStatus;
	Data pedal;
	Data brake;
	Data brakeRear;
	Data tractionControl;
	Data steer;
	Data gpsLatitude;
	Data gpsLongitude;
	Data gpsAltitude;

	uint8_t map;
} DataControls;

/*
 * Initialize DataControls Struct
 * @param dataControls	-> DataControls Struct
 */
void initializeDataControls(DataControls* dataControls);

/*
 * Unset Flag Updated to All Datas include in this Dataset
 * @param dataControls	-> DataControls Struct
 */
void setFlagNotUpdatedDataControls(DataControls* dataControls);

/*
 * Reads current traction control level from adc1
 * @param dataControls	-> DataControls Struct
 */
void readTractionControlData(DataControls* dataControls);

void toggleMap(DataControls* dataControls);
void writeMap(DataControls* dataControls);

#ifdef __cplusplus
}
#endif

#endif /* DATA_DATACONTROLS_H_ */
