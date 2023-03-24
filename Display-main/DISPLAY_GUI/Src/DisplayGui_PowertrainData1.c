
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

static void DisplayGui_Intro(void);
static void DisplayGui_DataInit(void);
static void DisplayGui_DataRefresh(void);

extern void Display_DataLog(DisplayGui_DataGuiTypeDef *data, uint8_t density);


//DisplayGui_DataLogTypeDef powertrainData[5][5] = {0};

DisplayGui_DataGuiTypeDef powertrainData_dense[20] = {0};

uint32_t PowertrainData1TextColor = GUI_WHITE;
uint32_t PowertrainData1DataColor = GUI_WHITE;
uint32_t PowertrainData1BackColor = GUI_BLACK;


#define DEFAULT_BLINKING_FRAME_SIZE		4

#define DEFAULT_BLINK_DELAY_OVER		250
#define DEFAULT_BLINK_DELAY_UNDER		250


void DisplayGui_PowertrainData1(void)
{
	// Intro section BEGIN
	static uint32_t millisGuiIntro = 0;
	static uint8_t introStatus = 0;

	if(selectedGui_old != GuiPowertrainData1)
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

	DisplayGui_DataRefresh();
	Display_DataLog(&powertrainData_dense[0], 0);

	//CORE FUNCTION END

	DisplayGui_END:;
}


void DisplayGui_DataInit(void)
{
	static uint8_t flagInit = 0;

	if(flagInit == 0)
	{
		flagInit = 1;

		powertrainData_dense[0].enable = ENABLE;

		powertrainData_dense[0].string = "Data 1";
		powertrainData_dense[0].intStr = "";
		powertrainData_dense[0].endStr = "";

		powertrainData_dense[0].dataLogInt.number = 123;
		powertrainData_dense[0].dataLogFloat.number = 0;
		powertrainData_dense[0].decimalDigits = 2;

		powertrainData_dense[0].textColor = PowertrainData1TextColor;
		powertrainData_dense[0].backColor = PowertrainData1BackColor;
		powertrainData_dense[0].dataColor = PowertrainData1DataColor;
		powertrainData_dense[0].frameColor = PowertrainData1BackColor;

		powertrainData_dense[0].dataType = DataLog_DataType_Float;
		powertrainData_dense[0].signEnable = DISABLE;

		powertrainData_dense[0].valueControlEnable = DISABLE;
		powertrainData_dense[0].maxValue = 0;
		powertrainData_dense[0].minValue = 0;

		powertrainData_dense[0].lastExeTime = 0;
		powertrainData_dense[0].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[0].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[0].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[0].blinkingFrameEnable = ENABLE;
		powertrainData_dense[0].blinkingBackEnable = DISABLE;
		powertrainData_dense[0].blinkingOverColor = GUI_RED;
		powertrainData_dense[0].blinkingUnderColor = GUI_BLUE;



		powertrainData_dense[1].enable = ENABLE;

		powertrainData_dense[1].string = "Data 2";
		powertrainData_dense[1].intStr = "N: ";
		powertrainData_dense[1].endStr = " dec";

		powertrainData_dense[1].dataLogInt.number = 2;
		powertrainData_dense[1].dataLogFloat.number = 2;
		powertrainData_dense[1].decimalDigits = 1;

		powertrainData_dense[1].textColor = PowertrainData1TextColor;
		powertrainData_dense[1].backColor = PowertrainData1BackColor;
		powertrainData_dense[1].dataColor = PowertrainData1DataColor;
		powertrainData_dense[1].frameColor = PowertrainData1BackColor;

		powertrainData_dense[1].dataType = DataLog_DataType_Int;
		powertrainData_dense[1].signEnable = DISABLE;

		powertrainData_dense[1].valueControlEnable = DISABLE;
		powertrainData_dense[1].maxValue = 0;
		powertrainData_dense[1].minValue = 0;

		powertrainData_dense[1].lastExeTime = 0;
		powertrainData_dense[1].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[1].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[1].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[1].blinkingFrameEnable = ENABLE;
		powertrainData_dense[1].blinkingBackEnable = DISABLE;
		powertrainData_dense[1].blinkingOverColor = GUI_RED;
		powertrainData_dense[1].blinkingUnderColor = GUI_BLUE;



		powertrainData_dense[2].enable = ENABLE;

		powertrainData_dense[2].string = "Data 3";
		powertrainData_dense[2].intStr = "";
		powertrainData_dense[2].endStr = "";

		powertrainData_dense[2].dataLogInt.number = 123;
		powertrainData_dense[2].dataLogFloat.number = 1;
		powertrainData_dense[2].decimalDigits = 1;

		powertrainData_dense[2].textColor = PowertrainData1TextColor;
		powertrainData_dense[2].backColor = PowertrainData1BackColor;
		powertrainData_dense[2].dataColor = PowertrainData1DataColor;
		powertrainData_dense[2].frameColor = PowertrainData1BackColor;

		powertrainData_dense[2].dataType = DataLog_DataType_Int;
		powertrainData_dense[2].signEnable = DISABLE;

		powertrainData_dense[2].valueControlEnable = DISABLE;
		powertrainData_dense[2].maxValue = 0;
		powertrainData_dense[2].minValue = 0;

		powertrainData_dense[2].lastExeTime = 0;
		powertrainData_dense[2].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[2].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[2].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[2].blinkingFrameEnable = ENABLE;
		powertrainData_dense[2].blinkingBackEnable = DISABLE;
		powertrainData_dense[2].blinkingOverColor = GUI_RED;
		powertrainData_dense[2].blinkingUnderColor = GUI_BLUE;



		powertrainData_dense[3].enable = ENABLE;

		powertrainData_dense[3].string = "Oil Pressure";
		powertrainData_dense[3].intStr = "";
		powertrainData_dense[3].endStr = "";

		powertrainData_dense[3].dataLogInt.number = 123;
		powertrainData_dense[3].dataLogFloat.number = 0.7;
		powertrainData_dense[3].decimalDigits = 1;

		powertrainData_dense[3].textColor = PowertrainData1TextColor;
		powertrainData_dense[3].backColor = PowertrainData1BackColor;
		powertrainData_dense[3].dataColor = PowertrainData1DataColor;
		powertrainData_dense[3].frameColor = PowertrainData1BackColor;

		powertrainData_dense[3].dataType = DataLog_DataType_Float;
		powertrainData_dense[3].signEnable = DISABLE;

		powertrainData_dense[3].valueControlEnable = ENABLE;
		powertrainData_dense[3].maxValue = pOil_MAX_VALUE;
		powertrainData_dense[3].minValue = pOil_MIN_VALUE;

		powertrainData_dense[3].lastExeTime = 0;
		powertrainData_dense[3].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[3].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[3].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[3].blinkingFrameEnable = ENABLE;
		powertrainData_dense[3].blinkingBackEnable = ENABLE;
		powertrainData_dense[3].blinkingOverColor = GUI_RED;
		powertrainData_dense[3].blinkingUnderColor = GUI_RED;



		powertrainData_dense[4].enable = ENABLE;

		powertrainData_dense[4].string = "Data 5";
		powertrainData_dense[4].intStr = "";
		powertrainData_dense[4].endStr = "";

		powertrainData_dense[4].dataLogInt.number = 123;
		powertrainData_dense[4].dataLogFloat.number = 1;
		powertrainData_dense[4].decimalDigits = 2;

		powertrainData_dense[4].textColor = PowertrainData1TextColor;
		powertrainData_dense[4].backColor = PowertrainData1BackColor;
		powertrainData_dense[4].dataColor = PowertrainData1DataColor;
		powertrainData_dense[4].frameColor = PowertrainData1BackColor;

		powertrainData_dense[4].dataType = DataLog_DataType_Float;
		powertrainData_dense[4].signEnable = DISABLE;

		powertrainData_dense[4].valueControlEnable = DISABLE;
		powertrainData_dense[4].maxValue = 0;
		powertrainData_dense[4].minValue = 0;

		powertrainData_dense[4].lastExeTime = 0;
		powertrainData_dense[4].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[4].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[4].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[4].blinkingFrameEnable = ENABLE;
		powertrainData_dense[4].blinkingBackEnable = DISABLE;
		powertrainData_dense[4].blinkingOverColor = GUI_RED;
		powertrainData_dense[4].blinkingUnderColor = GUI_BLUE;



		powertrainData_dense[5].enable = ENABLE;

		powertrainData_dense[5].string = "Data 6";
		powertrainData_dense[5].intStr = "";
		powertrainData_dense[5].endStr = "";

		powertrainData_dense[5].dataLogInt.number = 123;
		powertrainData_dense[5].dataLogFloat.number = 1;
		powertrainData_dense[5].decimalDigits = 1;

		powertrainData_dense[5].textColor = PowertrainData1TextColor;
		powertrainData_dense[5].backColor = PowertrainData1BackColor;
		powertrainData_dense[5].dataColor = PowertrainData1DataColor;
		powertrainData_dense[5].frameColor = PowertrainData1BackColor;

		powertrainData_dense[5].dataType = DataLog_DataType_Float;
		powertrainData_dense[5].signEnable = DISABLE;

		powertrainData_dense[5].valueControlEnable = DISABLE;
		powertrainData_dense[5].maxValue = 0;
		powertrainData_dense[5].minValue = 0;

		powertrainData_dense[5].lastExeTime = 0;
		powertrainData_dense[5].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[5].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[5].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[5].blinkingFrameEnable = ENABLE;
		powertrainData_dense[5].blinkingBackEnable = DISABLE;
		powertrainData_dense[5].blinkingOverColor = GUI_RED;
		powertrainData_dense[5].blinkingUnderColor = GUI_BLUE;



		powertrainData_dense[6].enable = ENABLE;

		powertrainData_dense[6].string = "Data 7";
		powertrainData_dense[6].intStr = "";
		powertrainData_dense[6].endStr = "";

		powertrainData_dense[6].dataLogInt.number = 123;
		powertrainData_dense[6].dataLogFloat.number = 1;
		powertrainData_dense[6].decimalDigits = 1;

		powertrainData_dense[6].textColor = PowertrainData1TextColor;
		powertrainData_dense[6].backColor = PowertrainData1BackColor;
		powertrainData_dense[6].dataColor = PowertrainData1DataColor;
		powertrainData_dense[6].frameColor = PowertrainData1BackColor;

		powertrainData_dense[6].dataType = DataLog_DataType_Float;
		powertrainData_dense[6].signEnable = DISABLE;

		powertrainData_dense[6].valueControlEnable = DISABLE;
		powertrainData_dense[6].maxValue = 0;
		powertrainData_dense[6].minValue = 0;

		powertrainData_dense[6].lastExeTime = 0;
		powertrainData_dense[6].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[6].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[6].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[6].blinkingFrameEnable = ENABLE;
		powertrainData_dense[6].blinkingBackEnable = DISABLE;
		powertrainData_dense[6].blinkingOverColor = GUI_RED;
		powertrainData_dense[6].blinkingUnderColor = GUI_BLUE;



		powertrainData_dense[7].enable = ENABLE;

		powertrainData_dense[7].string = "Water Temp";
		powertrainData_dense[7].intStr = "";
		powertrainData_dense[7].endStr = " C";

		powertrainData_dense[7].dataLogInt.number = 123;
		powertrainData_dense[7].dataLogFloat.number = 64.3;
		powertrainData_dense[7].decimalDigits = 1;

		powertrainData_dense[7].textColor = PowertrainData1TextColor;
		powertrainData_dense[7].backColor = PowertrainData1BackColor;
		powertrainData_dense[7].dataColor = PowertrainData1DataColor;
		powertrainData_dense[7].frameColor = PowertrainData1BackColor;

		powertrainData_dense[7].dataType = DataLog_DataType_Float;
		powertrainData_dense[7].signEnable = DISABLE;

		powertrainData_dense[7].valueControlEnable = ENABLE;
		powertrainData_dense[7].maxValue = tWater_MAX_VALUE;
		powertrainData_dense[7].minValue = tWater_MIN_VALUE;

		powertrainData_dense[7].lastExeTime = 0;
		powertrainData_dense[7].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[7].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[7].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[7].blinkingFrameEnable = ENABLE;
		powertrainData_dense[7].blinkingBackEnable = DISABLE;
		powertrainData_dense[7].blinkingOverColor = GUI_RED;
		powertrainData_dense[7].blinkingUnderColor = GUI_BLUE;



		powertrainData_dense[8].enable = ENABLE;

		powertrainData_dense[8].string = "Data 9";
		powertrainData_dense[8].intStr = "";
		powertrainData_dense[8].endStr = "";

		powertrainData_dense[8].dataLogInt.number = 123;
		powertrainData_dense[8].dataLogFloat.number = 1;
		powertrainData_dense[8].decimalDigits = 2;

		powertrainData_dense[8].textColor = PowertrainData1TextColor;
		powertrainData_dense[8].backColor = PowertrainData1BackColor;
		powertrainData_dense[8].dataColor = PowertrainData1DataColor;
		powertrainData_dense[8].frameColor = PowertrainData1BackColor;

		powertrainData_dense[8].dataType = DataLog_DataType_Float;
		powertrainData_dense[8].signEnable = DISABLE;

		powertrainData_dense[8].valueControlEnable = DISABLE;
		powertrainData_dense[8].maxValue = 0;
		powertrainData_dense[8].minValue = 0;

		powertrainData_dense[8].lastExeTime = 0;
		powertrainData_dense[8].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[8].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[8].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[8].blinkingFrameEnable = ENABLE;
		powertrainData_dense[8].blinkingBackEnable = DISABLE;
		powertrainData_dense[8].blinkingOverColor = GUI_RED;
		powertrainData_dense[8].blinkingUnderColor = GUI_BLUE;



		powertrainData_dense[9].enable = ENABLE;

		powertrainData_dense[9].string = "Data 10";
		powertrainData_dense[9].intStr = "";
		powertrainData_dense[9].endStr = "";

		powertrainData_dense[9].dataLogInt.number = 123;
		powertrainData_dense[9].dataLogFloat.number = 1;
		powertrainData_dense[9].decimalDigits = 1;

		powertrainData_dense[9].textColor = PowertrainData1TextColor;
		powertrainData_dense[9].backColor = PowertrainData1BackColor;
		powertrainData_dense[9].dataColor = PowertrainData1DataColor;
		powertrainData_dense[9].frameColor = PowertrainData1BackColor;

		powertrainData_dense[9].dataType = DataLog_DataType_Float;
		powertrainData_dense[9].signEnable = DISABLE;

		powertrainData_dense[9].valueControlEnable = DISABLE;
		powertrainData_dense[9].maxValue = 0;
		powertrainData_dense[9].minValue = 0;

		powertrainData_dense[9].lastExeTime = 0;
		powertrainData_dense[9].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[9].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[9].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[9].blinkingFrameEnable = ENABLE;
		powertrainData_dense[9].blinkingBackEnable = DISABLE;
		powertrainData_dense[9].blinkingOverColor = GUI_RED;
		powertrainData_dense[9].blinkingUnderColor = GUI_BLUE;



		powertrainData_dense[10].enable = ENABLE;

		powertrainData_dense[10].string = "Data 11";
		powertrainData_dense[10].intStr = "";
		powertrainData_dense[10].endStr = "";

		powertrainData_dense[10].dataLogInt.number = 123;
		powertrainData_dense[10].dataLogFloat.number = 1;
		powertrainData_dense[10].decimalDigits = 1;

		powertrainData_dense[10].textColor = PowertrainData1TextColor;
		powertrainData_dense[10].backColor = PowertrainData1BackColor;
		powertrainData_dense[10].dataColor = PowertrainData1DataColor;
		powertrainData_dense[10].frameColor = PowertrainData1BackColor;

		powertrainData_dense[10].dataType = DataLog_DataType_Float;
		powertrainData_dense[10].signEnable = DISABLE;

		powertrainData_dense[10].valueControlEnable = DISABLE;
		powertrainData_dense[10].maxValue = 0;
		powertrainData_dense[10].minValue = 0;

		powertrainData_dense[10].lastExeTime = 0;
		powertrainData_dense[10].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[10].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[10].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[10].blinkingFrameEnable = ENABLE;
		powertrainData_dense[10].blinkingBackEnable = DISABLE;
		powertrainData_dense[10].blinkingOverColor = GUI_RED;
		powertrainData_dense[10].blinkingUnderColor = GUI_BLUE;



		powertrainData_dense[11].enable = ENABLE;

		powertrainData_dense[11].string = "Data 12";
		powertrainData_dense[11].intStr = "";
		powertrainData_dense[11].endStr = "";

		powertrainData_dense[11].dataLogInt.number = 123;
		powertrainData_dense[11].dataLogFloat.number = 1;
		powertrainData_dense[11].decimalDigits = 1;

		powertrainData_dense[11].textColor = PowertrainData1TextColor;
		powertrainData_dense[11].backColor = PowertrainData1BackColor;
		powertrainData_dense[11].dataColor = PowertrainData1DataColor;
		powertrainData_dense[11].frameColor = PowertrainData1BackColor;

		powertrainData_dense[11].dataType = DataLog_DataType_Float;
		powertrainData_dense[11].signEnable = DISABLE;

		powertrainData_dense[11].valueControlEnable = DISABLE;
		powertrainData_dense[11].maxValue = 0;
		powertrainData_dense[11].minValue = 0;

		powertrainData_dense[11].lastExeTime = 0;
		powertrainData_dense[11].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[11].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[11].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[11].blinkingFrameEnable = ENABLE;
		powertrainData_dense[11].blinkingBackEnable = DISABLE;
		powertrainData_dense[11].blinkingOverColor = GUI_RED;
		powertrainData_dense[11].blinkingUnderColor = GUI_BLUE;



		powertrainData_dense[12].enable = ENABLE;

		powertrainData_dense[12].string = "Data 13";
		powertrainData_dense[12].intStr = "";
		powertrainData_dense[12].endStr = "";

		powertrainData_dense[12].dataLogInt.number = 123;
		powertrainData_dense[12].dataLogFloat.number = 1;
		powertrainData_dense[12].decimalDigits = 1;

		powertrainData_dense[12].textColor = PowertrainData1TextColor;
		powertrainData_dense[12].backColor = PowertrainData1BackColor;
		powertrainData_dense[12].dataColor = PowertrainData1DataColor;
		powertrainData_dense[12].frameColor = PowertrainData1BackColor;

		powertrainData_dense[12].dataType = DataLog_DataType_Float;
		powertrainData_dense[12].signEnable = DISABLE;

		powertrainData_dense[12].valueControlEnable = DISABLE;
		powertrainData_dense[12].maxValue = 0;
		powertrainData_dense[12].minValue = 0;

		powertrainData_dense[12].lastExeTime = 0;
		powertrainData_dense[12].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[12].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[12].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[12].blinkingFrameEnable = ENABLE;
		powertrainData_dense[12].blinkingBackEnable = DISABLE;
		powertrainData_dense[12].blinkingOverColor = GUI_RED;
		powertrainData_dense[12].blinkingUnderColor = GUI_BLUE;



		powertrainData_dense[13].enable = ENABLE;

		powertrainData_dense[13].string = "Data 14";
		powertrainData_dense[13].intStr = "";
		powertrainData_dense[13].endStr = "";

		powertrainData_dense[13].dataLogInt.number = 123;
		powertrainData_dense[13].dataLogFloat.number = 1;
		powertrainData_dense[13].decimalDigits = 1;

		powertrainData_dense[13].textColor = PowertrainData1TextColor;
		powertrainData_dense[13].backColor = PowertrainData1BackColor;
		powertrainData_dense[13].dataColor = PowertrainData1DataColor;
		powertrainData_dense[13].frameColor = PowertrainData1BackColor;

		powertrainData_dense[13].dataType = DataLog_DataType_Float;
		powertrainData_dense[13].signEnable = DISABLE;

		powertrainData_dense[13].valueControlEnable = DISABLE;
		powertrainData_dense[13].maxValue = 0;
		powertrainData_dense[13].minValue = 0;

		powertrainData_dense[13].lastExeTime = 0;
		powertrainData_dense[13].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[13].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[13].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[13].blinkingFrameEnable = ENABLE;
		powertrainData_dense[13].blinkingBackEnable = DISABLE;
		powertrainData_dense[13].blinkingOverColor = GUI_RED;
		powertrainData_dense[13].blinkingUnderColor = GUI_BLUE;



		powertrainData_dense[14].enable = ENABLE;

		powertrainData_dense[14].string = "Data 15";
		powertrainData_dense[14].intStr = "";
		powertrainData_dense[14].endStr = "";

		powertrainData_dense[14].dataLogInt.number = 123;
		powertrainData_dense[14].dataLogFloat.number = 1;
		powertrainData_dense[14].decimalDigits = 1;

		powertrainData_dense[14].textColor = PowertrainData1TextColor;
		powertrainData_dense[14].backColor = PowertrainData1BackColor;
		powertrainData_dense[14].dataColor = PowertrainData1DataColor;
		powertrainData_dense[14].frameColor = PowertrainData1BackColor;

		powertrainData_dense[14].dataType = DataLog_DataType_Float;
		powertrainData_dense[14].signEnable = DISABLE;

		powertrainData_dense[14].valueControlEnable = DISABLE;
		powertrainData_dense[14].maxValue = 0;
		powertrainData_dense[14].minValue = 0;

		powertrainData_dense[14].lastExeTime = 0;
		powertrainData_dense[14].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[14].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[14].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[14].blinkingFrameEnable = ENABLE;
		powertrainData_dense[14].blinkingBackEnable = DISABLE;
		powertrainData_dense[14].blinkingOverColor = GUI_RED;
		powertrainData_dense[14].blinkingUnderColor = GUI_BLUE;



		powertrainData_dense[15].enable = ENABLE;

		powertrainData_dense[15].string = "Data 16";
		powertrainData_dense[15].intStr = "";
		powertrainData_dense[15].endStr = "";

		powertrainData_dense[15].dataLogInt.number = 123;
		powertrainData_dense[15].dataLogFloat.number = 1;
		powertrainData_dense[15].decimalDigits = 1;

		powertrainData_dense[15].textColor = PowertrainData1TextColor;
		powertrainData_dense[15].backColor = PowertrainData1BackColor;
		powertrainData_dense[15].dataColor = PowertrainData1DataColor;
		powertrainData_dense[15].frameColor = PowertrainData1BackColor;

		powertrainData_dense[15].dataType = DataLog_DataType_Float;
		powertrainData_dense[15].signEnable = DISABLE;

		powertrainData_dense[15].valueControlEnable = DISABLE;
		powertrainData_dense[15].maxValue = 0;
		powertrainData_dense[15].minValue = 0;

		powertrainData_dense[15].lastExeTime = 0;
		powertrainData_dense[15].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[15].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[15].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[15].blinkingFrameEnable = ENABLE;
		powertrainData_dense[15].blinkingBackEnable = DISABLE;
		powertrainData_dense[15].blinkingOverColor = GUI_RED;
		powertrainData_dense[15].blinkingUnderColor = GUI_BLUE;



		powertrainData_dense[16].enable = ENABLE;

		powertrainData_dense[16].string = "Data 17";
		powertrainData_dense[16].intStr = "";
		powertrainData_dense[16].endStr = "";

		powertrainData_dense[16].dataLogInt.number = 123;
		powertrainData_dense[16].dataLogFloat.number = 1;
		powertrainData_dense[16].decimalDigits = 1;

		powertrainData_dense[16].textColor = PowertrainData1TextColor;
		powertrainData_dense[16].backColor = PowertrainData1BackColor;
		powertrainData_dense[16].dataColor = PowertrainData1DataColor;
		powertrainData_dense[16].frameColor = PowertrainData1BackColor;

		powertrainData_dense[16].dataType = DataLog_DataType_Float;
		powertrainData_dense[16].signEnable = DISABLE;

		powertrainData_dense[16].valueControlEnable = DISABLE;
		powertrainData_dense[16].maxValue = 0;
		powertrainData_dense[16].minValue = 0;

		powertrainData_dense[16].lastExeTime = 0;
		powertrainData_dense[16].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[16].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[16].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[16].blinkingFrameEnable = ENABLE;
		powertrainData_dense[16].blinkingBackEnable = DISABLE;
		powertrainData_dense[16].blinkingOverColor = GUI_RED;
		powertrainData_dense[16].blinkingUnderColor = GUI_BLUE;



		powertrainData_dense[17].enable = ENABLE;

		powertrainData_dense[17].string = "Data 18";
		powertrainData_dense[17].intStr = "";
		powertrainData_dense[17].endStr = "";

		powertrainData_dense[17].dataLogInt.number = 123;
		powertrainData_dense[17].dataLogFloat.number = 1;
		powertrainData_dense[17].decimalDigits = 1;

		powertrainData_dense[17].textColor = PowertrainData1TextColor;
		powertrainData_dense[17].backColor = PowertrainData1BackColor;
		powertrainData_dense[17].dataColor = PowertrainData1DataColor;
		powertrainData_dense[17].frameColor = PowertrainData1BackColor;

		powertrainData_dense[17].dataType = DataLog_DataType_Float;
		powertrainData_dense[17].signEnable = DISABLE;

		powertrainData_dense[17].valueControlEnable = DISABLE;
		powertrainData_dense[17].maxValue = 0;
		powertrainData_dense[17].minValue = 0;

		powertrainData_dense[17].lastExeTime = 0;
		powertrainData_dense[17].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[17].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[17].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[17].blinkingFrameEnable = ENABLE;
		powertrainData_dense[17].blinkingBackEnable = DISABLE;
		powertrainData_dense[17].blinkingOverColor = GUI_RED;
		powertrainData_dense[17].blinkingUnderColor = GUI_BLUE;



		powertrainData_dense[18].enable = ENABLE;

		powertrainData_dense[18].string = "Data 19";
		powertrainData_dense[18].intStr = "";
		powertrainData_dense[18].endStr = "";

		powertrainData_dense[18].dataLogInt.number = 123;
		powertrainData_dense[18].dataLogFloat.number = 1;
		powertrainData_dense[18].decimalDigits = 1;

		powertrainData_dense[18].textColor = PowertrainData1TextColor;
		powertrainData_dense[18].backColor = PowertrainData1BackColor;
		powertrainData_dense[18].dataColor = PowertrainData1DataColor;
		powertrainData_dense[18].frameColor = PowertrainData1BackColor;

		powertrainData_dense[18].dataType = DataLog_DataType_Float;
		powertrainData_dense[18].signEnable = DISABLE;

		powertrainData_dense[18].valueControlEnable = DISABLE;
		powertrainData_dense[18].maxValue = 0;
		powertrainData_dense[18].minValue = 0;

		powertrainData_dense[18].lastExeTime = 0;
		powertrainData_dense[18].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[18].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[18].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[18].blinkingFrameEnable = ENABLE;
		powertrainData_dense[18].blinkingBackEnable = DISABLE;
		powertrainData_dense[18].blinkingOverColor = GUI_RED;
		powertrainData_dense[18].blinkingUnderColor = GUI_BLUE;



		powertrainData_dense[19].enable = ENABLE;

		powertrainData_dense[19].string = "Data 20";
		powertrainData_dense[19].intStr = "";
		powertrainData_dense[19].endStr = "";

		powertrainData_dense[19].dataLogInt.number = 123;
		powertrainData_dense[19].dataLogFloat.number = 1;
		powertrainData_dense[19].decimalDigits = 1;

		powertrainData_dense[19].textColor = PowertrainData1TextColor;
		powertrainData_dense[19].backColor = PowertrainData1BackColor;
		powertrainData_dense[19].dataColor = PowertrainData1DataColor;
		powertrainData_dense[19].frameColor = PowertrainData1BackColor;

		powertrainData_dense[19].dataType = DataLog_DataType_Float;
		powertrainData_dense[19].signEnable = DISABLE;

		powertrainData_dense[19].valueControlEnable = DISABLE;
		powertrainData_dense[19].maxValue = 0;
		powertrainData_dense[19].minValue = 0;

		powertrainData_dense[19].lastExeTime = 0;
		powertrainData_dense[19].blinkingDelayOver = DEFAULT_BLINK_DELAY_OVER;
		powertrainData_dense[19].blinkingDelayUnder = DEFAULT_BLINK_DELAY_UNDER;

		powertrainData_dense[19].blinkingFrameSize = DEFAULT_BLINKING_FRAME_SIZE;
		powertrainData_dense[19].blinkingFrameEnable = ENABLE;
		powertrainData_dense[19].blinkingBackEnable = DISABLE;
		powertrainData_dense[19].blinkingOverColor = GUI_RED;
		powertrainData_dense[19].blinkingUnderColor = GUI_BLUE;

	}
}


void DisplayGui_DataRefresh(void)
{
	powertrainData_dense[0].dataLogFloat.number = 0;
	powertrainData_dense[0].dataLogInt.number = 123;

	powertrainData_dense[1].dataLogFloat.number = 0;
	powertrainData_dense[1].dataLogInt.number = 2;

	powertrainData_dense[2].dataLogFloat.number = 0;
	powertrainData_dense[2].dataLogInt.number = 123;

	powertrainData_dense[3].dataLogFloat.number = 0.7;
	powertrainData_dense[3].dataLogInt.number = 123;

	powertrainData_dense[4].dataLogFloat.number = 1.23456789;
	powertrainData_dense[4].dataLogInt.number = 123;

	powertrainData_dense[5].dataLogFloat.number = 0;
	powertrainData_dense[5].dataLogInt.number = 123;

	powertrainData_dense[6].dataLogFloat.number = 0;
	powertrainData_dense[6].dataLogInt.number = 123;

	powertrainData_dense[7].dataLogFloat.number = 64.2;
	powertrainData_dense[7].dataLogInt.number = 123;

	powertrainData_dense[8].dataLogFloat.number = 123.456789;
	powertrainData_dense[8].dataLogInt.number = 123;

	powertrainData_dense[9].dataLogFloat.number = 0;
	powertrainData_dense[9].dataLogInt.number = 123;

	powertrainData_dense[10].dataLogFloat.number = 0;
	powertrainData_dense[10].dataLogInt.number = 123;

	powertrainData_dense[11].dataLogFloat.number = 0;
	powertrainData_dense[11].dataLogInt.number = 123;

	powertrainData_dense[12].dataLogFloat.number = 0;
	powertrainData_dense[12].dataLogInt.number = 123;

	powertrainData_dense[13].dataLogFloat.number = 0;
	powertrainData_dense[13].dataLogInt.number = 123;

	powertrainData_dense[14].dataLogFloat.number = 0;
	powertrainData_dense[14].dataLogInt.number = 123;

	powertrainData_dense[15].dataLogFloat.number = 0;
	powertrainData_dense[15].dataLogInt.number = 123;

	powertrainData_dense[16].dataLogFloat.number = 0;
	powertrainData_dense[16].dataLogInt.number = 123;

	powertrainData_dense[17].dataLogFloat.number = 0;
	powertrainData_dense[17].dataLogInt.number = 123;

	powertrainData_dense[18].dataLogFloat.number = 0;
	powertrainData_dense[18].dataLogInt.number = 123;

	powertrainData_dense[19].dataLogFloat.number = 0;
	powertrainData_dense[19].dataLogInt.number = 123;
}

void DisplayGui_Intro(void)
{
	GUI_SetTextAlign(GUI_TA_HCENTER);

	GUI_SetColor(GUI_WHITE);

	GUI_SetFont(&GUI_Font32B_1);
	GUI_DispStringAt("Powertrain Data", 236, 50);

	GUI_SetFont(&GUI_FontD80);
	GUI_DispDecAt(1, 214, 90, 1);

	GUI_SetTextAlign(GUI_TA_LEFT);

	GUI_SetColor(GUI_WHITE);
	GUI_SetBkColor(GUI_BLACK);
}
