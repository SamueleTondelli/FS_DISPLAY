#include <gui/setup_screen/SETUPView.hpp>
#include <gui/common/FrontendApplication.hpp>
#include "Data/Dataset.h"

extern Dataset ds;

SETUPView::SETUPView()
{

}

void SETUPView::setupScreen()
{
    SETUPViewBase::setupScreen();
}

void SETUPView::tearDownScreen()
{
    SETUPViewBase::tearDownScreen();
}

void SETUPView::updateDisplay()
{
	FrontendApplication::writeFloatDataInBuffer(&(ds.mechanics.carHeightFL), txtFLBuffer, TXTFL_SIZE, &txtFL);
	FrontendApplication::writeFloatDataInBuffer(&(ds.mechanics.carHeightFR), txtFRBuffer, TXTFR_SIZE, &txtFR);
	FrontendApplication::writeFloatDataInBuffer(&(ds.mechanics.carHeightRL), txtRLBuffer, TXTRL_SIZE, &txtRL);
	FrontendApplication::writeFloatDataInBuffer(&(ds.mechanics.carHeightRR), txtRRBuffer, TXTRR_SIZE, &txtRR);
	FrontendApplication::writeIntDataInBuffer(&(ds.controls.steer), txtSteeringWheelBuffer, TXTSTEERINGWHEEL_SIZE, &txtSteeringWheel);
}
