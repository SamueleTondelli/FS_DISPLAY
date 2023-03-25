#ifndef DATA_NOTIFICATION_H
#define DATA_NOTIFICATION_H

#ifdef __cplusplus
extern "C" {
#endif

// START
#include "main.h"
#include "DataStatus.h"
#include "TimersList.h"
#include "string.h"
// END

#define DATA_NOTIFICATION_TYPE_DEFAULT -1
#define DATA_NOTIFICATION_LENGHT 33
#define DATA_NOTIFICATION_TYPE_DEFINE_LENGHT 5
#define DATA_NOTIFICATION_NUMBER_OF_CAN_MESSAGES 4
#define DATA_NOTIFICATION_CHECK_MESSAGE_READY 0x0F
#define DATA_NOTIFICATION_ERROR_MESSAGE "\nERROR\n"

/*
 * DataNotification Struct (Store messages and messages parameters)
 * @attr notificationType							-> Enumeration Message Type
 * @attr notification[DATA_NOTIFICATION_LENGHT]
 * @attr notificationLength							-> char array length
 * @attr notificationCounter						-> Flag used to check if all CAN messages are arrived and message is complete
 */
typedef struct {
	DataStatus notificationType;
	char notification[DATA_NOTIFICATION_LENGHT];
	uint8_t notificationLength;
	uint8_t notificationCounter;
} DataNotification;
/*
 * Initialize DataNotification Struct
 * @param *dataMessage 		-> DataNotification Struct
 */
void initializeDataNotification(DataNotification* dataNotification);
/*
 * Set Message Type
 * @param *dataMessage 		-> DataNotification Struct
 * @param newType 			-> New Message Type
 */
void setMessageTypeDataNotification(DataNotification* dataNotification, uint8_t newType);
/*
 * Set Message Length
 * @param *dataMessage 		-> DataMessage Struct
 * @param newType 			-> New Message Length
 */
void setMessageLengthDataNotification(DataNotification* dataNotification, uint8_t length);
/*
 * Get Message Length
 * @param *dataMessage 		-> DataMessage Struct
 * @return 					-> Message Length
 */
uint8_t getMessageLengthDataNotification(DataNotification* dataNotification);
/*
 * Load entire Message to data
 * @param *dataMessage 		-> DataMessage Struct
 * @param *message 			-> New Message
 * @param messageLength		-> New Message Length
 * @param startPosition 	-> Message Start Position
 * @param endPosition 		-> Message End Position
 */
void setMessageDataNotification(DataNotification* dataNotification, char* message, uint8_t messageLength, uint8_t startPosition, uint8_t endPosition);
/*
 * Load Message from Data
 * @param *dataMessage 		-> DataMessage Struct
 * @param *payload	 		-> CAN Message Payload
 * @param messageNumber		-> CAN Message Number
 */
void loadDriverMessage(DataNotification* dataNotification, uint8_t* payload, uint8_t messageNumber);
/*
 * Get Message
 * @param *dataMessage 		-> DataMessage Struct
 * @return 					-> char* message
 */
char* getMessageDataNotification(DataNotification* dataNotification);
/*
 * Clean all the Message
 * @param *dataMessage 		-> DataMessage Struct
 */
void cleanDataNotification(DataNotification* dataNotification);
/*
 * Get the status of the Message (if is complete or not)
 * [ each CAN message update the messageCounter if all CAN messages
 *   are arrived the message is classified as complete ]
 * messageCounter = (1111)b -> (0x0F)hex (Complete Message)
 * Can Message 1  = messageCounter | 0X01;
 * Can Message 2  = messageCounter | 0X02;
 * Can Message 3  = messageCounter | 0X04;
 * Can Message 4  = messageCounter | 0X08;
 */
uint8_t isDataNotificationReady(DataNotification* dataNotification);

#ifdef __cplusplus
}
#endif

#endif /* DATA_NOTIFICATION_H */
