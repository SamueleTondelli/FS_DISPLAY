#ifndef SCREEN0PRESENTER_HPP
#define SCREEN0PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screen0View;

class Screen0Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    Screen0Presenter(Screen0View& v);

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

    virtual ~Screen0Presenter() {};

    virtual void updateDisplay();

private:
    Screen0Presenter();

    Screen0View& view;
};

#endif // SCREEN0PRESENTER_HPP
