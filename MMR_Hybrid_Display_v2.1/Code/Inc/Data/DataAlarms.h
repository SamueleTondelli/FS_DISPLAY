#ifndef DATA_ALARMS_H
#define DATA_ALARMS_H

#include "Data/DataConstantAlarms.h"
#include <string.h>

typedef enum {
	DATA,
	STRING
} CONTENT_TYPE;

typedef struct {
	int priority;
	char name[ALARM_NAME_BUFFER_SIZE];
	void* contents;
	CONTENT_TYPE type;
} Alarm;

uint8_t insertAlarmInQueue(Alarm* a);
Alarm extractAlarmFromQueue();
Alarm* peekAlarmFromQueue();
uint8_t isQueueFull(int priority);
uint8_t isQueueEmpty(int priority);
void updateQueue();


#endif	/*DATA_ALARMS_H*/
