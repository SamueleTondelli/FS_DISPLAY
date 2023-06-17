#include <gui/common/FrontendApplication.hpp>

#include <touchgfx/Color.hpp>

FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap)
{

}

//MODIFIED

#include "Data/Dataset.h"

extern Dataset ds;

enum HANDLEALARM_STATUS {
	NO_ALARM, //no active alarma
	ALARM_NOTINT, //alarm in not interruptible
	ALARM_BONUST, //giving alarm bonus time
	ALARM_INT, //alarm is interruptible
	DEACTIVATE_ALARM //deactivation of current alarm, either with flag or timeout
};

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

	//antiflicker
	static uint32_t lastValueUpdate = 0;

	Unicode::strncpy(nameBuffer, alarm->name, nameBufferSize);

	switch (alarm->type)
	{
	case DATA: {
		if (lastValueUpdate != 0 && (uwTick - lastValueUpdate) < ANTI_FLICKER_TIME)
		{
			return;
		}
		lastValueUpdate = uwTick;

		Data* d = (Data*)alarm->contents;
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
		break;
	}
	case STRING: {
		char* s = (char*)alarm->contents;
		Unicode::strncpy(valueBuffer, s, valueBufferSize);
		bxAlarm->setColor(Color::getColorFromRGB(60, 255, 202));
		break;
	}
	case MAP: {
		uint8_t map = *(uint8_t*)alarm->contents;
		Unicode::strncpy(valueBuffer, map == 0 ? "BASE" : "ECO", valueBufferSize);
		bxAlarm->setColor(Color::getColorFromRGB(60, 255, 202));
		break;
	}
	default:
		break;
	}
}

//weird way to have a static variable of a class initialized even if there is no instance of the class
Alarm* FrontendApplication::getCurrentAlarm()
{
	static Alarm a = {.contents = NULL};
	return &a;
}

/*Alarms works by having a not interruptable time, which unless the button is pressed we show the alarm even if there's an alarm after with a higher priority,
  after that if there's an alarm with same or lower priority (more important), we switch to that, otherwise we give a bonus time to the current alarm because
  it's more important
*/
void FrontendApplication::handleAlarms(touchgfx::Container* ctAlarm, Unicode::UnicodeChar* nameBuffer, uint16_t nameBufferSize, Unicode::UnicodeChar* valueBuffer, uint16_t valueBufferSize, BoxWithBorder* bxAlarm)
{
	Alarm* currentAlarm = FrontendApplication::getCurrentAlarm();
	static uint32_t currentAlarmStartTime;

	static HANDLEALARM_STATUS status = NO_ALARM;

	switch (status)
	{
	case NO_ALARM: //no current alarm, check if there are any in queue
		ctAlarm->setVisible(false);
		if (peekAlarmFromQueue() != NULL) //check if there is an alarm in queue
		{
			*currentAlarm = extractAlarmFromQueue();
			currentAlarmStartTime = uwTick;
			status = ALARM_NOTINT;
		}
		break;

	case ALARM_NOTINT: //current alarm is showed even if there is a more important alarm after
		if (ds.screen.invalidateCurrentAlarmFlag == 1) //check if we need to disable current alarm
		{
			status = DEACTIVATE_ALARM;
		}
		else if (uwTick - currentAlarmStartTime < ALARM_NOT_INTERRUPTABLE_TIME) //associated amount of time not passed yet, we switch to NO_ALARM only if the current alarm is not on
		{
			if (getAlarmStatus(currentAlarm) == ON || currentAlarm->priority == NOTIFICATION_PRIORITY)
			{
				ctAlarm->setVisible(true);
				FrontendApplication::writeAlarmInBuffers(currentAlarm, nameBuffer, nameBufferSize, valueBuffer, valueBufferSize, bxAlarm);
			}
			else
			{
				if (currentAlarm->type == DATA) //we remove current alarm from queue
				{
					((Data*)currentAlarm->contents)->alarmStatus = OFF_QUEUE;
				}
				status = NO_ALARM;
			}
		}
		else //check which status we need to switch to
		{
			Alarm* nextAlarm = peekAlarmFromQueue();
			if (nextAlarm == NULL) //no alarm after, so current alarm can be interrupted by any new alarm
			{
				status = ALARM_INT;
			}
			else
			{
				if (nextAlarm->priority <= currentAlarm->priority)
				{
					if (currentAlarm->type == DATA) //we remove current alarm from queue
					{
						((Data*)currentAlarm->contents)->alarmStatus = OFF_QUEUE;
					}
					status = NO_ALARM; //next alarm is more important, we switch to NO_ALARM so that we can extract from queue the next alarm
				}
				else
				{
					status = ALARM_BONUST; //next alarm is less important, we give current alarm bonus time
				}
			}
		}
		break;

	case ALARM_BONUST: //there is an alarm after this which is less important
		if (ds.screen.invalidateCurrentAlarmFlag == 1) //check if we need to disable current alarm
		{
			status = DEACTIVATE_ALARM;
		}
		else if(uwTick - currentAlarmStartTime < ALARM_NOT_INTERRUPTABLE_TIME + ALARM_BONUS_TIME) //associated amount of time not passed yet, we switch to NO_ALARM only if the current alarm is not on
		{
			if (getAlarmStatus(currentAlarm) == ON)
			{
				ctAlarm->setVisible(true);
				FrontendApplication::writeAlarmInBuffers(currentAlarm, nameBuffer, nameBufferSize, valueBuffer, valueBufferSize, bxAlarm);
			}
			else
			{
				if (currentAlarm->type == DATA) //we remove current alarm from queue
				{
					((Data*)currentAlarm->contents)->alarmStatus = OFF_QUEUE;
				}
				status = NO_ALARM;
			}
		}
		else //bonus time has passed, we switch to NO_ALARM so that we can go to the next alarm (we know there is one because we end here only if there's an alarm less important after)
		{
			status = NO_ALARM;
		}
		break;

	case ALARM_INT: //current alarm can be interrupted by any alarm if there is one
		if (ds.screen.invalidateCurrentAlarmFlag == 1 || (uwTick - currentAlarmStartTime >= ALARM_AUTOMATIC_TIMEOUT_TIME)) //check if we need to disable current alarm (also in case of timeout)
		{
			status = DEACTIVATE_ALARM;
		}
		else // we switch to NO_ALARM only if the current alarm is not on
		{
			if (getAlarmStatus(currentAlarm) == ON)
			{
				ctAlarm->setVisible(true);
				FrontendApplication::writeAlarmInBuffers(currentAlarm, nameBuffer, nameBufferSize, valueBuffer, valueBufferSize, bxAlarm);
			}
			else
			{
				if (currentAlarm->type == DATA) //we remove current alarm from queue
				{
					((Data*)currentAlarm->contents)->alarmStatus = OFF_QUEUE;
				}
				status = NO_ALARM;
			}
		}
		break;

	case DEACTIVATE_ALARM: //deactivate current alarm
		deactivateAlarm(currentAlarm); //either by the dataset flag (set by associated button) or timeout
		ds.screen.invalidateCurrentAlarmFlag = 0;
		status = NO_ALARM;
		break;

	default: //we should never get here, something bad happened
		break;
	}

	ctAlarm->invalidate();
}

//END MODIFIEDS
