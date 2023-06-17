#ifndef FRONTENDAPPLICATION_HPP
#define FRONTENDAPPLICATION_HPP

#include <gui_generated/common/FrontendApplicationBase.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include "DisplayConstant.h"
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

    void gotoRACEScreenNoTransition();

    void gotoDRAGScreenNoTransition();

    void gotoENDURANCEScreenNoTransition();

    void gotoSKIDPADScreenNoTransition();

    void gotoSETUPScreenNoTransition();

    static void writeIntDataInBuffer(Data* data, Unicode::UnicodeChar* buffer, uint16_t bufferSize, TextAreaWithOneWildcard* txtArea);

    static void writeFloatDataInBuffer(Data* data, Unicode::UnicodeChar* buffer, uint16_t bufferSize, TextAreaWithOneWildcard* txtArea);

    static void writeAlarmInBuffers(Alarm* alarm, Unicode::UnicodeChar* nameBuffer, uint16_t nameBufferSize, Unicode::UnicodeChar* valueBuffer, uint16_t valueBufferSize, BoxWithBorder* bxAlarm);

    static Alarm* getCurrentAlarm();

    static void handleAlarms(touchgfx::Container* ctAlarm, Unicode::UnicodeChar* nameBuffer, uint16_t nameBufferSize, Unicode::UnicodeChar* valueBuffer, uint16_t valueBufferSize, BoxWithBorder* bxAlarm);

    //END MODIFIED

    virtual void handleTickEvent()
    {
        model.tick();
        FrontendApplicationBase::handleTickEvent();
    }
private:
};

#endif // FRONTENDAPPLICATION_HPP
