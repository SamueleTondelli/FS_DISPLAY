// START
#include "Data/DataDynamics.h"
#include "Data/DataConstant.h"
#include "DisplayConstant.h"
// END

void initializeDataDynamics(DataDynamics* dataDynamics) {
	initializeData(&(dataDynamics->brakePressureFront), EMPTY_VALUE, BRAKE_PRESSURE_FRONT_CONVERSION_FACTOR);
	initializeData(&(dataDynamics->brakePressureRear), EMPTY_VALUE, BRAKE_PRESSURE_REAR_CONVERSION_FACTOR);
	initializeData(&(dataDynamics->accelerometerX), EMPTY_VALUE, ACCELEROMETER_X_CONVERSION_FACTOR);
	initializeData(&(dataDynamics->accelerometerY), EMPTY_VALUE, ACCELEROMETER_Y_CONVERSION_FACTOR);
	initializeData(&(dataDynamics->wheelSpeedFrontRight), EMPTY_VALUE, WHEEL_SPEED_FRONT_RIGHT_CONVERSION_FACTOR);
	initializeData(&(dataDynamics->wheelSpeedFrontLeft), EMPTY_VALUE, WHEEL_SPEED_FRONT_LEFT_CONVERSION_FACTOR);
	initializeData(&(dataDynamics->wheelSpeedRearRight), EMPTY_VALUE, WHEEL_SPEED_REAR_RIGHT_CONVERSION_FACTOR);
	initializeData(&(dataDynamics->wheelSpeedRearleft), EMPTY_VALUE, WHEEL_SPEED_REAR_LEFT_CONVERSION_FACTOR);
	initializeData(&(dataDynamics->suspensionHeightFrontRight), EMPTY_VALUE, SUSPENSION_HEIGHT_FRONT_RIGHT_CONVERSION_FACTOR);
	initializeData(&(dataDynamics->suspensionHeightFrontLeft), EMPTY_VALUE, SUSPENSION_HEIGHT_FRONT_LEFT_CONVERSION_FACTOR);
	initializeData(&(dataDynamics->suspensionHeightRearRight), EMPTY_VALUE, SUSPENSION_HEIGHT_REAR_RIGHT_CONVERSION_FACTOR);
	initializeData(&(dataDynamics->suspensionHeightRearLeft), EMPTY_VALUE, SUSPENSION_HEIGHT_REAR_LEFT_CONVERSION_FACTOR);
	initializeData(&(dataDynamics->motecGpsLatitude), EMPTY_VALUE, MOTEC_GPS_LATITUDE_CONVERSION_FACTOR);
	initializeData(&(dataDynamics->motecGpsLongitude), EMPTY_VALUE, MOTEC_GPS_LONGITUDE_CONVERSION_FACTOR);
	initializeData(&(dataDynamics->motecGpsTrueCourse), EMPTY_VALUE, MOTEC_GPS_TRUE_COURSE__CONVERSION_FACTOR);
	initializeData(&(dataDynamics->gpsSpeed), EMPTY_VALUE, GPS_SPEED_CONVERSION_FACTOR);
	initializeData(&(dataDynamics->steeringAngle), EMPTY_VALUE, STEERING_ANGLE_CONVERSION_FACTOR);
}

void setFlagNotUpdatedDataDynamics(DataDynamics* dataDynamics) {
	setNotUpdateData(&(dataDynamics->brakePressureFront));
	setNotUpdateData(&(dataDynamics->brakePressureRear));
	setNotUpdateData(&(dataDynamics->accelerometerX));
	setNotUpdateData(&(dataDynamics->accelerometerY));
	setNotUpdateData(&(dataDynamics->wheelSpeedFrontRight));
	setNotUpdateData(&(dataDynamics->wheelSpeedFrontLeft));
	setNotUpdateData(&(dataDynamics->wheelSpeedRearRight));
	setNotUpdateData(&(dataDynamics->wheelSpeedRearleft));
	setNotUpdateData(&(dataDynamics->suspensionHeightFrontRight));
	setNotUpdateData(&(dataDynamics->suspensionHeightFrontLeft));
	setNotUpdateData(&(dataDynamics->suspensionHeightRearRight));
	setNotUpdateData(&(dataDynamics->suspensionHeightRearLeft));
	setNotUpdateData(&(dataDynamics->motecGpsLatitude));
	setNotUpdateData(&(dataDynamics->motecGpsLongitude));
	setNotUpdateData(&(dataDynamics->motecGpsTrueCourse));
	setNotUpdateData(&(dataDynamics->gpsSpeed));
	setNotUpdateData(&(dataDynamics->steeringAngle));
}
