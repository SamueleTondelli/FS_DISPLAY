#include <gui/drag_screen/DRAGView.hpp>
#include <gui/common/FrontendApplication.hpp>
#include "Data/Dataset.h"

extern Dataset ds;

DRAGView::DRAGView()
{

}

void DRAGView::setupScreen()
{
    DRAGViewBase::setupScreen();
}

void DRAGView::tearDownScreen()
{
    DRAGViewBase::tearDownScreen();
}

void DRAGView::updateDisplay()
{
	static uint32_t lastValueUpdate = 0;
	if (peekAlarmFromQueue() == NULL && FrontendApplication::getCurrentAlarm()->contents == NULL)
	{
		if ((uwTick - lastValueUpdate) >= ANTI_FLICKER_TIME || lastValueUpdate == 0)
		{
			lastValueUpdate = uwTick;

			//Poil
			FrontendApplication::writeFloatDataInBuffer(&(ds.thermalPressure.oilPressure), txtOilPBuffer, TXTOILP_SIZE, &txtOilP);

			//Toil
			FrontendApplication::writeFloatDataInBuffer(&(ds.thermalPressure.oilTemperature), txtOilTBuffer, TXTOILT_SIZE, &txtOilT);

			//tWater
			FrontendApplication::writeFloatDataInBuffer(&(ds.thermalPressure.waterTemperature), txtWaterTBuffer, TXTWATERT_SIZE, &txtWaterT);

			//vBat
			FrontendApplication::writeFloatDataInBuffer(&(ds.controls.batteryVoltage), txtVbatBuffer, TXTVBAT_SIZE, &txtVbat);
		}

		//speed
		FrontendApplication::writeIntDataInBuffer(&(ds.mechanics.speed), txtSpeedBuffer, TXTSPEED_SIZE, &txtSpeed);

		//rpm
		FrontendApplication::writeIntDataInBuffer(&(ds.mechanics.rpm), txtRPMBuffer, TXTRPM_SIZE, &txtRPM);

		//tps
		FrontendApplication::writeIntDataInBuffer(&(ds.mechanics.tps), txtTpsBuffer, TXTTPS_SIZE, &txtTps);

		int gear = getValueData(&(ds.mechanics.gear));
		switch(gear) {
		case 1:
			txtGearBuffer[0] = '1';
			break;
		case 2:
			txtGearBuffer[0] = '2';
		break;
		case 3:
			txtGearBuffer[0] = '3';
			break;
		case 4:
			txtGearBuffer[0] = '4';
			break;
		default:
			txtGearBuffer[0] = 'N';
			break;
		}
		txtGear.invalidate();

		//traction
		int traction = getValueData(&(ds.controls.tractionControl));
		switch(traction) {
			case 1:
				txtTractionBuffer[0] = '1';
				txtTractionBuffer[1] = ' ';
				txtTractionBuffer[2] = ' ';
				break;
			case 2:
				txtTractionBuffer[0] = '2';
				txtTractionBuffer[1] = ' ';
				txtTractionBuffer[2] = ' ';
				break;
			case 3:
				txtTractionBuffer[0] = '3';
				txtTractionBuffer[1] = ' ';
				txtTractionBuffer[2] = ' ';
				break;
			case 4:
				txtTractionBuffer[0] = '4';
				txtTractionBuffer[1] = ' ';
				txtTractionBuffer[2] = ' ';
				break;
			case 5:
				txtTractionBuffer[0] = '5';
				txtTractionBuffer[1] = ' ';
				txtTractionBuffer[2] = ' ';
				break;
			default:
				txtTractionBuffer[0] = 'O';
				txtTractionBuffer[1] = 'F';
				txtTractionBuffer[2] = 'F';
				break;
		}
		txtTraction.invalidate();

		if (ds.controls.map == 0)
		{
			txtMapBuffer[0] = 'B';
			txtMapBuffer[1] = 'A';
			txtMapBuffer[2] = 'S';
			txtMapBuffer[3] = 'E';
		}
		else
		{
			txtMapBuffer[0] = 'E';
			txtMapBuffer[1] = 'C';
			txtMapBuffer[2] = 'O';
			txtMapBuffer[3] = ' ';
		}

	}
	else
	{
		FrontendApplication::handleAlarms(&ctAlarm, txtAlarmNameBuffer, TXTALARMNAME_SIZE, txtAlarmValueBuffer, TXTALARMVALUE_SIZE, &bxAlarm);
	}
}
