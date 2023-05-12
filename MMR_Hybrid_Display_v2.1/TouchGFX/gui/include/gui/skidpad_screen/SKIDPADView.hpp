#ifndef SKIDPADVIEW_HPP
#define SKIDPADVIEW_HPP

#include <gui_generated/skidpad_screen/SKIDPADViewBase.hpp>
#include <gui/skidpad_screen/SKIDPADPresenter.hpp>

class SKIDPADView : public SKIDPADViewBase
{
public:
    SKIDPADView();
    virtual ~SKIDPADView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SKIDPADVIEW_HPP
