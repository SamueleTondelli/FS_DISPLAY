#include "Data/DataMechanics.h"
#include "Data/DataConstant.h"
#include "DisplayConstant.h"

void initializeDataMechanics(DataMechanics* dataMechanics) {
	initializeData(&(dataMechanics->rpm), EMPTY_VALUE, RPM_CONVERSION_FACTOR);
	initializeData(&(dataMechanics->gear), EMPTY_VALUE, GEAR_CONVERSION_FACTOR);
	initializeData(&(dataMechanics->slip), EMPTY_VALUE, SLIP_CONVERSION_FACTOR);
	initializeData(&(dataMechanics->speed), EMPTY_VALUE, SPEED_CONVERSION_FACTOR);
	initializeData(&(dataMechanics->tps), EMPTY_VALUE, TPS_CONVERSION_FACTOR);
}

void setFlagNotUpdatedDataMechanics(DataMechanics* dataMechanics) {
	setNotUpdateData(&(dataMechanics->rpm));
	setNotUpdateData(&(dataMechanics->gear));
	setNotUpdateData(&(dataMechanics->slip));
	setNotUpdateData(&(dataMechanics->tps));
	setNotUpdateData(&(dataMechanics->tps));
}
