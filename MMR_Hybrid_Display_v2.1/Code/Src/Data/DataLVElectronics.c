// START
#include "Data/DataLVElectronics.h"
#include "DisplayConstant.h"
#include "Data/DataConstant.h"
// END

void initializeDataLVElectronics(DataLVElectronics* dataLVElectronics) {
	inizializeData(&(dataLVElectronics->voltageBatteryLV), EMPTY_VALUE, BATTERY_LV_VOLTAGE_CONVERSION_FACTOR);
	inizializeData(&(dataLVElectronics->throttlePedal), EMPTY_VALUE, THROTTLE_PEDAL_CONVERSION_FACTOR);
	inizializeData(&(dataLVElectronics->throttlePosition), EMPTY_VALUE, THROTTLE_POSITION_CONVERSION_FACTOR);
	inizializeData(&(dataLVElectronics->tps1), EMPTY_VALUE, TPS1_CONVERSION_FACTOR);
	inizializeData(&(dataLVElectronics->tps2), EMPTY_VALUE, TPS2_CONVERSION_FACTOR);
	inizializeData(&(dataLVElectronics->apps1), EMPTY_VALUE, APPS1_CONVERSION_FACTOR);
	inizializeData(&(dataLVElectronics->apps2), EMPTY_VALUE, APPS2_CONVERSION_FACTOR);
	inizializeData(&(dataLVElectronics->bseFront), EMPTY_VALUE, BSE_FRONT_CONVERSION_FACTOR);
	inizializeData(&(dataLVElectronics->bseRear), EMPTY_VALUE, BSE_REAR_CONVERSION_FACTOR);
	inizializeData(&(dataLVElectronics->ecuCpuUsage), EMPTY_VALUE, ECU_CPU_USAGE_CONVERSION_FACTOR);
	inizializeData(&(dataLVElectronics->ecuLed), EMPTY_VALUE, ECU_LED_CONVERSION_FACTOR);
	inizializeData(&(dataLVElectronics->ecuTemperature), EMPTY_VALUE, ECU_TEMPERATURE_CONVERSION_FACTOR);

	initializeDataStatus(&(dataLVElectronics->can1Diagnostic));	//TODO aggingere 4 al valore in canMessage perchè l'enumeration in centralina ha valori negativi
	dataLVElectronics->can1Diagnostic.statusDef[0]  = "InvalidCanbus";
	dataLVElectronics->can1Diagnostic.statusDef[1]  = "BusOff";
	dataLVElectronics->can1Diagnostic.statusDef[2]  = "TrasmitErrorPassive";
	dataLVElectronics->can1Diagnostic.statusDef[3]  = "ReceiveErrorPassive";
	dataLVElectronics->can1Diagnostic.statusDef[4]  = "NotInUse";
	dataLVElectronics->can1Diagnostic.statusDef[5]  = "Ok";
	dataLVElectronics->can1Diagnostic.statusDef[6]  = "ReceiveWarning";
	dataLVElectronics->can1Diagnostic.statusDef[7]  = "TransmitWarning";
	dataLVElectronics->can1Diagnostic.statusDef[8]  = "WrongSpeed";
	dataLVElectronics->can1Diagnostic.statusDef[9]  = "TransmitOverrun";
	dataLVElectronics->can1Diagnostic.statusDef[10] = "ReceiveOverrun";
	dataLVElectronics->can1Diagnostic.statusDefLength = 11;

	initializeDataStatus(&(dataLVElectronics->can1Mode));
	dataLVElectronics->can1Mode.statusDef[0] = "NotInUse";
	dataLVElectronics->can1Mode.statusDef[1] = "1Mbps";
	dataLVElectronics->can1Mode.statusDef[2] = "500kbps";
	dataLVElectronics->can1Mode.statusDef[3] = "250kbps";
	dataLVElectronics->can1Mode.statusDef[4] = "125kbps";
	dataLVElectronics->can1Mode.statusDefLength = 5;

	initializeDataStatus(&(dataLVElectronics->can2Diagnostic));	//TODO aggingere 4 al valore in canMessage
	dataLVElectronics->can2Diagnostic.statusDef[0]  = "InvalidCanbus";
	dataLVElectronics->can2Diagnostic.statusDef[1]  = "BusOff";
	dataLVElectronics->can2Diagnostic.statusDef[2]  = "TrasmitError";
	dataLVElectronics->can2Diagnostic.statusDef[3]  = "ReceiveError";
	dataLVElectronics->can2Diagnostic.statusDef[4]  = "NotInUse";
	dataLVElectronics->can2Diagnostic.statusDef[5]  = "Ok";
	dataLVElectronics->can2Diagnostic.statusDef[6]  = "ReceiveWarning";
	dataLVElectronics->can2Diagnostic.statusDef[7]  = "TransmitWarning";
	dataLVElectronics->can2Diagnostic.statusDef[8]  = "WrongSpeed";
	dataLVElectronics->can2Diagnostic.statusDef[9]  = "TransmitOverrun";
	dataLVElectronics->can2Diagnostic.statusDef[10] = "ReceiveOverrun";
	dataLVElectronics->can2Diagnostic.statusDefLength = 11;

	initializeDataStatus(&(dataLVElectronics->can2Mode));
	dataLVElectronics->can2Mode.statusDef[0] = "NotInUse";
	dataLVElectronics->can2Mode.statusDef[1] = "1Mbps";
	dataLVElectronics->can2Mode.statusDef[2] = "500kbps";
	dataLVElectronics->can2Mode.statusDef[3] = "250kbps";
	dataLVElectronics->can2Mode.statusDef[4] = "125kbps";
	dataLVElectronics->can2Mode.statusDefLength = 5;

	initializeDataStatus(&(dataLVElectronics->can3Diagnostic));	//TODO aggingere 4 al valore in canMessage
	dataLVElectronics->can3Diagnostic.statusDef[0]  = "InvalidCanbus";
	dataLVElectronics->can3Diagnostic.statusDef[1]  = "BusOff";
	dataLVElectronics->can3Diagnostic.statusDef[2]  = "TrasmitErrorPassive";
	dataLVElectronics->can3Diagnostic.statusDef[3]  = "ReceiveErrorPassive";
	dataLVElectronics->can3Diagnostic.statusDef[4]  = "NotInUse";
	dataLVElectronics->can3Diagnostic.statusDef[5]  = "Ok";
	dataLVElectronics->can3Diagnostic.statusDef[6]  = "ReceiveWarning";
	dataLVElectronics->can3Diagnostic.statusDef[7]  = "TransmitWarning";
	dataLVElectronics->can3Diagnostic.statusDef[8]  = "WrongSpeed";
	dataLVElectronics->can3Diagnostic.statusDef[9]  = "TransmitOverrun";
	dataLVElectronics->can3Diagnostic.statusDef[10] = "ReceiveOverrun";
	dataLVElectronics->can3Diagnostic.statusDefLength = 11;

	initializeDataStatus(&(dataLVElectronics->can3Mode));
	dataLVElectronics->can3Mode.statusDef[0] = "NotInUse";
	dataLVElectronics->can3Mode.statusDef[1] = "1Mbps";
	dataLVElectronics->can3Mode.statusDef[2] = "500kbps";
	dataLVElectronics->can3Mode.statusDef[3] = "250kbps";
	dataLVElectronics->can3Mode.statusDef[4] = "125kbps";
	dataLVElectronics->can3Mode.statusDefLength = 5;

	initializeDataStatus(&(dataLVElectronics->etcMode));
	dataLVElectronics->etcMode.statusDef[0] = "NotInUse";
	dataLVElectronics->etcMode.statusDef[1] = "Enabled";
	dataLVElectronics->etcMode.statusDefLength = 2;
	
	initializeDataStatus(&(dataLVElectronics->etcState));
	dataLVElectronics->etcState.statusDef[0] = "Disable";
	dataLVElectronics->etcState.statusDef[1] = "Enabled";
	dataLVElectronics->etcState.statusDefLength = 2;

	initializeDataStatus(&(dataLVElectronics->etcCriticalState));
	dataLVElectronics->etcCriticalState.statusDef[0] = "False";
	dataLVElectronics->etcCriticalState.statusDef[1] = "True";
	dataLVElectronics->etcCriticalState.statusDefLength = 2;

	initializeDataStatus(&(dataLVElectronics->etcThrottlePedalCritical));
	dataLVElectronics->etcThrottlePedalCritical.statusDef[0] = "Problem";
	dataLVElectronics->etcThrottlePedalCritical.statusDef[1] = "NoProblem";
	dataLVElectronics->etcThrottlePedalCritical.statusDefLength = 2;

	// TODO Aggiungere stato bottoni
	//DataStatus markerButton;
	initializeDataStatus(&(dataLVElectronics->markerButton));
	dataLVElectronics->markerButton.statusDef[0] = "";
	dataLVElectronics->markerButton.statusDefLength = 1;
	//DataStatus mapAButton;
	initializeDataStatus(&(dataLVElectronics->mapAButton));
	dataLVElectronics->mapAButton.statusDef[0] = "";
	dataLVElectronics->mapAButton.statusDefLength = 1;
	//DataStatus mapEButton;
	initializeDataStatus(&(dataLVElectronics->mapEButton));
	dataLVElectronics->mapEButton.statusDef[0] = "";
	dataLVElectronics->mapEButton.statusDefLength = 1;
	//DataStatus mapCButton;
	initializeDataStatus(&(dataLVElectronics->mapCButton));
	dataLVElectronics->mapCButton.statusDef[0] = "";
	dataLVElectronics->mapCButton.statusDefLength = 1;
	//DataStatus neutralButton;
	initializeDataStatus(&(dataLVElectronics->neutralButton));
	dataLVElectronics->neutralButton.statusDef[0] = "";
	dataLVElectronics->neutralButton.statusDefLength = 1;
	//DataStatus killButton;
	initializeDataStatus(&(dataLVElectronics->killButton));
	dataLVElectronics->killButton.statusDef[0] = "";
	dataLVElectronics->killButton.statusDefLength = 1;
	//DataStatus startButton;
	initializeDataStatus(&(dataLVElectronics->startButton));
	dataLVElectronics->startButton.statusDef[0] = "";
	dataLVElectronics->startButton.statusDefLength = 1;
	//DataStatus readyToDriveButton;
	initializeDataStatus(&(dataLVElectronics->readyToDriveButton));
	dataLVElectronics->readyToDriveButton.statusDef[0] = "";
	dataLVElectronics->readyToDriveButton.statusDefLength = 1;
	//DataStatus readyToDriveState;
	initializeDataStatus(&(dataLVElectronics->readyToDriveState));
	dataLVElectronics->readyToDriveState.statusDef[0] = "";
	dataLVElectronics->readyToDriveState.statusDefLength = 1;
	//DataStatus readyToDriveRelayState;
	initializeDataStatus(&(dataLVElectronics->readyToDriveRelayState));
	dataLVElectronics->readyToDriveRelayState.statusDef[0] = "";
	dataLVElectronics->readyToDriveRelayState.statusDefLength = 1;

	initializeDataStatus(&(dataLVElectronics->gbuUpshiftInputRequest));
	dataLVElectronics->gbuUpshiftInputRequest.statusDef[0] = "OFF";
	dataLVElectronics->gbuUpshiftInputRequest.statusDef[1] = "UP";
	dataLVElectronics->gbuUpshiftInputRequest.statusDefLength = 2;

	initializeDataStatus(&(dataLVElectronics->gbuDownShiftInputRequest));
	dataLVElectronics->gbuDownShiftInputRequest.statusDef[0] = "OFF";
	dataLVElectronics->gbuDownShiftInputRequest.statusDef[1] = "DOWN";
	dataLVElectronics->gbuDownShiftInputRequest.statusDefLength = 2;
}

void setFlagNotUpdatedDataLVElectronics(DataLVElectronics* dataLVElectronics) {
	setNotUpdateData(&(dataLVElectronics->voltageBatteryLV));
	setNotUpdateData(&(dataLVElectronics->throttlePedal));
	setNotUpdateData(&(dataLVElectronics->throttlePosition));
	setNotUpdateData(&(dataLVElectronics->tps1));
	setNotUpdateData(&(dataLVElectronics->tps2));
	setNotUpdateData(&(dataLVElectronics->apps1));
	setNotUpdateData(&(dataLVElectronics->apps2));
	setNotUpdateData(&(dataLVElectronics->bseFront));
	setNotUpdateData(&(dataLVElectronics->bseRear));
	setNotUpdateData(&(dataLVElectronics->ecuCpuUsage));
	setNotUpdateData(&(dataLVElectronics->ecuLed));
	setNotUpdateData(&(dataLVElectronics->ecuTemperature));
}
