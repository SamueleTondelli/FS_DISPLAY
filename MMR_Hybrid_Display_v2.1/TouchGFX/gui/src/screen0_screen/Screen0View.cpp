#include <gui/screen0_screen/Screen0View.hpp>

#include "Data/Dataset.h"
#include "TimersList.h"
#include "TimerHandler.h"

extern Dataset ds;
extern TimersList timList;
extern TIM_HandleTypeDef htim4;

Screen0View::Screen0View() {
	imgLogo1.setAlpha(0);
	imgLogo1.startFadeAnimation(255, 50, EasingEquations::linearEaseNone);
	imgLogo1.invalidate();

	imgLogo2.setAlpha(0);
	imgLogo2.invalidate();

	Screen0View::updateDisplay();
}

void Screen0View::setupScreen() {
    Screen0ViewBase::setupScreen();
}

void Screen0View::tearDownScreen() {
    Screen0ViewBase::tearDownScreen();
}

void Screen0View::updateDisplay() {

	if((ds.screen.counterFrameIntroductionPresentation == (DISPLAY_FPS*(PRESENTATION_DURATION-3.5f)))) {
		imgLogo1.startFadeAnimation(0, 20, EasingEquations::linearEaseNone);
		imgLogo2.startFadeAnimation(255, 100, EasingEquations::linearEaseNone);
	}

	ds.screen.counterFrameIntroductionPresentation++;
	if(ds.screen.counterFrameIntroductionPresentation > (DISPLAY_FPS*PRESENTATION_DURATION)) {
		ds.screen.introductionPresentationFlag = 0;
		//startTimer(&htim4);
		startTimer(timList.tim2sec);
	}
}
