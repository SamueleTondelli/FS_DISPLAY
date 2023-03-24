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

#ifndef __MCU_TEMPERATURE_H
#include "mcu_temperature.h"
#endif

#ifndef __ADC_H
#include "adc.h"
#endif

#ifndef __MDM_FUNCTIONS_H
#include "MDM_Functions.h"
#endif

#define TEMP_SENSOR_AVG_SLOPE_MV_PER_CELSIUS                        25 // 2.5 but multiplied for 10
#define TEMP_SENSOR_VOLTAGE_MV_AT_25                                760
#define ADC_REFERENCE_VOLTAGE_MV                                    3300
#define ADC_MAX_OUTPUT_VALUE                                        4095

int32_t MCU_temperature = 0;
float MCU_Temperature = 0;


void readMcuTemperature(void)
{
	static uint32_t refreshTime = 0;

	if(millis > 100)
	if(millis < refreshTime + MCU_TEMPERATURE_REFRESH_TIME)
		goto readMcuTemperature_END;

	refreshTime = millis;

	/*---readMcuTemperature function core BEGIN---*/
	static uint8_t dataToReadFlag = 0;

	uint32_t sensorValue = 0;

	//float adcCalValue30 = (float)(*TEMP30_CAL_VALUE);
	//float adcCalValue110 = (float)(*TEMP110_CAL_VALUE);

	if(dataToReadFlag == 0)
	{
		ADC_ChannelConfTypeDef sConfig = {0};

		sConfig.Channel = ADC_CHANNEL_TEMPSENSOR;
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
			sensorValue = map_int32(sensorValue, 0, ADC_MAX_OUTPUT_VALUE, 0, ADC_REFERENCE_VOLTAGE_MV);
			//MCU_temperature = sensorValue;

			MCU_temperature = ((sensorValue - TEMP_SENSOR_VOLTAGE_MV_AT_25)*10)/TEMP_SENSOR_AVG_SLOPE_MV_PER_CELSIUS + 25;
			MCU_Temperature = ((float)((sensorValue - TEMP_SENSOR_VOLTAGE_MV_AT_25)*10))/((float)(TEMP_SENSOR_AVG_SLOPE_MV_PER_CELSIUS)) + 25;

		}
		else
			dataToReadFlag = 2;
	}


	/*---readMcuTemperature function core END---*/


	readMcuTemperature_END:;
}
