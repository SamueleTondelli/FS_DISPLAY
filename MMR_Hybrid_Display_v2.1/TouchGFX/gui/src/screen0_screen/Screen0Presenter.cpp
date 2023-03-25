#include <gui/screen0_screen/Screen0View.hpp>
#include <gui/screen0_screen/Screen0Presenter.hpp>

Screen0Presenter::Screen0Presenter(Screen0View& v)
    : view(v)
{

}

void Screen0Presenter::activate()
{
	model->saveCurrentScreenIndex(0);
}

void Screen0Presenter::deactivate()
{

}

void Screen0Presenter::updateDisplay() {
	view.updateDisplay();
}
