#ifndef WARMUPVIEW_HPP
#define WARMUPVIEW_HPP

#include <gui_generated/warmup_screen/WARMUPViewBase.hpp>
#include <gui/warmup_screen/WARMUPPresenter.hpp>

class WARMUPView : public WARMUPViewBase
{
public:
    WARMUPView();
    virtual ~WARMUPView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // WARMUPVIEW_HPP
