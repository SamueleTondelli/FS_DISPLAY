#ifndef SETUPVIEW_HPP
#define SETUPVIEW_HPP

#include <gui_generated/setup_screen/SETUPViewBase.hpp>
#include <gui/setup_screen/SETUPPresenter.hpp>

class SETUPView : public SETUPViewBase
{
public:
    SETUPView();
    virtual ~SETUPView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETUPVIEW_HPP
