#include <gui/screen5_screen/Screen5View.hpp>

#include <touchgfx/Color.hpp>

#include "Data/Dataset.h"
#include "Data/DataStatus.h"
#include "Data/DataConstantNotification.h"
#include "DisplayConstant.h"
#include "TimerHandler.h"

extern Dataset ds;

Screen5View::Screen5View()
{
	ctAlarm.setVisible(false);

	ctMessage.setVisible(false);

	ctScreenName.setVisible(true);

	bxDelta.setVisible(false);
	bxAbatMax.setVisible(false);
	bxInvTemp.setVisible(false);
	bxPowerProvidedElectric.setVisible(false);
	bxDeltaMax.setVisible(false);
	bxAbat.setVisible(false);
	bxTbat.setVisible(false);
	bxVbatHV.setVisible(false);

	Chart1.setGraphRangeYAuto(0, 0);
	Chart2.setGraphRangeY(0, 2000);

	bxBackground.setBorderColor(Color::getColorFrom24BitRGB(0,0,0));
	bxBackground.invalidate();
}

void Screen5View::setupScreen()
{
    Screen5ViewBase::setupScreen();
}

void Screen5View::tearDownScreen()
{
    Screen5ViewBase::tearDownScreen();
}

void Screen5View::updateDisplay() {

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

// VbatHV
	float vBatHV = getValueData(&(ds.hvElectronicsBMS.voltageBatteryHV));
	if(vBatHV != EMPTY_VALUE) {
		if(!bxVbatHV.isVisible())
			bxVbatHV.setVisible(true);

		// Set Color vBatHV Box
		if(vBatHV >= LOW_VBATHV_MIN && vBatHV <= LOW_VBATHV_MAX) {
			bxVbatHV.setColor(Color::getColorFrom24BitRGB(255,0,0));		//Color Red
			lblVbatHV.setColor(Color::getColorFrom24BitRGB(255,255,255));
			txtVbatHV.setColor(Color::getColorFrom24BitRGB(255, 255, 255));
		} else if(vBatHV >= MEDIUM_VBATHV_MIN && vBatHV <= MEDIUM_VBATHV_MAX) {
			bxVbatHV.setColor(Color::getColorFrom24BitRGB(0,0,0));			//Color Black -> Color Orange (255, 69, 0)
			lblVbatHV.setColor(Color::getColorFrom24BitRGB(255,255,255));
			txtVbatHV.setColor(Color::getColorFrom24BitRGB(255, 255, 255));
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
			bxTbat.setColor(Color::getColorFrom24BitRGB(0,0,0));	 					//Color Black
			//lblTbat.setColor(Color::getColorFrom24BitRGB(255,255,255));
		} else if(tBatHV >= HIGH_TBATHV_MIN && tBatHV <= HIGH_TBATHV_MAX) {
			bxTbat.setColor(Color::getColorFrom24BitRGB(255,0,0));						//Color Red

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

// PowerProvidedElectric
	int powerProvidedElectric = getValueData(&(ds.hvElectronicsInverter.actualPowerProvidedElectric));
	if(powerProvidedElectric != EMPTY_VALUE) {

		// TODO Set Box color

		if(isDataUpdated(&(ds.hvElectronicsInverter.actualPowerProvidedElectric)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtPowerProvidedElectricBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintf(txtPowerProvidedElectricBuffer, TXTPOWERPROVIDEDELECTRIC_SIZE-1, "%d", powerProvidedElectric);
		}

		txtPowerProvidedElectric.invalidate();
	}

// AbatHV
	float aBatHV = getValueData(&(ds.hvElectronicsBMS.ampereBatteryHV));
	if(aBatHV != EMPTY_VALUE) {
		if(!bxAbat.isVisible())
			bxAbat.setVisible(false);

		if(isDataUpdated(&(ds.hvElectronicsBMS.ampereBatteryHV)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtAbatBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintfFloat(txtAbatBuffer, TXTABAT_SIZE-1, "%.1f", aBatHV);
		}

		txtAbat.invalidate();
	}

// AbatMax
	float aBatHVmax = getValueData(&(ds.hvElectronicsBMS.ampereBatteryHVmax));
	if(aBatHVmax != EMPTY_VALUE) {

		// TODO set Box Color

		if(isDataUpdated(&(ds.hvElectronicsBMS.ampereBatteryHVmax)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtAbatMaxBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintfFloat(txtAbatMaxBuffer, TXTABATMAX_SIZE-1, "%.1f", aBatHVmax);
		}

		txtAbatMax.invalidate();
	}

//FPS
	int fps = getFpsScreen(&(ds.screen));
	if(fps != EMPTY_VALUE) {

		// Set Text
		Unicode::snprintf(txtFpsBuffer, TXTFPS_SIZE-1, "%d", fps);
		txtFps.invalidate();
	}

// DeltaMax
	int deltaMax = getValueData(&(ds.hvElectronicsBMS.deltaMax));
	if(deltaMax != EMPTY_VALUE) {

		// TODO Inserire Box Color

		if(isDataUpdated(&(ds.hvElectronicsBMS.deltaMax)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtDeltaMaxBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintf(txtDeltaMaxBuffer, TXTDELTAMAX_SIZE-1, "%d", deltaMax);
		}

		txtDeltaMax.invalidate();
	}

// Delta
	int delta = getValueData(&(ds.hvElectronicsBMS.delta));
	if(delta != EMPTY_VALUE) {

		if(isDataUpdated(&(ds.hvElectronicsBMS.delta)) == 0 && ds.screen.blinkFlag == 1) {
			Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
			Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
			Unicode::snprintf(txtDeltaBuffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
		} else {
			// Set Text
			Unicode::snprintf(txtDeltaBuffer, TXTDELTA_SIZE-1, "%d", delta);
		}

		txtDelta.invalidate();
	}

// Chart1 -> SOC
	float soc = getValueData(&(ds.hvElectronicsBMS.soc));
	if(soc != EMPTY_VALUE) {
		if(isDataUpdated(&(ds.hvElectronicsBMS.soc)) == 0) {
			if(ds.screen.blinkFlag) {
				Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
				Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
				Unicode::snprintf(txtChart1Buffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
			} else {
				Unicode::snprintfFloat(txtChart1Buffer, TXTCHART1_SIZE-1, "%.2f", soc);
			}
			txtChart1.invalidate();
		} else {
			Chart1.addDataPoint(soc);
			Unicode::snprintfFloat(txtChart1Buffer, TXTCHART1_SIZE-1, "%.2f", soc);

			txtChart1.invalidate();
			Chart1.invalidate();
		}
	}

// Chart2 -> Delta
	if(delta != EMPTY_VALUE) {
		if(isDataUpdated(&(ds.hvElectronicsBMS.delta)) == 0) {
			if(ds.screen.blinkFlag) {
				Unicode::UnicodeChar buffer[NO_DATA_RECEIVED_WARNING_LENGTH+1] = {0};
				Unicode::strncpy(buffer, NO_DATA_RECEIVED_WARNING, NO_DATA_RECEIVED_WARNING_LENGTH);
				Unicode::snprintf(txtChart2Buffer, NO_DATA_RECEIVED_WARNING_LENGTH+1, "%s", buffer);
			} else {
				Unicode::snprintfFloat(txtChart2Buffer, TXTCHART2_SIZE-1, "%.2f", delta);
			}
			txtChart2.invalidate();
		} else {
			Chart2.addDataPoint(delta);
			Unicode::snprintfFloat(txtChart2Buffer, TXTCHART2_SIZE-1, "%.2f", delta);

			txtChart2.invalidate();
			Chart2.invalidate();
		}
	}

// DISPLAY

	bxBackground.invalidate();
}
