#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include <gui/common/FrontendApplication.hpp>

#include "Data/Dataset.h"
#include "TimerHandler.h"

#define DEBUG_MODEL 1

extern Dataset ds;
extern TimersList timList;
extern TIM_HandleTypeDef htim4;
extern IWDG_HandleTypeDef hiwdg;

#ifdef DEBUG_MODEL
//DEBUG
extern CAN_HandleTypeDef hcan1;
extern CAN_TxHeaderTypeDef ptxHeader;
extern uint32_t txMailbox;
#endif

Model::Model() : modelListener(0), currentScreenIndex(0) {

}

void Model::tick() {
	if(ds.screen.updateFlag) {
		ds.screen.updateFlag = 0;

		// Display Sanity Check
		HAL_IWDG_Refresh(&hiwdg);

		// Check for Changed Screen Event
		uint8_t currentScreen = Model::getCurrentScreenIndex();

		if(ds.screen.introductionPresentationFlag == 1) {
			updateDisplay();
			return;
		}

		uint8_t screen = getCurrentScreen(&(ds.screen));

		if(screen != currentScreen) {
			// To active Animation Screen Name
			ds.screen.screenNameFlag = 1;

			//startTimer(&htim4);
			startTimer(timList.tim2sec);

			switch (screen)
			{
			case HOME:
				static_cast<FrontendApplication*>(Application::getInstance())->gotoHOMEScreenNoTransition();
				break;
			case DRAG:
				//call gotoDRAGScreen
				break;
			case DRAG_2:
				//call gotoDRAGScreen
				break;
			default:
				updateDisplay();
			}
		} else {
			updateDisplay();
		}
	}
}

void Model::saveCurrentScreenIndex(uint8_t cScreen) {
	currentScreenIndex = cScreen;
}

uint8_t Model::getCurrentScreenIndex() {
	return currentScreenIndex;
}

void Model::updateDisplay() {

	ds.screen.frameCounter++;

	modelListener->updateDisplay();
}

