#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{
	model->saveCurrentScreenIndex(1);
}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::updateDisplay() {
	view.updateDisplay();
}
