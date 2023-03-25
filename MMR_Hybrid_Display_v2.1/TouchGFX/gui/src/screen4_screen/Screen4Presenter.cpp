#include <gui/screen4_screen/Screen4View.hpp>
#include <gui/screen4_screen/Screen4Presenter.hpp>

Screen4Presenter::Screen4Presenter(Screen4View& v)
    : view(v)
{

}

void Screen4Presenter::activate()
{
	model->saveCurrentScreenIndex(4);
}

void Screen4Presenter::deactivate()
{

}

void Screen4Presenter::updateDisplay() {
	view.updateDisplay();
}
