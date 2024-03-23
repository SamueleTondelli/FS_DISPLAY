#ifndef OLD_DRAGVIEW_HPP
#define OLD_DRAGVIEW_HPP

#include <gui_generated/old_drag_screen/OLD_DRAGViewBase.hpp>
#include <gui/old_drag_screen/OLD_DRAGPresenter.hpp>

class OLD_DRAGView : public OLD_DRAGViewBase
{
public:
    OLD_DRAGView();
    virtual ~OLD_DRAGView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // OLD_DRAGVIEW_HPP
