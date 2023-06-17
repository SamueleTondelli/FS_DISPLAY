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
		uint8_t screen = getCurrentScreen(&(ds.screen));

		if(screen != currentScreen) {

			//startTimer(&htim4);
			startTimer(timList.tim2sec);

			switch (screen)
			{
			case HOME:
				static_cast<FrontendApplication*>(Application::getInstance())->gotoHOMEScreenNoTransition();
				break;
			case RACE:
				static_cast<FrontendApplication*>(Application::getInstance())->gotoRACEScreenNoTransition();
				break;
			case DRAG:
				static_cast<FrontendApplication*>(Application::getInstance())->gotoDRAGScreenNoTransition();
				break;
			case ENDURANCE:
				static_cast<FrontendApplication*>(Application::getInstance())->gotoENDURANCEScreenNoTransition();
				break;
			case SKIDPAD:
				static_cast<FrontendApplication*>(Application::getInstance())->gotoSKIDPADScreenNoTransition();
				break;
			case SETUP:
				static_cast<FrontendApplication*>(Application::getInstance())->gotoSETUPScreenNoTransition();
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

