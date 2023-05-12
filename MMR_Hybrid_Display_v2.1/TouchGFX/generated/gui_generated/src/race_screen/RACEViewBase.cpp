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
    bxBackGround.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    bxBackGround.setBorderColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    bxBackGround.setBorderSize(5);
    add(bxBackGround);

    up_line.setPosition(-3, -4, 484, 19);
    up_linePainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    up_line.setPainter(up_linePainter);
    up_line.setStart(0, 5);
    up_line.setEnd(480, 5);
    up_line.setLineWidth(2);
    up_line.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(up_line);

    rpm_line.setPosition(-3, 30, 484, 19);
    rpm_linePainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    rpm_line.setPainter(rpm_linePainter);
    rpm_line.setStart(0, 5);
    rpm_line.setEnd(480, 5);
    rpm_line.setLineWidth(2);
    rpm_line.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(rpm_line);

    design_line_2.setPosition(-3, 136, 201, 17);
    design_line_2Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    design_line_2.setPainter(design_line_2Painter);
    design_line_2.setStart(0, 5);
    design_line_2.setEnd(190, 5);
    design_line_2.setLineWidth(2);
    design_line_2.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(design_line_2);

    design_line_2_1.setPosition(-3, 71, 201, 17);
    design_line_2_1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    design_line_2_1.setPainter(design_line_2_1Painter);
    design_line_2_1.setStart(0, 5);
    design_line_2_1.setEnd(190, 5);
    design_line_2_1.setLineWidth(2);
    design_line_2_1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(design_line_2_1);

    design_line_5.setPosition(292, 136, 201, 17);
    design_line_5Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    design_line_5.setPainter(design_line_5Painter);
    design_line_5.setStart(0, 5);
    design_line_5.setEnd(186, 5);
    design_line_5.setLineWidth(2);
    design_line_5.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(design_line_5);

    design_line_5_1.setPosition(292, 71, 201, 17);
    design_line_5_1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    design_line_5_1.setPainter(design_line_5_1Painter);
    design_line_5_1.setStart(0, 5);
    design_line_5_1.setEnd(186, 5);
    design_line_5_1.setLineWidth(2);
    design_line_5_1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(design_line_5_1);

    design_line_1.setPosition(-3, 200, 484, 19);
    design_line_1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    design_line_1.setPainter(design_line_1Painter);
    design_line_1.setStart(0, 5);
    design_line_1.setEnd(480, 5);
    design_line_1.setLineWidth(2);
    design_line_1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(design_line_1);

    right_line.setPosition(473, 0, 15, 272);
    right_linePainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    right_line.setPainter(right_linePainter);
    right_line.setStart(5, 0);
    right_line.setEnd(5, 272);
    right_line.setLineWidth(2);
    right_line.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(right_line);

    left_line.setPosition(-3, -1, 33, 272);
    left_linePainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    left_line.setPainter(left_linePainter);
    left_line.setStart(4, 0);
    left_line.setEnd(4, 272);
    left_line.setLineWidth(2);
    left_line.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(left_line);

    design_line_4.setPosition(184, 34, 15, 237);
    design_line_4Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    design_line_4.setPainter(design_line_4Painter);
    design_line_4.setStart(4, 0);
    design_line_4.setEnd(4, 238);
    design_line_4.setLineWidth(2);
    design_line_4.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(design_line_4);

    design_line_4_1.setPosition(92, 77, 15, 193);
    design_line_4_1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    design_line_4_1.setPainter(design_line_4_1Painter);
    design_line_4_1.setStart(4, 0);
    design_line_4_1.setEnd(4, 195);
    design_line_4_1.setLineWidth(2);
    design_line_4_1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(design_line_4_1);

    design_line_4_1_1.setPosition(380, 77, 15, 193);
    design_line_4_1_1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    design_line_4_1_1.setPainter(design_line_4_1_1Painter);
    design_line_4_1_1.setStart(4, 0);
    design_line_4_1_1.setEnd(4, 195);
    design_line_4_1_1.setLineWidth(2);
    design_line_4_1_1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(design_line_4_1_1);

    design_line_3.setPosition(289, 34, 15, 238);
    design_line_3Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    design_line_3.setPainter(design_line_3Painter);
    design_line_3.setStart(4, 0);
    design_line_3.setEnd(4, 238);
    design_line_3.setLineWidth(2);
    design_line_3.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(design_line_3);

    bottom_line.setPosition(-3, 266, 483, 18);
    bottom_linePainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    bottom_line.setPainter(bottom_linePainter);
    bottom_line.setStart(0, 5);
    bottom_line.setEnd(480, 5);
    bottom_line.setLineWidth(2);
    bottom_line.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(bottom_line);

    txtSpeed.setXY(320, 102);
    txtSpeed.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtSpeed.setLinespacing(0);
    Unicode::snprintf(txtSpeedBuffer, TXTSPEED_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_Q09Y).getText());
    txtSpeed.setWildcard(txtSpeedBuffer);
    txtSpeed.resizeToCurrentText();
    txtSpeed.setTypedText(touchgfx::TypedText(T___SINGLEUSE_HMAS));
    add(txtSpeed);

    txtBrake.setXY(412, 102);
    txtBrake.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtBrake.setLinespacing(0);
    Unicode::snprintf(txtBrakeBuffer, TXTBRAKE_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_JBTV).getText());
    txtBrake.setWildcard(txtBrakeBuffer);
    txtBrake.resizeToCurrentText();
    txtBrake.setTypedText(touchgfx::TypedText(T___SINGLEUSE_QLAJ));
    add(txtBrake);

    txtGear.setXY(187, 44);
    txtGear.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtGear.setLinespacing(0);
    Unicode::snprintf(txtGearBuffer, TXTGEAR_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_HQNO).getText());
    txtGear.setWildcard(txtGearBuffer);
    txtGear.resizeToCurrentText();
    txtGear.setTypedText(touchgfx::TypedText(T___SINGLEUSE_MS3Z));
    add(txtGear);

    txtRPM.setXY(193, 38);
    txtRPM.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtRPM.setLinespacing(0);
    Unicode::snprintf(txtRPMBuffer, TXTRPM_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_LXD6).getText());
    txtRPM.setWildcard(txtRPMBuffer);
    txtRPM.resizeToCurrentText();
    txtRPM.setTypedText(touchgfx::TypedText(T___SINGLEUSE_J6X0));
    add(txtRPM);

    txtVbat.setXY(412, 233);
    txtVbat.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtVbat.setLinespacing(0);
    Unicode::snprintf(txtVbatBuffer, TXTVBAT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_NLN8).getText());
    txtVbat.setWildcard(txtVbatBuffer);
    txtVbat.resizeToCurrentText();
    txtVbat.setTypedText(touchgfx::TypedText(T___SINGLEUSE_RN8V));
    add(txtVbat);

    nameVbat.setXY(400, 204);
    nameVbat.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nameVbat.setLinespacing(0);
    nameVbat.setTypedText(touchgfx::TypedText(T___SINGLEUSE_8SFQ));
    add(nameVbat);

    nameWaterT.setXY(17, 140);
    nameWaterT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nameWaterT.setLinespacing(0);
    nameWaterT.setTypedText(touchgfx::TypedText(T___SINGLEUSE_GR3A));
    add(nameWaterT);

    nameOilT.setXY(24, 75);
    nameOilT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nameOilT.setLinespacing(0);
    nameOilT.setTypedText(touchgfx::TypedText(T___SINGLEUSE_D469));
    add(nameOilT);

    nameAirT.setXY(23, 204);
    nameAirT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nameAirT.setLinespacing(0);
    nameAirT.setTypedText(touchgfx::TypedText(T___SINGLEUSE_3W2Q));
    add(nameAirT);

    txtAirT.setXY(31, 233);
    txtAirT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtAirT.setLinespacing(0);
    Unicode::snprintf(txtAirTBuffer, TXTAIRT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_91PD).getText());
    txtAirT.setWildcard(txtAirTBuffer);
    txtAirT.resizeToCurrentText();
    txtAirT.setTypedText(touchgfx::TypedText(T___SINGLEUSE_MCD3));
    add(txtAirT);

    txtOilT.setXY(31, 102);
    txtOilT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtOilT.setLinespacing(0);
    Unicode::snprintf(txtOilTBuffer, TXTOILT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_IN9Q).getText());
    txtOilT.setWildcard(txtOilTBuffer);
    txtOilT.resizeToCurrentText();
    txtOilT.setTypedText(touchgfx::TypedText(T___SINGLEUSE_7HCT));
    add(txtOilT);

    txtWaterT.setXY(31, 170);
    txtWaterT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtWaterT.setLinespacing(0);
    Unicode::snprintf(txtWaterTBuffer, TXTWATERT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_WSEE).getText());
    txtWaterT.setWildcard(txtWaterTBuffer);
    txtWaterT.resizeToCurrentText();
    txtWaterT.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ZZGT));
    add(txtWaterT);

    nameOilP.setXY(115, 75);
    nameOilP.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nameOilP.setLinespacing(0);
    nameOilP.setTypedText(touchgfx::TypedText(T___SINGLEUSE_4VY7));
    add(nameOilP);

    nameFuelT.setXY(107, 204);
    nameFuelT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nameFuelT.setLinespacing(0);
    nameFuelT.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ZQHQ));
    add(nameFuelT);

    nameFuelP.setXY(107, 140);
    nameFuelP.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nameFuelP.setLinespacing(0);
    nameFuelP.setTypedText(touchgfx::TypedText(T___SINGLEUSE_5QSF));
    add(nameFuelP);

    txtOilP.setXY(122, 102);
    txtOilP.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtOilP.setLinespacing(0);
    Unicode::snprintf(txtOilPBuffer, TXTOILP_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_DM48).getText());
    txtOilP.setWildcard(txtOilPBuffer);
    txtOilP.resizeToCurrentText();
    txtOilP.setTypedText(touchgfx::TypedText(T___SINGLEUSE_0BM4));
    add(txtOilP);

    txtFuelT.setXY(122, 167);
    txtFuelT.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtFuelT.setLinespacing(0);
    Unicode::snprintf(txtFuelTBuffer, TXTFUELT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_U5OS).getText());
    txtFuelT.setWildcard(txtFuelTBuffer);
    txtFuelT.resizeToCurrentText();
    txtFuelT.setTypedText(touchgfx::TypedText(T___SINGLEUSE_6LK1));
    add(txtFuelT);

    txtFuelP.setXY(122, 233);
    txtFuelP.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtFuelP.setLinespacing(0);
    Unicode::snprintf(txtFuelPBuffer, TXTFUELP_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_UL1S).getText());
    txtFuelP.setWildcard(txtFuelPBuffer);
    txtFuelP.resizeToCurrentText();
    txtFuelP.setTypedText(touchgfx::TypedText(T___SINGLEUSE_F3ZL));
    add(txtFuelP);

    nameSteeringWheel.setXY(401, 140);
    nameSteeringWheel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nameSteeringWheel.setLinespacing(0);
    nameSteeringWheel.setTypedText(touchgfx::TypedText(T___SINGLEUSE_0YAC));
    add(nameSteeringWheel);

    txtTps.setXY(222, 233);
    txtTps.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtTps.setLinespacing(0);
    Unicode::snprintf(txtTpsBuffer, TXTTPS_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_KC09).getText());
    txtTps.setWildcard(txtTpsBuffer);
    txtTps.resizeToCurrentText();
    txtTps.setTypedText(touchgfx::TypedText(T___SINGLEUSE_S478));
    add(txtTps);

    txtMap.setXY(305, 233);
    txtMap.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtMap.setLinespacing(0);
    Unicode::snprintf(txtMapBuffer, TXTMAP_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_Q0D2).getText());
    txtMap.setWildcard(txtMapBuffer);
    txtMap.resizeToCurrentText();
    txtMap.setTypedText(touchgfx::TypedText(T___SINGLEUSE_O97M));
    add(txtMap);

    nameMap.setXY(315, 204);
    nameMap.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nameMap.setLinespacing(0);
    nameMap.setTypedText(touchgfx::TypedText(T___SINGLEUSE_HZBY));
    add(nameMap);

    nameTps.setXY(219, 204);
    nameTps.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nameTps.setLinespacing(0);
    nameTps.setTypedText(touchgfx::TypedText(T___SINGLEUSE_42IU));
    add(nameTps);

    txtTraction.setXY(314, 167);
    txtTraction.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtTraction.setLinespacing(0);
    Unicode::snprintf(txtTractionBuffer, TXTTRACTION_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_Z0Z3).getText());
    txtTraction.setWildcard(txtTractionBuffer);
    txtTraction.resizeToCurrentText();
    txtTraction.setTypedText(touchgfx::TypedText(T___SINGLEUSE_4SVJ));
    add(txtTraction);

    nameTraction.setXY(316, 140);
    nameTraction.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nameTraction.setLinespacing(0);
    nameTraction.setTypedText(touchgfx::TypedText(T___SINGLEUSE_U9VT));
    add(nameTraction);

    txtSteeringWheel.setXY(412, 167);
    txtSteeringWheel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtSteeringWheel.setLinespacing(0);
    Unicode::snprintf(txtSteeringWheelBuffer, TXTSTEERINGWHEEL_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_0EQM).getText());
    txtSteeringWheel.setWildcard(txtSteeringWheelBuffer);
    txtSteeringWheel.resizeToCurrentText();
    txtSteeringWheel.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ZQAM));
    add(txtSteeringWheel);

    nameSpeed.setXY(304, 75);
    nameSpeed.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nameSpeed.setLinespacing(0);
    nameSpeed.setTypedText(touchgfx::TypedText(T___SINGLEUSE_L7M2));
    add(nameSpeed);

    nameBrake.setXY(399, 75);
    nameBrake.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    nameBrake.setLinespacing(0);
    nameBrake.setTypedText(touchgfx::TypedText(T___SINGLEUSE_N9UW));
    add(nameBrake);

    txtBestLap.setXY(44, 44);
    txtBestLap.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtBestLap.setLinespacing(0);
    txtBestLap.setTypedText(touchgfx::TypedText(T___SINGLEUSE_87KS));
    add(txtBestLap);

    txtCurLap.setXY(325, 43);
    txtCurLap.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    txtCurLap.setLinespacing(0);
    txtCurLap.setTypedText(touchgfx::TypedText(T___SINGLEUSE_TEIU));
    add(txtCurLap);

    bxRPMLowRange.setPosition(2, 2, 200, 32);
    bxRPMLowRange.setColor(touchgfx::Color::getColorFromRGB(17, 0, 255));
    add(bxRPMLowRange);

    bxRPMMediumRange.setPosition(201, 2, 157, 32);
    bxRPMMediumRange.setColor(touchgfx::Color::getColorFromRGB(235, 207, 0));
    add(bxRPMMediumRange);

    bxRPMHighRange.setPosition(358, 2, 119, 32);
    bxRPMHighRange.setColor(touchgfx::Color::getColorFromRGB(255, 0, 21));
    add(bxRPMHighRange);

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
    Unicode::snprintf(txtAlarmBuffer, TXTALARM_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_CE0Z).getText());
    txtAlarm.setWildcard(txtAlarmBuffer);
    txtAlarm.setTypedText(touchgfx::TypedText(T___SINGLEUSE_KLZP));
    ctAlarm.add(txtAlarm);

    add(ctAlarm);
}

RACEViewBase::~RACEViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
}

void RACEViewBase::setupScreen()
{

}
