#pragma once

#include "alarms.hpp"
#include "dash_utils.hpp"

#define POPUP_QUEUE_SIZE 20
#define POPUP_NAME_MAX_SIZE 11
#define POPUP_CONTENT_MAX_SIZE 11
#define ALARMPOPUP_DEACTIVATION_TIME 45000 //ms

class IPopUp
{
public:
	virtual void fillTitle(char* titleBuffer, size_t titleSize) = 0;
	virtual void fillContent(char* contentBuffer, size_t contentSize) = 0;
	virtual void getBgColor(uint8_t* r, uint8_t* g, uint8_t* b) = 0;
	virtual uint8_t getPriority() = 0;
	virtual const char* getName() = 0;
	virtual void setColor(uint8_t r, uint8_t g, uint8_t b) = 0;
	virtual void turnOn() = 0; 
	virtual void turnOff() = 0;
	virtual bool isOn() = 0;
	virtual void deactivate() = 0;
	virtual bool isDeactivated() = 0;
	virtual bool isRetained() = 0; //true if it should be put back in queue after we stop showing it
};

class DataAlarmPopUp : public IPopUp
{
public:
	DataAlarmPopUp(DataAlarm* alarm);

	void setAlarm(DataAlarm* alarm);

	virtual void fillTitle(char* titleBuffer, size_t titleSize);
	virtual void fillContent(char* contentBuffer, size_t contentSize);
	virtual void getBgColor(uint8_t* r, uint8_t* g, uint8_t* b);
	virtual uint8_t getPriority();
	virtual const char* getName();
	virtual void setColor(uint8_t r, uint8_t g, uint8_t b);
	virtual void turnOn();
	virtual void turnOff();
	virtual bool isOn();
	virtual void deactivate();
	virtual bool isDeactivated();
	virtual bool isRetained();

private:
	DataAlarm* m_alarm;
	uint8_t m_priority;
	uint8_t m_r;
	uint8_t m_g;
	uint8_t m_b;
	bool m_on;
	bool m_deactivated;
	unsigned int m_deactivationTime;
};

class PopUpHandler
{
public:
	PopUpHandler();

	bool registerPopUp(IPopUp* popUp);

	void onDataAlarmTurnedOn(DataAlarm* alarm);
	void onDataAlarmTurnedOff(DataAlarm* alarm);

	void deactivateCurrentPopUp();
	bool canShowPopUp();
	IPopUp* handleShowingPopUp();

	bool pushPopUp(IPopUp* popUp);

private:
	TSafeQueue<IPopUp> m_queue;
	HashMap<char*, IPopUp*> m_popUpMap;
	IPopUp* m_currentPopUp;

	bool push(IPopUp* popUp);
	IPopUp* peek();
	IPopUp* pop();
	bool isQueueFull();
	void swapCurrentPopUp(IPopUp* next);
};

class DAlarmEventDecoder : public IDataAlarmEventListener
{
public:
	DAlarmEventDecoder(PopUpHandler* handler);

	virtual void onTurnOn(DataAlarm* alarm);
	virtual void onTurnOff(DataAlarm* alarm);

private:
	PopUpHandler* m_handler;
};