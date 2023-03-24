

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

#include "string.h"


#ifndef __DISPLAY_DRIVESTD_H
#include "Display_DriveSTD.h"
#endif

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

extern GUI_CONST_STORAGE GUI_FONT GUI_FontCalibri24Balised4pp;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontCalibri44Balised4pp;
extern GUI_CONST_STORAGE GUI_FONT GUI_FontCalibri230Balised2pp_DigAndMaiusc;

#define HQ_GEARBOX_ENABLE 			1							// 0 == DISABLED, 1 == ENABLED
#define GEARBOX_COLOR_ENABLE		0							// 0 == DISABLED, 1 == ENABLED (avaible only with HQ_GEARBOX_ENABLE) WARNING: if unused MUST BE 0

#define HQ_TEXT_ENABLE				1							// 0 == DISABLED, 1 == ENABLED

#define HQ_TEXT_TEXT_FONT			GUI_FontCalibri24Balised4pp//GUI_Font20_1
#define HQ_TEXT_BIG_TEXT_FONT		GUI_FontCalibri24Balised4pp//GUI_Font20B_1
#define HQ_TEXT_DATA_FONT			GUI_FontCalibri44Balised4pp

#if HQ_TEXT_ENABLE == 0
#define DriveSTD_TextFont			GUI_Font20_1
#define DriveSTD_BigTextFont		GUI_Font20B_1
#define DriveSTD_DataFont			GUI_Font32B_1
//#define DriveSTD_DataOffset_x		0
#define DriveSTD_DataOffset_y		0
#elif HQ_TEXT_ENABLE == 1
#define DriveSTD_TextFont			HQ_TEXT_TEXT_FONT
#define DriveSTD_BigTextFont		HQ_TEXT_BIG_TEXT_FONT
#define DriveSTD_DataFont			HQ_TEXT_DATA_FONT
//#define DriveSTD_DataOffset_x		0
#define DriveSTD_DataOffset_y		+2
#endif

#define RPM_GREEN_MIN	11000
#define RPM_GREEN_MAX	12000
#define RPM_RED			12000

#define blinkColckPeriod				250


#define PAGE_TEXT_COLOR				GUI_WHITE
#define PAGE_DATA_COLOR				GUI_WHITE
#define PAGE_BACK_COLOR				GUI_BLACK

#define DEFAULT_MIN_TIME_VALUE_OVER		1000

#define DEFAULT_BLINKING_FRAME_SIZE		4

#define DEFAULT_BLINK_DELAY_OVER		250
#define DEFAULT_BLINK_DELAY_UNDER		250

#define NO_BLINK_DELAY					10000

#define DEFAULT_NO_DATA_ERROR_DELAY		1000


static void Display_Frame(uint32_t color);
static void Display_Armature(void);

void Display_DenseDataLogArmature(void);


typedef struct
{
	uint16_t xVertex1; //top left vertex x
	uint16_t yVertex1; //top left vertex y

	uint16_t xVertex2; //bottom right vertex x
	uint16_t yVertex2; //bottom right vertex y
}Typedef_rectInformations;


#define rectNumber 15
Typedef_rectInformations pageRectPositions[rectNumber];


DisplayGui_DataGuiTypeDef DriveSTD_noData 			= {0};
DisplayGui_DataGuiTypeDef DriveSTD_waterTemp 		= {0};
DisplayGui_DataGuiTypeDef DriveSTD_oilTemp 			= {0};
DisplayGui_DataGuiTypeDef DriveSTD_fuelTemp 		= {0};
DisplayGui_DataGuiTypeDef DriveSTD_airTemp 			= {0};
DisplayGui_DataGuiTypeDef DriveSTD_fuelPressure 	= {0};
DisplayGui_DataGuiTypeDef DriveSTD_oilPressure 		= {0};
DisplayGui_DataGuiTypeDef DriveSTD_batteryVoltage 	= {0};
DisplayGui_DataGuiTypeDef DriveSTD_tps 				= {0};
DisplayGui_DataGuiTypeDef DriveSTD_speed 			= {0};
DisplayGui_DataGuiTypeDef DriveSTD_traction 		= {0};
DisplayGui_DataGuiTypeDef DriveSTD_map		 		= {0};
DisplayGui_DataGuiTypeDef DriveSTD_drsStatus 		= {0};
DisplayGui_DataGuiTypeDef DriveSTD_brakeBias 		= {0};
DisplayGui_DataGuiTypeDef DriveSTD_brake 			= {0};
DisplayGui_DataGuiTypeDef DriveSTD_brakeRear 		= {0};
DisplayGui_DataGuiTypeDef DriveSTD_RL_Ty_Temp 		= {0};
DisplayGui_DataGuiTypeDef DriveSTD_RR_Ty_Temp 		= {0};
DisplayGui_DataGuiTypeDef DriveSTD_FL_Ty_Temp 		= {0};
DisplayGui_DataGuiTypeDef DriveSTD_FR_Ty_Temp 		= {0};


void rectInitialization(void)
{
	pageRectPositions[0].xVertex1 = 3 + 0*95;
	pageRectPositions[0].yVertex1 = 34 + 52 + 1;
	pageRectPositions[0].xVertex2 = pageRectPositions[0].xVertex1 + 95 - 2;
	pageRectPositions[0].yVertex2 = pageRectPositions[0].yVertex1 + 61 - 2;

	pageRectPositions[1].xVertex1 = 3 + 0*95;
	pageRectPositions[1].yVertex1 = 34 + 52 + 1*61 + 1;
	pageRectPositions[1].xVertex2 = pageRectPositions[1].xVertex1 + 95 - 2;
	pageRectPositions[1].yVertex2 = pageRectPositions[1].yVertex1 + 61 - 2;

	pageRectPositions[2].xVertex1 = 3 + 0*95;
	pageRectPositions[2].yVertex1 = 34 + 52 + 2*61 + 1;
	pageRectPositions[2].xVertex2 = pageRectPositions[2].xVertex1 + 95 - 2;
	pageRectPositions[2].yVertex2 = pageRectPositions[2].yVertex1 + 61 - 2 + 1;

	pageRectPositions[3].xVertex1 = 3 + 1*95;
	pageRectPositions[3].yVertex1 = 34 + 52 + 2*61 + 1;
	pageRectPositions[3].xVertex2 = pageRectPositions[3].xVertex1 + 95 - 2;
	pageRectPositions[3].yVertex2 = pageRectPositions[3].yVertex1 + 61 - 2 + 1;

	pageRectPositions[4].xVertex1 = 3 + 1*95;
	pageRectPositions[4].yVertex1 = 34 + 52 + 1*61 + 1;
	pageRectPositions[4].xVertex2 = pageRectPositions[4].xVertex1 + 95 - 2;
	pageRectPositions[4].yVertex2 = pageRectPositions[4].yVertex1 + 61 - 2;

	pageRectPositions[5].xVertex1 = 3 + 1*95;
	pageRectPositions[5].yVertex1 = 34 + 52 + 1;
	pageRectPositions[5].xVertex2 = pageRectPositions[5].xVertex1 + 95 - 2;
	pageRectPositions[5].yVertex2 = pageRectPositions[5].yVertex1 + 61 - 2;


	pageRectPositions[5 + 1].xVertex1 = 4 + 3*95;
	pageRectPositions[5 + 1].yVertex1 = 34 + 52 + 1;
	pageRectPositions[5 + 1].xVertex2 = pageRectPositions[5 + 1].xVertex1 + 95 - 2;
	pageRectPositions[5 + 1].yVertex2 = pageRectPositions[5 + 1].yVertex1 + 61 - 2;

	pageRectPositions[5 + 2].xVertex1 = 4 + 3*95;
	pageRectPositions[5 + 2].yVertex1 = 34 + 52 + 1*61 + 1;
	pageRectPositions[5 + 2].xVertex2 = pageRectPositions[5 + 2].xVertex1 + 95 - 2;
	pageRectPositions[5 + 2].yVertex2 = pageRectPositions[5 + 2].yVertex1 + 61 - 2;

	pageRectPositions[5 + 3].xVertex1 = 4 + 3*95;
	pageRectPositions[5 + 3].yVertex1 = 34 + 52 + 2*61 + 1;
	pageRectPositions[5 + 3].xVertex2 = pageRectPositions[5 + 3].xVertex1 + 95 - 2;
	pageRectPositions[5 + 3].yVertex2 = pageRectPositions[5 + 3].yVertex1 + 61 - 2 + 1;

	pageRectPositions[5 + 4].xVertex1 = 4 + 4*95;
	pageRectPositions[5 + 4].yVertex1 = 34 + 52 + 2*61 + 1;
	pageRectPositions[5 + 4].xVertex2 = pageRectPositions[5 + 4].xVertex1 + 95 - 2;
	pageRectPositions[5 + 4].yVertex2 = pageRectPositions[5 + 4].yVertex1 + 61 - 2 + 1;

	pageRectPositions[5 + 5].xVertex1 = 4 + 4*95;
	pageRectPositions[5 + 5].yVertex1 = 34 + 52 + 1*61 + 1;
	pageRectPositions[5 + 5].xVertex2 = pageRectPositions[5 + 5].xVertex1 + 95 - 2;
	pageRectPositions[5 + 5].yVertex2 = pageRectPositions[5 + 5].yVertex1 + 61 - 2;

	pageRectPositions[5 + 6].xVertex1 = 4 + 4*95;
	pageRectPositions[5 + 6].yVertex1 = 34 + 52 + 1;
	pageRectPositions[5 + 6].xVertex2 = pageRectPositions[5 + 6].xVertex1 + 95 - 2;
	pageRectPositions[5 + 6].yVertex2 = pageRectPositions[5 + 6].yVertex1 + 61 - 2;


	pageRectPositions[12].xVertex1 = 3 + 2*95;
	pageRectPositions[12].yVertex1 = 34 + 52 + 2*61 + 1;
	pageRectPositions[12].xVertex2 = pageRectPositions[12].xVertex1 + 95 - 2 + 1;
	pageRectPositions[12].yVertex2 = pageRectPositions[12].yVertex1 + 61 - 2 + 1;



	pageRectPositions[13].xVertex1 = 3;
	pageRectPositions[13].yVertex1 = 34 + 1;
	pageRectPositions[13].xVertex2 = pageRectPositions[13].xVertex1 + 2*88 - 1 - 2;
	pageRectPositions[13].yVertex2 = pageRectPositions[13].yVertex1 + 52 - 2;

	pageRectPositions[14].xVertex1 = 480 - 2 - 2*88 + 1 + 1;
	pageRectPositions[14].yVertex1 = 34 + 1;
	pageRectPositions[14].xVertex2 = pageRectPositions[14].xVertex1 + 2*88 - 1 - 2;
	pageRectPositions[14].yVertex2 = pageRectPositions[14].yVertex1 + 52 - 2;
}

void defaultDataInitialization(void)
{
	DriveSTD_noData.enable = DISABLE;

	DriveSTD_noData.string = "Data";
	DriveSTD_noData.intStr = "";
	DriveSTD_noData.endStr = "";

	DriveSTD_noData.dataPointer = &defaultDataPointed;
	DriveSTD_noData.dataLogInt.number = 123;
	DriveSTD_noData.dataLogFloat.number = 0.7;
	DriveSTD_noData.decimalDigits = 1;

	DriveSTD_noData.textColor = PAGE_TEXT_COLOR;
	DriveSTD_noData.dataColor = PAGE_DATA_COLOR;
	DriveSTD_noData.backColor = PAGE_BACK_COLOR;
	DriveSTD_noData.frameColor = PAGE_BACK_COLOR;

	DriveSTD_noData.dataType = DataLog_DataType_Float;
	DriveSTD_noData.signEnable = SIGN_NEGATIVE;

	DriveSTD_noData.valueControlEnable = DISABLE;
	DriveSTD_noData.maxValue = 0;
	DriveSTD_noData.minValue = 0;
	DriveSTD_noData.millisValueOver = millis;
	DriveSTD_noData.minTimeValueOver = DEFAULT_MIN_TIME_VALUE_OVER;

	DriveSTD_noData.dataRefreshDelay = 500;
	DriveSTD_noData.dataRefreshMillis = 0;

	DriveSTD_noData.receivedDataControlEnable = DISABLE;
	DriveSTD_noData.lastTimeData = (uint32_t*)(&defaultDataPointed);
	DriveSTD_noData.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_noData.blinkingMillis = 0;
	DriveSTD_noData.blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
	DriveSTD_noData.blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;
	DriveSTD_noData.blinkingStatus = 0;
	DriveSTD_noData.blinkingState = 0;

	DriveSTD_noData.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_noData.blinkingFrameEnable = DISABLE;
	DriveSTD_noData.blinkingBackEnable = DISABLE;
	DriveSTD_noData.blinkingOverColor = GUI_RED;
	DriveSTD_noData.blinkingUnderColor = GUI_RED;

	DriveSTD_noData.lastExeTime = 0;




	DriveSTD_waterTemp.enable = ENABLE;

	DriveSTD_waterTemp.string = "Water T";
	DriveSTD_waterTemp.intStr = "";
	DriveSTD_waterTemp.endStr = "";

	DriveSTD_waterTemp.dataPointer = &CAR_Data.waterTemp.floatData;
	DriveSTD_waterTemp.dataLogInt.number = 123;
	DriveSTD_waterTemp.dataLogFloat.number = 0.7;
	DriveSTD_waterTemp.decimalDigits = 1;

	DriveSTD_waterTemp.textColor = PAGE_TEXT_COLOR;
	DriveSTD_waterTemp.dataColor = PAGE_DATA_COLOR;
	DriveSTD_waterTemp.backColor = PAGE_BACK_COLOR;
	DriveSTD_waterTemp.frameColor = PAGE_BACK_COLOR;

	DriveSTD_waterTemp.dataType = DataLog_DataType_Float;
	DriveSTD_waterTemp.signEnable = SIGN_NEGATIVE;

	DriveSTD_waterTemp.valueControlEnable = ENABLE;
	DriveSTD_waterTemp.maxValue = CAR_Data.waterTemp.maxValue;
	DriveSTD_waterTemp.minValue = CAR_Data.waterTemp.minValue;
	DriveSTD_waterTemp.millisValueOver = millis;
	DriveSTD_waterTemp.minTimeValueOver = DEFAULT_MIN_TIME_VALUE_OVER;

	DriveSTD_waterTemp.dataRefreshDelay = 500;
	DriveSTD_waterTemp.dataRefreshMillis = 0;

	DriveSTD_waterTemp.receivedDataControlEnable = ENABLE;
	DriveSTD_waterTemp.lastTimeData = &CAR_Data.waterTemp.lastTimeData;
	DriveSTD_waterTemp.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_waterTemp.blinkingMillis = 0;
	DriveSTD_waterTemp.blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
	DriveSTD_waterTemp.blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;
	DriveSTD_waterTemp.blinkingStatus = 0;
	DriveSTD_waterTemp.blinkingState = 0;

	DriveSTD_waterTemp.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_waterTemp.blinkingFrameEnable = ENABLE;
	DriveSTD_waterTemp.blinkingBackEnable = ENABLE;
	DriveSTD_waterTemp.blinkingOverColor = GUI_RED;
	DriveSTD_waterTemp.blinkingUnderColor = GUI_BLUE;

	DriveSTD_waterTemp.lastExeTime = 0;



	DriveSTD_oilTemp.enable = ENABLE;

	DriveSTD_oilTemp.string = "Oil T";
	DriveSTD_oilTemp.intStr = "";
	DriveSTD_oilTemp.endStr = "";

	DriveSTD_oilTemp.dataPointer = &CAR_Data.oilTemp.floatData;
	DriveSTD_oilTemp.dataLogInt.number = 123;
	DriveSTD_oilTemp.dataLogFloat.number = 0.7;
	DriveSTD_oilTemp.decimalDigits = 1;

	DriveSTD_oilTemp.textColor = PAGE_TEXT_COLOR;
	DriveSTD_oilTemp.dataColor = PAGE_DATA_COLOR;
	DriveSTD_oilTemp.backColor = PAGE_BACK_COLOR;
	DriveSTD_oilTemp.frameColor = PAGE_BACK_COLOR;

	DriveSTD_oilTemp.dataType = DataLog_DataType_Float;
	DriveSTD_oilTemp.signEnable = SIGN_NEGATIVE;

	DriveSTD_oilTemp.valueControlEnable = ENABLE;
	DriveSTD_oilTemp.maxValue = CAR_Data.oilTemp.maxValue;
	DriveSTD_oilTemp.minValue = CAR_Data.oilTemp.minValue;
	DriveSTD_oilTemp.millisValueOver = millis;
	DriveSTD_oilTemp.minTimeValueOver = DEFAULT_MIN_TIME_VALUE_OVER;

	DriveSTD_oilTemp.dataRefreshDelay = 500;
	DriveSTD_oilTemp.dataRefreshMillis = 0;

	DriveSTD_oilTemp.receivedDataControlEnable = ENABLE;
	DriveSTD_oilTemp.lastTimeData = &CAR_Data.oilTemp.lastTimeData;
	DriveSTD_oilTemp.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_oilTemp.blinkingMillis = 0;
	DriveSTD_oilTemp.blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
	DriveSTD_oilTemp.blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;
	DriveSTD_oilTemp.blinkingStatus = 0;
	DriveSTD_oilTemp.blinkingState = 0;

	DriveSTD_oilTemp.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_oilTemp.blinkingFrameEnable = ENABLE;
	DriveSTD_oilTemp.blinkingBackEnable = ENABLE;
	DriveSTD_oilTemp.blinkingOverColor = GUI_RED;
	DriveSTD_oilTemp.blinkingUnderColor = GUI_BLUE;

	DriveSTD_oilTemp.lastExeTime = 0;




	DriveSTD_fuelTemp.enable = ENABLE;

	DriveSTD_fuelTemp.string = "Fuel T";
	DriveSTD_fuelTemp.intStr = "";
	DriveSTD_fuelTemp.endStr = "";

	DriveSTD_fuelTemp.dataPointer = &CAR_Data.fuelTemp.floatData;
	DriveSTD_fuelTemp.dataLogInt.number = 123;
	DriveSTD_fuelTemp.dataLogFloat.number = 0.7;
	DriveSTD_fuelTemp.decimalDigits = 1;

	DriveSTD_fuelTemp.textColor = PAGE_TEXT_COLOR;
	DriveSTD_fuelTemp.dataColor = PAGE_DATA_COLOR;
	DriveSTD_fuelTemp.backColor = PAGE_BACK_COLOR;
	DriveSTD_fuelTemp.frameColor = PAGE_BACK_COLOR;

	DriveSTD_fuelTemp.dataType = DataLog_DataType_Float;
	DriveSTD_fuelTemp.signEnable = SIGN_NEGATIVE;

	DriveSTD_fuelTemp.valueControlEnable = ENABLE;
	DriveSTD_fuelTemp.maxValue = CAR_Data.fuelTemp.maxValue;
	DriveSTD_fuelTemp.minValue = CAR_Data.fuelTemp.minValue;
	DriveSTD_fuelTemp.millisValueOver = millis;
	DriveSTD_fuelTemp.minTimeValueOver = DEFAULT_MIN_TIME_VALUE_OVER;

	DriveSTD_fuelTemp.dataRefreshDelay = 500;
	DriveSTD_fuelTemp.dataRefreshMillis = 0;

	DriveSTD_fuelTemp.receivedDataControlEnable = ENABLE;
	DriveSTD_fuelTemp.lastTimeData = &CAR_Data.fuelTemp.lastTimeData;
	DriveSTD_fuelTemp.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_fuelTemp.blinkingMillis = 0;
	DriveSTD_fuelTemp.blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
	DriveSTD_fuelTemp.blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;
	DriveSTD_fuelTemp.blinkingStatus = 0;
	DriveSTD_fuelTemp.blinkingState = 0;

	DriveSTD_fuelTemp.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_fuelTemp.blinkingFrameEnable = ENABLE;
	DriveSTD_fuelTemp.blinkingBackEnable = ENABLE;
	DriveSTD_fuelTemp.blinkingOverColor = GUI_RED;
	DriveSTD_fuelTemp.blinkingUnderColor = GUI_BLUE;

	DriveSTD_fuelTemp.lastExeTime = 0;




	DriveSTD_airTemp.enable = ENABLE;

	DriveSTD_airTemp.string = "Air T";
	DriveSTD_airTemp.intStr = "";
	DriveSTD_airTemp.endStr = "";

	DriveSTD_airTemp.dataPointer = &CAR_Data.airTemp.floatData;
	DriveSTD_airTemp.dataLogInt.number = 123;
	DriveSTD_airTemp.dataLogFloat.number = 0.7;
	DriveSTD_airTemp.decimalDigits = 1;

	DriveSTD_airTemp.textColor = PAGE_TEXT_COLOR;
	DriveSTD_airTemp.dataColor = PAGE_DATA_COLOR;
	DriveSTD_airTemp.backColor = PAGE_BACK_COLOR;
	DriveSTD_airTemp.frameColor = PAGE_BACK_COLOR;

	DriveSTD_airTemp.dataType = DataLog_DataType_Float;
	DriveSTD_airTemp.signEnable = SIGN_NEGATIVE;

	DriveSTD_airTemp.valueControlEnable = ENABLE;
	DriveSTD_airTemp.maxValue = tAir_MAX_VALUE;
	DriveSTD_airTemp.minValue = tAir_MIN_VALUE;
	DriveSTD_airTemp.millisValueOver = millis;
	//DriveSTD_airTemp.minTimeValueOver = DEFAULT_MIN_TIME_VALUE_OVER;
	DriveSTD_airTemp.minTimeValueOver = 100;

	DriveSTD_airTemp.dataRefreshDelay = 500;
	DriveSTD_airTemp.dataRefreshMillis = 0;

	DriveSTD_airTemp.receivedDataControlEnable = ENABLE;
	DriveSTD_airTemp.lastTimeData = &CAR_Data.airTemp.lastTimeData;
	DriveSTD_airTemp.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_airTemp.blinkingMillis = 0;
	DriveSTD_airTemp.blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
	DriveSTD_airTemp.blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;
	DriveSTD_airTemp.blinkingStatus = 0;
	DriveSTD_airTemp.blinkingState = 0;

	DriveSTD_airTemp.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_airTemp.blinkingFrameEnable = ENABLE;
	DriveSTD_airTemp.blinkingBackEnable = ENABLE;
	DriveSTD_airTemp.blinkingOverColor = GUI_RED;
	DriveSTD_airTemp.blinkingUnderColor = GUI_BLUE;

	DriveSTD_airTemp.lastExeTime = 0;




	DriveSTD_fuelPressure.enable = ENABLE;

	DriveSTD_fuelPressure.string = "Fuel P";
	DriveSTD_fuelPressure.intStr = " ";
	DriveSTD_fuelPressure.endStr = "";

	DriveSTD_fuelPressure.dataPointer = &CAR_Data.fuelPressure.floatData;
	DriveSTD_fuelPressure.dataLogInt.number = 123;
	DriveSTD_fuelPressure.dataLogFloat.number = 0.7;
	DriveSTD_fuelPressure.decimalDigits = 1;

	DriveSTD_fuelPressure.textColor = PAGE_TEXT_COLOR;
	DriveSTD_fuelPressure.dataColor = PAGE_DATA_COLOR;
	DriveSTD_fuelPressure.backColor = PAGE_BACK_COLOR;
	DriveSTD_fuelPressure.frameColor = PAGE_BACK_COLOR;

	DriveSTD_fuelPressure.dataType = DataLog_DataType_Float;
	DriveSTD_fuelPressure.signEnable = SIGN_NEGATIVE;

	DriveSTD_fuelPressure.valueControlEnable = ENABLE;
	DriveSTD_fuelPressure.maxValue = pFuel_MAX_VALUE;
	DriveSTD_fuelPressure.minValue = pFuel_MIN_VALUE;
	DriveSTD_fuelPressure.millisValueOver = millis;
	DriveSTD_fuelPressure.minTimeValueOver = DEFAULT_MIN_TIME_VALUE_OVER;

	DriveSTD_fuelPressure.dataRefreshDelay = 100;
	DriveSTD_fuelPressure.dataRefreshMillis = 0;

	DriveSTD_fuelPressure.receivedDataControlEnable = ENABLE;
	DriveSTD_fuelPressure.lastTimeData = &CAR_Data.fuelPressure.lastTimeData;
	DriveSTD_fuelPressure.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_fuelPressure.blinkingMillis = 0;
	DriveSTD_fuelPressure.blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
	DriveSTD_fuelPressure.blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;
	DriveSTD_fuelPressure.blinkingStatus = 0;
	DriveSTD_fuelPressure.blinkingState = 0;

	DriveSTD_fuelPressure.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_fuelPressure.blinkingFrameEnable = ENABLE;
	DriveSTD_fuelPressure.blinkingBackEnable = ENABLE;
	DriveSTD_fuelPressure.blinkingOverColor = GUI_RED;
	DriveSTD_fuelPressure.blinkingUnderColor = GUI_RED;

	DriveSTD_fuelPressure.lastExeTime = 0;


	DriveSTD_oilPressure.enable = ENABLE;

	DriveSTD_oilPressure.string = "Oil P";
	DriveSTD_oilPressure.intStr = "";
	DriveSTD_oilPressure.endStr = "";

	//DriveSTD_oilPressure.dataPointer = &pOil;
	DriveSTD_oilPressure.dataPointer = &CAR_Data.oilPressure.floatData;
	DriveSTD_oilPressure.dataLogInt.number = 123;
	DriveSTD_oilPressure.dataLogFloat.number = 0.7;
	DriveSTD_oilPressure.decimalDigits = 1;

	DriveSTD_oilPressure.textColor = PAGE_TEXT_COLOR;
	DriveSTD_oilPressure.dataColor = PAGE_DATA_COLOR;
	DriveSTD_oilPressure.backColor = PAGE_BACK_COLOR;
	DriveSTD_oilPressure.frameColor = PAGE_BACK_COLOR;

	DriveSTD_oilPressure.dataType = DataLog_DataType_Float;
	DriveSTD_oilPressure.signEnable = SIGN_NEGATIVE;

	DriveSTD_oilPressure.valueControlEnable = ENABLE;
	DriveSTD_oilPressure.maxValue = pOil_MAX_VALUE;
	DriveSTD_oilPressure.minValue = pOil_MIN_VALUE;
	DriveSTD_oilPressure.millisValueOver = millis;
	DriveSTD_oilPressure.minTimeValueOver = DEFAULT_MIN_TIME_VALUE_OVER;

	DriveSTD_oilPressure.dataRefreshDelay = 100;
	DriveSTD_oilPressure.dataRefreshMillis = 0;

	DriveSTD_oilPressure.receivedDataControlEnable = ENABLE;
	DriveSTD_oilPressure.lastTimeData = &CAR_Data.oilPressure.lastTimeData;
	DriveSTD_oilPressure.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_oilPressure.blinkingMillis = 0;
	DriveSTD_oilPressure.blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
	DriveSTD_oilPressure.blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;
	DriveSTD_oilPressure.blinkingStatus = 0;
	DriveSTD_oilPressure.blinkingState = 0;

	DriveSTD_oilPressure.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_oilPressure.blinkingFrameEnable = ENABLE;
	DriveSTD_oilPressure.blinkingBackEnable = ENABLE;
	DriveSTD_oilPressure.blinkingOverColor = GUI_RED;
	DriveSTD_oilPressure.blinkingUnderColor = GUI_RED;

	DriveSTD_oilPressure.lastExeTime = 0;




	DriveSTD_batteryVoltage.enable = ENABLE;

	DriveSTD_batteryVoltage.string = "Bat V";
	DriveSTD_batteryVoltage.intStr = "";
	DriveSTD_batteryVoltage.endStr = "";

	DriveSTD_batteryVoltage.dataPointer = &CAR_Data.batteryVoltage.floatData;
	DriveSTD_batteryVoltage.dataLogInt.number = 123;
	DriveSTD_batteryVoltage.dataLogFloat.number = 0.7;
	DriveSTD_batteryVoltage.decimalDigits = 1;

	DriveSTD_batteryVoltage.textColor = PAGE_TEXT_COLOR;
	DriveSTD_batteryVoltage.dataColor = PAGE_DATA_COLOR;
	DriveSTD_batteryVoltage.backColor = PAGE_BACK_COLOR;
	DriveSTD_batteryVoltage.frameColor = PAGE_BACK_COLOR;

	DriveSTD_batteryVoltage.dataType = DataLog_DataType_Float;
	DriveSTD_batteryVoltage.signEnable = SIGN_NEGATIVE;

	DriveSTD_batteryVoltage.valueControlEnable = ENABLE;
	DriveSTD_batteryVoltage.maxValue = vBat_MAX_VALUE;
	DriveSTD_batteryVoltage.minValue = vBat_MIN_VALUE;
	DriveSTD_batteryVoltage.millisValueOver = millis;
	DriveSTD_batteryVoltage.minTimeValueOver = DEFAULT_MIN_TIME_VALUE_OVER;

	DriveSTD_batteryVoltage.dataRefreshDelay = 100;
	DriveSTD_batteryVoltage.dataRefreshMillis = 0;

	DriveSTD_batteryVoltage.receivedDataControlEnable = ENABLE;
	DriveSTD_batteryVoltage.lastTimeData = &CAR_Data.batteryVoltage.lastTimeData;
	DriveSTD_batteryVoltage.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_batteryVoltage.blinkingMillis = 0;
	DriveSTD_batteryVoltage.blinkingDelayOver = NO_BLINK_DELAY;
	DriveSTD_batteryVoltage.blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;
	DriveSTD_batteryVoltage.blinkingStatus = 0;
	DriveSTD_batteryVoltage.blinkingState = 0;

	DriveSTD_batteryVoltage.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_batteryVoltage.blinkingFrameEnable = ENABLE;
	DriveSTD_batteryVoltage.blinkingBackEnable = ENABLE;
	DriveSTD_batteryVoltage.blinkingOverColor = GUI_GREEN;
	DriveSTD_batteryVoltage.blinkingUnderColor = GUI_RED;

	DriveSTD_batteryVoltage.lastExeTime = 0;




	DriveSTD_tps.enable = ENABLE;

	DriveSTD_tps.string = "TPS";
	DriveSTD_tps.intStr = "";
	DriveSTD_tps.endStr = "";

	DriveSTD_tps.dataPointer = &CAR_Data.tps.intData;
	DriveSTD_tps.dataLogInt.number = 123;
	DriveSTD_tps.dataLogFloat.number = 0.7;
	DriveSTD_tps.decimalDigits = 1;

	DriveSTD_tps.textColor = PAGE_TEXT_COLOR;
	DriveSTD_tps.dataColor = PAGE_DATA_COLOR;
	DriveSTD_tps.backColor = PAGE_BACK_COLOR;
	DriveSTD_tps.frameColor = PAGE_BACK_COLOR;

	DriveSTD_tps.dataType = DataLog_DataType_Int;
	DriveSTD_tps.signEnable = DISABLE;

	DriveSTD_tps.valueControlEnable = DISABLE;
	DriveSTD_tps.maxValue = 100;
	DriveSTD_tps.minValue = 8;
	DriveSTD_tps.millisValueOver = millis;
	DriveSTD_tps.minTimeValueOver = 100;

	DriveSTD_tps.dataRefreshDelay = 0;
	DriveSTD_tps.dataRefreshMillis = 0;

	DriveSTD_tps.receivedDataControlEnable = ENABLE;
	DriveSTD_tps.lastTimeData = &CAR_Data.tps.lastTimeData;
	DriveSTD_tps.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_tps.blinkingMillis = 0;
	DriveSTD_tps.blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
	DriveSTD_tps.blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;
	DriveSTD_tps.blinkingStatus = 0;
	DriveSTD_tps.blinkingState = 0;

	DriveSTD_tps.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_tps.blinkingFrameEnable = ENABLE;
	DriveSTD_tps.blinkingBackEnable = ENABLE;
	DriveSTD_tps.blinkingOverColor = GUI_RED;
	DriveSTD_tps.blinkingUnderColor = GUI_RED;

	DriveSTD_tps.lastExeTime = 0;




	DriveSTD_speed.enable = ENABLE;

	DriveSTD_speed.string = "Speed";
	DriveSTD_speed.intStr = "";
	DriveSTD_speed.endStr = "";

	DriveSTD_speed.dataPointer = &CAR_Data.speed.floatData;
	DriveSTD_speed.dataLogInt.number = 123;
	DriveSTD_speed.dataLogFloat.number = 0.7;
	DriveSTD_speed.decimalDigits = 0;

	DriveSTD_speed.textColor = PAGE_TEXT_COLOR;
	DriveSTD_speed.dataColor = PAGE_DATA_COLOR;
	DriveSTD_speed.backColor = PAGE_BACK_COLOR;
	DriveSTD_speed.frameColor = PAGE_BACK_COLOR;

	DriveSTD_speed.dataType = DataLog_DataType_Float;
	DriveSTD_speed.signEnable = SIGN_NEGATIVE;

	DriveSTD_speed.valueControlEnable = DISABLE;
	DriveSTD_speed.maxValue = 0;
	DriveSTD_speed.minValue = 0;
	DriveSTD_speed.millisValueOver = millis;
	DriveSTD_speed.minTimeValueOver = DEFAULT_MIN_TIME_VALUE_OVER;

	DriveSTD_speed.dataRefreshDelay = 0;
	DriveSTD_speed.dataRefreshMillis = 0;

	DriveSTD_speed.receivedDataControlEnable = ENABLE;
	DriveSTD_speed.lastTimeData = &CAR_Data.speed.lastTimeData;
	DriveSTD_speed.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_speed.blinkingMillis = 0;
	DriveSTD_speed.blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
	DriveSTD_speed.blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;
	DriveSTD_speed.blinkingStatus = 0;
	DriveSTD_speed.blinkingState = 0;

	DriveSTD_speed.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_speed.blinkingFrameEnable = DISABLE;
	DriveSTD_speed.blinkingBackEnable = DISABLE;
	DriveSTD_speed.blinkingOverColor = GUI_RED;
	DriveSTD_speed.blinkingUnderColor = GUI_RED;

	DriveSTD_speed.lastExeTime = 0;




	DriveSTD_traction.enable = ENABLE;

	DriveSTD_traction.string = "Traction";
	DriveSTD_traction.intStr = "";
	DriveSTD_traction.endStr = "";

	DriveSTD_traction.dataPointer = &CAR_Data.tractionControl.intData;
	DriveSTD_traction.dataLogInt.number = 123;
	DriveSTD_traction.dataLogFloat.number = 0.7;
	DriveSTD_traction.decimalDigits = 1;

	DriveSTD_traction.textColor = PAGE_TEXT_COLOR;
	DriveSTD_traction.dataColor = PAGE_DATA_COLOR;
	DriveSTD_traction.backColor = PAGE_BACK_COLOR;
	DriveSTD_traction.frameColor = PAGE_BACK_COLOR;

	DriveSTD_traction.dataType = DataLog_DataType_Int;
	DriveSTD_traction.signEnable = DISABLE;

	DriveSTD_traction.valueControlEnable = DISABLE;
	DriveSTD_traction.maxValue = 0;
	DriveSTD_traction.minValue = 0;
	DriveSTD_traction.millisValueOver = millis;
	DriveSTD_traction.minTimeValueOver = DEFAULT_MIN_TIME_VALUE_OVER;

	DriveSTD_traction.dataRefreshDelay = 0;
	DriveSTD_traction.dataRefreshMillis = 0;

	DriveSTD_traction.receivedDataControlEnable = DISABLE;
	//DriveSTD_traction.lastTimeData = &;
	DriveSTD_traction.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_traction.blinkingMillis = 0;
	DriveSTD_traction.blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
	DriveSTD_traction.blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;
	DriveSTD_traction.blinkingStatus = 0;
	DriveSTD_traction.blinkingState = 0;

	DriveSTD_traction.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_traction.blinkingFrameEnable = DISABLE;
	DriveSTD_traction.blinkingBackEnable = DISABLE;
	DriveSTD_traction.blinkingOverColor = GUI_RED;
	DriveSTD_traction.blinkingUnderColor = GUI_RED;

	DriveSTD_traction.lastExeTime = 0;




	DriveSTD_map.enable = ENABLE;

	DriveSTD_map.string = "MAP";
	DriveSTD_map.intStr = "";
	DriveSTD_map.endStr = "";

	//DriveSTD_map.dataPointer = &map_pp;
	DriveSTD_map.dataPointer = &CAR_Data.map.intData;
	DriveSTD_map.dataLogInt.number = 123;
	DriveSTD_map.dataLogFloat.number = 0.7;
	DriveSTD_map.decimalDigits = 1;

	DriveSTD_map.textColor = PAGE_TEXT_COLOR;
	DriveSTD_map.dataColor = PAGE_DATA_COLOR;
	DriveSTD_map.backColor = PAGE_BACK_COLOR;
	DriveSTD_map.frameColor = PAGE_BACK_COLOR;

	DriveSTD_map.dataType = DataLog_DataType_Int;
	DriveSTD_map.signEnable = DISABLE;

	DriveSTD_map.valueControlEnable = DISABLE;
	DriveSTD_map.maxValue = 0;
	DriveSTD_map.minValue = 0;
	DriveSTD_map.millisValueOver = millis;
	DriveSTD_map.minTimeValueOver = DEFAULT_MIN_TIME_VALUE_OVER;

	DriveSTD_map.dataRefreshDelay = 0;
	DriveSTD_map.dataRefreshMillis = 0;

	DriveSTD_map.receivedDataControlEnable = DISABLE;
	//DriveSTD_map.lastTimeData = &;
	DriveSTD_map.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_map.blinkingMillis = 0;
	DriveSTD_map.blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
	DriveSTD_map.blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;
	DriveSTD_map.blinkingStatus = 0;
	DriveSTD_map.blinkingState = 0;

	DriveSTD_map.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_map.blinkingFrameEnable = DISABLE;
	DriveSTD_map.blinkingBackEnable = DISABLE;
	DriveSTD_map.blinkingOverColor = GUI_RED;
	DriveSTD_map.blinkingUnderColor = GUI_RED;

	DriveSTD_map.lastExeTime = 0;




	DriveSTD_drsStatus.enable = ENABLE;

	DriveSTD_drsStatus.string = "DRS";
	DriveSTD_drsStatus.intStr = "";
	DriveSTD_drsStatus.endStr = "";

	DriveSTD_drsStatus.dataPointer = &CAR_Data.drsStatus.intData;
	DriveSTD_drsStatus.dataLogInt.number = 123;
	DriveSTD_drsStatus.dataLogFloat.number = 0.7;
	DriveSTD_drsStatus.decimalDigits = 1;

	DriveSTD_drsStatus.textColor = PAGE_TEXT_COLOR;
	DriveSTD_drsStatus.dataColor = PAGE_DATA_COLOR;
	DriveSTD_drsStatus.backColor = PAGE_BACK_COLOR;
	DriveSTD_drsStatus.frameColor = PAGE_BACK_COLOR;

	DriveSTD_drsStatus.dataType = DataLog_DataType_Int;
	DriveSTD_drsStatus.signEnable = DISABLE;

	DriveSTD_drsStatus.valueControlEnable = ENABLE;
	DriveSTD_drsStatus.maxValue = drsStatus_max;
	DriveSTD_drsStatus.minValue = drsStatus_min;
	DriveSTD_drsStatus.millisValueOver = millis;
	DriveSTD_drsStatus.minTimeValueOver = 100;

	DriveSTD_drsStatus.dataRefreshDelay = 0;
	DriveSTD_drsStatus.dataRefreshMillis = 0;

	DriveSTD_drsStatus.receivedDataControlEnable = ENABLE;
	DriveSTD_drsStatus.lastTimeData = &CAR_Data.drsStatus.lastTimeData;
	DriveSTD_drsStatus.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_drsStatus.blinkingMillis = 0;
	DriveSTD_drsStatus.blinkingDelayOver = NO_BLINK_DELAY;
	DriveSTD_drsStatus.blinkingDelayUnder = NO_BLINK_DELAY;
	DriveSTD_drsStatus.blinkingStatus = 0;
	DriveSTD_drsStatus.blinkingState = 0;

	DriveSTD_drsStatus.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_drsStatus.blinkingFrameEnable = ENABLE;
	DriveSTD_drsStatus.blinkingBackEnable = ENABLE;
	DriveSTD_drsStatus.blinkingOverColor = GUI_GREEN;
	DriveSTD_drsStatus.blinkingUnderColor = GUI_RED;

	DriveSTD_drsStatus.lastExeTime = 0;




	DriveSTD_brakeBias.enable = ENABLE;

	DriveSTD_brakeBias.string = "Brake Bal";
	DriveSTD_brakeBias.intStr = "";
	DriveSTD_brakeBias.endStr = " %";

	DriveSTD_brakeBias.dataPointer = &CAR_Data.brakeBias.floatData;
	DriveSTD_brakeBias.dataLogInt.number = 123;
	DriveSTD_brakeBias.dataLogFloat.number = 0.7;
	DriveSTD_brakeBias.decimalDigits = 0;

	DriveSTD_brakeBias.textColor = PAGE_TEXT_COLOR;
	DriveSTD_brakeBias.dataColor = PAGE_DATA_COLOR;
	DriveSTD_brakeBias.backColor = PAGE_BACK_COLOR;
	DriveSTD_brakeBias.frameColor = PAGE_BACK_COLOR;

	DriveSTD_brakeBias.dataType = DataLog_DataType_Float;
	DriveSTD_brakeBias.signEnable = DISABLE;

	DriveSTD_brakeBias.valueControlEnable = DISABLE;
	DriveSTD_brakeBias.maxValue = 0;
	DriveSTD_brakeBias.minValue = 0;
	DriveSTD_brakeBias.millisValueOver = millis;
	DriveSTD_brakeBias.minTimeValueOver = DEFAULT_MIN_TIME_VALUE_OVER;

	DriveSTD_brakeBias.dataRefreshDelay = 0;
	DriveSTD_brakeBias.dataRefreshMillis = 0;

	DriveSTD_brakeBias.receivedDataControlEnable = ENABLE;
	DriveSTD_brakeBias.lastTimeData = &CAR_Data.brakeBias.lastTimeData;
	DriveSTD_brakeBias.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_brakeBias.blinkingMillis = 0;
	DriveSTD_brakeBias.blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
	DriveSTD_brakeBias.blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;
	DriveSTD_brakeBias.blinkingStatus = 0;
	DriveSTD_brakeBias.blinkingState = 0;

	DriveSTD_brakeBias.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_brakeBias.blinkingFrameEnable = DISABLE;
	DriveSTD_brakeBias.blinkingBackEnable = DISABLE;
	DriveSTD_brakeBias.blinkingOverColor = GUI_RED;
	DriveSTD_brakeBias.blinkingUnderColor = GUI_RED;

	DriveSTD_brakeBias.lastExeTime = 0;




	DriveSTD_brake.enable = ENABLE;

	DriveSTD_brake.string = "Brake PF";
	DriveSTD_brake.intStr = "";
	DriveSTD_brake.endStr = "";

	DriveSTD_brake.dataPointer = &CAR_Data.brake.intData;
	DriveSTD_brake.dataLogInt.number = 123;
	DriveSTD_brake.dataLogFloat.number = 0.7;
	DriveSTD_brake.decimalDigits = 0;

	DriveSTD_brake.textColor = PAGE_TEXT_COLOR;
	DriveSTD_brake.dataColor = PAGE_DATA_COLOR;
	DriveSTD_brake.backColor = PAGE_BACK_COLOR;
	DriveSTD_brake.frameColor = PAGE_BACK_COLOR;

	DriveSTD_brake.dataType = DataLog_DataType_Int;
	DriveSTD_brake.signEnable = SIGN_NEGATIVE;

	DriveSTD_brake.valueControlEnable = DISABLE;
	DriveSTD_brake.maxValue = 0;
	DriveSTD_brake.minValue = 0;
	DriveSTD_brake.millisValueOver = millis;
	DriveSTD_brake.minTimeValueOver = DEFAULT_MIN_TIME_VALUE_OVER;

	DriveSTD_brake.dataRefreshDelay = 0;
	DriveSTD_brake.dataRefreshMillis = 0;

	DriveSTD_brake.receivedDataControlEnable = ENABLE;
	DriveSTD_brake.lastTimeData = &CAR_Data.brake.lastTimeData;
	DriveSTD_brake.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_brake.blinkingMillis = 0;
	DriveSTD_brake.blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
	DriveSTD_brake.blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;
	DriveSTD_brake.blinkingStatus = 0;
	DriveSTD_brake.blinkingState = 0;

	DriveSTD_brake.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_brake.blinkingFrameEnable = ENABLE;
	DriveSTD_brake.blinkingBackEnable = ENABLE;
	DriveSTD_brake.blinkingOverColor = GUI_RED;
	DriveSTD_brake.blinkingUnderColor = GUI_RED;

	DriveSTD_brake.lastExeTime = 0;




	DriveSTD_brakeRear.enable = ENABLE;

	DriveSTD_brakeRear.string = "Brake PR";
	DriveSTD_brakeRear.intStr = "";
	DriveSTD_brakeRear.endStr = "";

	DriveSTD_brakeRear.dataPointer = &CAR_Data.brakeRear.intData;
	DriveSTD_brakeRear.dataLogInt.number = 123;
	DriveSTD_brakeRear.dataLogFloat.number = 0.7;
	DriveSTD_brakeRear.decimalDigits = 0;

	DriveSTD_brakeRear.textColor = PAGE_TEXT_COLOR;
	DriveSTD_brakeRear.dataColor = PAGE_DATA_COLOR;
	DriveSTD_brakeRear.backColor = PAGE_BACK_COLOR;
	DriveSTD_brakeRear.frameColor = PAGE_BACK_COLOR;

	DriveSTD_brakeRear.dataType = DataLog_DataType_Int;
	DriveSTD_brakeRear.signEnable = SIGN_NEGATIVE;

	DriveSTD_brakeRear.valueControlEnable = DISABLE;
	DriveSTD_brakeRear.maxValue = 0;
	DriveSTD_brakeRear.minValue = 0;
	DriveSTD_brakeRear.millisValueOver = millis;
	DriveSTD_brakeRear.minTimeValueOver = DEFAULT_MIN_TIME_VALUE_OVER;

	DriveSTD_brakeRear.dataRefreshDelay = 0;
	DriveSTD_brakeRear.dataRefreshMillis = 0;

	DriveSTD_brakeRear.receivedDataControlEnable = ENABLE;
	DriveSTD_brakeRear.lastTimeData = &CAR_Data.brake.lastTimeData;
	DriveSTD_brakeRear.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_brakeRear.blinkingMillis = 0;
	DriveSTD_brakeRear.blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
	DriveSTD_brakeRear.blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;
	DriveSTD_brakeRear.blinkingStatus = 0;
	DriveSTD_brakeRear.blinkingState = 0;

	DriveSTD_brakeRear.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_brakeRear.blinkingFrameEnable = ENABLE;
	DriveSTD_brakeRear.blinkingBackEnable = ENABLE;
	DriveSTD_brakeRear.blinkingOverColor = GUI_RED;
	DriveSTD_brakeRear.blinkingUnderColor = GUI_RED;

	DriveSTD_brakeRear.lastExeTime = 0;





	DriveSTD_RL_Ty_Temp.enable = ENABLE;

	DriveSTD_RL_Ty_Temp.string = "RL Ty T";
	DriveSTD_RL_Ty_Temp.intStr = "";
	DriveSTD_RL_Ty_Temp.endStr = "";

	DriveSTD_RL_Ty_Temp.dataPointer = &CAR_Data.tyresTemp[RL].floatData;
	DriveSTD_RL_Ty_Temp.dataLogInt.number = 123;
	DriveSTD_RL_Ty_Temp.dataLogFloat.number = 0.7;
	DriveSTD_RL_Ty_Temp.decimalDigits = 1;

	DriveSTD_RL_Ty_Temp.textColor = PAGE_TEXT_COLOR;
	DriveSTD_RL_Ty_Temp.dataColor = PAGE_DATA_COLOR;
	DriveSTD_RL_Ty_Temp.backColor = PAGE_BACK_COLOR;
	DriveSTD_RL_Ty_Temp.frameColor = PAGE_BACK_COLOR;

	DriveSTD_RL_Ty_Temp.dataType = DataLog_DataType_Float;
	DriveSTD_RL_Ty_Temp.signEnable = DISABLE;

	DriveSTD_RL_Ty_Temp.valueControlEnable = DISABLE;
	DriveSTD_RL_Ty_Temp.maxValue = 0;
	DriveSTD_RL_Ty_Temp.minValue = 0;
	DriveSTD_RL_Ty_Temp.millisValueOver = millis;
	DriveSTD_RL_Ty_Temp.minTimeValueOver = DEFAULT_MIN_TIME_VALUE_OVER;

	DriveSTD_RL_Ty_Temp.dataRefreshDelay = 0;
	DriveSTD_RL_Ty_Temp.dataRefreshMillis = 0;

	DriveSTD_RL_Ty_Temp.receivedDataControlEnable = ENABLE;
	DriveSTD_RL_Ty_Temp.lastTimeData = &CAR_Data.tyresTemp[RL].lastTimeData;
	DriveSTD_RL_Ty_Temp.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_RL_Ty_Temp.blinkingMillis = 0;
	DriveSTD_RL_Ty_Temp.blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
	DriveSTD_RL_Ty_Temp.blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;
	DriveSTD_RL_Ty_Temp.blinkingStatus = 0;
	DriveSTD_RL_Ty_Temp.blinkingState = 0;

	DriveSTD_RL_Ty_Temp.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_RL_Ty_Temp.blinkingFrameEnable = 1;
	DriveSTD_RL_Ty_Temp.blinkingBackEnable = 1;
	DriveSTD_RL_Ty_Temp.blinkingOverColor = GUI_RED;
	DriveSTD_RL_Ty_Temp.blinkingUnderColor = GUI_RED;

	DriveSTD_RL_Ty_Temp.lastExeTime = 0;




	DriveSTD_RR_Ty_Temp.enable = ENABLE;

	DriveSTD_RR_Ty_Temp.string = "RR Ty T";
	DriveSTD_RR_Ty_Temp.intStr = "";
	DriveSTD_RR_Ty_Temp.endStr = "";

	DriveSTD_RR_Ty_Temp.dataPointer = &CAR_Data.tyresTemp[RR].floatData;
	DriveSTD_RR_Ty_Temp.dataLogInt.number = 123;
	DriveSTD_RR_Ty_Temp.dataLogFloat.number = 0.7;
	DriveSTD_RR_Ty_Temp.decimalDigits = 1;

	DriveSTD_RR_Ty_Temp.textColor = PAGE_TEXT_COLOR;
	DriveSTD_RR_Ty_Temp.dataColor = PAGE_DATA_COLOR;
	DriveSTD_RR_Ty_Temp.backColor = PAGE_BACK_COLOR;
	DriveSTD_RR_Ty_Temp.frameColor = PAGE_BACK_COLOR;

	DriveSTD_RR_Ty_Temp.dataType = DataLog_DataType_Float;
	DriveSTD_RR_Ty_Temp.signEnable = DISABLE;

	DriveSTD_RR_Ty_Temp.valueControlEnable = DISABLE;
	DriveSTD_RR_Ty_Temp.maxValue = 0;
	DriveSTD_RR_Ty_Temp.minValue = 0;
	DriveSTD_RR_Ty_Temp.millisValueOver = millis;
	DriveSTD_RR_Ty_Temp.minTimeValueOver = DEFAULT_MIN_TIME_VALUE_OVER;

	DriveSTD_RR_Ty_Temp.dataRefreshDelay = 0;
	DriveSTD_RR_Ty_Temp.dataRefreshMillis = 0;

	DriveSTD_RR_Ty_Temp.receivedDataControlEnable = ENABLE;
	DriveSTD_RR_Ty_Temp.lastTimeData = &CAR_Data.tyresTemp[RR].lastTimeData;
	DriveSTD_RR_Ty_Temp.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_RR_Ty_Temp.blinkingMillis = 0;
	DriveSTD_RR_Ty_Temp.blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
	DriveSTD_RR_Ty_Temp.blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;
	DriveSTD_RR_Ty_Temp.blinkingStatus = 0;
	DriveSTD_RR_Ty_Temp.blinkingState = 0;

	DriveSTD_RR_Ty_Temp.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_RR_Ty_Temp.blinkingFrameEnable = 1;
	DriveSTD_RR_Ty_Temp.blinkingBackEnable = 1;
	DriveSTD_RR_Ty_Temp.blinkingOverColor = GUI_RED;
	DriveSTD_RR_Ty_Temp.blinkingUnderColor = GUI_RED;

	DriveSTD_RR_Ty_Temp.lastExeTime = 0;




	DriveSTD_FL_Ty_Temp.enable = ENABLE;

	DriveSTD_FL_Ty_Temp.string = "FL Ty T";
	DriveSTD_FL_Ty_Temp.intStr = "";
	DriveSTD_FL_Ty_Temp.endStr = "";

	DriveSTD_FL_Ty_Temp.dataPointer = &CAR_Data.tyresTemp[FL].floatData;
	DriveSTD_FL_Ty_Temp.dataLogInt.number = 123;
	DriveSTD_FL_Ty_Temp.dataLogFloat.number = 0.7;
	DriveSTD_FL_Ty_Temp.decimalDigits = 1;

	DriveSTD_FL_Ty_Temp.textColor = PAGE_TEXT_COLOR;
	DriveSTD_FL_Ty_Temp.dataColor = PAGE_DATA_COLOR;
	DriveSTD_FL_Ty_Temp.backColor = PAGE_BACK_COLOR;
	DriveSTD_FL_Ty_Temp.frameColor = PAGE_BACK_COLOR;

	DriveSTD_FL_Ty_Temp.dataType = DataLog_DataType_Float;
	DriveSTD_FL_Ty_Temp.signEnable = DISABLE;

	DriveSTD_FL_Ty_Temp.valueControlEnable = DISABLE;
	DriveSTD_FL_Ty_Temp.maxValue = 0;
	DriveSTD_FL_Ty_Temp.minValue = 0;
	DriveSTD_FL_Ty_Temp.millisValueOver = millis;
	DriveSTD_FL_Ty_Temp.minTimeValueOver = DEFAULT_MIN_TIME_VALUE_OVER;

	DriveSTD_FL_Ty_Temp.dataRefreshDelay = 0;
	DriveSTD_FL_Ty_Temp.dataRefreshMillis = 0;

	DriveSTD_FL_Ty_Temp.receivedDataControlEnable = ENABLE;
	DriveSTD_FL_Ty_Temp.lastTimeData = &CAR_Data.tyresTemp[FL].lastTimeData;
	DriveSTD_FL_Ty_Temp.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_FL_Ty_Temp.blinkingMillis = 0;
	DriveSTD_FL_Ty_Temp.blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
	DriveSTD_FL_Ty_Temp.blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;
	DriveSTD_FL_Ty_Temp.blinkingStatus = 0;
	DriveSTD_FL_Ty_Temp.blinkingState = 0;

	DriveSTD_FL_Ty_Temp.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_FL_Ty_Temp.blinkingFrameEnable = 1;
	DriveSTD_FL_Ty_Temp.blinkingBackEnable = 1;
	DriveSTD_FL_Ty_Temp.blinkingOverColor = GUI_RED;
	DriveSTD_FL_Ty_Temp.blinkingUnderColor = GUI_RED;

	DriveSTD_FL_Ty_Temp.lastExeTime = 0;




	DriveSTD_FR_Ty_Temp.enable = ENABLE;

	DriveSTD_FR_Ty_Temp.string = "FR Ty T";
	DriveSTD_FR_Ty_Temp.intStr = "";
	DriveSTD_FR_Ty_Temp.endStr = "";

	DriveSTD_FR_Ty_Temp.dataPointer = &CAR_Data.tyresTemp[FR].floatData;
	DriveSTD_FR_Ty_Temp.dataLogInt.number = 123;
	DriveSTD_FR_Ty_Temp.dataLogFloat.number = 0.7;
	DriveSTD_FR_Ty_Temp.decimalDigits = 1;

	DriveSTD_FR_Ty_Temp.textColor = PAGE_TEXT_COLOR;
	DriveSTD_FR_Ty_Temp.dataColor = PAGE_DATA_COLOR;
	DriveSTD_FR_Ty_Temp.backColor = PAGE_BACK_COLOR;
	DriveSTD_FR_Ty_Temp.frameColor = PAGE_BACK_COLOR;

	DriveSTD_FR_Ty_Temp.dataType = DataLog_DataType_Float;
	DriveSTD_FR_Ty_Temp.signEnable = DISABLE;

	DriveSTD_FR_Ty_Temp.valueControlEnable = DISABLE;
	DriveSTD_FR_Ty_Temp.maxValue = 0;
	DriveSTD_FR_Ty_Temp.minValue = 0;
	DriveSTD_FR_Ty_Temp.millisValueOver = millis;
	DriveSTD_FR_Ty_Temp.minTimeValueOver = DEFAULT_MIN_TIME_VALUE_OVER;

	DriveSTD_FR_Ty_Temp.dataRefreshDelay = 0;
	DriveSTD_FR_Ty_Temp.dataRefreshMillis = 0;

	DriveSTD_FR_Ty_Temp.receivedDataControlEnable = ENABLE;
	DriveSTD_FR_Ty_Temp.lastTimeData = &CAR_Data.tyresTemp[FR].lastTimeData;
	DriveSTD_FR_Ty_Temp.noDataErrorTimerValue = DEFAULT_NO_DATA_ERROR_DELAY;

	DriveSTD_FR_Ty_Temp.blinkingMillis = 0;
	DriveSTD_FR_Ty_Temp.blinkingDelayOver = NO_BLINK_DELAY;
	DriveSTD_FR_Ty_Temp.blinkingDelayUnder = NO_BLINK_DELAY;
	DriveSTD_FR_Ty_Temp.blinkingStatus = 0;
	DriveSTD_FR_Ty_Temp.blinkingState = 0;

	DriveSTD_FR_Ty_Temp.blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
	DriveSTD_FR_Ty_Temp.blinkingFrameEnable = 1;
	DriveSTD_FR_Ty_Temp.blinkingBackEnable = 1;
	DriveSTD_FR_Ty_Temp.blinkingOverColor = GUI_GREEN;
	DriveSTD_FR_Ty_Temp.blinkingUnderColor = GUI_RED;

	DriveSTD_FR_Ty_Temp.lastExeTime = 0;

}


uint8_t Display_DriveSTD_Initialized = 0;

void Display_DriveSTD(DisplayGui_DataGuiTypeDef *data, uint32_t frameColor)
{
	static uint8_t initializationFlag = 0;
	static uint32_t guiLastMillis = 0;

	static uint32_t millisBlinkClock = 0;
	static uint8_t  blinkClockState = 0;

	if(initializationFlag == 0)
	{
		rectInitialization();
		defaultDataInitialization();

		initializationFlag = 1;
		Display_DriveSTD_Initialized = 1;
	}


	if(millis >= millisBlinkClock + blinkColckPeriod)
	{
		millisBlinkClock += blinkColckPeriod;

		if(blinkClockState != 0)
			blinkClockState = 0;
		else
			blinkClockState = 1;
	}

//CORE FUNCTION BEGIN

	int xt = 0;
	int yt = 0 ;


	// RPM BAR BEGIN

	//Display_OldRpmBar_STD(CAR_Data.rpm.intData);
	Display_OldRpmBar(3, 23 + 10, 474, 20 + 10, CAR_Data.rpm.intData, 0, 5500, 10500, 12500);

	// RPM BAR END


	// GEAR BEGIN

	static uint8_t gear_old = 0;

	if(millis - guiLastMillis >= 100 || gear_old != CAR_Data.gear.intData)// || (CAR_Data.rpm.intData >= RPM_GREEN_MIN && CAR_Data.rpm.intData <= RPM_GREEN_MAX) || CAR_Data.rpm.intData > RPM_RED)
	{
		int16_t gearOffsetY = 0;

		if(gear_old != CAR_Data.gear.intData && (GEARBOX_COLOR_ENABLE == 0))
		{
			GUI_SetColor(GUI_BLACK);
			GUI_FillRect(193, 87 + gearOffsetY, 288, 207 + gearOffsetY);
		}

#if HQ_GEARBOX_ENABLE == 0

		switch(CAR_Data.gear.intData)
		{
			case 0:
				GUI_DrawBitmap(&bmGEARBOX_N, (480 - bmGEARBOX_N.XSize)/2 + 1, 84 + gearOffsetY);
				break;

			case 1:
				GUI_DrawBitmap(&bmGEARBOX_1, (480 - bmGEARBOX_1.XSize)/2 + 1, 84 + gearOffsetY);
				break;

			case 2:
				GUI_DrawBitmap(&bmGEARBOX_2, (480 - bmGEARBOX_2.XSize)/2 + 1, 84 + gearOffsetY);
				break;

			case 3:
				GUI_DrawBitmap(&bmGEARBOX_3, (480 - bmGEARBOX_3.XSize)/2 - 1, 84 + 1 + gearOffsetY);
				break;

			case 4:
				GUI_DrawBitmap(&bmGEARBOX_4, (480 - bmGEARBOX_4.XSize)/2 + 1, 84 + gearOffsetY);
				break;

			default:
				GUI_SetColor(GUI_RED);
				GUI_FillRect(193, 87 + gearOffsetY, 288, 207 + gearOffsetY);

		}

#elif HQ_GEARBOX_ENABLE == 1 && GEARBOX_COLOR_ENABLE == 0

		switch(CAR_Data.gear.intData)
		{
			case 0:
				GUI_DrawBitmap(&bmGEARBOX_N_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 6, 88 + gearOffsetY);
				break;

			case 1:
				GUI_DrawBitmap(&bmGEARBOX_1_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 15, 90 + gearOffsetY);
				break;

			case 2:
				GUI_DrawBitmap(&bmGEARBOX_2_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 13, 90 + gearOffsetY);
				break;

			case 3:
				GUI_DrawBitmap(&bmGEARBOX_3_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 15, 90 + gearOffsetY);
				break;

			case 4:
				GUI_DrawBitmap(&bmGEARBOX_4_116_Gray255, (480 - bmGEARBOX_N.XSize)/2 + 9, 90 + gearOffsetY);
				break;

			default:
				GUI_SetColor(GUI_RED);
				GUI_FillRect(193, 87 + gearOffsetY, 288, 207 + gearOffsetY);

		}

#endif

		//GUI_SetBkColor(GUI_BLACK);

		gear_old = CAR_Data.gear.intData;
	}


#if HQ_GEARBOX_ENABLE == 1 && GEARBOX_COLOR_ENABLE == 1

	int8_t tmpX = 0;

	switch (CAR_Data.gear.intData)
	{
		case 0:
			tmpX = 1;
			break;

		case 1:
			tmpX = -1;
			break;

		case 2:
			tmpX = 1;
			break;

		case 3:
			tmpX = 2;
			break;

		case 4:
			tmpX = 0;
			break;
	}

	if(CAR_Data.rpm.intData >= RPM_GREEN_MIN && CAR_Data.rpm.intData <= RPM_GREEN_MAX)
		GUI_SetColor(GUI_GREEN);
	else if (CAR_Data.rpm.intData > RPM_RED)
		GUI_SetColor(GUI_RED);
	else
		GUI_SetColor(GUI_WHITE);

	GUI_SetFont(&GUI_FontCalibri230Balised2pp_DigAndMaiusc);
	GUI_SetTextAlign(GUI_TA_HCENTER);

	if(CAR_Data.gear.intData != 0)
		GUI_DispDecAt(CAR_Data.gear.intData, 480/2 + tmpX, 90 - 6, 1);
	else
		GUI_DispStringAt("N", 480/2 + tmpX, 90 - 6);

#endif

	// GEAR END

	// RPM BEGIN

	static uint16_t rpm_old = 0;
	static uint8_t pageCall = 0;		//used to avoid a bag showing six zero at the rpm number

	xt = 480 / 2 - 50 + 2;
	yt = 40 + 4;

	if(rpm_old >= 10000 && CAR_Data.rpm.intData < 10000)
	{
		GUI_SetColor(GUI_BLACK);
		GUI_FillRect(xt - 14, yt - 2, xt + 110, yt + 32);
	}

	GUI_SetColor(GUI_WHITE);
	GUI_SetFont(&GUI_FontD32);


	if(CAR_Data.rpm.intData >= RPM_GREEN_MIN && CAR_Data.rpm.intData <= RPM_GREEN_MAX)
		GUI_SetColor(GUI_GREEN);
	else if (CAR_Data.rpm.intData >= RPM_GREEN_MAX)
		GUI_SetColor(GUI_RED);

	if(pageCall > 1)					//used to avoid a bag showing six zero at the rpm number
	{
		if(CAR_Data.rpm.intData < 10000)
		{
			if(millis - CAR_Data.rpm.lastTimeData > 500)
			{
				GUI_SetColor(GUI_RED);
				xt-= 12;
				GUI_DispDecAt(0, xt, yt, 5);
				rpm_old = rpm_max * 2;
			}
			else
				GUI_DispDecAt(CAR_Data.rpm.intData, xt, yt, 4);
		}
		else
		{
			xt-= 14;
			GUI_DispDecAt(CAR_Data.rpm.intData, xt, yt, 5);
		}
	}
	else
	{
		pageCall++;
	}

	rpm_old = CAR_Data.rpm.intData;

	// RPM END

	//data test begin

	GUI_SetColor(GUI_WHITE);
	GUI_SetBkColor(GUI_BLACK);
	GUI_SetFont(&DriveSTD_TextFont);
	GUI_SetTextAlign(GUI_TA_HCENTER);
/*
	char dataCar[16] = "T Water";

	GUI_DispStringAt(dataCar, 50, 34 + 52 + 6);

	GUI_SetFont(&GUI_Font32_1);
	GUI_SetTextAlign(GUI_TA_HCENTER);
	GUI_DispStringAt("120.20", 50, 34 + 52 + 28);

	GUI_SetTextAlign(GUI_TA_LEFT);
*/
	//data test end

	static uint8_t noDataDetectedClear[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


	for(uint8_t rect = 0; rect < 13; rect++)
	{
		if(data[rect].enable != ENABLE)
			goto END_OF_FOR;

		uint16_t x = pageRectPositions[rect].xVertex1 + (pageRectPositions[rect].xVertex2 - pageRectPositions[rect].xVertex1)/2;
		uint16_t y = pageRectPositions[rect].yVertex1 + 4;//(pageRectPositions[rect].yVertex2 - pageRectPositions[rect].yVertex1)/4;

		if(data[rect].receivedDataControlEnable == ENABLE)
		{
			if(millis - *data[rect].lastTimeData > data[rect].noDataErrorTimerValue)
			{
				GUI_SetColor(data[rect].backColor);

				if(data[rect].blinkingBackEnable && (data[rect].blinkingState != 0  || data[rect].blinkingStateOld != 0))
				{
					//GUI_SetColor(data[rect].backColor);
					GUI_FillRect(pageRectPositions[rect].xVertex1, pageRectPositions[rect].yVertex1, pageRectPositions[rect].xVertex2, pageRectPositions[rect].yVertex2);

					data[rect].blinkingState = 0;
					data[rect].blinkingStateOld = 0;
				}

				//GUI_SetColor(data[rect].backColor);
				GUI_FillRect(x - 46, y + 18, x + 46, y + 24);
				GUI_FillRect(x - 46, y + 44, x + 46, y + 55);

				GUI_SetColor(data[rect].textColor);
				GUI_SetBkColor(data[rect].backColor);
				GUI_SetFont(&DriveSTD_TextFont);
				GUI_SetTextAlign(GUI_TA_HCENTER);

				GUI_DispStringAt(data[rect].string, x, y);


				if(data[rect].backColor == GUI_RED)
					GUI_SetColor(GUI_GREEN);
				else
					GUI_SetColor(GUI_RED);

				GUI_SetBkColor(data[rect].backColor);
				GUI_SetFont(&DriveSTD_BigTextFont);
				GUI_SetTextAlign(GUI_TA_HCENTER);

				GUI_DispStringAt("NO DATA", x, y + 25);

				noDataDetectedClear[rect] = 1;

				goto END_OF_FOR;
			}
		}

		if(noDataDetectedClear[rect] != 0)
		{
			GUI_SetColor(data[rect].backColor);
			GUI_FillRect(pageRectPositions[rect].xVertex1, pageRectPositions[rect].yVertex1, pageRectPositions[rect].xVertex2, pageRectPositions[rect].yVertex2);

			noDataDetectedClear[rect] = 0;
		}

		uint8_t dataError = 0;

		uint8_t dataInRange = 1;


		uint32_t textColor = data[rect].textColor;
		uint32_t dataColor = data[rect].dataColor;
		uint32_t backColor = data[rect].backColor;
		uint32_t frameColor = data[rect].frameColor;

		if(textColor == backColor || dataColor == backColor)
			dataError = 1;


		//data in range check
		if(data[rect].valueControlEnable) //&& data[rect].maxValue != data[rect].minValue)
		{
			float tempDatacheck;

			if(data[rect].dataType == DataLog_DataType_Int)
			{
				if(data[rect].dataRefreshDelay == 0 || millis >= data[rect].dataRefreshMillis + data[rect].dataRefreshDelay)
					tempDatacheck = *((int32_t*) data[rect].dataPointer);
				else
					tempDatacheck = data[rect].dataLogInt.number;
			}
			else if(data[rect].dataType == DataLog_DataType_Float)
			{
				if(data[rect].dataRefreshDelay == 0 || millis >= data[rect].dataRefreshMillis + data[rect].dataRefreshDelay)
					tempDatacheck = *((float*) data[rect].dataPointer);
				else
					tempDatacheck = data[rect].dataLogFloat.number;
			}
			else
				dataError = 1;


			if(tempDatacheck < data[rect].maxValue && tempDatacheck > data[rect].minValue)
			{
				data[rect].millisValueOver = millis;
			}

			if(millis >= data[rect].millisValueOver + data[rect].minTimeValueOver || data[rect].minTimeValueOver == 0 || data[rect].blinkingStatus == 1)
			{
				if(tempDatacheck > data[rect].maxValue)
					dataInRange = 2;
				else if(tempDatacheck < data[rect].minValue)
					dataInRange = 0;
				else
					dataInRange = 1;
			}
		}
		else
			dataInRange = 1;


		//blinking state

		uint8_t fixBlinkStateUnder = 0;
		uint8_t fixBlinkStateOver = 0;

		if(data[rect].blinkingDelayUnder > 5000)
			fixBlinkStateUnder = 1;
			//fixBlinkStateOver = 1;

		if(data[rect].blinkingDelayOver > 5000)
			fixBlinkStateOver = 1;
			//fixBlinkStateUnder = 1;


		if(data[rect].blinkingDelayUnder < blinkColckPeriod && !fixBlinkStateUnder)
			data[rect].blinkingDelayUnder = blinkColckPeriod;

		if(data[rect].blinkingDelayOver < blinkColckPeriod && !fixBlinkStateOver)
			data[rect].blinkingDelayOver = blinkColckPeriod;


		switch(dataInRange)
		{
			case 1:						//value in range
				data[rect].blinkingStatus = 0;
				data[rect].blinkingState = 0;
				break;

			case 0:						//too low value

				data[rect].blinkingStatus = 1;

				if(millisBlinkClock >= data[rect].blinkingMillis + data[rect].blinkingDelayUnder)
				{
					if(fixBlinkStateUnder == 1)
						data[rect].blinkingState = 1;
					else
						data[rect].blinkingState = blinkClockState;

					data[rect].blinkingMillis = millisBlinkClock;
				}

				break;


			case 2:						//too high value
			default:

				data[rect].blinkingStatus = 1;

				if(millisBlinkClock >= data[rect].blinkingMillis + data[rect].blinkingDelayOver || data[rect].minTimeValueOver < blinkColckPeriod)
				{
					if(fixBlinkStateOver == 1)
						data[rect].blinkingState = 1;
					else
						data[rect].blinkingState = blinkClockState;

					data[rect].blinkingMillis = millisBlinkClock;
				}

				break;

		}


		//color management
		if(data[rect].blinkingBackEnable)
		{
			if(dataInRange == 0 && data[rect].blinkingState)
			{
				//frameColor = data[rect].blinkingUnderColor;
				backColor = data[rect].blinkingUnderColor;
			}
			else if(dataInRange == 2 && data[rect].blinkingState)
			{
				//frameColor = data[rect].blinkingOverColor;
				backColor = data[rect].blinkingOverColor;
			}
			else
				backColor = data[rect].backColor;

			if(data[rect].blinkingState == 0)
			{
				//frameColor = backColor;
				backColor = data[rect].backColor;
			}
		}

		if(data[rect].blinkingFrameEnable)
		{
			if(dataInRange == 0)
				frameColor = data[rect].blinkingUnderColor;
			else if(dataInRange == 2)
				frameColor = data[rect].blinkingOverColor;
			else
				frameColor = data[rect].frameColor;

			if(data[rect].blinkingStatus != 0 && data[rect].blinkingState == 0)
				frameColor = data[rect].frameColor;
		}


		if(!data[rect].blinkingBackEnable && !data[rect].blinkingFrameEnable)
		{
			if(dataInRange == 0)
				textColor = data[rect].blinkingUnderColor;
			else if(dataInRange == 2)
				textColor = data[rect].blinkingOverColor;
			else
				textColor = data[rect].textColor;

			if(data[rect].blinkingStatus != 0 && data[rect].blinkingState == 0)
				textColor = data[rect].backColor;
		}


		if((data[rect].blinkingBackEnable && data[rect].blinkingState != data[rect].blinkingStateOld) || data[rect].oldValueStatus != dataInRange)
		{
			GUI_SetColor(backColor);

			GUI_FillRect(pageRectPositions[rect].xVertex1 + data[rect].blinkingFrameSize, pageRectPositions[rect].yVertex1 + data[rect].blinkingFrameSize, pageRectPositions[rect].xVertex2 - data[rect].blinkingFrameSize, pageRectPositions[rect].yVertex2 - data[rect].blinkingFrameSize);
		}

		if(!data[rect].blinkingBackEnable && data[rect].blinkingState && data[rect].blinkingStateOld != data[rect].blinkingState)
		{
			GUI_SetColor(data[rect].backColor);
			backColor = data[rect].backColor;

			GUI_FillRect(pageRectPositions[rect].xVertex1 + data[rect].blinkingFrameSize, pageRectPositions[rect].yVertex1 + data[rect].blinkingFrameSize, pageRectPositions[rect].xVertex2 - data[rect].blinkingFrameSize, pageRectPositions[rect].yVertex2 - data[rect].blinkingFrameSize);
		}

		data[rect].blinkingStateOld = data[rect].blinkingState;



		GUI_SetColor(frameColor);

		//GUI_SetColor(GUI_GREEN);

		for(uint8_t size = 0; size < data[rect].blinkingFrameSize; size ++)
		{
			GUI_DrawRect(pageRectPositions[rect].xVertex1 + size, pageRectPositions[rect].yVertex1 + size, pageRectPositions[rect].xVertex2 - size, pageRectPositions[rect].yVertex2 - size);
		}


		if(dataError == 0)
		{
			uint8_t particularDataDetected = 0;

			GUI_SetColor(textColor);
			GUI_SetBkColor(backColor);
			GUI_SetFont(&DriveSTD_TextFont);
			GUI_SetTextAlign(GUI_TA_HCENTER);

			GUI_DispStringAt(data[rect].string, x, y);

			if(data[rect].dataPointer == &CAR_Data.drsStatus.intData)
			{
				particularDataDetected = 1;

				GUI_SetColor(data[rect].dataColor);
				GUI_SetBkColor(backColor);
				//GUI_SetFont(&GUI_Font32B_1);
				GUI_SetFont(&HQ_TEXT_DATA_FONT);

				char pString[4] = "OFF";
				GUI_SetTextAlign(GUI_TA_HCENTER);

				if(*((int32_t*) data[rect].dataPointer) == 0)
					GUI_DispStringAt(pString, x, y + 20 + DriveSTD_DataOffset_y);
				else
				{
					strcpy(pString, "ON");
					GUI_DispStringAt(pString, x, y + 20 + DriveSTD_DataOffset_y);
				}
			}

			if(data[rect].dataPointer == &CAR_Data.map.intData)
			{
				particularDataDetected = 1;

				GUI_SetColor(data[rect].dataColor);
				GUI_SetBkColor(backColor);
				//GUI_SetFont(&GUI_Font32B_1);
				GUI_SetFont(&HQ_TEXT_DATA_FONT);

				char pString[5] = "BASE";
				GUI_SetTextAlign(GUI_TA_HCENTER);

				if(*((int32_t*) data[rect].dataPointer) == 0)
					GUI_DispStringAt(pString, x, y + 20 + DriveSTD_DataOffset_y);
				else if(*((int32_t*) data[rect].dataPointer) == 1)
				{
					strcpy(pString, "ECO");
					GUI_DispStringAt(pString, x, y + 20 + DriveSTD_DataOffset_y);
				}
				else
				{
					GUI_SetColor(GUI_RED);
					strcpy(pString, "ERR");
					GUI_DispStringAt(pString, x, y + 20 + DriveSTD_DataOffset_y);
				}
			}

			if(data[rect].dataPointer == &CAR_Data.tractionControl.intData)// && *((int32_t*) data[rect].dataPointer) == 0)
			{
				particularDataDetected = 1;

				/*
				GUI_SetColor(data[rect].dataColor);
				GUI_SetBkColor(backColor);
				GUI_SetFont(&GUI_Font32B_1);

				char pString[4] = "OFF";
				GUI_SetTextAlign(GUI_TA_HCENTER);

				GUI_DispStringAt(pString, x, y + 20);
				*/

				if(data[rect].dataRefreshDelay == 0 || millis >= data[rect].dataRefreshMillis + data[rect].dataRefreshDelay)
				{
					data[rect].dataLogInt.number = *((int32_t*) data[rect].dataPointer);
					data[rect].dataRefreshMillis = millis;
				}

				static int32_t oldData = 0;

				if(*((int32_t*) data[rect].dataPointer) == 0)
				{
					GUI_SetColor(data[rect].dataColor);
					GUI_SetBkColor(backColor);
					GUI_SetFont(&HQ_TEXT_DATA_FONT);

					char pString[4] = "OFF";
					GUI_SetTextAlign(GUI_TA_HCENTER);

					GUI_DispStringAt(pString, x, y + 20 + DriveSTD_DataOffset_y);
				}
				else
				{
					if(oldData == 0)
					{
						GUI_SetColor(backColor);
						//GUI_SetColor(GUI_GREEN);
						GUI_FillRect(x - 36, y + 20, x + 36, y + 48);
					}

					GUI_DrawNumAt_Dec(x, y + 20 + DriveSTD_DataOffset_y, &DriveSTD_DataFont, data[rect].dataColor, backColor, &data[rect].dataLogInt, data[rect].signEnable, CENTER, data[rect].intStr, data[rect].endStr);
				}

				oldData = *((int32_t*) data[rect].dataPointer);
			}


			if(particularDataDetected == 0)
			{
				if(data[rect].dataType == DataLog_DataType_Float)
				{
					uint8_t decimalDigit = data[rect].decimalDigits;

					if(decimalDigit > 3)
						decimalDigit = 3;

					if(data[rect].dataRefreshDelay == 0 || millis >= data[rect].dataRefreshMillis + data[rect].dataRefreshDelay)
					{
						data[rect].dataLogFloat.number = *((float*) data[rect].dataPointer);
						data[rect].dataRefreshMillis = millis;
					}

					GUI_DrawNumAt(x, y + 20 + DriveSTD_DataOffset_y, &DriveSTD_DataFont, data[rect].dataColor, backColor, &data[rect].dataLogFloat, UNDEFINED_NINT, decimalDigit, data[rect].signEnable, DISABLE, CENTER, data[rect].intStr, data[rect].endStr);
				}
				else if(data[rect].dataType == DataLog_DataType_Int)
				{
					if(data[rect].dataRefreshDelay == 0 || millis >= data[rect].dataRefreshMillis + data[rect].dataRefreshDelay)
					{
						data[rect].dataLogInt.number = *((int32_t*) data[rect].dataPointer);
						data[rect].dataRefreshMillis = millis;
					}

					GUI_DrawNumAt_Dec(x, y + 20 + DriveSTD_DataOffset_y, &DriveSTD_DataFont, data[rect].dataColor, backColor, &data[rect].dataLogInt, data[rect].signEnable, CENTER, data[rect].intStr, data[rect].endStr);
				}
				else dataError = 1;
			}

		}

		if(dataError != 0)
		{

			GUI_SetColor(GUI_RED);
			GUI_SetBkColor(GUI_BLACK);
			GUI_SetFont(&DriveSTD_TextFont);
			GUI_SetTextAlign(GUI_TA_HCENTER);

			GUI_DispStringAt("ERR", x, y + 14);
		}


		data[rect].oldValueStatus = dataInRange;

		data[rect].lastExeTime = millis;

		END_OF_FOR:;
	}




//CORE FUNCTION END

	Display_Frame(frameColor);
	Display_Armature();

	guiLastMillis = millis;
}



void Display_Frame(uint32_t color)
{
	GUI_SetColor(color);

	//main rect (frame)
	GUI_DrawRect(1, 1, 479, 271);
	GUI_DrawRect(2, 2, 478, 270);

	//GUI_AA_DisableHiRes();
	//GUI_SetPenSize(1);
}


void Display_Armature(void)
{
	//GUI_SetColor(GUI_GREEN);
	GUI_SetColor(GUI_WHITE);

	//Horizontal lines
	GUI_DrawLine(3, 				34, 				477, 				34);
	GUI_DrawLine(3, 				34 + 52, 			477, 				34 + 52);

	GUI_DrawLine(3, 				34 + 52 + 1*61, 	2 + 2*95, 			34 + 52 + 1*61);
	GUI_DrawLine(3 + 3*95, 			34 + 52 + 1*61, 	477, 				34 + 52 + 1*61);

	GUI_DrawLine(3, 				34 + 52 + 2*61, 	477, 				34 + 52 + 2*61);

	//Vertical lines
	GUI_DrawLine(2 + 2*88 - 1,	 	25 + 9, 			2 + 2*88 - 1, 			25 + 9 + 52);
	GUI_DrawLine(480 - 2 - 2*88 + 1,25 + 9, 			480 - 2 - 2*88 + 1, 	25 + 9 + 52);

	GUI_DrawLine(2 + 1*95, 			25 + 9 + 52, 		2 + 1*95, 			270);
	GUI_DrawLine(2 + 2*95, 			25 + 9 + 52, 		2 + 2*95, 			270);
	GUI_DrawLine(2 + 3*95 + 1, 		25 + 9 + 52, 		2 + 3*95 + 1, 		270);
	GUI_DrawLine(2 + 4*95 + 1, 		25 + 9 + 52, 		2 + 4*95 + 1, 		270);
}
