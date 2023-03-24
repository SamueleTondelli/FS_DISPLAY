

#ifndef __MAIN_H
#include "main.h"
#endif

#ifndef __MDM_GUI_LIB_H
#include "MDM_GUI_LIB.h"
#endif

#ifndef __MDM_FUNCTIONS_H
#include "MDM_Functions.h"
#endif

#ifndef __DISPLAY_GUI_CONF_H
#include "DISPLAY_GUI_Conf.h"
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmLOGO_TECHBOARD_460_76_8888;
extern GUI_CONST_STORAGE GUI_BITMAP bmMMRLogo_296_164_8888;

void DisplayGui_Sponsor(void)
{
	if(selectedGui_old != GuiSponsor)
	{
		GUI_SetBkColor(GUI_WHITE);
		GUI_Clear();

		GUI_DrawBitmap(&bmLOGO_TECHBOARD_460_76_8888, (480 - bmLOGO_TECHBOARD_460_76_8888.XSize)/2, 16);
		GUI_DrawBitmap(&bmMMRLogo_296_164_8888, (480 - bmMMRLogo_296_164_8888.XSize)/2, 16 + 2 + bmLOGO_TECHBOARD_460_76_8888.YSize);

		GUI_SetBkColor(GUI_BLACK);
	}
}
