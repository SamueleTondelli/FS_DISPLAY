

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

static void DisplayGui_Old1Armature(void);
static void DisplayGui_Old1_Intro(void);

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


void DisplayGui_Old1(void)
{
	// Intro section BEGIN
	static uint32_t millisGuiIntro = 0;
	static uint8_t introStatus = 0;

	if(selectedGui_old != GuiOld1 && selectedGui_old != GuiAlarm)
	{
		introStatus = 1;
		millisGuiIntro = millis;

		GUI_Clear();
	}

	if(introStatus == 1)
	{
		if(millis < millisGuiIntro + DISPLAY_GUI_INTRO_TIME)
		{
			DisplayGui_Old1_Intro();
			goto DisplayGui_Old1_END;
		}
		else
		{
			introStatus = 0;
			GUI_Clear();
		}
	}

	// Intro section END


	//CORE FUNCTION BEGIN

	//DisplayGui_Old1Armature();

	int x, y, xt, yt;
	char *string = "";

	char *a = "";
	char *b = "";

	static uint32_t millisDataRefresh = 0;
	static uint8_t dataRefresh = 1;

	if(millis >= millisDataRefresh + 100)
	{
		millisDataRefresh = millis;
		dataRefresh = 1;
	}


	//static uint8_t gear = 0;
	//static float tOil = 10;
	//static float tWater = 10;
	//static uint8_t drsStatus = 0;
	//static uint8_t map = 0;
	//static uint8_t tractionControl = 1;
	//static uint8_t p0_value = 2;
	//static uint16_t rpm = 0;
	//static uint8_t tps = 3;
	//float vBat = 0.1;

	/*
	static uint32_t timerToIncrement = 0;

	if(millis >= timerToIncrement + 1000)
	{
		gear++;
		tractionControl++;
		p0_value++;
		tps++;
		//vBat += 1.3;
		timerToIncrement = millis;
	}

	if((millis/3000)%2)
	{
		drsStatus = 1;
	}
	else
	{
		drsStatus = 0;
	}

	rpm += 31;
	tWater += 1.3;
	tOil += 1.3;
	vBat += 0.03;


	if(gear > 4) 						gear = 0;
	if(tractionControl > 6) 			tractionControl = 0;
	if(p0_value > 5) 					p0_value = 0;
	if(rpm > 16000) 					rpm = 0;
	if(tWater >= 300) 					tWater  = 10;
	if(tOil >= 300) 					tOil  = 10;
	if(tps > 28)						tps = 0;
	if(vBat > 15)						vBat = 0.1;

*/
	// RPM BAR BEGIN

	Display_OldRpmBar(3 + RPM_BAR_LENGTH_OFFSET, 23, 474 - RPM_BAR_LENGTH_OFFSET*2, 20, rpm, 0, 5500, 10500, 12500);

	//Display_OldRpmBar_STD(rpm);

	// RPM BAR END

	//GUI_SetColor(GUI_BLACK);

	// GEAR BEGIN

	static uint8_t gear_old = 0;

	if(gear_old != gear)
	{
		GUI_SetColor(GUI_BLACK);
		GUI_FillRect(190, 20 + GUI_Y_OFFSET, 290, 22 + 126 + GUI_Y_OFFSET + 30);
	}

#if HQ_GEARBOX_ENABLE == 0
	switch(gear)
	{
		case 0:
			GUI_DrawBitmap(&bmGEARBOX_N, (480 - bmGEARBOX_N.XSize)/2, 22 + GUI_Y_OFFSET + 30);
			break;

		case 1:
			GUI_DrawBitmap(&bmGEARBOX_1, (480 - bmGEARBOX_1.XSize)/2, 22 + GUI_Y_OFFSET + 30);
			break;

		case 2:
			GUI_DrawBitmap(&bmGEARBOX_2, (480 - bmGEARBOX_2.XSize)/2, 22 + GUI_Y_OFFSET + 30);
			break;

		case 3:
			GUI_DrawBitmap(&bmGEARBOX_3, (480 - bmGEARBOX_3.XSize)/2, 22 + GUI_Y_OFFSET + 30);
			break;

		case 4:
			GUI_DrawBitmap(&bmGEARBOX_4, (480 - bmGEARBOX_4.XSize)/2, 22 + GUI_Y_OFFSET + 30);
			break;

		default:
			GUI_SetColor(GUI_RED);
			GUI_FillRect(190, 22 + GUI_Y_OFFSET, 290, 22 + 126 + GUI_Y_OFFSET + 30);

	}
#elif HQ_GEARBOX_ENABLE == 1

		switch(CAR_Data.gear.intData)
		{
			case 0:
				GUI_DrawBitmap(&bmGEARBOX_N_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 6, 20 + GUI_Y_OFFSET + 30);
				break;

			case 1:
				GUI_DrawBitmap(&bmGEARBOX_1_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 15, 22 + GUI_Y_OFFSET + 30);
				break;

			case 2:
				GUI_DrawBitmap(&bmGEARBOX_2_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 13, 22 + GUI_Y_OFFSET + 30);
				break;

			case 3:
				GUI_DrawBitmap(&bmGEARBOX_3_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 15, 22 + GUI_Y_OFFSET + 30);
				break;

			case 4:
				GUI_DrawBitmap(&bmGEARBOX_4_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 9, 22 + GUI_Y_OFFSET + 30);
				break;

			default:
				GUI_SetColor(GUI_RED);
				GUI_FillRect(193, 84 + GUI_Y_OFFSET, 288, 207 + GUI_Y_OFFSET + 30);

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

	if(dataRefresh == 1)
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

	xt = 30;
	yt = 98 + GUI_Y_OFFSET;
	string = "TC";
	GUI_SetFont(&GUI_Font32_1);
	GUI_DispStringAt(string, xt, yt);


	xt += 46;

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

	if(dataRefresh == 1)
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

	if(dataRefresh == 1)
		vBatDispData.number = vBat;

	uint32_t vBatBackColor = GUI_BLACK;

	{
		static uint8_t blink_counter = 0;

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
				if(blink_counter >= 10)
					vBatBackColor = GUI_RED;

				blink_counter++;

				if(blink_counter >= 255) blink_counter = 30;
			}
			else
			{
				vBatBackColor = GUI_BLACK;
			}
		}
		else
		{
			GUI_SetColor(GUI_LIGHTBLUE);
			vBatBackColor = GUI_BLACK;

			blink_counter = 0;
		}
	}

	xt = 54;
	yt = 221 + GUI_Y_OFFSET;
	string = "V BAT";
	GUI_SetFont(&GUI_Font16_1);
	GUI_SetBkColor(vBatBackColor);
	GUI_SetColor(GUI_LIGHTBLUE);
	GUI_DispStringAt(string, xt, yt);


	xt += 60;
	yt -= 2;

	GUI_DrawNumAt(xt, yt, &GUI_Font20_1, GUI_LIGHTGRAY, vBatBackColor, &vBatDispData, 3, 1, DISABLE, DISABLE, CENTER, a, b);
	GUI_SetBkColor(GUI_BLACK);

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

	if(dataRefresh == 1)
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

	GUI_SetColor(GUI_LIGHTGRAY);
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


	if(drsStatus == 1)			GUI_SetColor(GUI_GREEN);
	else if (drsStatus == 0) 	GUI_SetColor(GUI_LIGHTGRAY);
	else 						GUI_SetColor(GUI_RED);

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

	GUI_SetColor(GUI_LIGHTGRAY);
	y = 154 + GUI_Y_OFFSET;
	GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX) * rectAAfactor, (y + rectSizeY) * rectAAfactor, rectRadius * rectAAfactor);

	// MAP END


	// RPM BEGIN

	static uint16_t rpm_old = 0;

	GUI_SetColor(GUI_LIGHTBLUE);

	xt = (480 - rectSizeX) - 12;
	yt = 221 + GUI_Y_OFFSET;
	string = "RPM";
	GUI_SetFont(&GUI_Font16_1);
	GUI_DispStringAt(string, xt, yt);

	yt-=2;

	if(rpm_old >= 10000 && rpm < 10000)
	{
		GUI_SetColor(GUI_BLACK);
		GUI_FillRect(xt+30, yt, xt+86, yt+18);
	}

	GUI_SetColor(GUI_LIGHTGRAY);
	GUI_SetFont(&GUI_Font20_1);

	if(rpm < 10000)
	{
		xt+= 40;
		GUI_DispDecAt(rpm, xt, yt, 4);
	}
	else
	{
		xt+= 32;
		GUI_DispDecAt(rpm, xt, yt, 5);
	}

	rpm_old = rpm;

	y = 214 + GUI_Y_OFFSET;
	GUI_SetColor(GUI_LIGHTBLUE);
	GUI_AA_DrawRoundedRect(x * rectAAfactor, y * rectAAfactor, (x + rectSizeX - 24) * rectAAfactor, (y + rectSizeY - 10) * rectAAfactor, rectRadius * rectAAfactor);


	// RPM END

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

	//GUI_LaunchControlBar(launchControlStatus);

	// Launch Control BAR END


	// Time BEGIN
	if(DEBUG_MODE == 1)
	{
		static GUI_DrawTimeAtTypeDef timeToDisplay = {0};
		timeToDisplay.time = millis;

		GUI_DrawTimeAt(480/2 - 4, 164, &GUI_Font32_1, GUI_LIGHTGRAY, GUI_BLACK, &timeToDisplay, TIME_FORMAT_HOURS, 3, DISABLE, CENTER);
	}
	// Time END

	GUI_SetColor(GUI_WHITE);

	DisplayGui_Old1Armature();

	dataRefresh = 0;

	//CORE FUNCTION END

	DisplayGui_Old1_END:;
}



void DisplayGui_Old1Armature(void)
{
	GUI_SetColor(GUI_WHITE);

	//main rect (frame)
	GUI_DrawRect(1, 1, 479, 271);
	GUI_DrawRect(2, 2, 478, 270);

	//GUI_AA_DisableHiRes();
	//GUI_SetPenSize(1);
}


void DisplayGui_Old1_Intro(void)
{
	DisplayGui_Old1Armature();

	GUI_SetTextAlign(GUI_TA_HCENTER);
	GUI_SetColor(GUI_WHITE);

	/*
	GUI_SetFont(&GUI_Font32B_1);
	GUI_DispStringAt("PAGE", 236, 50);

	GUI_SetFont(&GUI_FontD80);
	GUI_DispDecAt(1, 214, 90, 1);
	*/

	GUI_SetFont(&GUI_Font32B_1);
	GUI_DispStringAt("AUTOCROSS", 236, 50 + 50);


	GUI_SetTextAlign(GUI_TA_LEFT);

	GUI_SetColor(GUI_WHITE);
	GUI_SetBkColor(GUI_BLACK);
}
