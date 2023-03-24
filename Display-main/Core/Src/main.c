/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "can.h"
#include "crc.h"
#include "dac.h"
#include "dma2d.h"
#include "iwdg.h"
#include "ltdc.h"
#include "quadspi.h"
#include "sdmmc.h"
#include "usart.h"
#include "gpio.h"
#include "fmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "DISPLAY_GUI.h"

#include "MDM_Functions.h"

#ifndef __CAR_DATA_H
#include "CAR_DATA.h"
#endif


#include "string.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

uint8_t Error_Handler_Code = 0;

uint8_t startingProcedureFlag = 0;


uint32_t loopTime = 0;

uint32_t loopTimeMax = 0;
uint32_t loopTimeMaxResetMillis = 0;
#define loopTimeMaxResetDelay		1000

float loopTimeAvg = 0;

#if HQ_AVG_LOOP_TIME_ENABLE == 0
#define avgLoopNumber				100		//100
#else
#define avgLoopNumber				1000		//1000
#endif

uint32_t loopTimeAvgMem[avgLoopNumber];


uint8_t LCD_LAYER0_BUFFER[LCD_FULLSCREEN_ARGB_BUFFER_SIZE] __attribute__((section(".SDRAM")));
uint8_t LCD_LAYER1_BUFFER[LCD_FULLSCREEN_ARGB_BUFFER_SIZE] __attribute__((section(".SDRAM")));

extern GUI_CONST_STORAGE GUI_BITMAP bmScuderia_Ferrari_F1_2018;

//uint8_t memTest1 __attribute__((section(".SDRAM")));


extern uint8_t TxData_CAN1[8];
extern uint8_t dataRX_SAVED[8];



//old car data (keep for old code)
float 		vBat 					= 99;
int32_t 	gear 					= 0;
float 		tOil 					= 99;
float 		tWater 					= 99;
float 		tAir 					= 3;
int32_t 	drsStatus 				= 0;
int32_t 	map 					= 0;
int32_t 	map_pp					= 1; //used to have map + 1
int32_t 	tractionControl 		= 0;
float 		pOil 					= 99;
int32_t 	rpm 					= 99;
int32_t 	tps 					= 99;
int32_t 	launchControlStatus 	= 0;
int32_t 	gs 						= 0;
int32_t 	pedal 					= 99;
float 		speed 					= 99;
int32_t 	steer 					= 0;
int32_t		slip 					= 0;
int32_t	 	brake 					= 0;
float		pFuel 					= 99;



int32_t defaultDataPointed = 13;


//antideb
uint8_t buttonStateMAP = 0;            // the current reading from the input pin
uint8_t lastButtonStateMAP = 0;  	// the previous reading from the input pin
uint8_t MAPbtn = 0;

uint32_t lastDebounceTimeMAP = 0;  	// the last time the output pin was toggled

uint8_t buttonStateDISP = 0;           // the current reading from the input pin
uint8_t lastButtonStateDISP = 0;  	// the previous reading from the input pin
uint8_t DISPbtn = 0;

uint32_t lastDebounceTimeDISP = 0;  // the last time the output pin was toggled

uint32_t debounceDelay = 100; 		// the debounce time; increase if the output flickers //it was 250 @ 30/11/21

GPIO_EdgeTypeDef displayButton = { 0 };
#define displayButtonDelay				100

uint8_t markState = 0;
uint32_t markMillis = 0;
#define markSendDelay					100

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

void dashboardLedControl(void);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

uint8_t dataWrite[100] = "test qspi data write";
uint8_t dataRead[100];

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* Enable I-Cache---------------------------------------------------------*/
  SCB_EnableICache();

  /* Enable D-Cache---------------------------------------------------------*/
  SCB_EnableDCache();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

	if (0)
	{
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_CAN1_Init();
  MX_CAN2_Init();
  MX_CAN3_Init();
  MX_DAC_Init();
  MX_FMC_Init();
  MX_LTDC_Init();
  MX_QUADSPI_Init();
  MX_SDMMC1_SD_Init();
  MX_USART1_UART_Init();
  MX_DMA2D_Init();
  MX_CRC_Init();
  MX_IWDG_Init();
  MX_ADC2_Init();
  MX_ADC3_Init();
  /* USER CODE BEGIN 2 */
	}

	MX_GPIO_Init();
	DisplayOFF();
	MX_ADC1_Init();
	//MX_ADC2_Init();
	MX_ADC3_Init();
	MX_CAN1_Init();
	MX_CAN2_Init();
	//MX_CAN3_Init();
	//MX_DAC_Init();
	//MX_SDMMC1_SD_Init();
	//MX_USART1_UART_Init();
	MX_DMA2D_Init();
	MX_CRC_Init();
	MX_FMC_Init();
	MX_LTDC_Init();
	MDM_LCD_SetLayerVisible(0, DISABLE);
	DisplayOFF();
	//MX_QUADSPI_Init();


	// QSPI meme test BEGIN
//
//	if(CSP_QUADSPI_Init() != HAL_OK)
//	{
//		Error_Handler();
//	}
//
//	if(CSP_QSPI_Erase_Chip() != HAL_OK)
//	{
//		Error_Handler();
//	}
//
//
//
//
//	if(CSP_QSPI_Write(dataWrite, 0x00, 9) != HAL_OK)
//	{
//		Error_Handler();
//	}
//
//	if(CSP_QSPI_Read(dataRead, 0x00, 100) != HAL_OK)
//	{
//		Error_Handler();
//	}
//
//
//	if(dataWrite[0] == dataRead[0])
//	{
//		DisplayOFF();
//		HAL_Delay(500);
//		DisplayON();
//		HAL_Delay(500);
//		DisplayOFF();
//		HAL_Delay(500);
//		DisplayON();
//	}
//
//



	// QSPI meme test END


	HAL_GPIO_WritePin(_5V_OUT1_GPIO_Port, _5V_OUT1_Pin, 1);

	CAR_CAN_Init();

	CAR_DATA_Init();

	MX_IWDG_Init();



	displayButton.GPIOx = Disp_BTN_F_GPIO_Port;
	displayButton.GPIO_Pin = Disp_BTN_F_Pin;
	displayButton.delay = displayButtonDelay;

	DisplayGui_Init();

	HAL_ADC_Start(&hadc3);

	__HAL_IWDG_RELOAD_COUNTER(&hiwdg);
	HAL_Delay(150);							//needed to eliminate white flash of the display at the startup (needed at least 150 ms)
	__HAL_IWDG_RELOAD_COUNTER(&hiwdg);

	DisplayON();

	HAL_GPIO_WritePin(_5V_OUT1_GPIO_Port, _5V_OUT1_Pin, 0);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1) {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

		// loop time calculation BEGIN

		static uint32_t loopTimeBegin = 0;
		static uint16_t loopTimeAvgPointer = 0;
		//uint32_t loopTimeAvgTemp = 0;

		static uint32_t loopTimeAvgTemp = 0;


		loopTime = millis - loopTimeBegin;
		loopTimeBegin = millis;


		loopTimeAvgTemp = loopTimeAvgTemp - loopTimeAvgMem[loopTimeAvgPointer];
		loopTimeAvgMem[loopTimeAvgPointer] = loopTime;
		loopTimeAvgTemp = loopTimeAvgTemp + loopTime;

		loopTimeAvgPointer++;

		if(loopTimeAvgPointer >= avgLoopNumber)
			loopTimeAvgPointer = 0;

		loopTimeAvg = (float)loopTimeAvgTemp / avgLoopNumber;


		if(millis >= loopTimeMaxResetMillis + loopTimeMaxResetDelay)
		{
			loopTimeMax = 0;
			loopTimeMaxResetMillis = millis;
		}

		loopTimeMax = max(loopTimeMax, loopTime);

		// loop time calculation END


		readMcuTemperature();


		CAR_DATA_Read();
		CAR_DATA_Calculations();

		if(DEBUG_MODE == 0)
		{
			tractionAcquisition();
		}


		// Mark button BEGIN

		if (millis >= markMillis + markSendDelay)
		{

			markState = HAL_GPIO_ReadPin(DIG1_F_GPIO_Port, DIG1_F_Pin);

			TxData_CAN1[0] = markState; //MARK TO ECU
			TxData_CAN1[1] = MCU_temperature; //SEND MCU TEMP FOR DEBUGGING
			TxData_CAN1[2] = dataRX_SAVED[0]; //STEER DATA FROM CAN2 TO CAN1 FOR DRS
			TxData_CAN1[3] = dataRX_SAVED[1]; //AS ABOVE
			//ADD Y ACCEL FROM CAN2 TO CAN1 FOR DRS
			TxData_CAN1[4]=dataRX_SAVED[2];
			TxData_CAN1[5]=dataRX_SAVED[3];

			if(DEBUG_MODE == 0)
			{
				CAR_Data.steer.intData = TxData_CAN1[2]<<8|TxData_CAN1[3];

				CAR_Data.steer.floatData = CAR_Data.steer.intData;
				CAR_Data.steer.oldTimeData = CAR_Data.steer.lastTimeData;
				CAR_Data.steer.lastTimeData = millis;

				steer = CAR_Data.steer.intData;
			}

			HAL_CAN_AddTxMessage(&hcan1, &pHeader_CAN1, TxData_CAN1, &TxMailbox_CAN1);		//WARNING: disable only for DEBUG

			markMillis = millis;
		}

		// Mark button END



		// Display debounce section BEGIN

		uint8_t readingDISP = HAL_GPIO_ReadPin(Disp_BTN_F_GPIO_Port, Disp_BTN_F_Pin);

		// check to see if you just pressed the button
		// (i.e. the input went from LOW to HIGH), and you've waited long enough
		// since the last press to ignore any noise:

		// If the switch changed, due to noise or pressing:
		if (readingDISP != lastButtonStateDISP) {
			// reset the debouncing timer
			lastDebounceTimeDISP = millis;
		}

		if ((millis - lastDebounceTimeDISP) > debounceDelay) {
			// whatever the reading is at, it's been there for longer than the debounce
			// delay, so take it as the actual current state:

			// if the button state has changed:
			if (readingDISP != buttonStateDISP) {
				buttonStateDISP = readingDISP;

				// only toggle the LED if the new button state is HIGH
				if (buttonStateDISP == 1) {
					//HAL_GPIO_TogglePin(MAP_OUT_GPIO_Port, MAP_OUT_Pin);
					//MAPbtn = !MAPbtn;
					DISPbtn = !DISPbtn;
				}
			}
		}


		//if(GPIO_AdvancedRead(&displayButton) == GPIO_FALL)
		//DISPbtn = !DISPbtn;

		lastButtonStateDISP = readingDISP;

		// Display debounce section END


		//Display page selection BEGIN
		static uint8_t flagIncrementoPagina = 0;
		static uint8_t flagDecrementoPagina = 0;
		static uint8_t paginaAttivata = 1;




		if(MAP_CHANGE_ENABLE == DISABLE)
		{
			if (DISPbtn == 1 && flagIncrementoPagina == 0)
			{
				paginaAttivata--;
				flagIncrementoPagina = 1;
			}

			if (DISPbtn == 0 && flagIncrementoPagina == 1)
			{
				paginaAttivata--;
				flagIncrementoPagina = 0;
			}

			if (MAPbtn == 1 && flagDecrementoPagina == 0) {
				paginaAttivata++;
				flagDecrementoPagina = 1;
			}

			if (MAPbtn == 0 && flagDecrementoPagina == 1) {
				paginaAttivata++;
				flagDecrementoPagina = 0;
			}
		}
		else
		{
			if (DISPbtn == 1 && flagIncrementoPagina == 0)
			{
				paginaAttivata++;
				flagIncrementoPagina = 1;
			}

			if (DISPbtn == 0 && flagIncrementoPagina == 1)
			{
				paginaAttivata++;
				flagIncrementoPagina = 0;
			}
		}

		if (paginaAttivata > 5)
		{
			paginaAttivata = 1;
		}
		else if (paginaAttivata < 1)
		{
			paginaAttivata = 5;
		}


		//paginaAttivata = 2;		//WARNING: SOLO DEBUG

		static uint8_t changePageFloag = 0;

		if (selectedGui != GuiAlarm && DEBUG_MODE == 0)
		{
			if(selectedGui_old != GuiAlarm && changePageFloag)
			{
				switch (paginaAttivata)
				{
					case 1:
						selectedGui = GuiDrive1;					//ENDURANCE
						break;

					case 2:
						//selectedGui = GuiDrive2;
						selectedGui = GuiOld1;						//AUTOCROSS
						break;

					case 3:
						selectedGui = GuiHandlingCurvesTest;		//SKIDPAD
						break;

					case 4:
						selectedGui = GuiAcceleration;				//ACCELERATION
						break;

					case 5:
						selectedGui = GuiCarSetup;
						break;

					case 6:
						selectedGui = GuiOld1;
						break;

					default:
						selectedGui = GuiDrive1;

				}

				changePageFloag = 0;
			}
			else
			{
				static uint32_t millisWaitToChangePage = 0;

				if(millisWaitToChangePage == 0)
					millisWaitToChangePage = millis;

				if(millis - millisWaitToChangePage >= 50)
				{
					millisWaitToChangePage = 0;
					changePageFloag = 1;
				}
			}
		}

		//Display page selection END



		// MAP debounce section BEGIN

		uint8_t readingMAP = HAL_GPIO_ReadPin(Map_BTN_F_GPIO_Port, Map_BTN_F_Pin);

		// check to see if you just pressed the button
		// (i.e. the input went from LOW to HIGH), and you've waited long enough
		// since the last press to ignore any noise:

		// If the switch changed, due to noise or pressing:
		if (readingMAP != lastButtonStateMAP)
		{
			// reset the debouncing timer
			lastDebounceTimeMAP = millis;
		}

		if ((millis - lastDebounceTimeMAP) > debounceDelay)
		{
			// whatever the reading is at, it's been there for longer than the debounce
			// delay, so take it as the actual current state:

			// if the button state has changed:
			if (readingMAP != buttonStateMAP)
			{
				buttonStateMAP = readingMAP;

				// only toggle the LED if the new button state is HIGH
				if (buttonStateMAP == 1)
				{
					//HAL_GPIO_TogglePin(MAP_OUT_GPIO_Port, MAP_OUT_Pin);
					MAPbtn = !MAPbtn;
				}
			}
		}

		if(MAP_CHANGE_ENABLE == ENABLE)
			HAL_GPIO_WritePin(MAP_OUT_GPIO_Port, MAP_OUT_Pin, !MAPbtn);
		else
			HAL_GPIO_WritePin(MAP_OUT_GPIO_Port, MAP_OUT_Pin, 1);

		//map = MAPbtn;
		CAR_Data.map.intData = !HAL_GPIO_ReadPin(MAP_OUT_GPIO_Port, MAP_OUT_Pin);
		map = CAR_Data.map.intData;

		CAR_Data.map.floatData = CAR_Data.map.intData;

		map_pp = CAR_Data.map.intData + 1;
		// save the reading. Next time through the loop, it'll be the lastButtonState:
		lastButtonStateMAP = readingMAP;

		// MAP debounce section END



		//MDM Debug Code BEGIN

#if DEBUG_MODE == 1

		static uint8_t debugModeSetupFlag = 0;

		if(debugModeSetupFlag == 0)
		{
			debugModeSetupFlag = 1;


			//selectedGui = GuiPowertrainData1;		//Warning: only for DEBUG

			//selectedGui = GuiOld1;
			//selectedGui = GuiOld2;
			//selectedGui = GuiAcceleration;

			selectedGui = GuiDrive1;
			//selectedGui = GuiDrive2;

			//selectedGui = GuiHandlingCurvesTest;

			//selectedGui = GuiCarSetup;



			//CAN_DATA_GuiPopUp_Disable(0);		//Traction, 			change
			//CAN_DATA_GuiPopUp_Disable(1);		//MAP,				 	change

			//CAN_DATA_GuiPopUp_Disable(2);		//Water Temperature, 	range
			//CAN_DATA_GuiPopUp_Disable(3);		//Oil Temperature,		range
			//CAN_DATA_GuiPopUp_Disable(4);		//Fuel Pressure, 		range
			//CAN_DATA_GuiPopUp_Disable(5);		//Oil Pressure, 		range
			//CAN_DATA_GuiPopUp_Disable(6);		//RPM,					range
			//CAN_DATA_GuiPopUp_Disable(7);		//BSPD,					range

			//CAN_DATA_GuiPopUp_DisableAll();

			CAR_Data.steer.floatData = steer_MIN_VALUE;
			CAR_Data.speed.floatData = 140;
		}

		if(DEBUG_BSPD == 1)
		{
			CAR_Data.brake.floatData += 0.0003;

			if(CAR_Data.brake.floatData > 20)
			{
				CAR_Data.brake.floatData = 0;
			}

			//CAR_Data.brake.floatData = 10;

			CAR_Data.brake.intData = CAR_Data.brake.floatData;
			CAR_Data.brake.oldTimeData = CAR_Data.brake.lastTimeData;
			CAR_Data.brake.lastTimeData = millis;



			CAR_Data.tps.floatData += 0.0003;

			if(CAR_Data.tps.floatData > 100)
			{
				CAR_Data.tps.floatData = 0;
			}

			CAR_Data.tps.intData = CAR_Data.tps.floatData;
			CAR_Data.tps.oldTimeData = CAR_Data.tps.lastTimeData;
			CAR_Data.tps.lastTimeData = millis;


			if(CAR_Data.BSPD_warning == 1)
			{
				CAR_Data.tps.intData = 0;
				CAR_Data.tps.floatData = 0;
			}

			goto END_OF_DEBUG_SECTION;
		}
		else
		{
			CAN_DATA_GuiPopUp_Disable(7);		//BSPD,					range
		}


/*
		static uint32_t millisPageToggle = 0;

		if(millis >= millisPageToggle + 10000)
		{
			if(selectedGui == GuiDrive1)
				selectedGui = GuiDrive2;
			else if(selectedGui == GuiDrive2)
				selectedGui = GuiHandlingCurvesTest;
			else
				selectedGui = GuiDrive1;

			millisPageToggle = millis;
		}
*/


		CAR_Data.canLastReceiveTime = millis;

		uint32_t static drsTime = 0;

		if(millis >= drsTime + 1000)
		{
			//drive1_gui_data[11].dataLogInt.number = !drive1_gui_data[11].dataLogInt.number;

			if(CAR_Data.drsStatus.intData != 0)
				CAR_Data.drsStatus.intData = 0;
			else
				CAR_Data.drsStatus.intData = 1;

			CAR_Data.drsStatus.floatData = CAR_Data.drsStatus.intData;
			CAR_Data.drsStatus.lastTimeData = millis;

			drsTime = millis;

			if(tAir < 100)
				CAR_Data.airTemp.floatData += 4.9;
			else
				tAir = 0;

			CAR_Data.airTemp.intData = CAR_Data.airTemp.floatData;
			CAR_Data.airTemp.oldTimeData = CAR_Data.airTemp.lastTimeData;
			CAR_Data.airTemp.lastTimeData = millis;
		}

		CAR_Data.waterTemp.oldTimeData = CAR_Data.waterTemp.lastTimeData;
		CAR_Data.waterTemp.floatData += 0.0001;
		CAR_Data.waterTemp.intData = CAR_Data.waterTemp.floatData;
		CAR_Data.waterTemp.lastTimeData = millis;

		if(CAR_Data.waterTemp.floatData >= 150)
			CAR_Data.waterTemp.floatData = 0;


		CAR_Data.oilPressure.oldTimeData = CAR_Data.oilPressure.lastTimeData;
		CAR_Data.oilPressure.floatData += 0.0001;
		CAR_Data.oilPressure.intData = CAR_Data.oilPressure.floatData;
		CAR_Data.oilPressure.lastTimeData = millis;

		if(CAR_Data.oilPressure.floatData >= 15)
			CAR_Data.oilPressure.floatData = -15;


		static uint32_t millisTraction = 0;

		if(millis > millisTraction + 7000)
		{
			millisTraction = millis;

			if(CAR_Data.tractionControl.intData < 4)
				CAR_Data.tractionControl.intData++;
			else
				CAR_Data.tractionControl.intData = 0;
		}


		CAR_Data.tractionControl.floatData = CAR_Data.tractionControl.intData;
		CAR_Data.tractionControl.oldTimeData = CAR_Data.tractionControl.lastTimeData;
		CAR_Data.tractionControl.lastTimeData = millis;


		static uint32_t millisGear = 0;

		if(millis > millisGear + 1000)
		{
			millisGear = millis;

			if(CAR_Data.gear.intData < 4)
				CAR_Data.gear.intData++;
			else
				CAR_Data.gear.intData = 0;
		}

		CAR_Data.gear.floatData = CAR_Data.gear.intData;
		CAR_Data.gear.oldTimeData = CAR_Data.gear.lastTimeData;
		CAR_Data.gear.lastTimeData = millis;


		if(CAR_Data.rpm.floatData > 13000)
			CAR_Data.rpm.floatData = 8000;

		CAR_Data.rpm.floatData += 0.1;
		CAR_Data.rpm.intData = CAR_Data.rpm.floatData;
		CAR_Data.rpm.oldTimeData = CAR_Data.rpm.lastTimeData;
		CAR_Data.rpm.lastTimeData = millis;


		CAR_Data.steer.floatData += 0.001;

		if(CAR_Data.steer.floatData > steer_MAX_VALUE)
		{
			CAR_Data.steer.floatData = steer_MIN_VALUE;
		}

		CAR_Data.steer.intData = CAR_Data.steer.floatData;
		CAR_Data.steer.oldTimeData = CAR_Data.rpm.lastTimeData;
		CAR_Data.steer.lastTimeData = millis;



		CAR_Data.brake.floatData -= 0.0002;

		if(CAR_Data.brake.floatData < 1)
		{
			CAR_Data.brake.floatData = 20;
		}

		//CAR_Data.brake.floatData = 20;

		CAR_Data.brake.intData = CAR_Data.brake.floatData;
		CAR_Data.brake.oldTimeData = CAR_Data.brake.lastTimeData;
		CAR_Data.brake.lastTimeData = millis;


		CAR_Data.brakeRear.floatData += 0.0003;

		if(CAR_Data.brakeRear.floatData > 18)
		{
			CAR_Data.brakeRear.floatData = 0;
		}

		CAR_Data.brakeRear.intData = CAR_Data.brakeRear.floatData;
		CAR_Data.brakeRear.oldTimeData = CAR_Data.brakeRear.lastTimeData;
		CAR_Data.brakeRear.lastTimeData = millis;



		CAR_Data.speed.floatData-=0.0007;
		if(CAR_Data.speed.floatData <= 0)
		{
			CAR_Data.speed.floatData = 140;
		}

		CAR_Data.speed.intData = CAR_Data.speed.floatData;
		CAR_Data.speed.oldTimeData = CAR_Data.speed.lastTimeData;
		CAR_Data.speed.lastTimeData = millis;


		END_OF_DEBUG_SECTION:;


		//HAL_GPIO_WritePin(LCD_DISP_GPIO_Port, LCD_DISP_Pin, 1);

#elif DEBUG_MODE == 2
		selectedGui = GuiDrive1;
#endif

		//MDM Debug Code END



		//CAN_DATA_GuiPopUp_Disable(0);		//Traction, 			change
		//CAN_DATA_GuiPopUp_Disable(2);		//Water Temperature, 	range
		//CAN_DATA_GuiPopUp_Disable(3);		//Oil Temperature,		range
		//CAN_DATA_GuiPopUp_Disable(4);		//Fuel Pressure, 		range
		//CAN_DATA_GuiPopUp_Disable(5);		//Oil Pressure, 		range
		CAN_DATA_GuiPopUp_Disable(6);		//RPM,					range
		CAN_DATA_GuiPopUp_Disable(7);		//BSPD,					range
		CAN_DATA_GuiPopUp_Disable(8);		//Water pump,			change
		CAN_DATA_GuiPopUp_Disable(9);		//Water pump,			range

		static uint32_t millisDelayEnableOilPressureAlarm = 0;
		static uint32_t oilPressureAlarmEnableStatus = 0;

		if(CAR_Data.rpm.intData <= 2500)
		{
			CAN_DATA_GuiPopUp_Disable(5);			//Oil Pressure, 		range

			if(CAR_Data.rpm.intData <= 1000)
				CAN_DATA_GuiPopUp_Disable(4);		//Fuel Pressure, 		range

			oilPressureAlarmEnableStatus = 1;
			millisDelayEnableOilPressureAlarm = millis;
		}
		else
		{
			if(oilPressureAlarmEnableStatus == 1 && millis >= millisDelayEnableOilPressureAlarm + 5000)
			{
				CAN_DATA_GuiRangePopUp_Enable(5);	//Oil Pressure, 		range

				CAN_DATA_GuiRangePopUp_Enable(4);	//Fuel Pressure, 		range

				oilPressureAlarmEnableStatus = 0;
			}
		}



		dashboardLedControl();

		DisplayGui();


		__HAL_IWDG_RELOAD_COUNTER(&hiwdg);

	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 432;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 8;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_LTDC|RCC_PERIPHCLK_USART1
                              |RCC_PERIPHCLK_SDMMC1|RCC_PERIPHCLK_CLK48;
  PeriphClkInitStruct.PLLSAI.PLLSAIN = 192;
  PeriphClkInitStruct.PLLSAI.PLLSAIR = 3;
  PeriphClkInitStruct.PLLSAI.PLLSAIQ = 2;
  PeriphClkInitStruct.PLLSAI.PLLSAIP = RCC_PLLSAIP_DIV4;
  PeriphClkInitStruct.PLLSAIDivQ = 1;
  PeriphClkInitStruct.PLLSAIDivR = RCC_PLLSAIDIVR_4;
  PeriphClkInitStruct.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  PeriphClkInitStruct.Clk48ClockSelection = RCC_CLK48SOURCE_PLLSAIP;
  PeriphClkInitStruct.Sdmmc1ClockSelection = RCC_SDMMC1CLKSOURCE_CLK48;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void dashboardLedControl(void)
{
	static uint8_t ledStartingProcedureDone = 0;

	if(ledStartingProcedureDone == 0)
	{
		static uint32_t millisLedStartingProcedure = 0;

		if(millisLedStartingProcedure < 500)
		{
			millisLedStartingProcedure = millis;

			HAL_GPIO_WritePin(_5V_OUT1_GPIO_Port, _5V_OUT1_Pin, 1);
		}
		else if(millisLedStartingProcedure < 2000)
		{
			if(millis >= millisLedStartingProcedure + 50)
			{
				HAL_GPIO_TogglePin(_5V_OUT1_GPIO_Port, _5V_OUT1_Pin);
				millisLedStartingProcedure = millis;
			}
		}
		else if(millisLedStartingProcedure < 2500)
		{
			millisLedStartingProcedure = millis;
			HAL_GPIO_WritePin(_5V_OUT1_GPIO_Port, _5V_OUT1_Pin, 1);
		}
		else
		{
			HAL_GPIO_WritePin(_5V_OUT1_GPIO_Port, _5V_OUT1_Pin, 0);
			ledStartingProcedureDone = 1;
			millisLedStartingProcedure = millis;
		}

		goto END_OF_FUNCTION;
	}

	static uint8_t ledAlarmDetected = 0;


	static uint32_t millisLedAlarmActivation = 0;

	if((CAR_Data.waterTemp.floatData > CAR_Data.waterTemp.maxValue && millis - CAR_Data.waterTemp.lastTimeData <= 100)
			|| (CAR_Data.oilTemp.floatData > CAR_Data.oilTemp.maxValue && millis - CAR_Data.oilTemp.lastTimeData <= 100)
			|| ((CAR_Data.oilTemp.floatData < CAR_Data.oilTemp.minValue && CAR_Data.rpm.intData > 1000 && millis - CAR_Data.oilTemp.lastTimeData <= 100))
			|| (CAR_Data.oilPressure.floatData > CAR_Data.oilPressure.maxValue && millis - CAR_Data.oilPressure.lastTimeData <= 100)
			|| ((CAR_Data.oilPressure.floatData < CAR_Data.oilPressure.minValue && CAR_Data.rpm.intData > 1000 && millis - CAR_Data.oilPressure.lastTimeData <= 100))
			)
	{
		if(millis - millisLedAlarmActivation >= 500)
		{
			ledAlarmDetected = 1;
		}
	}
	else
	{
		millisLedAlarmActivation = millis;
		ledAlarmDetected = 0;
	}



	static uint8_t blinkCounter = 0;

	if(ledAlarmDetected != 0)
	{
		static uint32_t millisLedAlarmDetected = 0;

		if(millis >= millisLedAlarmDetected + 50 && blinkCounter <= 30)
		{
			blinkCounter++;
			HAL_GPIO_TogglePin(_5V_OUT1_GPIO_Port, _5V_OUT1_Pin);
			millisLedAlarmDetected = millis;
		}

		if(blinkCounter >= 10)
			HAL_GPIO_WritePin(_5V_OUT1_GPIO_Port, _5V_OUT1_Pin, 1);
	}
	else
	{
		blinkCounter = 0;
		HAL_GPIO_WritePin(_5V_OUT1_GPIO_Port, _5V_OUT1_Pin, 0);
	}

	END_OF_FUNCTION:;
}


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */

	DisplayGui_Init();

	__disable_irq(); //Do not remove

	GUI_Clear();
	GUI_SetColor(GUI_RED);
	GUI_SetFont(&GUI_Font32_1);
	GUI_DispStringAt("SETUP ERROR!", (480 - 200) / 2, (272 - 20) / 2);

	GUI_SetTextAlign(GUI_TA_HCENTER);
	GUI_DispDecAt(Error_Handler_Code, 480 / 2, (272 - 20) / 2 + 32, 3);

	DisplayON();

	while (1)
	{
		/*
		 HAL_GPIO_WritePin(LCD_BL_CTRL_GPIO_Port, LCD_BL_CTRL_Pin, 1);
		 HAL_Delay(1000);
		 HAL_GPIO_WritePin(LCD_BL_CTRL_GPIO_Port, LCD_BL_CTRL_Pin, 0);
		 HAL_Delay(500);
		 */
	}
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
