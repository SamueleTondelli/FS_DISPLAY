#include "Data/DataMechanics.h"
#include "Data/DataConstant.h"
#include "DisplayConstant.h"

void initializeDataMechanics(DataMechanics* dataMechanics) {
	intializeData(&(dataMechanics->rpm), EMPTY_VALUE, RPM_CONVERSION_FACTOR);
	intializeData(&(dataMechanics->gear), EMPTY_VALUE, GEAR_CONVERSION_FACTOR);
	intializeData(&(dataMechanics->slip), EMPTY_VALUE, SLIP_CONVERSION_FACTOR);
	intializeData(&(dataMechanics->speed), EMPTY_VALUE, SPEED_CONVERSION_FACTOR);
	intializeData(&(dataMechanics->tps), EMPTY_VALUE, TPS_CONVERSION_FACTOR);
}

void setFlagNotUpdatedMechanics(DataMechanics* dataMechanics) {
	setFlagNotUpdated(&(dataMechanics->rpm));
	setFlagNotUpdated(&(dataMechanics->gear));
	setFlagNotUpdated(&(dataMechanics->slip));
	setFlagNotUpdated(&(dataMechanics->tps));
	setFlagNotUpdated(&(dataMechanics->tps));
}
