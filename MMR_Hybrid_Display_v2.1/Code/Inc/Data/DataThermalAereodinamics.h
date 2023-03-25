#ifndef DATA_THERMAL_MANAGEMENT_AERODYNAMICS_H
#define DATA_THERMAL_MANAGEMENT_AERODYNAMICS_H

#ifdef __cplusplus
extern "C" {
#endif

// START
#include "Data.h"
#include "DataStatus.h"
// END

/*
 *	DataThermalAerodynamics Struct (Store data about Thermal Management and Aerodynamics Division)
 *	@attr coolantTemperatureEV;
 *	@attr coolantFan1;
 *	@attr coolantFan1TemperatureLimit;
 *	@attr coolantFan2;
 *	@attr coolantFan2TemperatureLimit;
 * 
 *	@attr coolantFanInputMode;
 *	@attr coolantPumpHVState;
 * 
 *	@attr brakeTemperatureFrontRight;
 *	@attr brakeTemperatureFrontLeft;
 *	@attr brakeTemperatureRearRight;
 *	@attr brakeTemperatureRearLeft;
 *	@attr brakeTermocouple0;
 *	@attr brakeTermocouple1;
 *	@attr brakeTermocouple2;
 *	@attr brakeTermocouple3;
 */
typedef struct {
	Data coolantTemperatureEV;
	Data coolantFan1;
	Data coolantFan1TemperatureLimit;
	Data coolantFan2;
	Data coolantFan2TemperatureLimit;

	DataStatus coolantFanInputMode;
	DataStatus coolantPumpHVState;

	Data brakeTemperatureFrontRight;
	Data brakeTemperatureFrontLeft;
	Data brakeTemperatureRearRight;
	Data brakeTemperatureRearLeft;
	Data brakeTermocouple0;
	Data brakeTermocouple1;
	Data brakeTermocouple2;
	Data brakeTermocouple3;
} DataThermalAerodynamics;
/*
 * Initialize DataThermalAerodynamics Struct
 * @param *dataThermalAerodynamics 		-> DataThermalAerodynamics Struct
 */
void initializeDataThermalAerodynamics(DataThermalAerodynamics* dataThermalAerodynamics);
/*
 * Unset Flag Updated to All Datas include in this Dataset
 * @param *dataThermalAerodynamics 		-> DataThermalAerodynamics Struct
 */
void setFlagNotUpdatedDataThermalAerodynamics(DataThermalAerodynamics* dataThermalAerodynamics);

#ifdef __cplusplus
}
#endif

#endif /* DATA_THERMAL_MANAGEMENT_AERODYNAMICS_H */
