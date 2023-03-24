
#ifndef __MAIN_H
#include "main.h"
#endif

#ifndef __MDM_FUNCTIONS_H
#include "MDM_Functions.h"
#endif

#ifndef __DISPLAY_GUI_H
#include "DISPLAY_GUI.h"
#endif

#ifndef __CAR_DATA_H
#include "CAR_DATA.h"
#endif

extern LTDC_HandleTypeDef hltdc;

extern void DisplayGui_Logo(void);
extern void DisplayGui_Old1(void);
extern void DisplayGui_Old2(void);
extern void DisplayGui_PowertrainData1(void);
extern void DisplayGui_CarSetup(void);
extern void DisplayGui_Drive1(void);
extern void DisplayGui_Drive2(void);
extern void DisplayGui_Acceleration(void);
extern void DisplayGui_HandlingCurvesTest(void);
extern void DisplayGui_AntiStall(void);
extern void DisplayGui_Sponsor(void);
extern void DisplayGui_Debug(void);
extern void DisplayGui_TestDrive(void);

extern void MDM_LCD_SetLayerVisible(uint32_t LayerIndex, FunctionalState State);

#define logoStartupTime		2000
uint8_t logoStartupDoneFlag = 0;


uint8_t selectedGui = 0;
uint8_t selectedGui_old = GuiNoPage;

#define FPS_REFRESH_TIME	100
float FPS = 0;


void DisplayGui_Init(void)
{
	//DisplayOFF();
	GUI_Init();
	GUI_SetColor(GUI_BLACK);
	GUI_SetBkColor(GUI_BLACK);
	GUI_Clear();

	MDM_LCD_SetLayerVisible(0, ENABLE);
	//DisplayON();

	CAR_DATA_GuiAlarm_Init();
}

void DisplayOFF(void)
{
	HAL_GPIO_WritePin(LCD_BL_CTRL_GPIO_Port, LCD_BL_CTRL_Pin, 0);
	//HAL_GPIO_WritePin(LCD_DISP_GPIO_Port, LCD_DISP_Pin, 0);
}

void DisplayON(void)
{
	HAL_GPIO_WritePin(LCD_BL_CTRL_GPIO_Port, LCD_BL_CTRL_Pin, 1);
	//HAL_GPIO_WritePin(LCD_DISP_GPIO_Port, LCD_DISP_Pin, 1);
}


void DisplayGui(void)
{
	CAN_Data_AlarmDetection();

	//gui startup logo BEGIN

	if(logoStartupDoneFlag == 0 && millis <= logoStartupTime + 100 && selectedGui != GuiAlarm && DEBUG_MODE == 0 && DEBUG_ON_CAR == 0)
	{
		if(
					CAR_Data.canLastReceiveTime == 0	||
					(
							CAR_Data.speed.intData < 5 			&&
							CAR_Data.rpm.intData < 50 			&&
							CAR_Data.waterTemp.intData < 105	&&
							CAR_Data.oilTemp.intData < 100
					)
				)
		{
			selectedGui = GuiLogo;
		}
		else
			logoStartupDoneFlag = 1;
	}
	else
		logoStartupDoneFlag = 1;

	//gui startup logo END

	static uint32_t refreshTime = 0;
	static uint32_t clearTime = 0;

	if(selectedGui != selectedGui_old)
	{
		GUI_Clear();
		GUI_SetPenSize(1);

		refreshTime = millis;
		clearTime = millis;

		goto DisplayGui_BEGIN;
	}

	//gui refresh rate control BEGIN

	if(millis < refreshTime + DISPLAY_GUI_REFRESH_TIME)
		goto DisplayGui_END;

	refreshTime = millis;

	//gui refresh rate control END

	//gui clear rate control BEGIN

	if(millis < clearTime + DISPLAY_GUI_CLEAR_TIME)
		goto DisplayGui_BEGIN;

	if(selectedGui != GuiSponsor
		&& selectedGui != GuiLogo)
	{
		//GUI_Clear();
		clearTime = millis;
	}


	//gui clear rate control END

	DisplayGui_BEGIN:

	if(selectedGui != GuiAlarm)
		alarmPageDisplayRefreshEnable = 1;

	/*---DisplayGui function core BEGIN---*/

	switch(selectedGui)
	{

		case DisplayGui_Debug_INDEX:
			DisplayGui_Debug();
			break;

		case GuiLogo:
			if(DEBUG_MODE == DISABLE || DEBUG_ON_CAR == DISABLE)
				DisplayGui_Logo();
			break;

		case GuiAcceleration:
			DisplayGui_Acceleration();
			break;

		case GuiTestDrive:
			DisplayGui_TestDrive();
			break;

		case GuiOld1:
			DisplayGui_Old1();
			break;

		case GuiOld2:
			DisplayGui_Old2();
			break;

		case GuiDrive1:
			DisplayGui_Drive1();
			break;

		case GuiDrive2:
			DisplayGui_Drive2();
			break;

		case GuiHandlingCurvesTest:
			DisplayGui_HandlingCurvesTest();
			break;

		case DisplayGui_PowertrainData1_INDEX:
			DisplayGui_PowertrainData1();
			break;

		case GuiCarSetup:
			DisplayGui_CarSetup();
			break;

		case GuiAntiStall:
			//DisplayGui_AntiStall();
			break;

		case GuiSponsor:
			//DisplayGui_Sponsor();
			break;



		case GuiAlarm:
			alarmPageDisplayRefreshEnable = 1;
			break;

		default:
			Error_Handler();
			selectedGui = GuiDrive1;
			DisplayGui_Drive1();

	}

	GUI_SetColor(GUI_WHITE);
	GUI_SetBkColor(GUI_BLACK);
	GUI_Exec();

	/*---DisplayGui function core END---*/

	selectedGui_old = selectedGui;


	static uint8_t pointsToggle = 1;
	static uint32_t pointsToggleMillis = 0;

	if(millis >= pointsToggleMillis + 500)
	{
		pointsToggleMillis = millis;
		pointsToggle = !pointsToggle;
	}


	static uint32_t millisFpsCounter = 0;
	static uint16_t displayFpsCounter = 0;

	displayFpsCounter++;

	if(millis >= millisFpsCounter + FPS_REFRESH_TIME)
	{
		FPS = (float)displayFpsCounter*(1000.0/(millis - millisFpsCounter));
		displayFpsCounter = 0;
		millisFpsCounter = millis;
	}



	DisplayGui_END:;


	if(DEBUG_POINTS_ENABLE == ENABLE)
	{
		if(selectedGui != GuiLogo)
		{
			if(pointsToggle)
				GUI_SetColor(GUI_WHITE);
			else
				GUI_SetColor(GUI_BLACK);

			GUI_FillCircle(7, 			272 - 7, 2);
			GUI_FillCircle(480 - 7, 	272 - 7, 2);
		}
	}
}

