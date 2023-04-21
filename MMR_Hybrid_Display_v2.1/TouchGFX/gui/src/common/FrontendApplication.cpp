#include <gui/common/FrontendApplication.hpp>

FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap)
{

}

//MODIFIED

void goToScreenHomeNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::goToScreenHomeNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;

}

void goToScreenDragNoTransition()
{
	transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::goToScreenDragNoTransitionImpl);
	pendingScreenTransitionCallback = &transitionCallback;
}

void goToScreenDrag2NoTransition()
{
	transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::goToScreenDrag2NoTransitionImpl);
	pendingScreenTransitionCallback = &transitionCallback;
}

//END MODIFIED
