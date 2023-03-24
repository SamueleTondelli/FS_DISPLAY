
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

extern GUI_CONST_STORAGE GUI_FONT GUI_FontCalibri50alised4pp;


DisplayGui_DataGuiTypeDef drive1_gui_data[20] = {0};


#define PAGE_TEXT_COLOR				GUI_WHITE
#define PAGE_DATA_COLOR				GUI_WHITE
#define PAGE_BACK_COLOR				GUI_BLACK


#define DEFAULT_MIN_TIME_VALUE_OVER		1000


#define DEFAULT_BLINKING_FRAME_SIZE		4

#define DEFAULT_BLINK_DELAY_OVER		250
#define DEFAULT_BLINK_DELAY_UNDER		250

#define NO_BLINK_DELAY					10000

#define DEFAULT_NO_DATA_ERROR_DELAY		2000


//int32_t defaultDataPointed = 13;

int8_t reInitFlag = 0;

void DisplayGui_Drive1(void)
{
	// Intro section BEGIN
	static uint32_t millisGuiIntro = 0;
	static uint8_t introStatus = 0;

	if(selectedGui_old != GuiDrive1 && selectedGui_old != GuiAlarm)
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

			reInitFlag = 1;
			goto DisplayGui_END;
		}
		else
		{
			introStatus = 0;

			GUI_Clear();
		}

	}

	// Intro section END


	DisplayGui_DataInit(reInitFlag);

	//CORE FUNCTION BEGIN

	if(CAR_Data.rpm.intData < 2000)
	{
		drive1_gui_data[4].valueControlEnable = DISABLE;			//Oil P
		drive1_gui_data[0].valueControlEnable = DISABLE;			//Water T
		drive1_gui_data[1].valueControlEnable = DISABLE;			//Oil T
		drive1_gui_data[5].valueControlEnable = DISABLE;			//Fuel P

		drive1_gui_data[12].valueControlEnable = ENABLE;			//TPS

																	//Air T
		drive1_gui_data[2].blinkingOverColor = GUI_RED;
		drive1_gui_data[2].blinkingUnderColor = GUI_BLUE;

	}
	else
	{
		drive1_gui_data[4].valueControlEnable = ENABLE;				//Oil P
		drive1_gui_data[0].valueControlEnable = ENABLE;				//Water T
		drive1_gui_data[1].valueControlEnable = ENABLE;				//Oil T
		drive1_gui_data[5].valueControlEnable = ENABLE;				//Fuel P

		drive1_gui_data[12].valueControlEnable = DISABLE;			//TPS

																	//Air T
		drive1_gui_data[2].blinkingDelayOver = NO_BLINK_DELAY;
		drive1_gui_data[2].blinkingDelayUnder = NO_BLINK_DELAY;
		drive1_gui_data[2].blinkingOverColor = ARGB_CREATE(0, 130, 0, 0);	//GUI_RED;
		drive1_gui_data[2].blinkingUnderColor = ARGB_CREATE(0, 0, 20, 80); 	//GUI_BLUE;
	}

	//DisplayGui_DataRefresh();
	Display_DriveSTD(&drive1_gui_data[0], GUI_WHITE);

/*
	char test[20] = "test 1234567890";

	GUI_SetColor(GUI_RED);
	GUI_SetBkColor(GUI_BLACK);
	GUI_SetFont(&GUI_FontCalibri50alised4pp);
	//GUI_SetTextAlign(GUI_TA_HCENTER);
	GUI_DispStringAt(test, 50, 50);
*/
	//CORE FUNCTION END

	reInitFlag = 0;

	DisplayGui_END:;
}


void DisplayGui_DataInit(uint8_t extReInitFlag)
{
	static uint8_t flagInit = 0;


//#pragma warning disable

	if(selectedGui_old != selectedGui || selectedGui_old != GuiDrive1 || extReInitFlag != 0)
		flagInit = 0;

	if(flagInit == 0)
	{
		if(Display_DriveSTD_Initialized != 0)
			flagInit = 1;

//#pragma warning restore


		for(uint8_t i = 0; i < 20; i++)
		{
			drive1_gui_data[i] = DriveSTD_noData;
		}


		drive1_gui_data[0] = DriveSTD_waterTemp;
		drive1_gui_data[1] = DriveSTD_oilTemp;
		drive1_gui_data[2] = DriveSTD_airTemp;
		drive1_gui_data[3] = DriveSTD_batteryVoltage;
		drive1_gui_data[4] = DriveSTD_oilPressure;
		drive1_gui_data[5] = DriveSTD_fuelPressure;
		//drive1_gui_data[6] = DriveSTD_brake;

		//drive1_gui_data[7] = DriveSTD_brakeBias;
		drive1_gui_data[7] = DriveSTD_brake;
		drive1_gui_data[8] = DriveSTD_map;
		drive1_gui_data[9] = DriveSTD_traction;
		drive1_gui_data[10] = DriveSTD_speed;
		//drive1_gui_data[11] = DriveSTD_drsStatus;

		drive1_gui_data[12] = DriveSTD_tps;

/*
		drive1_gui_data[0] = DriveSTD_fuelTemp;
		drive1_gui_data[1] = DriveSTD_oilTemp;
		drive1_gui_data[2] = DriveSTD_waterTemp;
		drive1_gui_data[3] = DriveSTD_batteryVoltage;
		drive1_gui_data[4] = DriveSTD_oilPressure;
		drive1_gui_data[5] = DriveSTD_fuelPressure;
		//drive1_gui_data[6] = DriveSTD_brake;

		drive1_gui_data[7] = DriveSTD_brake;
		drive1_gui_data[8] = DriveSTD_map;
		drive1_gui_data[9] = DriveSTD_traction;
		drive1_gui_data[10] = DriveSTD_speed;
		//drive1_gui_data[11] = DriveSTD_drsStatus;

		drive1_gui_data[12] = DriveSTD_tps;
		*/

	}
}



void DisplayGui_Intro(void)
{
	GUI_SetTextAlign(GUI_TA_HCENTER);

	GUI_SetColor(GUI_WHITE);

	/*
	GUI_SetFont(&GUI_Font32B_1);
	GUI_DispStringAt("Drive Data", 236, 50);

	GUI_SetFont(&GUI_FontD80);
	GUI_DispDecAt(1, 214, 90, 1);
	*/

	GUI_SetFont(&GUI_Font32B_1);
	GUI_DispStringAt("ENDURANCE", 236, 50 + 50);

	GUI_SetTextAlign(GUI_TA_LEFT);

	GUI_SetColor(GUI_WHITE);
	GUI_SetBkColor(GUI_BLACK);
}
