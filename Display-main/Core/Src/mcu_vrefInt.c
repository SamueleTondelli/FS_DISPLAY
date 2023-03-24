/*
 * In this file there are some functions to read the MCU's internal temperature sensor
 *
 * To use these functions ADC1 must be configured correctly
 *
 * Created By Mario Di Marino (MDM)
 *
 * 21/06/2021 dd/mm/yy
 *
 */

#ifndef __MCU_VREFINT_H
#include "mcu_vrefInt.h"
#endif

#ifndef __ADC_H
#include "adc.h"
#endif

#ifndef __MDM_FUNCTIONS_H
#include "MDM_Functions.h"
#endif

#define ADC_REFERENCE_VOLTAGE_MV                                    3300
#define ADC_MAX_OUTPUT_VALUE                                        4095

int32_t MCU_vrefInt = 0;
float MCU_VrefInt = 0;

uint16_t testAdc = 0;

void readMcuVrefInt(void)
{
	static uint32_t refreshTime = 0;

	if(millis > 100)
	if(millis < refreshTime + MCU_VREFINT_REFRESH_TIME)
		goto readMcuVrefInt_END;

	refreshTime = millis;

	/*---readMcuVrefInt function core BEGIN---*/
	static uint8_t dataToReadFlag = 0;

	uint32_t sensorValue = 0;


	if(dataToReadFlag == 0)
	{
		ADC_ChannelConfTypeDef sConfig = {0};

		sConfig.Channel = ADC_CHANNEL_VREFINT;
		sConfig.Rank = ADC_REGULAR_RANK_1;
		sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;
		HAL_ADC_ConfigChannel(&hadc1, &sConfig);

		HAL_ADC_Start(&hadc1);
		dataToReadFlag = 1;
	}
	else
	{
		if(HAL_ADC_PollForConversion(&hadc1, 0) == HAL_OK)
		{
			sensorValue = HAL_ADC_GetValue(&hadc1);
			HAL_ADC_Stop(&hadc1);
			dataToReadFlag = 0;

			testAdc = sensorValue;

			MCU_vrefInt = ((sensorValue * ADC_MAX_OUTPUT_VALUE) / ADC_REFERENCE_VOLTAGE_MV) / 1000;
			MCU_VrefInt = ((float)(sensorValue * ADC_MAX_OUTPUT_VALUE) / (float)ADC_REFERENCE_VOLTAGE_MV) / 1000;
		}
		else
			dataToReadFlag = 2;
	}


	/*---readMcuVrefInt function core END---*/


	readMcuVrefInt_END:;
}
