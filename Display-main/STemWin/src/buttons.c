#include "BUTTON.h"

void Keyboard(void)
{
  //static BUTTON_Handle hButton, hButton1;
  static BUTTON_Handle b0, b1, b2, b3, b4, b5, b6, b7, b8, b9, be, bp, bm, bh, bs;

  //First row
  b1 = BUTTON_Create(230, 20, 45, 45, GUI_ID_OK, WM_CF_SHOW);
  BUTTON_SetText(b1, "1");
  BUTTON_SetFont(b1, GUI_FONT_32B_ASCII);

  b2 = BUTTON_Create(290, 20, 45, 45, GUI_ID_OK, WM_CF_SHOW);
  BUTTON_SetText(b2, "2");
  BUTTON_SetFont(b2, GUI_FONT_32B_ASCII);

  b3 = BUTTON_Create(350, 20, 45, 45, GUI_ID_OK, WM_CF_SHOW);
  BUTTON_SetText(b3, "3");
  BUTTON_SetFont(b3, GUI_FONT_32B_ASCII);

  bp = BUTTON_Create(410, 20, 45, 45, GUI_ID_OK, WM_CF_SHOW);
  BUTTON_SetText(bp, "+");
  BUTTON_SetFont(bp, GUI_FONT_32B_ASCII);

  //Second row
  b4 = BUTTON_Create(230, 80, 45, 45, GUI_ID_OK, WM_CF_SHOW);
  BUTTON_SetText(b4, "4");
  BUTTON_SetFont(b4, GUI_FONT_32B_ASCII);

  b5 = BUTTON_Create(290, 80, 45, 45, GUI_ID_OK, WM_CF_SHOW);
  BUTTON_SetText(b5, "5");
  BUTTON_SetFont(b5, GUI_FONT_32B_ASCII);

  b6 = BUTTON_Create(350, 80, 45, 45, GUI_ID_OK, WM_CF_SHOW);
  BUTTON_SetText(b6, "6");
  BUTTON_SetFont(b6, GUI_FONT_32B_ASCII);

  be = BUTTON_Create(410, 80, 45, 45, GUI_ID_OK, WM_CF_SHOW);
  BUTTON_SetText(be, "=");
  BUTTON_SetFont(be, GUI_FONT_32B_ASCII);

  //Third row
  b7 = BUTTON_Create(230, 140, 45, 45, GUI_ID_OK, WM_CF_SHOW);
  BUTTON_SetText(b7, "7");
  BUTTON_SetFont(b7, GUI_FONT_32B_ASCII);

  b8 = BUTTON_Create(290, 140, 45, 45, GUI_ID_OK, WM_CF_SHOW);
  BUTTON_SetText(b8, "8");
  BUTTON_SetFont(b8, GUI_FONT_32B_ASCII);

  b9 = BUTTON_Create(350, 140, 45, 45, GUI_ID_OK, WM_CF_SHOW);
  BUTTON_SetText(b9, "9");
  BUTTON_SetFont(b9, GUI_FONT_32B_ASCII);

  bm = BUTTON_Create(410, 140, 45, 45, GUI_ID_OK, WM_CF_SHOW);
  BUTTON_SetText(bm, "-");
  BUTTON_SetFont(bm, GUI_FONT_32B_ASCII);

  //Fourth row
  bs = BUTTON_Create(230, 200, 45, 45, GUI_ID_OK, WM_CF_SHOW);
  BUTTON_SetText(bs, "<");
  BUTTON_SetFont(bs, GUI_FONT_32B_ASCII);

  b0 = BUTTON_Create(290, 200, 45, 45, GUI_ID_OK, WM_CF_SHOW);
  BUTTON_SetText(b0, "0");
  BUTTON_SetFont(b0, GUI_FONT_32B_ASCII);

  bh = BUTTON_Create(350, 200, 105, 45, GUI_ID_OK, WM_CF_SHOW);
  BUTTON_SetText(bh, "Enter");
  BUTTON_SetFont(bh, GUI_FONT_32B_ASCII);


  GUI_Exec();
}
