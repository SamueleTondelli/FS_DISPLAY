// START
#include "Data/Dataset.h"
#include "DisplayConstant.h"
// END

#define DEBUG_CANFUNCTION 1

#ifdef DEBUG_CANFUNCTION
//DEBUG
extern CAN_HandleTypeDef hcan1;
extern CAN_TxHeaderTypeDef ptxHeader;
extern uint32_t txMailbox;
#endif

void decodifyCan1Msg(Dataset *dataset, uint16_t id, uint8_t dlc, uint8_t* payload) {
	switch (id) {
	case 0x200:
		setValueData(&(dataset->mechanics.rpm), ((payload[0] << 8) | payload[1]));
		setValueData(&(dataset->mechanics.tps), ((payload[2] << 8) | payload[3]));
		setValueData(&(dataset->thermalPressure.waterTemperature), ((payload[4] << 8) | payload[5]));
		if (isDataCritical(&(dataset->thermalPressure.waterTemperature)) != 0)
		{
			activateDataAlarm(&(dataset->thermalPressure.waterTemperature), "T_WATER");
		}
		setValueData(&(dataset->thermalPressure.oilPressure), ((payload[6] << 8) | payload[7]));
		if (isDataCritical(&(dataset->thermalPressure.oilPressure)) != 0)
		{
			activateDataAlarm(&(dataset->thermalPressure.oilPressure), "P_OIL");
		}
		break;

	case 0x204:
		setValueData(&(dataset->thermalPressure.oilTemperature), ((payload[0] << 8) | payload[1]));
		if (isDataCritical(&(dataset->thermalPressure.oilTemperature)) != 0)
		{
			activateDataAlarm(&(dataset->thermalPressure.oilTemperature), "T_OIL");
		}
		setValueData(&(dataset->mechanics.gear), payload[4]);
		setValueData(&(dataset->controls.batteryVoltage), payload[6] << 8 | payload[7]);
		if (isDataCritical(&(dataset->controls.batteryVoltage)) != 0)
		{
			activateDataAlarm(&(dataset->controls.batteryVoltage), "VBAT");
		}
		break;

	case 0x208:
		setValueData(&(dataset->thermalPressure.fuelPressure), ((payload[2] << 8) | payload[3]));
		if (isDataCritical(&(dataset->thermalPressure.fuelPressure)) != 0)
		{
			activateDataAlarm(&(dataset->thermalPressure.oilTemperature), "P_FUEL");
		}
		setValueData(&(dataset->thermalPressure.airTemperature), ((payload[4] << 8) | payload[5]));
		if (isDataCritical(&(dataset->thermalPressure.airTemperature)) != 0)
		{
			activateDataAlarm(&(dataset->thermalPressure.airTemperature), "T_AIR");
		}
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
		if (isDataCritical(&(dataset->thermalPressure.fuelTemperature)) != 0)
		{
			activateDataAlarm(&(dataset->thermalPressure.fuelTemperature), "T_FUEL");
		}
		break;
	case 0x240:
		updateTyreTemp(&(dataset->tyres.RL), (int8_t*)payload, NULL);
		break;
	case 0x244:
		updateTyreTemp(&(dataset->tyres.RL), NULL, (int8_t*)payload);
		break;
	case 0x24C:
		updateTyreTemp(&(dataset->tyres.RR), (int8_t*)payload, NULL);
		break;
	case 0x26C:
		updateTyreTemp(&(dataset->tyres.RR), NULL, (int8_t*)payload);
		break;
	case 0x254:
		updateTyreTemp(&(dataset->tyres.FL), (int8_t*)payload, NULL);
		break;
	case 0x25C:
		updateTyreTemp(&(dataset->tyres.FL), NULL, (int8_t*)payload);
		break;
	case 0x260:
		updateTyreTemp(&(dataset->tyres.FR), (int8_t*)payload, NULL);
		break;
	case 0x264:
		updateTyreTemp(&(dataset->tyres.FR), NULL, (int8_t*)payload);
	default:
		break;
	}
}

void decodifyCan2Msg(Dataset *dataset, uint16_t id, uint8_t dlc, uint8_t* payload)
{
	switch (id)
	{
	case 0x308:
		setValueData(&(dataset->controls.steer), ((payload[5] << 8) | payload[4]));
		break;
	case 0x390:
		setValueData(&(dataset->controls.gpsLongitude), ((payload[0] << 24) | (payload[1] << 16) | (payload[2] << 8) | payload[3]));
		setValueData(&(dataset->controls.gpsLatitude), ((payload[4] << 24) | (payload[5] << 16) | (payload[6] << 8) | payload[7]));
		break;
	case 0x394:
		setValueData(&(dataset->controls.gpsAltitude), ((payload[0] << 24) | (payload[1] << 16) | (payload[2] << 8) | payload[3]));
		break;
	default:
		break;
	}
}

// Old Messages
void decodifyCanMsgOld(Dataset *dataset, uint16_t id, uint8_t dlc, uint8_t *payload) {
	// TODO Implementare dati messaggi "Current Messages"
}
