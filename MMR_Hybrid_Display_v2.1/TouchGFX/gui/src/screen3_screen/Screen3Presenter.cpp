#include <gui/screen3_screen/Screen3View.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>

Screen3Presenter::Screen3Presenter(Screen3View& v)
    : view(v)
{

}

void Screen3Presenter::activate()
{
	model->saveCurrentScreenIndex(3);
}

void Screen3Presenter::deactivate()
{

}

void Screen3Presenter::updateDisplay() {
	view.updateDisplay();
}
