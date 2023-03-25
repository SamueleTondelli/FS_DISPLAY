#include <gui/screen7_screen/Screen7View.hpp>

Screen7View::Screen7View()
{
	shBrake.setWidth(0);	//MAX 185
	shThrottle.setCorner(0, CWRUtil::toQ5<int>(0), CWRUtil::toQ5<int>(80));		// TODO Modifica questo (angolo basso)
	shThrottle.setCorner(2, CWRUtil::toQ5<int>(0), CWRUtil::toQ5<int>(0));		// TODO Modifica questo (angolo alto)
	shThrottle.setCorner(1, CWRUtil::toQ5<int>(185), CWRUtil::toQ5<int>(80));	// TODO Non modificare questo (angolo destro)
}

void Screen7View::setupScreen()
{
    Screen7ViewBase::setupScreen();
}

void Screen7View::tearDownScreen()
{
    Screen7ViewBase::tearDownScreen();
}
