#ifndef INC_DATA_DATATHERMALPRESSURE_H_
#define INC_DATA_DATATHERMALPRESSURE_H_

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

#ifdef __cplusplus
}
#endif

#endif /* INC_DATA_DATATHERMALPRESSURE_H_ */
