#ifndef ENDURANCEPRESENTER_HPP
#define ENDURANCEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ENDURANCEView;

class ENDURANCEPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ENDURANCEPresenter(ENDURANCEView& v);

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

    virtual ~ENDURANCEPresenter() {};

    virtual void updateDisplay();
private:
    ENDURANCEPresenter();

    ENDURANCEView& view;
};

#endif // ENDURANCEPRESENTER_HPP
