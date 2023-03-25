#include <gui/screen4_screen/Screen4View.hpp>

#include <touchgfx/Color.hpp>

#include "Data/Dataset.h"
#include "Data/DataStatus.h"
#include "Data/DataConstantNotification.h"
#include "DisplayConstant.h"
#include "TimerHandler.h"

extern Dataset ds;

Screen4View::Screen4View()
{

	ctAlarm.setVisible(false);

	ctMessage.setVisible(false);

	ctScreenName.setVisible(true);

	bxEmTorque.setVisible(false);
	bxEmSpeed.setVisible(false);
	bxIgnitionTiming.setVisible(false);
	bxToil.setVisible(false);
	bxPoil.setVisible(false);
	bxTwaterC.setVisible(false);
	bxMap.setVisible(false);

	//chart1.setGraphRangeY(0.5f, 1.5f);	// TODO Impostare valori fissi scala Y
	//chart2.setGraphRangeY(0.5f, 1.5f);

	bxBackground.setBorderColor(Color::getColorFrom24BitRGB(0,0,0));
	bxBackground.invalidate();
}

void Screen4View::setupScreen()
{
    Screen4ViewBase::setupScreen();
}

void Screen4View::tearDownScreen()
{
    Screen4ViewBase::tearDownScreen();
}

void Screen4View::updateDisplay() {

// Alarm
	if(ds.screen.alarmFlag) {
		Unicode::UnicodeChar buffer[33] = {0};
		if(isPressureOilAlarmOn(&ds) != ALARM_OFF) {
			Unicode::strncpy(buffer, POIL_ALARM, POIL_ALARM_LENGTH);
			bxBackground.setBorderColor(Color::getColorFrom24BitRGB(255,0,0));
			Unicode::strncpy(txtAlarmBuffer, buffer, TXTALARM_SIZE-1);
		} else if(isOilTemperatureAlarmOn(&ds) != ALARM_OFF) {
			Unicode::strncpy(buffer, TOIL_ALARM, TOIL_ALARM_LENGTH);
			bxBackground.setBorderColor(Color::getColorFrom24BitRGB(255,0,0));
			Unicode::strncpy(txtAlarmBuffer, buffer, TXTALARM_SIZE-1);
		} else if(isWaterTemperatureAlarmOn(&ds) != ALARM_OFF) {
			Unicode::strncpy(buffer, TWATER_ALARM, TWATER_ALARM_LENGTH);
			bxBackground.setBorderColor(Color::getColorFrom24BitRGB(255,0,0));
			Unicode::strncpy(txtAlarmBuffer, buffer, TXTALARM_SIZE-1);
		} else if(isSOCAlarmOn(&ds) != ALARM_OFF) {
			Unicode::strncpy(buffer, SOC_ALARM, SOC_ALARM_LENGTH);
			bxBackground.setBorderColor(Color::getColorFrom24BitRGB(255,0,0));
			Unicode::strncpy(txtAlarmBuffer, buffer, TXTALARM_SIZE-1);
		} else if(isTemperatureBatteryAlarmOn(&ds) != ALARM_OFF) {
			Unicode::strncpy(buffer, TBATTERY_ALARM, TBATTERY_ALARM_LENGTH);
			bxBackground.setBorderColor(Color::getColorFrom24BitRGB(255,0,0));
			Unicode::strncpy(txtAlarmBuffer, buffer, TXTALARM_SIZE-1);
		}

		if(ds.screen.blinkFlag) {
			ctAlarm.setVisible(true);
		} else {
			ctAlarm.setVisible(false);
		}

	} else {
		ctAlarm.setVisible(false);
		bxBackground.setBorderColor(Color::getColorFrom24BitRGB(0,0,0));
	}

// Screen Name
	if(ds.screen.screenNameFlag) {
		ctScreenName.setVisible(true);
	} else {
		ctScreenName.setVisible(false);
	}

//FPS
	int fps = getFpsScreen(&(ds.screen));
	if(fps != EMPTY_VALUE) {
		// Set Text
		Unicode::snprintf(txtFpsBuffer, TXTFPS_SIZE-1, "%d", fps);
		txtFps.invalidate();
	}

// Poil
	float pOil = getValueData(&(ds.powerUnit.oilPressure));
	if(pOil != EMPTY_VALUE) {
		if(!bxPoil.isVisible())
			bxPoil.setVisible(true);

		// Set Color Poil
		if(pOil >= LOW_POIL_MIN && pOil <= LOW_POIL_MAX) {
			bxPoil.setColor(Color::getColorFrom24BitRGB(255,0,0));				//Color Red
		} else if(pOil >= MEDIUM_POIL_MIN && pOil <= MEDIUM_POIL_MAX) {
			bxPoil.setColor(Color::getColorFrom24BitRGB(0,0,0));				//Color Black
			//lblPoil.setColor(Color::getColorFrom24BitRGB(255,255,255));
		} else if(pOil >= HIGH_POIL_MIN && pOil <= HIGH_POIL_MAX) {
			bxPoil.setColor(Color::getColorFrom24BitRGB(255,0,0));				//Color Red
			//lblPoil.setColor(Color::getColorFrom24BitRGB(0,0,0));
		}

		if(isDataUpdated(&(ds.powerUnit.oilPressure)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtPoilBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);

			bxPoil.setColor(Color::getColorFrom24BitRGB(0,0,0));				//Color Black
		} else {
			// Set Text
			Unicode::snprintfFloat(txtPoilBuffer, TXTPOIL_SIZE-1, "%.2f", pOil);
		}

		bxPoil.invalidate();
		txtPoil.invalidate();
	}

// Toil
	float tOil = getValueData(&(ds.powerUnit.oilTemperature));
	if(tOil != EMPTY_VALUE) {
		if(!bxToil.isVisible())
			bxToil.setVisible(true);

		// Set Color
		if(tOil >= LOW_TOIL_MIN && tOil <= LOW_TOIL_MAX) {
			bxToil.setColor(Color::getColorFrom24BitRGB(0,0,255));				//Color Blue

			// Set Fade Toil
			// Range between 255-127
			uint8_t fadeValue = 255;
			if(tOil >= HIGH_TOIL_WARNING_START && tOil <= HIGH_TOIL_WARNING_END)
				fadeValue = FADE_MAX - ((FADE_MIN+1) / (HIGH_TOIL_WARNING_END - HIGH_TOIL_WARNING_START) * (tOil - HIGH_TOIL_WARNING_START));
			bxToil.setAlpha(fadeValue);

			//lblToil.setColor(Color::getColorFrom24BitRGB(0,0,0));
		} else if(tOil >= MEDIUM_TOIL_MIN && tOil <= MEDIUM_TOIL_MAX) {
			bxToil.setColor(Color::getColorFrom24BitRGB(0,0,0));				//Color Black
			//lblToil.setColor(Color::getColorFrom24BitRGB(255,255,255));
		} else if(tOil >= HIGH_TOIL_MIN && tOil <= HIGH_TOIL_MAX) {
			bxToil.setColor(Color::getColorFrom24BitRGB(255,0,0));				//Color Red

			// Set Fade Toil
			// Range between 127-255
			uint16_t fadeValue = 255;
			if(tOil >= HIGH_TOIL_WARNING_START && tOil <= HIGH_TOIL_WARNING_END)
				fadeValue = (((FADE_MIN+1) / (HIGH_TOIL_WARNING_END - HIGH_TOIL_WARNING_START)) * (tOil * HIGH_TOIL_WARNING_START) + (FADE_MIN));
			bxToil.setAlpha(fadeValue);

			//lblToil.setColor(Color::getColorFrom24BitRGB(0,0,0));
		}

		if(isDataUpdated(&(ds.powerUnit.oilTemperature)) == 0 && ds.screen.blinkFlag == 1) {

			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtToilBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);

			bxToil.setColor(Color::getColorFrom24BitRGB(0,0,0));				//Color Black
		} else {
			// Set Text
			Unicode::snprintfFloat(txtToilBuffer, TXTTOIL_SIZE-1, "%.1f", tOil);
		}

		bxToil.invalidate();
		txtToil.invalidate();
	}

// cvEngineStatus
	int cvEngineStatus = getDataStatus(&(ds.powerUnit.engineStateCV));
	if(cvEngineStatus != EMPTY_VALUE) {

		Unicode::UnicodeChar buffer[TXTCVSTATUS_SIZE] = {0};
		uint8_t statusLength = getCurrentDataStatusLength(&(ds.powerUnit.engineStateCV));
		if(statusLength > (TXTCVSTATUS_SIZE-1)) {
			Unicode::strncpy(buffer, DATA_STATUS_ERROR, DATA_STATUS_ERROR_LENGTH);
		} else {
			Unicode::strncpy(buffer, getCurrentDataStatus(&(ds.powerUnit.engineStateCV)), statusLength);
			Unicode::snprintf(txtCVStatusBuffer, TXTCVSTATUS_SIZE-1, "%s", buffer);
		}
	}

// TwaterC
	float tWaterC = getValueData(&(ds.powerUnit.coolantTemperatureCV));
	if(tWaterC != EMPTY_VALUE) {
		if(!bxTwaterC.isVisible())
			bxTwaterC.setVisible(true);

		// Set Color
		if(tWaterC >= LOW_TWATERC_MIN && tWaterC <= LOW_TWATERC_MAX) {
			bxTwaterC.setColor(Color::getColorFrom24BitRGB(0,0,255));						//Color Blue

			// Set Fade TwaterC
			// Range between 255-127
			uint8_t fadeValue = 255;
			if(tWaterC >= HIGH_TWATERC_WARNING_START && tWaterC <= HIGH_TWATERC_WARNING_END)
				fadeValue = FADE_MAX - ((FADE_MIN+1) / (HIGH_TWATERC_WARNING_END - HIGH_TWATERC_WARNING_START) * (tWaterC - HIGH_TWATERC_WARNING_START));
			bxTwaterC.setAlpha(fadeValue);

			//lblTwaterC.setColor(Color::getColorFrom24BitRGB(0,0,0));
		} else if(tWaterC >= MEDIUM_TWATERC_MIN && tWaterC <= MEDIUM_TWATERC_MAX) {
			bxTwaterC.setColor(Color::getColorFrom24BitRGB(0,0,0));		 					//Color Black
			//lblTwaterC.setColor(Color::getColorFrom24BitRGB(255,255,255));
		} else if(tWaterC >= HIGH_TWATERC_MIN && tWaterC <= HIGH_TWATERC_MAX) {
			bxTwaterC.setColor(Color::getColorFrom24BitRGB(255,0,0));						//Color Red

			// Set Fade TwaterC
			// Range between 127-255
			uint8_t fadeValue = 255;
			if(tWaterC >= HIGH_TWATERC_WARNING_START && tWaterC <= HIGH_TWATERC_WARNING_START)
				fadeValue = (((FADE_MIN+1) / (HIGH_TWATERC_WARNING_END - HIGH_TWATERC_WARNING_START)) * (tWaterC * HIGH_TWATERC_WARNING_START) + (FADE_MIN));
			bxTwaterC.setAlpha(fadeValue);

			//lblTwaterC.setColor(Color::getColorFrom24BitRGB(0,0,0));
		}

		if(isDataUpdated(&(ds.powerUnit.coolantTemperatureCV)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtTwaterCBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);

			bxTwaterC.setColor(Color::getColorFrom24BitRGB(0,0,0));		 					//Color Black
		} else {
			// Set Text
			Unicode::snprintfFloat(txtTwaterCBuffer, TXTTWATERC_SIZE-1, "%.1f", tWaterC);
		}

		bxTwaterC.invalidate();
		txtTwaterC.invalidate();
	}

// Ignition Timing
	int ignitionTiming = getValueData(&(ds.powerUnit.ignitionTiming));
	if(ignitionTiming != EMPTY_VALUE) {

		if(isDataUpdated(&(ds.powerUnit.ignitionTiming)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtIgnitionTimingBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintf(txtIgnitionTimingBuffer, TXTIGNITIONTIMING_SIZE-1, "%d", ignitionTiming);
		}

		txtIgnitionTiming.invalidate();
	}

// EmSpeed
	int emSpeed = getValueData(&(ds.hvElectronicsInverter.electricMotorSpeed));
	if(emSpeed != EMPTY_VALUE) {

		if(isDataUpdated(&(ds.hvElectronicsInverter.electricMotorSpeed)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtEmSpeedBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintf(txtEmSpeedBuffer, TXTEMSPEED_SIZE-1, "%d", emSpeed);
		}

		txtEmSpeed.invalidate();
	}

// EmTorque
	int emTorque = getValueData(&(ds.hvElectronicsInverter.electricMotorTorque));
	if(emTorque != EMPTY_VALUE) {

		if(isDataUpdated(&(ds.hvElectronicsInverter.electricMotorTorque)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtEmTorqueBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintf(txtEmTorqueBuffer, TXTEMTORQUE_SIZE-1, "%d", emTorque);
		}

		txtEmTorque.invalidate();
	}

// Map
	float map = getValueData(&(ds.powerUnit.map));
	if(map != EMPTY_VALUE) {
		bxMap.setVisible(false);

		if(isDataUpdated(&(ds.powerUnit.map)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtMapBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintfFloat(txtMapBuffer, TXTMAP_SIZE-1, "%.2f", map);
		}

		txtMap.invalidate();
	}

// GEAR
	int gear = getValueData(&(ds.powerUnit.gear));
	if(gear == 0 || gear == EMPTY_VALUE)
		txtGearBuffer[0] = 'N';
	else if(gear == 1)
		txtGearBuffer[0] = '1';
	else if(gear == 2)
		txtGearBuffer[0] = '2';
	else if(gear == 3)
		txtGearBuffer[0] = '3';
	else if(gear == 4)
		txtGearBuffer[0] = '4';
	else if(gear == 5)
		txtGearBuffer[0] = '5';
	else if(gear == 6)
		txtGearBuffer[0] = '6';

	txtGear.invalidate();

// Chart1 -> Lambda + Chart2 -> L-Target

	float lambda = getValueData(&(ds.powerUnit.exhaustLambda));
	float lTarget = getValueData(&(ds.powerUnit.lambdaTarget));
	if(lambda != EMPTY_VALUE || lTarget != EMPTY_VALUE) {
		uint8_t lambdaUpdated = isDataUpdated(&(ds.powerUnit.exhaustLambda));
		uint8_t lambdaTargetUpdated = isDataUpdated(&(ds.powerUnit.lambdaTarget));
		if(lambdaUpdated == 0) {
			if(ds.screen.blinkFlag) {
				Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
				Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
				Unicode::snprintf(txtChart1Buffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
			} else {
				Unicode::snprintfFloat(txtChart1Buffer, TXTCHART1_SIZE-1, "%.1f", lambda);
			}
		} else {
			chart1.addDataPoint(lambda);

			Unicode::snprintfFloat(txtChart1Buffer, TXTCHART1_SIZE-1, "%.1f", lambda);

			txtChart1.invalidate();
			chart1.invalidate();
		}
		if(lambdaTargetUpdated == 0) {
			if(ds.screen.blinkFlag) {
				Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
				Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
				Unicode::snprintf(txtChart2Buffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
			} else {
				Unicode::snprintfFloat(txtChart2Buffer, TXTCHART2_SIZE-1, "%.1f", lTarget);
			}
		} else {
			chart2.addDataPoint(lTarget);

			Unicode::snprintfFloat(txtChart2Buffer, TXTCHART2_SIZE-1, "%.1f", lTarget);

			txtChart2.invalidate();
			chart2.invalidate();
		}
	}

// DISPLAY

	bxBackground.invalidate();
}
