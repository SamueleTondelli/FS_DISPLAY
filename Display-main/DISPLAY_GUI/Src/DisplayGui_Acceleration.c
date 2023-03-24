

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

static void DisplayGui_AccelerationArmature(void);
static void DisplayGui_Acceleration_Intro(void);

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


#define rectAAfactor				6
#define rectSizeX					120
#define rectSizeY					40
#define rectRadius					12
#define rectThickness				4

#define GUI_Y_OFFSET				16

#define RPM_BAR_LENGTH_OFFSET		0

#define RPM_SMALL 					0  //1 = small, 2 = big whit text, other = very big


void DisplayGui_Acceleration(void)
{
	// Intro section BEGIN
	static uint32_t millisGuiIntro = 0;
	static uint8_t introStatus = 0;

	if(selectedGui_old != GuiAcceleration && selectedGui_old != GuiAlarm)
	{
		introStatus = 1;
		millisGuiIntro = millis;

		GUI_Clear();
	}

	if(introStatus == 1)
	{
		if(millis < millisGuiIntro + DISPLAY_GUI_INTRO_TIME)
		{
			DisplayGui_Acceleration_Intro();
			goto DisplayGui_Acceleration_END;
		}
		else
		{
			introStatus = 0;
			GUI_Clear();
		}
	}

	// Intro section END


	//CORE FUNCTION BEGIN

	int x, y, xt, yt;
	char *string = "";

	char *a = "";
	char *b = "";

	static uint8_t blinkClock = 0;
	static uint32_t millisBlinkClock = 0;

	if(millis >= millisBlinkClock + 250)
	{
		millisBlinkClock = millis;

		if(blinkClock == 0)
			blinkClock = 1;
		else
			blinkClock = 0;
	}


	static uint32_t millisDataRefresh = 0;
	static uint8_t dataRefresh = 1;

	if(millis >= millisDataRefresh + 100)
	{
		millisDataRefresh = millis;
		dataRefresh = 1;
	}

	// RPM BAR BEGIN

	Display_OldRpmBar_STD(CAR_Data.rpm.intData);

	// RPM BAR END

	// GEAR BEGIN

	static uint8_t gear_old = 0;

	if(gear_old != gear)
	{
		GUI_SetColor(GUI_BLACK);
		GUI_FillRect(190, 20 + GUI_Y_OFFSET, 290, 22 + 126 + GUI_Y_OFFSET + 50);
	}

#if HQ_GEARBOX_ENABLE == 0
	switch(gear)
	{
		case 0:
			GUI_DrawBitmap(&bmGEARBOX_N, (480 - bmGEARBOX_N.XSize)/2, 22 + GUI_Y_OFFSET + 50);
			break;

		case 1:
			GUI_DrawBitmap(&bmGEARBOX_1, (480 - bmGEARBOX_1.XSize)/2, 22 + GUI_Y_OFFSET + 50);
			break;

		case 2:
			GUI_DrawBitmap(&bmGEARBOX_2, (480 - bmGEARBOX_2.XSize)/2, 22 + GUI_Y_OFFSET + 50);
			break;

		case 3:
			GUI_DrawBitmap(&bmGEARBOX_3, (480 - bmGEARBOX_3.XSize)/2, 22 + GUI_Y_OFFSET + 50);
			break;

		case 4:
			GUI_DrawBitmap(&bmGEARBOX_4, (480 - bmGEARBOX_4.XSize)/2, 22 + GUI_Y_OFFSET + 50);
			break;

		default:
			GUI_SetColor(GUI_RED);
			GUI_FillRect(190, 22 + GUI_Y_OFFSET, 290, 22 + 126 + GUI_Y_OFFSET + 50);

	}
#elif HQ_GEARBOX_ENABLE == 1

		switch(CAR_Data.gear.intData)
		{
			case 0:
				GUI_DrawBitmap(&bmGEARBOX_N_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 6, 20 + GUI_Y_OFFSET + 50);
				break;

			case 1:
				GUI_DrawBitmap(&bmGEARBOX_1_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 15, 22 + GUI_Y_OFFSET + 50);
				break;

			case 2:
				GUI_DrawBitmap(&bmGEARBOX_2_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 13, 22 + GUI_Y_OFFSET + 50);
				break;

			case 3:
				GUI_DrawBitmap(&bmGEARBOX_3_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 15, 22 + GUI_Y_OFFSET + 50);
				break;

			case 4:
				GUI_DrawBitmap(&bmGEARBOX_4_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 9, 22 + GUI_Y_OFFSET + 50);
				break;

			default:
				GUI_SetColor(GUI_RED);
				GUI_FillRect(193, 84 + GUI_Y_OFFSET, 288, 207 + GUI_Y_OFFSET + 50);

		}

#endif

	gear_old = gear;

	// GEAR END


	GUI_AA_SetFactor(rectAAfactor);
	GUI_AA_EnableHiRes();
	GUI_AA_SetFactor(rectAAfactor);

	GUI_SetPenSize(rectThickness);


	// 0 - 100 last acceleration time BEGIN

	xt = 34 + 70;
	yt = 21 + 25 + GUI_Y_OFFSET;

	static GUI_DrawNumAtTypeDef lastAccelerationTimeToDisplay = {0};
	lastAccelerationTimeToDisplay.number = (float)CAR_Data.lastAccelerationTime/1000;

	b = " s";

	if(CAR_Data.lastAccelerationTime < 10000)
		GUI_DrawNumAt(xt - 24, yt - 10, &GUI_Font32_1, GUI_WHITE, GUI_BLACK, &lastAccelerationTimeToDisplay, 1, 3, DISABLE, ENABLE, CENTER, a, b);
	else
		GUI_DrawNumAt(xt - 24, yt - 10, &GUI_Font32_1, GUI_WHITE, GUI_BLACK, &lastAccelerationTimeToDisplay, 2, 3, DISABLE, ENABLE, CENTER, a, b);

	b = "";

	GUI_SetColor(GUI_LIGHTGRAY);

	xt = 34;
	yt = 21 + GUI_Y_OFFSET;
	string = "0-100 Km/h";
	GUI_SetFont(&GUI_Font20_1);
	GUI_DispStringAt(string, xt, yt);

	// Water Temparature END

	// Traction Control "TC" BEGIN

	static uint8_t tractionControl_old = 0;

	GUI_SetColor(GUI_LIGHTGRAY);

	x = 20;
	y = 16 + GUI_Y_OFFSET;
	GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX) * rectAAfactor, (y + rectSizeY) * 1.3 * rectAAfactor, rectRadius * rectAAfactor);


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
	GUI_SetColor(GUI_RED);

	switch(tractionControl)
	{
		case 0:
			string = "OFF";
			GUI_SetFont(&GUI_Font32_1);
			GUI_SetColor(GUI_GREEN);
			break;

		case 1:
			string = "1";
			xt+=18;
			GUI_SetColor(GUI_ORANGE);
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

	static uint32_t millisTractionBlink = 0;
	static uint8_t tractionBlinkStatus = 0;

	switch(tractionControl)
	{
		case 0:
			GUI_SetColor(GUI_LIGHTGRAY);
			tractionBlinkStatus = 0;
			break;

		case 1:
			GUI_SetColor(GUI_ORANGE);
			tractionBlinkStatus = 0;
			break;

		case 2:
		case 3:
		case 4:
		default:

			tractionBlinkStatus = 1;

			break;
	}

	if(tractionBlinkStatus == 1 && blinkClock == 1)
		GUI_SetColor(GUI_RED);
	else
		GUI_SetColor(GUI_LIGHTGRAY);

	//GUI_SetColor(GUI_LIGHTGRAY);

	y = 94 + GUI_Y_OFFSET;
	GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX) * rectAAfactor, (y + rectSizeY) * rectAAfactor, rectRadius * rectAAfactor);

	// Traction Control "TC" END


	// SPEED BEGIN

	static GUI_DrawNumAtTypeDef speedTempGui;

	GUI_SetColor(GUI_LIGHTGRAY);

	xt = 30;
	yt = 158 + GUI_Y_OFFSET;
	string = "Km/h";
	GUI_SetFont(&GUI_Font24_1);
	GUI_DispStringAt(string, xt, yt + 5);

	speedTempGui.number = CAR_Data.speed.floatData;

	xt += 76;
	//yt += 2;

	a = "";
	b = "";

	GUI_DrawNumAt(xt, yt, &GUI_Font32_1, GUI_WHITE, GUI_BLACK, &speedTempGui, 3, 0, DISABLE, DISABLE, CENTER, a, b);

	GUI_SetColor(GUI_LIGHTGRAY);

	y = 154 + GUI_Y_OFFSET;
	GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX) * rectAAfactor, (y + rectSizeY) * rectAAfactor, rectRadius * rectAAfactor);

	// P Oil END


	// V BAT BEGIN

	xt = 54;
	yt = 221 + GUI_Y_OFFSET;
	string = "V BAT";
	GUI_SetFont(&GUI_Font16_1);
	GUI_SetColor(GUI_LIGHTBLUE);
	GUI_DispStringAt(string, xt, yt);

	static GUI_DrawNumAtTypeDef vBatDispData = {0};

	if(dataRefresh == 1)
		vBatDispData.number = vBat;

	xt += 60;
	yt -= 2;

	GUI_DrawNumAt(xt, yt, &GUI_Font20_1, GUI_LIGHTGRAY, GUI_BLACK, &vBatDispData, 2, 1, DISABLE, DISABLE, CENTER, a, b);


	y = 214 + GUI_Y_OFFSET;
	GUI_SetColor(GUI_LIGHTBLUE);
	GUI_AA_DrawRoundedRect((x + 24) * rectAAfactor, y * rectAAfactor, (x + rectSizeX) * rectAAfactor, (y + rectSizeY - 10) * rectAAfactor, rectRadius * rectAAfactor);

	// V BAT END
	// right rects END


	// left rects BEGIN

	// Best 0-100 BEGIN

	xt = (480 - rectSizeX) + 65;
	yt = 21 + 25 + GUI_Y_OFFSET;

	static GUI_DrawNumAtTypeDef bestAccelerationTimeToDisplay = {0};
	bestAccelerationTimeToDisplay.number = (float)CAR_Data.bestAccelerationTime/1000;

	b = " s";

	if(CAR_Data.bestAccelerationTime < 10000)
		GUI_DrawNumAt(xt - 24, yt - 10, &GUI_Font32_1, GUI_WHITE, GUI_BLACK, &bestAccelerationTimeToDisplay, 1, 3, DISABLE, ENABLE, CENTER, a, b);
	else
		GUI_DrawNumAt(xt - 24, yt - 10, &GUI_Font32_1, GUI_WHITE, GUI_BLACK, &bestAccelerationTimeToDisplay, 2, 3, DISABLE, ENABLE, CENTER, a, b);

	b = "";

	GUI_SetColor(GUI_LIGHTGRAY);

	xt = (480 - rectSizeX) - 2;
	yt = 21 + GUI_Y_OFFSET;
	string = "Best 0-100";
	GUI_SetFont(&GUI_Font20_1);
	GUI_DispStringAt(string, xt, yt);


	x = (480 - 20) - rectSizeX;
	y = 16 + GUI_Y_OFFSET;
	GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX) * rectAAfactor, (y + rectSizeY) * 1.3 * rectAAfactor, rectRadius * rectAAfactor);

	// Best 0-100 END


	// DRS BEGIN

	static uint8_t drsStatus_old = 0;

	xt = (480 - rectSizeX) - 17;
	//yt = 98 + GUI_Y_OFFSET;
	yt = 158 + GUI_Y_OFFSET;
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

	//y = 94 + GUI_Y_OFFSET;
	//x = (480 - 20) - rectSizeX;

	x = (480 - 20) - rectSizeX;
	y = 154 + GUI_Y_OFFSET;
	GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX) * rectAAfactor, (y + rectSizeY) * rectAAfactor, rectRadius * rectAAfactor);
	// DRS END

	// MAP BEGIN

	static uint8_t map_old = 0;


	GUI_SetColor(GUI_LIGHTGRAY);
	xt = (480 - rectSizeX) - 17;
	//yt = 158 + GUI_Y_OFFSET;
	yt = 98 + GUI_Y_OFFSET;
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


	//GUI_SetColor(GUI_WHITE);
	GUI_SetColor(GUI_RED);
	GUI_SetFont(&GUI_Font24_1);

	switch(map)
	{
		case 0:
			string = "BASE";
			GUI_SetColor(GUI_GREEN);
			break;

		case 1:
			string = "ECO";
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

	static uint32_t millisMapBlink = 0;
	static uint8_t mapBlinkStatus = 0;

	switch(map)
	{
	case 0:
		//GUI_SetColor(GUI_LIGHTGRAY);
		mapBlinkStatus = 0;
		break;

	case 1:
	case 2:
	case 3:
	default:

		mapBlinkStatus = 1;

		break;
	}


	if(mapBlinkStatus == 1 && blinkClock == 1)
		GUI_SetColor(GUI_RED);
	else
		GUI_SetColor(GUI_LIGHTGRAY);

	//GUI_SetColor(GUI_LIGHTGRAY);
	//x = (480 - 20) - rectSizeX;
	//y = 154 + GUI_Y_OFFSET;

	y = 94 + GUI_Y_OFFSET;
	x = (480 - 20) - rectSizeX;
	GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX) * rectAAfactor, (y + rectSizeY) * rectAAfactor, rectRadius * rectAAfactor);

	// MAP END


	// T oil BEGIN

	GUI_SetColor(GUI_LIGHTBLUE);

	xt = (480 - rectSizeX) - 12;
	yt = 221 + GUI_Y_OFFSET;
	string = "T OIL";
	GUI_SetFont(&GUI_Font16_1);
	GUI_DispStringAt(string, xt, yt);

	static GUI_DrawNumAtTypeDef tAirDisp = {0};

	if(dataRefresh == 1)
		tAirDisp.number = CAR_Data.oilTemp.floatData;

	xt+= 60;
	yt-= 2;
	GUI_DrawNumAt(xt, yt, &GUI_Font20_1, GUI_LIGHTGRAY, GUI_BLACK, &tAirDisp, 2, 1, DISABLE, DISABLE, CENTER, a, b);

	x = (480 - 20) - rectSizeX;
	y = 214 + GUI_Y_OFFSET;
	GUI_SetColor(GUI_LIGHTBLUE);
	GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX - 24) * rectAAfactor, (y + rectSizeY - 10) * rectAAfactor, rectRadius * rectAAfactor);

	// T oil END

	// left rects END


	// RPM BEGIN

	#if RPM_SMALL == 1		//normal rpm

		static uint16_t rpm_old = 0;

		GUI_SetColor(GUI_LIGHTBLUE);

		xt = 202;
		yt = 221 + GUI_Y_OFFSET - 190;
		string = "RPM";
		GUI_SetFont(&GUI_Font16_1);
		GUI_DispStringAt(string, xt, yt);

		yt-=2;

		if(rpm_old >= 10000 && CAR_Data.rpm.intData < 10000)
		{
			GUI_SetColor(GUI_BLACK);
			GUI_FillRect(xt+30, yt, xt+86, yt+18);
		}

		GUI_SetColor(GUI_LIGHTGRAY);
		GUI_SetFont(&GUI_Font20_1);

		switch(CAR_Data.gear.intData)
		{
			case 0:
				if(CAR_Data.rpm.intData >= 9200 && CAR_Data.rpm.intData <= 10800)		//lounch
					GUI_SetColor(GUI_GREEN);
				break;

			case 1:
				if(CAR_Data.rpm.intData >= 9400 && CAR_Data.rpm.intData <= 10900)
					GUI_SetColor(GUI_GREEN);
				if(CAR_Data.rpm.intData > 10900)
					GUI_SetColor(GUI_ORANGE);
				break;

			case 2:
				if(CAR_Data.rpm.intData >= 9600 && CAR_Data.rpm.intData <= 10800)		//200 ms before 10500 (9600 rpm)
					GUI_SetColor(GUI_GREEN);
				if(CAR_Data.rpm.intData > 10800)
					GUI_SetColor(GUI_ORANGE);
				break;

			case 3:
				if(CAR_Data.rpm.intData >= 10000 && CAR_Data.rpm.intData <= 10700)		//200 ms before 10500 (10000 rpm)
					GUI_SetColor(GUI_GREEN);
				if(CAR_Data.rpm.intData > 10700)
					GUI_SetColor(GUI_ORANGE);
				break;
		}

		if(CAR_Data.rpm.intData < 10000)
		{
			xt+= 40;
			GUI_DispDecAt(CAR_Data.rpm.intData, xt, yt, 4);
		}
		else
		{
			xt+= 32;
			GUI_DispDecAt(CAR_Data.rpm.intData, xt, yt, 5);
		}

		rpm_old = CAR_Data.rpm.intData;

		x = (480 - (rectSizeX - 24)) / 2;
		y = 214 + GUI_Y_OFFSET;
		GUI_SetColor(GUI_LIGHTBLUE);
		GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX - 24) * rectAAfactor, (y + rectSizeY - 10) * rectAAfactor, rectRadius * rectAAfactor);

	#elif RPM_SMALL == 2		//big rpm whit "RPM" text

		static uint16_t rpm_old = 0;

		GUI_SetColor(GUI_LIGHTBLUE);

		xt = (480 - rectSizeX) / 2 + 2;
		yt = 214 + GUI_Y_OFFSET - 190;
		string = "RPM";
		GUI_SetFont(&GUI_Font20_1);
		GUI_DispStringAt(string, xt, yt);

		yt-=6;

		if(rpm_old >= 10000 && CAR_Data.rpm.intData < 10000)
		{
			GUI_SetColor(GUI_BLACK);
			GUI_FillRect(xt + 40, yt + 2, xt + 110, yt + 26);
		}

		GUI_SetColor(GUI_WHITE);
		GUI_SetFont(&GUI_Font32_1);

		switch(CAR_Data.gear.intData)
		{
			case 0:
				if(CAR_Data.rpm.intData >= 9200 && CAR_Data.rpm.intData <= 10800)		//lounch
					GUI_SetColor(GUI_GREEN);
				break;

			case 1:
				if(CAR_Data.rpm.intData >= 9400 && CAR_Data.rpm.intData <= 10900)
					GUI_SetColor(GUI_GREEN);
				if(CAR_Data.rpm.intData > 10900)
					GUI_SetColor(GUI_ORANGE);
				break;

			case 2:
				if(CAR_Data.rpm.intData >= 9600 && CAR_Data.rpm.intData <= 10800)		//200 ms before 10500 (9600 rpm)
					GUI_SetColor(GUI_GREEN);
				if(CAR_Data.rpm.intData > 10800)
					GUI_SetColor(GUI_ORANGE);
				break;

			case 3:
				if(CAR_Data.rpm.intData >= 10000 && CAR_Data.rpm.intData <= 10700)		//200 ms before 10500 (10000 rpm)
					GUI_SetColor(GUI_GREEN);
				if(CAR_Data.rpm.intData > 10700)
					GUI_SetColor(GUI_ORANGE);
				break;
		}

		if(CAR_Data.rpm.intData < 10000)
		{
			xt+= 48;
			GUI_DispDecAt(CAR_Data.rpm.intData, xt, yt, 4);
		}
		else
		{
			xt+= 40;
			GUI_DispDecAt(CAR_Data.rpm.intData, xt, yt, 5);
		}

		rpm_old = CAR_Data.rpm.intData;

		x = (480 - rectSizeX) / 2;
		y = 204 + GUI_Y_OFFSET;
		GUI_SetColor(GUI_LIGHTGRAY);
		GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX) * rectAAfactor, (y + rectSizeY) * rectAAfactor, rectRadius * rectAAfactor);

	#else			//very big rpm whitout other texts or lines

		static uint16_t rpm_old = 0;

		GUI_SetColor(GUI_LIGHTBLUE);


		xt = 480 / 2 - 50 + 2;
		yt = 210 + GUI_Y_OFFSET - 190;

		if(rpm_old >= 10000 && CAR_Data.rpm.intData < 10000)
		{
			GUI_SetColor(GUI_BLACK);
			GUI_FillRect(xt - 14, yt - 2, xt + 110, yt + 32);
		}

		GUI_SetColor(GUI_WHITE);
		GUI_SetFont(&GUI_FontD32);

		switch(CAR_Data.gear.intData)
		{
			case 0:
				if(CAR_Data.rpm.intData >= 9200 && CAR_Data.rpm.intData <= 10800)		//lounch
					GUI_SetColor(GUI_GREEN);
				break;

			case 1:
				if(CAR_Data.rpm.intData >= 9400 && CAR_Data.rpm.intData <= 10900)
					GUI_SetColor(GUI_GREEN);
				if(CAR_Data.rpm.intData > 10900)
					GUI_SetColor(GUI_ORANGE);
				break;

			case 2:
				if(CAR_Data.rpm.intData >= 9600 && CAR_Data.rpm.intData <= 10800)		//200 ms before 10500 (9600 rpm)
					GUI_SetColor(GUI_GREEN);
				if(CAR_Data.rpm.intData > 10800)
					GUI_SetColor(GUI_ORANGE);
				break;

			case 3:
				if(CAR_Data.rpm.intData >= 10000 && CAR_Data.rpm.intData <= 10700)		//200 ms before 10500 (10000 rpm)
					GUI_SetColor(GUI_GREEN);
				if(CAR_Data.rpm.intData > 10700)
					GUI_SetColor(GUI_ORANGE);
				break;
		}

		if(CAR_Data.rpm.intData < 10000)
		{
			//xt+= 48;
			GUI_DispDecAt(CAR_Data.rpm.intData, xt, yt, 4);
		}
		else
		{
			xt-= 12;
			GUI_DispDecAt(CAR_Data.rpm.intData, xt, yt, 5);
		}

		rpm_old = CAR_Data.rpm.intData;
/*
		x = (480 - rectSizeX) / 2;
		y = 206 + GUI_Y_OFFSET;
		GUI_SetColor(GUI_LIGHTGRAY);
		GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX) * rectAAfactor, (y + rectSizeY) * rectAAfactor, rectRadius * rectAAfactor);
*/

	#endif

	// RPM END


	// Launch Control BAR BEGIN

	//GUI_LaunchControlBar(launchControlStatus);

	// Launch Control BAR END




	//static GUI_DrawTimeAtTypeDef timeToDisplay = {0};
	//timeToDisplay.time = millis;

	//GUI_DrawTimeAt(480/2, 164, &GUI_Font32_1, GUI_LIGHTGRAY, GUI_BLACK, &timeToDisplay, TIME_FORMAT_HOURS, 3, DISABLE, CENTER);


	static GUI_BarTypeDef throttleBar = {0};

	throttleBar.x = 480/2 - 140/2;
	throttleBar.y = 180 + 50;
	throttleBar.size_x = 140;
	throttleBar.size_y = 10;
	throttleBar.frameSize = 1;
	throttleBar.frameColor = GUI_LIGHTGREEN;
	throttleBar.backgroundColor = GUI_BLACK;
	throttleBar.barColor = GUI_GREEN;
	throttleBar.barMode = GUI_BAR_LTR;
	//throttleBar.maxValue = 100;
	throttleBar.maxValue = 95;
	//throttleBar.minValue = 0;
	throttleBar.minValue = 5;

	GUI_Bar(&throttleBar, CAR_Data.pedal.intData);
	//GUI_Bar(&throttleBar, pippo);

	DisplayGui_AccelerationArmature();


	dataRefresh = 0;

	//CORE FUNCTION END

	DisplayGui_Acceleration_END:;
}



void DisplayGui_AccelerationArmature(void)
{
	GUI_SetColor(GUI_WHITE);

	//main rect (frame)
	GUI_DrawRect(1, 1, 479, 271);
	GUI_DrawRect(2, 2, 478, 270);
}


void DisplayGui_Acceleration_Intro(void)
{
	DisplayGui_AccelerationArmature();

	GUI_SetColor(GUI_WHITE);
	GUI_SetFont(&GUI_Font32B_1);
	//GUI_DispStringAt("PAGE", 200, 50);

	//GUI_SetFont(&GUI_FontD80);
	//GUI_DispDecAt(2, 214, 90, 1);

	//GUI_DispStringAt("ACCELERATION", 130, 90);
	GUI_DispStringAt("ACCELERATION", 130, 100);

	GUI_SetColor(GUI_WHITE);
	GUI_SetBkColor(GUI_BLACK);
}
