#ifndef DRAG_2VIEW_HPP
#define DRAG_2VIEW_HPP

#include <gui_generated/drag_2_screen/DRAG_2ViewBase.hpp>
#include <gui/drag_2_screen/DRAG_2Presenter.hpp>

class DRAG_2View : public DRAG_2ViewBase
{
public:
    DRAG_2View();
    virtual ~DRAG_2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // DRAG_2VIEW_HPP
