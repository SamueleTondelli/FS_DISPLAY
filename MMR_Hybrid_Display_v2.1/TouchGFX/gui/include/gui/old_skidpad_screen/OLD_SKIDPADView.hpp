#ifndef OLD_SKIDPADVIEW_HPP
#define OLD_SKIDPADVIEW_HPP

#include <gui_generated/old_skidpad_screen/OLD_SKIDPADViewBase.hpp>
#include <gui/old_skidpad_screen/OLD_SKIDPADPresenter.hpp>

class OLD_SKIDPADView : public OLD_SKIDPADViewBase
{
public:
    OLD_SKIDPADView();
    virtual ~OLD_SKIDPADView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // OLD_SKIDPADVIEW_HPP
