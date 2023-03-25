#ifndef TIMERHANDLER_H
#define TIMERHANDLER_H

#ifdef __cplusplus
extern "C" {
#endif

// START
#include "tim.h"
#include "Data/Dataset.h"
#include "TimersList.h"
#include "SDcardHandler.h"
// END

/*
 * Start a selected Timer
 * @param *htim 		-> TIM_HandleTypeDef 
 */
void startTimer(TIM_HandleTypeDef* htim);
/*
 * Stop a selected Timer
 * @param *htim 		-> TIM_HandleTypeDef
 */
void stopTimer(TIM_HandleTypeDef* htim);
/*
 * Handle all Timers Callback and contains all the logic related to them
 * @param *htim 		-> TIM_HandleTypeDef
 * @param *timers 		-> Timers
 * @param *dataset 		-> Dataset
 */
void timerHandler(TIM_HandleTypeDef* htim, TimersList* timers, Dataset* dataset);
void timerHandlerOld(TIM_HandleTypeDef *htim);

#ifdef __cplusplus
}
#endif

#endif /* TIMERHANDLER_H */
