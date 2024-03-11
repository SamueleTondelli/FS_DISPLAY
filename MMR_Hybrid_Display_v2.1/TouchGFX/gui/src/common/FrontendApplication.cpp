#include <gui/common/FrontendApplication.hpp>

#include <touchgfx/Color.hpp>

FrontendApplication::FrontendApplication(Model& m, FrontendHeap& heap)
    : FrontendApplicationBase(m, heap)
{

}

//MODIFIED

void FrontendApplication::gotoHOMEScreenNoTransition()
{
	transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoHOMEScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplication::gotoRACEScreenNoTransition()
{
	transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoRACEScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplication::gotoDRAGScreenNoTransition()
{
	transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoDRAGScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplication::gotoENDURANCEScreenNoTransition()
{
	transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoENDURANCEScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplication::gotoSKIDPADScreenNoTransition()
{
	transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoSKIDPADScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplication::gotoSETUPScreenNoTransition()
{
	transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoSETUPScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}


//END MODIFIEDS
