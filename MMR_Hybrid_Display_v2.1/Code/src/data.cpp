#include "../include/data.hpp"
#include "../include/alarms.hpp"

#include <string.h>

/*Data Section*/

Data::Data(float gain, float offset) : m_gain(gain), m_offset(offset), m_value(EMPTY_VALUE) {}

void Data::setValue(float value)
{
	m_value = value * m_gain + m_offset;
}

float Data::getValue()
{
	return m_value;
}

/*ObservableData Section*/

ObservableData::ObservableData(float gain, float offset, float startingValue) :ObservableData(gain, offset, startingValue, NULL) {}

ObservableData::ObservableData(float gain, float offset, float startingValue, IDataLisener* listener) :Data(gain, offset), m_listener(listener) 
{
	m_value = startingValue;
}

void ObservableData::setListener(IDataLisener* listener)
{
	m_listener = listener;
}

void ObservableData::setValue(float value)
{
	float oldValue = m_value;
	m_value = value * m_gain + m_offset;
	if (m_value != oldValue) m_listener->onChange(oldValue, m_value);
}

/*AlarmableData Section*/

AlarmableData::AlarmableData(float gain, float offset, float max, float min) :Data(gain, offset), m_max(max), m_min(min), m_alarm(NULL) {}

void AlarmableData::setValue(float value)
{
	m_value = value * m_gain + m_offset;

	checkCriticality() != CRITICALITY::NORMAL ? turnAlarmOn() : turnAlarmOff();
}

CRITICALITY AlarmableData::checkCriticality()
{
	if (m_value > m_max) return CRITICALITY::HIGH;
	if (m_value >= m_min) return CRITICALITY::NORMAL;
	return CRITICALITY::LOW;
}

void AlarmableData::bindAlarm(DataAlarm* alarm)
{
	m_alarm = alarm;
}

void AlarmableData::turnAlarmOn()
{
	if (m_alarm != NULL)
	{
		m_alarm->turnOn(true);
	}
}

void AlarmableData::turnAlarmOff()
{
	if (m_alarm != NULL)
	{
		m_alarm->turnOff(true);
	}
}

/* Tyre Section */

Tyre::Tyre() :m_temp(1, 0), m_tempSectorsUpdated(0) {
	for (int i = 0; i < 16; i++) {
		m_tempSectors[i] = EMPTY_VALUE;
	}
}

void Tyre::updateTyreTemp(int8_t* sectors0To7, int8_t* sectors8To15) {
	if (sectors0To7 != NULL) {
		setFirst8Sectors(sectors0To7);
	}

	if (sectors8To15 != NULL) {
		setLast8Sectors(sectors8To15);
	}

	if (m_tempSectorsUpdated == 0xFFFF) {
		m_tempSectorsUpdated = 0;
		float temp = 0;
		for (int i = 0; i < 16; i++) {
			temp += m_tempSectors[i];
		}
		m_temp.setValue(temp / 16);
	}
}

Data* Tyre::getTempData() {
	return &m_temp;
}

void Tyre::setFirst8Sectors(int8_t* sectors0To7) {
	memcpy(m_tempSectors, sectors0To7, 8);
	m_tempSectorsUpdated |= 0x00FF;
}

void Tyre::setLast8Sectors(int8_t* sectors8To15) {
	memcpy(m_tempSectors + 8, sectors8To15, 8);
	m_tempSectorsUpdated |= 0xFF00;
}
