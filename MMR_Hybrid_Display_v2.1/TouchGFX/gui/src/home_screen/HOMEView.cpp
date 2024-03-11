#include <gui/home_screen/HOMEView.hpp>
#include <gui/common/FrontendApplication.hpp>
HOMEView::HOMEView()
{
	ctAlarm.setVisible(false);
	ctScreenName.setVisible(true);
}

void HOMEView::setupScreen()
{
    HOMEViewBase::setupScreen();
}

void HOMEView::tearDownScreen()
{
    HOMEViewBase::tearDownScreen();
}

void HOMEView::updateDisplay()
{
}
