#ifndef FRONTENDAPPLICATION_HPP
#define FRONTENDAPPLICATION_HPP

#include <gui_generated/common/FrontendApplicationBase.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
class FrontendHeap;

using namespace touchgfx;

class FrontendApplication : public FrontendApplicationBase
{
public:
    FrontendApplication(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplication() { }

    //MODIFIED

    void gotoHOMEScreenNoTransition();

    void gotoRACEScreenNoTransition();

    void gotoDRAGScreenNoTransition();

    void gotoENDURANCEScreenNoTransition();

    void gotoSKIDPADScreenNoTransition();

    void gotoSETUPScreenNoTransition();

    //END MODIFIED

    virtual void handleTickEvent()
    {
        model.tick();
        FrontendApplicationBase::handleTickEvent();
    }
private:
};

#endif // FRONTENDAPPLICATION_HPP
