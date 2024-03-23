#ifndef OLD_DRAGPRESENTER_HPP
#define OLD_DRAGPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class OLD_DRAGView;

class OLD_DRAGPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    OLD_DRAGPresenter(OLD_DRAGView& v);

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

    virtual ~OLD_DRAGPresenter() {};

private:
    OLD_DRAGPresenter();

    OLD_DRAGView& view;
};

#endif // OLD_DRAGPRESENTER_HPP
