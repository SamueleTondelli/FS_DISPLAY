#include <gui/race_screen/RACEView.hpp>
#include <gui/common/FrontendApplication.hpp>
#include "Data/Dataset.h"

extern Dataset ds;

RACEView::RACEView()
{

}

void RACEView::setupScreen()
{
    RACEViewBase::setupScreen();
}

void RACEView::tearDownScreen()
{
    RACEViewBase::tearDownScreen();
}

void RACEView::updateDisplay()
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

			//pFuel
			FrontendApplication::writeFloatDataInBuffer(&(ds.thermalPressure.fuelPressure), txtFuelPBuffer, TXTFUELP_SIZE, &txtFuelP);

			//tFuel
			FrontendApplication::writeFloatDataInBuffer(&(ds.thermalPressure.fuelTemperature), txtFuelTBuffer, TXTFUELT_SIZE, &txtFuelT);

			//vBat
			FrontendApplication::writeFloatDataInBuffer(&(ds.controls.batteryVoltage), txtVbatBuffer, TXTVBAT_SIZE, &txtVbat);
		}

		//speed
		FrontendApplication::writeIntDataInBuffer(&(ds.mechanics.speed), txtSpeedBuffer, TXTSPEED_SIZE, &txtSpeed);

		//rpm
		FrontendApplication::writeIntDataInBuffer(&(ds.mechanics.rpm), txtRPMBuffer, TXTRPM_SIZE, &txtRPM);

		//tps
		FrontendApplication::writeIntDataInBuffer(&(ds.mechanics.tps), txtTpsBuffer, TXTTPS_SIZE, &txtTps);

		//brake
		FrontendApplication::writeIntDataInBuffer(&(ds.controls.brake), txtBrakeBuffer, TXTBRAKE_SIZE, &txtBrake);

		//steer
		FrontendApplication::writeIntDataInBuffer(&(ds.controls.steer), txtSteeringWheelBuffer, TXTSTEERINGWHEEL_SIZE, &txtSteeringWheel);

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

	}
	else
	{
		FrontendApplication::handleAlarms(&ctAlarm, txtAlarmNameBuffer, TXTALARMNAME_SIZE, txtAlarmValueBuffer, TXTALARMVALUE_SIZE, &bxAlarm);
	}
}
