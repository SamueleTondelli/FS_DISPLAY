#ifndef DATA_HV_ELECTRONICS_INVERTER_H
#define DATA_HV_ELECTRONICS_INVERTER_H

#ifdef __cplusplus
extern "C" {
#endif

// START
#include "Data.h"
// END

/*
 *	DataHVElectronicsInverter Struct (Store data about Inverter and Electronic Motor)
 *	@attr vBatLV								->	Voltage Battery Low Voltage
 *	@attr electricMotorSpeed;
 *	@attr electricMotorTorque;
 *	@attr electricMotorTemperature;
 *	@attr DataStatus hybridControlSystemState	//TODO Implementare?
 *	@attr targetID;
 *	@attr targetIQ;
 *	@attr currentID;
 *	@attr currentIQ;
 *	@attr inverterCapacitorVoltage;
 *	@attr inverterTemperature;
 *	@attr inverterBatteryCurrent;
 *	@attr inverterBatteryVoltage;
 *	@attr inverterTorqueMax;
 *	@attr inverterSpeedMax;
 *	@attr batteryDischargeCurrentMax;
 *	@attr batteryChargeCurrentMax;
 *	@attr actualPowerProvidedElectric;
 */
typedef struct {
	Data electricMotorSpeed;
	Data electricMotorTorque;
	Data electricMotorTemperature;
	//DataStatus hybridControlSystemState;	//TODO Implementare?
	Data targetID;
	Data targetIQ;
	Data currentID;
	Data currentIQ;
	Data inverterCapacitorVoltage;
	Data inverterTemperature;
	Data inverterBatteryCurrent;
	Data inverterBatteryVoltage;
	Data inverterTorqueMax;
	Data inverterSpeedMax;
	Data batteryDischargeCurrentMax;
	Data batteryChargeCurrentMax;
	Data actualPowerProvidedElectric;
} DataHVElectronicsInverter;
/*
* Initialize DataHVElectronicsInverter Struct
* @param *dataHVElectronicsInverter 		-> DataHVElectronicsInverter Struct
*/
void initializeDataHVElectronicsInverter(DataHVElectronicsInverter* dataHVElectronicsInverter);
/*
 * Unset Flag Updated to All Datas include in this Dataset
 * @param *dataHVElectronicsInverter 		-> DataHVElectronicsInverter Struct
 */
void setFlagNotUpdatedDataHVElectronicsInverter(DataHVElectronicsInverter* dataHVElectronicsInverter);

#ifdef __cplusplus
}
#endif

#endif /* DATA_HV_ELECTRONICS_INVERTER_H */
