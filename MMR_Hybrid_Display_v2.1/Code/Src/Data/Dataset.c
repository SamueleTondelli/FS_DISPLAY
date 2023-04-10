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
}

void setFlagNotUpdatedDataset(Dataset* dataset) {
	setFlagNotUpdatedDataThermalPressure(&(dataset->thermalPressure));
	setFlagNotUpdatedDataMechanics(&(dataset->mechanics));
	setFlagNotUpdatedDataControls(&(dataset->controls));
}
