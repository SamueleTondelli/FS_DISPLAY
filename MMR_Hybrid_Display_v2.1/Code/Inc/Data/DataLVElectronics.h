#ifndef DATA_LV_ELECTRONICS_H
#define DATA_LV_ELECTRONICS_H

#ifdef __cplusplus
extern "C" {
#endif

// START
#include "Data.h"
#include "DataStatus.h"
// END

/*
 *	DataLVElectronics Struct (Store data about all low voltage signals and others)
 *	@attr voltageBatteryLV;
 *	@attr throttlePedal;
 *	@attr throttlePosition;
 *	@attr tps1;
 *	@attr tps2;
 *	@attr apps1;
 *	@attr apps2;
 *	@attr bseFront;
 *	@attr bseRear;

 *	@attr can1Diagnostic;
 *	@attr can1Mode;
 *	@attr can2Diagnostic;
 *	@attr can2Mode;
 *	@attr can3Diagnostic;
 *	@attr can3Mode;

 *	@attr ecuCpuUsage;
 *	@attr ecuLed;
 *	@attr ecuTemperature;

 *	@attr etcMode;
 *	@attr etcState;
 *	@attr etcCriticalState;
 *	@attr etcThrottlePedalCritical;
 *	@attr markerButton;
 *	@attr mapAButton;
 *	@attr mapEButton;
 *	@attr mapCButton;
 *	@attr neutralButton;
 *	@attr killButton;
 *	@attr startButton;
 *	@attr readyToDriveButton;
 *	@attr readyToDriveState;
 *	@attr readyToDriveRelayState;
 *	@attr gbuUpshiftInputRequest;
 *	@attr gbuDownShiftInputRequest;
 */
typedef struct {
	Data voltageBatteryLV;
	Data throttlePedal;
	Data throttlePosition;
	Data tps1;
	Data tps2;
	Data apps1;
	Data apps2;
	Data bseFront;
	Data bseRear;

	DataStatus can1Diagnostic;
	DataStatus can1Mode;
	DataStatus can2Diagnostic;
	DataStatus can2Mode;
	DataStatus can3Diagnostic;
	DataStatus can3Mode;

	Data ecuCpuUsage;
	Data ecuLed;	// TODO Valutare se convertire in DataStatus
	Data ecuTemperature;

	DataStatus etcMode;
	DataStatus etcState;
	DataStatus etcCriticalState;
	DataStatus etcThrottlePedalCritical;
	DataStatus markerButton;
	DataStatus mapAButton;
	DataStatus mapEButton;
	DataStatus mapCButton;
	DataStatus neutralButton;
	DataStatus killButton;
	DataStatus startButton;
	DataStatus readyToDriveButton;
	DataStatus readyToDriveState;
	DataStatus readyToDriveRelayState;
	DataStatus gbuUpshiftInputRequest;
	DataStatus gbuDownShiftInputRequest;

} DataLVElectronics;
/*
* Initialize DataLVElectronics Struct
* @param *dataLVElectronics 		-> DataLVElectronics Struct
*/
void initializeDataLVElectronics(DataLVElectronics* dataLVElectronics);
/*
 * Unset Flag Updated to All Datas include in this Dataset
 * @param *dataLVElectronics 		-> DataLVElectronics Struct
 */
void setFlagNotUpdatedDataLVElectronics(DataLVElectronics* dataLVElectronics);

#ifdef __cplusplus
}
#endif

#endif /* DATA_LV_ELECTRONICS_H */
