#include "../include/ps_code.hpp"

Locker::Locker() {
	m_lock = xSemaphoreCreateMutex();
}

void Locker::acquireLock() {
	xSemaphoreTake(m_lock, portMAX_DELAY);
}

void Locker::giveLock() {
	xSemaphoreGive(m_lock);
}

XQueueWrapper::XQueueWrapper(size_t itemNumber, size_t itemSize) {
	m_handle = xQueueCreate(itemNumebr, itemSize);
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
