#include <gui/screen2_screen/Screen2View.hpp>

#include <touchgfx/Color.hpp>

#include "Data/Dataset.h"
#include "Data/DataConstantNotification.h"
#include "DisplayConstant.h"
#include "TimerHandler.h"

#define DEBUG_SCREEN2VIEW 1

extern Dataset ds;

#ifdef DEBUG_SCREEN2VIEW
// DEBUG
extern long counterMessages;
#endif

Screen2View::Screen2View()
{
	ctAlarm.setVisible(false);

	ctMessage.setVisible(false);

	ctScreenName.setVisible(true);

	bxSoc.setVisible(false);

	bxPoil.setVisible(false);
	bxToil.setVisible(false);
	bxMap.setVisible(false);

	bxTwaterC.setVisible(false);
	bxVbatLV.setVisible(false);
	bxTbat.setVisible(false);

	bxBackground.setBorderColor(Color::getColorFrom24BitRGB(0,0,0));
	bxBackground.invalidate();
}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::updateDisplay() {
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

// Message
	if(ds.screen.notificationFlag) {
		ctMessage.setVisible(true);

		Unicode::UnicodeChar buffer[35] = {0};
		uint8_t bufferLength = getMessageLengthDataNotification(&(ds.messageErrors.driverMessage));
		Unicode::strncpy(buffer, getMessageDataNotification(&(ds.messageErrors.driverMessage)), bufferLength);
		Unicode::snprintf(txtMessageBuffer, TXTMESSAGE_SIZE-1, "%s", buffer);
		if(isDataNotificationAlarmType(&(ds.messageErrors))) {
			bxMessage.setBorderColor(Color::getColorFrom24BitRGB(255,0,0));		// Alarm -> Red
		} else if(isDataNotificationWarningType(&(ds.messageErrors))) {
			bxMessage.setBorderColor(Color::getColorFrom24BitRGB(255,255,0));	// Warning -> Yellow
		} else if(isDataNotificationDriverType(&(ds.messageErrors))){
			bxMessage.setBorderColor(Color::getColorFrom24BitRGB(0,255,0));		// Driver -> Green
		}
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
		if(rpm >= LOW_RANGE_RPM_MIN && rpm <= LOW_RANGE_RPM_MAX) {
			bxRPM.setColor(Color::getColorFrom24BitRGB(0,255,0));		//Color Green
			clRPMPainter.setColor(Color::getColorFrom24BitRGB(0,255,0));
		} else if(rpm >= MEDIUM_RANGE_RPM_MIN && rpm <= MEDIUM_RANGE_RPM_MAX) {
			bxRPM.setColor(Color::getColorFrom24BitRGB(255,152,0));		//Color Yellow
			clRPMPainter.setColor(Color::getColorFrom24BitRGB(255,152,0));
		} else if(rpm >= HIGH_RANGE_RPM_MIN && rpm <= HIGH_RANGE_RPM_MAX) {
			bxRPM.setColor(Color::getColorFrom24BitRGB(255,0,0));		//Color Red
			clRPMPainter.setColor(Color::getColorFrom24BitRGB(255,0,0));
		} else {
			bxRPM.setColor(Color::getColorFrom24BitRGB(255,255,255));	//Color White
			clRPMPainter.setColor(Color::getColorFrom24BitRGB(255,255,255));
		}

		if(rpm > RPM_CIRCLE) {
			if(rpm > MAX_RPM)
				rpm = MAX_RPM;
			bxRPM.setWidth(BOX_RPM_WIDTH * (rpm - RPM_CIRCLE) / (MAX_RPM-RPM_CIRCLE));
			clRPM.setArc(180, 360);
		} else {
			bxRPM.setWidth(0);
			clRPM.setArc(180, ((rpm * 180) / RPM_CIRCLE) + 180);
		}

		if(rpm > 0 && rpm <= 1500) {
			txtRPMOne.setAlpha(255);
			txtRPMTwo.setAlpha(127);
			txtRPMThree.setAlpha(127);
			txtRPMFour.setAlpha(127);
			txtRPMFive.setAlpha(127);
			txtRPMSix.setAlpha(127);
			txtRPMSeven.setAlpha(127);
			txtRPMEight.setAlpha(127);
			txtRPMNine.setAlpha(127);
			txtRPMTen.setAlpha(127);
		} else if(rpm > 1500 && rpm <= 2500) {
			txtRPMOne.setAlpha(255);
			txtRPMTwo.setAlpha(255);
			txtRPMThree.setAlpha(127);
			txtRPMFour.setAlpha(127);
			txtRPMFive.setAlpha(127);
			txtRPMSix.setAlpha(127);
			txtRPMSeven.setAlpha(127);
			txtRPMEight.setAlpha(127);
			txtRPMNine.setAlpha(127);
			txtRPMTen.setAlpha(127);
		} else if(rpm > 2500 && rpm <= 3500) {
			txtRPMOne.setAlpha(255);
			txtRPMTwo.setAlpha(255);
			txtRPMThree.setAlpha(255);
			txtRPMFour.setAlpha(127);
			txtRPMFive.setAlpha(127);
			txtRPMSix.setAlpha(127);
			txtRPMSeven.setAlpha(127);
			txtRPMEight.setAlpha(127);
			txtRPMNine.setAlpha(127);
			txtRPMTen.setAlpha(127);
		} else if(rpm > 3500 && rpm <= 4500) {
			txtRPMOne.setAlpha(255);
			txtRPMTwo.setAlpha(255);
			txtRPMThree.setAlpha(255);
			txtRPMFour.setAlpha(255);
			txtRPMFive.setAlpha(127);
			txtRPMSix.setAlpha(127);
			txtRPMSeven.setAlpha(127);
			txtRPMEight.setAlpha(127);
			txtRPMNine.setAlpha(127);
			txtRPMTen.setAlpha(127);
		} else if(rpm > 4500 && rpm <= 5500) {
			txtRPMOne.setAlpha(255);
			txtRPMTwo.setAlpha(255);
			txtRPMThree.setAlpha(255);
			txtRPMFour.setAlpha(255);
			txtRPMFive.setAlpha(255);
			txtRPMSix.setAlpha(127);
			txtRPMSeven.setAlpha(127);
			txtRPMEight.setAlpha(127);
			txtRPMNine.setAlpha(127);
			txtRPMTen.setAlpha(127);
		} else if(rpm > 5500 && rpm <= 6500) {
			txtRPMOne.setAlpha(255);
			txtRPMTwo.setAlpha(255);
			txtRPMThree.setAlpha(255);
			txtRPMFour.setAlpha(255);
			txtRPMFive.setAlpha(255);
			txtRPMSix.setAlpha(255);
			txtRPMSeven.setAlpha(127);
			txtRPMEight.setAlpha(127);
			txtRPMNine.setAlpha(127);
			txtRPMTen.setAlpha(127);
		} else if(rpm > 6500 && rpm <= 7500) {
			txtRPMOne.setAlpha(255);
			txtRPMTwo.setAlpha(255);
			txtRPMThree.setAlpha(255);
			txtRPMFour.setAlpha(255);
			txtRPMFive.setAlpha(255);
			txtRPMSix.setAlpha(255);
			txtRPMSeven.setAlpha(255);
			txtRPMEight.setAlpha(127);
			txtRPMNine.setAlpha(127);
			txtRPMTen.setAlpha(127);
		} else if(rpm > 7500 && rpm <= 8500) {
			txtRPMOne.setAlpha(255);
			txtRPMTwo.setAlpha(255);
			txtRPMThree.setAlpha(255);
			txtRPMFour.setAlpha(255);
			txtRPMFive.setAlpha(255);
			txtRPMSix.setAlpha(255);
			txtRPMSeven.setAlpha(255);
			txtRPMEight.setAlpha(255);
			txtRPMNine.setAlpha(127);
			txtRPMTen.setAlpha(127);
		} else if(rpm > 8500 && rpm <= 9500) {
			txtRPMOne.setAlpha(255);
			txtRPMTwo.setAlpha(255);
			txtRPMThree.setAlpha(255);
			txtRPMFour.setAlpha(255);
			txtRPMFive.setAlpha(255);
			txtRPMSix.setAlpha(255);
			txtRPMSeven.setAlpha(255);
			txtRPMEight.setAlpha(255);
			txtRPMNine.setAlpha(255);
			txtRPMTen.setAlpha(127);
		} else {
			txtRPMOne.setAlpha(255);
			txtRPMTwo.setAlpha(255);
			txtRPMThree.setAlpha(255);
			txtRPMFour.setAlpha(255);
			txtRPMFive.setAlpha(255);
			txtRPMSix.setAlpha(255);
			txtRPMSeven.setAlpha(255);
			txtRPMEight.setAlpha(255);
			txtRPMNine.setAlpha(255);
			txtRPMTen.setAlpha(255);
		}

		if(rpm >= RPM_LIMIT) {
			if(bxRPM.isVisible()) {
				bxRPM.setVisible(false);
				clRPM.setVisible(false);
			} else {
				bxRPM.setVisible(true);
				clRPM.setVisible(true);
			}
		} else {
			bxRPM.setVisible(true);
			clRPM.setVisible(true);
		}

		bxRPM.invalidate();
		clRPM.invalidate();
	} else {

		txtRPMOne.setAlpha(255);
		txtRPMTwo.setAlpha(255);
		txtRPMThree.setAlpha(255);
		txtRPMFour.setAlpha(255);
		txtRPMFive.setAlpha(255);
		txtRPMSix.setAlpha(255);
		txtRPMSeven.setAlpha(255);
		txtRPMEight.setAlpha(255);
		txtRPMNine.setAlpha(255);
		txtRPMTen.setAlpha(255);

		bxRPM.setVisible(false);
		clRPM.setVisible(false);
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

			if(bxSocPositionY <= 82) {
				lblSoc.setColor(Color::getColorFrom24BitRGB(0,0,0));
				txtSoc.setColor(Color::getColorFrom24BitRGB(0,0,0));
			} else if(bxSocPositionY < 105 && bxSocPositionY > 82) {
				lblSoc.setColor(Color::getColorFrom24BitRGB(255,255,255));
				txtSoc.setColor(Color::getColorFrom24BitRGB(0,0,0));
			} else if(bxSocPositionY >= 105) {
				lblSoc.setColor(Color::getColorFrom24BitRGB(255,255,255));
				txtSoc.setColor(Color::getColorFrom24BitRGB(255,255,255));
			}

		} else if(soc >= HIGH_SOC_MIN && soc <= HIGH_SOC_MAX) {
			bxSoc.setColor(Color::getColorFrom24BitRGB(0,255,0));		//Color Green
			txtSoc.setColor(Color::getColorFrom24BitRGB(0,0,0));
			lblSoc.setColor(Color::getColorFrom24BitRGB(0,0,0));
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
			Unicode::snprintf(txtSocBuffer, TXTSOC_SIZE-1, "%d", soc);
		}

		bxSoc.invalidate();
		txtSoc.invalidate();
		lblSoc.invalidate();
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

// Poil

	float pOil = getValueData(&(ds.powerUnit.oilPressure));
	if(pOil != EMPTY_VALUE) {
		if(!bxPoil.isVisible())
			bxPoil.setVisible(true);

		// Set Color Poil
		if(pOil >= LOW_POIL_MIN && pOil <= LOW_POIL_MAX) {
			bxPoil.setColor(Color::getColorFrom24BitRGB(255,0,0));				//Color Red
			//lblPoil.setColor(Color::getColorFrom24BitRGB(0,0,0));
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
	float map = /*getValueData(&(ds.powerUnit.map));*/counterMessages;
	if(map != EMPTY_VALUE) {
		if(!bxMap.isVisible())
			bxMap.setVisible(true);
/*
		if(isDataUpdated(&(ds.powerUnit.map)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtMapBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintfFloat(txtMapBuffer, TXTMAP_SIZE-1, "%.2f", map);
		}
*/
		// DEBUG
		Unicode::snprintf(txtMapBuffer, TXTMAP_SIZE-1, "%d", counterMessages);

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

			bxTwaterC.setColor(Color::getColorFrom24BitRGB(0,0,0));		 					//Color Black
		} else {
			// Set Text
			Unicode::snprintfFloat(txtTwaterCBuffer, TXTTWATERC_SIZE-1, "%.1f", tWaterC);
		}

		bxTwaterC.invalidate();
		txtTwaterC.invalidate();
	}

// VbatLV
	float vBatLV = getValueData(&(ds.lvElectronics.voltageBatteryLV));
	if(vBatLV != EMPTY_VALUE) {// TODO Controllare
		if(!bxVbatLV.isVisible())
			bxVbatLV.setVisible(true);

		// Set Color SOC Box
		if(vBatLV >= LOW_VBATLV_MIN && vBatLV <= LOW_VBATLV_MAX) {
			bxVbatLV.setColor(Color::getColorFrom24BitRGB(255,0,0));		//Color Red
			//lblVbatLV.setColor(Color::getColorFrom24BitRGB(0,0,0));
		} else if(vBatLV >= MEDIUM_VBATLV_MIN && vBatLV <= MEDIUM_VBATLV_MAX) {
			bxVbatLV.setColor(Color::getColorFrom24BitRGB(0,0,0));			//Color Black
			//lblVbatLV.setColor(Color::getColorFrom24BitRGB(255,255,255));
		} else if(vBatLV >= HIGH_VBATLV_MIN && vBatLV <= HIGH_VBATLV_MAX) {
			bxVbatLV.setColor(Color::getColorFrom24BitRGB(255,0,0));		//Color Red
			//lblVbatLV.setColor(Color::getColorFrom24BitRGB(0,0,0));
		}

		if(isDataUpdated(&(ds.lvElectronics.voltageBatteryLV)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[7] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, 6);
			Unicode::snprintf(txtVbatLVBuffer, 7, "%s", buffer);

			bxVbatLV.setColor(Color::getColorFrom24BitRGB(0,0,0));			//Color Black
		} else {
			// Set Text
			Unicode::snprintfFloat(txtVbatLVBuffer, TXTTWATERC_SIZE-1, "%.1f", vBatLV);
		}

		txtVbatLV.invalidate();
		bxVbatLV.invalidate();
	}

// TbatHV
	float tBatHV = getValueData(&(ds.hvElectronicsBMS.batteryTMH));
	if(tBatHV != EMPTY_VALUE) {
		if(!bxTbat.isVisible())
			bxTbat.setVisible(true);

		// Set Color
		if(tBatHV >= LOW_TBATHV_MIN && tBatHV <= LOW_TBATHV_MAX) {
			bxTbat.setColor(Color::getColorFrom24BitRGB(0,0,255));						//Color Blue
			//lblTbat.setColor(Color::getColorFrom24BitRGB(0,0,0));
		} else if(tBatHV >= MEDIUM_TBATHV_MIN && tBatHV <= MEDIUM_TBATHV_MAX) {
			bxTbat.setColor(Color::getColorFrom24BitRGB(0,0,0));		 				//Color Black
			//lblTbat.setColor(Color::getColorFrom24BitRGB(255,255,255));
		} else if(tBatHV >= HIGH_TBATHV_MIN && tBatHV <= HIGH_TBATHV_MAX) {
			bxTbat.setColor(Color::getColorFrom24BitRGB(255,0,0));						//Color Red
			//lblTbat.setColor(Color::getColorFrom24BitRGB(0,0,0));
		}

		if(isDataUpdated(&(ds.hvElectronicsBMS.batteryTMH)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[7] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, 6);
			Unicode::snprintf(txtTbatBuffer, 7, "%s", buffer);

			bxTbat.setColor(Color::getColorFrom24BitRGB(0,0,0));		 				//Color Black
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
