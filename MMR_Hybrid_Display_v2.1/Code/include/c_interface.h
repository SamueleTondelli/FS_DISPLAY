#ifndef C_INTERFACE_H
#define C_INTERFACE_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
	void decodeCAN1Msg(uint16_t id, uint8_t dlc, uint8_t* payload);
	void decodeCAN2Msg(uint16_t id, uint8_t dlc, uint8_t* payload);
	void decodeCAN3Msg(uint16_t id, uint8_t dlc, uint8_t* payload);
	void startAlarmHandlerTask();
	void startControlsHandlerTask();
#ifdef __cplusplus
}
#endif

#endif
