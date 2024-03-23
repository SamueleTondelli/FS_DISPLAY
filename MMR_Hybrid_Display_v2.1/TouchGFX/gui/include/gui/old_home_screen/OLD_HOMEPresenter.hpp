#ifndef OLD_HOMEPRESENTER_HPP
#define OLD_HOMEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class OLD_HOMEView;

class OLD_HOMEPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    OLD_HOMEPresenter(OLD_HOMEView& v);

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

    virtual ~OLD_HOMEPresenter() {};

private:
    OLD_HOMEPresenter();

    OLD_HOMEView& view;
};

#endif // OLD_HOMEPRESENTER_HPP
