#include "../include/popup_handler.hpp"
#include "../include/dash_utils.hpp"

#include <string.h>
#include <stdio.h>

/* DataAlarmPopUp section */

DataAlarmPopUp::DataAlarmPopUp(DataAlarm* alarm) :m_alarm(alarm), m_priority(alarm->getPriority()), m_r(255), m_g(0), m_b(0), m_on(false), m_deactivated(false), m_deactivationTime(0) {}

void DataAlarmPopUp::setAlarm(DataAlarm* alarm)
{
	m_alarm = alarm;
	m_priority = alarm->getPriority();
}

void DataAlarmPopUp::setColor(uint8_t r, uint8_t g, uint8_t b)
{
	m_r = r;
	m_g = g;
	m_b = b;
}

void DataAlarmPopUp::fillTitle(char* titleBuffer, size_t titleSize)
{
	safeStringCopy(m_alarm->getName(), titleBuffer, titleSize);
}

void DataAlarmPopUp::fillContent(char* contentBuffer, size_t contentSize)
{
	char temp[POPUP_CONTENT_MAX_SIZE];
	sprintf(temp, "%.1f", m_alarm->getData()->getValue());
	safeStringCopy(temp, contentBuffer, contentSize);
}

void DataAlarmPopUp::getBgColor(uint8_t* r, uint8_t* g, uint8_t* b)
{
	*r = m_r;
	*g = m_g;
	*b = m_b;
}

uint8_t DataAlarmPopUp::getPriority()
{
	return m_priority;
}

const char* DataAlarmPopUp::getName()
{
	return m_alarm->getName();
}

void DataAlarmPopUp::turnOn() {
	m_on = true;
}

void DataAlarmPopUp::turnOff() {
	m_on = false;
}

bool DataAlarmPopUp::isOn() {
	return m_on;
}

void DataAlarmPopUp::deactivate() {
	m_deactivated = true;
	m_deactivationTime = millis();
}

bool DataAlarmPopUp::isDeactivated() {
	if (!m_deactivated) {
		return false;
	}

	if (m_deactivated && millis() - m_deactivationTime >= ALARMPOPUP_DEACTIVATION_TIME) {
		m_deactivated = false;
		return false;
	}

	return true;
}

bool DataAlarmPopUp::isRetained() {
	return true;
}

/* PopUpHandler section */

PopUpHandler::PopUpHandler() :m_queue(), m_popUpMap(hashCstr, compCstr), m_currentPopUp(NULL) {}

bool PopUpHandler::push(IPopUp* popUp)
{
	return m_queue.push(popUp);
}

IPopUp* PopUpHandler::peek()
{
	return m_queue.peek();
}

IPopUp* PopUpHandler::pop()
{
	return m_queue.pop();
}

bool PopUpHandler::isQueueFull()
{
	return m_queue.isQueueFull();
}

bool PopUpHandler::registerPopUp(IPopUp* popUp)
{
	return m_popUpMap.add((char*)popUp->getName(), popUp);
}

#define ALARM_TOOHIGH_BGCOL 255, 0, 0
#define ALARM_TOOLOW_BGCOL 0, 0, 255

void PopUpHandler::onDataAlarmTurnedOn(DataAlarm* alarm)
{
	char* name = (char*)alarm->getName();
	auto e = m_popUpMap.get(name);
	if (e == NULL) {
		return;
	}
	IPopUp* popUp = e->getValue();
	if (popUp->isDeactivated()) {
		return;
	}
	if (alarm->getData()->checkCriticality() == CRITICALITY::HIGH) {
		popUp->setColor(ALARM_TOOHIGH_BGCOL);
	}
	else {
		popUp->setColor(ALARM_TOOLOW_BGCOL);
	}
	pushPopUp(popUp);
}

void PopUpHandler::onDataAlarmTurnedOff(DataAlarm* alarm)
{
	char* name = (char*)alarm->getName();
	auto e = m_popUpMap.get(name);
	if (e == NULL) {
		return;
	}
	e->getValue()->turnOff();
}

void PopUpHandler::deactivateCurrentPopUp() {
	if (m_currentPopUp != NULL) m_currentPopUp->deactivate();
}

bool PopUpHandler::canShowPopUp() {
	return m_currentPopUp != NULL || peek() != NULL;
}

IPopUp* PopUpHandler::handleShowingPopUp() {
	IPopUp* retVal = NULL;
	if (!canShowPopUp()) return retVal;

	enum STATE {
		NO_POPUP,
		SHOW_NOTINT,
		SHOW_INT,
		SHOW_BONUST
	};

	static STATE currentState = NO_POPUP;
	static int64_t startingShowTime = -1;

	//times in milliseconds
	const uint32_t NOTINT_TIME = 4000;
	const uint32_t INT_TIME = 60000;
	const uint32_t BONUS_TIME = 7000;

	STATE oldState = currentState;

	switch (currentState)
	{
	case NO_POPUP:
		m_currentPopUp = NULL;
		if (peek() != NULL) {
			swapCurrentPopUp(pop());
			retVal = m_currentPopUp;
			currentState = SHOW_NOTINT;
			startingShowTime = millis();
		}
		break;
	
	case SHOW_NOTINT:
		retVal = m_currentPopUp;
		
		if (!m_currentPopUp->isOn() || m_currentPopUp->isDeactivated()) {
			swapCurrentPopUp(NULL);
			currentState = NO_POPUP;
			break;
		}

		if (millis() - (uint32_t)startingShowTime >= NOTINT_TIME) {
			IPopUp* next = peek();
			if (next == NULL) {
				currentState = SHOW_INT;
				break;
			}
			else if (next->getPriority() <= m_currentPopUp->getPriority()) {
				currentState = SHOW_NOTINT;
				swapCurrentPopUp(pop());
				startingShowTime = millis();
				break;
			}
			else {
				currentState = SHOW_BONUST;
				break;
			}

		}

		break;
	
	case SHOW_INT:
		retVal = m_currentPopUp;
		if (!m_currentPopUp->isOn() || m_currentPopUp->isDeactivated()) {
			swapCurrentPopUp(NULL);
			currentState = NO_POPUP;
			break;
		}

		if (peek() != NULL) {
			currentState = SHOW_NOTINT;
			swapCurrentPopUp(pop());
			startingShowTime = millis();
			break;
		}

		if (millis() - (uint32_t)startingShowTime >= INT_TIME) {
			m_currentPopUp->deactivate();
			swapCurrentPopUp(NULL);
			currentState = NO_POPUP;
			break;
		}

		break;
	
	case SHOW_BONUST:
		retVal = m_currentPopUp;
		if (!m_currentPopUp->isOn() || m_currentPopUp->isDeactivated() || millis() - (uint32_t)startingShowTime >= BONUS_TIME) {
			if (peek() == NULL) { //shouldnt happen, but who knows
				swapCurrentPopUp(NULL);
				startingShowTime = -1;
				currentState = NO_POPUP;
			}
			else {
				swapCurrentPopUp(pop());
				currentState = SHOW_NOTINT;
				startingShowTime = millis();
			}
			break;
		}
		break;
	
	default:
		retVal = NULL;
		break;
	}

	return retVal;
}

bool PopUpHandler::pushPopUp(IPopUp* popUp) {
	if (popUp->isDeactivated() || popUp->isOn()) {
		return false;
	}
	popUp->turnOn();
	return push(popUp);
}

void PopUpHandler::swapCurrentPopUp(IPopUp* next) {
	if (m_currentPopUp != NULL) {
		if (m_currentPopUp->isRetained() && m_currentPopUp->isOn()) {
			push(m_currentPopUp);
		}
		else {
			m_currentPopUp->turnOff();
		}
	}
	m_currentPopUp = next;
}

/* PHandlerDAlarmEventListener section */

DAlarmEventDecoder::DAlarmEventDecoder(PopUpHandler* handler) :m_handler(handler) {}

void DAlarmEventDecoder::onTurnOn(DataAlarm* alarm)
{
	m_handler->onDataAlarmTurnedOn(alarm);
}

void DAlarmEventDecoder::onTurnOff(DataAlarm* alarm)
{
	m_handler->onDataAlarmTurnedOff(alarm);
}
