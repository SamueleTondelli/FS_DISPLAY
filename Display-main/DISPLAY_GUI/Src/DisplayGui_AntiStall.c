

#ifndef __MAIN_H
#include "main.h"
#endif

#ifndef __MDM_GUI_LIB_H
#include "MDM_GUI_LIB.h"
#endif


extern GUI_CONST_STORAGE GUI_BITMAP bmantistall;

void DisplayGui_AntiStall(void)
{
	/*
	GUI_SetColor(GUI_WHITE);

	//main rect (frame)
	GUI_DrawRect(0, 0, 480, 272);
	GUI_DrawRect(1, 1, 479, 271);

	//GUI_SetColor(GUI_RED);
	GUI_SetColor(GUI_WHITE);
	GUI_FillRect(2, 2, 478, 270);

	GUI_SetColor(GUI_BLACK);
	GUI_SetBkColor(GUI_WHITE);
	GUI_SetFont(&GUI_Font32_1);
	GUI_DispStringAt("ANTI - STALL", (LCD_GetXSize()-150)/2, (LCD_GetYSize()-20)/2);
	GUI_SetBkColor(GUI_BLACK);

	//GUI_DrawStringAt();

	 */


	GUI_DrawBitmap(&bmantistall, 0, 0);
}
