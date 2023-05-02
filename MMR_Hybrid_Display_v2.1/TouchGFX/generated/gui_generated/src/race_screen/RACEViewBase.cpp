/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/race_screen/RACEViewBase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

RACEViewBase::RACEViewBase()
{
    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);
    
    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    bxBackGround.setPosition(0, 0, 480, 272);
    bxBackGround.setColor(touchgfx::Color::getColorFromRGB(13, 13, 13));
    bxBackGround.setBorderColor(touchgfx::Color::getColorFromRGB(13, 13, 13));
    bxBackGround.setBorderSize(5);
    add(bxBackGround);

    design.setPosition(0, 0, 480, 272);
    bottom_line.setPosition(-1, 265, 480, 17);
    bottom_linePainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bottom_line.setPainter(bottom_linePainter);
    bottom_line.setStart(5, 5);
    bottom_line.setEnd(480, 5);
    bottom_line.setLineWidth(4);
    bottom_line.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    design.add(bottom_line);

    left_line.setPosition(-2, -1, 33, 272);
    left_linePainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    left_line.setPainter(left_linePainter);
    left_line.setStart(4, 5);
    left_line.setEnd(4, 272);
    left_line.setLineWidth(4);
    left_line.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    design.add(left_line);

    right_line.setPosition(473, 0, 15, 272);
    right_linePainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    right_line.setPainter(right_linePainter);
    right_line.setStart(5, 0);
    right_line.setEnd(5, 272);
    right_line.setLineWidth(4);
    right_line.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    design.add(right_line);

    RPM_line.setPosition(63, 44, 354, 15);
    RPM_linePainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    RPM_line.setPainter(RPM_linePainter);
    RPM_line.setStart(5, 5);
    RPM_line.setEnd(350, 5);
    RPM_line.setLineWidth(4);
    RPM_line.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    design.add(RPM_line);

    circleWhiteLeft.setPosition(14, -59, 111, 110);
    circleWhiteLeft.setCenter(55, 55);
    circleWhiteLeft.setRadius(55);
    circleWhiteLeft.setLineWidth(0);
    circleWhiteLeft.setArc(0, 360);
    circleWhiteLeftPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    circleWhiteLeft.setPainter(circleWhiteLeftPainter);
    design.add(circleWhiteLeft);

    circleBlackLeft.setPosition(14, -59, 111, 110);
    circleBlackLeft.setCenter(55, 55);
    circleBlackLeft.setRadius(51);
    circleBlackLeft.setLineWidth(0);
    circleBlackLeft.setArc(0, 360);
    circleBlackLeftPainter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    circleBlackLeft.setPainter(circleBlackLeftPainter);
    design.add(circleBlackLeft);

    circleWhiteRight.setPosition(356, -59, 111, 110);
    circleWhiteRight.setCenter(55, 55);
    circleWhiteRight.setRadius(55);
    circleWhiteRight.setLineWidth(0);
    circleWhiteRight.setArc(0, 360);
    circleWhiteRightPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    circleWhiteRight.setPainter(circleWhiteRightPainter);
    design.add(circleWhiteRight);

    circleBlackRight.setPosition(356, -59, 111, 110);
    circleBlackRight.setCenter(55, 55);
    circleBlackRight.setRadius(51);
    circleBlackRight.setLineWidth(0);
    circleBlackRight.setArc(0, 360);
    circleBlackRightPainter.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    circleBlackRight.setPainter(circleBlackRightPainter);
    design.add(circleBlackRight);

    up_line.setPosition(-2, -3, 480, 17);
    up_linePainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    up_line.setPainter(up_linePainter);
    up_line.setStart(5, 5);
    up_line.setEnd(480, 5);
    up_line.setLineWidth(4.5f);
    up_line.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    design.add(up_line);

    bxBackGroundRPM.setPosition(75, 4, 336, 43);
    bxBackGroundRPM.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    design.add(bxBackGroundRPM);

    add(design);

    ctAlarm.setPosition(0, 0, 480, 272);
    ctAlarm.setVisible(false);
    bxAlarm.setPosition(0, 0, 480, 272);
    bxAlarm.setColor(touchgfx::Color::getColorFromRGB(3, 32, 255));
    bxAlarm.setBorderColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bxAlarm.setBorderSize(4);
    ctAlarm.add(bxAlarm);

    txtName.setXY(153, 15);
    txtName.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    txtName.setLinespacing(0);
    Unicode::snprintf(txtNameBuffer, TXTNAME_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_9YAT).getText());
    txtName.setWildcard(txtNameBuffer);
    txtName.resizeToCurrentText();
    txtName.setTypedText(touchgfx::TypedText(T___SINGLEUSE_H52F));
    ctAlarm.add(txtName);

    txtValue.setXY(93, 88);
    txtValue.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    txtValue.setLinespacing(0);
    Unicode::snprintf(txtValueBuffer, TXTVALUE_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_N4KB).getText());
    txtValue.setWildcard(txtValueBuffer);
    txtValue.resizeToCurrentText();
    txtValue.setTypedText(touchgfx::TypedText(T___SINGLEUSE_O6YU));
    ctAlarm.add(txtValue);

    add(ctAlarm);

    txtRPM.setXY(36, 10);
    txtRPM.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtRPM.setLinespacing(0);
    Unicode::snprintf(txtRPMBuffer, TXTRPM_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_U9BO).getText());
    txtRPM.setWildcard(txtRPMBuffer);
    txtRPM.resizeToCurrentText();
    txtRPM.setTypedText(touchgfx::TypedText(T___SINGLEUSE_9LZL));
    add(txtRPM);

    txtGear.setXY(194, 35);
    txtGear.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtGear.setLinespacing(0);
    Unicode::snprintf(txtGearBuffer, TXTGEAR_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_V5NR).getText());
    txtGear.setWildcard(txtGearBuffer);
    txtGear.resizeToCurrentText();
    txtGear.setTypedText(touchgfx::TypedText(T___SINGLEUSE_84RE));
    add(txtGear);

    txtSpeed.setXY(218, 151);
    txtSpeed.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtSpeed.setLinespacing(0);
    Unicode::snprintf(txtSpeedBuffer, TXTSPEED_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_KI4P).getText());
    txtSpeed.setWildcard(txtSpeedBuffer);
    txtSpeed.resizeToCurrentText();
    txtSpeed.setTypedText(touchgfx::TypedText(T___SINGLEUSE_8OZ1));
    add(txtSpeed);

    txtKmH.setXY(257, 166);
    txtKmH.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtKmH.setLinespacing(0);
    txtKmH.setTypedText(touchgfx::TypedText(T___SINGLEUSE_S8RD));
    add(txtKmH);

    line1.setPosition(13, 59, 18, 200);
    line1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    line1.setPainter(line1Painter);
    line1.setStart(5, 0);
    line1.setEnd(5, 200);
    line1.setLineWidth(4);
    line1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(line1);

    line1_2.setPosition(98, 59, 18, 200);
    line1_2Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    line1_2.setPainter(line1_2Painter);
    line1_2.setStart(5, 0);
    line1_2.setEnd(5, 200);
    line1_2.setLineWidth(4);
    line1_2.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(line1_2);

    line1_1.setPosition(180, 59, 18, 200);
    line1_1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    line1_1.setPainter(line1_1Painter);
    line1_1.setStart(5, 0);
    line1_1.setEnd(5, 200);
    line1_1.setLineWidth(4);
    line1_1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(line1_1);

    line2.setPosition(16, 53, 174, 17);
    line2Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    line2.setPainter(line2Painter);
    line2.setStart(0, 5);
    line2.setEnd(169, 5);
    line2.setLineWidth(4);
    line2.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(line2);

    line2_2.setPosition(16, 122, 178, 15);
    line2_2Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    line2_2.setPainter(line2_2Painter);
    line2_2.setStart(0, 5);
    line2_2.setEnd(169, 5);
    line2_2.setLineWidth(4);
    line2_2.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(line2_2);

    line2_2_1.setPosition(16, 188, 174, 18);
    line2_2_1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    line2_2_1.setPainter(line2_2_1Painter);
    line2_2_1.setStart(0, 5);
    line2_2_1.setEnd(169, 5);
    line2_2_1.setLineWidth(4);
    line2_2_1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(line2_2_1);

    line2_1.setPosition(16, 252, 174, 50);
    line2_1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    line2_1.setPainter(line2_1Painter);
    line2_1.setStart(0, 5);
    line2_1.setEnd(169, 5);
    line2_1.setLineWidth(4);
    line2_1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(line2_1);

    txtFuelP.setXY(43, 217);
    txtFuelP.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtFuelP.setLinespacing(0);
    Unicode::snprintf(txtFuelPBuffer, TXTFUELP_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_49HN).getText());
    txtFuelP.setWildcard(txtFuelPBuffer);
    txtFuelP.resizeToCurrentText();
    txtFuelP.setTypedText(touchgfx::TypedText(T___SINGLEUSE_EGUV));
    add(txtFuelP);

    txtFuelT.setXY(43, 151);
    txtFuelT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtFuelT.setLinespacing(0);
    Unicode::snprintf(txtFuelTBuffer, TXTFUELT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_CEPX).getText());
    txtFuelT.setWildcard(txtFuelTBuffer);
    txtFuelT.resizeToCurrentText();
    txtFuelT.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ZVOS));
    add(txtFuelT);

    txtOilP.setXY(44, 81);
    txtOilP.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtOilP.setLinespacing(0);
    Unicode::snprintf(txtOilPBuffer, TXTOILP_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_R3H0).getText());
    txtOilP.setWildcard(txtOilPBuffer);
    txtOilP.resizeToCurrentText();
    txtOilP.setTypedText(touchgfx::TypedText(T___SINGLEUSE_4C61));
    add(txtOilP);

    nameFuelP.setXY(29, 195);
    nameFuelP.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nameFuelP.setLinespacing(0);
    nameFuelP.setTypedText(touchgfx::TypedText(T___SINGLEUSE_M7PW));
    add(nameFuelP);

    nameFuelT.setXY(27, 128);
    nameFuelT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nameFuelT.setLinespacing(0);
    nameFuelT.setTypedText(touchgfx::TypedText(T___SINGLEUSE_U72G));
    add(nameFuelT);

    nameOilP.setXY(36, 59);
    nameOilP.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nameOilP.setLinespacing(0);
    nameOilP.setTypedText(touchgfx::TypedText(T___SINGLEUSE_JVCJ));
    add(nameOilP);

    txtWaterT.setXY(126, 151);
    txtWaterT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtWaterT.setLinespacing(0);
    Unicode::snprintf(txtWaterTBuffer, TXTWATERT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_4SPB).getText());
    txtWaterT.setWildcard(txtWaterTBuffer);
    txtWaterT.resizeToCurrentText();
    txtWaterT.setTypedText(touchgfx::TypedText(T___SINGLEUSE_N325));
    add(txtWaterT);

    txtOilT.setXY(126, 81);
    txtOilT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtOilT.setLinespacing(0);
    Unicode::snprintf(txtOilTBuffer, TXTOILT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_REBG).getText());
    txtOilT.setWildcard(txtOilTBuffer);
    txtOilT.resizeToCurrentText();
    txtOilT.setTypedText(touchgfx::TypedText(T___SINGLEUSE_GTHP));
    add(txtOilT);

    txtAirT.setXY(126, 217);
    txtAirT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtAirT.setLinespacing(0);
    Unicode::snprintf(txtAirTBuffer, TXTAIRT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_2KZX).getText());
    txtAirT.setWildcard(txtAirTBuffer);
    txtAirT.resizeToCurrentText();
    txtAirT.setTypedText(touchgfx::TypedText(T___SINGLEUSE_O840));
    add(txtAirT);

    nameAirT.setXY(114, 195);
    nameAirT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nameAirT.setLinespacing(0);
    nameAirT.setTypedText(touchgfx::TypedText(T___SINGLEUSE_T4I7));
    add(nameAirT);

    nameOilT.setXY(115, 59);
    nameOilT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nameOilT.setLinespacing(0);
    nameOilT.setTypedText(touchgfx::TypedText(T___SINGLEUSE_QYDU));
    add(nameOilT);

    nameWaterT.setXY(111, 129);
    nameWaterT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nameWaterT.setLinespacing(0);
    nameWaterT.setTypedText(touchgfx::TypedText(T___SINGLEUSE_MPHM));
    add(nameWaterT);
}

RACEViewBase::~RACEViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
}

void RACEViewBase::setupScreen()
{

}
