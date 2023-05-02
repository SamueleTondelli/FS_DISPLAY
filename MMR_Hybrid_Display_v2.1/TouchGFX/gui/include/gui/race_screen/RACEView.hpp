#ifndef RACEVIEW_HPP
#define RACEVIEW_HPP

#include <gui_generated/race_screen/RACEViewBase.hpp>
#include <gui/race_screen/RACEPresenter.hpp>

class RACEView : public RACEViewBase
{
public:
    RACEView();
    virtual ~RACEView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RACEVIEW_HPP
