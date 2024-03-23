#ifndef OLD_RACEVIEW_HPP
#define OLD_RACEVIEW_HPP

#include <gui_generated/old_race_screen/OLD_RACEViewBase.hpp>
#include <gui/old_race_screen/OLD_RACEPresenter.hpp>

class OLD_RACEView : public OLD_RACEViewBase
{
public:
    OLD_RACEView();
    virtual ~OLD_RACEView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // OLD_RACEVIEW_HPP
