#ifndef DATA_MESSAGES_ERRORS_H
#define DATA_MESSAGES_ERRORS_H

#ifdef __cplusplus
extern "C" {
#endif

// START
#include "DataNotification.h"
#include "DataStatus.h"
#include "DataLapTime.h"
#include "string.h"
// END

#define DRIVER_MESSAGE_READY 1
#define DRIVER_MESSAGE_NOT_READY 0

#define DRIVER_MESSAGE_DRIVER_TYPE 				"Driver"
#define DRIVER_MESSAGE_DRIVER_TYPE_LENGTH 		6
#define DRIVER_MESSAGE_WARNING_TYPE 			"Warning"
#define DRIVER_MESSAGE_WARNING_TYPE_LENGTH		7
#define DRIVER_MESSAGE_ALARM_TYPE 				"Alarm"
#define DRIVER_MESSAGE_ALARM_TYPE_LENGTH 		5

/*
 *	DataMessagesErrors Struct (Store data about other devices)
 *	@attr pressureOilAlarm
 *	@attr oilTemperatureAlarm
 *	@attr waterTemperatureAlarm
 *	@attr warningSource
 *	@attr displayMode
 * 
 *	@attr driverMessageType
 *	@attr driverMessage
 * 
 *	@attr lapTime
 *	@attr bestLapTime
 */
typedef struct {
	DataStatus pressureOilAlarm;
	DataStatus oilTemperatureAlarm;
	DataStatus waterTemperatureAlarm;
	DataStatus socAlarm;
	DataStatus tempBatteryAlarm;

	DataStatus warningSource;		// TODO Controllare se implementare o meno

	DataNotification driverMessage;

	DataLapTime lapTime;
	DataLapTime bestLapTime;
} DataMessagesErrors;
/*
 * Initialize DataMessagesErrors Struct
 * @param *dataMessagesErrors 		-> DataMessagesErrors Struct
 */
void initializeDataMessagesErrors(DataMessagesErrors* dataMessagesErrors);
/*
 * Check if the current Message is a "Custom" Type
 * @param *dataMessagesErrors 		-> DataMessagesErrors Struct
 * @return [0 or 1]
 */
uint8_t isDataNotificationDriverType(DataMessagesErrors* dataMessagesErrors);
/*
 * Check if the current Message is a "Warning" Type
 * @param *dataMessagesErrors 		-> DataMessagesErrors Struct
 * @return [0 or 1]
 */
uint8_t isDataNotificationWarningType(DataMessagesErrors* dataMessagesErrors);
/*
 * Check if the current Message is a "Alarm" Type
 * @param *dataMessagesErrors 		-> DataMessagesErrors Struct
 * @return [0 or 1]
 */
uint8_t isDataNotificationAlarmType(DataMessagesErrors* dataMessagesErrors);

#ifdef __cplusplus
}
#endif

#endif /* DATA_MESSAGES_ERRORS_H */
