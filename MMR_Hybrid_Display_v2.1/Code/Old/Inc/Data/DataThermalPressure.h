#ifndef DATATHERMALPRESSURE_H_
#define DATATHERMALPRESSURE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "Data.h"

/*
 * DataThermalPressure Struct (Stores data about temperature and pressure)
 * @attr oilPressure
 * @attr oilTemperature
 * @attr fuelPressure
 * @attr fuelTemperature
 * @attr airTemperature
 * @attr waterTemperature
 */
typedef struct {
	Data oilPressure;
	Data oilTemperature;
	Data fuelPressure;
	Data fuelTemperature;
	Data airTemperature;
	Data waterTemperature;
} DataThermalPressure;

/*
 * Initialize DataThermalPressure Struct
 * @param dataThermalPressure	-> DataThermalPressure Struct
 */
void initializeDataThermalPressure(DataThermalPressure* dataThermalPressure);

/*
 * Unset Flag Updated to All Datas include in this Dataset
 * @param dataThermalPressure	-> DataThermalPressure Struct
 */
void setFlagNotUpdatedDataThermalPressure(DataThermalPressure* dataThermalPressure);

#ifdef __cplusplus
}
#endif

#endif /* DATATHERMALPRESSURE_H_ */
