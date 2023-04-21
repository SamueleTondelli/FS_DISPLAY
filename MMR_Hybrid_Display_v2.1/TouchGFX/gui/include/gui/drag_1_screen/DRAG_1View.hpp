#ifndef DRAG_1VIEW_HPP
#define DRAG_1VIEW_HPP

#include <gui_generated/drag_1_screen/DRAG_1ViewBase.hpp>
#include <gui/drag_1_screen/DRAG_1Presenter.hpp>

class DRAG_1View : public DRAG_1ViewBase
{
public:
    DRAG_1View();
    virtual ~DRAG_1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // DRAG_1VIEW_HPP
