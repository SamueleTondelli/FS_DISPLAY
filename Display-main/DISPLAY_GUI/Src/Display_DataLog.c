

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


static void Display_DataLogFrame(void);
static void Display_DataLogArmature(void);

void Display_DenseDataLogArmature(void);

/*
extern GUI_CONST_STORAGE GUI_BITMAP bmGEARBOX_N;
extern GUI_CONST_STORAGE GUI_BITMAP bmGEARBOX_1;
extern GUI_CONST_STORAGE GUI_BITMAP bmGEARBOX_2;
extern GUI_CONST_STORAGE GUI_BITMAP bmGEARBOX_3;
extern GUI_CONST_STORAGE GUI_BITMAP bmGEARBOX_4;
*/



void Display_DataLog(DisplayGui_DataGuiTypeDef *data, uint8_t density)
{
	//CORE FUNCTION BEGIN

	// RPM BAR BEGIN

	Display_OldRpmBar_STD(rpm);

	// RPM BAR END

	uint16_t x = 0;
	uint16_t y = 0;

	uint8_t c = 0;
	uint8_t r = 0;

	int16_t data_y_offset = 0;
	int16_t text_y_offset = 0;

	uint8_t debugCounter = 0;

	uint8_t dataNumber = 0;

	switch(density)
	{
		case 0:
			dataNumber = 12;
			break;

		case 1:
			dataNumber = 20;
			break;

		default:
			dataNumber = 12;

	}

	uint32_t tempBackColor = 0;
	uint32_t tempFrameColor = 0;

	uint8_t tempBackBlinkEnble = 0;

	for(uint8_t i = 0; i < dataNumber; i++)
	{
		if(data[i].enable == ENABLE)
		{
			uint8_t frameSize = data[i].blinkingFrameSize;

			debugCounter++;

			tempBackColor = data[i].backColor;
			tempFrameColor = data[i].frameColor;

			GUI_SetColor(data[i].textColor);
			GUI_SetBkColor(data[i].backColor);

			switch(density)
			{
			/*
				case 0:
					r = i / 4;
					c = i - r * 4;

					x = 2 + c * 119;
					y = 24 + r * 82;

					data_y_offset = 36;
					text_y_offset = 6;
					break;
					*/

				case 1:
					r = i / 4;
					c = i - r * 4;

					x = 2 + c * 119;
					y = 24 + r * 49;

					data_y_offset = 17;
					text_y_offset = 1;
					break;

				case 0:
				default:
					r = i / 4;
					c = i - r * 4;

					x = 2 + c * 119;
					y = 24 + r * 82;

					data_y_offset = 36;
					text_y_offset = 6;
			}



			if(data[i].valueControlEnable == DISABLE)
			{
				//GUI_SetColor(data[i].frameColor);
				tempFrameColor = data[i].frameColor;
				data[i].blinkingStatus = 0;
				data[i].blinkingState = 0;
			}
			else
			{
				if(data[i].dataLogFloat.number >= data[i].maxValue)
				{
					data[i].blinkingStatus = 1;
				}
				else if(data[i].dataLogFloat.number <= data[i].minValue)
				{
					data[i].blinkingStatus = 2;
				}
				else
				{
					//GUI_SetColor(data[i].frameColor);
					tempFrameColor = data[i].frameColor;
					data[i].blinkingStatus = 0;
					data[i].blinkingState = 0;
				}
			}

			if(data[i].blinkingStatus != 0)
			{
				if((millis >= data[i].blinkingMillis + data[i].blinkingDelayOver && data[i].blinkingStatus == 1)
					|| (millis >= data[i].blinkingMillis + data[i].blinkingDelayUnder && data[i].blinkingStatus == 2))
				{
					if(data[i].blinkingState == 0)
						data[i].blinkingState = 1;
					else
						data[i].blinkingState = 0;

					data[i].blinkingMillis = millis;

					tempBackBlinkEnble = 1;
				}
				else
				{
					tempBackBlinkEnble = 0;
				}
			}

			if(data[i].blinkingState == 0)
			{
				tempFrameColor = data[i].frameColor;
			}
			else
			{
				if(data[i].blinkingStatus == 1)
				{
					if(data[i].blinkingFrameEnable)
						tempFrameColor = data[i].blinkingOverColor;
					else
						tempFrameColor = data[i].frameColor;

					if(data[i].blinkingBackEnable)
						tempBackColor = data[i].blinkingOverColor;
				}
				else if (data[i].blinkingStatus == 2)
				{
					if(data[i].blinkingFrameEnable)
						tempFrameColor = data[i].blinkingUnderColor;
					else
						tempFrameColor = data[i].frameColor;

					if(data[i].blinkingBackEnable)
						tempBackColor = data[i].blinkingUnderColor;
				}
			}

			if(data[i].blinkingBackEnable && tempBackBlinkEnble)
			{
				GUI_SetColor(tempBackColor);

				switch(density)
				{
					case 1:
						GUI_FillRect(x + frameSize, y + frameSize, x + 119 - frameSize, y + 49 - frameSize);
						break;

					case 0:
					default:
						GUI_FillRect(x + frameSize, y + frameSize, x + 119 - frameSize, y + 82 - frameSize);
				}
			}

			GUI_SetColor(data[i].textColor);
			//GUI_SetBkColor(data[i].backColor);
			GUI_SetBkColor(tempBackColor);
			GUI_SetFont(&GUI_Font20_1);
			GUI_SetTextAlign(GUI_TA_HCENTER);

			GUI_DispStringAt(data[i].string, x + 59, y + text_y_offset);

			if(data[i].dataType == DataLog_DataType_Float)
				GUI_DrawNumAt(x + 57, y + data_y_offset, &GUI_Font32_1, data[i].dataColor, tempBackColor, &data[i].dataLogFloat, UNDEFINED_NINT, data[i].decimalDigits, data[i].signEnable, DISABLE, CENTER, data[i].intStr, data[i].endStr);
			else
				GUI_DrawNumAt_Dec(x + 57, y + data_y_offset, &GUI_Font32_1, data[i].dataColor, tempBackColor, &data[i].dataLogInt, data[i].signEnable, CENTER, data[i].intStr, data[i].endStr);


			GUI_SetColor(tempFrameColor);

			switch(density)
			{
				case 1:
					if(frameSize > 5)	frameSize = 5;

					for(uint8_t f = 1; f <= frameSize; f++)
					{
						GUI_DrawRect(x + f, y + f, x + 119 - f, y + 49 - f);
					}

					break;

				case 0:
				default:
					if(frameSize > 10)	frameSize = 10;

					for(uint8_t f = 1; f <= frameSize; f++)
					{
						GUI_DrawRect(x + f, y + f, x + 119 - f, y + 82 - f);
					}

			}

		}


		data[i].lastExeTime = millis;
	}

	GUI_SetColor(GUI_WHITE);

	Display_DataLogFrame();

	switch(density)
	{
		case 1:
			Display_DenseDataLogArmature();
			break;

		case 0:
		default:
			Display_DataLogArmature();
	}



	//CORE FUNCTION END
}



void Display_DataLogFrame(void)
{
	GUI_SetColor(GUI_WHITE);

	//main rect (frame)
	GUI_DrawRect(1, 1, 479, 271);
	GUI_DrawRect(2, 2, 478, 270);

	//GUI_AA_DisableHiRes();
	//GUI_SetPenSize(1);
}


void Display_DataLogArmature(void)
{
	GUI_SetColor(GUI_GRAY);

	uint16_t y = 24;
	uint16_t x = 2;

	GUI_DrawLine(3, y, 477, y);
	y += 82;
	GUI_DrawLine(3, y, 477, y);
	y += 82;
	GUI_DrawLine(3, y, 477, y);

	y = 24;

	x = 121;
	GUI_DrawLine(x, y, x, 270);
	x += 119;
	GUI_DrawLine(x, y, x, 270);
	x += 119;
	GUI_DrawLine(x, y, x, 270);
}


void Display_DenseDataLogArmature(void)
{
	GUI_SetColor(GUI_GRAY);

	static uint16_t y = 49;		//(272-27)/5;

	for(uint8_t i = 0; i < 6; i++)
	{
		GUI_DrawLine(3, 24 + y*i, 477, 24 + y*i);
	}

	static uint16_t x = 119;	//(480-4)/4;

	for(uint8_t i = 0; i < 4; i++)
	{
		GUI_DrawLine(2 + x*i, 24, 2 + x*i, 270);
	}
}
