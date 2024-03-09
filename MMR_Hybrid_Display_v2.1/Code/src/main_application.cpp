#include "../include/main_application.hpp"
#include "../include/data_constants.hpp"
#include "../include/dash_utils.hpp"

/* pilot's inputs listeners section */

AckBtnLisener::AckBtnLisener() {}

void AckBtnLisener::onChange(float oldValue, float newValue) {
	if (newValue == 1) {
		mainApp.popUpHandler.deactivateCurrentPopUp();
	}
}

IncrementBtnListener::IncrementBtnListener() {}

void IncrementBtnListener::onChange(float oldValue, float newValue) {
}

DecrementBtnListener::DecrementBtnListener() {}

void DecrementBtnListener::onChange(float oldValue, float newValue) {
}

RadioBtnListener::RadioBtnListener() {}

void RadioBtnListener::onChange(float oldValue, float newValue) {
}

MarkBtnListener::MarkBtnListener() {}

void MarkBtnListener::onChange(float oldValue, float newValue) {
}

Special1BtnListener::Special1BtnListener() {}

void Special1BtnListener::onChange(float oldValue, float newValue) {
}

Special2BtnListener::Special2BtnListener() {}

void Special2BtnListener::onChange(float oldValue, float newValue) {
}

MapListener::MapListener() {}

void MapListener::onChange(float oldValue, float newValue) {
	mainApp.setPage((uint8_t)newValue);
}

/* DataControls section */

DataControls::DataControls(DataAlarmHandler* alarmHandler, PopUpHandler* popUpHandler)
	:batteryVoltage(BATTERY_VOLTAGE_CONVERSION_FACTOR, 0, BATTERY_VOLTAGE_MAX_VALUE, BATTERY_VOLTAGE_MIN_VALUE),
	batteryVoltageAlarm(&batteryVoltage, BATTERY_VOLTAGE_ALARM_PRIORITY, alarmHandler, "VOLT_BATT"),
	battVoltPopUp(&batteryVoltageAlarm),
	launchControlStatus(LAUNCH_CONTROL_STATUS_CONVERSION_FACTOR, 0),
	pedal(PEDAL_CONVERSION_FACTOR, 0),
	brake(BRAKE_CONVERSION_FACTOR, 0),
	brakeRear(BRAKE_CONVERSION_FACTOR, 0),
	ackBtn(1, 0, 0),
	incrementBtn(1, 0, 0),
	decrementBtn(1, 0, 0),
	radioBtn(1, 0, 0),
	markBtn(1, 0, 0),
	special1Btn(1, 0, 0),
	special2Btn(1, 0, 0),
	tractionControl(TRACTION_CONTROL_CONVERSION_FACTOR, 0),
	torqueVectoring(1, 0),
	map(1, 0, 0),
	steer(STEER_CONVERSION_FACTOR, 0),
	gpsLatitude(LATITUDE_CONVERSION_FACTOR, 0),
	gpsLongitude(LONGITUDE_CONVERSION_FACTOR, 0),
	gpsAltitude(LONGITUDE_CONVERSION_FACTOR, 0),
	m_lastUpdateTime(0)
{
	batteryVoltage.bindAlarm(&batteryVoltageAlarm);
	alarmHandler->pushAlarm(&batteryVoltageAlarm);
	popUpHandler->registerPopUp(&battVoltPopUp);

	ackBtn.setListener(&ackListener);
	incrementBtn.setListener(&incListener);
	decrementBtn.setListener(&decListener);
	radioBtn.setListener(&radioListener);
	markBtn.setListener(&markListener);
	special1Btn.setListener(&sp1Listener);
	special2Btn.setListener(&sp2Listener);
	map.setListener(&mapListener);
}

void DataControls::updateSteeringWheelControlsTime() {
	m_lastUpdateTime = millis();
}

bool DataControls::isSteeringWheelOK() {
	return !(millis() - m_lastUpdateTime > STEERING_WHEEL_TIMEOUT);
}

/* DataMechanics section */

DataMechanics::DataMechanics() 
	:rpm(RPM_CONVERSION_FACTOR, 0),
	gear(GEAR_CONVERSION_FACTOR, 0),
	slip(SLIP_CONVERSION_FACTOR, 0),
	speed(SPEED_CONVERSION_FACTOR, 0),
	tps(TPS_CONVERSION_FACTOR, 0),
	carHeightFR(CAR_HEIGHT_CONVERSION_FACTOR, 0),
	carHeightFL(CAR_HEIGHT_CONVERSION_FACTOR, 0),
	carHeightRR(CAR_HEIGHT_CONVERSION_FACTOR, 0),
	carHeightRL(CAR_HEIGHT_CONVERSION_FACTOR, 0)
{}

/* DataThermalPressure section */

DataThermalPressure::DataThermalPressure(DataAlarmHandler* alarmHandler, PopUpHandler* popUpHandler) 
	:oilPressure(OIL_PRESSURE_CONVERSION_FACTOR, 0, OIL_PRESSURE_MAX_VALUE, OIL_PRESSURE_MIN_VALUE),
	oilPAlarm(&oilPressure, OIL_PRESSURE_ALARM_PRIORITY, alarmHandler, "OIL_PRESS"),
	oilPAlarmPopUp(&oilPAlarm),
	oilTemperature(OIL_TEMPERATURE_CONVERSION_FACTOR, 0, OIL_TEMPERATURE_MAX_VALUE, OIL_TEMPERATURE_MIN_VALUE),
	oilTAlarm(&oilTemperature, OIL_TEMPERATURE_ALARM_PRIORITY, alarmHandler, "OIL_TEMP"),
	oilTAlarmPopUp(&oilTAlarm),
	fuelPressure(FUEL_PRESSURE_CONVERSION_FACTOR, 0, FUEL_PRESSURE_MAX_VALUE, FUEL_PRESSURE_MIN_VALUE),
	fuelPAlarm(&fuelPressure, FUEL_PRESSURE_ALARM_PRIORITY, alarmHandler, "FUEL_PRESS"),
	fuelPAlarmPopUp(&fuelPAlarm),
	fuelTemperature(FUEL_TEMPERATURE_CONVERSION_FACTOR, 0, FUEL_TEMPERATURE_MAX_VALUE, FUEL_TEMPERATURE_MIN_VALUE),
	fuelTAlarm(&fuelTemperature, FUEL_TEMPERATURE_ALARM_PRIORITY, alarmHandler, "FUEL_TEMP"),
	fuelTAlarmPopUp(&fuelTAlarm),
	airTemperature(AIR_TEMPERATURE_CONVERSION_FACTOR, 0, AIR_TEMPERATURE_MAX_VALUE, AIR_TEMPERATURE_MIN_VALUE),
	airTAlarm(&airTemperature, AIR_TEMPERATURE_ALARM_PRIORITY, alarmHandler, "AIR_TEMP"),
	airTAlarmPopUp(&airTAlarm),
	waterTemperature(WATER_TEMPERATURE_CONVERSION_FACTOR, 0, WATER_TEMPERATURE_MAX_VALUE, WATER_TEMPERATURE_MIN_VALUE),
	waterTAlarm(&waterTemperature, WATER_TEMPERATURE_ALARM_PRIORITY, alarmHandler, "WATER_TEMP"),
	waterTAlarmPopUp(&waterTAlarm)
{
	oilPressure.bindAlarm(&oilPAlarm);
	oilTemperature.bindAlarm(&oilTAlarm);
	fuelPressure.bindAlarm(&fuelPAlarm);
	fuelTemperature.bindAlarm(&fuelTAlarm);
	airTemperature.bindAlarm(&airTAlarm);
	waterTemperature.bindAlarm(&waterTAlarm);

	alarmHandler->pushAlarm(&oilPAlarm);
	alarmHandler->pushAlarm(&oilTAlarm);
	alarmHandler->pushAlarm(&fuelPAlarm);
	alarmHandler->pushAlarm(&fuelTAlarm);
	alarmHandler->pushAlarm(&airTAlarm);
	alarmHandler->pushAlarm(&waterTAlarm);

	popUpHandler->registerPopUp(&oilPAlarmPopUp);
	popUpHandler->registerPopUp(&oilTAlarmPopUp);
	popUpHandler->registerPopUp(&fuelPAlarmPopUp);
	popUpHandler->registerPopUp(&fuelPAlarmPopUp);
	popUpHandler->registerPopUp(&airTAlarmPopUp);
	popUpHandler->registerPopUp(&waterTAlarmPopUp);
}

/* Tyres section */

Tyres::Tyres() {}

/* SteeringWheelBrokenPopUp section */

SteerinWheelBrokenPopUp::SteerinWheelBrokenPopUp() :m_on(false), m_deactivated(false) {}

void SteerinWheelBrokenPopUp::fillTitle(char* titleBuffer, size_t titleSize) {
	safeStringCopy(m_name, titleBuffer, titleSize);
}

void SteerinWheelBrokenPopUp::fillContent(char* contentBuffer, size_t contentSize) {
	safeStringCopy(m_content, contentBuffer, contentSize);
}

void SteerinWheelBrokenPopUp::setColor(uint8_t r, uint8_t g, uint8_t b) {
	//not used
}

void SteerinWheelBrokenPopUp::getBgColor(uint8_t* r, uint8_t* g, uint8_t* b) {
	*r = 255;
	*g = 0;
	*b = 0;
}

uint8_t SteerinWheelBrokenPopUp::getPriority() {
	return 0;
}

const char* SteerinWheelBrokenPopUp::getName() {
	return m_name;
}

void SteerinWheelBrokenPopUp::turnOn() {
	m_on = true;
}

void SteerinWheelBrokenPopUp::turnOff() {
	m_on = false;
}

bool SteerinWheelBrokenPopUp::isOn() {
	return m_on;
}

void SteerinWheelBrokenPopUp::deactivate() {
	m_deactivated = true;
}

bool SteerinWheelBrokenPopUp::isDeactivated() {
	return m_deactivated;
}

bool SteerinWheelBrokenPopUp::isRetained() {
	return false;
}

/* MainApplication section */

MainApplication MainApplication::instance;

MainApplication::MainApplication()
	:dataControls(&alarmHandler, &popUpHandler),
	dataThermalPressure(&alarmHandler, &popUpHandler),
	dAlDec(&popUpHandler),
	m_currentPage(0),
	m_pageChanged(false)
{
	alarmHandler.pushListener(&dAlDec);
	popUpHandler.registerPopUp(&m_steerWheelBrokenPopUp);
}

void MainApplication::decodeCAN1Msg(uint16_t id, uint8_t dlc, uint8_t* payload) {
}

void MainApplication::decodeCAN2Msg(uint16_t id, uint8_t dlc, uint8_t* payload) {
}

void MainApplication::decodeCAN3Msg(uint16_t id, uint8_t dlc, uint8_t* payload) {
}

uint8_t MainApplication::getCurrentPage() {
	m_pageChanged = false;
	return m_currentPage;
}

void MainApplication::setPage(uint8_t pageIdx) {
	if (pageIdx < NUMBER_OF_PAGES && pageIdx != m_currentPage) {
		m_currentPage = pageIdx;
		m_pageChanged = true;
	}
}

bool MainApplication::currentPageChanged() {
	return m_pageChanged;
}

void MainApplication::controlsHandler() {
	bool steeringWheelWorking = true;
	while (1) {
		if (steeringWheelWorking && !dataControls.isSteeringWheelOK()) {
			steeringWheelWorking = false;
			popUpHandler.pushPopUp(&m_steerWheelBrokenPopUp);
		}
	}
}