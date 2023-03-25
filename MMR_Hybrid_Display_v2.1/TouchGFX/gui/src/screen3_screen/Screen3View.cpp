#include <gui/screen3_screen/Screen3View.hpp>

#include <touchgfx/Color.hpp>

#include "Data/Dataset.h"
#include "Data/DataStatus.h"
#include "Data/DataConstantNotification.h"
#include "DisplayConstant.h"
#include "TimerHandler.h"

extern Dataset ds;

Screen3View::Screen3View()
{

	ctAlarm.setVisible(false);

	ctMessage.setVisible(false);

	ctScreenName.setVisible(true);

	bxRpm.setVisible(false);
	bxToil.setVisible(false);
	bxPoil.setVisible(false);
	bxMap.setVisible(false);
	bxTps.setVisible(false);

	bxTbat.setVisible(false);
	bxSoc.setVisible(false);
	bxEmTemp.setVisible(false);

	bxVbatHV.setVisible(false);
	bxVbatLV.setVisible(false);
	bxInvTemp.setVisible(false);

	bxTwaterC.setVisible(false);
	bxTwaterE.setVisible(false);
	bxTair.setVisible(false);
	bxBpps.setVisible(false);

	bxBackground.setBorderColor(Color::getColorFrom24BitRGB(0,0,0));
	bxBackground.invalidate();
}

void Screen3View::setupScreen()
{
    Screen3ViewBase::setupScreen();
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}

void Screen3View::updateDisplay(){

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
			//bxToil.setColor(Color::getColorFrom24BitRGB(255,0,0));			//Color Red

			// Set Fade Toil
			// Range between 127-255
			uint16_t fadeValue = 255;
			if(tOil >= HIGH_TOIL_WARNING_START && tOil <= HIGH_TOIL_WARNING_END)
				fadeValue = (((FADE_MIN+1) / (HIGH_TOIL_WARNING_END - HIGH_TOIL_WARNING_START)) * (tOil * HIGH_TOIL_WARNING_START) + (FADE_MIN));
			bxToil.setAlpha(fadeValue);

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
		} else if(pOil >= HIGH_POIL_MIN && pOil <= HIGH_POIL_MAX) {
			bxPoil.setColor(Color::getColorFrom24BitRGB(255,0,0));				//Color Red
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

// Map
	float map = getValueData(&(ds.powerUnit.map));
	if(map != EMPTY_VALUE) {

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

//TPS
	float tps1 = getValueData(&(ds.lvElectronics.tps1));
	if(tps1 != EMPTY_VALUE) {

		if(isDataUpdated(&(ds.lvElectronics.tps1)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtTpsBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			Unicode::snprintfFloat(txtTpsBuffer, TXTTPS_SIZE-1, "%.1f", tps1);
		}

		txtTps.invalidate();
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

// Tbat
	float tBatHV = getValueData(&(ds.hvElectronicsBMS.batteryTMH));
	if(tBatHV != EMPTY_VALUE) {
		if(!bxTbat.isVisible())
			bxTbat.setVisible(true);

		// Set Color
		if(tBatHV >= LOW_TBATHV_MIN && tBatHV <= LOW_TBATHV_MAX) {
			bxTbat.setColor(Color::getColorFrom24BitRGB(0,0,255));				//Color Blue

			//lblTbat.setColor(Color::getColorFrom24BitRGB(0,0,0));
		} else if(tBatHV >= MEDIUM_TBATHV_MIN && tBatHV <= MEDIUM_TBATHV_MAX) {
			bxTbat.setColor(Color::getColorFrom24BitRGB(0,0,0));		 		//Color Black
			//lblTbat.setColor(Color::getColorFrom24BitRGB(255,255,255));
		} else if(tBatHV >= HIGH_TBATHV_MIN && tBatHV <= HIGH_TBATHV_MAX) {
			bxTbat.setColor(Color::getColorFrom24BitRGB(255,0,0));				//Color Red

			uint8_t fadeValue = 255;
			if(tBatHV >= HIGH_TBATHV_WARNING_START && tBatHV <= HIGH_TBATHV_WARNING_END)
				fadeValue = FADE_MAX - ((FADE_MIN+1) / (HIGH_TBATHV_WARNING_END - HIGH_TBATHV_WARNING_START) * (tBatHV - HIGH_TBATHV_WARNING_START));
			bxTbat.setAlpha(fadeValue);

			//lblTbat.setColor(Color::getColorFrom24BitRGB(0,0,0));
		}

		if(isDataUpdated(&(ds.hvElectronicsBMS.batteryTMH)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtTbatBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);

			bxTbat.setColor(Color::getColorFrom24BitRGB(0,0,0));				//Color Black
		} else {
			// Set Text
			Unicode::snprintfFloat(txtTbatBuffer, TXTTBAT_SIZE-1, "%.1f", tBatHV);
		}

		bxTbat.invalidate();
		txtTbat.invalidate();
	}

// SOC
	int soc = getValueData(&(ds.hvElectronicsBMS.soc));
	if(soc != EMPTY_VALUE) {
		if(!bxSoc.isVisible())
			bxSoc.setVisible(true);

		// Set Color SOC Box
		if(soc >= LOW_SOC_MIN && soc <= LOW_SOC_MAX) {
			bxSoc.setColor(Color::getColorFrom24BitRGB(255,0,0));		//Color Red
			lblSoc.setColor(Color::getColorFrom24BitRGB(255,255,255));
			txtSoc.setColor(Color::getColorFrom24BitRGB(255,255,255));
		} else if(soc >= MEDIUM_SOC_MIN && soc <= MEDIUM_SOC_MAX) {
			bxSoc.setColor(Color::getColorFrom24BitRGB(0,0,0));			//Color Black
			lblSoc.setColor(Color::getColorFrom24BitRGB(255,255,255));
			txtSoc.setColor(Color::getColorFrom24BitRGB(255,255,255));
		} else if(soc >= HIGH_SOC_MIN && soc <= HIGH_SOC_MAX) {
			bxSoc.setColor(Color::getColorFrom24BitRGB(0,255,0));		//Color Green
			lblSoc.setColor(Color::getColorFrom24BitRGB(0,0,0));
			txtSoc.setColor(Color::getColorFrom24BitRGB(0, 0, 0));
		}

		if(isDataUpdated(&(ds.hvElectronicsBMS.soc)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtSocBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);

			txtSoc.setColor(Color::getColorFrom24BitRGB(255, 255, 255));
			lblSoc.setColor(Color::getColorFrom24BitRGB(255,255,255));
			bxSoc.setColor(Color::getColorFrom24BitRGB(0,0,0));				//Color Black
		} else {
			// Set Text
			Unicode::snprintf(txtSocBuffer, TXTSOC_SIZE-1, "%d", soc);
		}

		txtSoc.invalidate();
		bxSoc.invalidate();
	}

// EmTemp
	float emTemp = getValueData(&(ds.hvElectronicsInverter.electricMotorTemperature));
	if(emTemp != EMPTY_VALUE) {

		//TODO Controlli sulle temperature EM

		if(isDataUpdated(&(ds.hvElectronicsInverter.electricMotorTemperature)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtEmTempBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintfFloat(txtEmTempBuffer, TXTEMTEMP_SIZE-1, "%.1f", emTemp);
		}

		txtEmTemp.invalidate();
	}

// VbatHV
	float vBatHV = getValueData(&(ds.hvElectronicsBMS.voltageBatteryHV));
	if(vBatHV != EMPTY_VALUE) {
		if(!bxVbatHV.isVisible())
			bxVbatHV.setVisible(true);

		// Set Color vBatHV Box
		if(vBatHV >= LOW_VBATHV_MIN && vBatHV <= LOW_VBATHV_MAX) {
			bxVbatHV.setColor(Color::getColorFrom24BitRGB(255,0,0));		//Color Red
			lblVbatHV.setColor(Color::getColorFrom24BitRGB(255,255,255));
			txtVbatHV.setColor(Color::getColorFrom24BitRGB(255,255,255));
		} else if(vBatHV >= MEDIUM_VBATHV_MIN && vBatHV <= MEDIUM_VBATHV_MAX) {
			bxVbatHV.setColor(Color::getColorFrom24BitRGB(0,0,0));			//Color Black
			lblVbatHV.setColor(Color::getColorFrom24BitRGB(255,255,255));
			txtVbatHV.setColor(Color::getColorFrom24BitRGB(255,255,255));
		} else if(vBatHV >= HIGH_VBATHV_MIN && vBatHV <= HIGH_VBATHV_MAX) {
			bxVbatHV.setColor(Color::getColorFrom24BitRGB(0,255,0));		//Color Green
			lblVbatHV.setColor(Color::getColorFrom24BitRGB(0,0,0));
			txtVbatHV.setColor(Color::getColorFrom24BitRGB(0,0,0));
		}

		if(isDataUpdated(&(ds.hvElectronicsBMS.voltageBatteryHV)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtVbatHVBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);

			bxVbatHV.setColor(Color::getColorFrom24BitRGB(0,0,0));			//Color Black
			lblVbatHV.setColor(Color::getColorFrom24BitRGB(255,255,255));
			txtVbatHV.setColor(Color::getColorFrom24BitRGB(255,255,255));
		} else {
			// Set Text
			Unicode::snprintfFloat(txtVbatHVBuffer, TXTVBATHV_SIZE-1, "%.1f", vBatHV);
		}

		txtVbatHV.invalidate();
		bxVbatHV.invalidate();
	}

// VbatLV
	float vBatLV = getValueData(&(ds.lvElectronics.voltageBatteryLV));
	if(vBatLV != EMPTY_VALUE) {
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
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtVbatLVBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);

			bxVbatLV.setColor(Color::getColorFrom24BitRGB(0,0,0));			//Color Black
		} else {
			// Set Text
			Unicode::snprintfFloat(txtVbatLVBuffer, TXTVBATLV_SIZE-1, "%.1f", vBatLV);
		}

		txtVbatLV.invalidate();
		bxVbatLV.invalidate();
	}

// invTemperature
	float invTemperature = getValueData(&(ds.hvElectronicsInverter.inverterTemperature));
	if(invTemperature != EMPTY_VALUE) {

		//TODO Controllo sul valore per colore box

		if(isDataUpdated(&(ds.hvElectronicsInverter.inverterTemperature)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtInvTempBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintfFloat(txtInvTempBuffer, TXTINVTEMP_SIZE-1, "%.1f", invTemperature);
		}

		txtInvTemp.invalidate();
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
			Unicode::snprintf(txtTwaterCBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);

			bxTwaterE.setColor(Color::getColorFrom24BitRGB(0,0,0));		 					//Color Black
		} else {
			// Set Text
			Unicode::snprintfFloat(txtTwaterEBuffer, TXTTWATERE_SIZE-1, "%.1f", tWaterE);
		}

		bxTwaterE.invalidate();
		txtTwaterE.invalidate();
	}

// Tair
	float tAir = getValueData(&(ds.powerUnit.airTemperature));
	if(tAir != EMPTY_VALUE) {

		Unicode::snprintfFloat(txtTairBuffer, TXTTAIR_SIZE-1, "%.1f", tAir);

		txtTair.invalidate();
		bxTair.invalidate();
	}

// BPPS
	float bppsFront = getValueData(&(ds.dynamics.brakePressureFront));
	if(bppsFront != EMPTY_VALUE) {

		if(isDataUpdated(&(ds.dynamics.brakePressureFront)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtBppsBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			Unicode::snprintfFloat(txtBppsBuffer, TXTBPPS_SIZE-1, "%.1f", bppsFront);
		}
		txtBpps.invalidate();
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

// DISPLAY

	bxBackground.invalidate();
}
