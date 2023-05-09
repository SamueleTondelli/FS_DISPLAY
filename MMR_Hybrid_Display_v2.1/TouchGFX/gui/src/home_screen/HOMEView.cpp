#include <gui/home_screen/HOMEView.hpp>
#include <gui/common/FrontendApplication.hpp>
#include "Data/Dataset.h"

extern Dataset ds;
extern Alarm queue[PRIORITIES][ALARMS_PER_PRIORITY];
extern uint8_t invalidateCurrentAlarmFlag; //bad, move to somewhere else

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
	static Alarm currentAlarm = {.contents = NULL};
	static uint32_t currentAlarmStartTime;
	if (peekAlarmFromQueue() == NULL && currentAlarm.contents == NULL)
	{
		// Screen Name
		if(ds.screen.screenNameFlag) {
			bxScreenName.setVisible(true);
			txtScreenName.setVisible(true);
		} else {
			bxScreenName.setVisible(false);
			txtScreenName.setVisible(false);
		}

		//Poil
		float pOil = getValueData(&(ds.thermalPressure.oilPressure));
		Unicode::snprintf(txtOilPBuffer, TXTOILP_SIZE, "%.1f", pOil);
		txtOilP.invalidate();

		//Toil
		float tOil = getValueData(&(ds.thermalPressure.oilTemperature));
		Unicode::snprintf(txtOilTBuffer, TXTOILT_SIZE, "%.1f", tOil);
		txtOilT.invalidate();

		//tWater
		float tWater = getValueData(&(ds.thermalPressure.waterTemperature));
		Unicode::snprintf(txtWaterTBuffer, TXTWATERT_SIZE, "%.1f", tWater);
		txtWaterT.invalidate();

		//tAir
		float tAir = getValueData(&(ds.thermalPressure.airTemperature));
		Unicode::snprintf(txtAirTBuffer, TXTAIRT_SIZE, "%.1f", tAir);
		txtAirT.invalidate();

		//pFuel
		float pFuel = getValueData(&(ds.thermalPressure.fuelPressure));
		Unicode::snprintf(txtFuelPBuffer, TXTFUELP_SIZE, "%.1f", pFuel);
		txtFuelP.invalidate();

		//tFuel
		float tFuel = getValueData(&(ds.thermalPressure.fuelTemperature));
		Unicode::snprintf(txtFuelTBuffer, TXTFUELT_SIZE, "%.1f", tFuel);
		txtFuelT.invalidate();

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
		txtSpeed.invalidate();

		//rpm
		int rpm = getValueData(&(ds.mechanics.rpm));
		Unicode::snprintf(txtRPMBuffer, TXTRPM_SIZE, "%d", rpm);
		txtRPM.invalidate();

		//vBat
		float vBat = getValueData(&(ds.controls.batteryVoltage));
		Unicode::snprintf(txtVbatBuffer, TXTVBAT_SIZE, "%.1f", vBat);
		txtVbat.invalidate();

		//tps
		int tps = getValueData(&(ds.mechanics.tps));
		Unicode::snprintf(txtTpsBuffer, TXTTPS_SIZE, "%d", tps);
		txtTps.invalidate();

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
	else
	{
		//TODO: move to model
		ctAlarm.setVisible(true);

		//if it's first time we enter here, we initialize currentAlarm and get the timestamp at which the alarm starts
		if (currentAlarm.contents == NULL)
		{
			currentAlarm = extractAlarmFromQueue();
			currentAlarmStartTime = uwTick;
		}

		/*Alarms works by having a not interruptable time, which unless the button is pressed we show the alarm even if there's an alarm after with a higher priority,
		  after that if there's an alarm with same or lower priority (more important), we switch to that, otherwise we give a bonus time to the current alarm because
		  it's more important
		*/
		//TODO: improve
		if ((invalidateCurrentAlarmFlag == 1) || (uwTick - currentAlarmStartTime >= ALARM_AUTOMATIC_TIMEOUT_TIME))
		{
			deactivateAlarm(&currentAlarm);
			invalidateCurrentAlarmFlag = 0;
		}
		else
		{
			if (uwTick - currentAlarmStartTime < ALARM_NOT_INTERRUPTABLE_TIME)
			{
				if (getAlarmStatus(&currentAlarm) == ON)
				{
					FrontendApplication::writeAlarmInBuffers(&currentAlarm, txtAlarmNameBuffer, TXTALARMNAME_SIZE, txtAlarmValueBuffer, TXTALARMVALUE_SIZE);
				}
				else
				{
					ctAlarm.setVisible(false);
					currentAlarm.contents = NULL;
				}
			}
			else
			{
				Alarm* nextAlarm = peekAlarmFromQueue();
				if (nextAlarm != NULL)
				{
					if (nextAlarm->priority <= currentAlarm.priority || (uwTick - currentAlarmStartTime >= ALARM_NOT_INTERRUPTABLE_TIME + ALARM_BONUS_TIME))
					{
						if (currentAlarm.type == DATA)
						{
							Data* data = (Data*)currentAlarm.contents;
							data->alarmStatus = OFF_QUEUE; //so we can insert again the alarm in the queue
						}
						else
						{
							//telemetry
						}
						//we invalidate current alarm
						currentAlarm.contents = NULL;
					}
					else
					{
						if (getAlarmStatus(&currentAlarm) == ON)
						{
							FrontendApplication::writeAlarmInBuffers(&currentAlarm, txtAlarmNameBuffer, TXTALARMNAME_SIZE, txtAlarmValueBuffer, TXTALARMVALUE_SIZE);
						}
						else
						{
							ctAlarm.setVisible(false);
							currentAlarm.contents = NULL;
						}
					}
				}
				else
				{
					if (getAlarmStatus(&currentAlarm) == ON)
					{
						FrontendApplication::writeAlarmInBuffers(&currentAlarm, txtAlarmNameBuffer, TXTALARMNAME_SIZE, txtAlarmValueBuffer, TXTALARMVALUE_SIZE);
					}
					else
					{
						ctAlarm.setVisible(false);
						currentAlarm.contents = NULL;
					}
				}
			}

		}

		ctAlarm.invalidate();
	}
}
