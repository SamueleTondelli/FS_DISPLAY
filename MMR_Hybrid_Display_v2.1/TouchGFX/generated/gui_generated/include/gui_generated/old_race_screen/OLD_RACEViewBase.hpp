/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef OLD_RACEVIEWBASE_HPP
#define OLD_RACEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/old_race_screen/OLD_RACEPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/canvas/Line.hpp>
#include <touchgfx/widgets/canvas/PainterRGB565.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/Container.hpp>

class OLD_RACEViewBase : public touchgfx::View<OLD_RACEPresenter>
{
public:
    OLD_RACEViewBase();
    virtual ~OLD_RACEViewBase();
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
    touchgfx::TextAreaWithOneWildcard txtBestLap;
    touchgfx::Line up_line;
    touchgfx::PainterRGB565 up_linePainter;
    touchgfx::Line rpm_line;
    touchgfx::PainterRGB565 rpm_linePainter;
    touchgfx::Line design_line_2;
    touchgfx::PainterRGB565 design_line_2Painter;
    touchgfx::Line design_line_2_1;
    touchgfx::PainterRGB565 design_line_2_1Painter;
    touchgfx::Line design_line_5;
    touchgfx::PainterRGB565 design_line_5Painter;
    touchgfx::Line design_line_5_1;
    touchgfx::PainterRGB565 design_line_5_1Painter;
    touchgfx::Line design_line_1;
    touchgfx::PainterRGB565 design_line_1Painter;
    touchgfx::Line right_line;
    touchgfx::PainterRGB565 right_linePainter;
    touchgfx::Line left_line;
    touchgfx::PainterRGB565 left_linePainter;
    touchgfx::Line design_line_4;
    touchgfx::PainterRGB565 design_line_4Painter;
    touchgfx::Line design_line_4_1;
    touchgfx::PainterRGB565 design_line_4_1Painter;
    touchgfx::Line design_line_4_1_1;
    touchgfx::PainterRGB565 design_line_4_1_1Painter;
    touchgfx::Line design_line_3;
    touchgfx::PainterRGB565 design_line_3Painter;
    touchgfx::Line bottom_line;
    touchgfx::PainterRGB565 bottom_linePainter;
    touchgfx::TextAreaWithOneWildcard txtSpeed;
    touchgfx::TextAreaWithOneWildcard txtBrake;
    touchgfx::TextAreaWithOneWildcard txtGear;
    touchgfx::TextAreaWithOneWildcard txtRPM;
    touchgfx::TextAreaWithOneWildcard txtVbat;
    touchgfx::TextArea nameVbat;
    touchgfx::TextArea nameWaterT;
    touchgfx::TextArea nameOilT;
    touchgfx::TextArea nameAirT;
    touchgfx::TextAreaWithOneWildcard txtAirT;
    touchgfx::TextAreaWithOneWildcard txtOilT;
    touchgfx::TextAreaWithOneWildcard txtWaterT;
    touchgfx::TextArea nameOilP;
    touchgfx::TextArea nameFuelT;
    touchgfx::TextArea nameFuelP;
    touchgfx::TextAreaWithOneWildcard txtFuelT;
    touchgfx::TextAreaWithOneWildcard txtFuelP;
    touchgfx::TextArea nameSteeringWheel;
    touchgfx::TextAreaWithOneWildcard txtTps;
    touchgfx::TextAreaWithOneWildcard txtMap;
    touchgfx::TextArea nameMap;
    touchgfx::TextArea nameTps;
    touchgfx::TextAreaWithOneWildcard txtTraction;
    touchgfx::TextArea nameTraction;
    touchgfx::TextAreaWithOneWildcard txtSteeringWheel;
    touchgfx::TextArea nameSpeed;
    touchgfx::TextArea nameBrake;
    touchgfx::Box bxRPMLowRange;
    touchgfx::Box bxRPMMediumRange;
    touchgfx::Box bxRPMHighRange;
    touchgfx::TextAreaWithOneWildcard txtOilP;
    touchgfx::Box bxRPMCover;
    touchgfx::TextArea nameBestLap;
    touchgfx::TextArea nameLastLap;
    touchgfx::TextAreaWithOneWildcard txtLastLap;
    touchgfx::Container ctTemp;
    touchgfx::BoxWithBorder bxOilTemp;
    touchgfx::BoxWithBorder bxWaterTemp;
    touchgfx::TextAreaWithOneWildcard txtWaterTemp;
    touchgfx::TextAreaWithOneWildcard txtOilTemp;
    touchgfx::TextArea nameWaterTemp;
    touchgfx::TextArea nameOilTemp;
    touchgfx::Container ctAlarm;
    touchgfx::BoxWithBorder bxAlarm;
    touchgfx::TextAreaWithOneWildcard txtAlarmName;
    touchgfx::TextAreaWithOneWildcard txtAlarmValue;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TXTBESTLAP_SIZE = 10;
    touchgfx::Unicode::UnicodeChar txtBestLapBuffer[TXTBESTLAP_SIZE];
    static const uint16_t TXTSPEED_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtSpeedBuffer[TXTSPEED_SIZE];
    static const uint16_t TXTBRAKE_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtBrakeBuffer[TXTBRAKE_SIZE];
    static const uint16_t TXTGEAR_SIZE = 1;
    touchgfx::Unicode::UnicodeChar txtGearBuffer[TXTGEAR_SIZE];
    static const uint16_t TXTRPM_SIZE = 5;
    touchgfx::Unicode::UnicodeChar txtRPMBuffer[TXTRPM_SIZE];
    static const uint16_t TXTVBAT_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtVbatBuffer[TXTVBAT_SIZE];
    static const uint16_t TXTAIRT_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtAirTBuffer[TXTAIRT_SIZE];
    static const uint16_t TXTOILT_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtOilTBuffer[TXTOILT_SIZE];
    static const uint16_t TXTWATERT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar txtWaterTBuffer[TXTWATERT_SIZE];
    static const uint16_t TXTFUELT_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtFuelTBuffer[TXTFUELT_SIZE];
    static const uint16_t TXTFUELP_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtFuelPBuffer[TXTFUELP_SIZE];
    static const uint16_t TXTTPS_SIZE = 10;
    touchgfx::Unicode::UnicodeChar txtTpsBuffer[TXTTPS_SIZE];
    static const uint16_t TXTMAP_SIZE = 4;
    touchgfx::Unicode::UnicodeChar txtMapBuffer[TXTMAP_SIZE];
    static const uint16_t TXTTRACTION_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtTractionBuffer[TXTTRACTION_SIZE];
    static const uint16_t TXTSTEERINGWHEEL_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtSteeringWheelBuffer[TXTSTEERINGWHEEL_SIZE];
    static const uint16_t TXTOILP_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtOilPBuffer[TXTOILP_SIZE];
    static const uint16_t TXTLASTLAP_SIZE = 10;
    touchgfx::Unicode::UnicodeChar txtLastLapBuffer[TXTLASTLAP_SIZE];
    static const uint16_t TXTWATERTEMP_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtWaterTempBuffer[TXTWATERTEMP_SIZE];
    static const uint16_t TXTOILTEMP_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtOilTempBuffer[TXTOILTEMP_SIZE];
    static const uint16_t TXTALARMNAME_SIZE = 10;
    touchgfx::Unicode::UnicodeChar txtAlarmNameBuffer[TXTALARMNAME_SIZE];
    static const uint16_t TXTALARMVALUE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar txtAlarmValueBuffer[TXTALARMVALUE_SIZE];

private:

    /*
     * Canvas Buffer Size
     */
    static const uint32_t CANVAS_BUFFER_SIZE = 7200;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];

};

#endif // OLD_RACEVIEWBASE_HPP
