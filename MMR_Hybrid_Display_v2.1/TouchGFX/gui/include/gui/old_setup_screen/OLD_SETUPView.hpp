#ifndef OLD_SETUPVIEW_HPP
#define OLD_SETUPVIEW_HPP

#include <gui_generated/old_setup_screen/OLD_SETUPViewBase.hpp>
#include <gui/old_setup_screen/OLD_SETUPPresenter.hpp>

class OLD_SETUPView : public OLD_SETUPViewBase
{
public:
    OLD_SETUPView();
    virtual ~OLD_SETUPView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // OLD_SETUPVIEW_HPP
