#include <gui/drag_screen/DRAGView.hpp>
#include <gui/drag_screen/DRAGPresenter.hpp>

DRAGPresenter::DRAGPresenter(DRAGView& v)
    : view(v)
{

}

void DRAGPresenter::activate()
{

}

void DRAGPresenter::deactivate()
{

}

void DRAGPresenter::updateDisplay()
{
	view.updateDisplay();
}
