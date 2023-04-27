#include <gui/home_screen/HOMEView.hpp>

#include "Data/Dataset.h"

extern Dataset ds;

HOMEView::HOMEView()
{
	ctAlarm.setVisible(false);
	ctScreenName.setVisible(true);
}

void HOMEView::setupScreen()
{
    HOMEViewBase::setupScreen();
}

void HOMEView::tearDownScreen()
{
    HOMEViewBase::tearDownScreen();
}

void HOMEView::updateDisplay()
{
	//Poil
	float pOil = getValueData(&(ds.thermalPressure.oilPressure));
	Unicode::snprintf(txtOilPBuffer, TXTOILP_SIZE, "%.1f", pOil);

	//Toil
	float tOil = getValueData(&(ds.thermalPressure.oilTemperature));
	Unicode::snprintf(txtOilTBuffer, TXTOILT_SIZE, "%.1f", tOil);

	//tWater
	float tWater = getValueData(&(ds.thermalPressure.waterTemperature));
	Unicode::snprintf(txtWaterTBuffer, TXTWATERT_SIZE, "%.1f", tWater);

	//tAir
	float tAir = getValueData(&(ds.thermalPressure.airTemperature));
	Unicode::snprintf(txtAirTBuffer, TXTAIRT_SIZE, "%.1f", tAir);

	//pFuel
	float pFuel = getValueData(&(ds.thermalPressure.fuelPressure));
	Unicode::snprintf(txtFuelPBuffer, TXTFUELP_SIZE, "%.1f", pFuel);

	//tFuel
	float tFuel = getValueData(&(ds.thermalPressure.fuelTemperature));
	Unicode::snprintf(txtFuelTBuffer, TXTFUELT_SIZE, "%.1f", tFuel);

	//gear
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

	//speed
	int speed = getValueData(&(ds.mechanics.speed));
	Unicode::snprintf(txtSpeedBuffer, TXTSPEED_SIZE, "%d", speed);

	//rpm
	int rpm = getValueData(&(ds.mechanics.rpm));
	Unicode::snprintf(txtRPMBuffer, TXTRPM_SIZE, "%d", rpm);

	//vBat
	float vBat = getValueData(&(ds.controls.batteryVoltage));
	Unicode::snprintf(txtVbatBuffer, TXTVBAT_SIZE, "%.1f", vBat);

	//tps
	int tps = getValueData(&(ds.mechanics.tps));
	Unicode::snprintf(txtTpsBuffer, TXTTPS_SIZE, "%d", tps);

	//traction
	int traction = ds.controls.tractionControl;
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
