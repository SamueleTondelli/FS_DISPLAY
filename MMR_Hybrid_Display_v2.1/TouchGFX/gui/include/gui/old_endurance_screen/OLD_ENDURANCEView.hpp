#ifndef OLD_ENDURANCEVIEW_HPP
#define OLD_ENDURANCEVIEW_HPP

#include <gui_generated/old_endurance_screen/OLD_ENDURANCEViewBase.hpp>
#include <gui/old_endurance_screen/OLD_ENDURANCEPresenter.hpp>

class OLD_ENDURANCEView : public OLD_ENDURANCEViewBase
{
public:
    OLD_ENDURANCEView();
    virtual ~OLD_ENDURANCEView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // OLD_ENDURANCEVIEW_HPP
