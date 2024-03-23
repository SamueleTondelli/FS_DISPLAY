#ifndef OLD_SETUPPRESENTER_HPP
#define OLD_SETUPPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class OLD_SETUPView;

class OLD_SETUPPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    OLD_SETUPPresenter(OLD_SETUPView& v);

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

    virtual ~OLD_SETUPPresenter() {};

private:
    OLD_SETUPPresenter();

    OLD_SETUPView& view;
};

#endif // OLD_SETUPPRESENTER_HPP
