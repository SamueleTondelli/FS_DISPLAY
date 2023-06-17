// START
#include "Data/Dataset.h"
#include "TimerHandler.h"
#include "SimulationMode.h"
#include "SDcardHandler.h"
// END

#define DEBUG_DATASET 1

extern TIM_HandleTypeDef htim5;

#ifdef DEBUG_DATASET
//DEBUG
extern CAN_HandleTypeDef hcan1;
extern CAN_TxHeaderTypeDef ptxHeader;
extern uint32_t txMailbox;
#endif

void initializeDataset(Dataset *dataset) {
	initializeDataThermalPressure(&(dataset->thermalPressure));
	initializeDataMechanics(&(dataset->mechanics));
	initializeDataControls(&(dataset->controls));
	initializeDataScreen(&(dataset->screen));

	setMessage(&(dataset->telemetryMessage[0]), "STOP");
	setPriority(&(dataset->telemetryMessage[0]), 0);
	setMessage(&(dataset->telemetryMessage[0]), "BOX");
	setPriority(&(dataset->telemetryMessage[0]), 2);
	setMessage(&(dataset->telemetryMessage[0]), "COOLDOWN");
	setPriority(&(dataset->telemetryMessage[0]), 3);

	initializeButton(&(dataset->okBtn), OK_BTN_GPIO_Port, OK_BTN_Pin);
	initializeButton(&(dataset->dispBtn), DISP_BTN_GPIO_Port, DISP_BTN_Pin);
	initializeButton(&(dataset->markBtn), MARK_BTN_GPIO_Port, MARK_BTN_Pin);
	initializeButton(&(dataset->mapBtn), MAP_BTN_GPIO_Port, MAP_BTN_Pin);
}

void setFlagNotUpdatedDataset(Dataset* dataset) {
	setFlagNotUpdatedDataThermalPressure(&(dataset->thermalPressure));
	setFlagNotUpdatedDataMechanics(&(dataset->mechanics));
	setFlagNotUpdatedDataControls(&(dataset->controls));
}
