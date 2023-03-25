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

	if(id == 0x200) {
		setValueData(&(dataset->powerUnit.rpm), ((payload[0] << 8) | payload[1]));
	}

	if ((id < 0x200) && (id > 0x2ff))
		return;

	/*
	 * POWER UNIT 
	 */
	if ((id >= 0x200) && (id <= 0x20f)) {
		if (id == 0x200) {
			setValueData(&(dataset->powerUnit.gear), payload[0]);
			setDataStatus(&(dataset->powerUnit.engineStateCV), payload[1]);
			setValueData(&(dataset->powerUnit.rpm), ((payload[2] << 8) | payload[3]));
			setValueData(&(dataset->powerUnit.oilPressure), ((payload[4] << 8) | payload[5]));
			setValueData(&(dataset->powerUnit.oilTemperature), ((payload[6] << 8) | payload[7]));
		} else if (id == 0x201) {
			setDataStatus(&(dataset->powerUnit.idleStateCV), payload[0]);
			setValueData(&(dataset->powerUnit.coolantTemperatureCV), ((payload[1] << 8) | payload[2]));
			setValueData(&(dataset->powerUnit.vehicleSpeed), payload[3]);
			setValueData(&(dataset->powerUnit.ignitionTiming), ((payload[4] << 8) | payload[5]));
			setValueData(&(dataset->powerUnit.fuelPressure), ((payload[6] << 8) | payload[7]));
		} else if (id == 0x202) {
			setValueData(&(dataset->powerUnit.exhaustLambda), ((payload[0] << 8) | payload[1]));
			setValueData(&(dataset->powerUnit.lambdaTarget), ((payload[2] << 8) | payload[3]));
			setValueData(&(dataset->powerUnit.ambientTemperature), ((payload[4] << 8) | payload[5]));
			setValueData(&(dataset->powerUnit.inletMainfoldPressure), ((payload[6] << 8) | payload[7]));
		} else if (id == 0x203) {
			setValueData(&(dataset->powerUnit.map), ((payload[0] << 8) | payload[1]));
			setValueData(&(dataset->powerUnit.engineChargeTemperature), ((payload[2] << 8) | payload[3]));
			setValueData(&(dataset->powerUnit.bevelGearTemperature), ((payload[4] << 8) | payload[5]));
			setValueData(&(dataset->powerUnit.injectedFuelFlow), ((payload[6] << 8) | payload[7]));
		} else if (id == 0x204) {
			setValueData(&(dataset->powerUnit.injectedFuelVolume), ((payload[0] << 8) | payload[1]));
			setValueData(&(dataset->powerUnit.fuelClosedLoopControlBank1), ((payload[2] << 8) | payload[3]));
			setValueData(&(dataset->powerUnit.fuelUsed), ((payload[4] << 8) | payload[5]));
			setValueData(&(dataset->powerUnit.fuelInjectorPrimaryDifferentialPressure), ((payload[6] << 8) | payload[7]));
		}
	}
	/*
	 * HV ELECTRONICS BMS
	 */
	if ((id >= 0x210) && (id <= 0x21f)) {
		if (id == 0x210) {
			setValueData(&(dataset->hvElectronicsBMS.delta), ((payload[0] << 8) | payload[1]));
			setValueData(&(dataset->hvElectronicsBMS.deltaMax), ((payload[2] << 8) | payload[3]));
			setValueData(&(dataset->hvElectronicsBMS.soc), payload[4]);
			setValueData(&(dataset->hvElectronicsBMS.soh), payload[5]);
			setValueData(&(dataset->hvElectronicsBMS.ampereBatteryHVmax), ((payload[6] << 8) | payload[7]));
		} else if (id == 0x211) {
			setValueData(&(dataset->hvElectronicsBMS.voltageBatteryHV), ((payload[0] << 8) | payload[1]));
			setValueData(&(dataset->hvElectronicsBMS.ampereBatteryHV), ((payload[2] << 8) | payload[3]));
			setValueData(&(dataset->hvElectronicsBMS.batteryTML), ((payload[4] << 8) | payload[5]));
			setValueData(&(dataset->hvElectronicsBMS.batteryTMH), ((payload[6] << 8) | payload[7]));
		}
	}
	/*
	 * HV ELECTRONICS INVERTER
	 */
	if ((id >= 0x220) && (id <= 0x22f)) {
		if (id == 0x220) {
			setValueData(&(dataset->hvElectronicsInverter.electricMotorSpeed), ((payload[0] << 8) | payload[1]));
			setValueData(&(dataset->hvElectronicsInverter.electricMotorTorque), ((payload[2] << 8) | payload[3]));
			setValueData(&(dataset->hvElectronicsInverter.electricMotorTemperature), ((payload[4] << 8) | payload[5]));
			// HCCS setDataStatus(&(dataset->powerUnit.idleStateCV), payload[0]);
		} else if (id == 0x221) {
			setValueData(&(dataset->hvElectronicsInverter.targetID), ((payload[0] << 8) | payload[1]));
			setValueData(&(dataset->hvElectronicsInverter.targetIQ), ((payload[2] << 8) | payload[3]));
			setValueData(&(dataset->hvElectronicsInverter.currentID), ((payload[4] << 8) | payload[5]));
			setValueData(&(dataset->hvElectronicsInverter.currentIQ), ((payload[6] << 8) | payload[7]));
		} else if (id == 0x222) {
			setValueData(&(dataset->hvElectronicsInverter.inverterCapacitorVoltage), ((payload[0] << 8) | payload[1]));
			setValueData(&(dataset->hvElectronicsInverter.inverterTemperature), ((payload[2] << 8) | payload[3]));
			setValueData(&(dataset->hvElectronicsInverter.inverterBatteryCurrent), ((payload[4] << 8) | payload[5]));
			setValueData(&(dataset->hvElectronicsInverter.inverterBatteryVoltage), ((payload[6] << 8) | payload[7]));
		} else if (id == 0x223) {
			setValueData(&(dataset->hvElectronicsInverter.inverterTorqueMax), ((payload[0] << 8) | payload[1]));
			setValueData(&(dataset->hvElectronicsInverter.inverterSpeedMax), ((payload[2] << 8) | payload[3]));
			setValueData(&(dataset->hvElectronicsInverter.batteryDischargeCurrentMax), ((payload[4] << 8) | payload[5]));
			setValueData(&(dataset->hvElectronicsInverter.batteryChargeCurrentMax), ((payload[6] << 8) | payload[7]));
		} else if (id == 0x224) {
			setValueData(&(dataset->hvElectronicsInverter.actualPowerProvidedElectric), ((payload[0] << 8) | payload[1]));
		}
	}
	/*
	 * LV ELECTRONICS
	 */
	if ((id >= 0x230) && (id <= 0x23f)) {
		if (id == 0x230) {
			setValueData(&(dataset->lvElectronics.voltageBatteryLV), payload[0]);
			setValueData(&(dataset->lvElectronics.throttlePedal), payload[1]);
			setValueData(&(dataset->lvElectronics.throttlePosition), payload[2]);
			setValueData(&(dataset->lvElectronics.tps1), payload[3]);
			setValueData(&(dataset->lvElectronics.tps2), payload[4]);
			setValueData(&(dataset->lvElectronics.apps1), payload[5]);
			setValueData(&(dataset->lvElectronics.apps2), payload[6]);
		} else if (id == 0x231) {
			setValueData(&(dataset->lvElectronics.bseFront), ((payload[0] << 8) | payload[1]));
			setValueData(&(dataset->lvElectronics.bseRear), ((payload[2] << 8) | payload[3]));
		} else if (id == 0x232) {
			setDataStatus(&(dataset->lvElectronics.can1Diagnostic), payload[0]);
			setDataStatus(&(dataset->lvElectronics.can1Mode), payload[1]);
			setDataStatus(&(dataset->lvElectronics.can2Diagnostic), payload[2]);
			setDataStatus(&(dataset->lvElectronics.can2Mode), payload[3]);
			setDataStatus(&(dataset->lvElectronics.can3Diagnostic), payload[4]);
			setDataStatus(&(dataset->lvElectronics.can3Mode), payload[5]);
			setValueData(&(dataset->lvElectronics.ecuCpuUsage), payload[6]);
			//setDataStatus(&(dataset->lvElectronics.ecuLed), payload[7]);	// TODO Controllare
		} else if (id == 0x233) {
			setValueData(&(dataset->lvElectronics.ecuTemperature), ((payload[0] << 8) | payload[1]));
			setDataStatus(&(dataset->lvElectronics.etcMode), payload[2]);
			setDataStatus(&(dataset->lvElectronics.etcState), payload[3]);
			setDataStatus(&(dataset->lvElectronics.etcCriticalState), payload[4]);
			setDataStatus(&(dataset->lvElectronics.etcThrottlePedalCritical), payload[5]);
		} else if (id == 0x234) {
			// TODO Implementare Stato Bottoni	
		} else if (id == 0x235) {
			// TODO Implementare Stato Bottoni
		}
	}
	/*
	 * THERMAL MANAGEMENT & AERODYNAMICS
	 */
	if ((id >= 0x240) && (id <= 0x24f)) {
		if (id == 0x240) {
			setValueData(&(dataset->thermalAerodynamics.coolantTemperatureEV), ((payload[0] << 8) | payload[1]));
			setValueData(&(dataset->thermalAerodynamics.coolantFan1), payload[2]);
			setValueData(&(dataset->thermalAerodynamics.coolantFan1TemperatureLimit), ((payload[3] << 8) | payload[4]));
			setValueData(&(dataset->thermalAerodynamics.coolantFan2), payload[5]);
			setValueData(&(dataset->thermalAerodynamics.coolantFan2TemperatureLimit), ((payload[6] << 8) | payload[7]));
		} else if (id == 0x241) {
			setDataStatus(&(dataset->thermalAerodynamics.coolantFanInputMode), payload[0]);
			setDataStatus(&(dataset->thermalAerodynamics.coolantPumpHVState), payload[1]);
		} else if (id == 0x242) {
			setValueData(&(dataset->thermalAerodynamics.brakeTemperatureFrontRight), ((payload[0] << 8) | payload[1]));
			setValueData(&(dataset->thermalAerodynamics.brakeTemperatureFrontLeft), ((payload[2] << 8) | payload[3]));
			setValueData(&(dataset->thermalAerodynamics.brakeTemperatureRearRight), ((payload[4] << 8) | payload[5]));
			setValueData(&(dataset->thermalAerodynamics.brakeTemperatureRearLeft), ((payload[6] << 8) | payload[7]));
		} else if (id == 0x243) {
			setValueData(&(dataset->thermalAerodynamics.brakeTermocouple0), ((payload[0] << 8) | payload[1]));
			setValueData(&(dataset->thermalAerodynamics.brakeTermocouple1), ((payload[4] << 8) | payload[5]));
			setValueData(&(dataset->thermalAerodynamics.brakeTermocouple2), ((payload[6] << 8) | payload[7]));
			setValueData(&(dataset->thermalAerodynamics.brakeTermocouple3), ((payload[6] << 8) | payload[7]));
		}
	}
	/*
	 * VEHICLE DYNAMICS
	 */
	if ((id >= 0x250) && (id <= 0x25f)) {
		if (id == 0x250) {
			setValueData(&(dataset->dynamics.brakePressureFront), ((payload[0] << 8) | payload[1]));
			setValueData(&(dataset->dynamics.brakePressureRear), ((payload[2] << 8) | payload[3]));
			setValueData(&(dataset->dynamics.accelerometerX), ((payload[4] << 8) | payload[5]));
			setValueData(&(dataset->dynamics.accelerometerY), ((payload[6] << 8) | payload[7]));
		} else if (id == 0x251) {
			setValueData(&(dataset->dynamics.wheelSpeedFrontRight), payload[0]);
			setValueData(&(dataset->dynamics.wheelSpeedFrontLeft), payload[1]);
			setValueData(&(dataset->dynamics.wheelSpeedRearRight), payload[2]);
			setValueData(&(dataset->dynamics.wheelSpeedRearleft), payload[3]);
			setValueData(&(dataset->dynamics.suspensionHeightFrontRight), payload[4]);
			setValueData(&(dataset->dynamics.suspensionHeightFrontLeft), payload[5]);
			setValueData(&(dataset->dynamics.suspensionHeightRearRight), payload[6]);
			setValueData(&(dataset->dynamics.suspensionHeightRearLeft), payload[7]);
		} else if (id == 0x252) {
			// TODO Implementare GPS
		} else if (id == 0x253) {
			setValueData(&(dataset->dynamics.motecGpsTrueCourse), ((payload[0] << 8) | payload[1]));
			setValueData(&(dataset->dynamics.gpsSpeed), payload[2]);
			//setValueData(&(dataset->dynamics), payload[3]);
		}
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
