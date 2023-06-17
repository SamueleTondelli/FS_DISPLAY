#ifndef DATA_CONSTANT_THERMAL_PRESSURE_H_
#define DATA_CONSTANT_THERMAL_PRESSURE_H_

#define OIL_PRESSURE_CONVERSION_FACTOR			0.001f
#define OIL_TEMPERATURE_CONVERSION_FACTOR		0.1f
#define FUEL_PRESSURE_CONVERSION_FACTOR			0.001f
#define FUEL_TEMPERATURE_CONVERSION_FACTOR		0.1f
#define AIR_TEMPERATURE_CONVERSION_FACTOR		0.1f
#define WATER_TEMPERATURE_CONVERSION_FACTOR		0.1f

#define OIL_PRESSURE_ALARM_PRIORITY				0
#define OIL_PRESSURE_MAX_VALUE					((float) 5)
#define OIL_PRESSURE_MIN_VALUE					((float) 1)
#define OIL_TEMPERATURE_ALARM_PRIORITY			1
#define OIL_TEMPERATURE_MAX_VALUE				((float) 135)
#define OIL_TEMPERATURE_MIN_VALUE				((float) 70)
#define FUEL_PRESSURE_ALARM_PRIORITY			2
#define FUEL_PRESSURE_MAX_VALUE					((float) 5)
#define FUEL_PRESSURE_MIN_VALUE					((float) 3.5)
#define FUEL_TEMPERATURE_ALARM_PRIORITY			2
#define FUEL_TEMPERATURE_MAX_VALUE				((float) 90)
#define FUEL_TEMPERATURE_MIN_VALUE				((float) 10)
#define AIR_TEMPERATURE_ALARM_PRIORITY			4
#define AIR_TEMPERATURE_MAX_VALUE				((float) 60)
#define AIR_TEMPERATURE_MIN_VALUE				((float) 5)
#define WATER_TEMPERATURE_ALARM_PRIORITY		0
#define WATER_TEMPERATURE_MAX_VALUE				((float)105)
#define WATER_TEMPERATURE_MIN_VALUE				((float) 60)

#endif /* DATA_CONSTANT_THERMAL_PRESSURE_H_ */
