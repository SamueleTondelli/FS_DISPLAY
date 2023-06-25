#ifndef DRAGPRESENTER_HPP
#define DRAGPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DRAGView;

class DRAGPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DRAGPresenter(DRAGView& v);

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

    virtual ~DRAGPresenter() {};

    virtual void updateDisplay();

private:
    DRAGPresenter();

    DRAGView& view;
};

#endif // DRAGPRESENTER_HPP
