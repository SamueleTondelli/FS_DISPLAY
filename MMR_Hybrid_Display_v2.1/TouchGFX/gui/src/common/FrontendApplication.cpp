#include <gui/common/FrontendApplication.hpp>

FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap)
{

}

//MODIFIED

	//Screen1
void FrontendApplication::gotoScreen1ScreenNoTransition()
{
    //transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoScreen1ScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}
	//Screen2
void FrontendApplication::gotoScreen2ScreenNoTransition()
{
    //transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoScreen2ScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}
	//Screen3
void FrontendApplication::gotoScreen3ScreenNoTransition()
{
    //transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoScreen3ScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}
	//Screen4
void FrontendApplication::gotoScreen4ScreenNoTransition()
{
    //transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoScreen4ScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

	//Screen5
void FrontendApplication::gotoScreen5ScreenNoTransition()
{
    //transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoScreen5ScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

//END MODIFIED
