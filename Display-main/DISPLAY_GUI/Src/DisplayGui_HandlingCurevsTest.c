
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

#ifndef __DISPLAY_DRIVESTD_H
#include "Display_DriveSTD.h"
#endif

#include "string.h"

static void DisplayGui_Intro(void);
static void DisplayGui_DataInit(uint8_t extReInitFlag);
//static void DisplayGui_DataRefresh(void);


DisplayGui_DataGuiTypeDef handlingCurves_gui_data[20] = {0};


#define PAGE_TEXT_COLOR				GUI_WHITE
#define PAGE_DATA_COLOR				GUI_WHITE
#define PAGE_BACK_COLOR				GUI_BLACK


#define DEFAULT_MIN_TIME_VALUE_OVER		1000


#define DEFAULT_BLINKING_FRAME_SIZE		4

#define DEFAULT_BLINK_DELAY_OVER		250
#define DEFAULT_BLINK_DELAY_UNDER		250

#define NO_BLINK_DELAY					10000

#define DEFAULT_NO_DATA_ERROR_DELAY		2000


int8_t reInitFlagHandlingCurves = 0;




#define steerGreenDegWindow					((float) (2))
#define steerGreenPointsNumber				18

float steerGreenPoints[steerGreenPointsNumber] = {0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 117};

uint32_t steerColor = GUI_WHITE;



void DisplayGui_HandlingCurvesTest(void)
{
	// Intro section BEGIN
	static uint32_t millisGuiIntro = 0;
	static uint8_t introStatus = 0;

	if(selectedGui_old != GuiHandlingCurvesTest && selectedGui_old != GuiAlarm)
	{
		introStatus = 1;
		millisGuiIntro = millis;

		GUI_Clear();
	}

	if(introStatus == 1)
	{
		if(millis < millisGuiIntro + DISPLAY_GUI_INTRO_TIME * 2)
		{
			DisplayGui_Intro();

			reInitFlagHandlingCurves = 1;
			goto DisplayGui_END;
		}
		else
		{
			introStatus = 0;

			GUI_Clear();
		}

	}

	// Intro section END


	DisplayGui_DataInit(reInitFlagHandlingCurves);

	//CORE FUNCTION BEGIN

	if(CAR_Data.rpm.intData < 2000)
	{
		//handlingCurves_gui_data[4].valueControlEnable = DISABLE;			//Oil P
		handlingCurves_gui_data[10].valueControlEnable = DISABLE;			//Oil P
		handlingCurves_gui_data[0].valueControlEnable = DISABLE;			//Water T
		handlingCurves_gui_data[1].valueControlEnable = DISABLE;			//Oil T
		//handlingCurves_gui_data[5].valueControlEnable = DISABLE;			//Fuel P
		handlingCurves_gui_data[11].valueControlEnable = DISABLE;			//Fuel P

		handlingCurves_gui_data[12].valueControlEnable = ENABLE;			//TPS

																	//Air T
		handlingCurves_gui_data[2].blinkingOverColor = GUI_RED;
		handlingCurves_gui_data[2].blinkingUnderColor = GUI_BLUE;

	}
	else
	{
		//handlingCurves_gui_data[4].valueControlEnable = ENABLE;				//Oil P
		handlingCurves_gui_data[10].valueControlEnable = ENABLE;			//Oil P
		handlingCurves_gui_data[0].valueControlEnable = ENABLE;				//Water T
		handlingCurves_gui_data[1].valueControlEnable = ENABLE;				//Oil T
		//handlingCurves_gui_data[5].valueControlEnable = ENABLE;				//Fuel P
		handlingCurves_gui_data[11].valueControlEnable = ENABLE;			//Fuel P

		handlingCurves_gui_data[12].valueControlEnable = DISABLE;			//TPS

																	//Air T
		handlingCurves_gui_data[2].blinkingDelayOver = NO_BLINK_DELAY;
		handlingCurves_gui_data[2].blinkingDelayUnder = NO_BLINK_DELAY;
		handlingCurves_gui_data[2].blinkingOverColor = ARGB_CREATE(0, 130, 0, 0);	//GUI_RED;
		handlingCurves_gui_data[2].blinkingUnderColor = ARGB_CREATE(0, 0, 20, 80); 	//GUI_BLUE;
	}

	//DisplayGui_DataRefresh();
	Display_DriveSTD(&handlingCurves_gui_data[0], steerColor);



	int y = 40 + 4;

	char steeringTextString[10] = "Steer";

	GUI_SetFont(&GUI_Font20_1);

	GUI_SetColor(GUI_GRAY);
	GUI_SetTextAlign(GUI_TA_HCENTER);
	GUI_DispStringAt(steeringTextString, 480 / 2 - 95, y - 4);
	GUI_SetTextAlign(GUI_TA_HCENTER);
	GUI_DispStringAt(steeringTextString, 480 / 2 + 95, y - 4);

	strcpy(steeringTextString, "Deg");

	GUI_SetColor(GUI_DARKGRAY);
	GUI_SetTextAlign(GUI_TA_HCENTER);
	GUI_DispStringAt(steeringTextString, 480 / 2 - 95, y + 15);
	GUI_SetTextAlign(GUI_TA_HCENTER);
	GUI_DispStringAt(steeringTextString, 480 / 2 + 95, y + 15);

	GUI_SetTextAlign(GUI_TA_LEFT);

	float steerAngle = map_float(CAR_Data.steer.intData, steer_MIN_VALUE, steer_MAX_VALUE, -117, 117);

	if(steerAngle < 0) steerAngle*=-1;

	steerColor = PAGE_TEXT_COLOR;

	for(uint8_t i = 0; i < steerGreenPointsNumber; i++)
	{
		if(steerAngle <= steerGreenPoints[i] + steerGreenDegWindow/2 && steerAngle >= steerGreenPoints[i] - steerGreenDegWindow/2)
		{
			steerColor = GUI_GREEN;

			i = steerGreenPointsNumber;
		}
	}


	int x = 175;

	static GUI_DrawNumAtTypeDef steerText1 = {0};
	static GUI_DrawNumAtTypeDef steerText2 = {0};
	steerText1.number = steerAngle;
	steerText2.number = steerAngle;

	char string[2] = "";

	GUI_DrawNumAt(480 / 2 - x, y, &GUI_FontD32, steerColor, PAGE_BACK_COLOR, &steerText1, UNDEFINED_NINT, 1, DISABLE, DISABLE, CENTER, string, string);
	GUI_DrawNumAt(480 / 2 + x, y, &GUI_FontD32, steerColor, PAGE_BACK_COLOR, &steerText2, UNDEFINED_NINT, 1, DISABLE, DISABLE, CENTER, string, string);

	if(steerAngle < 100)
	{
		if(steerColor == GUI_GREEN)
			GUI_SetColor(GUI_GREEN);
		else
			GUI_SetColor(PAGE_BACK_COLOR);

		GUI_FillRect(3, 35, 3 + 15, 35 + 50);
		GUI_FillRect(477 - 15, 35, 477, 35 + 50);
	}


	GUI_SetColor(PAGE_TEXT_COLOR);


	//CORE FUNCTION END

	reInitFlagHandlingCurves = 0;

	DisplayGui_END:;
}


void DisplayGui_DataInit(uint8_t extReInitFlag)
{
	static uint8_t flagInit = 0;


//#pragma warning disable

	if(selectedGui_old != selectedGui || selectedGui_old != GuiHandlingCurvesTest || extReInitFlag != 0)
		flagInit = 0;

	if(flagInit == 0)
	{
		if(Display_DriveSTD_Initialized != 0)
			flagInit = 1;

//#pragma warning restore

		for(uint8_t i = 0; i < 20; i++)
		{
			handlingCurves_gui_data[i] = DriveSTD_noData;
		}
/*
		handlingCurves_gui_data[0] = DriveSTD_waterTemp;
		handlingCurves_gui_data[1] = DriveSTD_oilTemp;
		handlingCurves_gui_data[2] = DriveSTD_airTemp;
		handlingCurves_gui_data[3] = DriveSTD_batteryVoltage;
		handlingCurves_gui_data[4] = DriveSTD_oilPressure;
		handlingCurves_gui_data[5] = DriveSTD_fuelPressure;
		handlingCurves_gui_data[6] = DriveSTD_FL_Ty_Temp;

		handlingCurves_gui_data[7] = DriveSTD_RL_Ty_Temp;
		handlingCurves_gui_data[8] = DriveSTD_speed;
		handlingCurves_gui_data[9] = DriveSTD_traction;
		handlingCurves_gui_data[10] = DriveSTD_RR_Ty_Temp;
		handlingCurves_gui_data[11] = DriveSTD_FR_Ty_Temp;
*/

		handlingCurves_gui_data[0] = DriveSTD_waterTemp;
		handlingCurves_gui_data[1] = DriveSTD_oilTemp;
		handlingCurves_gui_data[2] = DriveSTD_airTemp;
		handlingCurves_gui_data[3] = DriveSTD_batteryVoltage;
		handlingCurves_gui_data[4] = DriveSTD_RL_Ty_Temp;
		handlingCurves_gui_data[5] = DriveSTD_FL_Ty_Temp;
		handlingCurves_gui_data[6] = DriveSTD_FR_Ty_Temp;

		handlingCurves_gui_data[7] = DriveSTD_RR_Ty_Temp;
		handlingCurves_gui_data[8] = DriveSTD_speed;
		handlingCurves_gui_data[9] = DriveSTD_traction;
		handlingCurves_gui_data[10] = DriveSTD_oilPressure;
		handlingCurves_gui_data[11] = DriveSTD_fuelPressure;


		handlingCurves_gui_data[12] = DriveSTD_tps;
	}
}



void DisplayGui_Intro(void)
{
	GUI_SetTextAlign(GUI_TA_HCENTER);

	GUI_SetColor(GUI_WHITE);

	/*
	GUI_SetFont(&GUI_Font32B_1);
	GUI_DispStringAt("Handling Curves Test", 236, 50);

	GUI_SetFont(&GUI_FontD80);
	GUI_DispDecAt(1, 214, 90, 1);
	*/

	GUI_SetFont(&GUI_Font32B_1);
	GUI_DispStringAt("SKIDPAD", 236, 50 + 50);


	GUI_SetTextAlign(GUI_TA_LEFT);

	GUI_SetColor(GUI_WHITE);
	GUI_SetBkColor(GUI_BLACK);
}
