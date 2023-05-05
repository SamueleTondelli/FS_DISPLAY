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
		if (isDataCritical(&(dataset->mechanics.rpm)) == 1)
		{
			activateDataAlarm(&(dataset->mechanics.rpm), "RPM");
		}
		setValueData(&(dataset->mechanics.tps), ((payload[2] << 8) | payload[3]));
		if (isDataCritical(&(dataset->mechanics.tps)) == 1)
		{
			activateDataAlarm(&(dataset->mechanics.tps), "TPS");
		}
		setValueData(&(dataset->thermalPressure.waterTemperature), ((payload[4] << 8) | payload[5]));
		if (isDataCritical(&(dataset->thermalPressure.waterTemperature)) == 1)
		{
			activateDataAlarm(&(dataset->thermalPressure.waterTemperature), "T_WATER");
		}
		setValueData(&(dataset->thermalPressure.oilPressure), ((payload[6] << 8) | payload[7]));
		if (isDataCritical(&(dataset->thermalPressure.oilPressure)) == 1)
		{
			activateDataAlarm(&(dataset->thermalPressure.oilPressure), "P_OIL");
		}
		break;

	case 0x204:
		setValueData(&(dataset->thermalPressure.oilTemperature), ((payload[0] << 8) | payload[1]));
		if (isDataCritical(&(dataset->thermalPressure.oilTemperature)) == 1)
		{
			activateDataAlarm(&(dataset->thermalPressure.oilTemperature), "T_OIL");
		}
		setValueData(&(dataset->mechanics.gear), payload[4]);
		if (isDataCritical(&(dataset->mechanics.gear)) == 1)
		{
			activateDataAlarm(&(dataset->mechanics.gear), "GEAR");
		}
		setValueData(&(dataset->controls.batteryVoltage), payload[6] << 8 | payload[7]);
		if (isDataCritical(&(dataset->controls.batteryVoltage)) == 1)
		{
			activateDataAlarm(&(dataset->controls.batteryVoltage), "VBAT");
		}
		break;

	case 0x208:
		setValueData(&(dataset->thermalPressure.fuelPressure), ((payload[2] << 8) | payload[3]));
		if (isDataCritical(&(dataset->thermalPressure.fuelPressure)) == 1)
		{
			activateDataAlarm(&(dataset->thermalPressure.oilTemperature), "P_FUEL");
		}
		setValueData(&(dataset->thermalPressure.airTemperature), ((payload[4] << 8) | payload[5]));
		if (isDataCritical(&(dataset->thermalPressure.airTemperature)) == 1)
		{
			activateDataAlarm(&(dataset->thermalPressure.airTemperature), "T_AIR");
		}
		break;

	case 0x20C:
		setValueData(&(dataset->controls.pedal), payload[0]);
		if (isDataCritical(&(dataset->controls.pedal)) == 1)
		{
			activateDataAlarm(&(dataset->controls.pedal), "PEDAL");
		}
		setValueData(&(dataset->mechanics.slip), payload[1]);
		if (isDataCritical(&(dataset->mechanics.slip)) == 1)
		{
			activateDataAlarm(&(dataset->mechanics.slip), "SLIP");
		}
		setValueData(&(dataset->mechanics.speed), ((payload[2] << 8) | payload[3]));
		if (isDataCritical(&(dataset->mechanics.speed)) == 1)
		{
			activateDataAlarm(&(dataset->mechanics.speed), "SPEED");
		}
		setValueData(&(dataset->controls.brake), payload[4]);
		if (isDataCritical(&(dataset->controls.brake)) == 1)
		{
			activateDataAlarm(&(dataset->controls.brake), "BRAKE");
		}
		break;

	case 0x220:
		setValueData(&(dataset->controls.launchControlStatus), payload[3]);
		if (isDataCritical(&(dataset->controls.launchControlStatus)) == 1)
		{
			activateDataAlarm(&(dataset->controls.launchControlStatus), "LAUNCH");
		}
		break;

	case 0x30C:
		setValueData(&(dataset->controls.brakeRear), ((payload[0] << 8) | payload[1]));
		if (isDataCritical(&(dataset->controls.brakeRear)) == 1)
		{
			activateDataAlarm(&(dataset->controls.brakeRear), "BRAKE_R");
		}
		break;

	case 0x312:
		setValueData(&(dataset->thermalPressure.fuelTemperature), ((payload[0] << 8) | payload[1]));
		if (isDataCritical(&(dataset->thermalPressure.fuelTemperature)) == 1)
		{
			activateDataAlarm(&(dataset->thermalPressure.fuelTemperature), "T_FUEL");
		}
		break;
	default:
		break;
	}
}

// Old Messages
void decodifyCanMsgOld(Dataset *dataset, uint16_t id, uint8_t dlc, uint8_t *payload) {
	// TODO Implementare dati messaggi "Current Messages"
}
