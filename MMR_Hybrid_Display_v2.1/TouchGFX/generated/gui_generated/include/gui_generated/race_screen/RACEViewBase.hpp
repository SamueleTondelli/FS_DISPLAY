/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef RACEVIEWBASE_HPP
#define RACEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/race_screen/RACEPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/canvas/Circle.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class RACEViewBase : public touchgfx::View<RACEPresenter>
{
public:
    RACEViewBase();
    virtual ~RACEViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::BoxWithBorder bxBackGround;
    touchgfx::Container design;
    touchgfx::Line bottom_line;
    touchgfx::PainterRGB565 bottom_linePainter;
    touchgfx::Line left_line;
    touchgfx::PainterRGB565 left_linePainter;
    touchgfx::Line right_line;
    touchgfx::PainterRGB565 right_linePainter;
    touchgfx::Line RPM_line;
    touchgfx::PainterRGB565 RPM_linePainter;
    touchgfx::Circle circleWhiteLeft;
    touchgfx::PainterRGB565 circleWhiteLeftPainter;
    touchgfx::Circle circleBlackLeft;
    touchgfx::PainterRGB565 circleBlackLeftPainter;
    touchgfx::Circle circleWhiteRight;
    touchgfx::PainterRGB565 circleWhiteRightPainter;
    touchgfx::Circle circleBlackRight;
    touchgfx::PainterRGB565 circleBlackRightPainter;
    touchgfx::Line up_line;
    touchgfx::PainterRGB565 up_linePainter;
    touchgfx::Box bxBackGroundRPM;
    touchgfx::Container ctAlarm;
    touchgfx::BoxWithBorder bxAlarm;
    touchgfx::TextAreaWithOneWildcard txtAlarmName;
    touchgfx::TextAreaWithOneWildcard txtAlarmValue;
    touchgfx::TextAreaWithOneWildcard txtRPM;
    touchgfx::TextAreaWithOneWildcard txtGear;
    touchgfx::TextAreaWithOneWildcard txtSpeed;
    touchgfx::TextArea txtKmH;
    touchgfx::TextAreaWithOneWildcard txtFuelP;
    touchgfx::TextAreaWithOneWildcard txtFuelT;
    touchgfx::TextAreaWithOneWildcard txtOilP;
    touchgfx::TextArea nameFuelP;
    touchgfx::TextArea nameFuelT;
    touchgfx::TextArea nameOilP;
    touchgfx::TextAreaWithOneWildcard txtWaterT;
    touchgfx::TextAreaWithOneWildcard txtOilT;
    touchgfx::TextAreaWithOneWildcard txtAirT;
    touchgfx::TextArea nameAirT;
    touchgfx::TextArea nameOilT;
    touchgfx::TextArea nameWaterT;
    touchgfx::TextArea nameTps;
    touchgfx::TextArea nameVbat;
    touchgfx::TextArea nameMap;
    touchgfx::TextAreaWithOneWildcard txtMap;
    touchgfx::TextAreaWithOneWildcard txtVbat;
    touchgfx::TextAreaWithOneWildcard txtTps;
    touchgfx::Container gridLeft;
    touchgfx::Line line1;
    touchgfx::PainterRGB565 line1Painter;
    touchgfx::Line line1_2;
    touchgfx::PainterRGB565 line1_2Painter;
    touchgfx::Line line1_1;
    touchgfx::PainterRGB565 line1_1Painter;
    touchgfx::Line line2;
    touchgfx::PainterRGB565 line2Painter;
    touchgfx::Line line2_2;
    touchgfx::PainterRGB565 line2_2Painter;
    touchgfx::Line line2_2_1;
    touchgfx::PainterRGB565 line2_2_1Painter;
    touchgfx::Line line2_1;
    touchgfx::PainterRGB565 line2_1Painter;
    touchgfx::Container gridRight;
    touchgfx::Line line1_3;
    touchgfx::PainterRGB565 line1_3Painter;
    touchgfx::Line line1_2_1;
    touchgfx::PainterRGB565 line1_2_1Painter;
    touchgfx::Line line1_1_1;
    touchgfx::PainterRGB565 line1_1_1Painter;
    touchgfx::Line line2_3;
    touchgfx::PainterRGB565 line2_3Painter;
    touchgfx::Line line2_2_2;
    touchgfx::PainterRGB565 line2_2_2Painter;
    touchgfx::Line line2_2_1_1;
    touchgfx::PainterRGB565 line2_2_1_1Painter;
    touchgfx::Line line2_1_1;
    touchgfx::PainterRGB565 line2_1_1Painter;
    touchgfx::TextArea nameTraction;
    touchgfx::TextAreaWithOneWildcard txtTraction;
    touchgfx::Box bxCoverRPM;
    touchgfx::Line Traction_line_bottom;
    touchgfx::PainterRGB565 Traction_line_bottomPainter;
    touchgfx::Line Traction_line_up;
    touchgfx::PainterRGB565 Traction_line_upPainter;
    touchgfx::TextArea nameSteeringWheel;
    touchgfx::TextArea txtSteeringWheelGrade;
    touchgfx::TextAreaWithOneWildcard txtSteeringWheel;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TXTALARMNAME_SIZE = 10;
    touchgfx::Unicode::UnicodeChar txtAlarmNameBuffer[TXTALARMNAME_SIZE];
    static const uint16_t TXTALARMVALUE_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtAlarmValueBuffer[TXTALARMVALUE_SIZE];
    static const uint16_t TXTRPM_SIZE = 5;
    touchgfx::Unicode::UnicodeChar txtRPMBuffer[TXTRPM_SIZE];
    static const uint16_t TXTGEAR_SIZE = 1;
    touchgfx::Unicode::UnicodeChar txtGearBuffer[TXTGEAR_SIZE];
    static const uint16_t TXTSPEED_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtSpeedBuffer[TXTSPEED_SIZE];
    static const uint16_t TXTFUELP_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtFuelPBuffer[TXTFUELP_SIZE];
    static const uint16_t TXTFUELT_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtFuelTBuffer[TXTFUELT_SIZE];
    static const uint16_t TXTOILP_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtOilPBuffer[TXTOILP_SIZE];
    static const uint16_t TXTWATERT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar txtWaterTBuffer[TXTWATERT_SIZE];
    static const uint16_t TXTOILT_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtOilTBuffer[TXTOILT_SIZE];
    static const uint16_t TXTAIRT_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtAirTBuffer[TXTAIRT_SIZE];
    static const uint16_t TXTMAP_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtMapBuffer[TXTMAP_SIZE];
    static const uint16_t TXTVBAT_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtVbatBuffer[TXTVBAT_SIZE];
    static const uint16_t TXTTPS_SIZE = 10;
    touchgfx::Unicode::UnicodeChar txtTpsBuffer[TXTTPS_SIZE];
    static const uint16_t TXTTRACTION_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtTractionBuffer[TXTTRACTION_SIZE];
    static const uint16_t TXTSTEERINGWHEEL_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtSteeringWheelBuffer[TXTSTEERINGWHEEL_SIZE];

private:

    /*
     * Canvas Buffer Size
     */
    static const uint32_t CANVAS_BUFFER_SIZE = 7200;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];

};

#endif // RACEVIEWBASE_HPP