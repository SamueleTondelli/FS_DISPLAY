// START
#include "ButtonHandler.h"
#include "Data/Dataset.h"
// END

extern void GPS_lapTimerReset(void);
extern void GPS_lapSetStarPoint(float lat, float lon);

void buttonsActionHandler(Dataset* dataset) {
	if(!updateButton(&(dataset->dispBtn)))
	{
		if ((dataset->dispBtn.state == BUTTON_PRESSED) && (uwTick -  dataset->dispBtn.timeWhenPressed >= DEBOUNCE_TIME))
		{
			changeScreenButton(dataset);
			dataset->dispBtn.state = BUTTON_DISABLED;
		}
	}

	if(!updateButton(&(dataset->markBtn)))
	{
		if ((dataset->markBtn.state == BUTTON_PRESSED) && (uwTick -  dataset->markBtn.timeWhenPressed >= GPS_SET_TIME))
		{
			GPS_lapTimerReset();
			GPS_lapSetStarPoint(getValueData(&(dataset->controls.gpsLatitude)), getValueData(&(dataset->controls.gpsLongitude)));
			dataset->markBtn.state = BUTTON_DISABLED;
		}
	}

	if(!updateButton(&(dataset->okBtn)))
	{
		if ((dataset->okBtn.state == BUTTON_PRESSED) && (uwTick -  dataset->okBtn.timeWhenPressed >= DEBOUNCE_TIME))
		{
			dataset->screen.invalidateCurrentAlarmFlag = 1;
			dataset->okBtn.state = BUTTON_DISABLED;
		}
		else
		{
			dataset->screen.invalidateCurrentAlarmFlag = 1;
		}
	}

	if(!updateButton(&(dataset->mapBtn)))
	{
		if ((dataset->mapBtn.state == BUTTON_PRESSED) && (uwTick -  dataset->mapBtn.timeWhenPressed >= DEBOUNCE_TIME))
		{
			toggleMap(&(dataset->controls));
			dataset->mapBtn.state = BUTTON_DISABLED;
		}
	}
}

void changeScreenButton(Dataset* dataset) {
	incrementCurrentScreen(&(dataset->screen));
}
