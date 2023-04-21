#ifndef DRAG_2PRESENTER_HPP
#define DRAG_2PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DRAG_2View;

class DRAG_2Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    DRAG_2Presenter(DRAG_2View& v);

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

    virtual ~DRAG_2Presenter() {};

private:
    DRAG_2Presenter();

    DRAG_2View& view;
};

#endif // DRAG_2PRESENTER_HPP
