#include "../include/alarms.hpp"

#include <string.h>

/* Utils section */

static void safeStringCopy(const char* src, char* dst, size_t dstSize)
{
	size_t cpySize = strlen(src) < (dstSize - 1) ? strlen(src) : dstSize - 1;
	memcpy(dst, src, cpySize);
	dst[cpySize] = 0;
}

/*DataAlarm Section*/

DataAlarm::DataAlarm(AlarmableData* data, uint8_t priority, DataAlarmHandler* handler, const char* alarmName) :m_on(false), m_data(data), m_priority(priority), m_handler(handler) {
	safeStringCopy(alarmName, m_alarmName, ALARM_NAME_LENGTH);
}

void DataAlarm::turnOn(bool fromISR)
{
	if (m_on) return;
	m_on = true;
	m_handler->processAlarmEvent(DAlarmEvent(this, ALARM_EVENT_TYPE::TURNED_ON), fromISR);
}

void DataAlarm::turnOff(bool fromISR)
{
	if (!m_on) return;
	m_on = false;
	m_handler->processAlarmEvent(DAlarmEvent(this, ALARM_EVENT_TYPE::TURNED_OFF), fromISR);
}

bool DataAlarm::isOn()
{
	return m_on;
}

uint8_t DataAlarm::getPriority()
{
	return m_priority;
}

AlarmableData* DataAlarm::getData()
{
	return m_data;
}

const char* DataAlarm::getName() {
	return m_alarmName;
}

/*DAlarmEvent Section*/
DAlarmEvent::DAlarmEvent() {}
DAlarmEvent::DAlarmEvent(DataAlarm* alarm, ALARM_EVENT_TYPE eventType) :alarm(alarm), eventType(eventType) {}

/*DataAlarmHandler Section*/

DataAlarmHandler::DataAlarmHandler() :m_alarmVector(), m_alarmVectorSize(0), m_listenersVector(), m_listenersVectorSize(0), m_alarmEventsQueue(ALARM_EVENTS_QUEUE_LENGTH, sizeof(DAlarmEvent)) {}

bool DataAlarmHandler::pushAlarm(DataAlarm* alarm)
{
	if (!isAlarmVectorFull()) return false;
	m_alarmVector[m_alarmVectorSize] = alarm;
	m_alarmVectorSize++;
	return true;
}

DataAlarm* DataAlarmHandler::getLastAlarm()
{
	if (m_alarmVectorSize == 0) return NULL;
	return m_alarmVector[m_alarmVectorSize - 1];
}

DataAlarm* DataAlarmHandler::getAlarmAt(size_t pos)
{
	if (pos >= m_alarmVectorSize) return NULL;
	return m_alarmVector[pos];
}

bool DataAlarmHandler::isAlarmVectorFull()
{
	return m_alarmVectorSize >= DATA_ALARM_VECTOR_SIZE;
}

void DataAlarmHandler::processAlarmEvent(DAlarmEvent alarmEvent, bool fromISR)
{
	fromISR ? m_alarmEventsQueue.pushBackFromISR(&alarmEvent) : m_alarmEventsQueue.pushBack(&alarmEvent);
}

bool DataAlarmHandler::pushListener(IDataAlarmEventListener* listener)
{
	if (isListenerVectorFull()) return false;
	m_listenersVector[m_listenersVectorSize] = listener;
	m_listenersVectorSize++;
	return true;
}

bool DataAlarmHandler::isListenerVectorFull()
{
	return m_listenersVectorSize >= MAX_DALARM_LISTENERS;
}

const DataAlarm** DataAlarmHandler::getAlarmVector(size_t* size)
{
	*size = m_alarmVectorSize;
	return (const DataAlarm**)m_alarmVector;
}

void DataAlarmHandler::handlerTask() {
	DAlarmEvent e;
	while (1) {
		if (m_alarmEventsQueue.receive(&e)) {
			if (e.eventType == ALARM_EVENT_TYPE::TURNED_ON) {
				for (auto i = 0; i < m_listenersVectorSize; i++) {
					m_listenersVector[i]->onTurnOn(e.alarm);
				}
			}
			else {
				for (auto i = 0; i < m_listenersVectorSize; i++) {
					m_listenersVector[i]->onTurnOff(e.alarm);
				}
			}
			
		}
	}
}