#ifndef OLD_RACEPRESENTER_HPP
#define OLD_RACEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class OLD_RACEView;

class OLD_RACEPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    OLD_RACEPresenter(OLD_RACEView& v);

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

    virtual ~OLD_RACEPresenter() {};

private:
    OLD_RACEPresenter();

    OLD_RACEView& view;
};

#endif // OLD_RACEPRESENTER_HPP
