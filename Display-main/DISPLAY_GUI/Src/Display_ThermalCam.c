

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



void camFrame(uint16_t x, uint16_t y, uint8_t pixelRow, uint8_t pixelCol, uint8_t pixelSizeX, uint8_t pixelSizeY, uint8_t frameSize, uint32_t frameColor, float *data)
{
	int16_t tempData = 0;
	uint32_t tempColor = 0;

	GUI_ColorCihTypeDef colorStructure;

	colorStructure.maxValue = 100;
	colorStructure.idealValue = 50;
	colorStructure.minValue = 0;
	colorStructure.idealWindow = 0;

	for(uint8_t r = 0; r < pixelRow; r++)
	{
		for(uint8_t c = 0; c < pixelCol; c++)
		{
			tempData = data[r + c];

			tempColor = GUI_ColorColdIdealHot_ARGB32(colorStructure, tempData, 255);

			GUI_SetColor(tempColor);
			GUI_FillRect(x + pixelSizeX * r, y + pixelSizeY * c, x + pixelSizeX * (r+1), y + pixelSizeY + pixelSizeY * (c+1));
		}
	}

	GUI_SetColor(frameColor);

	for(uint8_t i = 0; i < frameSize; i++)
	{
		GUI_FillRect(x - 1 - i, y - 1 - i, x + 1 + i + pixelRow * pixelSizeX, y + 1 + i + pixelCol * pixelSizeY);
	}

}
