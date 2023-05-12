#include <gui/common/FrontendApplication.hpp>

#include <touchgfx/Color.hpp>

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

void FrontendApplication::writeIntDataInBuffer(Data* data, Unicode::UnicodeChar* buffer, uint16_t bufferSize, TextAreaWithOneWildcard* txtArea)
{
	int value = getValueData(data);
	if (value != EMPTY_VALUE)
	{
		Unicode::snprintf(buffer, bufferSize, "%d", value);
		txtArea->invalidate();
	}
	else
	{
		buffer[0] = 'N';
		if (bufferSize >= 2)
		{
			buffer[1] = 'A';
		}
	}
}

void FrontendApplication::writeFloatDataInBuffer(Data* data, Unicode::UnicodeChar* buffer, uint16_t bufferSize, TextAreaWithOneWildcard* txtArea)
{
	float value = getValueData(data);
	if (value != EMPTY_VALUE)
	{
		Unicode::snprintf(buffer, bufferSize, "%.1f", value);
		txtArea->invalidate();
	}
	else
	{
		buffer[0] = 'N';
		if (bufferSize >= 2)
		{
			buffer[1] = 'A';
		}
	}
}

void FrontendApplication::writeAlarmInBuffers(Alarm* alarm, Unicode::UnicodeChar* nameBuffer, uint16_t nameBufferSize, Unicode::UnicodeChar* valueBuffer, uint16_t valueBufferSize, BoxWithBorder* bxAlarm)
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

		if (alarm->priority == NOTIFICATION_PRIORITY)
		{
			bxAlarm->setColor(Color::getColorFromRGB(60, 255, 202));
		}
		else
		{
			if (isDataCritical(d) < 0)
			{
				bxAlarm->setColor(Color::getColorFromRGB(3, 32, 255));
			}
			else
			{
				bxAlarm->setColor(Color::getColorFromRGB(255, 0, 0));
			}
		}
	}
}

//END MODIFIEDS
