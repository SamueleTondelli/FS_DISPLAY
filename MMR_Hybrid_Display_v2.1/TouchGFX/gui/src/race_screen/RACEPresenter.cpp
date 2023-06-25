#include <gui/race_screen/RACEView.hpp>
#include <gui/race_screen/RACEPresenter.hpp>

RACEPresenter::RACEPresenter(RACEView& v)
    : view(v)
{

}

void RACEPresenter::activate()
{

}

void RACEPresenter::deactivate()
{

}

void RACEPresenter::updateDisplay()
{
	view.updateDisplay();
}
