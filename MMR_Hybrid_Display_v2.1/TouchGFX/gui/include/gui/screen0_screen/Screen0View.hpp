#ifndef SCREEN0VIEW_HPP
#define SCREEN0VIEW_HPP

#include <gui_generated/screen0_screen/Screen0ViewBase.hpp>
#include <gui/screen0_screen/Screen0Presenter.hpp>

class Screen0View : public Screen0ViewBase
{
public:
    Screen0View();
    virtual ~Screen0View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void updateDisplay();
protected:
};

#endif // SCREEN0VIEW_HPP
