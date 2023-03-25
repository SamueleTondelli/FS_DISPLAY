// START
#include "Data/DataNotification.h"
#include "Data/DataStatus.h"
#include "TimersList.h"
#include "TimerHandler.h"
// END

void initializeDataNotification(DataNotification* dataNotification) {
	cleanDataNotification(dataNotification);
	initializeDataStatus(&(dataNotification->notificationType));
}

void setMessageTypeDataNotification(DataNotification* dataNotification, uint8_t newType) {
	uint8_t typeStatusLength = getDataStatusDefLength(&(dataNotification->notificationType));
	if (newType >= 0 && newType < typeStatusLength/*dataNotification->notificationType.statusDefLength*/) {
		setDataStatus(&(dataNotification->notificationType), newType);
	}
}

void setMessageLengthDataNotification(DataNotification* dataNotification, uint8_t length) {
	if (length > 0 && length < DATA_NOTIFICATION_LENGHT) {
		dataNotification->notificationLength = length;
	}
}

uint8_t getMessageLengthDataNotification(DataNotification* dataNotification) {
	return dataNotification->notificationLength;
}

void setMessageDataNotification(DataNotification* dataNotification, char* message, uint8_t messageLength, uint8_t startPosition, uint8_t endPosition) {
	if (messageLength < 0 || messageLength > DATA_NOTIFICATION_LENGHT)
		return;
	if (startPosition < 0 || endPosition >= DATA_NOTIFICATION_LENGHT)
		return;

	for (uint8_t i = startPosition, j = 0; i <= endPosition; i++, j++) {
		dataNotification->notification[i] = message[j];
	}
	dataNotification->notificationLength = messageLength;
	dataNotification->notificationCounter = DATA_NOTIFICATION_CHECK_MESSAGE_READY;
}

void loadDriverMessage(DataNotification* dataNotification, uint8_t* payload, uint8_t messageNumber) {
	
	if (messageNumber < 1 || messageNumber > 4) {
		cleanDataNotification(dataNotification);
		return;
	}
	/*
	 * notificationCounter = (1111)b -> (0x0F)hex (Complete Message)
	 * Can Message 1 = messageCounter | 0X01;
	 * Can Message 2 = messageCounter | 0X02;
	 * Can Message 3 = messageCounter | 0X04;
	 * Can Message 4 = messageCounter | 0X08;
	 */
	uint8_t start = 0, end = 7, pos = 0;
	switch (messageNumber) {
		case(1):
			start = 2;
			pos = 0;

			// Safety Check
			memset(dataNotification->notification, 0, DATA_NOTIFICATION_LENGHT);
			dataNotification->notificationCounter = 0;

			dataNotification->notificationCounter |= 0x01;
			break;
		case(2):
			start = 0;
			pos = 6;
			dataNotification->notificationCounter |= 0x02;
			break;
		case(3):
			start = 0;
			pos = 14;
			dataNotification->notificationCounter |= 0x04;
			break;
		case(4):
			start = 0;
			pos = 22;
			dataNotification->notificationCounter |= 0x08;
			break;
		default:
			return;
	}

	while (start != (end + 1)) {
		dataNotification->notification[pos] = payload[start];
		pos++;
		start++;
	}
}

char* getMessageDataNotification(DataNotification* dataNotification) {
	if (dataNotification->notificationLength > 0 && dataNotification->notificationCounter == DATA_NOTIFICATION_CHECK_MESSAGE_READY) {
		return dataNotification->notification;
	}
	return DATA_NOTIFICATION_ERROR_MESSAGE;
}

void cleanDataNotification(DataNotification* dataNotification) {
	memset(dataNotification->notification, 0, DATA_NOTIFICATION_LENGHT * sizeof(char));
	dataNotification->notificationCounter = 0;
	setDataStatus(&(dataNotification->notificationType), DATA_NOTIFICATION_TYPE_DEFAULT);
}

uint8_t isDataNotificationReady(DataNotification* dataNotification) {
	if (dataNotification->notificationCounter == DATA_NOTIFICATION_CHECK_MESSAGE_READY) {
		if(getDataStatus(&(dataNotification->notificationType)) != DATA_STATUS_ERROR_VALUE) {
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
}
