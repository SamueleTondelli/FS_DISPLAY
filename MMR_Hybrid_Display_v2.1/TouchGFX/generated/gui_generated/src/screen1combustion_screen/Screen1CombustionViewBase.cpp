/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1combustion_screen/Screen1CombustionViewBase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen1CombustionViewBase::Screen1CombustionViewBase()
{
    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);
    
    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    ctScreen1.setPosition(0, 0, 480, 271);
    bxBackground.setPosition(0, 0, 480, 272);
    bxBackground.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    bxBackground.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    bxBackground.setBorderSize(10);
    ctScreen1.add(bxBackground);

    ctRPM.setPosition(0, 0, 480, 272);
    bxRPMBackground.setPosition(130, 10, 340, 51);
    bxRPMBackground.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    ctRPM.add(bxRPMBackground);

    bxRPM.setPosition(134, 10, 336, 51);
    bxRPM.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    ctRPM.add(bxRPM);

    ctRPMLayout1.setPosition(0, 0, 480, 272);
    clGaugeBorderOut.setPosition(-1, -1, 272, 272);
    clGaugeBorderOut.setCenter(136, 136);
    clGaugeBorderOut.setRadius(129);
    clGaugeBorderOut.setLineWidth(0);
    clGaugeBorderOut.setArc(180, 359);
    clGaugeBorderOutPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    clGaugeBorderOut.setPainter(clGaugeBorderOutPainter);
    ctRPMLayout1.add(clGaugeBorderOut);

    ctRPM.add(ctRPMLayout1);

    clRPMBackground.setPosition(10, 10, 250, 250);
    clRPMBackground.setCenter(125, 125);
    clRPMBackground.setRadius(125);
    clRPMBackground.setLineWidth(0);
    clRPMBackground.setArc(180, 360);
    clRPMBackgroundPainter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    clRPMBackground.setPainter(clRPMBackgroundPainter);
    ctRPM.add(clRPMBackground);

    clRPM.setPosition(10, 10, 250, 250);
    clRPM.setCenter(125, 125);
    clRPM.setRadius(125);
    clRPM.setLineWidth(0);
    clRPM.setArc(180, 360);
    clRPMPainter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    clRPM.setPainter(clRPMPainter);
    ctRPM.add(clRPM);

    ctRPMLayout2.setPosition(0, 0, 480, 272);
    lnGaugeEnd.setPosition(460, 2, 20, 66);
    lnGaugeEndPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnGaugeEnd.setPainter(lnGaugeEndPainter);
    lnGaugeEnd.setStart(10, 6);
    lnGaugeEnd.setEnd(10, 59);
    lnGaugeEnd.setLineWidth(4);
    lnGaugeEnd.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctRPMLayout2.add(lnGaugeEnd);

    lnGaugeBottom.setPosition(126, 200, 88, 22);
    lnGaugeBottomPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnGaugeBottom.setPainter(lnGaugeBottomPainter);
    lnGaugeBottom.setStart(8, 8);
    lnGaugeBottom.setEnd(344, 8);
    lnGaugeBottom.setLineWidth(4);
    lnGaugeBottom.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctRPMLayout2.add(lnGaugeBottom);

    lnGaugeBottom_2.setPosition(126, 254, 89, 19);
    lnGaugeBottom_2Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnGaugeBottom_2.setPainter(lnGaugeBottom_2Painter);
    lnGaugeBottom_2.setStart(8, 8);
    lnGaugeBottom_2.setEnd(700, 8);
    lnGaugeBottom_2.setLineWidth(4.5f);
    lnGaugeBottom_2.setLineEndingStyle(touchgfx::Line::SQUARE_CAP_ENDING);
    ctRPMLayout2.add(lnGaugeBottom_2);

    lnGaugeBottom_1.setPosition(126, 54, 348, 22);
    lnGaugeBottom_1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnGaugeBottom_1.setPainter(lnGaugeBottom_1Painter);
    lnGaugeBottom_1.setStart(8, 8);
    lnGaugeBottom_1.setEnd(344, 8);
    lnGaugeBottom_1.setLineWidth(4);
    lnGaugeBottom_1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctRPMLayout2.add(lnGaugeBottom_1);

    lnGaugeTop.setPosition(125, 0, 349, 20);
    lnGaugeTopPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnGaugeTop.setPainter(lnGaugeTopPainter);
    lnGaugeTop.setStart(8, 8);
    lnGaugeTop.setEnd(344, 8);
    lnGaugeTop.setLineWidth(4);
    lnGaugeTop.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctRPMLayout2.add(lnGaugeTop);

    lnGaugeStart.setPosition(204, 203, 26, 61);
    lnGaugeStartPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnGaugeStart.setPainter(lnGaugeStartPainter);
    lnGaugeStart.setStart(10, 5);
    lnGaugeStart.setEnd(10, 60);
    lnGaugeStart.setLineWidth(4);
    lnGaugeStart.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctRPMLayout2.add(lnGaugeStart);

    clGaugeBorderIn.setPosition(10, 10, 250, 250);
    clGaugeBorderIn.setCenter(125, 125);
    clGaugeBorderIn.setRadius(75);
    clGaugeBorderIn.setLineWidth(0);
    clGaugeBorderIn.setArc(180, 360);
    clGaugeBorderInPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    clGaugeBorderIn.setPainter(clGaugeBorderInPainter);
    ctRPMLayout2.add(clGaugeBorderIn);

    clGaugeCover.setPosition(10, 10, 250, 250);
    clGaugeCover.setCenter(125, 125);
    clGaugeCover.setRadius(71);
    clGaugeCover.setLineWidth(0);
    clGaugeCover.setArc(0, 360);
    clGaugeCoverPainter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    clGaugeCover.setPainter(clGaugeCoverPainter);
    ctRPMLayout2.add(clGaugeCover);

    ctRPM.add(ctRPMLayout2);

    ctRPMNumbers.setPosition(0, -2, 480, 272);
    txtRPMTwelwe.setXY(410, 21);
    txtRPMTwelwe.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtRPMTwelwe.setLinespacing(0);
    txtRPMTwelwe.setTypedText(touchgfx::TypedText(T___SINGLEUSE_U1AQ));
    ctRPMNumbers.add(txtRPMTwelwe);

    txtRPMEleven.setXY(345, 20);
    txtRPMEleven.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtRPMEleven.setLinespacing(0);
    txtRPMEleven.setTypedText(touchgfx::TypedText(T___SINGLEUSE_PIDE));
    ctRPMNumbers.add(txtRPMEleven);

    txtRPMTen.setXY(280, 20);
    txtRPMTen.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtRPMTen.setLinespacing(0);
    txtRPMTen.setTypedText(touchgfx::TypedText(T___SINGLEUSE_UTNA));
    ctRPMNumbers.add(txtRPMTen);

    txtRPMNine.setXY(221, 20);
    txtRPMNine.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtRPMNine.setLinespacing(0);
    txtRPMNine.setTypedText(touchgfx::TypedText(T___SINGLEUSE_JMVN));
    ctRPMNumbers.add(txtRPMNine);

    txtRPMEight.setXY(160, 20);
    txtRPMEight.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtRPMEight.setLinespacing(0);
    txtRPMEight.setTypedText(touchgfx::TypedText(T___SINGLEUSE_JFWH));
    ctRPMNumbers.add(txtRPMEight);

    txtRPMSeven.setXY(106, 22);
    txtRPMSeven.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtRPMSeven.setLinespacing(0);
    txtRPMSeven.setTypedText(touchgfx::TypedText(T___SINGLEUSE_RO8U));
    ctRPMNumbers.add(txtRPMSeven);

    txtRPMSix.setXY(55, 49);
    txtRPMSix.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtRPMSix.setLinespacing(0);
    txtRPMSix.setTypedText(touchgfx::TypedText(T___SINGLEUSE_45MR));
    ctRPMNumbers.add(txtRPMSix);

    txtRPMFive.setXY(26, 101);
    txtRPMFive.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtRPMFive.setLinespacing(0);
    txtRPMFive.setTypedText(touchgfx::TypedText(T___SINGLEUSE_HMTT));
    ctRPMNumbers.add(txtRPMFive);

    txtRPMFour.setXY(35, 161);
    txtRPMFour.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtRPMFour.setLinespacing(0);
    txtRPMFour.setTypedText(touchgfx::TypedText(T___SINGLEUSE_KH9A));
    ctRPMNumbers.add(txtRPMFour);

    txtRPMThree.setXY(74, 204);
    txtRPMThree.setColor(touchgfx::Color::getColorFromRGB(255, 255, 251));
    txtRPMThree.setLinespacing(0);
    txtRPMThree.setTypedText(touchgfx::TypedText(T___SINGLEUSE_27Z9));
    ctRPMNumbers.add(txtRPMThree);

    txtRPMTwo.setXY(128, 220);
    txtRPMTwo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtRPMTwo.setLinespacing(0);
    txtRPMTwo.setTypedText(touchgfx::TypedText(T___SINGLEUSE_VZCQ));
    ctRPMNumbers.add(txtRPMTwo);

    txtRPMOne.setXY(185, 220);
    txtRPMOne.setColor(touchgfx::Color::getColorFromRGB(255, 255, 250));
    txtRPMOne.setLinespacing(0);
    txtRPMOne.setTypedText(touchgfx::TypedText(T___SINGLEUSE_0VPV));
    ctRPMNumbers.add(txtRPMOne);

    ctRPM.add(ctRPMNumbers);

    ctScreen1.add(ctRPM);

    ctValues.setPosition(221, 65, 259, 205);
    ctLeft.setPosition(0, 0, 124, 208);
    ctToil.setPosition(9, 73, 113, 60);
    boxToil.setPosition(0, 5, 113, 55);
    boxToil.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    ctToil.add(boxToil);

    lnToilDown.setPosition(-6, 50, 123, 14);
    lnToilDownPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnToilDown.setPainter(lnToilDownPainter);
    lnToilDown.setStart(8, 8);
    lnToilDown.setEnd(117, 8);
    lnToilDown.setLineWidth(4);
    lnToilDown.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctToil.add(lnToilDown);

    lnToilUp.setPosition(-6, -4, 123, 14);
    lnToilUpPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnToilUp.setPainter(lnToilUpPainter);
    lnToilUp.setStart(8, 8);
    lnToilUp.setEnd(117, 8);
    lnToilUp.setLineWidth(4);
    lnToilUp.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctToil.add(lnToilUp);

    lnToilLeft.setPosition(-3, -3, 10, 65);
    lnToilLeftPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnToilLeft.setPainter(lnToilLeftPainter);
    lnToilLeft.setStart(4, 10);
    lnToilLeft.setEnd(4, 60);
    lnToilLeft.setLineWidth(4);
    lnToilLeft.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctToil.add(lnToilLeft);

    lnToilRight.setPosition(108, -3, 10, 65);
    lnToilRightPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnToilRight.setPainter(lnToilRightPainter);
    lnToilRight.setStart(4, 10);
    lnToilRight.setEnd(4, 60);
    lnToilRight.setLineWidth(4);
    lnToilRight.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctToil.add(lnToilRight);

    lblToil.setPosition(16, 7, 75, 22);
    lblToil.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lblToil.setLinespacing(0);
    lblToil.setTypedText(touchgfx::TypedText(T___SINGLEUSE_2AOS));
    ctToil.add(lblToil);

    txtToil.setPosition(0, 27, 110, 30);
    txtToil.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtToil.setLinespacing(0);
    Unicode::snprintf(txtToilBuffer, TXTTOIL_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_T3QA).getText());
    txtToil.setWildcard(txtToilBuffer);
    txtToil.setTypedText(touchgfx::TypedText(T___SINGLEUSE_UMDE));
    ctToil.add(txtToil);

    ctLeft.add(ctToil);

    ctPoil.setPosition(9, 7, 113, 60);
    boxPoil.setPosition(0, 5, 113, 55);
    boxPoil.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    ctPoil.add(boxPoil);

    lnPoilDown.setPosition(-6, 50, 123, 14);
    lnPoilDownPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnPoilDown.setPainter(lnPoilDownPainter);
    lnPoilDown.setStart(8, 8);
    lnPoilDown.setEnd(117, 8);
    lnPoilDown.setLineWidth(4);
    lnPoilDown.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctPoil.add(lnPoilDown);

    lnPoilUp.setPosition(-6, -4, 123, 14);
    lnPoilUpPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnPoilUp.setPainter(lnPoilUpPainter);
    lnPoilUp.setStart(8, 8);
    lnPoilUp.setEnd(117, 8);
    lnPoilUp.setLineWidth(4);
    lnPoilUp.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctPoil.add(lnPoilUp);

    InPoilLeft.setPosition(-3, -3, 10, 65);
    InPoilLeftPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    InPoilLeft.setPainter(InPoilLeftPainter);
    InPoilLeft.setStart(4, 10);
    InPoilLeft.setEnd(4, 60);
    InPoilLeft.setLineWidth(4);
    InPoilLeft.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctPoil.add(InPoilLeft);

    lnPoilRight.setPosition(108, -3, 10, 65);
    lnPoilRightPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnPoilRight.setPainter(lnPoilRightPainter);
    lnPoilRight.setStart(4, 10);
    lnPoilRight.setEnd(4, 60);
    lnPoilRight.setLineWidth(4);
    lnPoilRight.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctPoil.add(lnPoilRight);

    lblPoil.setXY(13, 7);
    lblPoil.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lblPoil.setLinespacing(0);
    lblPoil.setTypedText(touchgfx::TypedText(T___SINGLEUSE_B8ND));
    ctPoil.add(lblPoil);

    txtPoil.setPosition(-2, 27, 111, 32);
    txtPoil.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtPoil.setLinespacing(0);
    Unicode::snprintf(txtPoilBuffer, TXTPOIL_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_UX8S).getText());
    txtPoil.setWildcard(txtPoilBuffer);
    txtPoil.setTypedText(touchgfx::TypedText(T___SINGLEUSE_NIAK));
    ctPoil.add(txtPoil);

    ctLeft.add(ctPoil);

    ctVbat.setPosition(9, 139, 113, 60);
    boxVbat.setPosition(0, 5, 113, 55);
    boxVbat.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    ctVbat.add(boxVbat);

    lnVbatDown.setPosition(-6, 50, 123, 14);
    lnVbatDownPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnVbatDown.setPainter(lnVbatDownPainter);
    lnVbatDown.setStart(8, 8);
    lnVbatDown.setEnd(117, 8);
    lnVbatDown.setLineWidth(4);
    lnVbatDown.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctVbat.add(lnVbatDown);

    lnVbatUp.setPosition(-6, -4, 123, 14);
    lnVbatUpPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnVbatUp.setPainter(lnVbatUpPainter);
    lnVbatUp.setStart(8, 8);
    lnVbatUp.setEnd(117, 8);
    lnVbatUp.setLineWidth(4);
    lnVbatUp.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctVbat.add(lnVbatUp);

    lnVbatLeft.setPosition(-3, -3, 10, 65);
    lnVbatLeftPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnVbatLeft.setPainter(lnVbatLeftPainter);
    lnVbatLeft.setStart(4, 10);
    lnVbatLeft.setEnd(4, 60);
    lnVbatLeft.setLineWidth(4);
    lnVbatLeft.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctVbat.add(lnVbatLeft);

    lnVbatRight.setPosition(108, -3, 10, 65);
    lnVbatRightPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnVbatRight.setPainter(lnVbatRightPainter);
    lnVbatRight.setStart(4, 10);
    lnVbatRight.setEnd(4, 60);
    lnVbatRight.setLineWidth(4);
    lnVbatRight.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctVbat.add(lnVbatRight);

    lblVbatLV.setXY(18, 7);
    lblVbatLV.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lblVbatLV.setLinespacing(0);
    lblVbatLV.setTypedText(touchgfx::TypedText(T___SINGLEUSE_8ZPL));
    ctVbat.add(lblVbatLV);

    txtVbatLV.setPosition(-1, 27, 112, 30);
    txtVbatLV.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtVbatLV.setLinespacing(0);
    Unicode::snprintf(txtVbatLVBuffer, TXTVBATLV_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_MPE5).getText());
    txtVbatLV.setWildcard(txtVbatLVBuffer);
    txtVbatLV.setTypedText(touchgfx::TypedText(T___SINGLEUSE_B8P9));
    ctVbat.add(txtVbatLV);

    ctLeft.add(ctVbat);

    ctValues.add(ctLeft);

    ctRight.setPosition(128, 0, 124, 208);
    ctPfuel.setPosition(9, 139, 113, 60);
    boxPfuel.setPosition(0, 5, 113, 55);
    boxPfuel.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    ctPfuel.add(boxPfuel);

    lnPfuelDown.setPosition(-6, 50, 123, 14);
    lnPfuelDownPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnPfuelDown.setPainter(lnPfuelDownPainter);
    lnPfuelDown.setStart(8, 8);
    lnPfuelDown.setEnd(117, 8);
    lnPfuelDown.setLineWidth(4);
    lnPfuelDown.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctPfuel.add(lnPfuelDown);

    lnPfuelUp.setPosition(-6, -4, 123, 14);
    lnPfuelUpPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnPfuelUp.setPainter(lnPfuelUpPainter);
    lnPfuelUp.setStart(8, 8);
    lnPfuelUp.setEnd(117, 8);
    lnPfuelUp.setLineWidth(4);
    lnPfuelUp.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctPfuel.add(lnPfuelUp);

    lnPfuelLeft.setPosition(-3, -3, 10, 65);
    lnPfuelLeftPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnPfuelLeft.setPainter(lnPfuelLeftPainter);
    lnPfuelLeft.setStart(4, 10);
    lnPfuelLeft.setEnd(4, 60);
    lnPfuelLeft.setLineWidth(4);
    lnPfuelLeft.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctPfuel.add(lnPfuelLeft);

    lnPfuelRight.setPosition(108, -3, 10, 65);
    lnPfuelRightPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnPfuelRight.setPainter(lnPfuelRightPainter);
    lnPfuelRight.setStart(4, 10);
    lnPfuelRight.setEnd(4, 60);
    lnPfuelRight.setLineWidth(4);
    lnPfuelRight.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctPfuel.add(lnPfuelRight);

    lblPfuel.setXY(34, 7);
    lblPfuel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lblPfuel.setLinespacing(0);
    lblPfuel.setTypedText(touchgfx::TypedText(T___SINGLEUSE_9618));
    ctPfuel.add(lblPfuel);

    txtPfuel.setPosition(-1, 27, 112, 30);
    txtPfuel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtPfuel.setLinespacing(0);
    Unicode::snprintf(txtPfuelBuffer, TXTPFUEL_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_6FZ7).getText());
    txtPfuel.setWildcard(txtPfuelBuffer);
    txtPfuel.setTypedText(touchgfx::TypedText(T___SINGLEUSE_TKTU));
    ctPfuel.add(txtPfuel);

    ctRight.add(ctPfuel);

    ctTwater.setPosition(9, 7, 113, 60);
    boxTwater.setPosition(0, 5, 113, 55);
    boxTwater.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    ctTwater.add(boxTwater);

    lnTwaterDown.setPosition(-6, 50, 123, 14);
    lnTwaterDownPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnTwaterDown.setPainter(lnTwaterDownPainter);
    lnTwaterDown.setStart(8, 8);
    lnTwaterDown.setEnd(117, 8);
    lnTwaterDown.setLineWidth(4);
    lnTwaterDown.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctTwater.add(lnTwaterDown);

    lnTwaterUp.setPosition(-6, -4, 123, 14);
    lnTwaterUpPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnTwaterUp.setPainter(lnTwaterUpPainter);
    lnTwaterUp.setStart(8, 8);
    lnTwaterUp.setEnd(117, 8);
    lnTwaterUp.setLineWidth(4);
    lnTwaterUp.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctTwater.add(lnTwaterUp);

    InTwaterLeft.setPosition(-3, -3, 10, 65);
    InTwaterLeftPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    InTwaterLeft.setPainter(InTwaterLeftPainter);
    InTwaterLeft.setStart(4, 10);
    InTwaterLeft.setEnd(4, 60);
    InTwaterLeft.setLineWidth(4);
    InTwaterLeft.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctTwater.add(InTwaterLeft);

    lnTwaterRight.setPosition(108, -3, 10, 65);
    lnTwaterRightPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnTwaterRight.setPainter(lnTwaterRightPainter);
    lnTwaterRight.setStart(4, 10);
    lnTwaterRight.setEnd(4, 60);
    lnTwaterRight.setLineWidth(4);
    lnTwaterRight.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctTwater.add(lnTwaterRight);

    lblTwaterC.setXY(13, 7);
    lblTwaterC.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lblTwaterC.setLinespacing(0);
    lblTwaterC.setTypedText(touchgfx::TypedText(T___SINGLEUSE_99UJ));
    ctTwater.add(lblTwaterC);

    txtTwaterC.setPosition(-1, 28, 112, 30);
    txtTwaterC.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtTwaterC.setLinespacing(0);
    Unicode::snprintf(txtTwaterCBuffer, TXTTWATERC_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_2LJW).getText());
    txtTwaterC.setWildcard(txtTwaterCBuffer);
    txtTwaterC.setTypedText(touchgfx::TypedText(T___SINGLEUSE_H2KM));
    ctTwater.add(txtTwaterC);

    ctRight.add(ctTwater);

    ctTair.setPosition(9, 73, 113, 60);
    boxTair.setPosition(0, 5, 113, 55);
    boxTair.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    ctTair.add(boxTair);

    lnTairDown.setPosition(-6, 50, 123, 14);
    lnTairDownPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnTairDown.setPainter(lnTairDownPainter);
    lnTairDown.setStart(8, 8);
    lnTairDown.setEnd(117, 8);
    lnTairDown.setLineWidth(4);
    lnTairDown.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctTair.add(lnTairDown);

    lnTairUp.setPosition(-6, -4, 123, 14);
    lnTairUpPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnTairUp.setPainter(lnTairUpPainter);
    lnTairUp.setStart(8, 8);
    lnTairUp.setEnd(117, 8);
    lnTairUp.setLineWidth(4);
    lnTairUp.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctTair.add(lnTairUp);

    lnTairLeft.setPosition(-3, -3, 10, 65);
    lnTairLeftPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnTairLeft.setPainter(lnTairLeftPainter);
    lnTairLeft.setStart(4, 10);
    lnTairLeft.setEnd(4, 60);
    lnTairLeft.setLineWidth(4);
    lnTairLeft.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctTair.add(lnTairLeft);

    lnTairRight.setPosition(108, -3, 10, 65);
    lnTairRightPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lnTairRight.setPainter(lnTairRightPainter);
    lnTairRight.setStart(4, 10);
    lnTairRight.setEnd(4, 60);
    lnTairRight.setLineWidth(4);
    lnTairRight.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    ctTair.add(lnTairRight);

    ITair.setPosition(8, 6, 95, 26);
    ITair.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    ITair.setLinespacing(0);
    ITair.setTypedText(touchgfx::TypedText(T___SINGLEUSE_914K));
    ctTair.add(ITair);

    txtTair.setPosition(0, 26, 110, 30);
    txtTair.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtTair.setLinespacing(0);
    Unicode::snprintf(txtTairBuffer, TXTTAIR_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_THD5).getText());
    txtTair.setWildcard(txtTairBuffer);
    txtTair.setTypedText(touchgfx::TypedText(T___SINGLEUSE_5MI2));
    ctTair.add(txtTair);

    ctRight.add(ctTair);

    ctValues.add(ctRight);

    ctScreen1.add(ctValues);

    add(ctScreen1);

    ctAlarm.setPosition(11, 11, 460, 250);
    ctAlarm.setVisible(false);
    bxAlarm.setPosition(0, 0, 460, 250);
    bxAlarm.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bxAlarm.setBorderColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    bxAlarm.setBorderSize(8);
    ctAlarm.add(bxAlarm);

    txtAlarm.setPosition(5, 5, 450, 240);
    txtAlarm.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    txtAlarm.setLinespacing(0);
    Unicode::snprintf(txtAlarmBuffer, TXTALARM_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_79R3).getText());
    txtAlarm.setWildcard(txtAlarmBuffer);
    txtAlarm.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ADVZ));
    ctAlarm.add(txtAlarm);

    add(ctAlarm);

    ctMessage.setPosition(0, 0, 480, 272);
    ctMessage.setVisible(false);
    bxMessage.setPosition(90, 61, 300, 150);
    bxMessage.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bxMessage.setBorderColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
    bxMessage.setBorderSize(5);
    ctMessage.add(bxMessage);

    txtMessage.setPosition(95, 61, 290, 150);
    txtMessage.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    txtMessage.setLinespacing(0);
    Unicode::snprintf(txtMessageBuffer, TXTMESSAGE_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_IZ4X).getText());
    txtMessage.setWildcard(txtMessageBuffer);
    txtMessage.setTypedText(touchgfx::TypedText(T___SINGLEUSE_12NF));
    ctMessage.add(txtMessage);

    add(ctMessage);

    ctScreenName.setPosition(165, 91, 150, 100);
    ctScreenName.setVisible(false);
    bxScreenName.setPosition(0, 0, 150, 100);
    bxScreenName.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bxScreenName.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 255));
    bxScreenName.setBorderSize(5);
    ctScreenName.add(bxScreenName);

    txtScreenName.setPosition(5, 25, 140, 50);
    txtScreenName.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    txtScreenName.setLinespacing(0);
    txtScreenName.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ZEHU));
    ctScreenName.add(txtScreenName);

    add(ctScreenName);

    textGear.setXY(126, 49);
    textGear.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textGear.setLinespacing(0);
    textGear.setTypedText(touchgfx::TypedText(T___SINGLEUSE_YF3A));
    add(textGear);
}

Screen1CombustionViewBase::~Screen1CombustionViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
}

void Screen1CombustionViewBase::setupScreen()
{

}
