#ifndef DRAG_1PRESENTER_HPP
#define DRAG_1PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DRAG_1View;

class DRAG_1Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    DRAG_1Presenter(DRAG_1View& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~DRAG_1Presenter() {};

private:
    DRAG_1Presenter();

    DRAG_1View& view;
};

#endif // DRAG_1PRESENTER_HPP
