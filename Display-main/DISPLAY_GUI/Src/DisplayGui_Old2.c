

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

#ifndef __DISPLAY_OLDRPMBAR_H
#include "Display_OldRpmBar.h"
#endif

static void DisplayGui_Old2Armature(void);
static void DisplayGui_Old2_Intro(void);

extern void GUI_LaunchControlBar(uint8_t launchControlActived);

//extern GUI_CONST_STORAGE GUI_FONT GUI_FontGearboxFont112;

extern GUI_CONST_STORAGE GUI_BITMAP bmGEARBOX_N;
extern GUI_CONST_STORAGE GUI_BITMAP bmGEARBOX_1;
extern GUI_CONST_STORAGE GUI_BITMAP bmGEARBOX_2;
extern GUI_CONST_STORAGE GUI_BITMAP bmGEARBOX_3;
extern GUI_CONST_STORAGE GUI_BITMAP bmGEARBOX_4;

extern GUI_CONST_STORAGE GUI_BITMAP bmGEARBOX_N_116_Gray255;
extern GUI_CONST_STORAGE GUI_BITMAP bmGEARBOX_1_116_Gray255;
extern GUI_CONST_STORAGE GUI_BITMAP bmGEARBOX_2_116_Gray255;
extern GUI_CONST_STORAGE GUI_BITMAP bmGEARBOX_3_116_Gray255;
extern GUI_CONST_STORAGE GUI_BITMAP bmGEARBOX_4_116_Gray255;

#define HQ_GEARBOX_ENABLE 			1


#define rectAAfactor			6
#define rectSizeX				120
#define rectSizeY				40
#define rectRadius				12
#define rectThickness			4

#define GUI_Y_OFFSET			16

#define RPM_BAR_LENGTH_OFFSET	0


void DisplayGui_Old2(void)
{
	// Intro section BEGIN
	static uint32_t millisGuiIntro = 0;
	static uint8_t introStatus = 0;

	if(selectedGui_old != GuiOld2)
	{
		introStatus = 1;
		millisGuiIntro = millis;

		GUI_Clear();
	}

	if(introStatus == 1)
	{
		if(millis < millisGuiIntro + DISPLAY_GUI_INTRO_TIME)
		{
			DisplayGui_Old2_Intro();
			goto DisplayGui_Old2_END;
		}
		else
		{
			introStatus = 0;
			GUI_Clear();
		}
	}

	// Intro section END


	//CORE FUNCTION BEGIN

	//DisplayGui_Old2Armature();

	int x, y, xt, yt;
	char *string = "";

	char *a = "";
	char *b = "";


	// RPM BAR BEGIN

	Display_OldRpmBar(3 + RPM_BAR_LENGTH_OFFSET, 23, 474 - RPM_BAR_LENGTH_OFFSET*2, 20, rpm, 0, 5500, 10500, 12500);

	// RPM BAR END

	// GEAR BEGIN

	static uint8_t gear_old = 0;

	if(gear_old != gear)
	{
		GUI_SetColor(GUI_BLACK);
		GUI_FillRect(190, 20 + GUI_Y_OFFSET, 290, 22 + 126 + GUI_Y_OFFSET);
	}

#if HQ_GEARBOX_ENABLE == 0
	switch(gear)
	{
		case 0:
			GUI_DrawBitmap(&bmGEARBOX_N, (480 - bmGEARBOX_N.XSize)/2, 22 + GUI_Y_OFFSET);
			break;

		case 1:
			GUI_DrawBitmap(&bmGEARBOX_1, (480 - bmGEARBOX_1.XSize)/2, 22 + GUI_Y_OFFSET);
			break;

		case 2:
			GUI_DrawBitmap(&bmGEARBOX_2, (480 - bmGEARBOX_2.XSize)/2, 22 + GUI_Y_OFFSET);
			break;

		case 3:
			GUI_DrawBitmap(&bmGEARBOX_3, (480 - bmGEARBOX_3.XSize)/2, 22 + GUI_Y_OFFSET);
			break;

		case 4:
			GUI_DrawBitmap(&bmGEARBOX_4, (480 - bmGEARBOX_4.XSize)/2, 22 + GUI_Y_OFFSET);
			break;

		default:
			GUI_SetColor(GUI_RED);
			GUI_FillRect(190, 22 + GUI_Y_OFFSET, 290, 22 + 126 + GUI_Y_OFFSET);

	}
#elif HQ_GEARBOX_ENABLE == 1

		switch(CAR_Data.gear.intData)
		{
			case 0:
				GUI_DrawBitmap(&bmGEARBOX_N_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 6, 20 + GUI_Y_OFFSET);
				break;

			case 1:
				GUI_DrawBitmap(&bmGEARBOX_1_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 15, 22 + GUI_Y_OFFSET);
				break;

			case 2:
				GUI_DrawBitmap(&bmGEARBOX_2_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 13, 22 + GUI_Y_OFFSET);
				break;

			case 3:
				GUI_DrawBitmap(&bmGEARBOX_3_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 15, 22 + GUI_Y_OFFSET);
				break;

			case 4:
				GUI_DrawBitmap(&bmGEARBOX_4_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 9, 22 + GUI_Y_OFFSET);
				break;

			default:
				GUI_SetColor(GUI_RED);
				GUI_FillRect(193, 84 + GUI_Y_OFFSET, 288, 207 + GUI_Y_OFFSET);

		}

#endif

	gear_old = gear;

	// GEAR END


	GUI_AA_SetFactor(rectAAfactor);
	GUI_AA_EnableHiRes();
	GUI_AA_SetFactor(rectAAfactor);

	GUI_SetPenSize(rectThickness);

	// Water Temparature BEGIN

	GUI_SetColor(GUI_WHITE);
	GUI_SetBkColor(GUI_BLACK);

	xt = 48 + 56;
	yt = 21 + 25 + GUI_Y_OFFSET;

	string = " C";
	GUI_SetFont(&GUI_Font32_1);
	GUI_DispStringAt(string, xt - 4, yt - 10);

	GUI_SetBkColor(GUI_BLACK);
	//GUI_DrawNumAtAuto();

	//GUI_DrawNumAt();

	static GUI_DrawNumAtTypeDef tWaterTEMP;
	tWaterTEMP.number = tWater;

	//GUI_DrawNumAt(xt - 10, yt - 10, &GUI_Font32_1, GUI_WHITE, GUI_BLACK, &tWaterTEMP, 3, 1, DISABLE, DISABLE, RIGHT, a, b);
	GUI_DrawNumAt(xt - 40, yt - 10, &GUI_Font32_1, GUI_WHITE, GUI_BLACK, &tWaterTEMP, 3, 1, DISABLE, DISABLE, CENTER, a, b);

	GUI_DrawCircle(xt, yt, 3);

	GUI_SetBkColor(GUI_BLACK);


	if(tWaterTEMP.number >= tWater_MAX_VALUE)
	{
		static uint32_t millis_blink = 0;
		static uint8_t color_flag = 0;

		if(millis > millis_blink + DISPLAY_GUI_WARNING_BLINK_TIME && color_flag == 0)
		{
			color_flag = 1;

			millis_blink = millis;
		}
		else if(millis > millis_blink + DISPLAY_GUI_WARNING_BLINK_TIME && color_flag != 0)
		{
			color_flag = 0;

			millis_blink = millis;
		}

		if(color_flag == 1)
		{
			GUI_SetColor(GUI_RED);
		}
		else
		{
			GUI_SetColor(GUI_WHITE);
		}
	}
	else
	{
		GUI_SetColor(GUI_LIGHTGRAY);
	}

	//GUI_SetColor(GUI_LIGHTGRAY);

	x = 20;
	y = 16 + GUI_Y_OFFSET;
	GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX) * rectAAfactor, (y + rectSizeY) * 1.3 * rectAAfactor, rectRadius * rectAAfactor);


	xt = 48;
	yt = 21 + GUI_Y_OFFSET;
	string = "T water";
	GUI_SetFont(&GUI_Font20_1);
	GUI_DispStringAt(string, xt, yt);

	// Water Temparature END


	// Traction Control "TC" BEGIN

	static uint8_t tractionControl_old = 0;

	GUI_SetColor(GUI_LIGHTGRAY);

	xt = 40;
	yt = 98 + GUI_Y_OFFSET;
	string = "TC";
	GUI_SetFont(&GUI_Font32_1);
	GUI_DispStringAt(string, xt, yt);


	xt += 40;

	if(tractionControl != tractionControl_old)
	{
		GUI_SetColor(GUI_BLACK);
		GUI_FillRect(xt, yt, xt + 58, yt + 28);
	}

	tractionControl_old = tractionControl;

	GUI_SetFont(&GUI_Font32B_1);
	GUI_SetColor(GUI_WHITE);

	switch(tractionControl)
	{
		case 0:
			string = "OFF";
			GUI_SetFont(&GUI_Font32_1);
			break;

		case 1:
			string = "1";
			xt+=18;
			break;

		case 2:
			string = "2";
			xt+=18;
			break;

		case 3:
			string = "3";
			xt+=18;
			break;

		case 4:
			string = "4";
			xt+=18;
			break;

		default:
			GUI_SetColor(GUI_RED);
			string = "ERR";
			GUI_SetFont(&GUI_Font32_1);
	}

	GUI_DispStringAt(string, xt, yt);

	GUI_SetColor(GUI_LIGHTGRAY);

	y = 94 + GUI_Y_OFFSET;
	GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX) * rectAAfactor, (y + rectSizeY) * rectAAfactor, rectRadius * rectAAfactor);

	// Traction Control "TC" END

	// P0 BEGIN
/*
	static uint8_t gs_value_old = 0;

	GUI_SetColor(GUI_LIGHTBLUE);

	xt = 40;
	yt = 158 + GUI_Y_OFFSET;
	string = "GS";
	GUI_SetFont(&GUI_Font32_1);
	GUI_DispStringAt(string, xt, yt);

	xt += 40;

	if(gs != gs_value_old)
	{
		GUI_SetColor(GUI_BLACK);
		GUI_FillRect(xt, yt, xt + 58, yt + 28);
	}

	gs_value_old = gs;

	GUI_SetFont(&GUI_Font32B_1);
	GUI_SetColor(GUI_LIGHTGRAY);

	switch(gs)
	{
		case 0:
			string = "0";
			xt+=18;
			break;

		case 1:
			string = "1";
			xt+=18;
			break;

		case 2:
			string = "2";
			xt+=18;
			break;

		case 3:
			string = "3";
			xt+=18;
			break;

		case 4:
			string = "4";
			xt+=18;
			break;

		default:
			GUI_SetColor(GUI_RED);
			string = "ERR";
			GUI_SetFont(&GUI_Font32_1);
	}

	GUI_DispStringAt(string, xt, yt);

	GUI_SetColor(GUI_LIGHTBLUE);

	y = 154 + GUI_Y_OFFSET;
	GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX) * rectAAfactor, (y + rectSizeY) * rectAAfactor, rectRadius * rectAAfactor);
*/
	// P0 END

	// P oil BEGIN

	//static uint8_t p0_value_old = 0;

	static GUI_DrawNumAtTypeDef tOilPRESSURE;

	if(tOilPRESSURE.number <= pOil_MIN_VALUE && rpm >= 1000)
	{
		static uint32_t millis_blink = 0;
		static uint8_t color_flag = 0;

		if(millis > millis_blink + DISPLAY_GUI_WARNING_BLINK_TIME && color_flag == 0)
		{
			color_flag = 1;

			millis_blink = millis;
		}
		else if(millis > millis_blink + DISPLAY_GUI_WARNING_BLINK_TIME && color_flag != 0)
		{
			color_flag = 0;

			millis_blink = millis;
		}

		if(color_flag == 1)
		{
			GUI_SetColor(GUI_RED);
		}
		else
		{
			GUI_SetColor(GUI_WHITE);
		}
	}
	else
	{
		GUI_SetColor(GUI_LIGHTGRAY);
	}


	//GUI_SetColor(GUI_LIGHTGRAY);

	xt = 30;
	yt = 158 + GUI_Y_OFFSET;
	string = "Poil";
	GUI_SetFont(&GUI_Font32_1);
	GUI_DispStringAt(string, xt, yt);

	//xt += 30;
/*
	if(p0_value != p0_value_old)
	{
		GUI_SetColor(GUI_BLACK);
		GUI_FillRect(xt, yt, xt + 58, yt + 28);
	}
*/
	//p0_value_old = p0_value;

	//static GUI_DrawNumAtTypeDef tOilPRESSURE;
	tOilPRESSURE.number = pOil;

	xt += 76;
	//yt += 2;

	a = "";
	b = "";

	GUI_DrawNumAt(xt, yt, &GUI_Font32_1, GUI_WHITE, GUI_BLACK, &tOilPRESSURE, 3, 1, DISABLE, DISABLE, CENTER, a, b);


	if(tOilPRESSURE.number <= pOil_MIN_VALUE && rpm >= 1000)
	{
		static uint32_t millis_blink = 0;
		static uint8_t color_flag = 0;

		if(millis > millis_blink + DISPLAY_GUI_WARNING_BLINK_TIME && color_flag == 0)
		{
			color_flag = 1;

			millis_blink = millis;
		}
		else if(millis > millis_blink + DISPLAY_GUI_WARNING_BLINK_TIME && color_flag != 0)
		{
			color_flag = 0;

			millis_blink = millis;
		}

		if(color_flag == 1)
		{
			GUI_SetColor(GUI_RED);
		}
		else
		{
			GUI_SetColor(GUI_WHITE);
		}
	}
	else
	{
		GUI_SetColor(GUI_LIGHTGRAY);
	}

	//GUI_SetColor(GUI_LIGHTGRAY);

	y = 154 + GUI_Y_OFFSET;
	GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX) * rectAAfactor, (y + rectSizeY) * rectAAfactor, rectRadius * rectAAfactor);

	// P Oil END


	// V BAT BEGIN

	static GUI_DrawNumAtTypeDef vBatDispData = {0};
	vBatDispData.number = vBat;

	if(vBatDispData.number <= vBat_MIN_VALUE)
	{
		static uint32_t millis_blink = 0;
		static uint8_t color_flag = 0;

		if(millis > millis_blink + DISPLAY_GUI_WARNING_BLINK_TIME && color_flag == 0)
		{
			color_flag = 1;

			millis_blink = millis;
		}
		else if(millis > millis_blink + DISPLAY_GUI_WARNING_BLINK_TIME && color_flag != 0)
		{
			color_flag = 0;

			millis_blink = millis;
		}

		if(color_flag == 1)
		{
			GUI_SetColor(GUI_RED);
		}
		else
		{
			GUI_SetColor(GUI_LIGHTBLUE);
		}
	}
	else
	{
		GUI_SetColor(GUI_LIGHTBLUE);
	}

	xt = 54;
	yt = 221 + GUI_Y_OFFSET;
	string = "V BAT";
	GUI_SetFont(&GUI_Font16_1);
	GUI_SetColor(GUI_LIGHTBLUE);
	GUI_DispStringAt(string, xt, yt);


	xt += 60;
	yt -= 2;

	GUI_DrawNumAt(xt, yt, &GUI_Font20_1, GUI_LIGHTGRAY, GUI_BLACK, &vBatDispData, 2, 1, DISABLE, DISABLE, CENTER, a, b);

	if(vBatDispData.number <= vBat_MIN_VALUE)
	{
		static uint32_t millis_blink = 0;
		static uint8_t color_flag = 0;

		if(millis > millis_blink + DISPLAY_GUI_WARNING_BLINK_TIME && color_flag == 0)
		{
			color_flag = 1;

			millis_blink = millis;
		}
		else if(millis > millis_blink + DISPLAY_GUI_WARNING_BLINK_TIME && color_flag != 0)
		{
			color_flag = 0;

			millis_blink = millis;
		}

		if(color_flag == 1)
		{
			GUI_SetColor(GUI_RED);
		}
		else
		{
			GUI_SetColor(GUI_LIGHTBLUE);
		}
	}
	else
	{
		GUI_SetColor(GUI_LIGHTBLUE);
	}

	y = 214 + GUI_Y_OFFSET;
	//GUI_SetColor(GUI_LIGHTBLUE);
	GUI_AA_DrawRoundedRect((x + 24) * rectAAfactor, y * rectAAfactor, (x + rectSizeX) * rectAAfactor, (y + rectSizeY - 10) * rectAAfactor, rectRadius * rectAAfactor);

	// V BAT END
	// right rects END


	// left rects BEGIN

	// Oil Temparature BEGIN

	GUI_SetColor(GUI_WHITE);

	xt = (480 - rectSizeX) + 65;
	yt = 21 + 25 + GUI_Y_OFFSET;

	string = " C";
	GUI_SetFont(&GUI_Font32_1);
	GUI_DispStringAt(string, xt - 4, yt - 10);


	static GUI_DrawNumAtTypeDef tOilTEMP;
	tOilTEMP.number = tOil;

	//GUI_DrawNumAt(xt - 10, yt - 10, &GUI_Font32_1, GUI_WHITE, GUI_BLACK, &tWaterTEMP, 3, 1, DISABLE, DISABLE, RIGHT, a, b);
	GUI_DrawNumAt(xt - 40, yt - 10, &GUI_Font32_1, GUI_WHITE, GUI_BLACK, &tOilTEMP, 3, 1, DISABLE, DISABLE, CENTER, a, b);

	GUI_DrawCircle(xt, yt, 3);

	if(tOilTEMP.number >= tOil_MAX_VALUE)
	{
		static uint32_t millis_blink = 0;
		static uint8_t color_flag = 0;

		if(millis > millis_blink + DISPLAY_GUI_WARNING_BLINK_TIME && color_flag == 0)
		{
			color_flag = 1;

			millis_blink = millis;
		}
		else if(millis > millis_blink + DISPLAY_GUI_WARNING_BLINK_TIME && color_flag != 0)
		{
			color_flag = 0;

			millis_blink = millis;
		}

		if(color_flag == 1)
		{
			GUI_SetColor(GUI_RED);
		}
		else
		{
			GUI_SetColor(GUI_WHITE);
		}
	}
	else
	{
		GUI_SetColor(GUI_LIGHTGRAY);
	}

	xt = (480 - rectSizeX) + 20;
	yt = 21 + GUI_Y_OFFSET;
	string = "T oil";
	GUI_SetFont(&GUI_Font20_1);
	GUI_DispStringAt(string, xt, yt);

	x = (480 - 20) - rectSizeX;
	y = 16 + GUI_Y_OFFSET;
	GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX) * rectAAfactor, (y + rectSizeY) * 1.3 * rectAAfactor, rectRadius * rectAAfactor);

	// Oil Temparature END


	// DRS BEGIN

	static uint8_t drsStatus_old = 0;

	xt = (480 - rectSizeX) - 17;
	yt = 98 + GUI_Y_OFFSET;
	string = "DRS";
	GUI_SetFont(&GUI_Font32_1);
	GUI_DispStringAt(string, xt, yt);

	xt += 60;

	if(drsStatus != drsStatus_old)
	{
		GUI_SetColor(GUI_BLACK);
		GUI_FillRect(xt, yt, xt + 54, yt + 28);
	}

	drsStatus_old = drsStatus;

	switch(drsStatus)
	{
		case 0:
			GUI_SetColor(GUI_WHITE);
			string = "OFF";
			break;

		case 1:
			GUI_SetColor(GUI_GREEN);
			string = "ON";
			xt+=6;
			break;


		default:
			GUI_SetColor(GUI_RED);
			string = "ERR";
			break;
	}

	GUI_DispStringAt(string, xt, yt);

	if(drsStatus == 1)
		GUI_SetColor(GUI_GREEN);
	else
		GUI_SetColor(GUI_LIGHTGRAY);

	y = 94 + GUI_Y_OFFSET;
	GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX) * rectAAfactor, (y + rectSizeY) * rectAAfactor, rectRadius * rectAAfactor);
	// DRS END

	// MAP BEGIN

	static uint8_t map_old = 0;


	GUI_SetColor(GUI_LIGHTGRAY);
	xt = (480 - rectSizeX) - 17;
	yt = 158 + GUI_Y_OFFSET;
	string = "MAP";
	GUI_SetFont(&GUI_Font32_1);
	GUI_DispStringAt(string, xt, yt);

	xt += 60;
	yt += 5;

	if(map != map_old)
	{
		GUI_SetColor(GUI_BLACK);
		GUI_FillRect(xt, yt, xt + 54, yt + 28);
	}

	map_old = map;


	GUI_SetColor(GUI_WHITE);
	GUI_SetFont(&GUI_Font24_1);

	switch(map)
	{
		case 0:
			string = "BASE";
			break;

		case 1:
			string = "MAP1";
			break;

		case 2:
			string = "MAP2";
			break;

		case 3:
			string = "MAP3";
			break;

		default:
			string = "ERR";
			GUI_SetColor(GUI_RED);
			GUI_SetFont(&GUI_Font32_1);

			yt -= 5;
	}


	GUI_DispStringAt(string, xt, yt);

	GUI_SetColor(GUI_LIGHTGRAY);
	y = 154 + GUI_Y_OFFSET;
	GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX) * rectAAfactor, (y + rectSizeY) * rectAAfactor, rectRadius * rectAAfactor);

	// MAP END


	// T air BEGIN

	GUI_SetColor(GUI_LIGHTBLUE);

	xt = (480 - rectSizeX) - 12;
	yt = 221 + GUI_Y_OFFSET;
	string = "T AIR";
	GUI_SetFont(&GUI_Font16_1);
	GUI_DispStringAt(string, xt, yt);

	static GUI_DrawNumAtTypeDef tAirDisp = {0};

	tAirDisp.number = tAir;

	xt+= 60;
	yt-= 2;
	GUI_DrawNumAt(xt, yt, &GUI_Font20_1, GUI_LIGHTGRAY, GUI_BLACK, &tAirDisp, 2, 1, DISABLE, DISABLE, CENTER, a, b);


	y = 214 + GUI_Y_OFFSET;
	GUI_SetColor(GUI_LIGHTBLUE);
	GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX - 24) * rectAAfactor, (y + rectSizeY - 10) * rectAAfactor, rectRadius * rectAAfactor);

	// T air END

	// left rects END


	// TPS BEGIN

	static uint8_t tps_old = 0;

	GUI_SetColor(GUI_LIGHTBLUE);

	xt = 203;
	yt = 219 + GUI_Y_OFFSET;
	string = "TPS";
	GUI_SetFont(&GUI_Font16_1);
	GUI_DispStringAt(string, xt, yt);

	yt-=2;

	if(tps_old >= 10 && tps < 10)
	{
		GUI_SetColor(GUI_BLACK);
		GUI_FillRect(xt+30, yt, xt+78, yt+18);
	}

	GUI_SetColor(GUI_LIGHTGRAY);
	GUI_SetFont(&GUI_Font20B_1);

	if(tps < 10)
	{
		xt+= 48;
		GUI_DispDecAt(tps, xt, yt, 1);
	}
	else
	{
		xt+= 42;

		if(tps < 100)
		{
			GUI_DispDecAt(tps, xt, yt, 2);
		}
		else
		{
			GUI_SetColor(GUI_GREEN);
			GUI_DispDecAt(99, xt, yt, 2);
		}
	}

	tps_old = tps;


	x = (480 - (rectSizeX - 24)) / 2;
	y = 214 - 2 + GUI_Y_OFFSET;
	GUI_SetColor(GUI_LIGHTBLUE);
	GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX - 24) * rectAAfactor, (y + rectSizeY - 10) * rectAAfactor, rectRadius * rectAAfactor);

	// TPS END

	// Launch Control BAR BEGIN

	GUI_LaunchControlBar(launchControlStatus);

	// Launch Control BAR END


	//static GUI_DrawTimeAtTypeDef timeToDisplay = {0};
	//timeToDisplay.time = millis;

	//GUI_DrawTimeAt(480/2, 164, &GUI_Font32_1, GUI_LIGHTGRAY, GUI_BLACK, &timeToDisplay, TIME_FORMAT_HOURS, 3, DISABLE, CENTER);


	//_GUI_DrawNumAt(speed);


	//static GUI_DrawNumAtTypeDef speedText;
	//speedText.number = speed;

	a = "";
	b = "";
	//GUI_DrawNumAt(xt - 10, yt - 10, &GUI_Font32_1, GUI_WHITE, GUI_BLACK, &tWaterTEMP, 3, 1, DISABLE, DISABLE, RIGHT, a, b);
	//GUI_DrawNumAt(480/2, 160, &GUI_Font32_1, GUI_WHITE, GUI_BLACK, &speedText, 3, 1, DISABLE, DISABLE, CENTER, a, b);


	DisplayGui_Old2Armature();


	//CORE FUNCTION END

	DisplayGui_Old2_END:;
}



void DisplayGui_Old2Armature(void)
{
	GUI_SetColor(GUI_WHITE);

	//main rect (frame)
	GUI_DrawRect(1, 1, 479, 271);
	GUI_DrawRect(2, 2, 478, 270);

	//GUI_AA_DisableHiRes();
	//GUI_SetPenSize(1);
}


void DisplayGui_Old2_Intro(void)
{
	DisplayGui_Old2Armature();

	GUI_SetTextAlign(GUI_TA_HCENTER);

	GUI_SetColor(GUI_WHITE);
	GUI_SetFont(&GUI_Font32B_1);
	GUI_DispStringAt("PAGE", 236, 50);

	GUI_SetFont(&GUI_FontD80);
	GUI_DispDecAt(2, 214, 90, 1);

	GUI_SetTextAlign(GUI_TA_LEFT);

	GUI_SetColor(GUI_WHITE);
	GUI_SetBkColor(GUI_BLACK);
}
