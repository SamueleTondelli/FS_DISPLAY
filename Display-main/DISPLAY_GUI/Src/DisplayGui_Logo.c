

#ifndef __MAIN_H
#include "main.h"
#endif

#ifndef __MDM_GUI_LIB_H
#include "MDM_GUI_LIB.h"
#endif

#ifndef __DISPLAY_GUI_CONF_H
#include "DISPLAY_GUI_Conf.h"
#endif

#ifndef __DISPLAY_GUI_H
#include "DISPLAY_GUI.h"
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmMMRLogo_480_265_8888;

extern LTDC_HandleTypeDef hltdc;

void DisplayGui_Logo(void)
{
	if(selectedGui_old != GuiLogo && DEBUG_MODE == 0)
	{
		DisplayOFF();
		GUI_SetBkColor(0x00D3D3E3);
		GUI_Clear();

#if DEBUG_MODE == 0
		GUI_DrawBitmap(&bmMMRLogo_480_265_8888, 0, (272 - bmMMRLogo_480_265_8888.YSize) - 4);
#endif

		GUI_SetBkColor(GUI_BLACK);

		HAL_Delay(100);

		DisplayON();
	}
}
