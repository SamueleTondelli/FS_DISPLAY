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


void writeAlarmInBuffers(Alarm* alarm, touchgfx::Unicode::UnicodeChar* nameBuffer, uint16_t nameBufferSize, touchgfx::Unicode::UnicodeChar* valueBuffer, uint16_t valueBufferSize)
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

//END MODIFIED
