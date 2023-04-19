// START
#include "TimerHandler.h"
#include "TimersList.h"
#include "Data/Dataset.h"
#include "Data/DataScreen.h"
#include "Data/DataNotification.h"
#include "SDcardHandler.h"
// END

//#define DEBUG_TIMERHANDLER 1

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim5;

extern Dataset ds;

extern TimersList timList;

#ifdef DEBUG_TIMERHANDLER

// DEBUG
extern CAN_HandleTypeDef hcan1;
extern CAN_TxHeaderTypeDef ptxHeader;
extern uint32_t txMailbox;

#endif

void startTimer(TIM_HandleTypeDef* htim) {
	HAL_TIM_Base_Start_IT(htim);
}

void stopTimer(TIM_HandleTypeDef* htim) {
	HAL_TIM_Base_Stop_IT(htim);
}

void timerHandlerOld(TIM_HandleTypeDef *htim) {

	if(htim == &htim1) {	//TIM2 33ms for 30 FPS Display Update

			ds.screen.updateFlag = 1;
	} else if(htim == &htim2) {
		if (ds.screen.isSimulationModeEnabled == 1 && ds.screen.simulationFlag == 1) {

			ds.screen.simulationReadFlag = 1;

			/*
			 * TODO Creare un task per gestire la Simulation Mode
			 * (Inserire questo codice in una routine)
			 */
			/*
			if(ds.screen.simulationReadFlag == 1) {
				int res = readFileRow(sdCard, dataset);
				if (res != 0) {	// Run Time Errors
					dataset->screen.simulationFlag = 0;
					stopSimulationMode(dataset, res, -1);
				}
			}
			*/
		}
	} else if(htim == &htim3) {	//TIM7 1s timeout for FPS counter

		// Update FPS
		setFpsScreen(&(ds.screen), ds.screen.frameCounter);
		cleanFpsCounter(&(ds.screen));
		// Change status blink 1s flag
		changeBlinkFlag(&(ds.screen));

#ifdef DEBUG_TIMERHANDLER
		//DEBUG
		uint8_t dummyData[8] = {0};
		ptxHeader.StdId = 0x100;
		ptxHeader.DLC = 8;
		HAL_CAN_AddTxMessage(&hcan1, &ptxHeader, dummyData, &txMailbox);
#endif

		// Add 1 to the update flag (To set Datas not updated)
		setFlagNotUpdatedDataset(&(ds));

#ifdef DEBUG_TIMERHANDLER
		//DEBUG
		ptxHeader.StdId = 0x101;
		ptxHeader.DLC = 8;
		HAL_CAN_AddTxMessage(&hcan1, &ptxHeader, dummyData, &txMailbox);
#endif
	} else if(htim == &htim4) {	//TIM8 2s for message enable time
	    // Stop Animation Timer
	    stopTimer(&htim4);

#ifdef DEBUG_TIMERHANDLER
	    //DEBUG
		uint8_t dummyData[8] = {0};
		dummyData[0] = ds.screen.screenNameFlag;
		dummyData[1] = ds.screen.notificationFlag;
		dummyData[2] = ds.screen.alarmFlag;
		dummyData[3] = ds.messageErrors.driverMessage.notificationType.status;
		dummyData[4] = ds.messageErrors.driverMessage.notificationLength;
		dummyData[5] = ds.messageErrors.driverMessage.notificationCounter;
		ptxHeader.StdId = 0x200;
		ptxHeader.DLC = 8;
		HAL_CAN_AddTxMessage(&hcan1, &ptxHeader, dummyData, &txMailbox);
#endif

	    // Disable Animation flag
	    ds.screen.screenNameFlag = 0;

#ifdef DEBUG_TIMERHANDLER
	    //DEBUG
		//uint8_t dummyData[8] = {0};
		dummyData[0] = ds.screen.screenNameFlag;
		dummyData[1] = ds.screen.notificationFlag;
		dummyData[2] = ds.screen.alarmFlag;
		dummyData[3] = ds.messageErrors.driverMessage.notificationType.status;
		dummyData[4] = ds.messageErrors.driverMessage.notificationLength;
		dummyData[5] = ds.messageErrors.driverMessage.notificationCounter;
		ptxHeader.StdId = 0x201;
		ptxHeader.DLC = 8;
		HAL_CAN_AddTxMessage(&hcan1, &ptxHeader, dummyData, &txMailbox);
#endif
    } else if(htim == &htim5) {
    	stopTimer(&htim5);
    	// Check if there are Notification Active. If yes de-Activate them
    	checkForNotificationDeActivated2(&ds);
    }
}

void timerHandler(TIM_HandleTypeDef* htim, TimersList* timers, Dataset* dataset) {
/*
	if(htim == timList.timUpdateDisplay) {	// 33ms for 30 FPS Display Update
		dataset->screen.updateFlag = 1;
	} else if(htim == timList.timSimulationModeRead) {	// Simulation Mode Read Row activation Flag
		if (dataset->screen.isSimulationModeEnabled == 1 && dataset->screen.simulationFlag == 1) {

			dataset->screen.simulationReadFlag = 1;

			/*
			 * TODO Creare un task per gestire la Simulation Mode
			 * (Inserire questo codice in una routine)
			 */
			/*
			if(dataset->screen.simulationReadFlag == 1) {
				int res = readFileRow(sdCard, dataset);
				if (res != 0) {	// Run Time Errors
					dataset->screen.simulationFlag = 0;
					stopSimulationMode(dataset, res, -1);
				}
			}
			*/
		/*}
	} else if(htim == timList.tim1sec) {	// 1s timeout for FPS counter, Blink Flag and Not-Update Data

		// Update FPS
		setFpsScreen(&(dataset->screen), dataset->screen.frameCounter);
		cleanFpsCounter(&(dataset->screen));
		// Change status blink 1s flag
		changeBlinkFlag(&(dataset->screen));

#ifdef DEBUG_TIMERHANDLER
		//DEBUG
		uint8_t dummyData[8] = {0};
		ptxHeader.StdId = 0x100;
		ptxHeader.DLC = 8;
		HAL_CAN_AddTxMessage(&hcan1, &ptxHeader, dummyData, &txMailbox);
#endif

		// Add 1 to the update flag (To set Datas not updated)
		setFlagNotUpdatedDataset(dataset);

#ifdef DEBUG_TIMERHANDLER
		//DEBUG
		ptxHeader.StdId = 0x101;
		ptxHeader.DLC = 8;
		HAL_CAN_AddTxMessage(&hcan1, &ptxHeader, dummyData, &txMailbox);
#endif
	} else if(htim == timList.tim2sec) {	//2s for ScreenName enable time
	    // Stop Animation Timer
	    stopTimer(timList.tim2sec);

	    // Disable Animation flag
		dataset->screen.screenNameFlag = 0;

    } else if(htim == timList.tim5sec) {	// 5s for Notification enable Time
    	//stopTimer(&htim5);
    	stopTimer(timList.tim5sec);
#ifdef DEBUG_TIMERHANDLER
	    //DEBUG
		uint8_t dummyData[8] = {0};
		dummyData[0] = ds.screen.screenNameFlag;
		dummyData[1] = ds.screen.notificationFlag;
		dummyData[2] = ds.screen.alarmFlag;
		dummyData[3] = ds.messageErrors.driverMessage.notificationType.status;
		dummyData[4] = ds.messageErrors.driverMessage.notificationLength;
		dummyData[5] = ds.messageErrors.driverMessage.notificationCounter;
		ptxHeader.StdId = 0x200;
		ptxHeader.DLC = 8;
		HAL_CAN_AddTxMessage(&hcan1, &ptxHeader, dummyData, &txMailbox);
#endif
    	// Check if there are Notification Active. If yes de-Activate them
    	//checkForNotificationDeActivated2(&dataset);
    	checkForNotificationDeActivated(dataset, timers);
#ifdef DEBUG_TIMERHANDLER
	    //DEBUG
		//uint8_t dummyData[8] = {0};
		dummyData[0] = ds.screen.screenNameFlag;
		dummyData[1] = ds.screen.notificationFlag;
		dummyData[2] = ds.screen.alarmFlag;
		dummyData[3] = ds.messageErrors.driverMessage.notificationType.status;
		dummyData[4] = ds.messageErrors.driverMessage.notificationLength;
		dummyData[5] = ds.messageErrors.driverMessage.notificationCounter;
		ptxHeader.StdId = 0x201;
		ptxHeader.DLC = 8;
		HAL_CAN_AddTxMessage(&hcan1, &ptxHeader, dummyData, &txMailbox);
#endif
    }
*/}
