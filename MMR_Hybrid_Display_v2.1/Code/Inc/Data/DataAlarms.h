#ifndef DATA_ALARMS_H
#define DATA_ALARMS_H

#include "Data/DataConstantAlarms.h"
#include <string.h>
#include <stdint.h>
#include <touchgfx/Unicode.hpp>

typedef enum {
	OFF_QUEUE,
	ON,
	DEACTIVATED
} ALARM_STATUS;

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

void deactivateAlarm(Alarm* alarm);
ALARM_STATUS getAlarmStatus(Alarm* alarm);

#endif	/*DATA_ALARMS_H*/
