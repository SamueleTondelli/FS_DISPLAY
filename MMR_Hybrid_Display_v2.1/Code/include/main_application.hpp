#pragma once

#include "data.hpp"
#include "alarms.hpp"
#include "popup_handler.hpp"

#define mainApp MainApplication::instance

// pilot's inputs listeners
class AckBtnLisener : public IDataLisener
{
public:
	AckBtnLisener();
	virtual void onChange(float oldValue, float newValue);
};

class IncrementBtnListener : public IDataLisener
{
public:
	IncrementBtnListener();
	virtual void onChange(float oldValue, float newValue);
};

class DecrementBtnListener : public IDataLisener
{
public:
	DecrementBtnListener();
	virtual void onChange(float oldValue, float newValue);
};

class RadioBtnListener : public IDataLisener
{
public:
	RadioBtnListener();
	virtual void onChange(float oldValue, float newValue);
};

class MarkBtnListener : public IDataLisener
{
public:
	MarkBtnListener();
	virtual void onChange(float oldValue, float newValue);
};

class Special1BtnListener: public IDataLisener
{
public:
	Special1BtnListener();
	virtual void onChange(float oldValue, float newValue);
};

class Special2BtnListener : public IDataLisener
{
public:
	Special2BtnListener();
	virtual void onChange(float oldValue, float newValue);
};

class MapListener : public IDataLisener
{
public:
	MapListener();
	virtual void onChange(float oldValue, float newValue);
};

struct	DataControls {
public:
	DataControls(DataAlarmHandler* alarmHandler, PopUpHandler* popUpHandler);

	AlarmableData batteryVoltage;
	DataAlarm batteryVoltageAlarm;
	DataAlarmPopUp battVoltPopUp;
	
	Data launchControlStatus;
	Data pedal;
	Data brake;
	Data brakeRear;
	ObservableData ackBtn;
	AckBtnLisener ackListener;
	ObservableData incrementBtn;
	IncrementBtnListener incListener;
	ObservableData decrementBtn;
	DecrementBtnListener decListener;
	ObservableData radioBtn;
	RadioBtnListener radioListener;
	ObservableData markBtn;
	MarkBtnListener markListener;
	ObservableData special1Btn;
	Special1BtnListener sp1Listener;
	ObservableData special2Btn;
	Special2BtnListener sp2Listener;
	Data tractionControl;
	Data torqueVectoring;
	ObservableData map;
	MapListener mapListener;
	Data steer;
	Data gpsLatitude;
	Data gpsLongitude;
	Data gpsAltitude;

	void updateSteeringWheelControlsTime();
	static const unsigned int STEERING_WHEEL_TIMEOUT = 500; //ms
	bool isSteeringWheelOK();

private:
	unsigned int m_lastUpdateTime;
};

struct DataMechanics {
	DataMechanics();

	Data rpm;
	Data gear;
	Data slip;
	Data speed;
	Data tps;
	Data carHeightFR;
	Data carHeightFL;
	Data carHeightRR;
	Data carHeightRL;
};

struct DataThermalPressure {
	DataThermalPressure(DataAlarmHandler* alarmHandler, PopUpHandler* popUpHandler);
	
	AlarmableData oilPressure;
	DataAlarm oilPAlarm;
	DataAlarmPopUp oilPAlarmPopUp;

	AlarmableData oilTemperature;
	DataAlarm oilTAlarm;
	DataAlarmPopUp oilTAlarmPopUp;
	
	AlarmableData fuelPressure;
	DataAlarm fuelPAlarm;
	DataAlarmPopUp fuelPAlarmPopUp;
	
	AlarmableData fuelTemperature;
	DataAlarm fuelTAlarm;
	DataAlarmPopUp fuelTAlarmPopUp;
	
	AlarmableData airTemperature;
	DataAlarm airTAlarm;
	DataAlarmPopUp airTAlarmPopUp;
	
	AlarmableData waterTemperature;
	DataAlarm waterTAlarm;
	DataAlarmPopUp waterTAlarmPopUp;
};

struct Tyres {
	Tyres();

	Tyre FR;
	Tyre FL;
	Tyre RR;
	Tyre RL;
};

class SteerinWheelBrokenPopUp : public IPopUp {
public:
	SteerinWheelBrokenPopUp();
	virtual void fillTitle(char* titleBuffer, size_t titleSize);
	virtual void fillContent(char* contentBuffer, size_t contentSize);
	virtual void setColor(uint8_t r, uint8_t g, uint8_t b); //not used
	virtual void getBgColor(uint8_t* r, uint8_t* g, uint8_t* b);
	virtual uint8_t getPriority();
	virtual const char* getName();
	virtual void turnOn();
	virtual void turnOff();
	virtual bool isOn();
	virtual void deactivate();
	virtual bool isDeactivated();
	virtual bool isRetained();

private:
	bool m_on;
	bool m_deactivated;
	char m_name[12] = "STEER WHEEL";
	char m_content[10] = "NO INPUTS";
};

class MainApplication {
public:
	MainApplication(const MainApplication&) = delete;
	MainApplication& operator=(const MainApplication&) = delete;

	static MainApplication instance;

	DataAlarmHandler alarmHandler;
	PopUpHandler popUpHandler;
	DAlarmEventDecoder dAlDec;

	DataControls dataControls;
	DataMechanics dataMechanics;
	DataThermalPressure dataThermalPressure;
	Tyres tyres;

	void decodeCAN1Msg(uint16_t id, uint8_t dlc, uint8_t* payload);
	void decodeCAN2Msg(uint16_t id, uint8_t dlc, uint8_t* payload);
	void decodeCAN3Msg(uint16_t id, uint8_t dlc, uint8_t* payload);

	static const uint8_t NUMBER_OF_PAGES = 8;

	uint8_t getCurrentPage();
	void setPage(uint8_t pageIdx);
	bool currentPageChanged();

	// checks if we're still receiveing messages from steering wheel, else it sends an error
	void controlsHandler();

private:
	MainApplication();

	uint8_t m_currentPage;
	bool m_pageChanged; // might have concurrency issues, idk

	SteerinWheelBrokenPopUp m_steerWheelBrokenPopUp;
};
