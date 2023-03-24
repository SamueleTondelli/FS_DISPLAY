
#include "main.h"
#include "stm32f7xx_hal.h"

#ifndef  GUI_H
#include "GUI.h" //STEmWin
#endif

#include <string.h>

#ifndef __MDM_FUNCTIONS_H
#include "MDM_Functions.h"
#endif

#ifndef __GUI_private_function_H
#include "MDM_GUI_LIB.h"
#endif

#include <math.h>

extern GUI_CONST_STORAGE GUI_FONT GUI_FontCalibri44Balised4pp;


void GUI_accelerometer(GUI_AccelTypeDef *GUI_Accel, float gforce_x, float gforce_y)
{
	uint16_t delayRefresh = GUI_Accel->delayRefresh;
	uint32_t millisRefres = GUI_Accel->millisRefresh;

	if(millis >= millisRefres + delayRefresh)
	{
		uint8_t size = GUI_Accel->size;
		int16_t x = GUI_Accel->x;
		int16_t y = GUI_Accel->y;
		float accelerometer_max_gforce = GUI_Accel->accelerometer_max_gforce;
		uint8_t pointSize = GUI_Accel->pointSize;
		uint32_t pointColor = GUI_Accel->pointColor;
		uint32_t circleColor = GUI_Accel->circleColor;
		uint8_t circleNumber = GUI_Accel->circleNumber;
		float gforce_x_old = GUI_Accel->gforce_x_old;
		float gforce_y_old = GUI_Accel->gforce_y_old;

		int16_t fx_old = map_float(gforce_x_old, -accelerometer_max_gforce, accelerometer_max_gforce, -size*0.84, size*0.84);
		int16_t fy_old = map_float(gforce_y_old, accelerometer_max_gforce, -accelerometer_max_gforce, -size*0.84, size*0.84);

		int16_t fx = map_float(gforce_x, -accelerometer_max_gforce, accelerometer_max_gforce, -size*0.84, size*0.84);
		int16_t	fy = map_float(gforce_y, accelerometer_max_gforce, -accelerometer_max_gforce, -size*0.84, size*0.84);

		if(fx_old != fx || fy_old != fy)
		{
			GUI_SetColor(GUI_Accel->backgroundColor);
			GUI_FillCircle(x + fx_old,y + fy_old, pointSize);
		}


		GUI_Accel->gforce = sqrt(pow(gforce_x, 2) + pow(gforce_y, 2));

		if(millis > GUI_Accel->millisRefreshMaxGforce + GUI_Accel->delayRefreshMaxGforce || GUI_Accel->gforce > GUI_Accel->max_gforce)
		{
			if(GUI_Accel->gforce > GUI_Accel->max_gforce)
			{
				GUI_Accel->max_gforce = GUI_Accel->gforce;
				GUI_Accel->maxGforcePoint_x = fx;
				GUI_Accel->maxGforcePoint_y = fy;
			}
			else GUI_Accel->max_gforce = 0;

			GUI_Accel->millisRefreshMaxGforce = millis;
		}

		//if(GUI_Accel->gforce > GUI_Accel->max_gforce) GUI_Accel->max_gforce = GUI_Accel->gforce;
		if(GUI_Accel->gforce > GUI_Accel->absolute_max_gforce)
		{
			GUI_Accel->absolute_max_gforce = GUI_Accel->gforce;
			GUI_Accel->absoluteMaxGforcePoint_x = fx;
			GUI_Accel->absoluteMaxGforcePoint_y = fy;
		}


		if(GUI_Accel->old_maxGforcePoint_x != GUI_Accel->maxGforcePoint_x || GUI_Accel->old_maxGforcePoint_y != GUI_Accel->maxGforcePoint_y)
		{
			GUI_SetColor(GUI_Accel->backgroundColor);
			GUI_FillCircle(x + GUI_Accel->old_maxGforcePoint_x ,y + GUI_Accel->old_maxGforcePoint_y, GUI_Accel->maxGforcePointSize);
		}

		if(GUI_Accel->old_absoluteMaxGforcePoint_x != GUI_Accel->absoluteMaxGforcePoint_x || GUI_Accel->old_absoluteMaxGforcePoint_y != GUI_Accel->absoluteMaxGforcePoint_y)
		{
			GUI_SetColor(GUI_Accel->backgroundColor);
			GUI_FillCircle(x + GUI_Accel->old_absoluteMaxGforcePoint_x ,y + GUI_Accel->old_absoluteMaxGforcePoint_y, GUI_Accel->absoluteMaxGforcePointSize);
		}

		uint8_t colore_red = *((uint8_t *)&circleColor);
		uint8_t colore_green = *((uint8_t *)&circleColor + 1);
		uint8_t colore_blue = *((uint8_t *)&circleColor + 2);
		uint8_t colore_alpha = *((uint8_t *)&circleColor + 3);

		uint32_t colorePuntoCentrale = colore_alpha << 24 | colore_blue/3 << 16 | colore_green/3 << 8 | colore_red/3;

		GUI_SetColor(colorePuntoCentrale);
		GUI_FillCircle(x, y, pointSize);
		//GUI_DrawCircle(x, y, pointSize);

		//uint32_t coloreSecondario = colore_alpha << 24 | colore_blue/10 << 16 | colore_green/10 << 8 | colore_red/10;
		uint32_t coloreSecondario = colore_alpha << 24 | colore_blue/8 << 16 | colore_green/8 << 8 | colore_red/8;

		for(uint8_t i = 1; i <= circleNumber; i++)
		{
			GUI_SetColor(circleColor);
			GUI_DrawCircle(x, y, (size/circleNumber)*i);

			GUI_SetColor(coloreSecondario);
			GUI_DrawCircle(x, y, (size/circleNumber)*i - ((size/circleNumber)*i - (size/circleNumber)*(i-1))/2);
		}

		GUI_SetColor(pointColor);
		GUI_FillCircle(x + fx, y + fy, pointSize);

		GUI_Accel->gforce_x_old = gforce_x;
		GUI_Accel->gforce_y_old = gforce_y;

		GUI_Accel->millisRefresh = millis;

		/*
		GUI_Accel->gforce = sqrt(pow(gforce_x, 2) + pow(gforce_y, 2));

		if(millis > GUI_Accel->millisRefreshMaxGforce + GUI_Accel->delayRefreshMaxGforce || GUI_Accel->gforce > GUI_Accel->max_gforce)
		{
			if(GUI_Accel->gforce > GUI_Accel->max_gforce)
			{
				GUI_Accel->max_gforce = GUI_Accel->gforce;
				GUI_Accel->maxGforcePoint_x = fx;
				GUI_Accel->maxGforcePoint_y = fy;
			}
			else GUI_Accel->max_gforce = 0;

			GUI_Accel->millisRefreshMaxGforce = millis;
		}

		//if(GUI_Accel->gforce > GUI_Accel->max_gforce) GUI_Accel->max_gforce = GUI_Accel->gforce;
		if(GUI_Accel->gforce > GUI_Accel->absolute_max_gforce)
		{
			GUI_Accel->absolute_max_gforce = GUI_Accel->gforce;
			GUI_Accel->absoluteMaxGforcePoint_x = fx;
			GUI_Accel->absoluteMaxGforcePoint_y = fy;
		}
		*/

		/*
		if(GUI_Accel->old_maxGforcePoint_x != GUI_Accel->maxGforcePoint_x || GUI_Accel->old_maxGforcePoint_y != GUI_Accel->maxGforcePoint_y)
		{
			GUI_SetColor(GUI_Accel->backgroundColor);
			GUI_FillCircle(x + GUI_Accel->old_maxGforcePoint_x ,y + GUI_Accel->old_maxGforcePoint_y, GUI_Accel->maxGforcePointSize);
		}
		*/

		GUI_SetColor(GUI_Accel->maxGforcePointClor);
		GUI_FillCircle(x + GUI_Accel->maxGforcePoint_x, y + GUI_Accel->maxGforcePoint_y, GUI_Accel->maxGforcePointSize);

		/*
		if(GUI_Accel->old_absoluteMaxGforcePoint_x != GUI_Accel->absoluteMaxGforcePoint_x || GUI_Accel->old_absoluteMaxGforcePoint_y != GUI_Accel->absoluteMaxGforcePoint_y)
		{
			GUI_SetColor(GUI_Accel->backgroundColor);
			GUI_FillCircle(x + GUI_Accel->old_absoluteMaxGforcePoint_x ,y + GUI_Accel->old_absoluteMaxGforcePoint_y, GUI_Accel->absoluteMaxGforcePointSize);
		}
		*/

		if(GUI_Accel->absolute_max_gforce <= GUI_Accel->accelerometer_max_gforce * 1.5)
		{
			//if(GUI_Accel->absolute_max_gforce == GUI_Accel->max_gforce) GUI_SetColor((GUI_Accel->absoluteMaxGforcePointColor && GUI_Accel->maxGforcePointColor));
			//else GUI_SetColor(GUI_Accel->absoluteMaxGforcePointColor);

			GUI_SetColor(GUI_Accel->absoluteMaxGforcePointColor);
			GUI_FillCircle(x + GUI_Accel->absoluteMaxGforcePoint_x, y + GUI_Accel->absoluteMaxGforcePoint_y, GUI_Accel->absoluteMaxGforcePointSize);
		}

		GUI_Accel->old_absoluteMaxGforcePoint_x = GUI_Accel->absoluteMaxGforcePoint_x;
		GUI_Accel->old_absoluteMaxGforcePoint_y = GUI_Accel->absoluteMaxGforcePoint_y;

		GUI_Accel->old_maxGforcePoint_x = GUI_Accel->maxGforcePoint_x;
		GUI_Accel->old_maxGforcePoint_y = GUI_Accel->maxGforcePoint_y;
	}
}

void GUI_accelerometerQueue(GUI_AccelQueueTypeDef *GUI_Accel, float gforce_x, float gforce_y)
{
	uint16_t delayRefresh = GUI_Accel->delayRefresh;
	uint32_t millisRefres = GUI_Accel->millisRefresh;

	if(millis >= millisRefres + delayRefresh)
	{
		uint8_t size = GUI_Accel->size;
		int16_t x = GUI_Accel->x;
		int16_t y = GUI_Accel->y;
		float accelerometer_max_gforce = GUI_Accel->accelerometer_max_gforce;
		uint8_t pointSize = GUI_Accel->pointSize;
		uint32_t pointColor = GUI_Accel->pointColor;
		uint32_t circleColor = GUI_Accel->circleColor;
		uint8_t circleNumber = GUI_Accel->circleNumber;
		float gforce_x_old = GUI_Accel->gforce_x_old;
		float gforce_y_old = GUI_Accel->gforce_y_old;

		int16_t fx_old = map_float(gforce_x_old, -accelerometer_max_gforce, accelerometer_max_gforce, -size*0.84, size*0.84);
		int16_t fy_old = map_float(gforce_y_old, accelerometer_max_gforce, -accelerometer_max_gforce, -size*0.84, size*0.84);

		int16_t fx = map_float(gforce_x, -accelerometer_max_gforce, accelerometer_max_gforce, -size*0.84, size*0.84);
		int16_t	fy = map_float(gforce_y, accelerometer_max_gforce, -accelerometer_max_gforce, -size*0.84, size*0.84);

		if(fx_old != fx || fy_old != fy)
		{
			GUI_SetColor(GUI_Accel->backgroundColor);
			GUI_FillCircle(x + fx_old,y + fy_old, pointSize);
			//BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
			//BSP_LCD_FillCircle(x + fx, y + fy, pointSize);
		}

		GUI_Accel->gforce = sqrt(pow(gforce_x, 2) + pow(gforce_y, 2));

		if(millis >= GUI_Accel->millisRefreshMaxGforce + GUI_Accel->delayRefreshMaxGforce || GUI_Accel->gforce > GUI_Accel->max_gforce)
		{
			if(GUI_Accel->gforce >= GUI_Accel->max_gforce)
			{
				GUI_Accel->max_gforce = GUI_Accel->gforce;
				GUI_Accel->maxGforcePoint_x = fx;
				GUI_Accel->maxGforcePoint_y = fy;
			}
			else GUI_Accel->max_gforce = 0;

			GUI_Accel->millisRefreshMaxGforce = millis;
		}

		if(GUI_Accel->gforce >= GUI_Accel->absolute_max_gforce)
		{
			GUI_Accel->absolute_max_gforce = GUI_Accel->gforce;
			GUI_Accel->absoluteMaxGforcePoint_x = fx;
			GUI_Accel->absoluteMaxGforcePoint_y = fy;
		}


		if(GUI_Accel->old_maxGforcePoint_x != GUI_Accel->maxGforcePoint_x || GUI_Accel->old_maxGforcePoint_y != GUI_Accel->maxGforcePoint_y)
		{
			GUI_SetColor(GUI_Accel->backgroundColor);
			GUI_FillCircle(x + GUI_Accel->old_maxGforcePoint_x ,y + GUI_Accel->old_maxGforcePoint_y, GUI_Accel->maxGforcePointSize);
		}

		if(GUI_Accel->old_absoluteMaxGforcePoint_x != GUI_Accel->absoluteMaxGforcePoint_x || GUI_Accel->old_absoluteMaxGforcePoint_y != GUI_Accel->absoluteMaxGforcePoint_y)
		{
			GUI_SetColor(GUI_Accel->backgroundColor);
			GUI_FillCircle(x + GUI_Accel->old_absoluteMaxGforcePoint_x ,y + GUI_Accel->old_absoluteMaxGforcePoint_y, GUI_Accel->absoluteMaxGforcePointSize);
		}

		if(GUI_Accel->queueLength != 0 && GUI_Accel->queueSize != 0)
		{
			if(GUI_Accel->queueLength > GUI_accelerometerQueue_MAX_QUEUE_SIZE) GUI_Accel->queueLength = GUI_accelerometerQueue_MAX_QUEUE_SIZE;

			GUI_SetColor(GUI_Accel->queueColor);

			for(uint16_t i = 0; i < GUI_Accel->queueLength; i++)
			{
				if(GUI_Accel->queue_x[i] != 0xFFFF && GUI_Accel->queue_y[i] != 0xFFFF)
				{
					GUI_FillCircle(x + GUI_Accel->queue_x[i], y + GUI_Accel->queue_y[i], GUI_Accel->queueSize);
				}
			}

			GUI_SetColor(GUI_Accel->backgroundColor);
			//GUI_SetColor(GUI_WHITE);

			if(GUI_Accel->queue_x[GUI_Accel->queueLength - 1] != 0xFFFF && GUI_Accel->queue_y[GUI_Accel->queueLength - 1] != 0xFFFF)
			{
				GUI_FillCircle(x + GUI_Accel->queue_x[GUI_Accel->queueLength - 1], y + GUI_Accel->queue_y[GUI_Accel->queueLength - 1], GUI_Accel->queueSize);
				//BSP_LCD_FillCircle(x + GUI_Accel->queue_x[GUI_Accel->queueLength - 1], y + GUI_Accel->queue_y[GUI_Accel->queueLength - 1], GUI_Accel->queueSize);
			}


			uint8_t colore_red = *((uint8_t *)&circleColor);
			uint8_t colore_green = *((uint8_t *)&circleColor + 1);
			uint8_t colore_blue = *((uint8_t *)&circleColor + 2);
			uint8_t colore_alpha = *((uint8_t *)&circleColor + 3);

			//colore_alpha = ~colore_alpha; // for BSP_COLORS

			uint32_t colorePuntoCentrale = colore_alpha << 24 | colore_blue/3 << 16 | colore_green/3 << 8 | colore_red/3;
			//uint32_t coloreSecondario = colore_alpha << 24 | colore_blue/8 << 16 | colore_green/8 << 8 | colore_red/8;

			GUI_SetColor(colorePuntoCentrale);
			GUI_FillCircle(x, y, pointSize);
/*
			for(uint8_t i = 1; i <= circleNumber; i++)
			{
				GUI_SetColor(circleColor);
				GUI_DrawCircle(x, y, (size/circleNumber)*i);

				GUI_SetColor(coloreSecondario);
				GUI_DrawCircle(x, y, (size/circleNumber)*i - ((size/circleNumber)*i - (size/circleNumber)*(i-1))/2);
			}
			*/
/*
			BSP_LCD_SelectLayer(1);
			BSP_LCD_SetTextColor(LCD_COLOR_DARKGRAY);
			BSP_LCD_FillCircle(x, y, pointSize);
*/
			for(uint8_t i = 1; i <= circleNumber; i++)
			{
				/*
				//BSP_LCD_SetTextColor(circleColor);
				BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
				BSP_LCD_DrawCircle(x, y, (size/circleNumber)*i);

				//BSP_LCD_SetTextColor(coloreSecondario);
				BSP_LCD_SetTextColor(LCD_COLOR_DARKGRAY);
				BSP_LCD_DrawCircle(x, y, (size/circleNumber)*i - ((size/circleNumber)*i - (size/circleNumber)*(i-1))/2);
				 */
			}


			for(int16_t i = GUI_Accel->queueLength - 2; i >= -2; i--)
			{
				if(i >= 0)
				{
					GUI_Accel->queue_x[i + 1] = GUI_Accel->queue_x[i];
					GUI_Accel->queue_y[i + 1] = GUI_Accel->queue_y[i];
				}
			}

			GUI_Accel->queue_x[0] = fx;
			GUI_Accel->queue_y[0] = fy;
		}

		GUI_SetColor(pointColor);
		GUI_FillCircle(x + fx, y + fy, pointSize);

		//BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
		//BSP_LCD_FillCircle(x + fx, y + fy, pointSize);

		GUI_Accel->gforce_x_old = gforce_x;
		GUI_Accel->gforce_y_old = gforce_y;

		GUI_SetColor(GUI_Accel->maxGforcePointClor);
		GUI_FillCircle(x + GUI_Accel->maxGforcePoint_x, y + GUI_Accel->maxGforcePoint_y, GUI_Accel->maxGforcePointSize);

		if(GUI_Accel->absolute_max_gforce <= GUI_Accel->accelerometer_max_gforce * 1.5)
		{
			GUI_SetColor(GUI_Accel->absoluteMaxGforcePointColor);
			GUI_FillCircle(x + GUI_Accel->absoluteMaxGforcePoint_x, y + GUI_Accel->absoluteMaxGforcePoint_y, GUI_Accel->absoluteMaxGforcePointSize);
		}

		GUI_Accel->old_absoluteMaxGforcePoint_x = GUI_Accel->absoluteMaxGforcePoint_x;
		GUI_Accel->old_absoluteMaxGforcePoint_y = GUI_Accel->absoluteMaxGforcePoint_y;

		GUI_Accel->old_maxGforcePoint_x = GUI_Accel->maxGforcePoint_x;
		GUI_Accel->old_maxGforcePoint_y = GUI_Accel->maxGforcePoint_y;

		GUI_Accel->millisRefresh = millis;
	}
}

void GUI_Rect(GUI_RectTypeDef rect)
{
	GUI_SetColor(rect.color);
	GUI_FillRect(rect.x + rect.frameSize, rect.y + rect.frameSize, rect.x + rect.size_x - rect.frameSize, rect.y + rect.size_y - rect.frameSize);

	GUI_SetColor(rect.frameColor);

	for(uint8_t i = 0; i < rect.frameSize; i++)
	{
		GUI_DrawRect(rect.x + i, rect.y + i, rect.x + rect.size_x - i, rect.y + rect.size_y - i);
	}
}


void GUI_Bar(GUI_BarTypeDef *bar, float value)
{
	uint16_t barValue = 0;

	value = min(value, bar->maxValue);
	value = max(value, bar->minValue);

	GUI_SetColor(bar->frameColor);

	for(uint8_t i = 0; i < bar->frameSize; i++)
	{
		GUI_DrawRect(bar->x + i, bar->y - bar->size_y + i, bar->x + bar->size_x - i, bar->y - i);
	}


	switch(bar->barMode)
	{
		case GUI_BAR_DTU:
			barValue = (uint16_t) map_float(value, bar->minValue, bar->maxValue, 0, (float)bar->size_y);

			GUI_SetColor(bar->backgroundColor);
			GUI_FillRect(bar->x + bar->frameSize, bar->y - bar->size_y + bar->frameSize,  bar->x + bar->size_x - bar->frameSize,  bar->y - bar->frameSize - barValue);


			GUI_SetColor(bar->barColor);
			GUI_FillRect(bar->x + bar->frameSize, bar->y + bar->frameSize - barValue, bar->x + bar->size_x - bar->frameSize, bar->y - bar->frameSize);
			break;

		case GUI_BAR_UTD:
			barValue = (uint16_t) map_float(value, bar->minValue, bar->maxValue, 0, (float)bar->size_y);

			GUI_SetColor(bar->backgroundColor);
			GUI_FillRect(bar->x + bar->frameSize, bar->y + bar->frameSize - barValue, bar->x + bar->size_x - bar->frameSize, bar->y - bar->frameSize);

			GUI_SetColor(bar->barColor);
			GUI_FillRect(bar->x + bar->frameSize, bar->y - bar->size_y + bar->frameSize,  bar->x + bar->size_x - bar->frameSize,  bar->y - bar->frameSize - barValue);

			break;

		case GUI_BAR_LTR:
			barValue = (uint16_t) map_float(value, bar->minValue, bar->maxValue, 0, (float)bar->size_x);

			GUI_SetColor(bar->backgroundColor);
			GUI_FillRect(bar->x + barValue + bar->frameSize, bar->y - bar->size_y + bar->frameSize, bar->x + bar->size_x - bar->frameSize, bar->y - bar->frameSize);

			GUI_SetColor(bar->barColor);
			GUI_FillRect(bar->x + bar->frameSize, bar->y - bar->size_y + bar->frameSize, bar->x + barValue - bar->frameSize, bar->y - bar->frameSize);
			break;

		case GUI_BAR_RTL:
			barValue = (uint16_t) map_float(value, bar->minValue, bar->maxValue, 0, (float)bar->size_x);

			GUI_SetColor(bar->backgroundColor);
			GUI_FillRect(bar->x + bar->frameSize, bar->y - bar->size_y + bar->frameSize, bar->x + barValue - bar->frameSize, bar->y - bar->frameSize);

			GUI_SetColor(bar->barColor);
			GUI_FillRect(bar->x + barValue + bar->frameSize, bar->y - bar->size_y + bar->frameSize, bar->x + bar->size_x - bar->frameSize, bar->y - bar->frameSize);
			break;
	}




}

void GUI_Bar_OLD(GUI_BarTypeDef *GUI_Bar, float value)
{
	int16_t x = GUI_Bar->x;
	int16_t y = GUI_Bar->y;
	uint16_t size_x = GUI_Bar->size_x;
	uint16_t size_y = GUI_Bar->size_y;
	uint8_t barMode = GUI_Bar->barMode;
	uint16_t barOld = GUI_Bar->barOld;
	//float oldValue = GUI_Bar->oldValue;
	float maxValue = GUI_Bar->maxValue;
	float minValue = GUI_Bar->minValue;
	uint8_t frameSize = GUI_Bar->frameSize;
	uint32_t frameColor = GUI_Bar->frameColor;
	uint32_t barColor = GUI_Bar->barColor;
	uint32_t backgroundColor = GUI_Bar->backgroundColor;

	//uint32_t millisRefresh = GUI_Bar->millisRefresh;
	//uint16_t delayRefresh = GUI_Bar->delayRefresh;

	uint16_t dimensioneBarra = 0;

	switch(barMode)
	{
		case GUI_BAR_DTU:

			value = max(minValue, value);
			value = min(maxValue, value);

			dimensioneBarra = (uint16_t) map_float(value, minValue, maxValue, 0, (float)size_y);
			//dimensioneBarra = min_int32(dimensioneBarra, (int32_t) maxValue);
			//dimensioneBarra = max_int32(dimensioneBarra, (int32_t) minValue);

			GUI_SetColor(backgroundColor);
			GUI_FillRect(x + frameSize, y - barOld, x + size_x - frameSize, y - dimensioneBarra);

			GUI_SetColor(barColor);
			GUI_FillRect(x + frameSize, y - dimensioneBarra + frameSize, x + size_x - frameSize, y - frameSize);

			GUI_SetColor(frameColor);
			for(uint8_t i = 0; i < frameSize; i++) GUI_DrawRect(x + i, y - size_y + i, x + size_x - i, y - i);

			GUI_Bar->barOld = dimensioneBarra;

			break;

		case GUI_BAR_UTD:

			value = max(minValue, value);
			value = min(maxValue, value);

			dimensioneBarra = (uint16_t) map_float(value, minValue, maxValue, 0, (float)size_y);
			//dimensioneBarra = min_int32(dimensioneBarra, (int32_t) maxValue);
			//dimensioneBarra = max_int32(dimensioneBarra, (int32_t) minValue);

			GUI_SetColor(backgroundColor);
			//GUI_FillRect(x + frameSize, y - size_y - barOld, x + size_x - frameSize, y + barOld - dimensioneBarra);
			GUI_FillRect(x + frameSize, y - size_y + dimensioneBarra, x + size_x - frameSize, y + barOld - dimensioneBarra);

			GUI_SetColor(barColor);
			GUI_FillRect(x + frameSize, y - size_y + frameSize, x + size_x - frameSize, y - size_y + dimensioneBarra - frameSize);

			GUI_SetColor(frameColor);
			for(uint8_t i = 0; i < frameSize; i++) GUI_DrawRect(x + i, y - size_y + i, x + size_x - i, y - i);

			GUI_Bar->barOld = dimensioneBarra;

			break;

		case GUI_BAR_LTR:

			value = max(minValue, value);
			value = min(maxValue, value);

			dimensioneBarra = (uint16_t) map_float(value, minValue, maxValue, 0, (float)size_x - frameSize + 1);
			//dimensioneBarra = min_int32(dimensioneBarra, (int32_t) maxValue);
			//dimensioneBarra = max_int32(dimensioneBarra, (int32_t) minValue);

			GUI_SetColor(backgroundColor);

			int16_t appoggio_x_end = x + size_x - barOld + dimensioneBarra - frameSize;
			appoggio_x_end = min_int32(appoggio_x_end, x + size_x - frameSize);

			GUI_FillRect(x + barOld + 1, y - size_y + frameSize, appoggio_x_end, y - frameSize);

			GUI_SetColor(barColor);
			GUI_FillRect(x + frameSize, y - size_y + frameSize, x + dimensioneBarra, y - frameSize);

			GUI_SetColor(frameColor);
			for(uint8_t i = 0; i < frameSize; i++) GUI_DrawRect(x + i, y - size_y + i, x + size_x - i, y - i);

			GUI_Bar->barOld = dimensioneBarra;

			break;

		case GUI_BAR_RTL:

			value = max(minValue, value);
			value = min(maxValue, value);

			dimensioneBarra = (uint16_t) map_float(value, minValue, maxValue, 0, (float)size_x);
			//dimensioneBarra = min_int32(dimensioneBarra, (int32_t) maxValue);
			//dimensioneBarra = max_int32(dimensioneBarra, (int32_t) minValue);

			GUI_SetColor(backgroundColor);
			GUI_FillRect(x + size_x - barOld, y - size_y, x + size_x - dimensioneBarra, y);

			GUI_SetColor(barColor);
			GUI_FillRect(x + size_x - dimensioneBarra , y - size_y, x + size_x, y);

			GUI_SetColor(frameColor);
			for(uint8_t i = 0; i < frameSize; i++) GUI_DrawRect(x + i, y - size_y + i, x + size_x - i, y - i);

			GUI_Bar->barOld = dimensioneBarra;

			break;
	}
}

uint32_t GUI_ColorColdIdealHot_ARGB32(GUI_ColorCihTypeDef GUI_Color, float value, uint8_t brightness)
{
	int16_t color_red = 0;
	int16_t color_green = 0;
	int16_t color_blue = 0;
	int16_t color_alpha = 255 - brightness;

	GUI_Color.idealWindow = GUI_Color.idealWindow/2;

	if(value < GUI_Color.minValue)
	{
		color_red = 0;
		color_green = 0;
		color_blue = 255;
	}
	else if(value < GUI_Color.idealValue - GUI_Color.idealWindow)
	{
		color_red = 0;

		if(value <= GUI_Color.minValue + (GUI_Color.idealValue - GUI_Color.idealWindow)/2)
		{
			color_blue = 255;
			color_green = map_int32(value, GUI_Color.minValue, GUI_Color.minValue + (GUI_Color.idealValue - GUI_Color.idealWindow)/2, 0, 255);
			color_green = max_int32(color_green, 0);
			color_green = min_int32(color_green, 255);
		}
		else
		{
			color_green = 255;
			color_blue = map_int32(value, GUI_Color.minValue + (GUI_Color.idealValue - GUI_Color.idealWindow)/2, GUI_Color.idealValue - GUI_Color.idealWindow, 255, 0);
		}
	}
	else if(value >= GUI_Color.idealValue - GUI_Color.idealWindow && value <= GUI_Color.idealValue + GUI_Color.idealWindow)
	{
		color_red = 0;
		color_green = 255;
		color_blue = 0;
	}
	else if(value > GUI_Color.idealValue + GUI_Color.idealWindow && value < GUI_Color.maxValue * 3)
	{
		color_blue = 0;

		if(value <= GUI_Color.idealValue + GUI_Color.idealWindow + (GUI_Color.maxValue - (GUI_Color.idealValue + GUI_Color.idealWindow))/2)
		{
			color_green = 255;
			color_red = map_int32(value, GUI_Color.idealValue + GUI_Color.idealWindow, GUI_Color.idealValue + GUI_Color.idealWindow + (GUI_Color.maxValue - (GUI_Color.idealValue + GUI_Color.idealWindow))/2, 0, 255);
			color_red = max_int32(color_red, 0);
			color_red = min_int32(color_red, 255);
		}
		else
		{
			color_red = 255;
			color_green = map_int32(value, GUI_Color.maxValue, GUI_Color.idealValue + GUI_Color.idealWindow + (GUI_Color.maxValue - (GUI_Color.idealValue + GUI_Color.idealWindow))/2, 0, 255);
			color_green = max_int32(color_green, 0);
			color_green = min_int32(color_green, 255);
		}
	}
	else
	{
		color_red = 255;
		color_green = 255;
		color_blue = 255;
		color_alpha = 0;
	}

	uint32_t color = (uint8_t) color_alpha << 24 | (uint8_t) color_blue << 16 | (uint8_t) color_green << 8 | (uint8_t) color_red;

	return color;
}

void ARGB_Scomposition(uint32_t ARGB_color, uint8_t* color_alpha, uint8_t* color_red, uint8_t* color_green, uint8_t* color_blue)
{
	*color_red = *((uint8_t *)&ARGB_color);
	*color_green = *((uint8_t *)&ARGB_color + 1);
	*color_blue = *((uint8_t *)&ARGB_color + 2);
	*color_alpha = *((uint8_t *)&ARGB_color + 3);
}

void ARGB_Scomposition_1(uint32_t ARGB_color, uint8_t *componenti_ARGB)
{
	componenti_ARGB[0] = *((uint8_t *)&ARGB_color + 3);
	componenti_ARGB[1] = *((uint8_t *)&ARGB_color);
	componenti_ARGB[2] = *((uint8_t *)&ARGB_color + 1);
	componenti_ARGB[3] = *((uint8_t *)&ARGB_color + 2);
}

uint32_t ARGB_Creation(uint8_t color_alpha, uint8_t color_red, uint8_t color_green, uint8_t color_blue)
{
	uint32_t ARGB_color = (uint8_t) color_alpha << 24 | (uint8_t) color_blue << 16 | (uint8_t) color_green << 8 | (uint8_t) color_red;

	return ARGB_color;
}

uint32_t ARGB_Alteration(uint32_t color, int8_t factor)
{
	uint8_t color_red = *((uint8_t *)&color);
	uint8_t color_green = *((uint8_t *)&color + 1);
	uint8_t color_blue = *((uint8_t *)&color + 2);
	uint8_t color_alpha = *((uint8_t *)&color + 3);

	uint32_t ARGB_color = color;

	if(factor < 0)
	{
		factor = factor * -1;
		ARGB_color = (uint8_t) color_alpha << 24 | (uint8_t) color_blue/factor << 16 | (uint8_t) color_green/factor << 8 | (uint8_t) color_red/factor;
	}
	else if(factor != 0)
		ARGB_color = (uint8_t) color_alpha << 24 | (uint8_t) color_blue*factor << 16 | (uint8_t) color_green*factor << 8 | (uint8_t) color_red*factor;

	return ARGB_color;
}


#define ABSOLUTE_MAX_DIGITS 9
#define ABSOLUTE_MAX_DECIMAL_DIGITS 9
#define maxStringSize 51

void GUI_DrawNumAtAuto(int16_t x, int16_t y, const GUI_FONT *font, uint32_t color, uint32_t backColor, GUI_DrawNumAtTypeDef *data, uint8_t nDecimal, uint8_t signEnable, uint8_t alignment, char *initString, char *endString)
{
	GUI_SetBkColor(backColor);
	//GUI_SetColor(color);
	GUI_SetFont(font);

	char numToDisplay[41];

	dtoa_sign(data->number, numToDisplay, nDecimal, 0);

	char sign[2] = " ";
	uint16_t sizeOfSign = 0;

	if(signEnable)
	{
		if(signEnable == SIGN_ENABLED)
		{
			if(data->number > 0)
				sign[0] = '+';
			else if (data->number < 0)
				sign[0] = '-';
		}
		else if(signEnable == SIGN_INVERTED)
		{
			if(data->number > 0)
				sign[0] = '-';
			else if (data->number < 0)
				sign[0] = '+';
		}

		if(sign[0] != '\0')
		{
			int tmpCharSize = 0;

			font->pfGetCharDistX('+', &tmpCharSize);
			sizeOfSign += tmpCharSize;

			if(sign[0] == '+')
				sizeOfSign += 2;
			else
				sizeOfSign -= 3;

			if(!data->sizeOfSign) data->sizeOfSign = sizeOfSign; //for compatibility with older functions
		}
	}

	int8_t signCorrectionY = 0;

	if(sign[0] == '-')
		signCorrectionY = 2;

	int16_t X = 0;

	uint16_t sizeOfString = 0;

	if(numToDisplay[0] != '\0')
	{
		int tmpCharSize = 0;

		for(uint8_t i = 0; numToDisplay[i] != '\0'; i++)
		{
			font->pfGetCharDistX(numToDisplay[i], &tmpCharSize);
			sizeOfString += tmpCharSize;
		}
	}

	uint16_t sizeOfInitString = 0;

	if(initString[0] != '\0')
	{
		int tmpCharSize = 0;

		for(uint8_t i = 0; initString[i] != '\0'; i++)
		{
			font->pfGetCharDistX(initString[i], &tmpCharSize);
			sizeOfInitString += tmpCharSize;
		}
	}

	uint16_t sizeOfEndString = 0;

	if(endString[0] != '\0')
	{
		int tmpCharSize = 0;

		for(uint8_t i = 0; endString[i] != '\0'; i++)
		{
			font->pfGetCharDistX(endString[i], &tmpCharSize);
			sizeOfEndString += tmpCharSize;
		}
	}

	if(alignment == POINT) alignment = CENTER;

	switch(alignment)
	{
		case RIGHT:

			X = x - (sizeOfString + sizeOfInitString + sizeOfEndString + sizeOfSign);

			if(sizeOfString + sizeOfInitString + sizeOfEndString + sizeOfSign < data->stringSize + data->sizeOfSign + data->initStringSize + data->endStringSize)
			{
				GUI_SetColor(backColor);
				GUI_FillRect(X, y + font->LHeight*0.3, X + sizeOfString + sizeOfInitString + sizeOfEndString + sizeOfSign, y + font->LHeight + font->LHeight*0.8);
			}

			GUI_SetColor(color);
			GUI_DispStringAt(initString, X, y);
			GUI_DispStringAt(sign, X + sizeOfInitString + sizeOfSign, y - signCorrectionY);
			GUI_DispStringAt(numToDisplay, X + sizeOfInitString + sizeOfSign, y);
			GUI_DispStringAt(numToDisplay, X + sizeOfInitString + sizeOfSign + sizeOfEndString, y);

			break;

		case CENTER:

			X = x - (sizeOfString + sizeOfInitString + sizeOfEndString + sizeOfSign)/2;

			if(sizeOfString + sizeOfSign + sizeOfInitString + sizeOfEndString < data->stringSize + data->sizeOfSign + data->initStringSize + data->endStringSize)
			{
				GUI_SetColor(backColor);
				GUI_FillRect(X, y + font->LHeight*0.3, X + sizeOfString + sizeOfSign + sizeOfInitString + sizeOfEndString, y + font->LHeight + font->LHeight*0.8);
			}

			GUI_SetColor(color);
			GUI_DispStringAt(initString, X, y);
			GUI_DispStringAt(sign, X + sizeOfInitString, y - signCorrectionY);
			GUI_DispStringAt(numToDisplay, X + sizeOfInitString + sizeOfSign, y);
			GUI_DispStringAt(numToDisplay, X + sizeOfInitString + sizeOfSign + sizeOfEndString, y);

			break;

		case LEFT:
		default:

			if(sizeOfString + sizeOfSign + sizeOfInitString + sizeOfEndString < data->stringSize + data->sizeOfSign + data->initStringSize + data->endStringSize)
			{
				GUI_SetColor(backColor);
				GUI_FillRect(x, y + font->LHeight*0.3, x + sizeOfString + sizeOfSign + sizeOfInitString + sizeOfEndString, y + font->LHeight + font->LHeight*0.8);
			}

			GUI_SetColor(color);
			GUI_DispStringAt(initString, x, y);
			GUI_DispStringAt(sign, x + sizeOfInitString, y - signCorrectionY);
			GUI_DispStringAt(numToDisplay, x + sizeOfInitString + sizeOfSign, y);
			GUI_DispStringAt(numToDisplay, x + sizeOfInitString + sizeOfSign + sizeOfEndString, y);

			break;
	}

	data->stringSize = sizeOfString;
	data->initStringSize = sizeOfInitString;
	data->endStringSize = sizeOfEndString;
	data->sizeOfSign = sizeOfSign;
	data->sign = sign[0];
}


void GUI_DrawNumAt(int16_t x, int16_t y, const GUI_FONT *font, uint32_t color, uint32_t backColor, GUI_DrawNumAtTypeDef *data, int8_t nInt, uint8_t nDecimal, uint8_t signEnable, uint8_t showZero, uint8_t alignment, char *initString, char *endString)
{
	GUI_SetBkColor(backColor);
	GUI_SetColor(color);
	GUI_SetFont(font);

	//if(((nInt < 1 && nInt > -1) || nInt + nDecimal > maxStringSize - 2 || alignment > 3) || data->number > pow(10, nInt-1))
	if(((nInt < 0 && nInt != UNDEFINED_NINT) || nInt + nDecimal > maxStringSize - 2 || alignment > 3) || (nInt > 0 ? (data->number > pow(10, nInt) || data->number < -pow(10, nInt)) : false))
	{
		int xSize = 0;
		font->pfGetCharDistX('0', &xSize);

		char s[21];
		if((nInt < 0 && nInt != UNDEFINED_NINT) || nInt + nDecimal > maxStringSize - 2 || alignment > 3) strcpy(s, "UNCORRECT SETTINGS");
		else strcpy(s, "TOO HIGH NUM");

		switch(alignment)
		{
			case LEFT:
				GUI_DispStringAt(s, x, y);
				break;

			case RIGHT:
				GUI_DispStringAt(s, x - xSize * strlen(s), y);
				break;

			case CENTER:
				GUI_DispStringAt(s, x - (xSize * strlen(s) / 2), y);
				break;

			default:
				GUI_DispStringAt(s, x - (xSize * strlen(s) / 2), y);
				break;
		}

		goto END_OF_FUNCTION;
	}

	int xPointSize = 0;
	font->pfGetCharDistX('.', &xPointSize);		//funziona sul font correntemente settato (occorre settarlo prima di richiamare questa funzione)

	int xSize = 0;
	font->pfGetCharDistX('0', &xSize);			//funziona sul font correntemente settato (occorre settarlo prima di richiamare questa funzione)

	char convertedNum[maxStringSize];
	uint8_t sizeOfOldString = data->stringSize;

	/*
	if(nInt > 0 || nInt == -1)
		dtoa(data->number, convertedNum, nDecimal);
	else
		dtoa_decimalPart(data->number, convertedNum, nDecimal, true);
*/

	if(nInt > 0 || nInt == UNDEFINED_NINT)
		dtoa_sign(data->number, convertedNum, nDecimal, 0);
	else
		dtoa_decimalPart(data->number, convertedNum, nDecimal, true);

	int16_t X = 0;
	uint8_t numOfZero = 0;

	char sign[2] = " ";

	if(signEnable)
	{
		if(signEnable == SIGN_ENABLED)
		{
			if(data->number > 0)
				sign[0] = '+';
			else if (data->number < 0)
				sign[0] = '-';
		}
		else if(signEnable == SIGN_INVERTED)
		{
			if(data->number > 0)
				sign[0] = '-';
			else if (data->number < 0)
				sign[0] = '+';
		}
		else if(signEnable == SIGN_NEGATIVE)
		{
			if (data->number < 0)
				sign[0] = '-';
		}
	}

	char zero[maxStringSize] = "11111111111111111111111111111111111111111";

	char c = ' ';

	if(nInt == UNDEFINED_NINT || nInt == 0 || signEnable != SIGN_DISABLED)
			showZero = hide;

	if(showZero)
	{
		c = '0';

		int8_t h = -4;

		if(nDecimal)
			while(convertedNum[h] != '.') h++;
		else
			while(convertedNum[h] != '\0') h++;

		for (; numOfZero < (nInt - h); numOfZero++)
			zero[numOfZero] = c;

		zero[numOfZero] = '\0';

		//GUI_DispStringAt(zero, X - numOfZero * xSize, y);
	}
	else
		numOfZero = 0;

	char numToDisplay[maxStringSize];

	strcpy(numToDisplay, zero);

	uint8_t i = 0;

	while(convertedNum[i] != '\0' || numOfZero + i < maxStringSize)
	{
		numToDisplay[numOfZero + i] = convertedNum[i];
		i++;
	}

	numToDisplay[numOfZero + i] = '\0';

	/*
	if(endString[0] != '\0')
		strcpy(numToDisplay + numOfZero + i, endString);
		//GUI_SetFont(&GUI_Font16_ASCII);

	strcpy(numToDisplay, endString);
	*/

	i = 0;

	uint8_t sizeOfString = strlen(numToDisplay);

	if(sign[0] != ' ')
		sizeOfString++;

	uint16_t sizeOfInitString = 0;

	if(initString[0] != '\0')
	{
		int tmpCharSize = 0;

		for(uint8_t i = 0; initString[i] != '\0'; i++)
		{
			font->pfGetCharDistX(initString[i], &tmpCharSize);
			sizeOfInitString += tmpCharSize;
		}
	}

	uint16_t sizeOfEndString = 0;

	if(endString[0] != '\0')
	{
		int tmpCharSize = 0;

		for(uint8_t i = 0; endString[i] != '\0'; i++)
		{
			font->pfGetCharDistX(endString[i], &tmpCharSize);
			sizeOfEndString += tmpCharSize;
		}
	}

	uint16_t sizeOfStringInPixel = 0;

/*
	if((alignment == POINT || alignment == CENTER) && (sizeOfInitString[0] != "\0" || sizeOfEndString[0] != "\0"))
		alignment = LEFT;
		*/

	if(alignment == POINT && nDecimal == 0)
		alignment = RIGHT;

	switch(alignment)
	{
		case RIGHT:

			if(nDecimal) X = (x - (sizeOfString - 1) * xSize) - xPointSize - numOfZero * xSize - sizeOfEndString;
			else X = x - sizeOfString * xSize - numOfZero * xSize - sizeOfEndString;

			GUI_SetColor(color);
			GUI_DispStringAt(endString, x - sizeOfEndString, y);
			GUI_DispStringAt(initString, X - sizeOfInitString, y);

			if(sizeOfString < sizeOfOldString || sign[0] != data->sign || sizeOfEndString < data->endStringSize || sizeOfInitString < data->initStringSize)
			{
				GUI_SetColor(backColor);

				if(showZero)
					GUI_FillRect(X - sizeOfInitString, y + font->LHeight*0.3, x, y + font->LHeight + font->LHeight*0.8);
				else
					//GUI_FillRect(X - xSize * 3 - sizeOfInitString, y + font->LHeight*0.3, x, y + font->LHeight + font->LHeight*0.8);
					GUI_FillRect(X - sizeOfInitString, y + font->LHeight*0.3, x, y + font->LHeight + font->LHeight*0.8);
			}

			GUI_SetColor(color);

			if(sign[0] == ' ')
				GUI_DispStringAt(numToDisplay, X, y);
			else
			{
				GUI_DispStringAt(sign, X, y);
				GUI_DispStringAt(numToDisplay, X + xSize, y);
			}

			break;

		case CENTER:

/*
  	  	  	GUI_SetColor(backColor);

			if(nDecimal)
			{
				X = x - ((sizeOfString - 1) * xSize + xPointSize + numOfZero * xSize) / 2;

				if(sizeOfString < sizeOfOldString || numToDisplay[0] != data->sign)
					GUI_FillRect(X - (sizeOfOldString - sizeOfString) * xSize / 2, y + font->LHeight*0.3, X + (sizeOfOldString - 2) * xSize + xPointSize, y + font->LHeight + font->LHeight*0.8);
			}
			else
			{
				X = x - (sizeOfString * xSize + numOfZero * xSize) / 2;

				if(sizeOfString < sizeOfOldString || numToDisplay[0] != data->sign)
					GUI_FillRect(X - (sizeOfOldString - sizeOfString) * xSize / 2, y + font->LHeight*0.3, X + (sizeOfOldString - 2) * xSize, y + font->LHeight + font->LHeight*0.8);
			}
*/
			if(nDecimal)
				sizeOfStringInPixel = ((sizeOfString - 1) + numOfZero) * xSize + xPointSize;
			else
				sizeOfStringInPixel = (sizeOfString + numOfZero) * xSize;

			sizeOfStringInPixel += sizeOfEndString + sizeOfInitString;

			if(sizeOfStringInPixel < (sizeOfOldString - 1 + numOfZero) * xSize + xPointSize + sizeOfEndString + sizeOfInitString || sign[0] != data->sign)
			//if(sizeOfString < sizeOfOldString || sign[0] != data->sign)
			{
				GUI_SetColor(backColor);
				//GUI_SetColor(GUI_BLUE);

				if(font == &GUI_FontD32)
					GUI_FillRect(x - (sizeOfOldString) * xSize / 2, y - 2, x + (sizeOfOldString) * xSize / 2, y + 34);
				else if(font == &GUI_FontCalibri44Balised4pp)
				{
					//GUI_SetColor(GUI_GREEN);
					GUI_FillRect(x - (sizeOfOldString) * xSize / 2, y - 2, x + (sizeOfOldString) * xSize / 2, y + font->LHeight + font->LHeight*0.8);
				}
				else
					GUI_FillRect(x - (sizeOfOldString) * xSize / 2, y + font->LHeight*0.3*0, x + (sizeOfOldString) * xSize / 2, y + font->LHeight + font->LHeight*0.8);

/*
				if(font != &GUI_FontD32)
					GUI_FillRect(x - (sizeOfOldString) * xSize / 2, y + font->LHeight*0.3*0, x + (sizeOfOldString) * xSize / 2, y + font->LHeight + font->LHeight*0.8);
					//GUI_FillRect(x - ((sizeOfOldString + numOfZero) * xSize + sizeOfEndString + sizeOfInitString)/2.2, y + font->LHeight*0.3, x + ((sizeOfOldString + numOfZero) * xSize + sizeOfEndString + sizeOfInitString)/2.2, y + font->LHeight + font->LHeight*0.8);
				else
					GUI_FillRect(x - (sizeOfOldString) * xSize / 2, y - 2, x + (sizeOfOldString) * xSize / 2, y + 34);
*/
			}

			GUI_SetColor(color);
			GUI_DispStringAt(initString, x - sizeOfStringInPixel/2, y);
			GUI_DispStringAt(endString, x + (sizeOfStringInPixel/2 - sizeOfEndString), y);

			if(sign[0] == ' ')
				GUI_DispStringAt(numToDisplay, x - (sizeOfStringInPixel/2 - sizeOfInitString), y);
			else
			{
				GUI_DispStringAt(sign, x - (sizeOfStringInPixel/2 - sizeOfInitString), y);
				GUI_DispStringAt(numToDisplay, x - (sizeOfStringInPixel/2 - sizeOfInitString) + xSize, y);
			}

			break;

		case POINT:

			while(convertedNum[i] != '.') i++;

			X = x - (i + numOfZero) * xSize;

			GUI_SetColor(color);

			if(sign[0] == ' ')
				GUI_DispStringAt(numToDisplay, X, y);
			else
			{
				GUI_DispStringAt(sign, X, y);
				GUI_DispStringAt(numToDisplay, X + xSize, y);
			}

			GUI_SetColor(backColor);

			if((sizeOfString < sizeOfOldString && !numOfZero) || sign[0] != data->sign)
			{
				if(nDecimal)
					GUI_FillRect(X - (sizeOfOldString - sizeOfString - 1) * xSize / 2, y + font->LHeight*0.3, X + (sizeOfOldString - 1) * xSize + xPointSize, y + font->LHeight + font->LHeight*0.8);
				else
					GUI_FillRect(X - (sizeOfOldString - sizeOfString - 1) * xSize / 2, y + font->LHeight*0.3, X + sizeOfOldString * xSize, y + font->LHeight + font->LHeight*0.8);
			}

			//GUI_SetColor(color);
			//GUI_DispStringAt(numToDisplay, X, y);  //mettendolo qui non so perchè ma si visualizza buggato (messo sopra no)

			break;

		case LEFT:
		default:

			//section of function to write the number

			X = x + sizeOfInitString;

			if(sizeOfString < sizeOfOldString || sign[0] != data->sign)
			{
				GUI_SetColor(backColor);

				if(nDecimal)
				{
					//GUI_FillRect(X, y + font->LHeight*0.3, X + (sizeOfOldString - 1) * xSize + xPointSize, y + font->LHeight + font->LHeight*0.8);
					//GUI_FillRect(X + (sizeOfOldString - 1) * xSize + xPointSize, y + font->LHeight*0.3, X + (sizeOfOldString - 1) * xSize + xPointSize + sizeOfEndString, y + font->LHeight + font->LHeight*0.8);
					GUI_FillRect(X, y + font->LHeight*0.3, X + (sizeOfOldString - 1) * xSize + xPointSize + sizeOfEndString, y + font->LHeight + font->LHeight*0.8);
				}
				else
				{
					//GUI_FillRect(X, y + font->LHeight*0.3, X + sizeOfOldString * xSize, y + font->LHeight + font->LHeight*0.8);
					//GUI_FillRect(X + sizeOfOldString * xSize, y + font->LHeight*0.3, X + sizeOfOldString * xSize + sizeOfEndString, y + font->LHeight + font->LHeight*0.8);
					GUI_FillRect(X, y + font->LHeight*0.3, X + sizeOfOldString * xSize + sizeOfEndString, y + font->LHeight + font->LHeight*0.8);
				}
			}

			GUI_SetColor(color);

			if(sign[0] == ' ')
				GUI_DispStringAt(numToDisplay, X, y);
			else
			{
				GUI_DispStringAt(sign, X, y);
				GUI_DispStringAt(numToDisplay, X + xSize, y);
			}

			//section of function to write the initString

			if(sizeOfInitString < data->initStringSize)
			{
				GUI_SetColor(backColor);
				GUI_FillRect(x, y + font->LHeight*0.3, x + sizeOfInitString, y + font->LHeight + font->LHeight*0.8);
			}

			GUI_SetColor(color);
			GUI_DispStringAt(initString, x, y);

			//section of function to write the endString

			if(sizeOfEndString < data->endStringSize)
			{
				GUI_SetColor(backColor);

				if(nDecimal)
					GUI_FillRect(X + (sizeOfOldString - 1) * xSize + xPointSize, y + font->LHeight*0.3, X + (sizeOfOldString - 1) * xSize + xPointSize + sizeOfEndString, y + font->LHeight + font->LHeight*0.8);
				else
					GUI_FillRect(X + sizeOfOldString * xSize, y + font->LHeight*0.3, X + sizeOfOldString * xSize + sizeOfEndString, y + font->LHeight + font->LHeight*0.8);
			}

			GUI_SetColor(color);

			if(endString[0] != '\0')
			{
				if(nDecimal)
					GUI_DispStringAt(endString, X + (sizeOfString-1) * xSize + xPointSize, y);
				else
					GUI_DispStringAt(endString, X + sizeOfString * xSize, y);
			}

			break;
	}

	data->stringSize = sizeOfString;
	data->initStringSize = sizeOfInitString;
	data->endStringSize = sizeOfEndString;
	data->sign = sign[0];

	END_OF_FUNCTION:;
}


void GUI_DrawNumAtStruct(int16_t x, int16_t y, GUI_DrawNumAtStructParametersTypeDef *dataStruct, GUI_DrawNumAtTypeDef *data, char *initString, char *endString)
{
	GUI_DrawNumAt(x, y, dataStruct->font, dataStruct->color, dataStruct->backColor, data, dataStruct->nInt, dataStruct->nDecimal, dataStruct->signEnable, dataStruct->showZero, dataStruct->alignment, initString, endString);
}


void _GUI_DrawNumAt(double num)
{
	char convertedNum[21];

	if (num < 0) num *= -1;

	dtoa(num, convertedNum, 4);

	GUI_SetFont(&GUI_Font32_ASCII);
	GUI_DispStringAt(convertedNum, 239, 160);
}


#define TIME_NORMAL_CHARACTERS 		2
#define TIME_POINTS_CHARATTERS 		1
//#define TIME_CRITICAL_1 			599999	//9:59.999 (9 minutes, 59 seconds, 999 milliseconds) time in milliseconds


void GUI_DrawTimeAt(int16_t x, int16_t y, const GUI_FONT *font, uint32_t color, uint32_t backColor, GUI_DrawTimeAtTypeDef *data, int8_t format, uint8_t nDecimal, uint8_t signEnable, uint8_t alignment)
{
	GUI_SetBkColor(backColor);
	GUI_SetFont(font);

	int xPointSize = 0;
	font->pfGetCharDistX('.', &xPointSize);		//funziona sul font correntemente settato (occorre settarlo prima di richiamare questa funzione)

	int xSize = 0;
	font->pfGetCharDistX('0', &xSize);			//funziona sul font correntemente settato (occorre settarlo prima di richiamare questa funzione)

	//to avoid bugs due to incorrect input parameters
	nDecimal = max(nDecimal, 0);
	nDecimal = min(nDecimal, 3);

	uint32_t time = 0;
	//uint8_t sign = POSITIVE;
	//uint8_t signOld = POSITIVE;

	//sign calculation and abs(time)
	if(data->time < 0)
	{
		//sign = NEGATIVE;
		time = data->time * -1;
	}
	else
		time = data->time;

	uint16_t milliseconds = time - (time/1000)*1000;

	time /= 1000;

	uint8_t hours = time / 3600;
	uint16_t minutes = (time - hours * 3600) / 60;
	uint32_t seconds = (time - hours * 3600) - minutes * 60;

	switch(format)
	{
		case TIME_FORMAT_SECONDS:
			seconds = time;
			break;

		case TIME_FORMAT_MINUTES:
			minutes += hours * 60;
			break;

		case TIME_FORMAT_HOURS:
			break;

		case TIME_FORMAT_AUTO:
		default:

			if(hours)
				format = TIME_FORMAT_HOURS;
			else if(minutes)
				format = TIME_FORMAT_MINUTES;
			else
				format = TIME_FORMAT_SECONDS;

			break;
	}


	milliseconds = milliseconds / MDM_pow(10, 3 - nDecimal);

	uint8_t charNumberToAdd = 0;
	uint16_t shift = 0;

	//uint16_t yPointsCorrection = y - font->LHeight * 0.08;
	uint16_t yPointsCorrection = y;

	GUI_DrawNumAtTypeDef variableForSecondsFormat;

	switch(alignment)
	{
		case RIGHT:
			switch(format)
			{
				case TIME_FORMAT_SECONDS:

					variableForSecondsFormat.number = ((float)seconds + (float)milliseconds/1000);
					variableForSecondsFormat.sign = 0;
					variableForSecondsFormat.stringSize = data->sizeOld/xSize;
					variableForSecondsFormat.endStringSize = 0;
					variableForSecondsFormat.initStringSize = 0;
					variableForSecondsFormat.sign = '+';

					GUI_DrawNumAtAuto(x, y, font, color, backColor, &variableForSecondsFormat, 3, signEnable, RIGHT, &NO_STRING, &NO_STRING);

					break;

				case TIME_FORMAT_HOURS:

					if(hours == 0)
						charNumberToAdd = 1;
					else
					{
						for(uint8_t i = 1; i < 5; i++)
						{
							if(hours < MDM_pow(10, i))
							{
								charNumberToAdd = i;
								break;
							}
						}
					}

					if((xSize * (charNumberToAdd + 4 + nDecimal) + xPointSize * 2) < data->sizeOld)
					{
						GUI_SetColor(backColor);
						GUI_FillRect(x - data->sizeOld, y + font->LHeight*0.3, x, y + font->LHeight + font->LHeight*0.8);
					}

					GUI_SetColor(color);


					GUI_DispDecAt(hours, x - (xSize * (charNumberToAdd + 4 + nDecimal) + xPointSize * 3), y, charNumberToAdd);
					GUI_DispStringAt(":", x - (xSize * (4 + nDecimal) + xPointSize * 3), yPointsCorrection);
					GUI_DispDecAt(minutes, x - (xSize * (4 + nDecimal) + xPointSize * 2), y, 2);
					GUI_DispStringAt(":", x - (xSize * (2 + nDecimal) + xPointSize * 2), yPointsCorrection);
					GUI_DispDecAt(seconds, x - (xSize * (2 + nDecimal) + xPointSize), y, 2);

					if(nDecimal)
					{
						GUI_DispStringAt(".", x - (xSize * nDecimal + xPointSize), y);
						GUI_DispDecAt(milliseconds, x - (xSize * nDecimal), y, nDecimal);

						data->sizeOld = xSize * (charNumberToAdd + 2 + nDecimal) + xPointSize * 2;
					}
					else
						data->sizeOld = xSize * (charNumberToAdd + 2) + xPointSize;

					break;

				case TIME_FORMAT_MINUTES:
				default:

					if(minutes == 0)
						charNumberToAdd = 1;
					else
					{
						for(uint8_t i = 1; i < 10; i++)
						{
							if(minutes < MDM_pow(10, i))
							{
								charNumberToAdd = i;
								break;
							}
						}
					}

					if((xSize * (charNumberToAdd + 2 + nDecimal) + xPointSize * 2) < data->sizeOld)
					{
						GUI_SetColor(backColor);
						GUI_FillRect(x - data->sizeOld, y + font->LHeight*0.3, x, y + font->LHeight + font->LHeight*0.8);
					}

					GUI_SetColor(color);

					GUI_DispDecAt(minutes, x - (xSize * (charNumberToAdd + 2 + nDecimal) + xPointSize * 2), y, charNumberToAdd);
					GUI_DispStringAt(":", x - (xSize * (2 + nDecimal) + xPointSize * 2), yPointsCorrection);
					GUI_DispDecAt(seconds, x - (xSize * (2 + nDecimal) + xPointSize), y, 2);

					if(nDecimal)
					{
						GUI_DispStringAt(".", x - (xSize * nDecimal + xPointSize), y);
						GUI_DispDecAt(milliseconds, x - (xSize * nDecimal), y, nDecimal);

						data->sizeOld = xSize * (charNumberToAdd + 2 + nDecimal) + xPointSize * 2;
					}
					else
						data->sizeOld = xSize * (charNumberToAdd + 2) + xPointSize;

				break;
			}
			break;


		case CENTER:
			switch(format)
			{
				case TIME_FORMAT_SECONDS:

					variableForSecondsFormat.number = ((float)seconds + (float)milliseconds/1000);
					variableForSecondsFormat.stringSize = data->sizeOld;
					variableForSecondsFormat.endStringSize = 0;
					variableForSecondsFormat.initStringSize = 0;
					variableForSecondsFormat.sign = '+';

					GUI_DrawNumAtAuto(x, y, font, color, backColor, &variableForSecondsFormat, 3, signEnable, CENTER, &NO_STRING, &NO_STRING);

					break;

				case TIME_FORMAT_HOURS:

					if(hours == 0)
						charNumberToAdd = 1;
					else
					{
						for(uint8_t i = 1; i < 10; i++)
						{
							if(hours < MDM_pow(10, i))
							{
								charNumberToAdd = i;
								break;
							}
						}
					}

					if((xSize * (charNumberToAdd + 4 + nDecimal) + xPointSize * 3) < data->sizeOld)
					{
						GUI_SetColor(backColor);
						GUI_FillRect(x, y + font->LHeight*0.3, x + data->sizeOld, y + font->LHeight + font->LHeight*0.8);
					}

					GUI_SetColor(color);

					if(nDecimal)
						shift = (xSize * (charNumberToAdd + 4 + nDecimal) + xPointSize * 2) / 2;
					else
						shift = (xSize * (charNumberToAdd + 4 + nDecimal) + xPointSize) / 2;

					x -= shift;

					GUI_DispDecAt(hours, x, y, charNumberToAdd);
					GUI_DispStringAt(":", x + xSize * charNumberToAdd, yPointsCorrection);
					GUI_DispDecAt(minutes, x + xSize * charNumberToAdd + xPointSize, y, 2);
					GUI_DispStringAt(":", x + xSize * (charNumberToAdd + 2) + xPointSize, yPointsCorrection);
					GUI_DispDecAt(seconds, x  + xSize * (charNumberToAdd + 2) + xPointSize * 2, y, 2);

					if(nDecimal)
					{
						GUI_DispStringAt(".", x + xSize * (charNumberToAdd + 4) + xPointSize * 2, y);
						GUI_DispDecAt(milliseconds, x  + xSize * (charNumberToAdd + 4) + xPointSize * 3, y, nDecimal);

						data->sizeOld = xSize * (charNumberToAdd + 4 + nDecimal) + xPointSize * 3;
					}
					else
						data->sizeOld = xSize * (charNumberToAdd + 4 + nDecimal) + xPointSize * 2;

					break;

				case TIME_FORMAT_MINUTES:
				default:

					if(minutes == 0)
						charNumberToAdd = 1;
					else
					{
						for(uint8_t i = 1; i < 10; i++)
						{
							if(minutes < MDM_pow(10, i))
							{
								charNumberToAdd = i;
								break;
							}
						}
					}

					if((xSize * (charNumberToAdd + 2 + nDecimal) + xPointSize * 2) < data->sizeOld)
					{
						GUI_SetColor(backColor);
						GUI_FillRect(x, y + font->LHeight*0.3, x + data->sizeOld, y + font->LHeight + font->LHeight*0.8);
					}

					GUI_SetColor(color);

					if(nDecimal)
						shift = (xSize * (charNumberToAdd + 2 + nDecimal) + xPointSize * 2) / 2;
					else
						shift = (xSize * (charNumberToAdd + 2 + nDecimal) + xPointSize) / 2;

					x -= shift;

					GUI_DispDecAt(minutes, x, y, charNumberToAdd);
					GUI_DispStringAt(":", x + xSize * charNumberToAdd, yPointsCorrection);
					GUI_DispDecAt(seconds, x  + xSize * charNumberToAdd + xPointSize, y, 2);

					if(nDecimal)
					{
						GUI_DispStringAt(".", x + xSize * (charNumberToAdd + 2) + xPointSize, y);
						GUI_DispDecAt(milliseconds, x  + xSize * (charNumberToAdd + 2) + xPointSize * 2, y, nDecimal);

						data->sizeOld = xSize * (charNumberToAdd + 2 + nDecimal) + xPointSize * 2;
					}
					else
						data->sizeOld = xSize * (charNumberToAdd + 2 + nDecimal) + xPointSize;

					break;
			}
			break;


		case LEFT:
		default:
			switch(format)
			{
				case TIME_FORMAT_SECONDS:

					variableForSecondsFormat.number = ((float)seconds + (float)milliseconds/1000);
					variableForSecondsFormat.sign = 0;
					variableForSecondsFormat.stringSize = data->sizeOld/xSize;
					variableForSecondsFormat.endStringSize = 0;
					variableForSecondsFormat.initStringSize = 0;
					variableForSecondsFormat.sign = '+';

					GUI_DrawNumAtAuto(x, y, font, color, backColor, &variableForSecondsFormat, 3, signEnable, LEFT, &NO_STRING, &NO_STRING);

					break;

				case TIME_FORMAT_HOURS:

					if(hours == 0)
						charNumberToAdd = 1;
					else
					{
						for(uint8_t i = 1; i < 5; i++)
						{
							if(hours < MDM_pow(10, i))
							{
								charNumberToAdd = i;
								break;
							}
						}
					}

					if((xSize * (charNumberToAdd + 4 + nDecimal) + xPointSize * 3) < data->sizeOld)
					{
						GUI_SetColor(backColor);
						GUI_FillRect(x, y + font->LHeight*0.3, x + data->sizeOld, y + font->LHeight + font->LHeight*0.8);
					}

					GUI_SetColor(color);

					GUI_DispDecAt(hours, x, y, charNumberToAdd);
					GUI_DispStringAt(":", x + xSize * charNumberToAdd, yPointsCorrection);
					GUI_DispDecAt(minutes, x + xSize * charNumberToAdd + xPointSize, y, 2);
					GUI_DispStringAt(":", x + xSize * (charNumberToAdd + 2) + xPointSize, yPointsCorrection);
					GUI_DispDecAt(seconds, x  + xSize * (charNumberToAdd + 2) + xPointSize * 2, y, 2);

					if(nDecimal)
					{
						GUI_DispStringAt(".", x + xSize * (charNumberToAdd + 4) + xPointSize * 2, y);
						GUI_DispDecAt(milliseconds, x  + xSize * (charNumberToAdd + 4) + xPointSize * 3, y, nDecimal);

						data->sizeOld = xSize * (charNumberToAdd + 4 + nDecimal) + xPointSize * 3;
					}
					else
						data->sizeOld = xSize * (charNumberToAdd + 4) + xPointSize * 2;

					break;

				case TIME_FORMAT_MINUTES:
				default:

					if(minutes == 0)
						charNumberToAdd = 1;
					else
					{
						for(uint8_t i = 1; i < 10; i++)
						{
							if(minutes < MDM_pow(10, i))
							{
								charNumberToAdd = i;
								break;
							}
						}
					}

					if((xSize * (charNumberToAdd + 2 + nDecimal) + xPointSize * 2) < data->sizeOld)
					{
						GUI_SetColor(backColor);
						GUI_FillRect(x, y + font->LHeight*0.3, x + data->sizeOld, y + font->LHeight + font->LHeight*0.8);
					}

					GUI_SetColor(color);

					//GUI_DispDecAt(charNumberToAdd, x - 100, y, 1);
					//GUI_DispDecAt(minutes, x - 80, y, 3);

					GUI_DispDecAt(minutes, x, y, charNumberToAdd);
					GUI_DispStringAt(":", x + xSize * charNumberToAdd, yPointsCorrection);
					GUI_DispDecAt(seconds, x  + xSize * charNumberToAdd + xPointSize, y, 2);

					if(nDecimal)
					{
						GUI_DispStringAt(".", x + xSize * (charNumberToAdd + 2) + xPointSize, y);
						GUI_DispDecAt(milliseconds, x  + xSize * (charNumberToAdd + 2) + xPointSize * 2, y, nDecimal);

						data->sizeOld = xSize * (charNumberToAdd + 2 + nDecimal) + xPointSize * 2;
					}
					else
						data->sizeOld = xSize * (charNumberToAdd + 2 + nDecimal) + xPointSize;

					break;
			}
			break;
	}
}

void GUI_DrawNumAt_Dec(int16_t x, int16_t y, const GUI_FONT *font, uint32_t color, uint32_t backColor, GUI_DrawNumAt_DecTypeDef *data, uint8_t signEnable, uint8_t alignment, char *initString, char *endString)
{
	GUI_SetColor(color);
	GUI_SetBkColor(backColor);

	GUI_SetFont(font);

	uint32_t value = 0;

	uint8_t stringSize = 0;
	char string[51] = "";
	char stringSigned[51] = "";
	char sign[2] = " ";

	if(data->number >= 0)
	{
		value = data->number;
	}
	else
	{
		value = data->number * -1;
	}


	switch(alignment)
	{
		case LEFT:
			GUI_SetTextAlign(GUI_TA_LEFT);
			break;

		case RIGHT:
			GUI_SetTextAlign(GUI_TA_RIGHT);
			break;

		case CENTER:
			GUI_SetTextAlign(GUI_TA_HCENTER);
			break;

		default:
			GUI_SetTextAlign(GUI_TA_LEFT);
	}

	uint32_t pow = 10;
	uint8_t digit = 1;

	while(value >= pow)
	{
		pow*=10;
		digit++;
	}

	intToStr(value, string, digit);

	if(signEnable)
	{
		uint8_t flagNoSign = 0;

		if(signEnable == SIGN_ENABLED)
		{
			if(data->number > 0)
				sign[0] = '+';
			else if (data->number < 0)
				sign[0] = '-';
		}
		else if(signEnable == SIGN_INVERTED)
		{
			if(data->number > 0)
				sign[0] = '-';
			else if (data->number < 0)
				sign[0] = '+';
		}
		else if(signEnable == SIGN_NEGATIVE)
		{
			if (data->number < 0)
				sign[0] = '-';
			else
				flagNoSign = 1;
		}


		if(flagNoSign == 0 && value != 0)
		{
			stringSigned[0] = sign[0];
			strcpy(&stringSigned[1], string);
		}
		else
		{
			strcpy(&stringSigned[0], string);
		}
	}
	else
	{
		strcpy(&stringSigned[0], string);
	}


	uint8_t c = 0;
	uint8_t k = 0;
	for(k = 0; initString[k] != '\0'; k++)
	{
		string[k] = initString[k];
	}

	c = k;

	for(k = 0; stringSigned[k] != '\0'; k++)
	{
		string[c + k] = stringSigned[k];
	}

	c += k;

	for(k = 0; endString[k] != '\0'; k++)
	{
		string[c + k] = endString[k];
	}

	string[c + k] = '\0';


	int tmpCharSize = 0;
	/*
	for(uint8_t i = 0; stringSigned[i] != '\0'; i++)
	{
		font->pfGetCharDistX(stringSigned[i], &tmpCharSize);
		stringSize += tmpCharSize;
	}
	*/

	for(uint8_t i = 0; string[i] != '\0'; i++)
	{
		font->pfGetCharDistX(string[i], &tmpCharSize);
		stringSize += tmpCharSize;
	}




	if(stringSize < data->stringSize || sign[0] != data->sign)
	{
		GUI_SetColor(backColor);

		switch(alignment)
		{
			case LEFT:
				GUI_FillRect(x, y + font->LHeight*0.3, x + data->stringSize, y + font->LHeight + font->LHeight*0.8);
				break;

			case RIGHT:
				GUI_FillRect(x - data->stringSize, y + font->LHeight*0.3, x, y + font->LHeight + font->LHeight*0.8);
				break;

			case CENTER:
				GUI_FillRect(x - (data->stringSize/2 + 1), y + font->LHeight*0.3*0 - 2, x + (data->stringSize/2 + 1), y + font->LHeight + font->LHeight*0.8);
				break;

			default:
				GUI_FillRect(x, y + font->LHeight*0.3, x + data->stringSize, y + font->LHeight + font->LHeight*0.8);
		}
	}

	GUI_SetColor(color);
	GUI_DispStringAt(string, x, y);

	data->stringSize = stringSize;
	data->sign = sign[0];
}


void GUI_DrawStringAt(int16_t x, int16_t y, const GUI_FONT *font, uint32_t color, uint32_t backColor, GUI_DrawStringAtTypeDef *data, uint8_t alignment)
{
	uint16_t stringSize = 0;

	if(data->string[0] == '\0')
		goto END_OF_FUNCTION;

	GUI_SetFont(font);
	//GUI_SetColor(color);
	GUI_SetBkColor(backColor);

	int tmpCharSize = 0;

	for(uint8_t i = 0; data->string[i] != '\0'; i++)
	{
		font->pfGetCharDistX(data->string[i], &tmpCharSize);
		stringSize += tmpCharSize;
	}


	switch(alignment)
	{
		case RIGHT:

			/*
			if(stringSize != data->sizeOld)
			{

			}
			*/

			GUI_SetColor(color);
			GUI_DispStringAt(data->string, x, y);

			//GUI_FillRect(X - (sizeOfOldString - sizeOfString - 1) * xSize / 2, y + font->LHeight*0.3, X + (sizeOfOldString - 1) * xSize + xPointSize, y + font->LHeight + font->LHeight*0.8);

			break;

		case LEFT:

			GUI_SetColor(color);
			GUI_DispStringAt(data->string, x - stringSize, y);

			break;

		case CENTER:
		default:

			/*
			if(stringSize != data->sizeOld)
			{
				GUI_SetColor(backColor);
				GUI_FillRect(x - data->sizeOld/2, y, x + data->sizeOld/2, y + font->LHeight);
			}
			*/

			GUI_SetColor(color);
			GUI_DispStringAt(data->string, x - stringSize/2, y);

			break;
	}


	END_OF_FUNCTION:;

	data->sizeOld = stringSize;
}
