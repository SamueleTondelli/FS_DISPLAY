/**
  ******************************************************************************
  * @file    quadspi.c
  * @brief   This file provides code for the configuration
  *          of the QUADSPI instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "quadspi.h"

/* USER CODE BEGIN 0 */

#include "n25q128a.h"

/* Private functions ---------------------------------------------------------*/

/** @defgroup MDM_QSPI_Private_Functions N25Q128A QSPI Private Functions
  * @{
  */
//static uint8_t MDM_QSPI_Init(void);
//static uint8_t MDM_QSPI_ResetMemory          (QSPI_HandleTypeDef *hqspi);
//static uint8_t MDM_QSPI_DummyCyclesCfg       (QSPI_HandleTypeDef *hqspi);
//static uint8_t MDM_QSPI_WriteEnable          (QSPI_HandleTypeDef *hqspi);
//static uint8_t MDM_QSPI_AutoPollingMemReady  (QSPI_HandleTypeDef *hqspi, uint32_t Timeout);

/**
  * @}
  */

static uint8_t QSPI_WriteEnable(void);
static uint8_t QSPI_AutoPollingMemReady(void);
static uint8_t QSPI_Configuration(void);
static uint8_t QSPI_ResetChip(void);

/* USER CODE END 0 */

QSPI_HandleTypeDef hqspi;

/* QUADSPI init function */
void MX_QUADSPI_Init(void)
{

  /* USER CODE BEGIN QUADSPI_Init 0 */

  /* USER CODE END QUADSPI_Init 0 */

  /* USER CODE BEGIN QUADSPI_Init 1 */

  /* USER CODE END QUADSPI_Init 1 */
  hqspi.Instance = QUADSPI;
  hqspi.Init.ClockPrescaler = 1;
  hqspi.Init.FifoThreshold = 4;
  hqspi.Init.SampleShifting = QSPI_SAMPLE_SHIFTING_HALFCYCLE;
  hqspi.Init.FlashSize = 23;
  hqspi.Init.ChipSelectHighTime = QSPI_CS_HIGH_TIME_6_CYCLE;
  hqspi.Init.ClockMode = QSPI_CLOCK_MODE_0;
  hqspi.Init.FlashID = QSPI_FLASH_ID_1;
  hqspi.Init.DualFlash = QSPI_DUALFLASH_DISABLE;
  if (HAL_QSPI_Init(&hqspi) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN QUADSPI_Init 2 */

  /* USER CODE END QUADSPI_Init 2 */

}

void HAL_QSPI_MspInit(QSPI_HandleTypeDef* qspiHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(qspiHandle->Instance==QUADSPI)
  {
  /* USER CODE BEGIN QUADSPI_MspInit 0 */

  /* USER CODE END QUADSPI_MspInit 0 */
    /* QUADSPI clock enable */
    __HAL_RCC_QSPI_CLK_ENABLE();

    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**QUADSPI GPIO Configuration
    PE2     ------> QUADSPI_BK1_IO2
    PF6     ------> QUADSPI_BK1_IO3
    PF8     ------> QUADSPI_BK1_IO0
    PF9     ------> QUADSPI_BK1_IO1
    PB2     ------> QUADSPI_CLK
    PB10     ------> QUADSPI_BK1_NCS
    */
    GPIO_InitStruct.Pin = GPIO_PIN_2;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_QUADSPI;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_QUADSPI;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF10_QUADSPI;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_10;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF9_QUADSPI;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN QUADSPI_MspInit 1 */

  /* USER CODE END QUADSPI_MspInit 1 */
  }
}

void HAL_QSPI_MspDeInit(QSPI_HandleTypeDef* qspiHandle)
{

  if(qspiHandle->Instance==QUADSPI)
  {
  /* USER CODE BEGIN QUADSPI_MspDeInit 0 */

  /* USER CODE END QUADSPI_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_QSPI_CLK_DISABLE();

    /**QUADSPI GPIO Configuration
    PE2     ------> QUADSPI_BK1_IO2
    PF6     ------> QUADSPI_BK1_IO3
    PF8     ------> QUADSPI_BK1_IO0
    PF9     ------> QUADSPI_BK1_IO1
    PB2     ------> QUADSPI_CLK
    PB10     ------> QUADSPI_BK1_NCS
    */
    HAL_GPIO_DeInit(GPIOE, GPIO_PIN_2);

    HAL_GPIO_DeInit(GPIOF, GPIO_PIN_6|GPIO_PIN_8|GPIO_PIN_9);

    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_2|GPIO_PIN_10);

  /* USER CODE BEGIN QUADSPI_MspDeInit 1 */

  /* USER CODE END QUADSPI_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */


/* USER CODE BEGIN 1 */

/* QUADSPI init function */

uint8_t CSP_QUADSPI_Init(void)
{
    //prepare QSPI peripheral for ST-Link Utility operations
	hqspi.Instance = QUADSPI;
    if (HAL_QSPI_DeInit(&hqspi) != HAL_OK) {
        return HAL_ERROR;
    }

    HAL_Delay(1);

    MX_QUADSPI_Init();

    HAL_Delay(1);

    if (QSPI_ResetChip() != HAL_OK) {
        return HAL_ERROR;
    }

    HAL_Delay(1);

    if (QSPI_AutoPollingMemReady() != HAL_OK) {
        return HAL_ERROR;
    }

    if (QSPI_WriteEnable() != HAL_OK) {
        return HAL_ERROR;
    }

    if (QSPI_Configuration() != HAL_OK) {
        return HAL_ERROR;
    }

    return HAL_OK;
}


uint8_t CSP_QSPI_Erase_Chip(void)
{
    QSPI_CommandTypeDef sCommand;


    if (QSPI_WriteEnable() != HAL_OK) {
        return HAL_ERROR;
    }

    HAL_Delay(2);

    /* Erasing Sequence --------------------------------- */
    sCommand.Instruction = BULK_ERASE_CMD;
    sCommand.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    sCommand.AddressSize = QSPI_ADDRESS_24_BITS;
    sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
    sCommand.DdrMode = QSPI_DDR_MODE_DISABLE;
    sCommand.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
    sCommand.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;
    sCommand.AddressMode = QSPI_ADDRESS_NONE;
    sCommand.Address = 0;
    sCommand.DataMode = QSPI_DATA_NONE;
    sCommand.DummyCycles = 0;


    if (HAL_QSPI_Command(&hqspi, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE)
        != HAL_OK) {
        return HAL_ERROR;
    }

    HAL_Delay(20);

    if (QSPI_AutoPollingMemReady() != HAL_OK) {
        return HAL_ERROR;
    }

    return HAL_OK;
}

uint8_t QSPI_AutoPollingMemReady(void)
{

    QSPI_CommandTypeDef sCommand;
    QSPI_AutoPollingTypeDef sConfig;

    /* Configure automatic polling mode to wait for memory ready ------ */
    sCommand.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    sCommand.Instruction = READ_STATUS_REG_CMD;
    sCommand.AddressMode = QSPI_ADDRESS_NONE;
    sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
    sCommand.DataMode = QSPI_DATA_1_LINE;
    sCommand.DummyCycles = 0;
    sCommand.DdrMode = QSPI_DDR_MODE_DISABLE;
    sCommand.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
    sCommand.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

    sConfig.Match = 0x00;
    sConfig.Mask = N25Q128A_SR_WIP;
    sConfig.MatchMode = QSPI_MATCH_MODE_AND;
    sConfig.StatusBytesSize = 1;
    sConfig.Interval = 0x10;
    sConfig.AutomaticStop = QSPI_AUTOMATIC_STOP_ENABLE;

    if (HAL_QSPI_AutoPolling(&hqspi, &sCommand, &sConfig, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
        return HAL_ERROR;
    }

    return HAL_OK;
}

static uint8_t QSPI_WriteEnable(void)
{
    QSPI_CommandTypeDef sCommand;
    QSPI_AutoPollingTypeDef sConfig;

    /* Enable write operations ------------------------------------------ */
    sCommand.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    sCommand.Instruction = WRITE_ENABLE_CMD;
    sCommand.AddressMode = QSPI_ADDRESS_NONE;
    sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
    sCommand.DataMode = QSPI_DATA_NONE;
    sCommand.DummyCycles = 0;
    sCommand.DdrMode = QSPI_DDR_MODE_DISABLE;
    sCommand.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
    sCommand.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

    if (HAL_QSPI_Command(&hqspi, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE)
        != HAL_OK) {
        return HAL_ERROR;
    }

    /* Configure automatic polling mode to wait for write enabling ---- */
    sConfig.Match = 0x02;
    sConfig.Mask = 0x02;
    sConfig.MatchMode = QSPI_MATCH_MODE_AND;
    sConfig.StatusBytesSize = 1;
    sConfig.Interval = 0x10;
    sConfig.AutomaticStop = QSPI_AUTOMATIC_STOP_ENABLE;

    sCommand.Instruction = READ_STATUS_REG_CMD;
    sCommand.DataMode = QSPI_DATA_1_LINE;
    if (HAL_QSPI_AutoPolling(&hqspi, &sCommand, &sConfig,
                             HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
        return HAL_ERROR;
    }

    return HAL_OK;
}


/*Enable quad mode and set dummy cycles count*/
uint8_t QSPI_Configuration(void)
{

    QSPI_CommandTypeDef sCommand;
    uint8_t reg;

    /*read configuration register*/
    sCommand.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    sCommand.Instruction = READ_VOL_CFG_REG_CMD;
    sCommand.AddressMode = QSPI_ADDRESS_NONE;
    sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
    sCommand.DataMode = QSPI_DATA_1_LINE;
    sCommand.DummyCycles = 0;
    sCommand.DdrMode = QSPI_DDR_MODE_DISABLE;
    sCommand.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
    sCommand.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;
    sCommand.NbData = 1;

    if (HAL_QSPI_Command(&hqspi, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE)
        != HAL_OK) {
        return HAL_ERROR;
    }


    if (HAL_QSPI_Receive(&hqspi, &reg,
                         HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
        return HAL_ERROR;
    }



    if (QSPI_WriteEnable() != HAL_OK) {

        return HAL_ERROR;
    }


    /*set dummy cycles*/
    MODIFY_REG(reg, 0xF0, (N25Q128A_DUMMY_CYCLES_READ_QUAD << POSITION_VAL(0xF0)));

    sCommand.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
    sCommand.DdrMode = QSPI_DDR_MODE_DISABLE;
    sCommand.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
    sCommand.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;
    sCommand.Instruction = WRITE_VOL_CFG_REG_CMD;
    sCommand.AddressMode = QSPI_ADDRESS_NONE;
    sCommand.DataMode = QSPI_DATA_1_LINE;
    sCommand.DummyCycles = 0;
    sCommand.NbData = 1;

    if (HAL_QSPI_Command(&hqspi, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE)
        != HAL_OK) {
        return HAL_ERROR;
    }

    if (HAL_QSPI_Transmit(&hqspi, &reg,
                          HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK) {
        Error_Handler();
        return HAL_ERROR;
    }
    return HAL_OK;
}

uint8_t CSP_QSPI_EraseSector(uint32_t EraseStartAddress, uint32_t EraseEndAddress)
{

    QSPI_CommandTypeDef sCommand;

    EraseStartAddress = EraseStartAddress
                        - EraseStartAddress % N25Q128A_SECTOR_SIZE;

    /* Erasing Sequence -------------------------------------------------- */
    sCommand.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    sCommand.AddressSize = QSPI_ADDRESS_24_BITS;
    sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
    sCommand.DdrMode = QSPI_DDR_MODE_DISABLE;
    sCommand.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
    sCommand.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;
    sCommand.Instruction = SECTOR_ERASE_CMD;
    sCommand.AddressMode = QSPI_ADDRESS_1_LINE;

    sCommand.DataMode = QSPI_DATA_NONE;
    sCommand.DummyCycles = 0;

    while (EraseEndAddress >= EraseStartAddress)
    {
        sCommand.Address = (EraseStartAddress & 0x0FFFFFFF);

        if (QSPI_WriteEnable() != HAL_OK) {
            return HAL_ERROR;
        }

        if (HAL_QSPI_Command(&hqspi, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE)
            != HAL_OK) {
            return HAL_ERROR;
        }
        EraseStartAddress += N25Q128A_SECTOR_SIZE;

        if (QSPI_AutoPollingMemReady() != HAL_OK) {
            return HAL_ERROR;
        }
    }

    return HAL_OK;
}


uint8_t CSP_QSPI_EnableMemoryMappedMode(void)
{

    QSPI_CommandTypeDef sCommand;
    QSPI_MemoryMappedTypeDef sMemMappedCfg;

    /* Enable Memory-Mapped mode-------------------------------------------------- */

    sCommand.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    sCommand.AddressSize = QSPI_ADDRESS_24_BITS;
    sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
    sCommand.DdrMode = QSPI_DDR_MODE_DISABLE;
    sCommand.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
    sCommand.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;
    sCommand.AddressMode = QSPI_ADDRESS_4_LINES;
    sCommand.DataMode = QSPI_DATA_4_LINES;
    sCommand.NbData = 0;
    sCommand.Address = 0;
    sCommand.Instruction = QUAD_INOUT_FAST_READ_CMD;
    sCommand.DummyCycles = N25Q128A_DUMMY_CYCLES_READ_QUAD;

    sMemMappedCfg.TimeOutActivation = QSPI_TIMEOUT_COUNTER_DISABLE;

    if (HAL_QSPI_MemoryMapped(&hqspi, &sCommand, &sMemMappedCfg) != HAL_OK) {
        return HAL_ERROR;
    }
    return HAL_OK;
}

uint8_t QSPI_ResetChip()
{
    QSPI_CommandTypeDef sCommand;
    uint32_t temp = 0;
    /* Erasing Sequence -------------------------------------------------- */
    sCommand.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    sCommand.AddressSize = QSPI_ADDRESS_24_BITS;
    sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
    sCommand.DdrMode = QSPI_DDR_MODE_DISABLE;
    sCommand.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
    sCommand.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;
    sCommand.Instruction = RESET_ENABLE_CMD;
    sCommand.AddressMode = QSPI_ADDRESS_NONE;
    sCommand.Address = 0;
    sCommand.DataMode = QSPI_DATA_NONE;
    sCommand.DummyCycles = 0;

    if (HAL_QSPI_Command(&hqspi, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE)
        != HAL_OK) {
        return HAL_ERROR;
    }
    for (temp = 0; temp < 0x2f; temp++) {
        __NOP();
    }

    sCommand.InstructionMode = QSPI_INSTRUCTION_1_LINE;
    sCommand.AddressSize = QSPI_ADDRESS_24_BITS;
    sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
    sCommand.DdrMode = QSPI_DDR_MODE_DISABLE;
    sCommand.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
    sCommand.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;
    sCommand.Instruction = RESET_MEMORY_CMD;
    sCommand.AddressMode = QSPI_ADDRESS_NONE;
    sCommand.Address = 0;
    sCommand.DataMode = QSPI_DATA_NONE;
    sCommand.DummyCycles = 0;

    if (HAL_QSPI_Command(&hqspi, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE)
        != HAL_OK) {
        return HAL_ERROR;
    }
    return HAL_OK;
}


uint8_t CSP_QSPI_Erase_Block(uint32_t BlockAddress)
{
  QSPI_CommandTypeDef s_command;

  /* Initialize the erase command */
  s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
  s_command.Instruction       = SUBSECTOR_ERASE_CMD;
  s_command.AddressMode       = QSPI_ADDRESS_1_LINE;
  s_command.AddressSize       = QSPI_ADDRESS_24_BITS;
  s_command.Address           = BlockAddress;
  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode          = QSPI_DATA_NONE;
  s_command.DummyCycles       = 0;
  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  /* Enable write operations */
  if (QSPI_WriteEnable() != HAL_OK)
  {
    return HAL_ERROR;
  }

  /* Send the command */
  if (HAL_QSPI_Command(&hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return HAL_ERROR;
  }

  /* Configure automatic polling mode to wait for end of erase */
  if (QSPI_AutoPollingMemReady() != HAL_OK)
  {
    return HAL_ERROR;
  }

  return HAL_OK;
}


uint8_t CSP_QSPI_Write(uint8_t* pData, uint32_t WriteAddr, uint32_t Size)
{
  QSPI_CommandTypeDef s_command;
  uint32_t end_addr, current_size, current_addr;

  /* Calculation of the size between the write address and the end of the page */
  current_size = N25Q128A_PAGE_SIZE - (WriteAddr % N25Q128A_PAGE_SIZE);

  /* Check if the size of the data is less than the remaining place in the page */
  if (current_size > Size)
  {
    current_size = Size;
  }

  /* Initialize the adress variables */
  current_addr = WriteAddr;
  end_addr = WriteAddr + Size;

  /* Initialize the program command */
  s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
  s_command.Instruction       = EXT_QUAD_IN_FAST_PROG_CMD;
  s_command.AddressMode       = QSPI_ADDRESS_4_LINES;
  s_command.AddressSize       = QSPI_ADDRESS_24_BITS;
  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode          = QSPI_DATA_4_LINES;
  s_command.DummyCycles       = 0;
  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  /* Perform the write page by page */
  do
  {
    s_command.Address = current_addr;
    s_command.NbData  = current_size;

    /* Enable write operations */
    if (QSPI_WriteEnable() != HAL_OK)
    {
      return HAL_ERROR;
    }

    /* Configure the command */
    if (HAL_QSPI_Command(&hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
      return HAL_ERROR;
    }

    /* Transmission of the data */
    if (HAL_QSPI_Transmit(&hqspi, pData, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
      return HAL_ERROR;
    }

    /* Configure automatic polling mode to wait for end of program */
    if (QSPI_AutoPollingMemReady() != HAL_OK)
    {
      return HAL_ERROR;
    }

    /* Update the address and size variables for next page programming */
    current_addr += current_size;
    pData += current_size;
    current_size = ((current_addr + N25Q128A_PAGE_SIZE) > end_addr) ? (end_addr - current_addr) : N25Q128A_PAGE_SIZE;
  } while (current_addr < end_addr);

  return HAL_OK;
}


uint8_t CSP_QSPI_Read(uint8_t* pData, uint32_t ReadAddr, uint32_t Size)
{
  QSPI_CommandTypeDef s_command;

  /* Initialize the read command */
  s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
  s_command.Instruction       = QUAD_INOUT_FAST_READ_CMD;
  s_command.AddressMode       = QSPI_ADDRESS_4_LINES;
  s_command.AddressSize       = QSPI_ADDRESS_24_BITS;
  s_command.Address           = ReadAddr;
  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  s_command.DataMode          = QSPI_DATA_4_LINES;
  s_command.DummyCycles       = N25Q128A_DUMMY_CYCLES_READ_QUAD;
  s_command.NbData            = Size;
  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  /* Configure the command */
  if (HAL_QSPI_Command(&hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return HAL_ERROR;
  }

  /* Set S# timing for Read command */
  MODIFY_REG(hqspi.Instance->DCR, QUADSPI_DCR_CSHT, QSPI_CS_HIGH_TIME_3_CYCLE);

  /* Reception of the data */
  if (HAL_QSPI_Receive(&hqspi, pData, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return HAL_ERROR;
  }

  /* Restore S# timing for nonRead commands */
  MODIFY_REG(hqspi.Instance->DCR, QUADSPI_DCR_CSHT, QSPI_CS_HIGH_TIME_6_CYCLE);

  return HAL_OK;
}


































//
///**
//  * @brief  Initializes the QSPI direct access interface at 0x90000000.
//  * @retval QSPI memory status
//  */
//void MDM_QSPI_DirectAccess_Init(void)
//{
//	HAL_NVIC_DisableIRQ(QUADSPI_IRQn);
//
//	MPU_Region_InitTypeDef MPU_InitStruct;
//	MPU_InitStruct.Enable = MPU_REGION_ENABLE;
//	MPU_InitStruct.BaseAddress = 0x90000000;
//	MPU_InitStruct.Size = MPU_REGION_SIZE_256MB;
//	MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
//	MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
//	MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
//	MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
//	MPU_InitStruct.Number = MPU_REGION_NUMBER2;
//	MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
//	MPU_InitStruct.SubRegionDisable = 0x00;
//	MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
//
//	HAL_MPU_ConfigRegion(&MPU_InitStruct);
//
//	//Configure the MPU attributes as WT for QSPI (used 16Mbytes)
//	MPU_InitStruct.Enable = MPU_REGION_ENABLE;
//	MPU_InitStruct.BaseAddress = 0x90000000;
//	MPU_InitStruct.Size = MPU_REGION_SIZE_16MB;
//	MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
//	MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
//	MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
//	MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
//	MPU_InitStruct.Number = MPU_REGION_NUMBER3;
//	MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
//	MPU_InitStruct.SubRegionDisable = 0x00;
//	MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
//
//	HAL_MPU_ConfigRegion(&MPU_InitStruct);
//	HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
//}
//
//
///**
//  * @brief  Initializes the QSPI interface.
//  * @retval QSPI memory status
//  */
//uint8_t MDM_QSPI_Init(void)
//{
//	hqspi.Instance = QUADSPI;
//
//  /* Call the DeInit function to reset the driver */
//  if (HAL_QSPI_DeInit(&hqspi) != HAL_OK)
//  {
//    return HAL_ERROR;
//  }
//
//  /* System level initialization */
//  //BSP_QSPI_MspInit(&hqspi, NULL);
//
//  /* NVIC configuration for QSPI interrupt */
//    HAL_NVIC_SetPriority(QUADSPI_IRQn, 10, 0);
//    HAL_NVIC_EnableIRQ(QUADSPI_IRQn);
//
//  /* QSPI initialization */
//  hqspi.Init.ClockPrescaler     = 1; /* QSPI freq = 216 MHz/(1+1) = 108 Mhz */
//  hqspi.Init.FifoThreshold      = 4;
//  hqspi.Init.SampleShifting     = QSPI_SAMPLE_SHIFTING_HALFCYCLE;
//  hqspi.Init.FlashSize          = POSITION_VAL(N25Q128A_FLASH_SIZE) - 1;
//  hqspi.Init.ChipSelectHighTime = QSPI_CS_HIGH_TIME_6_CYCLE; /* Min 50ns for nonRead */
//  hqspi.Init.ClockMode          = QSPI_CLOCK_MODE_0;
//  hqspi.Init.FlashID            = QSPI_FLASH_ID_1;
//  hqspi.Init.DualFlash          = QSPI_DUALFLASH_DISABLE;
//
//  if (HAL_QSPI_Init(&hqspi) != HAL_OK)
//  {
//    return HAL_ERROR;
//  }
//
//  // QSPI memory reset
//  if (MDM_QSPI_ResetMemory(&hqspi) != HAL_OK)
//  {
//    return HAL_ERROR;
//  }
//
//
//  // Configuration of the dummy cycles on QSPI memory side
//  if (MDM_QSPI_DummyCyclesCfg(&hqspi) != HAL_OK)
//  {
//    return HAL_ERROR;
//  }
//
//
//  return HAL_OK;
//}
//
//
///**
//  * @brief  This function reset the QSPI memory.
//  * @param  hqspi: QSPI handle
//  * @retval None
//  */
//static uint8_t MDM_QSPI_ResetMemory(QSPI_HandleTypeDef *hqspi)
//{
//  QSPI_CommandTypeDef s_command;
//
//  /* Initialize the reset enable command */
//  s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
//  s_command.Instruction       = RESET_ENABLE_CMD;
//  s_command.AddressMode       = QSPI_ADDRESS_NONE;
//  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
//  s_command.DataMode          = QSPI_DATA_NONE;
//  s_command.DummyCycles       = 0;
//  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
//  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
//  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;
//
//  /* Send the command */
//  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//  {
//    return HAL_ERROR;
//  }
//
//  /* Send the reset memory command */
//  s_command.Instruction = RESET_MEMORY_CMD;
//  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//  {
//    return HAL_ERROR;
//  }
//
//  /* Configure automatic polling mode to wait the memory is ready */
//  if (MDM_QSPI_AutoPollingMemReady(hqspi, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//  {
//    return HAL_ERROR;
//  }
//
//  return HAL_OK;
//}
//
//
//
///**
//  * @brief  This function configure the dummy cycles on memory side.
//  * @param  hqspi: QSPI handle
//  * @retval None
//  */
//static uint8_t MDM_QSPI_DummyCyclesCfg(QSPI_HandleTypeDef *hqspi)
//{
//  QSPI_CommandTypeDef s_command;
//  uint8_t reg;
//
//  /* Initialize the read volatile configuration register command */
//  s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
//  s_command.Instruction       = READ_VOL_CFG_REG_CMD;
//  s_command.AddressMode       = QSPI_ADDRESS_NONE;
//  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
//  s_command.DataMode          = QSPI_DATA_1_LINE;
//  s_command.DummyCycles       = 0;
//  s_command.NbData            = 1;
//  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
//  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
//  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;
//
//  /* Configure the command */
//  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//  {
//    return HAL_ERROR;
//  }
//
//  /* Reception of the data */
//  if (HAL_QSPI_Receive(hqspi, &reg, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//  {
//    return HAL_ERROR;
//  }
//
//  /* Enable write operations */
//  if (MDM_QSPI_WriteEnable(hqspi) != HAL_OK)
//  {
//    return HAL_ERROR;
//  }
//
//  /* Update volatile configuration register (with new dummy cycles) */
//  s_command.Instruction = WRITE_VOL_CFG_REG_CMD;
//  MODIFY_REG(reg, N25Q128A_VCR_NB_DUMMY, (N25Q128A_DUMMY_CYCLES_READ_QUAD << POSITION_VAL(N25Q128A_VCR_NB_DUMMY)));
//
//  /* Configure the write volatile configuration register command */
//  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//  {
//    return HAL_ERROR;
//  }
//
//  /* Transmission of the data */
//  if (HAL_QSPI_Transmit(hqspi, &reg, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//  {
//    return HAL_ERROR;
//  }
//
//  return HAL_OK;
//}
//
//
///**
//  * @brief  This function send a Write Enable and wait it is effective.
//  * @param  hqspi: QSPI handle
//  * @retval None
//  */
//static uint8_t MDM_QSPI_WriteEnable(QSPI_HandleTypeDef *hqspi)
//{
//  QSPI_CommandTypeDef     s_command;
//  QSPI_AutoPollingTypeDef s_config;
//
//  /* Enable write operations */
//  s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
//  s_command.Instruction       = WRITE_ENABLE_CMD;
//  s_command.AddressMode       = QSPI_ADDRESS_NONE;
//  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
//  s_command.DataMode          = QSPI_DATA_NONE;
//  s_command.DummyCycles       = 0;
//  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
//  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
//  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;
//
//  if (HAL_QSPI_Command(hqspi, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//  {
//    return HAL_ERROR;
//  }
//
//  /* Configure automatic polling mode to wait for write enabling */
//  s_config.Match           = N25Q128A_SR_WREN;
//  s_config.Mask            = N25Q128A_SR_WREN;
//  s_config.MatchMode       = QSPI_MATCH_MODE_AND;
//  s_config.StatusBytesSize = 1;
//  s_config.Interval        = 0x10;
//  s_config.AutomaticStop   = QSPI_AUTOMATIC_STOP_ENABLE;
//
//  s_command.Instruction    = READ_STATUS_REG_CMD;
//  s_command.DataMode       = QSPI_DATA_1_LINE;
//
//  if (HAL_QSPI_AutoPolling(hqspi, &s_command, &s_config, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
//  {
//    return HAL_ERROR;
//  }
//
//  return HAL_OK;
//}
//
//
///**
//  * @brief  Configure the QSPI in memory-mapped mode
//  * @retval QSPI memory status
//  */
//uint8_t MDM_QSPI_EnableMemoryMappedMode(void)
//{
//  QSPI_CommandTypeDef      s_command;
//  QSPI_MemoryMappedTypeDef s_mem_mapped_cfg;
//
//  /* Configure the command for the read instruction */
//  s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
//  s_command.Instruction       = QUAD_INOUT_FAST_READ_CMD;
//  s_command.AddressMode       = QSPI_ADDRESS_4_LINES;
//  s_command.AddressSize       = QSPI_ADDRESS_24_BITS;
//  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
//  s_command.DataMode          = QSPI_DATA_4_LINES;
//  s_command.DummyCycles       = N25Q128A_DUMMY_CYCLES_READ_QUAD;
//  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
//  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
//  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;
//
//  /* Configure the memory mapped mode */
//  s_mem_mapped_cfg.TimeOutActivation = QSPI_TIMEOUT_COUNTER_DISABLE;
//  s_mem_mapped_cfg.TimeOutPeriod     = 0;
//
//  if (HAL_QSPI_MemoryMapped(&hqspi, &s_command, &s_mem_mapped_cfg) != HAL_OK)
//  {
//    return HAL_ERROR;
//  }
//
//  MDM_QSPI_WriteEnable(&hqspi);
//
//  return HAL_OK;
//}
//
//
//
///**
//  * @brief  This function read the SR of the memory and wait the EOP.
//  * @param  hqspi: QSPI handle
//  * @param  Timeout
//  * @retval None
//  */
//static uint8_t MDM_QSPI_AutoPollingMemReady(QSPI_HandleTypeDef *hqspi, uint32_t Timeout)
//{
//  QSPI_CommandTypeDef     s_command;
//  QSPI_AutoPollingTypeDef s_config;
//
//  /* Configure automatic polling mode to wait for memory ready */
//  s_command.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
//  s_command.Instruction       = READ_STATUS_REG_CMD;
//  s_command.AddressMode       = QSPI_ADDRESS_NONE;
//  s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
//  s_command.DataMode          = QSPI_DATA_1_LINE;
//  s_command.DummyCycles       = 0;
//  s_command.DdrMode           = QSPI_DDR_MODE_DISABLE;
//  s_command.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
//  s_command.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;
//
//  s_config.Match           = 0;
//  s_config.Mask            = N25Q128A_SR_WIP;
//  s_config.MatchMode       = QSPI_MATCH_MODE_AND;
//  s_config.StatusBytesSize = 1;
//  s_config.Interval        = 0x10;
//  s_config.AutomaticStop   = QSPI_AUTOMATIC_STOP_ENABLE;
//
//  if (HAL_QSPI_AutoPolling(hqspi, &s_command, &s_config, Timeout) != HAL_OK)
//  {
//    return HAL_ERROR;
//  }
//
//  return HAL_OK;
//}



/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
