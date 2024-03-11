#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include <gui/common/FrontendApplication.hpp>

#include "main_application.hpp"

extern TIM_HandleTypeDef htim4;
extern IWDG_HandleTypeDef hiwdg;

Model::Model() : modelListener(0), currentScreenIndex(0) {

}

void Model::tick() {
	HAL_IWDG_Refresh(&hiwdg);
	if (mainApp.currentPageChanged()) {
		switch (mainApp.getCurrentPage()) {
		default:
		}
	}
	updateDisplay();
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

