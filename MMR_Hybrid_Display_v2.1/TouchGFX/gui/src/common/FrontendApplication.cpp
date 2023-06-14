#include <gui/common/FrontendApplication.hpp>

#include <touchgfx/Color.hpp>

FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap)
{

}

//MODIFIED

extern uint8_t invalidateCurrentAlarmFlag; //bad, move to somewhere else

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

Alarm* FrontendApplication::getCurrentAlarm()
{
	static Alarm a = {.contents = NULL};
	return &a;
}

void FrontendApplication::handleAlarms(touchgfx::Container* ctAlarm, Unicode::UnicodeChar* nameBuffer, uint16_t nameBufferSize, Unicode::UnicodeChar* valueBuffer, uint16_t valueBufferSize, BoxWithBorder* bxAlarm)
{
	Alarm* currentAlarm = FrontendApplication::getCurrentAlarm();
	static uint32_t currentAlarmStartTime;
	ctAlarm->setVisible(true);

	//if it's first time we enter here, we initialize currentAlarm and get the timestamp at which the alarm starts
	if (currentAlarm->contents == NULL)
	{
		*currentAlarm = extractAlarmFromQueue();
		currentAlarmStartTime = uwTick;
	}

	/*Alarms works by having a not interruptable time, which unless the button is pressed we show the alarm even if there's an alarm after with a higher priority,
	  after that if there's an alarm with same or lower priority (more important), we switch to that, otherwise we give a bonus time to the current alarm because
	  it's more important
	*/
	//TODO: improve
	if ((invalidateCurrentAlarmFlag == 1) || (uwTick - currentAlarmStartTime >= ALARM_AUTOMATIC_TIMEOUT_TIME))
	{
		deactivateAlarm(currentAlarm);
		invalidateCurrentAlarmFlag = 0;
	}
	else
	{
		if (uwTick - currentAlarmStartTime < ALARM_NOT_INTERRUPTABLE_TIME)
		{
			if ((getAlarmStatus(currentAlarm) == ON) || currentAlarm->priority == NOTIFICATION_PRIORITY) //if the alarm has lowest priority, it means it's a notification, therefore we need to show it for the whole non interruptible time
			{
				FrontendApplication::writeAlarmInBuffers(currentAlarm, nameBuffer, nameBufferSize, valueBuffer, valueBufferSize, bxAlarm);
			}
			else
			{
				ctAlarm->setVisible(false);
				currentAlarm->contents = NULL;
			}
		}
		else
		{
			Alarm* nextAlarm = peekAlarmFromQueue();
			if (nextAlarm != NULL)
			{
				if (nextAlarm->priority <= currentAlarm->priority || (uwTick - currentAlarmStartTime >= ALARM_NOT_INTERRUPTABLE_TIME + ALARM_BONUS_TIME))
				{
					if (currentAlarm->type == DATA)
					{
						Data* data = (Data*)currentAlarm->contents;
						data->alarmStatus = OFF_QUEUE; //so we can insert again the alarm in the queue
					}
					else
					{
						//telemetry
					}
					//we invalidate current alarm
					currentAlarm->contents = NULL;
				}
				else
				{
					if (getAlarmStatus(currentAlarm) == ON)
					{
						FrontendApplication::writeAlarmInBuffers(currentAlarm, nameBuffer, nameBufferSize, valueBuffer, valueBufferSize, bxAlarm);
					}
					else
					{
						ctAlarm->setVisible(false);
						currentAlarm->contents = NULL;
					}
				}
			}
			else
			{
				if (getAlarmStatus(currentAlarm) == ON)
				{
					FrontendApplication::writeAlarmInBuffers(currentAlarm, nameBuffer, nameBufferSize, valueBuffer, valueBufferSize, bxAlarm);
				}
				else
				{
					ctAlarm->setVisible(false);
					currentAlarm->contents = NULL;
				}
			}
		}
	}

	ctAlarm->invalidate();
}

//END MODIFIEDS
