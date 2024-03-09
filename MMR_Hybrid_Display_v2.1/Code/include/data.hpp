#pragma once

#include <stdint.h>

#define EMPTY_VALUE -1

class Data
{
public:
	Data(float gain, float offset);

	void setValue(float value);
	float getValue();

protected:
	float m_value;
	float m_gain;
	float m_offset;
};

class IDataLisener
{
public:
	virtual void onChange(float oldValue, float newValue) = 0;
};

class ObservableData : public Data
{
public:
	ObservableData(float gain, float offset, float startingValue);
	ObservableData(float gain, float offset, float startingValue, IDataLisener* listener);

	void setListener(IDataLisener* listener);

	void setValue(float value);

private:
	IDataLisener* m_listener;
};

class DataAlarm;


enum class CRITICALITY {
	LOW,
	NORMAL,
	HIGH
};

class AlarmableData : public Data
{
public:
	AlarmableData(float gain, float offset, float max, float min);

	void setValue(float value);
	CRITICALITY checkCriticality();

	void bindAlarm(DataAlarm* alarm);

private:
	DataAlarm* m_alarm;
	float m_max;
	float m_min;

	void turnAlarmOn();
	void turnAlarmOff();
};

class Tyre {
public:
	Tyre();
	void updateTyreTemp(int8_t* sectors0To7, int8_t* sectors8To15);
	Data* getTempData();

private:
	Data m_temp;
	int8_t m_tempSectors[16];
	uint16_t m_tempSectorsUpdated; //every bit corresponds to a sector, if it's 1 then it's updated

	void setFirst8Sectors(int8_t* sectors0To7);
	void setLast8Sectors(int8_t* sectors8To15);
};