#ifndef ENDURANCEVIEW_HPP
#define ENDURANCEVIEW_HPP

#include <gui_generated/endurance_screen/ENDURANCEViewBase.hpp>
#include <gui/endurance_screen/ENDURANCEPresenter.hpp>

class ENDURANCEView : public ENDURANCEViewBase
{
public:
    ENDURANCEView();
    virtual ~ENDURANCEView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ENDURANCEVIEW_HPP
