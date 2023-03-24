

#ifndef __MAIN_H
#include "main.h"
#endif

#ifndef __MDM_GUI_LIB_H
#include "MDM_GUI_LIB.h"
#endif

#ifndef __MDM_FUNCTIONS_H
#include "MDM_Functions.h"
#endif

static void DisplayGui_TestDriveArmature(void);

extern GUI_CONST_STORAGE GUI_FONT GUI_FontGearboxFont112;

void DisplayGui_TestDrive(void)
{
	//DisplayGui_TestDriveArmature();

	GUI_SetColor(GUI_WHITE);
	GUI_SetFont(&GUI_FontGearboxFont112);

	static uint8_t gear = 0;
	static uint32_t timerToIncrement = 0;

	if(millis >= timerToIncrement + 1000)
	{
		gear++;
		timerToIncrement = millis;
	}

	if(gear > 4) gear = 0;

	static GUI_DrawStringAtTypeDef gearString = {0};

	intToStr(gear, gearString.string, 0);
	if(gear == 0)
	{
		gearString.string[0] = 'N';
		gearString.string[1] = '\0';
		//gearString.string[2] = '';
	}

	//GUI_DrawStringAt(240, 20, &GUI_FontGearboxFont112, GUI_WHITE, GUI_BLACK, &gearString, CENTER);

	//GUI_DispStringAtCEOL(gearString.string, 240, 20);

	//GUI_SetTextMode(GUI_TM_TRANS);
	GUI_SetTextAlign(GUI_TA_HCENTER);
	GUI_DispStringAt(gearString.string, 240, 20);
	GUI_DispCEOL();
	GUI_SetTextAlign(GUI_TA_LEFT);






	static GUI_DrawTimeAtTypeDef timeToDisplay = {0};
	timeToDisplay.time = millis;

	GUI_DrawTimeAt(480/3 - 8, 2, &GUI_Font32_1, GUI_LIGHTGRAY, GUI_BLACK, &timeToDisplay, TIME_FORMAT_HOURS, 3, DISABLE, RIGHT);


	DisplayGui_TestDriveArmature();
}



void DisplayGui_TestDriveArmature(void)
{
	GUI_SetColor(GUI_WHITE);

	//main rect (frame)
	GUI_DrawRect(0, 0, 480, 272);
	GUI_DrawRect(1, 1, 479, 271);

	/*
	//horizontal lines
	GUI_DrawLine(0, 68 - 32, 480, 68 - 32);

	GUI_DrawLine(0, 68*2 - 32, 480/5*2, 68*2 - 32);		GUI_DrawLine(480/5*3, 68*2 - 32, 480, 68*2 - 32);
	//GUI_DrawLine(0, 68*3 - 32, 480/5*2, 68*3 - 32);		GUI_DrawLine(480/5*3, 68*3 - 32, 480, 68*3 - 32);
	GUI_DrawLine(0, 68*3 - 32, 480, 68*3 - 32);

	GUI_DrawLine(0, 68*4 - 32, 480, 68*4 - 32);

	//vertical lines
	GUI_DrawLine(480/3, 0, 480/3, 68 - 32);
	GUI_DrawLine(480/3*2, 0, 480/3*2, 68 - 32);

	GUI_DrawLine(480/5*2, 68 - 32, 480/5*2, 68*3 - 32);
	GUI_DrawLine(480/5*3, 68 - 32, 480/5*3, 68*3 - 32);

	*/

	static uint8_t res = 6;

	GUI_AA_SetFactor(res);
	GUI_AA_EnableHiRes();
	GUI_AA_SetFactor(res);

	GUI_SetPenSize(5);
	GUI_AA_DrawRoundedRect(40*res, 40*res, 80*res, 160*res, 20*res);


	//GUI_AA_DisableHiRes();
	//GUI_SetPenSize(1);

}
