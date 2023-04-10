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
		setValueData(&(dataset->mechanics.rpm), ((payload[0] << 8) | payload[1]));
		setValueData(&(dataset->mechanics.tps), ((payload[2] << 8) | payload[3]));
		setValueData(&(dataset->thermalPressure.waterTemperature), ((payload[4] << 8) | payload[5]));
		setValueData(&(dataset->thermalPressure.oilPressure), ((payload[6] << 8) | payload[7]));
		break;

	case 0x204:
		setValueData(&(dataset->thermalPressure.oilTemperature), ((payload[0] << 8) | payload[1]));
		setValueData(&(dataset->mechanics.gear), payload[4]);
		setValueData(&(dataset->controls.batteryVoltage), payload[6] << 8 | payload[7]);
		break;

	case 0x208:
		setValueData(&(dataset->thermalPressure.fuelPressure), ((payload[2] << 8) | payload[3]));
		setValueData(&(dataset->thermalPressure.airTemperature), ((payload[4] << 8) | payload[5]));
		break;

	case 0x20C:
		setValueData(&(dataset->controls.pedal), payload[0]);
		setValueData(&(dataset->mechanics.slip), payload[1]);
		setValueData(&(dataset->mechanics.speed), ((payload[2] << 8) | payload[3]));
		setValueData(&(dataset->controls.brake), payload[4]);
		break;

	case 0x220:
		setValueData(&(dataset->controls.launchControlStatus), payload[3]);
		break;

	case 0x30C:
		setValueData(&(dataset->controls.brakeRear), ((payload[0] << 8) | payload[1]));
		break;

	case 0x312:
		setValueData(&(dataset->thermalPressure.fuelTemperature), ((payload[0] << 8) | payload[1]));
		break;
	default:
		break;
	}
}

// Old Messages
void decodifyCanMsgOld(Dataset *dataset, uint16_t id, uint8_t dlc, uint8_t *payload) {
	// TODO Implementare dati messaggi "Current Messages"
}
