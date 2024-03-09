// START
#include "TimersList.h"
// END

void initializeTimersList(TimersList* timers, TIM_HandleTypeDef* htim, uint8_t timerNumber) {
	if (timerNumber < 0)
		return;

	switch (timerNumber) {
		case 1:
			timers->timUpdateDisplay = htim;
			break;
		case 2:
			timers->timSimulationModeRead = htim;
			break;
		case 3:
			timers->tim1sec = htim;
			break;
		case 4:
			timers->tim2sec = htim;
			break;
		case 5:
			timers->tim5sec = htim;
			break;
		default:
			break;
	}
}
