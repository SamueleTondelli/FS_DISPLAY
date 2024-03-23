#ifndef OLD_ENDURANCEPRESENTER_HPP
#define OLD_ENDURANCEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class OLD_ENDURANCEView;

class OLD_ENDURANCEPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    OLD_ENDURANCEPresenter(OLD_ENDURANCEView& v);

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

    virtual ~OLD_ENDURANCEPresenter() {};

private:
    OLD_ENDURANCEPresenter();

    OLD_ENDURANCEView& view;
};

#endif // OLD_ENDURANCEPRESENTER_HPP
