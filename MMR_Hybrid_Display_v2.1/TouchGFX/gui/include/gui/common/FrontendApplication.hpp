#ifndef FRONTENDAPPLICATION_HPP
#define FRONTENDAPPLICATION_HPP

#include <gui_generated/common/FrontendApplicationBase.hpp>
#include "Data/Data.h"

class FrontendHeap;

using namespace touchgfx;

class FrontendApplication : public FrontendApplicationBase
{
public:
    FrontendApplication(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplication() { }

    //MODIFIED
    void gotoHOMEScreenNoTransition();
    //missing DRAG and DRAG_2 screen transitions

    static void writeAlarmInBuffers(Alarm* alarm, touchgfx::Unicode::UnicodeChar* nameBuffer, uint16_t nameBufferSize, touchgfx::Unicode::UnicodeChar* valueBuffer, uint16_t valueBufferSize);

    //END MODIFIED

    virtual void handleTickEvent()
    {
        model.tick();
        FrontendApplicationBase::handleTickEvent();
    }
private:
};

#endif // FRONTENDAPPLICATION_HPP
