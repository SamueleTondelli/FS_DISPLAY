#include <gui/screen6_screen/Screen6View.hpp>

#include <touchgfx/Color.hpp>

#include "Data/Dataset.h"
#include "Data/DataStatus.h"
#include "Data/DataConstantNotification.h"
#include "DisplayConstant.h"
#include "TimerHandler.h"

extern Dataset ds;

Screen6View::Screen6View()
{
	ctAlarm.setVisible(false);

	ctMessage.setVisible(false);

	ctScreenName.setVisible(true);

	bxRpm.setVisible(false);
	bxToil.setVisible(false);
	bxEmMaxSpeed.setVisible(false);
	bxEmMaxTorque.setVisible(false);
	bxTps.setVisible(false);

	bxInvId.setVisible(false);
	bxInvIq.setVisible(false);
	bxInvBatCurrent.setVisible(false);

	bxInvTargetID.setVisible(false);
	bxInvTargetIQ.setVisible(false);
	bxInvBatVoltage.setVisible(false);

	bxTwaterC.setVisible(false);
	bxTwaterE.setVisible(false);
	bxInvTemp.setVisible(false);
	bxInvCapacitorVoltage.setVisible(false);

	bxBackground.setBorderColor(Color::getColorFrom24BitRGB(0,0,0));
	bxBackground.invalidate();
}

void Screen6View::setupScreen()
{
    Screen6ViewBase::setupScreen();
}

void Screen6View::tearDownScreen()
{
    Screen6ViewBase::tearDownScreen();
}

void Screen6View::updateDisplay() {

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
		bxScreenName.setVisible(true);
		txtScreenName.setVisible(true);
	} else {
		bxScreenName.setVisible(false);
		txtScreenName.setVisible(false);
	}

//FPS
	int fps = getFpsScreen(&(ds.screen));
	if(fps != EMPTY_VALUE) {
		// Set Text
		Unicode::snprintf(txtFpsBuffer, TXTFPS_SIZE-1, "%d", fps);
		txtFps.invalidate();
	}

// can2Diagnostic
	int can2diagnostic = getDataStatus(&(ds.lvElectronics.can2Diagnostic));
	if(can2diagnostic != EMPTY_VALUE) {

		Unicode::UnicodeChar buffer[TXTCAN2DIAGNOSTIC_SIZE] = {0};
		uint8_t statusLength = getCurrentDataStatusLength(&(ds.lvElectronics.can2Diagnostic));
		if(statusLength > (TXTCAN2DIAGNOSTIC_SIZE-1)) {
			Unicode::strncpy(buffer, DATA_STATUS_ERROR, DATA_STATUS_ERROR_LENGTH);
		} else {
			Unicode::strncpy(buffer, getCurrentDataStatus(&(ds.lvElectronics.can2Diagnostic)), statusLength);
			Unicode::snprintf(txtCan2DiagnosticBuffer, TXTCAN2DIAGNOSTIC_SIZE-1, "%s", buffer);
		}
	}

// RPM
	int rpm = getValueData(&(ds.powerUnit.rpm));
	if(rpm != EMPTY_VALUE) {

		// Set Color RPM Box
		if(rpm >= LOW_RANGE_RPM_MIN && rpm <= LOW_RANGE_RPM_MAX)
			txtRpm.setColor(Color::getColorFrom24BitRGB(0,255,0));			//Color Green
		else if(rpm >= MEDIUM_RANGE_RPM_MIN && rpm <= MEDIUM_RANGE_RPM_MAX)
			txtRpm.setColor(Color::getColorFrom24BitRGB(255,255,0));		//Color Yellow
		else if(rpm >= HIGH_RANGE_RPM_MIN && rpm <= HIGH_RANGE_RPM_MAX)
			txtRpm.setColor(Color::getColorFrom24BitRGB(255,0,0));			//Color Red
		else
			txtRpm.setColor(Color::getColorFrom24BitRGB(0,0,0));			//Color Black

		if(rpm >= RPM_LIMIT) {
			txtRpm.setColor(Color::getColorFrom24BitRGB(255,255,255));		//Color White
			bxRpm.setColor(Color::getColorFrom24BitRGB(255,0,0));			//Color Red

			if(bxRpm.isVisible())
				bxRpm.setVisible(false);
			else
				bxRpm.setVisible(true);
		} else {
			bxRpm.setVisible(false);
		}

		if(isDataUpdated(&(ds.powerUnit.rpm)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtRpmBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
			txtRpm.setColor(Color::getColorFrom24BitRGB(255,255,255));			//Color White
			bxRpm.setVisible(false);
		} else {
			Unicode::snprintf(txtRpmBuffer, TXTRPM_SIZE-1, "%d", rpm);
		}

		txtRpm.invalidate();
		bxRpm.invalidate();
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
			//bxToil.setColor(Color::getColorFrom24BitRGB(255,0,0));				//Color Red

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

// EmMaxSpeed
	int emMaxSpeed = getValueData(&(ds.hvElectronicsInverter.inverterSpeedMax));
	if(emMaxSpeed != EMPTY_VALUE) {

		if(isDataUpdated(&(ds.hvElectronicsInverter.inverterSpeedMax)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtEmMaxSpeedBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintf(txtEmMaxSpeedBuffer, TXTEMMAXSPEED_SIZE-1, "%d", emMaxSpeed);
		}

		txtEmMaxSpeed.invalidate();
	}

// EmMaxTorque
	int emMaxTorque = getValueData(&(ds.hvElectronicsInverter.inverterTorqueMax));
	if(emMaxTorque != EMPTY_VALUE) {

		if(isDataUpdated(&(ds.hvElectronicsInverter.inverterTorqueMax)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtEmMaxTorqueBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintf(txtEmMaxTorqueBuffer, TXTEMMAXTORQUE_SIZE-1, "%d", emMaxTorque);
		}

		txtEmMaxTorque.invalidate();
	}

// tps
	float tps1 = getValueData(&(ds.lvElectronics.tps1));
	if(tps1 != EMPTY_VALUE) {

		if(isDataUpdated(&(ds.lvElectronics.tps1)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtTpsBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintfFloat(txtTpsBuffer, TXTTPS_SIZE-1, "%.1f", tps1);
		}

		txtTps.invalidate();
	}

// invId
	float invId = getValueData(&(ds.hvElectronicsInverter.currentID));
	if(invId != EMPTY_VALUE) {

		if(isDataUpdated(&(ds.hvElectronicsInverter.currentID)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtInvIdBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintfFloat(txtInvIdBuffer, TXTINVID_SIZE-1, "%f", invId);
		}

		txtInvId.invalidate();
	}

// invIq
	float invIq = getValueData(&(ds.hvElectronicsInverter.currentIQ));
	if(invIq != EMPTY_VALUE) {

		if(isDataUpdated(&(ds.hvElectronicsInverter.currentIQ)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtInvIqBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintfFloat(txtInvIqBuffer, TXTINVIQ_SIZE-1, "%f", invId);
		}

		txtInvIq.invalidate();
	}

// invBatCurrent
	float invBatCurrent = getValueData(&(ds.hvElectronicsInverter.inverterBatteryCurrent));
	if(invBatCurrent != EMPTY_VALUE) {

		if(isDataUpdated(&(ds.hvElectronicsInverter.inverterBatteryCurrent)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtInvBatCurrentBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintfFloat(txtInvBatCurrentBuffer, TXTINVBATCURRENT_SIZE-1, "%f", invBatCurrent);
		}

		txtInvBatCurrent.invalidate();
	}

// invTargerId
	float invTargetID = getValueData(&(ds.hvElectronicsInverter.targetID));
	if(invTargetID != EMPTY_VALUE) {

		if(isDataUpdated(&(ds.hvElectronicsInverter.targetID)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtInvTargetIDBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintfFloat(txtInvTargetIDBuffer, TXTINVTARGETID_SIZE-1, "%f", invTargetID);
		}

		txtInvTargetID.invalidate();
	}

// invTargetIq
	float invTargetIQ = getValueData(&(ds.hvElectronicsInverter.targetIQ));
	if(invTargetIQ != EMPTY_VALUE) {

		if(isDataUpdated(&(ds.hvElectronicsInverter.targetIQ)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtInvTargetIQBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintfFloat(txtInvTargetIQBuffer, TXTINVTARGETIQ_SIZE-1, "%f", invTargetIQ);
		}

		txtInvTargetIQ.invalidate();
	}

// invBatVoltage
	float invBatVoltage = getValueData(&(ds.hvElectronicsInverter.inverterBatteryVoltage));
	if(invBatVoltage != EMPTY_VALUE) {

		if(isDataUpdated(&(ds.hvElectronicsInverter.inverterBatteryVoltage)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtInvBatVoltageBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintfFloat(txtInvBatVoltageBuffer, TXTINVBATVOLTAGE_SIZE-1, "%f", invBatVoltage);
		}

		txtInvBatVoltage.invalidate();
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

// TwaterE
	float tWaterE = getValueData(&(ds.thermalAerodynamics.coolantTemperatureEV));
	if(tWaterE != EMPTY_VALUE) {
		if(!bxTwaterE.isVisible())
			bxTwaterE.setVisible(true);

		// Set Color
		if(tWaterE >= LOW_TWATERE_MIN && tWaterE <= LOW_TWATERE_MAX) {
			bxTwaterE.setColor(Color::getColorFrom24BitRGB(0,0,255));						//Color Blue

			// Set Fade TwaterE
			//uint8_t avgValue = ((LOW_TWATERE_MAX-LOW_TWATERE_MIN));	//TODO Set Fade
			//bxTwaterE.setAlpha(avgValue);

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
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtTwaterEBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);

			bxTwaterE.setColor(Color::getColorFrom24BitRGB(0,0,0));		 					//Color Black
		} else {
			// Set Text
			Unicode::snprintfFloat(txtTwaterEBuffer, TXTTWATERE_SIZE-1, "%.1f", tWaterE);
		}

		bxTwaterE.invalidate();
		txtTwaterE.invalidate();
	}

// InverterTemperature
	float inverterTemperature = getValueData(&(ds.hvElectronicsInverter.inverterTemperature));
	if(inverterTemperature != EMPTY_VALUE) {

		//TODO Settare colori box

		if(isDataUpdated(&(ds.hvElectronicsInverter.inverterTemperature)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtInvTempBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintfFloat(txtInvTempBuffer, TXTINVTEMP_SIZE-1, "%.1f", inverterTemperature);
		}

		txtInvTemp.invalidate();
	}

// invCapacitorVoltage
	float invCapacitorVoltage = getValueData(&(ds.hvElectronicsInverter.inverterCapacitorVoltage));
	if(invCapacitorVoltage != EMPTY_VALUE) {

		if(isDataUpdated(&(ds.hvElectronicsInverter.inverterCapacitorVoltage)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtInvCapacitorVoltageBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintfFloat(txtInvCapacitorVoltageBuffer, TXTINVCAPACITORVOLTAGE_SIZE-1, "%.1f", invCapacitorVoltage);
		}

		txtInvCapacitorVoltage.invalidate();
	}

// DISPLAY

	bxBackground.invalidate();
}


