
#define __DISPLAY_GUI_CONF_H

#define DISPLAY_GUI_REFRESH_TIME 			16  	//time in milliseconds (16 = 60 Hz)
#define DISPLAY_GUI_CLEAR_TIME				10000	//time in milliseconds

#define DISPLAY_GUI_INTRO_TIME				400		//time in milliseconds

#define DISPLAY_GUI_WARNING_BLINK_TIME		250		//time in milliseconds


#define DisplayGui_Debug_INDEX						19

#define DisplayGui_Logo_INDEX						99
//#define DisplayGui_Drive_INDEX					1
//#define DisplayGui_Endurance_INDEX				2
#define DisplayGui_Acceleration_INDEX				3
#define DisplayGui_TestDrive_INDEX					4

#define DisplayGui_Old1_INDEX						11
#define DisplayGui_Old2_INDEX						12

#define DisplayGui_Drive1_INDEX						21
#define DisplayGui_Drive2_INDEX						22

#define DisplayGui_HandlingCurvesTest_INDEX			31

#define DisplayGui_PowertrainData1_INDEX			41

#define DisplayGui_CarSetup_INDEX					51

#define DisplayGui_AntiStall_INDEX					88

#define DisplayGui_Sponsor_INDEX					90

#define DisplayGui_Alarm_INDEX						254

#define DisplayGui_NoPage_INDEX						255



#define DisplayGuiDebug 					DisplayGui_Debug_INDEX

#define GuiLogo								DisplayGui_Logo_INDEX
//#define GuiDrive							DisplayGui_Drive_INDEX
//#define GuiEndurance						DisplayGui_Endurance_INDEX
#define GuiAcceleration						DisplayGui_Acceleration_INDEX
#define GuiTestDrive						DisplayGui_TestDrive_INDEX

#define GuiOld1								DisplayGui_Old1_INDEX
#define GuiOld2								DisplayGui_Old2_INDEX

#define GuiDrive1							DisplayGui_Drive1_INDEX
#define GuiDrive2							DisplayGui_Drive2_INDEX

#define GuiHandlingCurvesTest				DisplayGui_HandlingCurvesTest_INDEX

#define GuiPowertrainData1					DisplayGui_PowertrainData1_INDEX

#define GuiCarSetup							DisplayGui_CarSetup_INDEX

#define GuiAntiStall						DisplayGui_AntiStall_INDEX
#define GuiSponsor							DisplayGui_Sponsor_INDEX

#define GuiAlarm							DisplayGui_Alarm_INDEX

#define GuiNoPage							DisplayGui_NoPage_INDEX


extern uint8_t selectedGui;
extern uint8_t selectedGui_old;
extern uint8_t introFlag;



#ifndef __MDM_GUI_LIB_H
#include "MDM_GUI_LIB.h"
#endif




#define DataLog_DataType_Int			0
#define DataLog_DataType_Float			1

typedef struct
{
	uint8_t 					enable;

	char* 						string;
	char* 						intStr;
	char* 						endStr;

	void*						dataPointer;
	GUI_DrawNumAt_DecTypeDef	dataLogInt;
	GUI_DrawNumAtTypeDef 		dataLogFloat;
	uint8_t						decimalDigits;

	uint32_t 					textColor;
	uint32_t					dataColor;
	uint32_t 					backColor;
	uint32_t 					frameColor;

	uint8_t 					dataType;
	uint8_t 					signEnable;

	uint8_t 					valueControlEnable;
	float 						maxValue;
	float						minValue;
	uint32_t					millisValueOver;
	uint16_t					minTimeValueOver;
	uint8_t						oldValueStatus;			//1 = in range, 2 = value over, 0 value under

	uint16_t					dataRefreshDelay;
	uint32_t					dataRefreshMillis;

	uint8_t						receivedDataControlEnable;
	uint32_t*					lastTimeData;
	uint16_t					noDataErrorTimerValue;

	uint32_t 					blinkingMillis;
	uint16_t 					blinkingDelayOver;
	uint16_t					blinkingDelayUnder;
	uint8_t 					blinkingStatus;
	uint8_t						blinkingState;
	uint8_t						blinkingStateOld;

	uint8_t 					blinkingFrameSize;
	uint8_t						blinkingFrameEnable;
	uint8_t						blinkingBackEnable;
	uint32_t 					blinkingOverColor;
	uint32_t 					blinkingUnderColor;

	uint32_t 					lastExeTime;

}
DisplayGui_DataGuiTypeDef;


extern float FPS;
