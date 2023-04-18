#ifndef SCREEN1COMBUSTIONVIEW_HPP
#define SCREEN1COMBUSTIONVIEW_HPP

#include <gui_generated/screen1combustion_screen/Screen1CombustionViewBase.hpp>
#include <gui/screen1combustion_screen/Screen1CombustionPresenter.hpp>

class Screen1CombustionView : public Screen1CombustionViewBase
{
public:
    Screen1CombustionView();
    virtual ~Screen1CombustionView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREEN1COMBUSTIONVIEW_HPP
