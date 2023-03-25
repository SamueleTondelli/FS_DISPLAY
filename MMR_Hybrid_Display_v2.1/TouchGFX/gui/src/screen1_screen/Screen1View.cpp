#include <gui/screen1_screen/Screen1View.hpp>

#include <touchgfx/Color.hpp>

#include "Data/Dataset.h"
#include "Data/DataConstantNotification.h"
#include "DisplayConstant.h"
#include "TimerHandler.h"

extern Dataset ds;

Screen1View::Screen1View()
{
	ctAlarm.setVisible(false);

	ctScreenName.setVisible(true);

	ctMessage.setVisible(false);

	bxRPM.setVisible(false);
	bxPoil.setVisible(false);
	bxToil.setVisible(false);
	bxMap.setVisible(false);

	bxTwaterC.setVisible(false);
	bxTwaterE.setVisible(false);
	bxTbat.setVisible(false);

	bxSoc.setVisible(false);

	lblCVStatusError.setVisible(false);
	lblCVStatusCicleLock.setVisible(false);
	lblCVStatusSearch.setVisible(false);
	lblCVStatusStall.setVisible(false);
	lblCVStatusPatternLock.setVisible(false);

	bxBackground.setBorderColor(Color::getColorFrom24BitRGB(0,0,0));
	bxBackground.invalidate();
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::updateDisplay() {

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

// Message Driver
	if(isDataNotificationReady(&(ds.messageErrors.driverMessage))) {
		ctMessage.setVisible(true);
		Unicode::UnicodeChar buffer[34] = {0};
		uint8_t bufferLength = getMessageLengthDataNotification(&(ds.messageErrors.driverMessage));
		Unicode::strncpy(buffer, getMessageDataNotification(&(ds.messageErrors.driverMessage)), bufferLength);
		Unicode::snprintf(txtToilBuffer, bufferLength, "%s", buffer);
	} else {
		if(ctMessage.isVisible())
			ctMessage.setVisible(false);
	}

// Screen Name
	if(ds.screen.screenNameFlag) {
		bxScreenName.setVisible(true);
		txtScreenName.setVisible(true);
	} else {
		bxScreenName.setVisible(false);
		txtScreenName.setVisible(false);
	}

// RPM
	int rpm = getValueData(&(ds.powerUnit.rpm));
	if(rpm != EMPTY_VALUE) {

		// Set Color RPM Box
		if(rpm >= LOW_RANGE_RPM_MIN && rpm <= LOW_RANGE_RPM_MAX)
			bxRPM.setColor(Color::getColorFrom24BitRGB(0,255,0));		//Color Green
		else if(rpm >= MEDIUM_RANGE_RPM_MIN && rpm <= MEDIUM_RANGE_RPM_MAX)
			bxRPM.setColor(Color::getColorFrom24BitRGB(255,152,0));		//Color Yellow
		else if(rpm >= HIGH_RANGE_RPM_MIN && rpm <= HIGH_RANGE_RPM_MAX)
			bxRPM.setColor(Color::getColorFrom24BitRGB(255,0,0));		//Color Red
		else
			bxRPM.setColor(Color::getColorFrom24BitRGB(0,0,0));			//Color Black

		// Set RPM Box Width
		if(rpm > MAX_RPM)
			rpm = MAX_RPM;

		bxRPM.setWidth(BXRPM_MAX_WIDTH * (rpm) / MAX_RPM);

		if(rpm > 0 && rpm <= 1500) {
			lblRPMOne.setAlpha(255);
			lblRPMTwo.setAlpha(127);
			lblRPMThree.setAlpha(127);
			lblRPMFour.setAlpha(127);
			lblRPMFive.setAlpha(127);
			lblRPMSix.setAlpha(127);
			lblRPMSeven.setAlpha(127);
			lblRPMEight.setAlpha(127);
			lblRPMNine.setAlpha(127);
			lblRPMTen.setAlpha(127);
		} else if(rpm > 1500 && rpm <= 2500) {
			lblRPMOne.setAlpha(255);
			lblRPMTwo.setAlpha(255);
			lblRPMThree.setAlpha(127);
			lblRPMFour.setAlpha(127);
			lblRPMFive.setAlpha(127);
			lblRPMSix.setAlpha(127);
			lblRPMSeven.setAlpha(127);
			lblRPMEight.setAlpha(127);
			lblRPMNine.setAlpha(127);
			lblRPMTen.setAlpha(127);
		} else if(rpm > 2500 && rpm <= 3500) {
			lblRPMOne.setAlpha(255);
			lblRPMTwo.setAlpha(255);
			lblRPMThree.setAlpha(255);
			lblRPMFour.setAlpha(127);
			lblRPMFive.setAlpha(127);
			lblRPMSix.setAlpha(127);
			lblRPMSeven.setAlpha(127);
			lblRPMEight.setAlpha(127);
			lblRPMNine.setAlpha(127);
			lblRPMTen.setAlpha(127);
		} else if(rpm > 3500 && rpm <= 4500) {
			lblRPMOne.setAlpha(255);
			lblRPMTwo.setAlpha(255);
			lblRPMThree.setAlpha(255);
			lblRPMFour.setAlpha(255);
			lblRPMFive.setAlpha(127);
			lblRPMSix.setAlpha(127);
			lblRPMSeven.setAlpha(127);
			lblRPMEight.setAlpha(127);
			lblRPMNine.setAlpha(127);
			lblRPMTen.setAlpha(127);
		} else if(rpm > 4500 && rpm <= 5500) {
			lblRPMOne.setAlpha(255);
			lblRPMTwo.setAlpha(255);
			lblRPMThree.setAlpha(255);
			lblRPMFour.setAlpha(255);
			lblRPMFive.setAlpha(255);
			lblRPMSix.setAlpha(127);
			lblRPMSeven.setAlpha(127);
			lblRPMEight.setAlpha(127);
			lblRPMNine.setAlpha(127);
			lblRPMTen.setAlpha(127);
		} else if(rpm > 5500 && rpm <= 6500) {
			lblRPMOne.setAlpha(255);
			lblRPMTwo.setAlpha(255);
			lblRPMThree.setAlpha(255);
			lblRPMFour.setAlpha(255);
			lblRPMFive.setAlpha(255);
			lblRPMSix.setAlpha(255);
			lblRPMSeven.setAlpha(127);
			lblRPMEight.setAlpha(127);
			lblRPMNine.setAlpha(127);
			lblRPMTen.setAlpha(127);
		} else if(rpm > 6500 && rpm <= 7500) {
			lblRPMOne.setAlpha(255);
			lblRPMTwo.setAlpha(255);
			lblRPMThree.setAlpha(255);
			lblRPMFour.setAlpha(255);
			lblRPMFive.setAlpha(255);
			lblRPMSix.setAlpha(255);
			lblRPMSeven.setAlpha(255);
			lblRPMEight.setAlpha(127);
			lblRPMNine.setAlpha(127);
			lblRPMTen.setAlpha(127);
		} else if(rpm > 7500 && rpm <= 8500) {
			lblRPMOne.setAlpha(255);
			lblRPMTwo.setAlpha(255);
			lblRPMThree.setAlpha(255);
			lblRPMFour.setAlpha(255);
			lblRPMFive.setAlpha(255);
			lblRPMSix.setAlpha(255);
			lblRPMSeven.setAlpha(255);
			lblRPMEight.setAlpha(255);
			lblRPMNine.setAlpha(127);
			lblRPMTen.setAlpha(127);
		} else if(rpm > 8500 && rpm <= 9500) {
			lblRPMOne.setAlpha(255);
			lblRPMTwo.setAlpha(255);
			lblRPMThree.setAlpha(255);
			lblRPMFour.setAlpha(255);
			lblRPMFive.setAlpha(255);
			lblRPMSix.setAlpha(255);
			lblRPMSeven.setAlpha(255);
			lblRPMEight.setAlpha(255);
			lblRPMNine.setAlpha(255);
			lblRPMTen.setAlpha(127);
		} else {
			lblRPMOne.setAlpha(255);
			lblRPMTwo.setAlpha(255);
			lblRPMThree.setAlpha(255);
			lblRPMFour.setAlpha(255);
			lblRPMFive.setAlpha(255);
			lblRPMSix.setAlpha(255);
			lblRPMSeven.setAlpha(255);
			lblRPMEight.setAlpha(255);
			lblRPMNine.setAlpha(255);
			lblRPMTen.setAlpha(255);
		}

		if(rpm >= RPM_LIMIT)
			if(bxRPM.isVisible())
				bxRPM.setVisible(false);
			else
				bxRPM.setVisible(true);
		else
			bxRPM.setVisible(true);

		bxRPM.invalidate();
	}


// SOC
	int soc = getValueData(&(ds.hvElectronicsBMS.soc));
	if(soc != EMPTY_VALUE) {
		if(!bxSoc.isVisible())
			bxSoc.setVisible(true);

		// Set Soc Box Y Position
		int bxSocPositionY = BXSOC_Y_POSITION_MIN - (((BXSOC_Y_POSITION_MIN - BXSOC_Y_POSITION_MAX) * (soc)) / 100);
		if(bxSocPositionY > BXSOC_Y_POSITION_MIN) {
			bxSocPositionY = BXSOC_Y_POSITION_MIN;
		} else if(bxSocPositionY < BXSOC_Y_POSITION_MAX) {
			bxSocPositionY = BXSOC_Y_POSITION_MAX;
		}
		bxSoc.setY(bxSocPositionY);

		// Set Color SOC Box
		if(soc >= LOW_SOC_MIN && soc <= LOW_SOC_MAX) {
			bxSoc.setColor(Color::getColorFrom24BitRGB(255,0,0));		//Color Red
			txtSoc.setColor(Color::getColorFrom24BitRGB(255, 255, 255));
			lblSoc.setColor(Color::getColorFrom24BitRGB(255,255,255));
		} else if(soc >= MEDIUM_SOC_MIN && soc <= MEDIUM_SOC_MAX) {
			bxSoc.setColor(Color::getColorFrom24BitRGB(255,255,0));		//Color Yellow

			if(bxSocPositionY <= 87) {
				lblSoc.setColor(Color::getColorFrom24BitRGB(0,0,0));
				txtSoc.setColor(Color::getColorFrom24BitRGB(0,0,0));
			} else if(bxSocPositionY < 105 && bxSocPositionY > 87) {
				lblSoc.setColor(Color::getColorFrom24BitRGB(255,255,255));
				txtSoc.setColor(Color::getColorFrom24BitRGB(0,0,0));
			} else if(bxSocPositionY >= 105) {
				lblSoc.setColor(Color::getColorFrom24BitRGB(255,255,255));
				txtSoc.setColor(Color::getColorFrom24BitRGB(255,255,255));
			}

		} else if(soc >= HIGH_SOC_MIN && soc <= HIGH_SOC_MAX) {
			bxSoc.setColor(Color::getColorFrom24BitRGB(0,255,0));		//Color Green
			txtSoc.setColor(Color::getColorFrom24BitRGB(0, 0, 0));
			lblSoc.setColor(Color::getColorFrom24BitRGB(0, 0, 0));
		}

		if(isDataUpdated(&(ds.hvElectronicsBMS.soc)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[9] = {0};
			//Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, 6);
			Unicode::strncpy(buffer, "NO\nDATA", 8);
			Unicode::snprintf(txtSocBuffer, 9, "%s", buffer);

			txtSoc.setColor(Color::getColorFrom24BitRGB(255, 255, 255));
			lblSoc.setColor(Color::getColorFrom24BitRGB(255,255,255));
			bxSoc.setColor(Color::getColorFrom24BitRGB(0,0,0));				//Color Black
		} else {
			// Set Text
			Unicode::snprintfFloat(txtSocBuffer, TXTSOC_SIZE-1, "%.1f", soc);
		}

		txtPoil.invalidate();
		bxSoc.invalidate();
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

// cvEngineStatus
	uint8_t cvEngineStatus = getDataStatus(&(ds.powerUnit.engineStateCV));
	if(cvEngineStatus != EMPTY_VALUE) {
		if(cvEngineStatus == 3) {	// Error
			lblCVStatusError.setVisible(true);
			lblCVStatusCicleLock.setVisible(false);
			lblCVStatusSearch.setVisible(false);
			lblCVStatusStall.setVisible(false);
			lblCVStatusPatternLock.setVisible(false);
		} else if(cvEngineStatus == 2) { // Cicle Lock
			lblCVStatusError.setVisible(false);
			lblCVStatusCicleLock.setVisible(true);
			lblCVStatusSearch.setVisible(false);
			lblCVStatusStall.setVisible(false);
			lblCVStatusPatternLock.setVisible(false);
		} else if(cvEngineStatus == 10) { // Stall
			lblCVStatusError.setVisible(false);
			lblCVStatusCicleLock.setVisible(false);
			lblCVStatusSearch.setVisible(false);
			lblCVStatusStall.setVisible(true);
			lblCVStatusPatternLock.setVisible(false);
		} else if(cvEngineStatus == 0) { // Search
			lblCVStatusError.setVisible(false);
			lblCVStatusCicleLock.setVisible(false);
			lblCVStatusSearch.setVisible(true);
			lblCVStatusStall.setVisible(false);
			lblCVStatusPatternLock.setVisible(false);
		} else if(cvEngineStatus == 1) { // Pattern Lock
			lblCVStatusError.setVisible(false);
			lblCVStatusCicleLock.setVisible(false);
			lblCVStatusSearch.setVisible(false);
			lblCVStatusStall.setVisible(false);
			lblCVStatusPatternLock.setVisible(true);
		} else {
			lblCVStatusError.setVisible(false);
			lblCVStatusCicleLock.setVisible(false);
			lblCVStatusSearch.setVisible(false);
			lblCVStatusStall.setVisible(false);
			lblCVStatusPatternLock.setVisible(false);
		}
	} else {
		lblCVStatusError.setVisible(false);
		lblCVStatusCicleLock.setVisible(false);
		lblCVStatusSearch.setVisible(false);
		lblCVStatusStall.setVisible(false);
		lblCVStatusPatternLock.setVisible(false);
	}


// Poil
	float pOil = getValueData(&(ds.powerUnit.oilPressure));
	if(pOil != EMPTY_VALUE) {
		if(!bxPoil.isVisible())
			bxPoil.setVisible(true);

		// Set Color Poil
		if(pOil >= LOW_POIL_MIN && pOil <= LOW_POIL_MAX) {
			bxPoil.setColor(Color::getColorFrom24BitRGB(255,0,0));				//Color Red
			//lblPoil.setColor(Color::getColorFrom24BitRGB(255,255,255));
		} else if(pOil >= MEDIUM_POIL_MIN && pOil <= MEDIUM_POIL_MAX) {
			bxPoil.setColor(Color::getColorFrom24BitRGB(0,0,0));				//Color Black
			//lblPoil.setColor(Color::getColorFrom24BitRGB(255,255,255));
		} else if(pOil >= HIGH_POIL_MIN && pOil <= HIGH_POIL_MAX) {
			bxPoil.setColor(Color::getColorFrom24BitRGB(255,0,0));				//Color Red
			//lblPoil.setColor(Color::getColorFrom24BitRGB(0,0,0));
		}

		if(isDataUpdated(&(ds.powerUnit.oilPressure)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[7] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, 6);
			Unicode::snprintf(txtPoilBuffer, 7, "%s", buffer);

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
			Unicode::UnicodeChar buffer[7] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, 6);
			Unicode::snprintf(txtToilBuffer, 7, "%s", buffer);

			bxToil.setColor(Color::getColorFrom24BitRGB(0,0,0));				//Color Black
		} else {
			// Set Text
			Unicode::snprintfFloat(txtToilBuffer, TXTTOIL_SIZE-1, "%.1f", tOil);
		}

		bxToil.invalidate();
		txtToil.invalidate();
	}

// Map

	float map = getValueData(&(ds.powerUnit.map));
	if(map != EMPTY_VALUE) {
		if(!bxMap.isVisible())
			bxMap.setVisible(true);

		if(isDataUpdated(&(ds.powerUnit.map)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[7] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, 6);
			Unicode::snprintf(txtMapBuffer, 7, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintfFloat(txtMapBuffer, TXTMAP_SIZE-1, "%.2f", map);
		}

		txtMap.invalidate();
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
			Unicode::UnicodeChar buffer[7] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, 6);
			Unicode::snprintf(txtTwaterCBuffer, 7, "%s", buffer);

			bxTwaterC.setColor(Color::getColorFrom24BitRGB(0,0,0));				//Color Black
		} else {
			// Set Text
			Unicode::snprintfFloat(txtTwaterCBuffer, TXTTWATERC_SIZE-1, "%.1f", tWaterC);
		}

		bxTwaterC.invalidate();
		txtTwaterC.invalidate();
	}

// TwaterE
	float tWaterE = getValueData(&(ds.thermalAerodynamics.coolantTemperatureEV));
	if(tWaterE != EMPTY_VALUE) {
		if(!bxTwaterE.isVisible())
			bxTwaterE.setVisible(true);

		// Set Color
		if(tWaterE >= LOW_TWATERE_MIN && tWaterE <= LOW_TWATERE_MAX) {
			bxTwaterE.setColor(Color::getColorFrom24BitRGB(0,0,255));						//Color Blue
			//lblTwaterE.setColor(Color::getColorFrom24BitRGB(0,0,0));
		} else if(tWaterE >= MEDIUM_TWATERE_MIN && tWaterE <= MEDIUM_TWATERE_MAX) {
			bxTwaterE.setColor(Color::getColorFrom24BitRGB(0,0,0));		 					//Color Black
			//lblTwaterE.setColor(Color::getColorFrom24BitRGB(255,255,255));
		} else if(tWaterE >= HIGH_TWATERE_MIN && tWaterE <= HIGH_TWATERE_MAX) {
			bxTwaterE.setColor(Color::getColorFrom24BitRGB(255,0,0));						//Color Red

			// Set Fade TwaterE
			// Range between 127-255
			uint8_t fadeValue = 255;
			if(tWaterE >= HIGH_TWATERE_WARNING_START && tWaterE <= HIGH_TWATERE_WARNING_START)
				fadeValue = (((FADE_MIN+1) / (HIGH_TWATERE_WARNING_END - HIGH_TWATERE_WARNING_START)) * (tWaterE * HIGH_TWATERE_WARNING_START) + (FADE_MIN));

			bxTwaterE.setAlpha(fadeValue);

			//lblTwaterE.setColor(Color::getColorFrom24BitRGB(0,0,0));
		}

		if(isDataUpdated(&(ds.thermalAerodynamics.coolantTemperatureEV)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[7] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, 6);
			Unicode::snprintf(txtTwaterEBuffer, 7, "%s", buffer);

			bxTwaterE.setColor(Color::getColorFrom24BitRGB(0,0,0));		 			//Color Black
		} else {
			// Set Text
			Unicode::snprintfFloat(txtTwaterEBuffer, TXTTWATERE_SIZE-1, "%.1f", tWaterE);
		}

		bxTwaterE.invalidate();
		txtTwaterE.invalidate();
	}

// TbatHV
	float tBatHV = getValueData(&(ds.hvElectronicsBMS.batteryTMH));
	if(tBatHV != EMPTY_VALUE) {
		if(!bxTbat.isVisible())
			bxTbat.setVisible(true);

		// Set Color
		if(tBatHV >= LOW_TBATHV_MIN && tBatHV <= LOW_TBATHV_MAX) {
			bxTbat.setColor(Color::getColorFrom24BitRGB(0,0,255));							//Color Blue
			//lblTbat.setColor(Color::getColorFrom24BitRGB(0,0,0));
		} else if(tBatHV >= MEDIUM_TBATHV_MIN && tBatHV <= MEDIUM_TBATHV_MAX) {
			bxTbat.setColor(Color::getColorFrom24BitRGB(0,0,0));		 					//Color Black
			//lblTbat.setColor(Color::getColorFrom24BitRGB(255,255,255));
		} else if(tBatHV >= HIGH_TBATHV_MIN && tBatHV <= HIGH_TBATHV_MAX) {
			bxTbat.setColor(Color::getColorFrom24BitRGB(255,0,0));							//Color Red
			//lblTbat.setColor(Color::getColorFrom24BitRGB(0,0,0));
		}

		if(isDataUpdated(&(ds.hvElectronicsBMS.batteryTMH)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[7] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, 6);
			Unicode::snprintf(txtTbatBuffer, 7, "%s", buffer);

			bxTbat.setColor(Color::getColorFrom24BitRGB(0,0,0));		 					//Color Black
		} else {
			// Set Text
			Unicode::snprintfFloat(txtTbatBuffer, TXTTBAT_SIZE-1, "%.1f", tBatHV);
		}

		txtTbat.invalidate();
		bxTbat.invalidate();
	}

// DISPLAY

	bxBackground.invalidate();
}
