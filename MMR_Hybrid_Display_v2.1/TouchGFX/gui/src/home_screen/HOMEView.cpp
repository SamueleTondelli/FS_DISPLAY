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
		FrontendApplication::writeIntDataInBuffer(&(ds.mechanics.speed), txtSpeedBuffer, TXTSPEED_SIZE, &txtSpeed);

		//rpm
		FrontendApplication::writeIntDataInBuffer(&(ds.mechanics.rpm), txtRPMBuffer, TXTRPM_SIZE, &txtRPM);

		//vBat
		FrontendApplication::writeFloatDataInBuffer(&(ds.controls.batteryVoltage), txtVbatBuffer, TXTVBAT_SIZE, &txtVbat);

		//tps
		FrontendApplication::writeIntDataInBuffer(&(ds.mechanics.tps), txtTpsBuffer, TXTTPS_SIZE, &txtTps);

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
