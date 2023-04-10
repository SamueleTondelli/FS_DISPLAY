#ifndef DATASET_H
#define DATASET_H

#ifdef __cplusplus
extern "C" {
#endif

// START
#include "DataPowerUnit.h"
#include "DataHVElectronicsBMS.h"
#include "DataHVElectronicsInverter.h"
#include "DataLVElectronics.h"
#include "DataThermalAereodinamics.h"
#include "DataDynamics.h"
#include "DataMessagesErrors.h"
#include "DataScreen.h"
#include "TimersList.h"
// END

/*
 * Dataset Struct (Collection of all needed group of Datas)
 * @param alarm		-> DataAlarm Struct
 * @param cv		-> DataCV Struct
 * @param ev		-> DataEV Struct
 * @param general	-> DataGeneral Struct
 * @param hv		-> DataHV Struct
 * @param inverter	-> DataInverter Struct
 * @param lv		-> DataLV Struct
 * @param screen	-> DataScreen Struct
 * @param status	-> DataStatus Struct
 */
typedef struct {
	DataPowerUnit powerUnit;
	DataHVElectronicsBMS hvElectronicsBMS;
	DataHVElectronicsInverter hvElectronicsInverter;
	DataLVElectronics lvElectronics;
	DataThermalAerodynamics thermalAerodynamics;
	DataDynamics dynamics;
	DataMessagesErrors messageErrors;
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
/*
 * Get Pressure Oil Alarm Status
 * @param *dataset 	-> DataSet Struct
 * @return [0 - 1]
 */
uint8_t isPressureOilAlarmOn(Dataset* dataset);
/*
 * Get Oil Temperature Alarm Status
 * @param *dataset 	-> DataSet Struct
 * @return [0 - 1]
 */
uint8_t isOilTemperatureAlarmOn(Dataset* dataset);
/*
 * Get Water Temperature Alarm Status
 * @param *dataset 	-> DataSet Struct
 * @return [0 - 1]
 */
uint8_t isWaterTemperatureAlarmOn(Dataset* dataset);
/*
 * Get SOC Alarm Status
 * @param *dataset 	-> DataSet Struct
 * @return [0 - 1]
 */
uint8_t isSOCAlarmOn(Dataset* dataset);
/*
 * Get Water Temperature Alarm Status
 * @param *dataset 	-> DataSet Struct
 * @return [0 - 1]
 */
uint8_t isTemperatureBatteryAlarmOn(Dataset* dataset);
/*
 * Used to check if there is an Alarm activated:
 * if yes activate timer and flags, otherwise do nothing
 * @param *dataset	-> Dataset Struct
 * @param *timers	-> Timers List Struct
 */
void checkForAlarmActivated(Dataset* dataset, TimersList* timers);
void checkForAlarmActivated2(Dataset* dataset);
/*
 * Used to de-Activate the Alarm flag and check if the current Alarm is still active
 * if yes reactivate timer, otherwise stop timer and unset the flag
 * @param *dataset	-> Dataset Struct
 * @param *timers 	-> Timers List Struct
 */
void checkForAlarmDeActivated(Dataset* dataset, TimersList* timers);
void checkForAlarmDeActivated2(Dataset* dataset);
/*
 * Used to check if there is an Alarm activated:
 * if yes activate timer and flags, otherwise do nothing
 * @param *dataset	-> Dataset Struct
 * @param *timers	-> Timers List Struct
 */
void checkForNotificationActivated(Dataset* dataset, TimersList* timers);
void checkForNotificationActivated2(Dataset* dataset);
/*
 * Used to de-Activate the Alarm flag and check if the current Alarm is still active
 * if yes reactivate timer, otherwise stop timer and unset the flag
 * @param *dataset	-> Dataset Struct
 * @param *timers 	-> Timers List Struct
 */
void checkForNotificationDeActivated(Dataset* dataset, TimersList* timers);
void checkForNotificationDeActivated2(Dataset* dataset);

#ifdef __cplusplus
}
#endif

#endif /* DATASET_H */
