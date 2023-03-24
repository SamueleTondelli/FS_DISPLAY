
#ifndef __MDM_GUI_LIB_H
#define __MDM_GUI_LIB_H
#endif

#ifndef __MAIN_H
#include "main.h"
#endif

/*
#define GUI_Font32B_ASCII_xPointSize 8
#define GUI_Font32B_ASCII_xSize 15

#define GUI_Font32_ASCII_xPointSize 8
#define GUI_Font32_ASCII_xSize 15

#define GUI_Font24B_ASCII_xPointSize 6
#define GUI_Font24B_ASCII_xSize 12

#define GUI_Font24_ASCII_xPointSize 6
#define GUI_Font24_ASCII_xSize 12

#define GUI_Font20B_ASCII_xPointSize 5
#define GUI_Font20B_ASCII_xSize 10

#define GUI_Font20_ASCII_xPointSize 5
#define GUI_Font20_ASCII_xSize 10

#define GUI_Font16B_ASCII_xPointSize 4
#define GUI_Font16B_ASCII_xSize 7

#define GUI_Font16_ASCII_xPointSize 4
#define GUI_Font16_ASCII_xSize 7

#define GUI_Font13HB_ASCII_xPointSize 4
#define GUI_Font13HB_ASCII_xSize 7

#define GUI_Font13H_ASCII_xPointSize 4
#define GUI_Font13H_ASCII_xSize 7

#define GUI_Font13B_ASCII_xPointSize 3
#define GUI_Font13B_ASCII_xSize 7

#define GUI_Font13_ASCII_xPointSize 4
#define GUI_Font13_ASCII_xSize 6

#define GUI_Font10_ASCII_xPointSize 3
#define GUI_Font10_ASCII_xSize 6

#define GUI_Font10S_ASCII_xPointSize 2
#define GUI_Font10S_ASCII_xSize 5

#define GUI_Font8_ASCII_xPointSize 3
#define GUI_Font8_ASCII_xSize 6

#define GUI_FontComic24B_ASCII_xPointSize 9
#define GUI_FontComic24B_ASCII_xSize 13

#define GUI_FontComic18B_ASCII_xPointSize 4
#define GUI_FontComic18B_ASCII_xSize 10
*/

typedef struct
{
	int16_t x;
	int16_t y;
	uint16_t size;
	float gforce_x_old;
	float gforce_y_old;
	float accelerometer_max_gforce;
	uint8_t pointSize;
	uint32_t pointColor;
	uint8_t circleNumber;
	uint32_t circleColor;
	uint32_t backgroundColor;
	uint32_t millisRefresh;
	uint16_t delayRefresh;

	float absolute_max_gforce;
	float max_gforce;
	float gforce;
	uint16_t delayRefreshMaxGforce;
	uint32_t millisRefreshMaxGforce;

	int16_t maxGforcePoint_x;
	int16_t maxGforcePoint_y;
	int16_t old_maxGforcePoint_x;
	int16_t old_maxGforcePoint_y;
	uint8_t maxGforcePointSize;
	uint32_t maxGforcePointClor;

	int16_t absoluteMaxGforcePoint_x;
	int16_t absoluteMaxGforcePoint_y;
	int16_t old_absoluteMaxGforcePoint_x;
	int16_t old_absoluteMaxGforcePoint_y;
	uint8_t absoluteMaxGforcePointSize;
	uint32_t absoluteMaxGforcePointColor;

} GUI_AccelTypeDef;

void GUI_accelerometer(GUI_AccelTypeDef *GUI_Accel, float gforce_x, float gforce_y);



#define GUI_accelerometerQueue_MAX_QUEUE_SIZE 1024

typedef struct
{
	int16_t x;
	int16_t y;
	uint16_t size;
	float gforce_x_old;
	float gforce_y_old;
	float accelerometer_max_gforce;
	uint8_t pointSize;
	uint32_t pointColor;
	uint8_t circleNumber;
	uint32_t circleColor;
	uint32_t backgroundColor;
	uint32_t millisRefresh;
	uint16_t delayRefresh;

	float absolute_max_gforce;
	float max_gforce;
	float gforce;
	uint16_t delayRefreshMaxGforce;
	uint32_t millisRefreshMaxGforce;

	int16_t maxGforcePoint_x;
	int16_t maxGforcePoint_y;
	int16_t old_maxGforcePoint_x;
	int16_t old_maxGforcePoint_y;
	uint8_t maxGforcePointSize;
	uint32_t maxGforcePointClor;

	int16_t absoluteMaxGforcePoint_x;
	int16_t absoluteMaxGforcePoint_y;
	int16_t old_absoluteMaxGforcePoint_x;
	int16_t old_absoluteMaxGforcePoint_y;
	uint8_t absoluteMaxGforcePointSize;
	uint32_t absoluteMaxGforcePointColor;

	uint16_t queueLength;
	int16_t queue_x[GUI_accelerometerQueue_MAX_QUEUE_SIZE];
	int16_t queue_y[GUI_accelerometerQueue_MAX_QUEUE_SIZE];
	uint8_t queueSize;
	uint32_t queueColor;

} GUI_AccelQueueTypeDef;

void GUI_accelerometerQueue(GUI_AccelQueueTypeDef *GUI_Accel, float gforce_x, float gforce_y);


typedef struct
{
	int16_t x;
	int16_t y;
	uint16_t size_x;
	uint16_t size_y;
	uint8_t frameSize;
	uint32_t frameColor;
	uint32_t color;

} GUI_RectTypeDef;

void GUI_Rect(GUI_RectTypeDef rect);


#define GUI_BAR_UTD 0
#define GUI_BAR_DTU 1
#define GUI_BAR_LTR 2
#define GUI_BAR_RTL 3

typedef struct
{
	int16_t x;
	int16_t y;
	uint16_t size_x;
	uint16_t size_y;
	uint8_t barMode;
	uint16_t barOld;
	float oldValue;
	float maxValue;
	float minValue;
	uint8_t frameSize;
	uint32_t frameColor;
	uint32_t barColor;
	uint32_t backgroundColor;

	uint8_t alignment;

	uint32_t millisRefresh;
	uint16_t delayRefresh;

} GUI_BarTypeDef;

void GUI_Bar(GUI_BarTypeDef *GUI_Bar, float value);


typedef struct
{
	float minValue;
	float idealValue;
	float maxValue;
	float idealWindow;

} GUI_ColorCihTypeDef;

uint32_t GUI_ColorColdIdealHot_ARGB32(GUI_ColorCihTypeDef GUI_Color, float value, uint8_t brightness);

void ARGB_Scomposition(uint32_t ARGB_color, uint8_t* color_alpha, uint8_t* color_red, uint8_t* color_green, uint8_t* color_blue);
void ARGB_Scomposition_1(uint32_t ARGB_color, uint8_t *componenti_ARGB);
uint32_t ARGB_Creation(uint8_t color_alpha, uint8_t color_red, uint8_t color_green, uint8_t color_blue);
uint32_t ARGB_Alteration(uint32_t color, int8_t factor);

#define ARGB_CREATE(alpha, red, green, blue) 	(uint32_t)((uint8_t) alpha << 24 | (uint8_t) blue << 16 | (uint8_t) green << 8 | (uint8_t) red)


#define SIGN_DISABLED	0
#define SIGN_ENABLED 	1
#define SIGN_INVERTED 	2
#define SIGN_NEGATIVE	3

#define DrawNumAt_MAX_DIGITS ABSOLUTE_MAX_DIGITS
#define DrawNumAt_MAX_DECIMAL_DIGITS ABSOLUTE_MAX_DECIMAL_DIGITS

#define LEFT 0
#define RIGHT 1
#define CENTER 2
#define POINT 3
#define UNDEFINED_NINT -1

void _GUI_DrawNumAt(double num);

typedef struct
{
	double number;
	uint16_t stringSize;
	uint16_t initStringSize;
	uint16_t endStringSize;
	uint16_t sizeOfSign;
	char sign;
}GUI_DrawNumAtTypeDef;

void GUI_DrawNumAtAuto(int16_t x, int16_t y, const GUI_FONT *font, uint32_t color, uint32_t backColor, GUI_DrawNumAtTypeDef *data, uint8_t nDecimal, uint8_t signEnable, uint8_t alignment, char *initString, char *endString);
void GUI_DrawNumAt(int16_t x, int16_t y, const GUI_FONT *font, uint32_t color, uint32_t backColor, GUI_DrawNumAtTypeDef *data, int8_t nInt, uint8_t nDecimal, uint8_t signEnable, uint8_t showZero, uint8_t alignment, char *initString, char *endString);


typedef struct
{
	const GUI_FONT *font;
	uint32_t color;
	uint32_t backColor;
	int8_t nInt;
	uint8_t nDecimal;
	uint8_t signEnable;
	uint8_t showZero;
	uint8_t alignment;
}GUI_DrawNumAtStructParametersTypeDef;

void GUI_DrawNumAtStruct(int16_t x, int16_t y, GUI_DrawNumAtStructParametersTypeDef *dataStruct, GUI_DrawNumAtTypeDef *data, char *initString, char *endString);



typedef struct
{
	int32_t time;
	uint16_t sizeOld;
}GUI_DrawTimeAtTypeDef;

#define TIME_FORMAT_AUTO			0
#define TIME_FORMAT_SECONDS			1
#define TIME_FORMAT_MINUTES 		2
#define TIME_FORMAT_HOURS 			3

void GUI_DrawTimeAt(int16_t x, int16_t y, const GUI_FONT *font, uint32_t color, uint32_t backColor, GUI_DrawTimeAtTypeDef *data, int8_t format, uint8_t nDecimal, uint8_t signEnable, uint8_t alignment);


typedef struct
{
	int32_t number;
	uint16_t stringSize;
	uint16_t initStringSize;
	uint16_t endStringSize;
	uint8_t sign;
}GUI_DrawNumAt_DecTypeDef;

void GUI_DrawNumAt_Dec(int16_t x, int16_t y, const GUI_FONT *font, uint32_t color, uint32_t backColor, GUI_DrawNumAt_DecTypeDef *data, uint8_t signEnable, uint8_t alignment, char *initString, char *endString);



#define GUI_DrawStringAt_MAX_STRING_SIZE 30

typedef struct
{
	char string[GUI_DrawStringAt_MAX_STRING_SIZE + 1];
	uint16_t sizeOld;
}GUI_DrawStringAtTypeDef;

void GUI_DrawStringAt(int16_t x, int16_t y, const GUI_FONT *font, uint32_t color, uint32_t backColor, GUI_DrawStringAtTypeDef *data, uint8_t alignment);
