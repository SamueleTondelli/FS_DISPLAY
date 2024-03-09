#pragma once

#include <stdint.h>
#include "FreeRTOS.h"

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
