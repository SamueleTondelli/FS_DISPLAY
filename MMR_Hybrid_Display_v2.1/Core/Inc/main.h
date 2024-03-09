/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SPARE10_Pin GPIO_PIN_3
#define SPARE10_GPIO_Port GPIOE
#define LCD_BL_CTRL_Pin GPIO_PIN_7
#define LCD_BL_CTRL_GPIO_Port GPIOF
#define TEMP_Pin GPIO_PIN_1
#define TEMP_GPIO_Port GPIOC
#define AN1_F_Pin GPIO_PIN_2
#define AN1_F_GPIO_Port GPIOC
#define AN2_F_Pin GPIO_PIN_3
#define AN2_F_GPIO_Port GPIOC
#define U_LED_Pin GPIO_PIN_7
#define U_LED_GPIO_Port GPIOA
#define AN3_F_Pin GPIO_PIN_4
#define AN3_F_GPIO_Port GPIOC
#define AN4_F_Pin GPIO_PIN_5
#define AN4_F_GPIO_Port GPIOC
#define SPARE25_Pin GPIO_PIN_1
#define SPARE25_GPIO_Port GPIOJ
#define SPARE24_Pin GPIO_PIN_2
#define SPARE24_GPIO_Port GPIOJ
#define SPARE23_Pin GPIO_PIN_4
#define SPARE23_GPIO_Port GPIOJ
#define SPARE3_Pin GPIO_PIN_11
#define SPARE3_GPIO_Port GPIOB
#define SPARE19_Pin GPIO_PIN_6
#define SPARE19_GPIO_Port GPIOH
#define SPARE18_Pin GPIO_PIN_7
#define SPARE18_GPIO_Port GPIOH
#define _5V_OUT2_Pin GPIO_PIN_11
#define _5V_OUT2_GPIO_Port GPIOD
#define _5V_OUT1_Pin GPIO_PIN_12
#define _5V_OUT1_GPIO_Port GPIOD
#define MAP_OUT_Pin GPIO_PIN_13
#define MAP_OUT_GPIO_Port GPIOD
#define SPARE16_Pin GPIO_PIN_3
#define SPARE16_GPIO_Port GPIOG
#define SPARE15_Pin GPIO_PIN_7
#define SPARE15_GPIO_Port GPIOG
#define SPARE4_Pin GPIO_PIN_6
#define SPARE4_GPIO_Port GPIOC
#define SPARE2_Pin GPIO_PIN_9
#define SPARE2_GPIO_Port GPIOA
#define _5V_OUT4_Pin GPIO_PIN_4
#define _5V_OUT4_GPIO_Port GPIOD
#define _5V_OUT3_Pin GPIO_PIN_5
#define _5V_OUT3_GPIO_Port GPIOD
#define SPARE9_Pin GPIO_PIN_7
#define SPARE9_GPIO_Port GPIOD
#define SPARE21_Pin GPIO_PIN_14
#define SPARE21_GPIO_Port GPIOJ
#define SPARE14_Pin GPIO_PIN_9
#define SPARE14_GPIO_Port GPIOG
#define uSD_DETECT_Pin GPIO_PIN_10
#define uSD_DETECT_GPIO_Port GPIOG
#define SPARE13_Pin GPIO_PIN_11
#define SPARE13_GPIO_Port GPIOG
#define SPARE12_Pin GPIO_PIN_13
#define SPARE12_GPIO_Port GPIOG
#define SPARE11_Pin GPIO_PIN_14
#define SPARE11_GPIO_Port GPIOG
#define LCD_DISP_Pin GPIO_PIN_3
#define LCD_DISP_GPIO_Port GPIOK
#define SPARE27_Pin GPIO_PIN_4
#define SPARE27_GPIO_Port GPIOK
#define SPARE26_Pin GPIO_PIN_7
#define SPARE26_GPIO_Port GPIOK
#define DIG4_F_Pin GPIO_PIN_4
#define DIG4_F_GPIO_Port GPIOB
#define DIG3_F_Pin GPIO_PIN_5
#define DIG3_F_GPIO_Port GPIOB
#define OK_BTN_Pin GPIO_PIN_6
#define OK_BTN_GPIO_Port GPIOB
#define MARK_BTN_Pin GPIO_PIN_7
#define MARK_BTN_GPIO_Port GPIOB
#define MAP_BTN_Pin GPIO_PIN_8
#define MAP_BTN_GPIO_Port GPIOB
#define DISP_BTN_Pin GPIO_PIN_9
#define DISP_BTN_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
