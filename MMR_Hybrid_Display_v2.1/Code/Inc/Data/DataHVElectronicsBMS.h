#include "Data.h"
#ifndef DATA_HV_ELECTRONICS_BMS_H
#define DATA_HV_ELECTRONICS_BMS_H

#ifdef __cplusplus
extern "C" {
#endif

// START
#include "Data.h"
// END

/*
 *	DataHVElectronicsBMS Struct (Store data about BMS)
 *	@attr delta					-> Current voltage difference between the more charged battery and the less charged
 *	@attr deltaMax				-> Highest Delta value reached since ECU is on
 *	@attr soc					-> State Of Charge
 *	@attr soh					-> State Of Health
 *	@attr ampereBatteryHV		-> Battery Current
 *	@attr ampereBatteryHVmax	-> Maximum value of Battery Current reached
 *	@attr voltageBatteryHV		-> Battery Voltage
 *	@attr batteryTMH			-> Battery Temperature Most High
 *	@attr batteryTML			-> Battery Temperature Most Low
 */
typedef struct {
	Data delta;
	Data deltaMax;
	Data soc;
	Data soh;
	Data ampereBatteryHV;
	Data ampereBatteryHVmax;
	Data voltageBatteryHV;
	Data batteryTMH;
	Data batteryTML;
} DataHVElectronicsBMS;
/*
 * Initialize DataHVElectronicsBMS Struct
 * @param *dataHVElectronicsBMS 		-> DataHVElectronicsBMS Struct
*/
void initializeDataHVElectronicsBMS(DataHVElectronicsBMS* dataHVElectronicsBMS);
/*
 * Unset Flag Updated to All Datas include in this Dataset
 * @param *dataHVElectronicsBMS 		-> DataHVElectronicsBMS Struct
 */
void setFlagNotUpdatedDataHVElectronicsBMS(DataHVElectronicsBMS* dataHVElectronicsBMS);

#ifdef __cplusplus
}
#endif

#endif /* DATA_HV_ELECTRONICS_BMS_H */
