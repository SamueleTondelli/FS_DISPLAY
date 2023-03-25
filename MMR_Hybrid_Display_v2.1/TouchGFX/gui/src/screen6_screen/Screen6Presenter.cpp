#include <gui/screen6_screen/Screen6View.hpp>
#include <gui/screen6_screen/Screen6Presenter.hpp>

Screen6Presenter::Screen6Presenter(Screen6View& v)
    : view(v)
{

}

void Screen6Presenter::activate()
{
	model->saveCurrentScreenIndex(6);
}

void Screen6Presenter::deactivate()
{

}

void Screen6Presenter::updateDisplay() {
	view.updateDisplay();
}
