#ifndef DRAGVIEW_HPP
#define DRAGVIEW_HPP

#include <gui_generated/drag_screen/DRAGViewBase.hpp>
#include <gui/drag_screen/DRAGPresenter.hpp>

class DRAGView : public DRAGViewBase
{
public:
    DRAGView();
    virtual ~DRAGView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void updateDisplay();
protected:
};

#endif // DRAGVIEW_HPP
