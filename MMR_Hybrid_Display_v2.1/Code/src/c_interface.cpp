#include "../include/c_interface.h"
#include "../include/main_application.hpp"

void decodeCAN1Msg(uint16_t id, uint8_t dlc, uint8_t* payload) {
	mainApp.decodeCAN1Msg(id, dlc, payload);
}

void decodeCAN2Msg(uint16_t id, uint8_t dlc, uint8_t* payload) {
	mainApp.decodeCAN2Msg(id, dlc, payload);
}

void decodeCAN3Msg(uint16_t id, uint8_t dlc, uint8_t* payload) {
	mainApp.decodeCAN3Msg(id, dlc, payload);
}

void startAlarmHandlerTask() {
	mainApp.alarmHandler.handlerTask();
}

void controlsHandlerTask() {
	mainApp.controlsHandler();
}
