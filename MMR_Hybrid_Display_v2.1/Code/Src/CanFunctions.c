// START
#include "Data/Dataset.h"
#include "Data/DataNotification.h"
#include "DisplayConstant.h"
// END

#define DEBUG_CANFUNCTION 1

#ifdef DEBUG_CANFUNCTION
//DEBUG
extern CAN_HandleTypeDef hcan1;
extern CAN_TxHeaderTypeDef ptxHeader;
extern uint32_t txMailbox;
#endif

void decodifyCanMsg(Dataset *dataset, uint16_t id, uint8_t dlc, uint8_t* payload) {
	switch (id) {
	case 0x200:
		break;

	case 0x204:
		break;

	case 0x208:
		break;

	case 0x220:
		break;

	case 0x20C:
		break;

	case 0x30C:

		break;

	case 0x321:
		break;

	case 0x240:

		break;

	case 0x244:

		break;

	case 0x24C:

		break;

	case 0x26C:

		break;

	case 0x254:

		break;

	case 0x25C:

		break;

	case 0x260:

		break;

	case 0x264:

		break;

	default:

		break;
	}

	/*
	 * MESSAGES & ERRORS
	 */
	if ((id >= 0x290) && (id <= 0x29f)) {
		if (id == 0x290) {
			setDataStatus(&(dataset->messageErrors.pressureOilAlarm), payload[0]);
			setDataStatus(&(dataset->messageErrors.oilTemperatureAlarm), payload[1]);
			setDataStatus(&(dataset->messageErrors.waterTemperatureAlarm), payload[2]);
			setDataStatus(&(dataset->messageErrors.warningSource), payload[3]);
#ifdef DEBUG_CANFUNCTION
			//DEBUG
			//uint8_t dummyData[8] = {0};
			ptxHeader.StdId = 0x290;
			ptxHeader.DLC = 8;
			HAL_CAN_AddTxMessage(&hcan1, &ptxHeader, payload, &txMailbox);
#endif
		} else if (id == 0x291) {
			if(dataset->screen.notificationFlag == 0) {
				setMessageTypeDataNotification(&(dataset->messageErrors.driverMessage), payload[0]);
				setMessageLengthDataNotification(&(dataset->messageErrors.driverMessage), payload[1]);
				loadDriverMessage(&(dataset->messageErrors.driverMessage), payload, 1);
#ifdef DEBUG_CANFUNCTION
				//DEBUG
				//uint8_t dummyData[8] = {0};
				//dummyData[0] = dataset->messageErrors.driverMessage.notificationCounter;
				ptxHeader.StdId = 0x291;
				ptxHeader.DLC = 8;
				HAL_CAN_AddTxMessage(&hcan1, &ptxHeader, payload, &txMailbox);
#endif
			}
		} else if (id == 0x292) {
			if(dataset->screen.notificationFlag == 0) {
				loadDriverMessage(&(dataset->messageErrors.driverMessage), payload, 2);
#ifdef DEBUG_CANFUNCTION
				//DEBUG
				//uint8_t dummyData[8] = {0};
				//dummyData[0] = dataset->messageErrors.driverMessage.notificationCounter;
				ptxHeader.StdId = 0x292;
				ptxHeader.DLC = 8;
				HAL_CAN_AddTxMessage(&hcan1, &ptxHeader, payload, &txMailbox);
#endif
			}
		} else if (id == 0x293) {
			if(dataset->screen.notificationFlag == 0) {
				loadDriverMessage(&(dataset->messageErrors.driverMessage), payload, 3);
#ifdef DEBUG_CANFUNCTION
				//DEBUG
				//uint8_t dummyData[8] = {0};
				//dummyData[0] = dataset->messageErrors.driverMessage.notificationCounter;
				ptxHeader.StdId = 0x293;
				ptxHeader.DLC = 8;
				HAL_CAN_AddTxMessage(&hcan1, &ptxHeader, payload, &txMailbox);
#endif
			}
		} else if (id == 0x294) {
			if(dataset->screen.notificationFlag == 0) {
				loadDriverMessage(&(dataset->messageErrors.driverMessage), payload, 4);
#ifdef DEBUG_CANFUNCTION
				//DEBUG
				//uint8_t dummyData[8] = {0};
				//dummyData[0] = dataset->messageErrors.driverMessage.notificationCounter;
				ptxHeader.StdId = 0x294;
				ptxHeader.DLC = 8;
				HAL_CAN_AddTxMessage(&hcan1, &ptxHeader, payload, &txMailbox);
#endif
			}
		} else if (id == 0x295) {
			changeDisplayMode(&(dataset->screen), payload[0]);
		} else if (id == 0x296) {
			// TODO Implementare funzione di decodifica per il LapTime
		}
	}
}

// Old Messages
void decodifyCanMsgOld(Dataset *dataset, uint16_t id, uint8_t dlc, uint8_t *payload) {
	// TODO Implementare dati messaggi "Current Messages"
}
