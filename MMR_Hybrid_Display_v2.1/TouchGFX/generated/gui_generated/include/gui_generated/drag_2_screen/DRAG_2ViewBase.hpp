/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef DRAG_2VIEWBASE_HPP
#define DRAG_2VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/drag_2_screen/DRAG_2Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Image.hpp>

class DRAG_2ViewBase : public touchgfx::View<DRAG_2Presenter>
{
public:
    DRAG_2ViewBase();
    virtual ~DRAG_2ViewBase();
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
    touchgfx::TextArea nameRPM;
    touchgfx::TextArea nameSpeed;
    touchgfx::Image imageSpeed;
    touchgfx::Image imageRPM;
    touchgfx::TextArea txtSpeed;
    touchgfx::TextArea txtKmH;
    touchgfx::TextArea txtRPM;
    touchgfx::Image imageTraction;
    touchgfx::Image imageLaunchControl;
    touchgfx::TextArea nameTraction;
    touchgfx::TextArea txtTraction;
    touchgfx::TextArea txtLaunchControl;
    touchgfx::TextArea txtSteeringWheel;
    touchgfx::TextArea txtSteeringWheelGrade;
    touchgfx::TextArea nameLaunchControl;
    touchgfx::TextArea nameSteeringWheel;
    touchgfx::TextArea nameGear;
    touchgfx::Image imageSteeringWheel;
    touchgfx::Image imageGear;
    touchgfx::TextArea txtGear;

private:

};

#endif // DRAG_2VIEWBASE_HPP