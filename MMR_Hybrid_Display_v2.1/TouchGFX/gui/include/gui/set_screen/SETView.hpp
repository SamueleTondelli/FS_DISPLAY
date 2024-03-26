#ifndef SETVIEW_HPP
#define SETVIEW_HPP

#include <gui_generated/set_screen/SETViewBase.hpp>
#include <gui/set_screen/SETPresenter.hpp>

class SETView : public SETViewBase
{
public:
    SETView();
    virtual ~SETView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETVIEW_HPP
