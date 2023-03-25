// START
#include "Data/DataPowerUnit.h"
#include "Data/DataConstant.h"
#include "DisplayConstant.h"
// END

void initializeDataPowerUnit(DataPowerUnit* dataPowerUnit) {
	inizializeData(&(dataPowerUnit->rpm), EMPTY_VALUE, RPM_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->gear), EMPTY_VALUE, GEAR_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->oilPressure), EMPTY_VALUE, OIL_PRESSURE_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->oilTemperature), EMPTY_VALUE, OIL_TEMPERATURE_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->coolantTemperatureCV), EMPTY_VALUE, COOLANT_TEMPERATURE_CV_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->vehicleSpeed), EMPTY_VALUE, VEHICLE_SPEED_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->ignitionTiming), EMPTY_VALUE, IGNITION_TIMING_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->fuelPressure), EMPTY_VALUE, FUEL_PRESSURE_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->exhaustLambda), EMPTY_VALUE, EXHAUST_LABDA_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->lambdaTarget), EMPTY_VALUE, LABDA_TARGER_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->ambientTemperature), EMPTY_VALUE, AMBIENT_TEMPERATURE_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->airTemperature), EMPTY_VALUE, AIR_TEMPERATURE_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->map), EMPTY_VALUE, MAP_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->engineChargeTemperature), EMPTY_VALUE, ENGINE_CHARGE_TEMPERATURE_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->inletMainfoldPressure), EMPTY_VALUE, INLET_MAINFOLD_PRESSURE_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->bevelGearTemperature), EMPTY_VALUE, BEVER_GEAR_TEMPERATURE_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->injectedFuelFlow), EMPTY_VALUE, INJECTED_FUEL_FLOW_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->injectedFuelVolume), EMPTY_VALUE, INJECTED_FUEL_VOLUME_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->fuelClosedLoopControlBank1), EMPTY_VALUE, FUEL_CLOSED_LOOP_CONTROL_BANK1_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->fuelUsed), EMPTY_VALUE, FUEL_USED_CONVERSION_FACTOR);
	inizializeData(&(dataPowerUnit->fuelInjectorPrimaryDifferentialPressure), EMPTY_VALUE, FUEL_INJECTOR_PRIMARY_DIFFERENTIAL_PRESSURE_CONVERSION_FACTOR);

	initializeDataStatus(&(dataPowerUnit->engineStateCV));
	dataPowerUnit->engineStateCV.statusDef[0] = "Search";	//TODO Controllare
	dataPowerUnit->engineStateCV.statusDef[1] = "PatternLock";
	dataPowerUnit->engineStateCV.statusDef[2] = "Error";
	dataPowerUnit->engineStateCV.statusDef[3] = "NA";
	dataPowerUnit->engineStateCV.statusDef[4] = "NA";
	dataPowerUnit->engineStateCV.statusDef[5] = "NA";
	dataPowerUnit->engineStateCV.statusDef[6] = "NA";
	dataPowerUnit->engineStateCV.statusDef[7] = "NA";
	dataPowerUnit->engineStateCV.statusDef[8] = "NA";
	dataPowerUnit->engineStateCV.statusDef[9] = "NA";
	dataPowerUnit->engineStateCV.statusDef[10] = "Stall";
	dataPowerUnit->engineStateCV.statusDefLength = 11;
	
	initializeDataStatus(&(dataPowerUnit->idleStateCV));
	dataPowerUnit->idleStateCV.statusDef[0] = "Disabled";
	dataPowerUnit->idleStateCV.statusDef[1] = "Enabled";
	dataPowerUnit->idleStateCV.statusDef[2] = "ActuatorTest";
	dataPowerUnit->idleStateCV.statusDefLength = 3;
}

void setFlagNotUpdatedDataPowerUnit(DataPowerUnit* dataPowerUnit) {
	setNotUpdateData(&(dataPowerUnit->rpm));
	setNotUpdateData(&(dataPowerUnit->gear));
	setNotUpdateData(&(dataPowerUnit->oilPressure));
	setNotUpdateData(&(dataPowerUnit->oilTemperature));
	setNotUpdateData(&(dataPowerUnit->coolantTemperatureCV));
	setNotUpdateData(&(dataPowerUnit->vehicleSpeed));
	setNotUpdateData(&(dataPowerUnit->ignitionTiming));
	setNotUpdateData(&(dataPowerUnit->fuelPressure));
	setNotUpdateData(&(dataPowerUnit->exhaustLambda));
	setNotUpdateData(&(dataPowerUnit->lambdaTarget));
	setNotUpdateData(&(dataPowerUnit->ambientTemperature));
	setNotUpdateData(&(dataPowerUnit->airTemperature));
	setNotUpdateData(&(dataPowerUnit->map));
	setNotUpdateData(&(dataPowerUnit->engineChargeTemperature));
	setNotUpdateData(&(dataPowerUnit->inletMainfoldPressure));
	setNotUpdateData(&(dataPowerUnit->bevelGearTemperature));
	setNotUpdateData(&(dataPowerUnit->injectedFuelFlow));
	setNotUpdateData(&(dataPowerUnit->injectedFuelVolume));
	setNotUpdateData(&(dataPowerUnit->fuelClosedLoopControlBank1));
	setNotUpdateData(&(dataPowerUnit->fuelUsed));
	setNotUpdateData(&(dataPowerUnit->fuelInjectorPrimaryDifferentialPressure));
}
