#include "../include/ps_code.hpp"
#include "../include/data_constants.hpp"

#include "adc.h"

Locker::Locker() {
	m_lock = xSemaphoreCreateMutex();
}

void Locker::acquireLock() {
	xSemaphoreTake(m_lock, portMAX_DELAY);
}

void Locker::giveLock() {
	xSemaphoreGive(m_lock);
}

unsigned int millis() {
	return uwTick;
}

XQueueWrapper::XQueueWrapper(size_t itemNumber, size_t itemSize) {
	m_handle = xQueueCreate(itemNumber, itemSize);
}

// do NOT use in a ISR
bool XQueueWrapper::pushBack(void* item) {
	return xQueueSendToBack(m_handle, item, 0) == pdPASS;
}

bool XQueueWrapper::pushBackFromISR(void* item) {
	return xQueueSendToBackFromISR(m_handle, item, 0) == pdPASS;
}

// do NOT use in a ISR
bool XQueueWrapper::receive(void* buffer) {
	return xQueueReceive(m_handle, buffer, 0) == pdPASS;
}

bool XQueueWrapper::receiveFromISR(void* buffer) {
	return xQueueReceiveFromISR(m_handle, buffer, 0) == pdPASS;
}

// do NOT use in a ISR
size_t XQueueWrapper::itemsInQueue() {
	return (size_t)uxQueueMessagesWaiting(m_handle);
}

class DashBtn {
public:
	DashBtn(GPIO_TypeDef* port, uint16_t pin)
		:m_port(port), m_pin(pin), m_lastState(LOW), m_lastChange(0) {}

	DASHBTN_STATE read() {
		DASHBTN_STATE currState = HAL_GPIO_ReadPin(m_port, m_pin) ? DASHBTN_STATE::HIGH : DASHBTN_STATE::LOW;
		if (currState != m_lastState) {
			DASHBTN_STATE retVal = m_lastState;
			m_lastState = currState;
			m_lastChange = millis();
			return retVal;
		}
		else {
			if (millis() - m_lastChange >= DEBOUNCE_TIME) {
				m_lastState = currState;
			}
			return m_lastState;
		}
	}

private:
	GPIO_TypeDef* m_port;
	uint16_t m_pin;
	DASHBTN_STATE m_lastState;
	unsigned int m_lastChange;
};

static DashBtn dashAck(NULL, 0);
static DashBtn dashInc(NULL, 0);
static DashBtn dashDec(NULL, 0);
static DashBtn dashRadio(NULL, 0);
static DashBtn dashMark(NULL, 0);
static DashBtn dashSp1(NULL, 0);
static DashBtn dashSp2(NULL, 0);

DASHBTN_STATE readDashAckBtn() {
	return dashAck.read();
}

DASHBTN_STATE readDashIncBtn() {
	return dashInc.read();
}

DASHBTN_STATE readDashDecBtn() {
	return dashDec.read();
}

DASHBTN_STATE readDashRadioBtn() {
	return dashRadio.read();
}

DASHBTN_STATE readDashMarkBtn() {
	return dashMark.read();
}

DASHBTN_STATE readDashSp1Btn() {
	return dashSp1.read();
}

DASHBTN_STATE readDashSp2Btn() {
	return dashSp2.read();
}

uint8_t readDashTractionLevel() {
	HAL_ADC_Start(&hadc3);

	while (HAL_ADC_PollForConversion(&hadc3, 1) != HAL_OK) {}

	uint16_t rawValue = HAL_ADC_GetValue(&hadc3);
	if (rawValue <= TRACTION_OFF_UPPER_VALUE) {
		return 0;
	}
	else if (rawValue <= TRACTION_1_UPPER_VALUE) {
		return 1;
	}
	else if (rawValue <= TRACTION_2_UPPER_VALUE) {
		return 2;
	}
	else if (rawValue <= TRACTION_3_UPPER_VALUE) {
		return 3;
	}
	return 4;
}

uint8_t readDashMap() {
	return 0;
}








