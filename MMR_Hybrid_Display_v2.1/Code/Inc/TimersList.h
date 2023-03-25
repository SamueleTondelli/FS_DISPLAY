#ifndef TIMERS_LIST_H
#define TIMERS_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

// START
#include "tim.h"
// END

typedef struct {				// TODO Cambiare nomi htimX con nomi consoni al compito del timer
	TIM_HandleTypeDef* timUpdateDisplay;	// Update Screen Display 								[each 0.030s]
	TIM_HandleTypeDef* timSimulationModeRead;	// Read a row in Simulation Mode and update Datas	[each 0.250s]
	TIM_HandleTypeDef* tim1sec;				// Update FPS, Blink Flag, Data Not Updated Routine 	[each 1s]
	TIM_HandleTypeDef* tim2sec;				// Screen Name Flag 									[each 2s]
	TIM_HandleTypeDef* tim5sec;				// Notification Flag 									[each 5s]
}TimersList;
/*
 * Initialize Timers Struct
 * @param *timers		 		-> Timers Struct
 * @param *htim 				-> TIM_HandleTypeDef timer
 * @param timerNumber 			-> which timer in Timers Struct
 */
void initializeTimersList(TimersList* timers, TIM_HandleTypeDef* htim, uint8_t timerNumber);

#ifdef __cplusplus
}
#endif

#endif /* TIMERS_LIST_H */
