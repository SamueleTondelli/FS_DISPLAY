/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SETVIEWBASE_HPP
#define SETVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/set_screen/SETPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>

class SETViewBase : public touchgfx::View<SETPresenter>
{
public:
    SETViewBase();
    virtual ~SETViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box bxBackground;
    touchgfx::Container ctRight;
    touchgfx::Container ctRRHeight;
    touchgfx::Box bxRRHeight;
    touchgfx::TextArea txtRRHeightLabel;
    touchgfx::TextAreaWithOneWildcard txtRRHeight;
    touchgfx::Container ctBrakeRear;
    touchgfx::Box bxBrakeRear;
    touchgfx::TextArea txtBrakeRearLabel;
    touchgfx::TextAreaWithOneWildcard txtBrakeRear;
    touchgfx::Container ctBias;
    touchgfx::Box bxBias;
    touchgfx::TextArea txtBiasLabel;
    touchgfx::TextAreaWithOneWildcard txtBias;
    touchgfx::Container ctFRHeight;
    touchgfx::Box bxFRHeight;
    touchgfx::TextArea txtFRHeightLabel;
    touchgfx::TextAreaWithOneWildcard txtFRHeight;
    touchgfx::Container ctLeft;
    touchgfx::Container ctRLHeight;
    touchgfx::Box bxRLHeight;
    touchgfx::TextArea txtRLHeightLabel;
    touchgfx::TextAreaWithOneWildcard txtRLHeight;
    touchgfx::Container ctFLHeight;
    touchgfx::Box bxFLHeight;
    touchgfx::TextArea txtFLHeightLabel;
    touchgfx::TextAreaWithOneWildcard txtFLHeight;
    touchgfx::Container ctTPS;
    touchgfx::Box bxTPS;
    touchgfx::TextArea txtTPSLabel;
    touchgfx::TextAreaWithOneWildcard txtTPS;
    touchgfx::Container ctBrakePres;
    touchgfx::Box bxBrakePres;
    touchgfx::TextArea txtBrakePresLabel;
    touchgfx::TextAreaWithOneWildcard txtBrakePres;
    touchgfx::Container ctCenter;
    touchgfx::Container ctVBat;
    touchgfx::BoxWithBorder bxMode;
    touchgfx::TextArea txtVBattLabel;
    touchgfx::TextAreaWithOneWildcard txtVBat;
    touchgfx::Container ctMap;
    touchgfx::BoxWithBorder bxMap;
    touchgfx::TextArea txtMapLabel;
    touchgfx::TextAreaWithOneWildcard txtMap;
    touchgfx::Container ctSteer;
    touchgfx::Box box1;
    touchgfx::TextAreaWithOneWildcard txtSteer;
    touchgfx::TextAreaWithOneWildcard txtGear;
    touchgfx::Container ctPopUp;
    touchgfx::Box bxPopUpContents;
    touchgfx::Box bxPopUpName;
    touchgfx::TextAreaWithOneWildcard txtPopUpName;
    touchgfx::TextAreaWithOneWildcard txtPopUpValue;

    /*
     * Wildcard Buffers
     */
    static const uint16_t TXTRRHEIGHT_SIZE = 6;
    touchgfx::Unicode::UnicodeChar txtRRHeightBuffer[TXTRRHEIGHT_SIZE];
    static const uint16_t TXTBRAKEREAR_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtBrakeRearBuffer[TXTBRAKEREAR_SIZE];
    static const uint16_t TXTBIAS_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtBiasBuffer[TXTBIAS_SIZE];
    static const uint16_t TXTFRHEIGHT_SIZE = 6;
    touchgfx::Unicode::UnicodeChar txtFRHeightBuffer[TXTFRHEIGHT_SIZE];
    static const uint16_t TXTRLHEIGHT_SIZE = 6;
    touchgfx::Unicode::UnicodeChar txtRLHeightBuffer[TXTRLHEIGHT_SIZE];
    static const uint16_t TXTFLHEIGHT_SIZE = 6;
    touchgfx::Unicode::UnicodeChar txtFLHeightBuffer[TXTFLHEIGHT_SIZE];
    static const uint16_t TXTTPS_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtTPSBuffer[TXTTPS_SIZE];
    static const uint16_t TXTBRAKEPRES_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtBrakePresBuffer[TXTBRAKEPRES_SIZE];
    static const uint16_t TXTVBAT_SIZE = 4;
    touchgfx::Unicode::UnicodeChar txtVBatBuffer[TXTVBAT_SIZE];
    static const uint16_t TXTMAP_SIZE = 3;
    touchgfx::Unicode::UnicodeChar txtMapBuffer[TXTMAP_SIZE];
    static const uint16_t TXTSTEER_SIZE = 5;
    touchgfx::Unicode::UnicodeChar txtSteerBuffer[TXTSTEER_SIZE];
    static const uint16_t TXTGEAR_SIZE = 2;
    touchgfx::Unicode::UnicodeChar txtGearBuffer[TXTGEAR_SIZE];
    static const uint16_t TXTPOPUPNAME_SIZE = 10;
    touchgfx::Unicode::UnicodeChar txtPopUpNameBuffer[TXTPOPUPNAME_SIZE];
    static const uint16_t TXTPOPUPVALUE_SIZE = 10;
    touchgfx::Unicode::UnicodeChar txtPopUpValueBuffer[TXTPOPUPVALUE_SIZE];

private:

};

#endif // SETVIEWBASE_HPP
