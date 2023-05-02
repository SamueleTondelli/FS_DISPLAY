#include "Data/DataAlarms.h"

extern Alarm queue[PRIORITIES][ALARMS_PER_PRIORITY];
extern int queueSize[PRIORITIES];

uint8_t insertAlarmInQueue(Alarm* a)
{
	if (!isQueueFull(a->priority))
	{
		memcpy(queue[a->priority] + queueSize[a->priority], a, sizeof(Alarm));
		queueSize[a->priority]++;
		return 1;
	}
	return 0;
}

Alarm extractAlarmFromQueue()
{
	Alarm a;
	a.priority = -1;
	for (int i = 0; i < PRIORITIES; i++)
	{
		if (!isQueueEmpty(i))
		{
			a = queue[i][0];
			for (int j = 1; j < queueSize[i]; j++)
			{
				queue[i][j - 1] = queue[i][j];
			}
			queueSize[i]--;
			updateQueue();
			break;
		}
	}
	return a;
}

Alarm* peekAlarmFromQueue()
{
	for (int i = 0; i < PRIORITIES; i++)
	{
		if (!isQueueEmpty(i))
		{
			return &queue[i][0];
		}
	}
	return NULL;
}

uint8_t isQueueFull(int priority)
{
	return queueSize[priority] >= ALARMS_PER_PRIORITY;
}

uint8_t isQueueEmpty(int priority)
{
	return queueSize[priority] == 0;
}

void updateQueue()
{
	for (int i = 1; i < PRIORITIES; i++)
	{
		if (!isQueueEmpty(i) && !isQueueFull(i-1))
		{
			queue[i - 1][queueSize[i - 1]] = queue[i][0];
			queueSize[i - 1]++;
			for (int j = 1; j < queueSize[i]; j++)
			{
				queue[i][j - 1] = queue[i][j];
			}
			queueSize[i]--;
		}
	}
}
