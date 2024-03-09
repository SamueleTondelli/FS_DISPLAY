#pragma once

#include "data.hpp"
#include "ps_code.hpp"

#define DATA_ALARM_VECTOR_SIZE 64
#define MAX_DALARM_LISTENERS 8
#define ALARM_NAME_LENGTH 11
#define ALARM_EVENTS_QUEUE_LENGTH 30

class DataAlarmHandler;

class DataAlarm
{
public:
	DataAlarm(AlarmableData* data, uint8_t priority, DataAlarmHandler* handler, const char* alarmName);

	void turnOn(bool fromISR);
	void turnOff(bool fromISR);
	bool isOn();
	uint8_t getPriority();
	AlarmableData* getData();
	const char* getName();

private:
	bool m_on;
	AlarmableData* m_data;
	uint8_t m_priority;
	DataAlarmHandler* m_handler;
	char m_alarmName[ALARM_NAME_LENGTH];
};

enum class ALARM_EVENT_TYPE : uint8_t
{
	TURNED_ON,
	TURNED_OFF
};

struct DAlarmEvent {
	DAlarmEvent();
	DAlarmEvent(DataAlarm* alarm, ALARM_EVENT_TYPE eventType);
	DataAlarm* alarm;
	ALARM_EVENT_TYPE eventType;
};

class IDataAlarmEventListener
{
public:
	virtual void onTurnOn(DataAlarm* alarm) = 0;
	virtual void onTurnOff(DataAlarm* alarm) = 0;
};

class DataAlarmHandler
{
public:
	DataAlarmHandler();

	bool pushAlarm(DataAlarm* alarm);
	DataAlarm* getLastAlarm();
	DataAlarm* getAlarmAt(size_t pos);
	bool isAlarmVectorFull();
	void processAlarmEvent(DAlarmEvent alarmEvent, bool fromISR);
	bool pushListener(IDataAlarmEventListener* listener);
	bool isListenerVectorFull();
	const DataAlarm** getAlarmVector(size_t* size);
	void handlerTask();

private:
	XQueueWrapper m_alarmEventsQueue;
	DataAlarm* m_alarmVector[DATA_ALARM_VECTOR_SIZE];
	size_t m_alarmVectorSize;
	IDataAlarmEventListener* m_listenersVector[MAX_DALARM_LISTENERS];
	size_t m_listenersVectorSize;
};
