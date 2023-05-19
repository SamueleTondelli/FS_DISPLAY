#ifndef CAN_FUNCTIONS_H
#define CAN_FUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

// START
#include "main.h"
#include "Data/Dataset.h"
// END

/**
* Function to Decodify CAN1 messages and get informations
* @param id			-> ID CAN Message
* @param dlc		-> Number of byte in Payload
* @param *payload	-> Data
*/
void decodifyCan1Msg(Dataset *dataset, uint16_t id, uint8_t dlc, uint8_t* payload);
/**
* Function to Decodify CAN2 messages and get informations
* @param id			-> ID CAN Message
* @param dlc		-> Number of byte in Payload
* @param *payload	-> Data
*/
void decodifyCan2Msg(Dataset *dataset, uint16_t id, uint8_t dlc, uint8_t* payload);
void decodifyCanMsgOld(Dataset *dataset, uint16_t id, uint8_t dlc, uint8_t* payload);

#ifdef __cplusplus
}
#endif

#endif /* CAN_FUNCTIONS_H */
