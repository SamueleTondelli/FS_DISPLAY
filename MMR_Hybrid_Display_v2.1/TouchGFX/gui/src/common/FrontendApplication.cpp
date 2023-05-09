#include <gui/common/FrontendApplication.hpp>

FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap)
{

}

//MODIFIED

void FrontendApplication::gotoHOMEScreenNoTransition()
{
	transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoHOMEScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}


void FrontendApplication::writeAlarmInBuffers(Alarm* alarm, Unicode::UnicodeChar* nameBuffer, uint16_t nameBufferSize, Unicode::UnicodeChar* valueBuffer, uint16_t valueBufferSize)
{
	if (alarm == NULL || nameBuffer == NULL || valueBuffer == NULL)
	{
		return;
	}

	if (alarm->type == DATA)
	{
		Data* d = (Data*)alarm->contents;
		if (strlen(alarm->name) <= nameBufferSize)
		{
			Unicode::snprintf(nameBuffer, strlen(alarm->name), "%s", alarm->name);
		}
		Unicode::snprintf(valueBuffer, valueBufferSize, "%f", getValueData(d));
	}
}

//END MODIFIEDS
