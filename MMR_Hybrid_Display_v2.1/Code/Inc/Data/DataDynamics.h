#ifndef DATA_VEHICLE_DYNAMICS_H
#define DATA_VEHICLE_DYNAMICS_H

#ifdef __cplusplus
extern "C" {
#endif

// START
#include "Data.h"
// END

/*
 *	DataDynamics Struct (Store data about Dynamics Division)
 *	@attr brakePressureFront
 *	@attr brakePressureRear
 *	@attr accelerometerX
 *	@attr accelerometerY
 *	@attr wheelSpeedFrontRight
 *	@attr wheelSpeedFrontLeft
 *	@attr wheelSpeedRearRight
 *	@attr wheelSpeedRearleft
 *	@attr suspensionHeightFrontRight
 *	@attr suspensionHeightFrontLeft
 *	@attr suspensionHeightRearRight
 *	@attr suspensionHeightRearLeft
 *	@attr motecGpsLatitude
 *	@attr motecGpsLongitude
 *	@attr motecGpsTrueCourse
 *	@attr gpsSpeed
 *	@attr steeringAngle
 */
typedef struct {
	Data brakePressureFront;
	Data brakePressureRear;
	Data accelerometerX;
	Data accelerometerY;
	Data wheelSpeedFrontRight;
	Data wheelSpeedFrontLeft;
	Data wheelSpeedRearRight;
	Data wheelSpeedRearleft;
	Data suspensionHeightFrontRight;
	Data suspensionHeightFrontLeft;
	Data suspensionHeightRearRight;
	Data suspensionHeightRearLeft;
	Data motecGpsLatitude;				//TODO Controllare se il gps sta in un float
	Data motecGpsLongitude;
	Data motecGpsTrueCourse;
	Data gpsSpeed;
	Data steeringAngle;
} DataDynamics;
/*
 * Initialize DataDynamics Struct
 * @param *dataDynamics 		-> DataDynamics Struct
 */
void initializeDataDynamics(DataDynamics* dataDynamics);
/*
 * Unset Flag Updated to All Datas include in this Dataset
 * @param *dataDynamics			-> DataDynamics Struct
 */
void setFlagNotUpdatedDataDynamics(DataDynamics* dataDynamics);

#ifdef __cplusplus
}
#endif

#endif /* DATA_VEHICLE_DYNAMICS_H */
