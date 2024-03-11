#pragma once

#include <stdint.h>
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
#include "main.h"

/* platform specific code */

class Locker
{
public:
	Locker();

	void acquireLock();
	void giveLock();

private:
	SemaphoreHandle_t m_lock;
};

unsigned int millis();

class XQueueWrapper {
public:
	XQueueWrapper(size_t itemNumber, size_t itemSize);
	// do NOT use in a ISR
	bool pushBack(void* item);
	bool pushBackFromISR(void* item);
	// do NOT use in a ISR
	bool receive(void* buffer);
	bool receiveFromISR(void* buffer);
	// do NOT use in a ISR
	size_t itemsInQueue();

private:
	QueueHandle_t m_handle;
};


enum DASHBTN_STATE {
	LOW,
	HIGH
};

DASHBTN_STATE readDashAckBtn();
DASHBTN_STATE readDashIncBtn();
DASHBTN_STATE readDashDecBtn();
DASHBTN_STATE readDashRadioBtn();
DASHBTN_STATE readDashMarkBtn();
DASHBTN_STATE readDashSp1Btn();
DASHBTN_STATE readDashSp2Btn();
uint8_t readDashTractionLevel();
uint8_t readDashMap();
