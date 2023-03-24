
#ifndef __MAIN_H
#include "main.h"
#endif

#ifndef __MDM_GUI_LIB_H
#include "MDM_GUI_LIB.h"
#endif

#ifndef __CAR_DATA_H
#include "CAR_DATA.h"
#endif

#ifndef __MDM_FUNCTIONS_H
#include "MDM_Functions.h"
#endif

#ifndef __DIAPLAY_GUI_CONF_H
#include "DISPLAY_GUI_Conf.h"
#endif

static void DisplayGui_DataInit(void);
//static void Display_Frame(void);
static void DisplayGui_Intro(void);


#define steerGreenDegWindow					((float) (2))
#define steerGreenPoints1Number				16

float steerGreenPoints1[steerGreenPoints1Number] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80};


void DisplayGui_CarSetup(void)
{
	// Intro section BEGIN
	static uint32_t millisGuiIntro = 0;
	static uint8_t introStatus = 0;

	if(selectedGui_old != GuiCarSetup)
	{
		introStatus = 1;
		millisGuiIntro = millis;

		GUI_Clear();
	}

	if(introStatus == 1)
	{
		if(millis < millisGuiIntro + DISPLAY_GUI_INTRO_TIME)
		{
			DisplayGui_Intro();
			goto DisplayGui_END;
		}
		else
		{
			introStatus = 0;
			GUI_Clear();
		}
	}

	// Intro section END

	DisplayGui_DataInit();

	//CORE FUNCTION BEGIN


	//Display_Frame();


	static int steerAngleIntOld = 0;
	static uint8_t signOld = 0;

	int x = 8;
	int y = 130;

	int xDelta = 0;

	static int signSize = 70;
	static int signThick = 12;

	uint8_t flagDataInRandge = 0;

	float steerAngle = map_float(CAR_Data.steer.intData, steer_MIN_VALUE, steer_MAX_VALUE, -117, 117);

	//steerAngle = (float)CAR_Data.steer.intData/10;

	uint8_t sign = 0;

	if(steerAngle < 0)
	{
		steerAngle *= -1;
		sign = 1;
	}
	else if(steerAngle == 0)
	{
		sign = 2;
		xDelta = xDelta - signSize * 2;
	}

	int steerAngleInt = steerAngle;
	int steerAngleDec = (steerAngle - steerAngleInt) * 100;


	if(
			(steerAngleIntOld 	> 99 	&& 	steerAngleInt 		<= 99) ||
			(steerAngleIntOld 	> 9  	&& 	steerAngleInt 		<= 9 ) ||
			(steerAngleInt 		> 99 	&& 	steerAngleIntOld 	<= 99) ||
			(steerAngleInt 		> 9  	&& 	steerAngleIntOld 	<= 9 ) ||
			(sign != signOld)
			)
	{
			GUI_Clear();
	}

	GUI_SetColor(GUI_WHITE);


	if(steerAngleInt > 99)
	{
		//x = 10;
		xDelta = 0;
	}
	else if (steerAngleInt > 9)
	{
		x += 60;
		xDelta = -60 - 30;
	}
	else
	{
		x += 2*60;
		xDelta = -120 - 60;
	}

	if(steerAngle <= 1)
	{
		GUI_SetColor(GUI_GREEN);
		flagDataInRandge = 1;
	}

	for(uint8_t i = 0; i < steerGreenPoints1Number; i++)
	{
		if(steerAngle <= steerGreenPoints1[i] + steerGreenDegWindow/2 && steerAngle >= steerGreenPoints1[i] - steerGreenDegWindow/2)
		{
			GUI_SetColor(GUI_GREEN);

			flagDataInRandge = 1;

			i = steerGreenPoints1Number;
		}
	}


	switch(sign)
	{
		case 0:

			//GUI_SetColor(GUI_RED);
			GUI_FillRect(x + 30 + xDelta/2, y, x + 30 + signSize + xDelta/2, y + signThick);

			break;

		case 1:

			//GUI_SetColor(GUI_GREEN);
			GUI_FillRect(x + 30 + xDelta/2, y, x + 30 + signSize + xDelta/2, y + signThick);
			GUI_FillRect(x + 30 + (signSize - signThick)/2 + xDelta/2, y - (signSize)/2 + signThick/2, x + 30 + (signSize - signThick)/2 + signThick + xDelta/2, y + (signSize)/2 + signThick/2);

			break;
	}

	GUI_SetFont(&GUI_FontD80);

	if(steerAngleInt > 99)
		GUI_DispDecAt(steerAngleInt, x + 100 + xDelta, 100, 3);
	else if (steerAngleInt > 9)
		GUI_DispDecAt(steerAngleInt, x + 100 + 60 + xDelta, 100, 2);
	else
		GUI_DispDecAt(steerAngleInt, x + 100 + 2*60 + xDelta, 100, 1);


	GUI_DispDecAt(steerAngleDec, x + 100 + 30 + 3 * 60 + xDelta, 100, 2);

	char point[2] = ".";
	GUI_DispStringAt(point, x + 100 + 3*60 + xDelta, 100);

	signOld = sign;
	steerAngleIntOld = steerAngleInt;

	GUI_DrawCircle(x + 100 + 5*60 + 44 + xDelta, y - 28, 10);
	GUI_DrawCircle(x + 100 + 5*60 + 44 + xDelta, y - 28, 9 );
	GUI_DrawCircle(x + 100 + 5*60 + 44 + xDelta, y - 28, 8 );
	//GUI_DrawCircle(x + 100 + 5*60 + 44 + xDelta, y - 28, 7 );

	if(flagDataInRandge == 1)
	{
		GUI_SetColor(GUI_GREEN);
	}
	else
	{
		GUI_SetColor(GUI_BLACK);
	}


	for(uint8_t i = 0; i < 15; i++)
	{
		GUI_DrawRect(3 + i, 3 + i, 477 - i, 269 - i);
	}


	GUI_SetColor(GUI_WHITE);

	//CORE FUNCTION END

	DisplayGui_END:;
}


void DisplayGui_DataInit(void)
{
	static uint8_t flagInit = 0;

	if(flagInit == 0)
	{
		flagInit = 1;

	}
}

/*
void Display_Frame(void)
{
	GUI_SetColor(GUI_WHITE);

	//main rect (frame)
	GUI_DrawRect(1, 1, 479, 271);
	GUI_DrawRect(2, 2, 478, 270);

	//GUI_AA_DisableHiRes();
	//GUI_SetPenSize(1);
}
*/

void DisplayGui_Intro(void)
{
	GUI_SetTextAlign(GUI_TA_HCENTER);

	GUI_SetColor(GUI_WHITE);

	GUI_SetFont(&GUI_Font32B_1);
	GUI_DispStringAt("CAR SETUP PAGE", 236, 50);

	GUI_SetFont(&GUI_FontD80);
	GUI_DispDecAt(1, 214, 90, 1);

	GUI_SetTextAlign(GUI_TA_LEFT);

	GUI_SetColor(GUI_WHITE);
	GUI_SetBkColor(GUI_BLACK);
}
