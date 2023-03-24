
#include "main.h"
#include "string.h"

#ifndef __MDM_GUI_LIB_H
#include "MDM_GUI_LIB.h"
#endif

#ifndef __DIAPLAY_GUI_CONF_H
#include "DISPLAY_GUI_Conf.h"
#endif

#define delayRefresh 	10000

#define BAR_X 			170
#define BAR_X_SIZE		140
#define BAR_Y			198
#define BAR_Y_SIZE		20

void GUI_LaunchControlBar(uint8_t launchControlActived)
{
	//launchControlActived = (millis/2000) % 2;

	static uint8_t launchControlActivedOld = 99; //must be different of any possible value of launchControlActived
	static uint32_t millisRefresh = 0;

	static GUI_DrawStringAtTypeDef stringBar = {0};
	strcpy(stringBar.string, "Launch Control");


	if(millis - millisRefresh > 200)
	{
		millisRefresh = 0;
		launchControlActivedOld = 99; //must be different from any possible value of launchControlActived
	}


	if(launchControlActived != launchControlActivedOld || (millis > millisRefresh + delayRefresh))
	{
		if(launchControlActived)
		{
			GUI_SetColor(GUI_GREEN);
			GUI_FillRect(BAR_X, BAR_Y, BAR_X + BAR_X_SIZE, BAR_Y + BAR_Y_SIZE);

			GUI_DrawStringAt(239, BAR_Y, &GUI_Font20_ASCII, GUI_WHITE, GUI_GREEN, &stringBar, CENTER);
		}
		else
		{
			GUI_SetColor(GUI_ORANGE);
			GUI_FillRect(BAR_X, BAR_Y, BAR_X + BAR_X_SIZE, BAR_Y + BAR_Y_SIZE);

			GUI_DrawStringAt(239, BAR_Y, &GUI_Font20_ASCII, GUI_WHITE, GUI_ORANGE, &stringBar, CENTER);
		}

		GUI_SetColor(GUI_WHITE);
		GUI_SetBkColor(GUI_BLACK);

		launchControlActivedOld = launchControlActived;
		millisRefresh = millis;
		GUI_SetColor(GUI_WHITE);
	}
}
