/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include "can.h"
#include "app_touchgfx.h"
#include "../../Code/include/c_interface.h"

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
/* USER CODE BEGIN Variables */


// CAN header TX & RX
extern CAN_HandleTypeDef hcan1;
extern CAN_TxHeaderTypeDef ptxHeader;
extern CAN_RxHeaderTypeDef prxHeader;
	// CAN Mailbox
extern uint32_t txMailbox;
	// CAN Filter
extern CAN_FilterTypeDef sFilterConfig;

// Timers
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim7;
extern TIM_HandleTypeDef htim8;

/* USER CODE END Variables */
osThreadId touchGFXTaskHandle;
osThreadId rtosAlarmHandleHandle;
osThreadId rtosControlsHanHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartTouchGFXTask(void const * argument);
void rtosAlarmHandlerTask(void const * argument);
void rtosControlsHandlerTask(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of touchGFXTask */
  osThreadDef(touchGFXTask, StartTouchGFXTask, osPriorityNormal, 0, 8192);
  touchGFXTaskHandle = osThreadCreate(osThread(touchGFXTask), NULL);

  /* definition and creation of rtosAlarmHandle */
  osThreadDef(rtosAlarmHandle, rtosAlarmHandlerTask, osPriorityIdle, 0, 128);
  rtosAlarmHandleHandle = osThreadCreate(osThread(rtosAlarmHandle), NULL);

  /* definition and creation of rtosControlsHan */
  osThreadDef(rtosControlsHan, rtosControlsHandlerTask, osPriorityIdle, 0, 128);
  rtosControlsHanHandle = osThreadCreate(osThread(rtosControlsHan), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartTouchGFXTask */
/**
  * @brief  Function implementing the touchGFXTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartTouchGFXTask */
void StartTouchGFXTask(void const * argument)
{
  /* USER CODE BEGIN StartTouchGFXTask */
/*
  //TIMER
  HAL_TIM_Base_Start_IT(&htim7); //TIM7 -> for FPS counter synchronize
  HAL_TIM_Base_Start_IT(&htim2); //TIM2 -> for Display Update synchronize

  // Enable CAN Routine
  CAN1_Config(&prxHeader, &prxHeader, &sFilterConfig);
  HAL_CAN_ConfigFilter(&hcan1, &sFilterConfig);
  HAL_CAN_Start(&hcan1);
  HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
*/

  MX_TouchGFX_Process();

  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTouchGFXTask */
}

/* USER CODE BEGIN Header_rtosAlarmHandlerTask */
/**
* @brief Function implementing the rtosAlarmHandle thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_rtosAlarmHandlerTask */
void rtosAlarmHandlerTask(void const * argument)
{
  /* USER CODE BEGIN rtosAlarmHandlerTask */
  startAlarmHandlerTask();
  //should not get here
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END rtosAlarmHandlerTask */
}

/* USER CODE BEGIN Header_rtosControlsHandlerTask */
/**
* @brief Function implementing the rtosControlsHan thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_rtosControlsHandlerTask */
void rtosControlsHandlerTask(void const * argument)
{
  /* USER CODE BEGIN rtosControlsHandlerTask */
  startControlsHandlerTask();
  //should not get here
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END rtosControlsHandlerTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

