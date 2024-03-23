#ifndef OLD_SKIDPADPRESENTER_HPP
#define OLD_SKIDPADPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class OLD_SKIDPADView;

class OLD_SKIDPADPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    OLD_SKIDPADPresenter(OLD_SKIDPADView& v);

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

    virtual ~OLD_SKIDPADPresenter() {};

private:
    OLD_SKIDPADPresenter();

    OLD_SKIDPADView& view;
};

#endif // OLD_SKIDPADPRESENTER_HPP
