#include <gui/skidpad_screen/SKIDPADView.hpp>
#include <gui/common/FrontendApplication.hpp>
#include "Data/Dataset.h"

extern Dataset ds;

SKIDPADView::SKIDPADView()
{

}

void SKIDPADView::setupScreen()
{
    SKIDPADViewBase::setupScreen();
}

void SKIDPADView::tearDownScreen()
{
    SKIDPADViewBase::tearDownScreen();
}

void SKIDPADView::updateDisplay()
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

			//tAir
			FrontendApplication::writeFloatDataInBuffer(&(ds.thermalPressure.airTemperature), txtAirTBuffer, TXTAIRT_SIZE, &txtAirT);

			//tFuel
			FrontendApplication::writeFloatDataInBuffer(&(ds.thermalPressure.fuelTemperature), txtFuelTBuffer, TXTFUELT_SIZE, &txtFuelT);

			//vBat
			FrontendApplication::writeFloatDataInBuffer(&(ds.controls.batteryVoltage), txtVbatBuffer, TXTVBAT_SIZE, &txtVbat);

			//wheels
			FrontendApplication::writeFloatValueInBuffer(ds.tyres.FL.temperature, txtFLBuffer, TXTFL_SIZE, &txtFL);
			FrontendApplication::writeFloatValueInBuffer(ds.tyres.FR.temperature, txtFRBuffer, TXTFR_SIZE, &txtFR);
			FrontendApplication::writeFloatValueInBuffer(ds.tyres.RL.temperature, txtRLBuffer, TXTRL_SIZE, &txtRL);
			FrontendApplication::writeFloatValueInBuffer(ds.tyres.RR.temperature, txtRRBuffer, TXTRR_SIZE, &txtRR);
		}

		//speed
		FrontendApplication::writeIntDataInBuffer(&(ds.mechanics.speed), txtSpeedBuffer, TXTSPEED_SIZE, &txtSpeed);

		//rpm
		FrontendApplication::writeIntDataInBuffer(&(ds.mechanics.rpm), txtRPMBuffer, TXTRPM_SIZE, &txtRPM);

		//tps
		FrontendApplication::writeIntDataInBuffer(&(ds.mechanics.tps), txtTpsBuffer, TXTTPS_SIZE, &txtTps);

		//steer
		FrontendApplication::writeIntDataInBuffer(&(ds.controls.steer), txtSteeringWheelLeftBuffer, TXTSTEERINGWHEELLEFT_SIZE, &txtSteeringWheelLeft);
		FrontendApplication::writeIntDataInBuffer(&(ds.controls.steer), txtSteeringWheelRightBuffer, TXTSTEERINGWHEELRIGHT_SIZE, &txtSteeringWheelRight);

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

		//rpm bar
		bxRPMCover.setPosition((getValueData(&(ds.mechanics.rpm)) * SCREEN_WIDTH) / MAX_RPM, bxRPMCover.getY(), bxRPMCover.getWidth(), bxRPMCover.getHeight());
		bxRPMCover.invalidate();
	}
	else
	{
		FrontendApplication::handleAlarms(&ctAlarm, txtAlarmNameBuffer, TXTALARMNAME_SIZE, txtAlarmValueBuffer, TXTALARMVALUE_SIZE, &bxAlarm);
	}
}
