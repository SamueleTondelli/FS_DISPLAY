#ifndef _DATA_MESSAGE_H
#define _DATA_MESSAGE_H

typedef struct {
	char message[9];
	int priority;
} DataMessage;

void setMessage(DataMessage* dataMessage, char message[9]);
void setPriority(DataMessage* dataMessage, int priority);

char* getMessage(DataMessage* dataMessage);
int getPriority(DataMessage* dataMessage);

#endif // _DATA_MESSAGE_H
