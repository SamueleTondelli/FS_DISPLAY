

#ifndef __MAIN_H
#include "main.h"
#endif

#ifndef __MDM_GUI_LIB_H
#include "MDM_GUI_LIB.h"
#endif


void DisplayGui_Debug(void)
{
	GUI_SetColor(GUI_RED);
	GUI_SetFont(&GUI_Font32_1);
	GUI_DispStringAt(" Gui_Debug! ", (LCD_GetXSize()-150)/2, (LCD_GetYSize()-20)/2);
	GUI_SetColor(GUI_BLUE);

	char* a = "";
	char* b = "";

	static GUI_DrawNumAtTypeDef temperatura_mcu = {0};
	temperatura_mcu.number = MCU_Temperature;
	a = "MCU Temp: ";
	b = " C";
	GUI_DrawNumAt(10, 160, &GUI_Font32_1, GUI_WHITE, GUI_BLACK, &temperatura_mcu, 2, 1, ENABLE, ENABLE, LEFT, a, b);

	/*
	static GUI_DrawNumAtTypeDef vrefInt_mcu = {0};
	vrefInt_mcu.number = MCU_VrefInt;
	a = "MCU Int VRef: ";
	b = " V";
	GUI_DrawNumAt(10, 190, &GUI_Font32_1, GUI_WHITE, GUI_BLACK, &vrefInt_mcu, 1, 3, ENABLE, ENABLE, LEFT, a, b);
	 */

	static GUI_DrawTimeAtTypeDef timeToDisplay = {0};
	timeToDisplay.time = millis;

	GUI_DrawTimeAt((LCD_GetXSize())/2, (LCD_GetYSize())/2 - 60, &GUI_Font32_1, GUI_GREEN, GUI_BLACK, &timeToDisplay, TIME_FORMAT_HOURS, 3, DISABLE, CENTER);
}
