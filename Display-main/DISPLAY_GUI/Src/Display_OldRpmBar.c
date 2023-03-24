

#ifndef __MAIN_H
#include "main.h"
#endif

#ifndef __MDM_GUI_LIB_H
#include "MDM_GUI_LIB.h"
#endif

#ifndef __DISPLAY_OLDRPMBAR_H
#include "Display_OldRpmBar.h"
#endif

#ifndef __MDM_FUNCTIONS_H
#include "MDM_Functions.h"
#endif

#ifndef __DIAPLAY_GUI_CONF_H
#include "DISPLAY_GUI_Conf.h"
#endif



void Display_OldRpmBar(uint16_t x, uint16_t y, uint16_t sizeX, uint16_t sizeY, uint16_t rpm, uint16_t minRpm, uint16_t rpm1, uint16_t rpm2, uint16_t maxRpm)
{
	static GUI_BarTypeDef rpmBar1 = {0};
	static GUI_BarTypeDef rpmBar2 = {0};
	static GUI_BarTypeDef rpmBar3 = {0};

	static uint8_t refreshFlag = 0;
	static uint32_t callerAddressOld = 0;

	uint32_t callerAddress = __get_LR();


	if(refreshFlag == 0 || callerAddress != callerAddressOld)
	{
		rpmBar1.x = x;
		rpmBar1.y = y;
		rpmBar1.size_x = sizeX * (rpm1 - minRpm) / (maxRpm - minRpm);
		rpmBar1.size_y = sizeY;
		rpmBar1.frameSize = 2;
		rpmBar1.frameColor = GUI_DARKBLUE;
		rpmBar1.backgroundColor = GUI_BLACK;
		rpmBar1.barColor = GUI_BLUE;
		rpmBar1.barMode = GUI_BAR_LTR;
		rpmBar1.maxValue = rpm1;
		rpmBar1.minValue = minRpm;


		rpmBar2.x = x + rpmBar1.size_x + 1;
		rpmBar2.y = y;
		rpmBar2.size_x = sizeX * (rpm2 - rpm1) / (maxRpm - minRpm);
		rpmBar2.size_y = sizeY;
		rpmBar2.frameSize = 2;
		rpmBar2.frameColor = GUI_DARKYELLOW;
		rpmBar2.backgroundColor = GUI_BLACK;
		rpmBar2.barColor = GUI_YELLOW;
		rpmBar2.barMode = GUI_BAR_LTR;
		rpmBar2.maxValue = rpm2;
		rpmBar2.minValue = rpm1;


		rpmBar3.x = x + rpmBar1.size_x + rpmBar2.size_x + 2;
		rpmBar3.y = y;
		rpmBar3.size_x = sizeX * (maxRpm - rpm2) / (maxRpm - minRpm);
		rpmBar3.size_y = sizeY;
		rpmBar3.frameSize = 2;
		rpmBar3.frameColor = GUI_DARKRED;
		rpmBar3.backgroundColor = GUI_BLACK;
		rpmBar3.barColor = GUI_RED;
		rpmBar3.barMode = GUI_BAR_LTR;
		rpmBar3.maxValue = maxRpm;
		rpmBar3.minValue = rpm2;

		refreshFlag = 1;



		callerAddressOld = callerAddress;
	}

	if(rpm < 100)
	{
		rpm = maxRpm;

		rpmBar1.frameColor = GUI_BLUE;
		rpmBar1.barColor = GUI_DARKBLUE;

		rpmBar2.frameColor = GUI_YELLOW;
		rpmBar2.barColor = GUI_DARKYELLOW;

		rpmBar3.frameColor = GUI_RED;
		rpmBar3.barColor = GUI_DARKRED;
	}
	else
	{
		rpmBar1.frameColor = GUI_DARKBLUE;
		rpmBar1.barColor = GUI_BLUE;

		rpmBar2.frameColor = GUI_DARKYELLOW;
		rpmBar2.barColor = GUI_YELLOW;

		rpmBar3.frameColor = GUI_DARKRED;
		rpmBar3.barColor = GUI_RED;
	}


	GUI_Bar(&rpmBar1, (float) rpm);
	GUI_Bar(&rpmBar2, (float) rpm);
	GUI_Bar(&rpmBar3, (float) rpm);


	static uint32_t millisRefresh = 0;

	if (millis >= millisRefresh + 2000)
	{
		refreshFlag = 0;
		millisRefresh = millis;
	}

}


#define RPM_BAR_LENGTH_OFFSET	0

void Display_OldRpmBar_STD(uint16_t rpm)
{
	Display_OldRpmBar(3 + RPM_BAR_LENGTH_OFFSET, 23, 474 - RPM_BAR_LENGTH_OFFSET*2, 20, rpm, 0, 5500, 10500, 12500);
}
