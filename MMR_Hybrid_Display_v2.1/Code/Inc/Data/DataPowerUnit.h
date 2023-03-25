#ifndef DATA_POWER_UNIT_H
#define DATA_POWER_UNIT_H

#ifdef __cplusplus
extern "C" {
#endif

// START
#include "Data.h"
#include "DataStatus.h"
// END

/*
 *	DataPowerUnit Struct (Store data about Power Unit Division)
 *	@attr engineStateCV;
 * 
 *	@attr rpm;
 *	@attr gear;
 *	@attr oilPressure;
 *	@attr oilTemperature;
 * 
 *	@attr idleStateCV;
 * 
 *	@attr coolantTemperatureCV;
 *	@attr vehicleSpeed;
 *	@attr ignitionTiming;
 *	@attr fuelPressure;
 *	@attr exhaustLambda;
 *	@attr lambdaTarget;
 *	@attr ambientTemperature;
 *	@attr airTemperature;
 *	@attr map;
 *	@attr engineChargeTemperature;
 *	@attr inletMainfoldPressure;
 *	@attr bevelGearTemperature;
 *	@attr injectedFuelFlow;
 *	@attr injectedFuelVolume;
 *	@attr fuelClosedLoopControlBank1;
 *	@attr fuelUsed;
 *	@attr fuelInjectorPrimaryDifferentialPressure;
 */
typedef struct {

	DataStatus engineStateCV;
	Data rpm;
	Data gear;
	Data oilPressure;
	Data oilTemperature;
	DataStatus idleStateCV;
	Data coolantTemperatureCV;
	Data vehicleSpeed;
	Data ignitionTiming;
	Data fuelPressure;
	Data exhaustLambda;
	Data lambdaTarget;
	Data ambientTemperature;
	Data airTemperature;
	Data map;
	Data engineChargeTemperature;
	Data inletMainfoldPressure;
	Data bevelGearTemperature;
	Data injectedFuelFlow;
	Data injectedFuelVolume;
	Data fuelClosedLoopControlBank1;
	Data fuelUsed;
	Data fuelInjectorPrimaryDifferentialPressure;

} DataPowerUnit;
/*
* Initialize DataPowerUnit Struct
* @param *dataPowerUnit 		-> DataPowerUnit Struct
*/
void initializeDataPowerUnit(DataPowerUnit* dataPowerUnit);
/*
 * Unset Flag Updated to All Datas include in this Dataset
 * @param *dataPowerUnit 		-> DataPowerUnit Struct
 */
void setFlagNotUpdatedDataPowerUnit(DataPowerUnit* dataPowerUnit);

#ifdef __cplusplus
}
#endif

#endif /* DATA_POWER_UNIT_H */
