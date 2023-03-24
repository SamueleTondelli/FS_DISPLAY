

#ifndef __CAR_DATA_H
#include "CAR_DATA.h"
#endif

#ifndef __DIAPLAY_GUI_CONF_H
#include "DISPLAY_GUI_Conf.h"
#endif

#ifndef __MDM_FUNCTIONS_H
#include "MDM_Functions.h"
#endif

extern CAN_HandleTypeDef 			hcan1;
CAN_TxHeaderTypeDef 				pHeader_CAN1; 					//declare a specific header for message transmittions
CAN_RxHeaderTypeDef 				pRxHeader_CAN1; 				//declare header for message reception
uint32_t 							TxMailbox_CAN1;
uint8_t 							TxData_CAN1[8];
uint8_t 							RxData_CAN1[8];

CAN_FilterTypeDef 					sFilterConfig0_CAN1;
CAN_FilterTypeDef 					sFilterConfig1_CAN1;
CAN_FilterTypeDef 					sFilterConfig2_CAN1;

CAN_FilterTypeDef 					sFilterConfig3_CAN1;

CAN_FilterTypeDef 					sFilterConfig9_CAN1;			//RL Tyre Temp filter
CAN_FilterTypeDef 					sFilterConfig10_CAN1;			//RR Tyre Temp filter
CAN_FilterTypeDef 					sFilterConfig11_CAN1;			//FL Tyre Temp filter
CAN_FilterTypeDef 					sFilterConfig12_CAN1;			//FR Tyre Temp filter


void CAN1_DATA_Read(void);
void GPIO_IN_Read(void);

void canDataGenerationForDebug(void);


extern CAN_HandleTypeDef 			hcan2;
CAN_TxHeaderTypeDef 				pHeader_CAN2; 					//declare a specific header for message transmissions
CAN_RxHeaderTypeDef 				pRxHeader_CAN2; 				//declare header for message reception
uint32_t TxMailbox_CAN2;

uint8_t 							TxData_CAN2[8];
uint8_t 							dataRX_CAN2[8];
uint8_t 							dataRX_SAVED[8];

CAN_FilterTypeDef 					sFilterConfig0_CAN2;
CAN_FilterTypeDef 					sFilterConfig1_CAN2;


extern ADC_HandleTypeDef hadc3;
uint16_t TRACTION_AD_RESr = 0;
uint16_t tractionFilterBuffer[TRACTION_FILTER_SIZE];
uint16_t tractionAdcFiltered = 0;


uint32_t cameraData = 0;			//used for debug

void CAR_CAN_Init(void)
{
	pHeader_CAN1.DLC = 8; //give message size of 1 byte
	pHeader_CAN1.IDE = CAN_ID_STD; //set identifier to standard
	pHeader_CAN1.RTR = CAN_RTR_DATA; //set data type to remote transmission request?
	pHeader_CAN1.StdId = 0x250; //define a standard identifier, used for message identification by filters (switch this for the other microcontroller)

	sFilterConfig0_CAN1.FilterBank = 0; //filter bank 0 to 12
	sFilterConfig0_CAN1.FilterMode = CAN_FILTERMODE_IDLIST; //CAN_FILTERMODE_IDLIST
	sFilterConfig0_CAN1.FilterScale = CAN_FILTERSCALE_16BIT;
	sFilterConfig0_CAN1.FilterIdHigh = 0x204 << 5; //can put 2 standard id's in 16 bit mode
	sFilterConfig0_CAN1.FilterIdLow = 0x200 << 5;
	sFilterConfig0_CAN1.FilterMaskIdHigh = 0x0; //mask doesn't care in IDLIST Mode
	sFilterConfig0_CAN1.FilterMaskIdLow = 0x0;
	sFilterConfig0_CAN1.FilterFIFOAssignment = CAN_FILTER_FIFO0; //we have fifo 0 and fifo 1
	sFilterConfig0_CAN1.SlaveStartFilterBank = 14;
	sFilterConfig0_CAN1.FilterActivation = ENABLE;

	sFilterConfig1_CAN1.FilterBank = 1; //filter bank 0 to 12
	sFilterConfig1_CAN1.FilterMode = CAN_FILTERMODE_IDLIST; //CAN_FILTERMODE_IDLIST
	sFilterConfig1_CAN1.FilterScale = CAN_FILTERSCALE_16BIT;
	sFilterConfig1_CAN1.FilterIdHigh = 0x220 << 5; //can put 2 standard id's in 16 bit mode
	sFilterConfig1_CAN1.FilterIdLow = 0x208 << 5;
	sFilterConfig1_CAN1.FilterMaskIdHigh = 0x0; //mask doesn't care in IDLIST Mode
	sFilterConfig1_CAN1.FilterMaskIdLow = 0x0;
	sFilterConfig1_CAN1.FilterFIFOAssignment = CAN_FILTER_FIFO0; //we have fifo 0 and fifo 1
	sFilterConfig1_CAN1.SlaveStartFilterBank = 14;
	sFilterConfig1_CAN1.FilterActivation = ENABLE;

	sFilterConfig2_CAN1.FilterBank = 2; //filter bank 0 to 12
	sFilterConfig2_CAN1.FilterMode = CAN_FILTERMODE_IDLIST; //CAN_FILTERMODE_IDLIST
	sFilterConfig2_CAN1.FilterScale = CAN_FILTERSCALE_16BIT;
	sFilterConfig2_CAN1.FilterIdHigh = 0x20C << 5; //can put 2 standard id's in 16 bit mode
	sFilterConfig2_CAN1.FilterIdLow = 0x321 << 5;
	sFilterConfig2_CAN1.FilterMaskIdHigh = 0x0; //mask doesn't care in IDLIST Mode
	sFilterConfig2_CAN1.FilterMaskIdLow = 0x0;
	sFilterConfig2_CAN1.FilterFIFOAssignment = CAN_FILTER_FIFO0; //we have fifo 0 and fifo 1
	sFilterConfig2_CAN1.SlaveStartFilterBank = 14;
	sFilterConfig2_CAN1.FilterActivation = ENABLE;




	sFilterConfig3_CAN1.FilterBank = 3; //filter bank 0 to 12
	sFilterConfig3_CAN1.FilterMode = CAN_FILTERMODE_IDLIST; //CAN_FILTERMODE_IDLIST
	sFilterConfig3_CAN1.FilterScale = CAN_FILTERSCALE_16BIT;
	sFilterConfig3_CAN1.FilterIdHigh = 0x30C << 5; //can put 2 standard id's in 16 bit mode
	sFilterConfig3_CAN1.FilterIdLow = 0x312 << 5;
	sFilterConfig3_CAN1.FilterMaskIdHigh = 0x0; //mask doesn't care in IDLIST Mode
	sFilterConfig3_CAN1.FilterMaskIdLow = 0x0;
	sFilterConfig3_CAN1.FilterFIFOAssignment = CAN_FILTER_FIFO0; //we have fifo 0 and fifo 1
	sFilterConfig3_CAN1.SlaveStartFilterBank = 14;
	sFilterConfig3_CAN1.FilterActivation = ENABLE;





	sFilterConfig9_CAN1.FilterBank = 12; //filter bank 0 to 12
	sFilterConfig9_CAN1.FilterMode = CAN_FILTERMODE_IDLIST; //CAN_FILTERMODE_IDLIST
	sFilterConfig9_CAN1.FilterScale = CAN_FILTERSCALE_16BIT;
	sFilterConfig9_CAN1.FilterIdHigh = 0x00 << 5;
	sFilterConfig9_CAN1.FilterIdLow = 0x00 << 5;
	sFilterConfig9_CAN1.FilterMaskIdHigh = 0x0; //mask doesn't care in IDLIST Mode
	sFilterConfig9_CAN1.FilterMaskIdLow = 0x0;
	sFilterConfig9_CAN1.FilterFIFOAssignment = CAN_FILTER_FIFO0; //we have fifo 0 and fifo 1
	sFilterConfig9_CAN1.SlaveStartFilterBank = 14;
	sFilterConfig9_CAN1.FilterActivation = ENABLE;

	sFilterConfig10_CAN1 = sFilterConfig9_CAN1;
	sFilterConfig11_CAN1 = sFilterConfig9_CAN1;
	sFilterConfig12_CAN1 = sFilterConfig9_CAN1;

	sFilterConfig9_CAN1.FilterBank   = 9;
	sFilterConfig9_CAN1.FilterIdHigh = RL_TyreTemp_0to7_address  << 5;
	sFilterConfig9_CAN1.FilterIdLow  = RL_TyreTemp_8to15_address << 5;

	sFilterConfig10_CAN1.FilterBank   = 10;
	sFilterConfig10_CAN1.FilterIdHigh = RR_TyreTemp_0to7_address  << 5;
	sFilterConfig10_CAN1.FilterIdLow  = RR_TyreTemp_8to15_address << 5;

	sFilterConfig11_CAN1.FilterBank   = 11;
	sFilterConfig11_CAN1.FilterIdHigh = FL_TyreTemp_0to7_address  << 5;
	sFilterConfig11_CAN1.FilterIdLow  = FL_TyreTemp_8to15_address << 5;

	sFilterConfig12_CAN1.FilterBank   = 12;
	sFilterConfig12_CAN1.FilterIdHigh = FR_TyreTemp_0to7_address  << 5;
	sFilterConfig12_CAN1.FilterIdLow  = FR_TyreTemp_8to15_address << 5;





	pHeader_CAN2.DLC = 8; //give message size of 1 byte
	pHeader_CAN2.IDE = CAN_ID_STD; //set identifier to standard
	pHeader_CAN2.RTR = CAN_RTR_DATA; //set data type to remote transmission request?
	pHeader_CAN2.StdId = 0x203; //define a standard identifier, used for message identification by filters (switch this for the other microcontroller)

	sFilterConfig0_CAN2.FilterBank = 14; //filter bank 13 to 27
	sFilterConfig0_CAN2.FilterMode = CAN_FILTERMODE_IDLIST; //CAN_FILTERMODE_IDLIST
	sFilterConfig0_CAN2.FilterScale = CAN_FILTERSCALE_16BIT;
	sFilterConfig0_CAN2.FilterIdHigh = 0x308 << 5; //can put 2 standard id's in 16 bit mode
	sFilterConfig0_CAN2.FilterIdLow = 0x174 << 5;
	sFilterConfig0_CAN2.FilterMaskIdHigh = 0x0; //mask doesn't care in IDLIST Mode
	sFilterConfig0_CAN2.FilterMaskIdLow = 0x0;
	sFilterConfig0_CAN2.FilterFIFOAssignment = CAN_FILTER_FIFO1; //we have fifo 0 and fifo 1
	sFilterConfig0_CAN2.SlaveStartFilterBank = 14;
	sFilterConfig0_CAN2.FilterActivation = ENABLE;

	sFilterConfig1_CAN2.FilterBank = 15; //filter bank 13 to 27
	sFilterConfig1_CAN2.FilterMode = CAN_FILTERMODE_IDLIST; //CAN_FILTERMODE_IDLIST
	sFilterConfig1_CAN2.FilterScale = CAN_FILTERSCALE_16BIT;
	sFilterConfig1_CAN2.FilterIdHigh = 0x178 << 5; //can put 2 standard id's in 16 bit mode
	sFilterConfig1_CAN2.FilterIdLow = 0x17C << 5;
	sFilterConfig1_CAN2.FilterMaskIdHigh = 0x0; //mask doesn't care in IDLIST Mode
	sFilterConfig1_CAN2.FilterMaskIdLow = 0x0;
	sFilterConfig1_CAN2.FilterFIFOAssignment = CAN_FILTER_FIFO1; //we have fifo 0 and fifo 1
	sFilterConfig1_CAN2.SlaveStartFilterBank = 14;
	sFilterConfig1_CAN2.FilterActivation = ENABLE;





	HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig0_CAN1);		//ECU		0x200: rpm[2], tps[2], waterTemperature[2], oilPressure[2]
															//ECU		0x204: oilTemperature[2], ND[1], gear[1], DN[1], batteryVoltage[2]
	HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig1_CAN1);		//ECU		0x208: ND[2], fuelPressure[2], airTemperature[2], ND[2]
															//GBU		0x220: ND[3], launchControlStatus[1], ND[4]
	HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig2_CAN1);		//ECU		0x20C: pedal[1], slip[1], speed[2], brake[1], ND[3]
															//DRS		0x321: ND[4], drsTargher[2], ND[2]

	HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig3_CAN1);		//LOG		0x30C: brakeRear[1], ND[7]
															//			0x312: fuelTemperature[2], ND[6]


	HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig9_CAN1);		//RL_TCAM	0x240: tyreTemp0_7[8]
															//RL_TCAM	0x244: tyreTemp8_15[8]
	HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig10_CAN1);	//RR_TCAM	0x24C: tyreTemp0_7[8]
															//RR_TCAM	0x26C: tyreTemp8_15[8]
	HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig11_CAN1);	//FL_TCAM	0x254: tyreTemp0_7[8]
															//FL_TCAM	0x25C: tyreTemp8_15[8]
	HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig12_CAN1);	//FR_TCAM	0x260: tyreTemp0_7[8]
															//FR_TCAM	0x264: tyreTemp8_15[8]




	HAL_CAN_ConfigFilter(&hcan2, &sFilterConfig0_CAN2);
	HAL_CAN_ConfigFilter(&hcan2, &sFilterConfig1_CAN2);


	HAL_CAN_Start(&hcan1);
	HAL_CAN_Start(&hcan2);


#if	CAN1_DATA_READ_IT_ENABLE == 1
	HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
	//HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_FULL);


#endif


}



CAR_DATA_Typedef CAR_Data = {0};

void CAR_DATA_Init(void)
{
	CAR_Data.speed.peripheric = speed_peripheric;
	CAR_Data.speed.dataAddress = speed_address;
	CAR_Data.speed.dataLength = speed_dataLength;

	CAR_Data.speed.dataId = 0;

	CAR_Data.speed.dataType = speed_dataType;

	CAR_Data.speed.floatData = 0;
	CAR_Data.speed.intData = 0;

	CAR_Data.speed.oldFloatData = 0;
	CAR_Data.speed.oldIntData = 0;

	CAR_Data.speed.gain = speed_gain;
	CAR_Data.speed.offset = speed_offset;

	CAR_Data.speed.checkEnable = speed_check;
	CAR_Data.speed.notificationEnable = speed_notification;
	CAR_Data.speed.priority = speed_priority;

	CAR_Data.speed.maxValue = speed_max;
	CAR_Data.speed.minValue = speed_min;
	CAR_Data.speed.idealValue = speed_ideal;

	CAR_Data.speed.absoluteMaxValue = speed_absoluteMax;
	CAR_Data.speed.absoluteMinValue = speed_absoluteMin;



	CAR_Data.airTemp.peripheric = airTemp_peripheric;
	CAR_Data.airTemp.dataAddress = airTemp_address;
	CAR_Data.airTemp.dataLength = airTemp_dataLength;

	CAR_Data.airTemp.dataId = 0;

	CAR_Data.airTemp.dataType = airTemp_dataType;

	CAR_Data.airTemp.floatData = 0;
	CAR_Data.airTemp.intData = 0;

	CAR_Data.airTemp.oldFloatData = 0;
	CAR_Data.airTemp.oldIntData = 0;

	CAR_Data.airTemp.gain = airTemp_gain;
	CAR_Data.airTemp.offset = airTemp_offset;

	CAR_Data.airTemp.checkEnable = airTemp_check;
	CAR_Data.airTemp.notificationEnable = airTemp_notification;
	CAR_Data.airTemp.priority = airTemp_priority;

	CAR_Data.airTemp.maxValue = airTemp_max;
	CAR_Data.airTemp.minValue = airTemp_min;
	CAR_Data.airTemp.idealValue = airTemp_ideal;

	CAR_Data.airTemp.absoluteMaxValue = airTemp_absoluteMax;
	CAR_Data.airTemp.absoluteMinValue = airTemp_absoluteMin;



	CAR_Data.gear.peripheric = gear_peripheric;
	CAR_Data.gear.dataAddress = gear_address;
	CAR_Data.gear.dataLength = gear_dataLength;

	CAR_Data.gear.dataId = gear_dataId;

	CAR_Data.gear.dataType = gear_dataType;

	CAR_Data.gear.floatData = 0;
	CAR_Data.gear.intData = 0;

	CAR_Data.gear.oldFloatData = 0;
	CAR_Data.gear.oldIntData = 0;

	CAR_Data.gear.gain = gear_gain;
	CAR_Data.gear.offset = gear_offset;

	CAR_Data.gear.checkEnable = gear_check;
	CAR_Data.gear.notificationEnable = gear_notification;
	CAR_Data.gear.priority = gear_priority;

	CAR_Data.gear.maxValue = gear_max;
	CAR_Data.gear.minValue = gear_min;
	CAR_Data.gear.idealValue = gear_ideal;

	CAR_Data.gear.absoluteMaxValue = gear_absoluteMax;
	CAR_Data.gear.absoluteMinValue = gear_absoluteMin;



	CAR_Data.brake.peripheric = brake_peripheric;
	CAR_Data.brake.dataAddress = brake_address;
	CAR_Data.brake.dataLength = brake_dataLength;

	CAR_Data.brake.dataId = brake_dataId;

	CAR_Data.brake.dataType = brake_dataType;

	CAR_Data.brake.floatData = 0;
	CAR_Data.brake.intData = 0;

	CAR_Data.brake.oldFloatData = 0;
	CAR_Data.brake.oldIntData = 0;

	CAR_Data.brake.gain = brake_gain;
	CAR_Data.brake.offset = brake_offset;

	CAR_Data.brake.checkEnable = brake_check;
	CAR_Data.brake.notificationEnable = brake_notification;
	CAR_Data.brake.priority = brake_priority;

	CAR_Data.brake.maxValue = brake_max;
	CAR_Data.brake.minValue = brake_min;
	CAR_Data.brake.idealValue = brake_ideal;

	CAR_Data.brake.absoluteMaxValue = brake_absoluteMax;
	CAR_Data.brake.absoluteMinValue = brake_absoluteMin;



	CAR_Data.brakeRear.peripheric = brakeRear_peripheric;
	CAR_Data.brakeRear.dataAddress = brakeRear_address;
	CAR_Data.brakeRear.dataLength = brakeRear_dataLength;

	CAR_Data.brakeRear.dataId = brakeRear_dataId;

	CAR_Data.brakeRear.dataType = brakeRear_dataType;

	CAR_Data.brakeRear.floatData = 0;
	CAR_Data.brakeRear.intData = 0;

	CAR_Data.brakeRear.oldFloatData = 0;
	CAR_Data.brakeRear.oldIntData = 0;

	CAR_Data.brakeRear.gain = brakeRear_gain;
	CAR_Data.brakeRear.offset = brakeRear_offset;

	CAR_Data.brakeRear.checkEnable = brakeRear_check;
	CAR_Data.brakeRear.notificationEnable = brakeRear_notification;
	CAR_Data.brakeRear.priority = brakeRear_priority;

	CAR_Data.brakeRear.maxValue = brakeRear_max;
	CAR_Data.brakeRear.minValue = brakeRear_min;
	CAR_Data.brakeRear.idealValue = brakeRear_ideal;

	CAR_Data.brakeRear.absoluteMaxValue = brakeRear_absoluteMax;
	CAR_Data.brakeRear.absoluteMinValue = brakeRear_absoluteMin;



	CAR_Data.pedal.peripheric = pedal_peripheric;
	CAR_Data.pedal.dataAddress = pedal_address;
	CAR_Data.pedal.dataLength = pedal_dataLength;

	CAR_Data.pedal.dataId = pedal_dataId;

	CAR_Data.pedal.dataType = pedal_dataType;

	CAR_Data.pedal.floatData = 0;
	CAR_Data.pedal.intData = 0;

	CAR_Data.pedal.oldFloatData = 0;
	CAR_Data.pedal.oldIntData = 0;

	CAR_Data.pedal.gain = pedal_gain;
	CAR_Data.pedal.offset = pedal_offset;

	CAR_Data.pedal.checkEnable = pedal_check;
	CAR_Data.pedal.notificationEnable = pedal_notification;
	CAR_Data.pedal.priority = pedal_priority;

	CAR_Data.pedal.maxValue = pedal_max;
	CAR_Data.pedal.minValue = pedal_min;
	CAR_Data.pedal.idealValue = pedal_ideal;

	CAR_Data.pedal.absoluteMaxValue = pedal_absoluteMax;
	CAR_Data.pedal.absoluteMinValue = pedal_absoluteMin;



	CAR_Data.steer.peripheric = steer_peripheric;
	CAR_Data.steer.dataAddress = steer_address;
	CAR_Data.steer.dataLength = steer_dataLength;

	CAR_Data.steer.dataId = steer_dataId;

	CAR_Data.steer.dataType =steer_dataType;

	CAR_Data.steer.floatData = 0;
	CAR_Data.steer.intData = 0;

	CAR_Data.steer.oldFloatData = 0;
	CAR_Data.steer.oldIntData = 0;

	CAR_Data.steer.gain = steer_gain;
	CAR_Data.steer.offset = steer_offset;

	CAR_Data.steer.checkEnable = steer_check;
	CAR_Data.steer.notificationEnable = steer_notification;
	CAR_Data.steer.priority = steer_priority;

	CAR_Data.steer.maxValue = steer_max;
	CAR_Data.steer.minValue = steer_min;
	CAR_Data.steer.idealValue = steer_ideal;

	CAR_Data.steer.absoluteMaxValue = steer_absoluteMax;
	CAR_Data.steer.absoluteMinValue = steer_absoluteMin;



	CAR_Data.rpm.peripheric = rpm_peripheric;
	CAR_Data.rpm.dataAddress = rpm_address;
	CAR_Data.rpm.dataLength = rpm_dataLength;

	CAR_Data.rpm.dataId = rpm_dataId;

	CAR_Data.rpm.dataType = rpm_dataType;

	CAR_Data.rpm.floatData = 0;
	CAR_Data.rpm.intData = 0;

	CAR_Data.rpm.oldFloatData = 0;
	CAR_Data.rpm.oldIntData = 0;

	CAR_Data.rpm.gain = rpm_gain;
	CAR_Data.rpm.offset = rpm_offset;

	CAR_Data.rpm.checkEnable = rpm_check;
	CAR_Data.rpm.notificationEnable = rpm_notification;
	CAR_Data.rpm.priority = rpm_priority;

	CAR_Data.rpm.maxValue = rpm_max;
	CAR_Data.rpm.minValue = rpm_min;
	CAR_Data.rpm.idealValue = rpm_ideal;

	CAR_Data.rpm.absoluteMaxValue = rpm_absoluteMax;
	CAR_Data.rpm.absoluteMinValue = rpm_absoluteMin;



	CAR_Data.drsStatus.peripheric = drsStatus_peripheric;
	CAR_Data.drsStatus.dataAddress = drsStatus_address;
	CAR_Data.drsStatus.dataLength = drsStatus_dataLength;

	CAR_Data.drsStatus.dataId = drsStatus_dataId;

	CAR_Data.drsStatus.dataType = drsStatus_dataType;

	CAR_Data.drsStatus.floatData = 0;
	CAR_Data.drsStatus.intData = 0;

	CAR_Data.drsStatus.oldFloatData = 0;
	CAR_Data.drsStatus.oldIntData = 0;

	CAR_Data.drsStatus.gain = drsStatus_gain;
	CAR_Data.drsStatus.offset = drsStatus_offset;

	CAR_Data.drsStatus.checkEnable = drsStatus_check;
	CAR_Data.drsStatus.notificationEnable = drsStatus_notification;
	CAR_Data.drsStatus.priority = drsStatus_priority;

	CAR_Data.drsStatus.maxValue = drsStatus_max;
	CAR_Data.drsStatus.minValue = drsStatus_min;
	CAR_Data.drsStatus.idealValue = drsStatus_ideal;

	CAR_Data.drsStatus.absoluteMaxValue = drsStatus_absoluteMax;
	CAR_Data.drsStatus.absoluteMinValue = drsStatus_absoluteMin;



	CAR_Data.tractionControl.peripheric = tractionControl_peripheric;
	CAR_Data.tractionControl.dataAddress = tractionControl_address;
	CAR_Data.tractionControl.dataLength = tractionControl_dataLength;

	CAR_Data.tractionControl.dataId = tractionControl_dataId;

	CAR_Data.tractionControl.dataType = tractionControl_dataType;

	CAR_Data.tractionControl.floatData = 0;
	CAR_Data.tractionControl.intData = 0;

	CAR_Data.tractionControl.oldFloatData = 0;
	CAR_Data.tractionControl.oldIntData = 0;

	CAR_Data.tractionControl.gain = tractionControl_gain;
	CAR_Data.tractionControl.offset = tractionControl_offset;

	CAR_Data.tractionControl.checkEnable = tractionControl_check;
	CAR_Data.tractionControl.notificationEnable = tractionControl_notification;
	CAR_Data.tractionControl.priority = tractionControl_priority;

	CAR_Data.tractionControl.maxValue = tractionControl_max;
	CAR_Data.tractionControl.minValue = tractionControl_min;
	CAR_Data.tractionControl.idealValue = tractionControl_ideal;

	CAR_Data.tractionControl.absoluteMaxValue = tractionControl_absoluteMax;
	CAR_Data.tractionControl.absoluteMinValue = tractionControl_absoluteMin;



	CAR_Data.slip.peripheric = slip_peripheric;
	CAR_Data.slip.dataAddress = slip_address;
	CAR_Data.slip.dataLength = slip_dataLength;

	CAR_Data.slip.dataId = slip_dataId;

	CAR_Data.slip.dataType = slip_dataType;

	CAR_Data.slip.floatData = 0;
	CAR_Data.slip.intData = 0;

	CAR_Data.slip.oldFloatData = 0;
	CAR_Data.slip.oldIntData = 0;

	CAR_Data.slip.gain = slip_gain;
	CAR_Data.slip.offset = slip_offset;

	CAR_Data.slip.checkEnable = slip_check;
	CAR_Data.slip.notificationEnable = slip_notification;
	CAR_Data.slip.priority = slip_priority;

	CAR_Data.slip.maxValue = slip_max;
	CAR_Data.slip.minValue = slip_min;
	CAR_Data.slip.idealValue = slip_ideal;

	CAR_Data.slip.absoluteMaxValue = slip_absoluteMax;
	CAR_Data.slip.absoluteMinValue = slip_absoluteMin;



//	CAR_Data.launchStatus.peripheric = launchStatus_peripheric;
//	CAR_Data.launchStatus.dataAddress = launchStatus_address;
//	CAR_Data.launchStatus.dataLength = launchStatus_dataLength;
//
//	CAR_Data.launchStatus.dataId = launchStatus_dataId;
//
//	CAR_Data.launchStatus.dataType = launchStatus_dataType;
//
//	CAR_Data.launchStatus.floatData = 0;
//	CAR_Data.launchStatus.intData = 0;
//
//	CAR_Data.launchStatus.oldFloatData = 0;
//	CAR_Data.launchStatus.oldIntData = 0;
//
//	CAR_Data.launchStatus.gain = launchStatus_gain;
//	CAR_Data.launchStatus.offset = launchStatus_offset;
//
//	CAR_Data.launchStatus.checkEnable = launchStatus_check;
//	CAR_Data.launchStatus.notificationEnable = launchStatus_notification;
//	CAR_Data.launchStatus.priority = launchStatus_priority;
//
//	CAR_Data.launchStatus.maxValue = launchStatus_max;
//	CAR_Data.launchStatus.minValue = launchStatus_min;
//	CAR_Data.launchStatus.idealValue = launchStatus_ideal;
//
//	CAR_Data.launchStatus.absoluteMaxValue = launchStatus_absoluteMax;
//	CAR_Data.launchStatus.absoluteMinValue = launchStatus_absoluteMin;



	CAR_Data.map.peripheric = map_peripheric;
	CAR_Data.map.dataAddress = map_address;
	CAR_Data.map.dataLength = map_dataLength;

	CAR_Data.map.dataId = map_dataId;

	CAR_Data.map.dataType = map_dataType;

	CAR_Data.map.floatData = 0;
	CAR_Data.map.intData = 0;

	CAR_Data.map.oldFloatData = 0;
	CAR_Data.map.oldIntData = 0;

	CAR_Data.map.gain = map_gain;
	CAR_Data.map.offset = map_offset;

	CAR_Data.map.checkEnable = map_check;
	CAR_Data.map.notificationEnable = map_notification;
	CAR_Data.map.priority = map_priority;

	CAR_Data.map.maxValue = map_max;
	CAR_Data.map.minValue = map_min;
	CAR_Data.map.idealValue = map_ideal;

	CAR_Data.map.absoluteMaxValue = map_absoluteMax;
	CAR_Data.map.absoluteMinValue = map_absoluteMin;






	CAR_Data.oilPressure.peripheric = oilPressure_peripheric;
	CAR_Data.oilPressure.dataAddress = oilPressure_address;
	CAR_Data.oilPressure.dataLength = oilPressure_dataLength;

	CAR_Data.oilPressure.dataId = oilPressure_dataId;

	CAR_Data.oilPressure.dataType = oilPressure_dataType;

	CAR_Data.oilPressure.floatData = 0;
	CAR_Data.oilPressure.intData = 0;

	CAR_Data.oilPressure.oldFloatData = 0;
	CAR_Data.oilPressure.oldIntData = 0;

	CAR_Data.oilPressure.gain = oilPressure_gain;
	CAR_Data.oilPressure.offset = oilPressure_offset;

	CAR_Data.oilPressure.checkEnable = oilPressure_check;
	CAR_Data.oilPressure.notificationEnable = oilPressure_notification;
	CAR_Data.oilPressure.priority = oilPressure_priority;

	CAR_Data.oilPressure.maxValue = oilPressure_max;
	CAR_Data.oilPressure.minValue = oilPressure_min;
	CAR_Data.oilPressure.idealValue = oilPressure_ideal;

	CAR_Data.oilPressure.absoluteMaxValue = oilPressure_absoluteMax;
	CAR_Data.oilPressure.absoluteMinValue = oilPressure_absoluteMin;



	CAR_Data.fuelPressure.peripheric = fuelPressure_peripheric;
	CAR_Data.fuelPressure.dataAddress = fuelPressure_address;
	CAR_Data.fuelPressure.dataLength = fuelPressure_dataLength;

	CAR_Data.fuelPressure.dataId = fuelPressure_dataId;

	CAR_Data.fuelPressure.dataType = fuelPressure_dataType;

	CAR_Data.fuelPressure.floatData = 0;
	CAR_Data.fuelPressure.intData = 0;

	CAR_Data.fuelPressure.oldFloatData = 0;
	CAR_Data.fuelPressure.oldIntData = 0;

	CAR_Data.fuelPressure.gain = fuelPressure_gain;
	CAR_Data.fuelPressure.offset = fuelPressure_offset;

	CAR_Data.fuelPressure.checkEnable = fuelPressure_check;
	CAR_Data.fuelPressure.notificationEnable = fuelPressure_notification;
	CAR_Data.fuelPressure.priority = fuelPressure_priority;

	CAR_Data.fuelPressure.maxValue = fuelPressure_max;
	CAR_Data.fuelPressure.minValue = fuelPressure_min;
	CAR_Data.fuelPressure.idealValue = fuelPressure_ideal;

	CAR_Data.fuelPressure.absoluteMaxValue = fuelPressure_absoluteMax;
	CAR_Data.fuelPressure.absoluteMinValue = fuelPressure_absoluteMin;



	CAR_Data.tps.peripheric = tps_peripheric;
	CAR_Data.tps.dataAddress = tps_address;
	CAR_Data.tps.dataLength = tps_dataLength;

	CAR_Data.tps.dataId = tps_dataId;

	CAR_Data.tps.dataType = tps_dataType;

	CAR_Data.tps.floatData = 0;
	CAR_Data.tps.intData = 0;

	CAR_Data.tps.oldFloatData = 0;
	CAR_Data.tps.oldIntData = 0;

	CAR_Data.tps.gain = tps_gain;
	CAR_Data.tps.offset = tps_offset;

	CAR_Data.tps.checkEnable = tps_check;
	CAR_Data.tps.notificationEnable = tps_notification;
	CAR_Data.tps.priority = tps_priority;

	CAR_Data.tps.maxValue = tps_max;
	CAR_Data.tps.minValue = tps_min;
	CAR_Data.tps.idealValue = tps_ideal;

	CAR_Data.tps.absoluteMaxValue = tps_absoluteMax;
	CAR_Data.tps.absoluteMinValue = tps_absoluteMin;



	CAR_Data.waterTemp.peripheric = waterTemp_peripheric;
	CAR_Data.waterTemp.dataAddress = waterTemp_address;
	CAR_Data.waterTemp.dataLength = waterTemp_dataLength;

	CAR_Data.waterTemp.dataId = waterTemp_dataId;

	CAR_Data.waterTemp.dataType = waterTemp_dataType;

	CAR_Data.waterTemp.floatData = 0;
	CAR_Data.waterTemp.intData = 0;

	CAR_Data.waterTemp.oldFloatData = 0;
	CAR_Data.waterTemp.oldIntData = 0;

	CAR_Data.waterTemp.gain = waterTemp_gain;
	CAR_Data.waterTemp.offset = waterTemp_offset;

	CAR_Data.waterTemp.checkEnable = waterTemp_check;
	CAR_Data.waterTemp.notificationEnable = waterTemp_notification;
	CAR_Data.waterTemp.priority = waterTemp_priority;

	CAR_Data.waterTemp.maxValue = waterTemp_max;
	CAR_Data.waterTemp.minValue = waterTemp_min;
	CAR_Data.waterTemp.idealValue = waterTemp_ideal;

	CAR_Data.waterTemp.absoluteMaxValue = waterTemp_absoluteMax;
	CAR_Data.waterTemp.absoluteMinValue = waterTemp_absoluteMin;



	CAR_Data.oilTemp.peripheric = oilTemp_peripheric;
	CAR_Data.oilTemp.dataAddress = oilTemp_address;
	CAR_Data.oilTemp.dataLength = oilTemp_dataLength;

	CAR_Data.oilTemp.dataId = oilTemp_dataId;

	CAR_Data.oilTemp.dataType = oilTemp_dataType;

	CAR_Data.oilTemp.floatData = 0;
	CAR_Data.oilTemp.intData = 0;

	CAR_Data.oilTemp.oldFloatData = 0;
	CAR_Data.oilTemp.oldIntData = 0;

	CAR_Data.oilTemp.gain = oilTemp_gain;
	CAR_Data.oilTemp.offset = oilTemp_offset;

	CAR_Data.oilTemp.checkEnable = oilTemp_check;
	CAR_Data.oilTemp.notificationEnable = oilTemp_notification;
	CAR_Data.oilTemp.priority = oilTemp_priority;

	CAR_Data.oilTemp.maxValue = oilTemp_max;
	CAR_Data.oilTemp.minValue = oilTemp_min;
	CAR_Data.oilTemp.idealValue = oilTemp_ideal;

	CAR_Data.oilTemp.absoluteMaxValue = oilTemp_absoluteMax;
	CAR_Data.oilTemp.absoluteMinValue = oilTemp_absoluteMin;



	CAR_Data.fuelTemp.peripheric = fuelTemp_peripheric;
	CAR_Data.fuelTemp.dataAddress = fuelTemp_address;
	CAR_Data.fuelTemp.dataLength = fuelTemp_dataLength;

	CAR_Data.fuelTemp.dataId = fuelTemp_dataId;

	CAR_Data.fuelTemp.dataType = fuelTemp_dataType;

	CAR_Data.fuelTemp.floatData = 0;
	CAR_Data.fuelTemp.intData = 0;

	CAR_Data.fuelTemp.oldFloatData = 0;
	CAR_Data.fuelTemp.oldIntData = 0;

	CAR_Data.fuelTemp.gain = fuelTemp_gain;
	CAR_Data.fuelTemp.offset = fuelTemp_offset;

	CAR_Data.fuelTemp.checkEnable = fuelTemp_check;
	CAR_Data.fuelTemp.notificationEnable = fuelTemp_notification;
	CAR_Data.fuelTemp.priority = fuelTemp_priority;

	CAR_Data.fuelTemp.maxValue = fuelTemp_max;
	CAR_Data.fuelTemp.minValue = fuelTemp_min;
	CAR_Data.fuelTemp.idealValue = fuelTemp_ideal;

	CAR_Data.fuelTemp.absoluteMaxValue = fuelTemp_absoluteMax;
	CAR_Data.fuelTemp.absoluteMinValue = fuelTemp_absoluteMin;



	CAR_Data.batteryVoltage.peripheric = batteryVoltage_peripheric;
	CAR_Data.batteryVoltage.dataAddress = batteryVoltage_address;
	CAR_Data.batteryVoltage.dataLength = batteryVoltage_dataLength;

	CAR_Data.batteryVoltage.dataId = batteryVoltage_dataId;

	CAR_Data.batteryVoltage.dataType = batteryVoltage_dataType;

	CAR_Data.batteryVoltage.floatData = 0;
	CAR_Data.batteryVoltage.intData = 0;

	CAR_Data.batteryVoltage.oldFloatData = 0;
	CAR_Data.batteryVoltage.oldIntData = 0;

	CAR_Data.batteryVoltage.gain = batteryVoltage_gain;
	CAR_Data.batteryVoltage.offset = batteryVoltage_offset;

	CAR_Data.batteryVoltage.checkEnable = batteryVoltage_check;
	CAR_Data.batteryVoltage.notificationEnable = batteryVoltage_notification;
	CAR_Data.batteryVoltage.priority = batteryVoltage_priority;

	CAR_Data.batteryVoltage.maxValue = batteryVoltage_max;
	CAR_Data.batteryVoltage.minValue = batteryVoltage_min;
	CAR_Data.batteryVoltage.idealValue = batteryVoltage_ideal;

	CAR_Data.batteryVoltage.absoluteMaxValue = batteryVoltage_absoluteMax;
	CAR_Data.batteryVoltage.absoluteMinValue = batteryVoltage_absoluteMin;







	CAR_Data.BSPD_status_can.peripheric = 0;
	CAR_Data.BSPD_status_can.dataAddress = 0;
	CAR_Data.BSPD_status_can.dataLength = 0;

	CAR_Data.BSPD_status_can.dataId = dataIdUnused;

	CAR_Data.BSPD_status_can.dataType = dataType_Int;

	CAR_Data.BSPD_status_can.floatData = 0;
	CAR_Data.BSPD_status_can.intData = 0;

	CAR_Data.BSPD_status_can.oldFloatData = 0;
	CAR_Data.BSPD_status_can.oldIntData = 0;

	CAR_Data.BSPD_status_can.gain = 0;
	CAR_Data.BSPD_status_can.offset = 0;

	CAR_Data.BSPD_status_can.checkEnable = dataCheck_Enabled;
	CAR_Data.BSPD_status_can.notificationEnable = dataNotification_Enabled;
	CAR_Data.BSPD_status_can.priority = 0;

	CAR_Data.BSPD_status_can.maxValue = 0;
	CAR_Data.BSPD_status_can.minValue = -1;
	CAR_Data.BSPD_status_can.idealValue = 0;

	CAR_Data.BSPD_status_can.absoluteMaxValue = noDataLimit;
	CAR_Data.BSPD_status_can.absoluteMinValue = noDataLimit;




	CAR_Data.waterPumpStatus.peripheric = 0;
	CAR_Data.waterPumpStatus.dataAddress = 0;
	CAR_Data.waterPumpStatus.dataLength = 0;

	CAR_Data.waterPumpStatus.dataId = dataIdUnused;

	CAR_Data.waterPumpStatus.dataType = dataType_Int;

	CAR_Data.waterPumpStatus.floatData = 0;
	CAR_Data.waterPumpStatus.intData = 0;

	CAR_Data.waterPumpStatus.oldFloatData = 0;
	CAR_Data.waterPumpStatus.oldIntData = 0;

	CAR_Data.waterPumpStatus.gain = 0;
	CAR_Data.waterPumpStatus.offset = 0;

	CAR_Data.waterPumpStatus.checkEnable = dataCheck_Enabled;
	CAR_Data.waterPumpStatus.notificationEnable = dataNotification_Enabled;
	CAR_Data.waterPumpStatus.priority = 0;

	CAR_Data.waterPumpStatus.maxValue = 1;
	CAR_Data.waterPumpStatus.minValue = 1;
	CAR_Data.waterPumpStatus.idealValue = 0;

	CAR_Data.waterPumpStatus.absoluteMaxValue = noDataLimit;
	CAR_Data.waterPumpStatus.absoluteMinValue = noDataLimit;


	CAR_Data.lastAccelerationTime = 0;
	CAR_Data.bestAccelerationTime = 0;

}



#if CAN1_DATA_READ_IT_ENABLE == 1

volatile uint32_t can1RxCallBackCounter = 0;

void HAL_CAN_RxFifoMsgPendingCallBack(CAN_HandleTypeDef *hcan)
{
	if(hcan->Instance == CAN1)
	{
		//CAN1_DATA_Read();
		can1RxCallBackCounter++;
	}
}


#endif


void CAR_DATA_Read(void)
{
#if CAN1_DATA_READ_IT_ENABLE == 0 && (DEBUG_MODE == 0 || DEBUG_MODE == 2)
	CAN1_DATA_Read();
#endif

	//FIFO1 CAN2
	while (HAL_CAN_GetRxFifoFillLevel(&hcan2, CAN_RX_FIFO1) > 0)
	{
		HAL_CAN_GetRxMessage(&hcan2, CAN_RX_FIFO1, &pRxHeader_CAN2, dataRX_CAN2);

		if (pRxHeader_CAN2.StdId == 0x308)
		{
			dataRX_SAVED[0]=dataRX_CAN2[4];
			dataRX_SAVED[1]=dataRX_CAN2[5];
			//speed *=-0.143693;
			//speed+=212.594;
		}

		if (pRxHeader_CAN2.StdId == 0x174)
		{
			//TxData_CAN2[0]=dataRX_CAN2[5];//y
			//TxData_CAN2[1]=dataRX_CAN2[4];
			//TxData_CAN2[2]=dataRX_CAN2[1];//yaw
			//TxData_CAN2[3]=dataRX_CAN2[0];

			dataRX_SAVED[2]=dataRX_CAN2[5];
			dataRX_SAVED[3]=dataRX_CAN2[4];//Y
			//HAL_CAN_AddTxMessage(&hcan2, &pHeader_CAN2, TxData_CAN2, &TxMailbox_CAN2);
		}
	}


	GPIO_IN_Read();
}


void GPIO_IN_Read(void)
{

	static uint8_t initFlag = 0;

	static GPIO_EdgeTypeDef DIG1;

	if(initFlag == 0)
	{
		DIG1.GPIOx = DIG1_F_GPIO_Port;
		DIG1.GPIO_Pin = DIG1_F_Pin;
		DIG1.delay = 100;
	}


	CAR_Data.waterPumpStatus.oldTimeData = CAR_Data.waterPumpStatus.lastTimeData;
	CAR_Data.waterPumpStatus.oldIntData = CAR_Data.waterPumpStatus.intData;
	CAR_Data.waterPumpStatus.oldFloatData = CAR_Data.waterPumpStatus.floatData;

	//if(HAL_GPIO_ReadPin(DIG1_F_GPIO_Port, DIG1_F_Pin))
	if(GPIO_AdvancedRead(&DIG1) == GPIO_HIGH)
	{
		CAR_Data.waterPumpStatus.intData = 1;
		CAR_Data.waterPumpStatus.floatData = 1;
	}
	else
	{
		CAR_Data.waterPumpStatus.intData = 0;
		CAR_Data.waterPumpStatus.floatData = 0;
	}

	CAR_Data.waterPumpStatus.lastTimeData = millis;
}



void CAN1_DATA_Read(void)
{
	uint8_t debugDataDone = 0;

	//FIFO 0
	while (HAL_CAN_GetRxFifoFillLevel(&hcan1, CAN_RX_FIFO0) > 0 || (DEBUG_MODE == 2 && debugDataDone == 0))
	{
		debugDataDone = 1;

		if(DEBUG_MODE == 2)
			canDataGenerationForDebug();
		else
			HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &pRxHeader_CAN1, RxData_CAN1);

		CAR_Data.canLastReceiveTime = millis;

		int32_t tempDataInt = 0;
		float 	tempDataFloat = 0;
		uint8_t tempDataInRange = 0;

		if (pRxHeader_CAN1.StdId == 0x200)
		{
			tWater = (float) (RxData_CAN1[4] << 8 | RxData_CAN1[5]) / 10;

			if (tWater > 299)
				tWater = 299;

			//CAR_Data.waterTemp.floatData = tWater;

			rpm = (RxData_CAN1[0] << 8 | RxData_CAN1[1]);

			tps = (float) (RxData_CAN1[2] << 8 | RxData_CAN1[3]) / 10;

			if (tps > 199)
				tps = 199;

			//CAR_Data.tps.intData = tps;

			pOil = (float) (RxData_CAN1[6] << 8 | RxData_CAN1[7]) / 1000;
			if (pOil > 19)
				pOil = 0;


			CAR_Data.waterTemp.oldIntData = CAR_Data.waterTemp.intData;
			CAR_Data.waterTemp.oldFloatData = CAR_Data.waterTemp.floatData;
			CAR_Data.waterTemp.oldTimeData = CAR_Data.waterTemp.lastTimeData;

			if(CAR_Data.waterTemp.dataType == dataType_Int)
			{
				tempDataInt = ((int32_t)((int8_t)RxData_CAN1[4] << 8 | (uint8_t)RxData_CAN1[5])) * CAR_Data.waterTemp.gain + CAR_Data.waterTemp.offset;

				if(
						(CAR_Data.waterTemp.absoluteMaxValue == noDataLimit || tempDataInt <= CAR_Data.waterTemp.absoluteMaxValue) &&
						(CAR_Data.waterTemp.absoluteMinValue == noDataLimit || tempDataInt >= CAR_Data.waterTemp.absoluteMinValue)
					)
				{
					CAR_Data.waterTemp.intData = tempDataInt;
					CAR_Data.waterTemp.floatData = CAR_Data.waterTemp.intData;

					tempDataInRange = 1;
				}
				else
					tempDataInRange = 0;
			}
			else
			{
				tempDataFloat = (float) ((int32_t)((int8_t)RxData_CAN1[4] << 8 | (uint8_t)RxData_CAN1[5])) * CAR_Data.waterTemp.gain + CAR_Data.waterTemp.offset;

				if(
						(CAR_Data.waterTemp.absoluteMaxValue == noDataLimit || tempDataInt <= CAR_Data.waterTemp.absoluteMaxValue) &&
						(CAR_Data.waterTemp.absoluteMinValue == noDataLimit || tempDataInt >= CAR_Data.waterTemp.absoluteMinValue)
					)
				{
					CAR_Data.waterTemp.floatData = tempDataFloat;
					CAR_Data.waterTemp.intData = CAR_Data.waterTemp.floatData;

					tempDataInRange = 1;
				}
				else
					tempDataInRange = 0;
			}

			if(tempDataInRange == 1)
				CAR_Data.waterTemp.lastTimeData = millis;



			CAR_Data.rpm.oldIntData = CAR_Data.rpm.intData;
			CAR_Data.rpm.oldFloatData = CAR_Data.rpm.floatData;
			CAR_Data.rpm.oldTimeData = CAR_Data.rpm.lastTimeData;

			if(CAR_Data.rpm.dataType == dataType_Int)
			{
				CAR_Data.rpm.intData = ((int32_t)((int8_t)RxData_CAN1[0] << 8 | (uint8_t)RxData_CAN1[1])) * CAR_Data.rpm.gain + CAR_Data.rpm.offset;
				CAR_Data.rpm.floatData = CAR_Data.rpm.intData;
			}
			else
			{
				CAR_Data.rpm.floatData = (float) ((int32_t)((int8_t)RxData_CAN1[0] << 8 | (uint8_t)RxData_CAN1[1])) * CAR_Data.rpm.gain + CAR_Data.rpm.offset;
				CAR_Data.rpm.intData = CAR_Data.rpm.floatData;
			}
			CAR_Data.rpm.lastTimeData = millis;



			CAR_Data.tps.oldIntData = CAR_Data.tps.intData;
			CAR_Data.tps.oldFloatData = CAR_Data.tps.floatData;
			CAR_Data.tps.oldTimeData = CAR_Data.tps.lastTimeData;

			if(CAR_Data.tps.dataType == dataType_Int)
			{
				CAR_Data.tps.intData = ((int32_t)((int8_t)RxData_CAN1[2] << 8 | (uint8_t)RxData_CAN1[3])) * CAR_Data.tps.gain + CAR_Data.tps.offset;
				CAR_Data.tps.floatData = CAR_Data.tps.intData;
			}
			else
			{
				CAR_Data.tps.floatData = (float) ((int32_t)((int8_t)RxData_CAN1[2] << 8 | (uint8_t)RxData_CAN1[3])) * CAR_Data.tps.gain + CAR_Data.tps.offset;
				CAR_Data.tps.intData = CAR_Data.tps.floatData;
			}
			CAR_Data.tps.lastTimeData = millis;


			float tmpOilPressure = ((float) ((int32_t)((int8_t)RxData_CAN1[6] << 8 | (uint8_t)RxData_CAN1[7])) * CAR_Data.oilPressure.gain + CAR_Data.oilPressure.offset);

			if(tmpOilPressure <= CAR_Data.oilPressure.absoluteMaxValue)
			{
				CAR_Data.oilPressure.oldIntData = CAR_Data.oilPressure.intData;
				CAR_Data.oilPressure.oldFloatData = CAR_Data.oilPressure.floatData;
				CAR_Data.oilPressure.oldTimeData = CAR_Data.oilPressure.lastTimeData;

				if(CAR_Data.oilPressure.dataType == dataType_Int)
				{
					CAR_Data.oilPressure.intData = ((int32_t)((int8_t)RxData_CAN1[6] << 8 | (uint8_t)RxData_CAN1[7])) * CAR_Data.oilPressure.gain + CAR_Data.oilPressure.offset;
					CAR_Data.oilPressure.floatData = CAR_Data.oilPressure.intData;
				}
				else
				{
					CAR_Data.oilPressure.floatData = (float) ((int32_t)((int8_t)RxData_CAN1[6] << 8 | (uint8_t)RxData_CAN1[7])) * CAR_Data.oilPressure.gain + CAR_Data.oilPressure.offset;
					CAR_Data.oilPressure.intData = CAR_Data.oilPressure.floatData;
				}
				CAR_Data.oilPressure.lastTimeData = millis;
			}
		}

		if (pRxHeader_CAN1.StdId == 0x204)
		{
			vBat = (float) ((int32_t)((int8_t)RxData_CAN1[6] << 8 | (uint8_t)RxData_CAN1[7])) / 1000;

			if (vBat > 19)
				vBat = 19;

			//CAR_Data.batteryVoltage.floatData = vBat;

			gear = RxData_CAN1[4];

			//CAR_Data.gear.intData = gear;

			tOil = (float) ((int32_t)((int8_t)RxData_CAN1[0] << 8 | (uint8_t)RxData_CAN1[1])) / 10;

			if (tOil > 199)
				tOil = 199;


			CAR_Data.batteryVoltage.oldIntData = CAR_Data.batteryVoltage.intData;
			CAR_Data.batteryVoltage.oldFloatData = CAR_Data.batteryVoltage.floatData;
			CAR_Data.batteryVoltage.oldTimeData = CAR_Data.batteryVoltage.lastTimeData;

			if(CAR_Data.batteryVoltage.dataType == dataType_Int)
			{
				CAR_Data.batteryVoltage.intData = ((int32_t)((int8_t)RxData_CAN1[6] << 8 | (uint8_t)RxData_CAN1[7])) * CAR_Data.batteryVoltage.gain + CAR_Data.batteryVoltage.offset;
				CAR_Data.batteryVoltage.floatData = CAR_Data.batteryVoltage.intData;
			}
			else
			{
				CAR_Data.batteryVoltage.floatData = (float) ((int32_t)((int8_t)RxData_CAN1[6] << 8 | (uint8_t)RxData_CAN1[7])) * CAR_Data.batteryVoltage.gain + CAR_Data.batteryVoltage.offset;
				CAR_Data.batteryVoltage.intData = CAR_Data.batteryVoltage.floatData;
			}
			CAR_Data.batteryVoltage.lastTimeData = millis;


			CAR_Data.gear.oldIntData = CAR_Data.gear.intData;
			CAR_Data.gear.oldFloatData = CAR_Data.gear.floatData;
			CAR_Data.gear.oldTimeData = CAR_Data.gear.lastTimeData;

			if(CAR_Data.gear.dataType == dataType_Int)
			{
				CAR_Data.gear.intData = ((int32_t)(RxData_CAN1[4])) * CAR_Data.gear.gain + CAR_Data.gear.offset;
				CAR_Data.gear.floatData = CAR_Data.gear.intData;
			}
			else
			{
				CAR_Data.gear.floatData = (float) ((int32_t)(RxData_CAN1[4])) * CAR_Data.gear.gain + CAR_Data.gear.offset;
				CAR_Data.gear.intData = CAR_Data.gear.floatData;
			}
			CAR_Data.gear.lastTimeData = millis;




			CAR_Data.oilTemp.oldIntData = CAR_Data.oilTemp.intData;
			CAR_Data.oilTemp.oldFloatData = CAR_Data.oilTemp.floatData;
			CAR_Data.oilTemp.oldTimeData = CAR_Data.oilTemp.lastTimeData;

			if(CAR_Data.oilTemp.dataType == dataType_Int)
			{
				CAR_Data.oilTemp.intData = ((int32_t)((int8_t)RxData_CAN1[0] << 8 | (uint8_t)RxData_CAN1[1])) * CAR_Data.oilTemp.gain + CAR_Data.oilTemp.offset;
				CAR_Data.oilTemp.floatData = CAR_Data.oilTemp.intData;
			}
			else
			{
				CAR_Data.oilTemp.floatData = (float) ((int32_t)((int8_t)RxData_CAN1[0] << 8 | (uint8_t)RxData_CAN1[1])) * CAR_Data.oilTemp.gain + CAR_Data.oilTemp.offset;
				CAR_Data.oilTemp.intData = CAR_Data.oilTemp.floatData;
			}
			CAR_Data.oilTemp.lastTimeData = millis;
		}

		if (pRxHeader_CAN1.StdId == 0x220)
		{
			launchControlStatus = RxData_CAN1[3];

			if (launchControlStatus >= 2 && launchControlStatus <= 4)
				launchControlStatus = 1;
			else
				launchControlStatus = 0;
		}

		if (pRxHeader_CAN1.StdId == 0x208)
		{
			tAir = (float) ((int32_t)((int8_t)RxData_CAN1[4] << 8 | (uint8_t)RxData_CAN1[5])) / 10;

			if (tAir > 199)	tAir = 199;

			CAR_Data.airTemp.oldIntData = CAR_Data.airTemp.intData;
			CAR_Data.airTemp.oldFloatData = CAR_Data.airTemp.floatData;
			CAR_Data.airTemp.oldTimeData = CAR_Data.airTemp.lastTimeData;

			if(CAR_Data.airTemp.dataType == dataType_Int)
			{
				CAR_Data.airTemp.intData = ((int32_t)((int8_t)RxData_CAN1[4] << 8 | (uint8_t)RxData_CAN1[5])) * CAR_Data.airTemp.gain + CAR_Data.airTemp.offset;
				CAR_Data.airTemp.floatData = CAR_Data.airTemp.intData;
			}
			else
			{
				CAR_Data.airTemp.floatData = (float) ((int32_t)((int8_t)RxData_CAN1[4] << 8 | (uint8_t)RxData_CAN1[5])) * CAR_Data.airTemp.gain + CAR_Data.airTemp.offset;
				CAR_Data.airTemp.intData = CAR_Data.airTemp.floatData;
			}
			CAR_Data.airTemp.lastTimeData = millis;



			//pFuel = (float) (RxData_CAN1[2] << 8 | RxData_CAN1[3]) / 1000;

			tempDataFloat = (float) ((int32_t)((int8_t)RxData_CAN1[2] << 8 | (uint8_t)RxData_CAN1[3])) / 1000;

			if(tempDataFloat <= CAR_Data.fuelPressure.absoluteMaxValue)
				pFuel = tempDataFloat;


			float tmpfuelPressure = ((float) ((uint32_t)((int8_t)RxData_CAN1[2] << 8 | (uint8_t)RxData_CAN1[3])) * CAR_Data.fuelPressure.gain + CAR_Data.fuelPressure.offset);

			if(tmpfuelPressure <= CAR_Data.fuelPressure.absoluteMaxValue)
			{
				CAR_Data.fuelPressure.oldIntData = CAR_Data.fuelPressure.intData;
				CAR_Data.fuelPressure.oldFloatData = CAR_Data.fuelPressure.floatData;
				CAR_Data.fuelPressure.oldTimeData = CAR_Data.fuelPressure.lastTimeData;


				if(CAR_Data.fuelPressure.dataType == dataType_Int)
				{
					CAR_Data.fuelPressure.intData = ((int32_t)((int8_t)RxData_CAN1[2] << 8 | (uint8_t)RxData_CAN1[3])) * CAR_Data.fuelPressure.gain + CAR_Data.fuelPressure.offset;
					CAR_Data.fuelPressure.floatData = CAR_Data.fuelPressure.intData;
				}
				else
				{
					CAR_Data.fuelPressure.floatData = (float) ((int32_t)((int8_t)RxData_CAN1[2] << 8 | (uint8_t)RxData_CAN1[3])) * CAR_Data.fuelPressure.gain + CAR_Data.fuelPressure.offset;
					CAR_Data.fuelPressure.intData = CAR_Data.fuelPressure.floatData;
				}

				CAR_Data.fuelPressure.lastTimeData = millis;
			}
		}

		if (pRxHeader_CAN1.StdId == 0x20C)
		{
			pedal = (float) ((int8_t) RxData_CAN1[0]); //signed byte (va da 0 a 100 senza decimali)

			CAR_Data.pedal.oldIntData = CAR_Data.pedal.intData;
			CAR_Data.pedal.oldFloatData = CAR_Data.pedal.floatData;
			CAR_Data.pedal.oldTimeData = CAR_Data.pedal.lastTimeData;

			if(CAR_Data.pedal.dataType == dataType_Int)
			{
				CAR_Data.pedal.intData = ((int32_t)(RxData_CAN1[0])) * CAR_Data.pedal.gain + CAR_Data.pedal.offset;
				CAR_Data.pedal.floatData = CAR_Data.pedal.intData;
			}
			else
			{
				CAR_Data.pedal.floatData = (float) ((int32_t)(RxData_CAN1[0])) * CAR_Data.pedal.gain + CAR_Data.pedal.offset;
				CAR_Data.pedal.intData = CAR_Data.pedal.floatData;
			}
			CAR_Data.pedal.lastTimeData = millis;


			slip = RxData_CAN1[1];

			CAR_Data.slip.oldIntData = CAR_Data.slip.intData;
			CAR_Data.slip.oldFloatData = CAR_Data.slip.floatData;
			CAR_Data.slip.oldTimeData = CAR_Data.slip.lastTimeData;

			if(CAR_Data.slip.dataType == dataType_Int)
			{
				CAR_Data.slip.intData = ((int32_t)(RxData_CAN1[1])) * CAR_Data.slip.gain + CAR_Data.slip.offset;
				CAR_Data.slip.floatData = CAR_Data.slip.intData;
			}
			else
			{
				CAR_Data.slip.floatData = (float) ((int32_t)(RxData_CAN1[1])) * CAR_Data.slip.gain + CAR_Data.slip.offset;
				CAR_Data.slip.intData = CAR_Data.slip.floatData;
			}
			CAR_Data.slip.lastTimeData = millis;



			speed = (float) ((int32_t)((int8_t)RxData_CAN1[2] << 8 | (uint8_t)RxData_CAN1[3])) / 10;// è SPEED

			CAR_Data.speed.oldIntData = CAR_Data.speed.intData;
			CAR_Data.speed.oldFloatData = CAR_Data.speed.floatData;
			CAR_Data.speed.oldTimeData = CAR_Data.speed.lastTimeData;

			if(CAR_Data.speed.dataType == dataType_Int)
			{
				CAR_Data.speed.intData = ((int32_t)((int8_t)RxData_CAN1[2] << 8 | (uint8_t)RxData_CAN1[3])) * CAR_Data.speed.gain + CAR_Data.speed.offset;
				CAR_Data.speed.floatData = CAR_Data.speed.intData;
			}
			else
			{
				CAR_Data.speed.floatData = (float) ((int32_t)((int8_t)RxData_CAN1[2] << 8 | (uint8_t)RxData_CAN1[3])) * CAR_Data.speed.gain + CAR_Data.speed.offset;
				CAR_Data.speed.intData = CAR_Data.speed.floatData;
			}
			CAR_Data.speed.lastTimeData = millis;



			//brake = (float) ((int8_t)RxData_CAN1[4]);
			brake = ((int8_t)RxData_CAN1[4]);

			CAR_Data.brake.oldIntData = CAR_Data.brake.intData;
			CAR_Data.brake.oldFloatData = CAR_Data.brake.floatData;
			CAR_Data.brake.oldTimeData = CAR_Data.brake.lastTimeData;

			if(CAR_Data.brake.dataType == dataType_Int)
			{
				CAR_Data.brake.intData = ((int32_t)(RxData_CAN1[4])) * CAR_Data.brake.gain + CAR_Data.brake.offset;
				CAR_Data.brake.floatData = CAR_Data.brake.intData;
			}
			else
			{
				CAR_Data.brake.floatData = (float) ((int32_t)(RxData_CAN1[4])) * CAR_Data.brake.gain + CAR_Data.brake.offset;
				CAR_Data.brake.intData = CAR_Data.brake.floatData;
			}
			CAR_Data.brake.lastTimeData = millis;


		}

		if (pRxHeader_CAN1.StdId == 0x321) //DATA FROM DRS
		{
			uint16_t drsTarget = ((int8_t)RxData_CAN1[4] << 8 | (uint8_t)RxData_CAN1[5]);

			if (drsTarget >= 1000)
			//if (drsTarget != 0)
				drsStatus = 1;
			else
				drsStatus = 0;


			CAR_Data.drsStatus.oldIntData = CAR_Data.drsStatus.intData;
			CAR_Data.drsStatus.oldFloatData = CAR_Data.drsStatus.floatData;
			CAR_Data.drsStatus.oldTimeData = CAR_Data.drsStatus.lastTimeData;

			if (drsTarget >= 1000)
			{
				CAR_Data.drsStatus.intData = 1;
				CAR_Data.drsStatus.floatData = 1;
			}
			else
			{
				CAR_Data.drsStatus.intData = 0;
				CAR_Data.drsStatus.floatData = 0;
			}

			CAR_Data.drsStatus.lastTimeData = millis;
		}



		if(pRxHeader_CAN1.StdId == 0x30C)
		{
			CAR_Data.brakeRear.oldIntData = CAR_Data.brakeRear.intData;
			CAR_Data.brakeRear.oldFloatData = CAR_Data.brakeRear.floatData;
			CAR_Data.brakeRear.oldTimeData = CAR_Data.brakeRear.lastTimeData;

			if(CAR_Data.brakeRear.dataType == dataType_Int)
			{
				CAR_Data.brakeRear.intData = ((int32_t)((int8_t)RxData_CAN1[0] << 8 | (uint8_t)RxData_CAN1[1])) * CAR_Data.brakeRear.gain + CAR_Data.brakeRear.offset;
				CAR_Data.brakeRear.floatData = CAR_Data.brakeRear.intData;
			}
			else
			{
				CAR_Data.brakeRear.floatData = (float) ((int32_t)((int8_t)RxData_CAN1[0] << 8 | (uint8_t)RxData_CAN1[1])) * CAR_Data.brakeRear.gain + CAR_Data.brakeRear.offset;
				CAR_Data.brakeRear.intData = CAR_Data.brakeRear.floatData;
			}
			CAR_Data.brakeRear.lastTimeData = millis;
		}


		if(pRxHeader_CAN1.StdId == 0x312)
		{
			CAR_Data.fuelTemp.oldIntData = CAR_Data.fuelTemp.intData;
			CAR_Data.fuelTemp.oldFloatData = CAR_Data.fuelTemp.floatData;
			CAR_Data.fuelTemp.oldTimeData = CAR_Data.fuelTemp.lastTimeData;

			if(CAR_Data.fuelTemp.dataType == dataType_Int)
			{
				CAR_Data.fuelTemp.intData = ((int32_t)((int8_t)RxData_CAN1[0] << 8 | (uint8_t)RxData_CAN1[1])) * CAR_Data.fuelTemp.gain + CAR_Data.fuelTemp.offset;
				CAR_Data.fuelTemp.floatData = CAR_Data.fuelTemp.intData;
			}
			else
			{
				CAR_Data.fuelTemp.floatData = (float) ((int32_t)((int8_t)RxData_CAN1[0] << 8 | (uint8_t)RxData_CAN1[1])) * CAR_Data.fuelTemp.gain + CAR_Data.fuelTemp.offset;
				CAR_Data.fuelTemp.intData = CAR_Data.fuelTemp.floatData;
			}
			CAR_Data.fuelTemp.lastTimeData = millis;
		}







		if(pRxHeader_CAN1.StdId == RL_TyreTemp_0to7_address || pRxHeader_CAN1.StdId == RL_TyreTemp_8to15_address)
		{
			static int8_t tmpTyTemp0[8];
			static int8_t tmpTyTemp8[8];

			static uint32_t millisTyTemp0 = 0;
			static uint32_t millisTyTemp8 = 0;

			switch(pRxHeader_CAN1.StdId)
			{
				case RL_TyreTemp_0to7_address:

					for(uint8_t i = 1; i < 8; i++)
						tmpTyTemp0[i] = (int8_t)RxData_CAN1[i];

					millisTyTemp0 = millis;

					break;

				case RL_TyreTemp_8to15_address:

					for(uint8_t i = 0; i < 7; i++)
						tmpTyTemp8[i] = (int8_t)RxData_CAN1[i];

					millisTyTemp8 = millis;

					break;
			}

			if(millis <= millisTyTemp0 + 1000 && millis <= millisTyTemp8 + 1000)
			{
				int16_t tyreTempTmp = 0;

				for(uint8_t i = 0; i < 7; i++)
					tyreTempTmp = tyreTempTmp + tmpTyTemp0[i+1] + tmpTyTemp8[i];

				CAR_Data.tyresTemp[RL].oldFloatData = CAR_Data.tyresTemp[RL].floatData;
				CAR_Data.tyresTemp[RL].oldIntData = CAR_Data.tyresTemp[RL].intData;

				CAR_Data.tyresTemp[RL].floatData = (float)tyreTempTmp / 16;
				CAR_Data.tyresTemp[RL].intData = CAR_Data.tyresTemp[RL].floatData;

				CAR_Data.tyresTemp[RL].oldTimeData = CAR_Data.tyresTemp[RL].lastTimeData;
				CAR_Data.tyresTemp[RL].lastTimeData = millis;

				cameraData++;
			}
		}

		if(pRxHeader_CAN1.StdId == RR_TyreTemp_0to7_address || pRxHeader_CAN1.StdId == RR_TyreTemp_8to15_address)
		{
			static int8_t tmpTyTemp0[8];
			static int8_t tmpTyTemp8[8];

			static uint32_t millisTyTemp0 = 0;
			static uint32_t millisTyTemp8 = 0;

			switch(pRxHeader_CAN1.StdId)
			{
				case RL_TyreTemp_0to7_address:

					for(uint8_t i = 1; i < 8; i++)
						tmpTyTemp0[i] = (int8_t)RxData_CAN1[i];

					millisTyTemp0 = millis;

					break;

				case RL_TyreTemp_8to15_address:

					for(uint8_t i = 0; i < 7; i++)
						tmpTyTemp8[i] = (int8_t)RxData_CAN1[i];

					millisTyTemp8 = millis;

					break;
			}

			if(millis <= millisTyTemp0 + 1000 && millis <= millisTyTemp8 + 1000)
			{
				int16_t tyreTempTmp = 0;

				for(uint8_t i = 0; i < 7; i++)
					tyreTempTmp = tyreTempTmp + tmpTyTemp0[i+1] + tmpTyTemp8[i];

				CAR_Data.tyresTemp[RR].oldFloatData = CAR_Data.tyresTemp[RR].floatData;
				CAR_Data.tyresTemp[RR].oldIntData = CAR_Data.tyresTemp[RR].intData;

				CAR_Data.tyresTemp[RR].floatData = (float)tyreTempTmp / 16;
				CAR_Data.tyresTemp[RR].intData = CAR_Data.tyresTemp[RR].floatData;

				CAR_Data.tyresTemp[RR].oldTimeData = CAR_Data.tyresTemp[RR].lastTimeData;
				CAR_Data.tyresTemp[RR].lastTimeData = millis;

				cameraData++;
			}
		}

		if(pRxHeader_CAN1.StdId == FL_TyreTemp_0to7_address || pRxHeader_CAN1.StdId == FL_TyreTemp_8to15_address)
		{
			static int8_t tmpTyTemp0[8];
			static int8_t tmpTyTemp8[8];

			static uint32_t millisTyTemp0 = 0;
			static uint32_t millisTyTemp8 = 0;

			switch(pRxHeader_CAN1.StdId)
			{
				case RL_TyreTemp_0to7_address:

					for(uint8_t i = 1; i < 8; i++)
						tmpTyTemp0[i] = (int8_t)RxData_CAN1[i];

					millisTyTemp0 = millis;

					break;

				case RL_TyreTemp_8to15_address:

					for(uint8_t i = 0; i < 7; i++)
						tmpTyTemp8[i] = (int8_t)RxData_CAN1[i];

					millisTyTemp8 = millis;

					break;
			}

			if(millis <= millisTyTemp0 + 1000 && millis <= millisTyTemp8 + 1000)
			{
				int16_t tyreTempTmp = 0;

				for(uint8_t i = 0; i < 7; i++)
					tyreTempTmp = tyreTempTmp + tmpTyTemp0[i+1] + tmpTyTemp8[i];

				CAR_Data.tyresTemp[FL].oldFloatData = CAR_Data.tyresTemp[FL].floatData;
				CAR_Data.tyresTemp[FL].oldIntData = CAR_Data.tyresTemp[FL].intData;

				CAR_Data.tyresTemp[FL].floatData = (float)tyreTempTmp / 16;
				CAR_Data.tyresTemp[FL].intData = CAR_Data.tyresTemp[FL].floatData;

				CAR_Data.tyresTemp[FL].oldTimeData = CAR_Data.tyresTemp[FL].lastTimeData;
				CAR_Data.tyresTemp[FL].lastTimeData = millis;

				cameraData++;
			}
		}

		if(pRxHeader_CAN1.StdId == FR_TyreTemp_0to7_address || pRxHeader_CAN1.StdId == FR_TyreTemp_8to15_address)
		{
			static int8_t tmpTyTemp0[8];
			static int8_t tmpTyTemp8[8];

			static uint32_t millisTyTemp0 = 0;
			static uint32_t millisTyTemp8 = 0;

			switch(pRxHeader_CAN1.StdId)
			{
				case RL_TyreTemp_0to7_address:

					for(uint8_t i = 1; i < 8; i++)
						tmpTyTemp0[i] = (int8_t)RxData_CAN1[i];

					millisTyTemp0 = millis;

					break;

				case RL_TyreTemp_8to15_address:

					for(uint8_t i = 0; i < 7; i++)
						tmpTyTemp8[i] = (int8_t)RxData_CAN1[i];

					millisTyTemp8 = millis;

					break;
			}

			if(millis <= millisTyTemp0 + 1000 && millis <= millisTyTemp8 + 1000)
			{
				int16_t tyreTempTmp = 0;

				for(uint8_t i = 0; i < 7; i++)
					tyreTempTmp = tyreTempTmp + tmpTyTemp0[i+1] + tmpTyTemp8[i];

				CAR_Data.tyresTemp[FR].oldFloatData = CAR_Data.tyresTemp[FR].oldFloatData;
				CAR_Data.tyresTemp[FR].oldIntData = CAR_Data.tyresTemp[FR].intData;

				CAR_Data.tyresTemp[FR].floatData = (float)tyreTempTmp / 16;
				CAR_Data.tyresTemp[FR].intData = CAR_Data.tyresTemp[FR].floatData;

				CAR_Data.tyresTemp[FR].oldTimeData = CAR_Data.tyresTemp[FR].lastTimeData;
				CAR_Data.tyresTemp[FR].lastTimeData = millis;

				cameraData++;
			}
		}


	}
}



void tractionAcquisition(void)
{

//			static uint8_t prevTrac = 0;
//
//			if 		(TRACTION_AD_RESr < 500  && (prevTrac == 1 || prevTrac == 0))						tractionControl = 0;
//			else if (TRACTION_AD_RESr < 1300 && (prevTrac == 0 || prevTrac == 1 || prevTrac == 2))		tractionControl = 1;
//			else if (TRACTION_AD_RESr < 1900	&& (prevTrac == 1 || prevTrac == 2 || prevTrac == 3)) 		tractionControl = 2;
//			else if (TRACTION_AD_RESr < 2200	&& (prevTrac == 2 || prevTrac == 3 || prevTrac == 4))		tractionControl = 3;
//			else if (TRACTION_AD_RESr > 2200 && (prevTrac == 3 || prevTrac == 4))						tractionControl = 4;
//
//			prevTrac = tractionControl;
//
//			CAR_Data.tractionControl.floatData = tractionControl;
//			CAR_Data.tractionControl.intData = tractionControl;

	static uint32_t millisTractionRefresh = 0;

	if(millis >= millisTractionRefresh + TRACTION_REFRESH_TIME)
	{
		if(HAL_ADC_PollForConversion(&hadc3, 1) == HAL_OK)
		{
			TRACTION_AD_RESr = HAL_ADC_GetValue(&hadc3);

			static uint16_t adcStartFlag = 0;
			static uint16_t adcDataPointer = 0;
			static uint32_t tractionAdcFilterSum = 0;

			tractionAdcFilterSum -= tractionFilterBuffer[adcDataPointer];
			tractionFilterBuffer[adcDataPointer] = TRACTION_AD_RESr;
			tractionAdcFilterSum += TRACTION_AD_RESr;

			tractionAdcFiltered = tractionAdcFilterSum / TRACTION_FILTER_SIZE;

			if(adcStartFlag < TRACTION_FILTER_SIZE)
			{
				adcStartFlag++;

				tractionAdcFiltered = TRACTION_AD_RESr;
			}

			if(adcDataPointer < TRACTION_FILTER_SIZE - 1)
				adcDataPointer++;
			else
				adcDataPointer = 0;

			register uint8_t tractionTmp = 0;

			if		(tractionAdcFiltered <= TRACTION_OFF_UPPER_VALUE) 	tractionTmp = 0;
			else if	(tractionAdcFiltered <= TRACTION_1_UPPER_VALUE) 	tractionTmp = 1;
			else if	(tractionAdcFiltered <= TRACTION_2_UPPER_VALUE) 	tractionTmp = 2;
			else if	(tractionAdcFiltered <= TRACTION_3_UPPER_VALUE) 	tractionTmp = 3;
			else 					 									tractionTmp = 4;

//
//			if		(tractionAdcFiltered >= TRACTION_OFF_UPPER_VALUE - TRACTION_VALUE_MARGIN &&
//					tractionAdcFiltered <= TRACTION_OFF_UPPER_VALUE + TRACTION_VALUE_MARGIN)	tractionTmp = 0;
//			else if	(tractionAdcFiltered >= TRACTION_1_UPPER_VALUE - TRACTION_VALUE_MARGIN &&
//					tractionAdcFiltered <= TRACTION_1_UPPER_VALUE + TRACTION_VALUE_MARGIN)		tractionTmp = 1;
//			else if	(tractionAdcFiltered >= TRACTION_2_UPPER_VALUE - TRACTION_VALUE_MARGIN &&
//					tractionAdcFiltered <= TRACTION_2_UPPER_VALUE + TRACTION_VALUE_MARGIN)		tractionTmp = 2;
//			else if	(tractionAdcFiltered >= TRACTION_3_UPPER_VALUE - TRACTION_VALUE_MARGIN &&
//					tractionAdcFiltered <= TRACTION_3_UPPER_VALUE + TRACTION_VALUE_MARGIN)		tractionTmp = 3;
//			else if	(tractionAdcFiltered >= TRACTION_4_UPPER_VALUE - TRACTION_VALUE_MARGIN &&
//					tractionAdcFiltered <= TRACTION_4_UPPER_VALUE + TRACTION_VALUE_MARGIN)		tractionTmp = 4;
//			else																				tractionTmp = CAR_Data.tractionControl.intData;

			CAR_Data.tractionControl.floatData = tractionTmp;
			CAR_Data.tractionControl.intData = tractionTmp;
			tractionControl = tractionTmp;

			millisTractionRefresh = millis;

			HAL_ADC_Start(&hadc3);				//traction ADC start conversion
		}
	}
}



void CAR_DATA_Calculations(void)
{
	//Acceleration Time Calculation 0-100 Km/h BEGIN
	static uint32_t timeStartVariable = 0;
	static uint32_t timeEndVariable = 0;
	static uint8_t accelerationStatus = 0;

	if (speed < ACC_SPEED_THRESHOLD)		// < 5
	{
		timeStartVariable = millis;

		accelerationStatus = 0;
	}

	if (CAR_Data.speed.intData >= ACC_MAX_SPEED && accelerationStatus == 0)
	{
		timeEndVariable = millis;

		accelerationStatus = 1;
	}

	if(accelerationStatus == 1)
	{
		CAR_Data.lastAccelerationTime = timeEndVariable - timeStartVariable;

		if(CAR_Data.lastAccelerationTime >= ACC_MIN_TIME)
		{
			if(CAR_Data.bestAccelerationTime != 0)
				CAR_Data.bestAccelerationTime = min(CAR_Data.bestAccelerationTime, CAR_Data.lastAccelerationTime);
			else
				CAR_Data.bestAccelerationTime = CAR_Data.lastAccelerationTime;

			CAR_Data.lastAccelerationTime = min(CAR_Data.lastAccelerationTime, 9999);
			CAR_Data.bestAccelerationTime = min(CAR_Data.bestAccelerationTime, 9999);
		}

		accelerationStatus = 3;
	}
	//Acceleration Time Calculation 0-100 Km/h END



	//Brake Bias / Brake Balance calculation BEGIN

	static uint8_t flagBrakeBalFirsthBrake = 0;

	if((CAR_Data.brake.intData + CAR_Data.brakeRear.intData) > 10)
	{
		CAR_Data.brakeBias.floatData = ((float)CAR_Data.brake.intData / (CAR_Data.brake.intData + CAR_Data.brakeRear.intData)) * 100;
		flagBrakeBalFirsthBrake = 1;
	}

	if(CAR_Data.brakeBias.floatData > 99)
		CAR_Data.brakeBias.floatData = 99;
	else if (CAR_Data.brakeBias.floatData < 0)
		CAR_Data.brakeBias.floatData = 0;

	CAR_Data.brakeBias.intData = CAR_Data.brakeBias.floatData;

	if(flagBrakeBalFirsthBrake)
		CAR_Data.brakeBias.lastTimeData = min(CAR_Data.brake.lastTimeData, CAR_Data.brakeRear.lastTimeData);

	//Brake Bias / Brake Balance calculation END


	//BSPD activation detected BEGIN

	static uint32_t millisCheckBSPD = 0;
	static uint32_t millisResetWarningBSPD = 0;

	if(millis < min(CAR_Data.brake.lastTimeData, CAR_Data.tps.lastTimeData) + 100)
	{
		if(CAR_Data.brake.intData >= BSPD_BRAKE_THRESHOLD && CAR_Data.tps.intData >= BSPD_TPS_THRESHOLD)
		{
			millisCheckBSPD = 0;
		}
		else
		{
			millisCheckBSPD = millis;
		}

		if(millis >= millisCheckBSPD + BSPD_DETECTION_TIME)
		{
			CAR_Data.BSPD_warning = 1;
			millisResetWarningBSPD = millis;
		}

		if(CAR_Data.BSPD_warning != 0)
		{
			if(CAR_Data.tps.intData < 10 || CAR_Data.batteryVoltage.intData < 6)
			{
				CAR_Data.BSPD_status_can.intData = 1;
			}
			else if(millis >= millisResetWarningBSPD + BSPD_TIME_RESET)
			{
				CAR_Data.BSPD_warning = 0;
				CAR_Data.BSPD_status_can.intData = 0;
			}
		}
	}
	else
	{
		CAR_Data.BSPD_warning = 0;
		CAR_Data.BSPD_status_can.intData = 0;
		millisCheckBSPD = millis;
	}

	//CAR_Data.BSPD_status_can.intData = 0; ///WARNING: only DEBUG

	CAR_Data.BSPD_status_can.oldIntData = CAR_Data.BSPD_status_can.intData;
	CAR_Data.BSPD_status_can.oldFloatData = CAR_Data.BSPD_status_can.floatData;

	CAR_Data.BSPD_status_can.floatData = CAR_Data.BSPD_status_can.intData;

	CAR_Data.BSPD_status_can.oldTimeData = CAR_Data.BSPD_status_can.lastTimeData;
	CAR_Data.BSPD_status_can.lastTimeData = min(CAR_Data.brake.lastTimeData, CAR_Data.tps.lastTimeData);

	//BSPD activation detected END



	//ALARMS activation control BEGIN

	static uint32_t millisWaitAlarmsEngineStart = 0;
	static uint8_t alarmsEngineStartFlag = 0;

	if(millis <= CAR_Data.rpm.lastTimeData + 1000)
	{
		if(CAR_Data.rpm.intData <= 1000)
		{
			millisWaitAlarmsEngineStart = millis;


			CAN_DATA_GuiPopUp_Disable(2);		//Water Temperature, 	range
			CAN_DATA_GuiPopUp_Disable(3);		//Oil Temperature,		range
			CAN_DATA_GuiPopUp_Disable(4);		//Fuel Pressure, 		range
			CAN_DATA_GuiPopUp_Disable(5);		//Oil Pressure, 		range
			//CAN_DATA_GuiPopUp_Disable(6);		//RPM,					range

			CAN_DATA_GuiPopUp_Disable(9);		//Water pump,			range

			alarmsEngineStartFlag = 0;
		}
		else
		{
			if(alarmsEngineStartFlag == 0 && millis >= millisWaitAlarmsEngineStart + 5000)
			{
				CAN_DATA_GuiRangePopUp_Enable(2);		//Water Temperature, 	range
				CAN_DATA_GuiRangePopUp_Enable(3);		//Oil Temperature,		range
				CAN_DATA_GuiRangePopUp_Enable(4);		//Fuel Pressure, 		range
				CAN_DATA_GuiRangePopUp_Enable(5);		//Oil Pressure, 		range
				//CAN_DATA_GuiRangePopUp_Enable(6);		//RPM,					range

				CAN_DATA_GuiRangePopUp_Enable(9);		//Water pump,			range

				alarmsEngineStartFlag = 1;
			}
		}
	}


	//ALARMS activation control END


	//Old car data refresh (for old code) BEGIN
	vBat 					= CAR_Data.batteryVoltage.floatData;
	gear 					= CAR_Data.gear.intData;
	tOil 					= CAR_Data.oilTemp.floatData;
	tWater 					= CAR_Data.waterTemp.floatData;
	tAir 					= CAR_Data.airTemp.floatData;
	drsStatus 				= CAR_Data.drsStatus.intData;
	map 					= CAR_Data.map.intData;
	//map_pp					= map + 1; //used to have map + 1
	tractionControl 		= CAR_Data.tractionControl.intData;
	pOil 					= CAR_Data.oilPressure.floatData;
	rpm 					= CAR_Data.rpm.intData;
	tps 					= CAR_Data.tps.intData;
	//launchControlStatus 	= CAR_Data.launchStatus.intData;
	gs 						= 0;
	pedal 					= CAR_Data.pedal.intData;
	speed 					= CAR_Data.speed.floatData;
	steer 					= CAR_Data.steer.intData;
	slip 					= CAR_Data.slip.intData;
	brake 					= CAR_Data.brake.intData;
	pFuel 					= CAR_Data.fuelPressure.floatData;
	//Old car data refresh (for old code) END
}




extern GUI_CONST_STORAGE GUI_FONT GUI_FontCalibri250;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontCalibri230Balised4pp;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontCalibri230Balised2pp_DigAndMaiusc;


#define ALARM_DATA_FONT				GUI_FontCalibri230Balised2pp_DigAndMaiusc
#define ALARM_DATA_OFFSET_Y			-10


#define BSPD_V3_ON_CAR				false





#define maxcanDataToCheck 50
uint8_t canDataToCheckNumber = 0;


CAN_DATA_GuiAlarmTypedef canDataToCheck[maxcanDataToCheck] = {0};

void AlarmPage(char* string, CAN_DATA_Typedef* dataPointer, uint32_t messageColor, uint32_t dataColor, uint32_t backColor);


void CAR_DATA_GuiAlarm_Init(void)
{
	uint16_t setupError = 0;

	//setupError += CAN_DATA_GuiChangePopUp_Add(0, &CAR_Data.tractionControl, 0, 1000, 0, "Traction", GUI_BLACK, GUI_BLACK, ARGB_CREATE(0, 100, 100, 255));
	setupError += CAN_DATA_GuiChangePopUp_Add(0, &CAR_Data.tractionControl, 0, 800, 100, "Traction", GUI_BLACK, GUI_BLACK, ARGB_CREATE(0, 100, 100, 255));
	setupError += CAN_DATA_GuiChangePopUp_Add(1, &CAR_Data.map, 0, 800, 100, "MAP", GUI_BLACK, GUI_BLACK, ARGB_CREATE(0, 100, 100, 255));

//	setupError += CAN_DATA_GuiChangePopUp_Add(99, &CAR_Data.tractionControl, 0, 1000, 100, "TRACTION TEST", GUI_BLACK, GUI_BLACK, ARGB_CREATE(0, 100, 255, 100));


	setupError += CAN_DATA_GuiRangePopUp_Add(2, &CAR_Data.waterTemp, 1000, 4000, 60000, "Water Temperature", GUI_BLACK, GUI_BLACK, GUI_BLUE, GUI_RED);
	setupError += CAN_DATA_GuiRangePopUp_Add(3, &CAR_Data.oilTemp, 1000, 4000, 60000, "Oil Temperature", GUI_BLACK, GUI_BLACK, GUI_BLUE, GUI_RED);

	setupError += CAN_DATA_GuiRangePopUp_Add(4, &CAR_Data.fuelPressure, 500, 4000, 60000, "Fuel Pressure", GUI_BLACK, GUI_BLACK, GUI_RED, GUI_RED);
	setupError += CAN_DATA_GuiRangePopUp_Add(5, &CAR_Data.oilPressure, 500, 4000, 60000, "Oil Pressure", GUI_BLACK, GUI_BLACK, GUI_RED, GUI_RED);

	setupError += CAN_DATA_GuiRangePopUp_Add(6, &CAR_Data.rpm, 0, 1000, 5000, "TOO HIGH RPM", GUI_BLACK, GUI_BLACK, GUI_RED, GUI_RED);

	if(BSPD_V3_ON_CAR == TRUE)
		setupError += CAN_DATA_GuiRangePopUp_Add(7, &CAR_Data.BSPD_status_can, 0, 11000, 20000, "BSPD ACTIVATED", GUI_BLACK, GUI_BLACK, GUI_GREEN, GUI_RED);
	else
		setupError += CAN_DATA_GuiRangePopUp_Add(7, &CAR_Data.BSPD_status_can, 1000, 10000, 10000, "BSPD ACTIVATED", GUI_BLACK, GUI_BLACK, GUI_GREEN, GUI_RED);


	setupError += CAN_DATA_GuiChangePopUp_Add(8, &CAR_Data.waterPumpStatus, 0, 5000,     0, "Water pump", GUI_BLACK, GUI_BLACK, GUI_RED);
	setupError += CAN_DATA_GuiRangePopUp_Add( 9, &CAR_Data.waterPumpStatus, 0, 5000, 10000, "Water pump", GUI_BLACK, GUI_BLACK, GUI_RED, GUI_RED);

	if(setupError != 0)
		Error_Handler();
}

uint8_t alarmPageDisplayRefreshEnable = 1;		//used to control the page frequency (60Hz refresh rate)

uint8_t alarmDetected = 0;
uint8_t alarmNumber = 0;
uint8_t lastAlarmId = 255;						//used for debug in STMStudio

void CAN_Data_AlarmDetection(void)
{
	if(millis < 7000 && DEBUG_MODE == DISABLE)
		goto END_OF_FUNCTION;

	static uint16_t localSelectedGui = 0;

	if(selectedGui != GuiAlarm)
		localSelectedGui = selectedGui;

	//data check BEGIN

	for(uint8_t i = 0; i < canDataToCheckNumber; i++)			//data check cycle
	{
		if(canDataToCheck[i].firstCall == 0)
		{
			canDataToCheck[i].oldData = canDataToCheck[i].dataPointer->floatData;
			canDataToCheck[i].firstCall = 1;
		}

		if(canDataToCheck[i].changeControlEnable == ENABLE)
		{
			if(canDataToCheck[i].dataPointer->floatData != canDataToCheck[i].oldData || (canDataToCheck[i].dataChanged == 1 && canDataToCheck[i].alarmWaiting == 1))
			{
				canDataToCheck[i].dataChanged = 1;

				canDataToCheck[i].oldData = canDataToCheck[i].dataPointer->floatData;
			}
			else
			{
				canDataToCheck[i].dataChanged = 0;
			}
		}
		else
		{
			canDataToCheck[i].dataChanged = 0;
		}


		if(canDataToCheck[i].rangeControlEnable == ENABLE && canDataToCheck[i].dataPointer->lastTimeData - canDataToCheck[i].dataPointer->oldTimeData <= 2000 && canDataToCheck[i].dataPointer->lastTimeData > 1000)
		{
			if(
					canDataToCheck[i].dataOutRange == 0 &&
					(canDataToCheck[i].dataPointer->floatData > canDataToCheck[i].dataPointer->maxValue ||
					 canDataToCheck[i].dataPointer->floatData < canDataToCheck[i].dataPointer->minValue	)
				)
			{

				if(millis >= canDataToCheck[i].dataOutRangeMillis + canDataToCheck[i].dataOutRangeTime)
				{
					if(canDataToCheck[i].dataPointer->floatData > canDataToCheck[i].dataPointer->maxValue)
					{
						canDataToCheck[i].dataOutRange = 1;
						canDataToCheck[i].backColorSelector = 1;
					}
					else
						if(canDataToCheck[i].dataPointer->floatData < canDataToCheck[i].dataPointer->maxValue)
						{
							canDataToCheck[i].dataOutRange = 2;
							canDataToCheck[i].backColorSelector = 2;
						}

					canDataToCheck[i].dataOutRangeMillis = millis;
				}

			}
			else
			{
				if(canDataToCheck[i].dataOutRange != 0)
				{
					if(!(canDataToCheck[i].dataPointer->floatData >= canDataToCheck[i].dataPointer->maxValue ||
						 canDataToCheck[i].dataPointer->floatData <= canDataToCheck[i].dataPointer->minValue)
						)
					{
						if(millis >= canDataToCheck[i].dataOutRangeMillis + canDataToCheck[i].dataOutRangeTime/2)
						{
							canDataToCheck[i].dataOutRange = 0;
							canDataToCheck[i].dataOutRangeMillis = millis;
						}
					}
					else
					{
						canDataToCheck[i].dataOutRangeMillis = millis;
					}
				}

				//canDataToCheck[i].dataOutRangeMillis = millis;
				//canDataToCheck[i].dataOutRange = 0;
			}
		}
		else
		{
			canDataToCheck[i].dataOutRange = 0;
		}


		if(canDataToCheck[i].alarmDisplayed == 0)
		{
			if(canDataToCheck[i].dataChanged == 1 || canDataToCheck[i].dataOutRange != 0)
			{
				canDataToCheck[i].alarmWaiting = 1;
			}
			else
			{
				canDataToCheck[i].alarmWaiting = 0;
			}
		}
		else
		{
			canDataToCheck[i].alarmWaiting = 0;
		}
	}

	//data check END

	//alarm selection BEGIN

	uint16_t lowerPriority = 0xFF;

	static uint16_t dataInAlarm = 0xFF;
	//static uint8_t alarmToDisplay = 0;
	static uint8_t alarmOnDisplay = 0;


	//static uint8_t alarmNumber = 0;

	if(alarmNumber != 0 && alarmDetected == 0)
	{
		for(uint8_t i = 0; i < canDataToCheckNumber; i++)			//alarm selection cycle
		{
			if(canDataToCheck[i].alarmWaiting == 1)
			{
				alarmDetected = 1;
				lowerPriority = min(lowerPriority, canDataToCheck[i].dataPointer->priority);
			}
		}
	}


	uint8_t tmpAlarmNumber = 0;

	for(uint8_t i = 0; i < canDataToCheckNumber; i++)			//alarm selection cycle
	{
		if(canDataToCheck[i].alarmWaiting == 1)
		{
			tmpAlarmNumber++;
			alarmDetected = 1;
			lowerPriority = min(lowerPriority, canDataToCheck[i].dataPointer->priority);
		}
	}

	alarmNumber = max(alarmNumber, tmpAlarmNumber);


	if(lowerPriority != 0xFF && alarmOnDisplay == 0)
	{
		for(uint8_t i = 0; i < canDataToCheckNumber; i++)			//alarm activation cycle
		{
			if(canDataToCheck[i].alarmWaiting == 1 && canDataToCheck[i].dataPointer->priority == lowerPriority)
			{
				canDataToCheck[i].alarmStatus = 1;
				canDataToCheck[i].alarmWaiting = 0;

				canDataToCheck[i].alarmMillis = millis;

				dataInAlarm = i;
				i = canDataToCheckNumber;

				//alarmToDisplay = 1;
			}
		}
	}

	//alarm selection END

	//alarm display BEGIN

	if(alarmPageDisplayRefreshEnable == 1)		//WARNING: if there are some problems disable this and make it true
	{
		static uint32_t millisAlarmPageExit = 0;

		if(alarmDetected != 0 || (alarmOnDisplay == 1 || dataInAlarm != 0xFF))
		{
			if(canDataToCheck[dataInAlarm].alarmDisplayed == 0)
			{
				canDataToCheck[dataInAlarm].alarmOnDisplay = 1;
				//alarmToDisplay = 0;
				alarmOnDisplay = 1;

				lastAlarmId = canDataToCheck[dataInAlarm].alarmId;

				uint32_t backColor = canDataToCheck[dataInAlarm].backColorOver;

				if(canDataToCheck[dataInAlarm].backColorSelector == 2)
					backColor = canDataToCheck[dataInAlarm].backColorUnder;

				AlarmPage(canDataToCheck[dataInAlarm].message, canDataToCheck[dataInAlarm].dataPointer, canDataToCheck[dataInAlarm].messageColor, canDataToCheck[dataInAlarm].dataColor, backColor);

				selectedGui = GuiAlarm;

				if(millis >= canDataToCheck[dataInAlarm].alarmMillis + canDataToCheck[dataInAlarm].alarmTime)
				{
					canDataToCheck[dataInAlarm].alarmMillis = millis;
					alarmDetected = 0;

					alarmNumber--;

					canDataToCheck[dataInAlarm].alarmOnDisplay = 0;
					canDataToCheck[dataInAlarm].alarmStatus = 0;

					canDataToCheck[dataInAlarm].alarmDisplayed = 1;

					alarmOnDisplay = 0;
					dataInAlarm = 0xFF;

					selectedGui = localSelectedGui;

					GUI_SetColor(GUI_WHITE);
					GUI_SetBkColor(GUI_BLACK);
					GUI_Clear();

					//canDataToCheck[dataInAlarm].alarmResetMillis = millis;
				}
			}

			millisAlarmPageExit = millis;

			alarmPageDisplayRefreshEnable = 0;
		}
		else
		{
			if(millis >=  millisAlarmPageExit + 200)
			if(alarmDetected == 0 && alarmNumber == 0)
			{
				selectedGui = localSelectedGui;
				millisAlarmPageExit = millis;
			}
		}
	}

	//alarm display END

	//alarm ri-enable after display BEGIN

	for(uint8_t i = 0; i < canDataToCheckNumber; i++)
	{
		if(canDataToCheck[i].alarmDisplayed == 1)
		{
			if(millis >= canDataToCheck[i].alarmResetMillis + canDataToCheck[i].alarmResetTime)
			{
				canDataToCheck[i].alarmResetMillis = millis;
				canDataToCheck[i].alarmDisplayed = 0;
			}
		}
		else
			canDataToCheck[i].alarmResetMillis = millis;
	}

	//alarm ri-enable after display END



	END_OF_FUNCTION:;
}



void AlarmPage(char* string, CAN_DATA_Typedef* dataPointer, uint32_t messageColor, uint32_t dataColor, uint32_t backColor)
{
	register uint8_t particularDataDetected = 0;

	static CAN_DATA_Typedef* dataPointerOld;
	float dataTemp;
	register uint8_t decimalDigit = 1;

	if(dataPointer->dataType == dataType_Float)
		dataTemp = dataPointer->floatData;
	else
	{
		dataTemp = dataPointer->intData;
		decimalDigit = 0;
	}


	GUI_SetColor(GUI_WHITE);

	//main rect (frame)
	GUI_DrawRect(1, 1, 479, 271);
	GUI_DrawRect(2, 2, 478, 270);


	static uint8_t countdownBSPD = 11;
	static uint8_t clearFlagBSPD = 0;

	if(countdownBSPD == 0 && dataPointer == &CAR_Data.BSPD_status_can)
	{
		backColor = GUI_GREEN;
		GUI_SetBkColor(backColor);

		if(clearFlagBSPD == 0)
		{
			GUI_Clear();
			clearFlagBSPD = 1;
		}
	}


	if(dataPointer == &CAR_Data.waterPumpStatus)
	{
		if(CAR_Data.waterPumpStatus.intData == 0)
		{
			backColor = GUI_RED;
			GUI_SetBkColor(backColor);
		}
		else
		{
			backColor = GUI_GREEN;
			GUI_SetBkColor(backColor);
		}
	}




	static char* lastString = 0;
	static uint32_t lastData = 0;
	static uint32_t lastBackColor = 0;

	if((string != lastString && dataTemp != lastData) || lastBackColor != backColor)
	{
		//GUI_SetColor(ARGB_CREATE(0, 100, 100, 255));
		GUI_SetColor(backColor);
		GUI_FillRect(3, 3, 477, 269);

		lastString = string;
		lastData = dataTemp;
		lastBackColor = backColor;
	}



	GUI_SetColor(messageColor);
	GUI_SetBkColor(backColor);

	GUI_SetTextAlign(GUI_TA_HCENTER);
	GUI_SetFont(&GUI_Font32B_1);
	GUI_DispStringAt(string, 240, 46);


	char stringInit[8] = "";
	char stringEnd[8] = "";
	static  GUI_DrawNumAtTypeDef dataforText = {0};



	if(dataPointer == &CAR_Data.tractionControl && dataTemp == 0)
	{
		GUI_SetFont(&ALARM_DATA_FONT);
		GUI_SetTextAlign(GUI_TA_HCENTER);
		GUI_DispStringAt("OFF", 240, 100 + ALARM_DATA_OFFSET_Y);

		particularDataDetected = 1;
	}

	if(dataPointer == &CAR_Data.map)
	{
		GUI_SetFont(&ALARM_DATA_FONT);
		GUI_SetTextAlign(GUI_TA_HCENTER);

		if(dataTemp == 0)
		{
			GUI_DispStringAt("BASE", 240, 100 + ALARM_DATA_OFFSET_Y);
		}
		else if(dataTemp == 1)
		{
			GUI_DispStringAt("ECO", 240, 100 + ALARM_DATA_OFFSET_Y);
		}
		else
		{
			GUI_DispStringAt("ERROR", 240, 100 + ALARM_DATA_OFFSET_Y);
		}

		particularDataDetected = 1;
	}




	if(dataPointer == &CAR_Data.rpm)
	{
		GUI_SetFont(&ALARM_DATA_FONT);
		GUI_SetTextAlign(GUI_TA_HCENTER);
		GUI_DispStringAt("RPM", 240, 100 + ALARM_DATA_OFFSET_Y);

		particularDataDetected = 1;
	}



	if(dataPointer == &CAR_Data.BSPD_status_can)
	{
		static uint32_t lastMillisBSPD = 0;
		static uint32_t millisRestartBSPD = 0;

		if(BSPD_V3_ON_CAR == TRUE)
		{
			if(millis >= lastMillisBSPD + 100)
			{
				millisRestartBSPD = 0;
				countdownBSPD = 11;

				clearFlagBSPD = 0;
			}

			if(millis > millisRestartBSPD + 1000)
			{
				millisRestartBSPD = millis;

				if(countdownBSPD > 0)
				{
					countdownBSPD -= 1;
				}
			}


			GUI_SetFont(&GUI_Font32B_1);
			GUI_SetTextAlign(GUI_TA_HCENTER);
			GUI_DispStringAt("RESTART IN:", 240, 90);

			if(countdownBSPD > 0)
			{
				dataforText.number = countdownBSPD;
				GUI_DrawNumAt(240, 130 + ALARM_DATA_OFFSET_Y, &ALARM_DATA_FONT, dataColor, backColor, &dataforText, UNDEFINED_NINT, decimalDigit, SIGN_NEGATIVE, DISABLE, CENTER, stringInit, stringEnd);
			}
			else
			{
				GUI_SetFont(&GUI_Font32B_1);
				GUI_SetTextAlign(GUI_TA_HCENTER);
				GUI_DispStringAt("RESTART!", 240, 180 + ALARM_DATA_OFFSET_Y);
			}
		}
		else
		{
			GUI_SetFont(&GUI_Font32B_1);
			GUI_SetTextAlign(GUI_TA_HCENTER);
			//GUI_DispStringAt("RETIRE", 240, 120);
			GUI_DispStringAt("IF CAN NOT RESTART", 240, 120);

			//GUI_SetFont(&GUI_Font32B_1);
			GUI_SetTextAlign(GUI_TA_HCENTER);
			//GUI_DispStringAt("THE CAR", 240, 160);
			GUI_DispStringAt("RETIRE THE CAR", 240, 160);
		}

		lastMillisBSPD = millis;

		particularDataDetected = 1;
	}



	if(dataPointer == &CAR_Data.waterPumpStatus)
	{
		GUI_SetFont(&ALARM_DATA_FONT);
		GUI_SetTextAlign(GUI_TA_HCENTER);


		if(CAR_Data.waterPumpStatus.intData == 0)
		{
			GUI_DispStringAt("OFF", 240, 100 + ALARM_DATA_OFFSET_Y);
		}
		else
		{
			GUI_DispStringAt("ON", 240, 100 + ALARM_DATA_OFFSET_Y);
		}


		particularDataDetected = 1;
	}


	if(particularDataDetected == 0)
	{
		static uint32_t dataTempMillisRefresh = 0;
		static float dataTempDelayed = 0;

		if(dataPointer != dataPointerOld || millis >= dataTempMillisRefresh + 200)
		{
			dataTempMillisRefresh = millis;
			dataTempDelayed = dataTemp;
		}

		if(dataPointer == &CAR_Data.tractionControl)
			dataTempDelayed = dataTemp;

		dataforText.number = dataTempDelayed;
		//GUI_DrawNumAt(240, 100, &GUI_FontD80, dataColor, backColor, &dataforText, UNDEFINED_NINT, decimalDigit, SIGN_NEGATIVE, DISABLE, CENTER, noString_, noString_);
		GUI_DrawNumAt(240, 100 + ALARM_DATA_OFFSET_Y, &ALARM_DATA_FONT, dataColor, backColor, &dataforText, UNDEFINED_NINT, decimalDigit, SIGN_NEGATIVE, DISABLE, CENTER, stringInit, stringEnd);
	}

	dataPointerOld = dataPointer;
}

uint8_t CAN_DATA_GuiChangePopUp_Add(uint8_t alarmId, CAN_DATA_Typedef* dataToAdd, uint32_t timeout, uint32_t popUpTime, uint32_t resetTime, char* message, uint32_t messageColor, uint32_t dataColor, uint32_t backColor)
{
	if(canDataToCheckNumber < maxcanDataToCheck)
	{
		uint8_t setupError = 0;

		for(uint16_t i = 0; i < canDataToCheckNumber; i++)
			if(canDataToCheck[i].alarmId == alarmId)
				setupError++;

		if(setupError == 0)
		{
			canDataToCheck[canDataToCheckNumber].alarmId =  alarmId;
			canDataToCheck[canDataToCheckNumber].dataPointer = dataToAdd;
			canDataToCheck[canDataToCheckNumber].rangeControlEnable = DISABLE;
			canDataToCheck[canDataToCheckNumber].changeControlEnable = ENABLE;

			canDataToCheck[canDataToCheckNumber].dataOutRangeTime = timeout;
			canDataToCheck[canDataToCheckNumber].alarmTime = popUpTime;
			canDataToCheck[canDataToCheckNumber].alarmResetTime = resetTime;

			canDataToCheck[canDataToCheckNumber].message = message;

			canDataToCheck[canDataToCheckNumber].messageColor = messageColor;
			canDataToCheck[canDataToCheckNumber].dataColor = dataColor;
			canDataToCheck[canDataToCheckNumber].backColorUnder = backColor;
			canDataToCheck[canDataToCheckNumber].backColorOver = backColor;

			canDataToCheck[canDataToCheckNumber].firstCall = 0;

			canDataToCheckNumber++;
		}
		else
			return 1;

		return 0;
	}
	else
		return 1;
}


uint8_t CAN_DATA_GuiRangePopUp_Add(uint8_t alarmId, CAN_DATA_Typedef* dataToAdd, uint32_t timeout, uint32_t popUpTime, uint32_t resetTime, char* message, uint32_t messageColor, uint32_t dataColor, uint32_t backColorUnder, uint32_t backColorOver)
{
	if(canDataToCheckNumber < maxcanDataToCheck)
	{
		uint8_t setupError = 0;

		for(uint16_t i = 0; i < canDataToCheckNumber; i++)
			if(canDataToCheck[i].alarmId == alarmId)
				setupError++;

		if(setupError == 0)
		{
			canDataToCheck[canDataToCheckNumber].alarmId =  alarmId;
			canDataToCheck[canDataToCheckNumber].dataPointer = dataToAdd;
			canDataToCheck[canDataToCheckNumber].rangeControlEnable = ENABLE;
			canDataToCheck[canDataToCheckNumber].changeControlEnable = DISABLE;

			canDataToCheck[canDataToCheckNumber].dataOutRangeTime = timeout;
			canDataToCheck[canDataToCheckNumber].alarmTime = popUpTime;
			canDataToCheck[canDataToCheckNumber].alarmResetTime = resetTime;

			canDataToCheck[canDataToCheckNumber].message = message;

			canDataToCheck[canDataToCheckNumber].messageColor = messageColor;
			canDataToCheck[canDataToCheckNumber].dataColor = dataColor;
			canDataToCheck[canDataToCheckNumber].backColorUnder = backColorUnder;
			canDataToCheck[canDataToCheckNumber].backColorOver = backColorOver;


			canDataToCheck[canDataToCheckNumber].firstCall = 0;

			canDataToCheckNumber++;
		}
		else
			return 1;

		return 0;
	}
	else
		return 1;
}


uint8_t CAN_DATA_GuiPopUp_Disable(uint8_t alarmId)
{
	for(uint16_t i = 0; i < canDataToCheckNumber; i++)
	{
		if(canDataToCheck[i].alarmId == alarmId)
		{
			canDataToCheck[i].rangeControlEnable = DISABLE;
			canDataToCheck[i].changeControlEnable = DISABLE;

			return 0;
		}
	}

	return 1;
}

void CAN_DATA_GuiPopUp_DisableAll(void)
{
	for(uint16_t i = 0; i < canDataToCheckNumber; i++)
	{
		canDataToCheck[i].rangeControlEnable = DISABLE;
		canDataToCheck[i].changeControlEnable = DISABLE;
	}
}


uint8_t CAN_DATA_GuiChangePopUp_Enable(uint8_t alarmId)
{
	for(uint16_t i = 0; i < canDataToCheckNumber; i++)
	{
		if(canDataToCheck[i].alarmId == alarmId)
		{
			canDataToCheck[i].rangeControlEnable = DISABLE;
			canDataToCheck[i].changeControlEnable = ENABLE;

			return 0;
		}
	}

	return 1;
}

uint8_t CAN_DATA_GuiRangePopUp_Enable(uint8_t alarmId)
{
	for(uint16_t i = 0; i < canDataToCheckNumber; i++)
	{
		if(canDataToCheck[i].alarmId == alarmId)
		{
			canDataToCheck[i].rangeControlEnable = ENABLE;
			canDataToCheck[i].changeControlEnable = DISABLE;

			return 0;
		}
	}

	return 1;
}



int16_t fuelPressureDebug = 0;
uint8_t fuelPressureDebugH = 0;
uint8_t fuelPressureDebugL = 0;

void canDataGenerationForDebug(void)
{

	if(pRxHeader_CAN1.StdId > 0x321)
		pRxHeader_CAN1.StdId = 0x90;
	else
		pRxHeader_CAN1.StdId++;



	static uint16_t drsTarget = 2000;
	static int16_t fuelPressure = -3000;

	switch(pRxHeader_CAN1.StdId)
	{
		case 0x208:	//ECU		0x208: ND[2], fuelPressure[2], airTemperature[2], ND[2]

			if(fuelPressure < 3000)
				fuelPressure+=10;
			else
				fuelPressure = -3000;

			RxData_CAN1[2] = (uint8_t)(fuelPressure >> 8);
			RxData_CAN1[3] = (uint8_t) fuelPressure;

			fuelPressureDebug = fuelPressure;
			fuelPressureDebugH = RxData_CAN1[2];
			fuelPressureDebugL = RxData_CAN1[3];

//			RxData_CAN1[2] = fuelPressure >> 8;
//			RxData_CAN1[3] = fuelPressure;

			break;


		case 0x321:	//DRS		0x321: ND[4], drsTargher[2], ND[2]

			RxData_CAN1[4] = (uint8_t)(drsTarget >> 8);
			RxData_CAN1[5] = (uint8_t) drsTarget;

			break;

	}
}
