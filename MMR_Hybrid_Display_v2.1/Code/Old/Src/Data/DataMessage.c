#include "Data/DataMessage.h"

#include <string.h>

void setMessage(DataMessage* dataMessage, char message[9])
{
	strcpy(dataMessage->message, message);
}

void setPriority(DataMessage* dataMessage, int priority)
{
	dataMessage->priority = priority;
}

char* getMessage(DataMessage* dataMessage)
{
	return dataMessage->message;
}

int getPriority(DataMessage* dataMessage)
{
	return dataMessage->priority;
}
