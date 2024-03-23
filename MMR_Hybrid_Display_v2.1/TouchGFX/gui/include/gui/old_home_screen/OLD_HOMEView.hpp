#ifndef OLD_HOMEVIEW_HPP
#define OLD_HOMEVIEW_HPP

#include <gui_generated/old_home_screen/OLD_HOMEViewBase.hpp>
#include <gui/old_home_screen/OLD_HOMEPresenter.hpp>

class OLD_HOMEView : public OLD_HOMEViewBase
{
public:
    OLD_HOMEView();
    virtual ~OLD_HOMEView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // OLD_HOMEVIEW_HPP
