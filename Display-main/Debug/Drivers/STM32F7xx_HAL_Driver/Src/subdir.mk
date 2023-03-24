################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc_ex.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_can.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc_ex.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dac.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dac_ex.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma2d.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma_ex.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dsi.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_exti.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash_ex.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c_ex.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_iwdg.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc_ex.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_qspi.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sd.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sdram.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart_ex.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_fmc.c \
../Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_sdmmc.c 

OBJS += \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc_ex.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_can.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc_ex.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dac.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dac_ex.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma2d.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma_ex.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dsi.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_exti.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash_ex.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c_ex.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_iwdg.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc_ex.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_qspi.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sd.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sdram.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart_ex.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_fmc.o \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_sdmmc.o 

C_DEPS += \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc_ex.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_can.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc_ex.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dac.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dac_ex.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma2d.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma_ex.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dsi.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_exti.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash_ex.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c_ex.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_iwdg.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc_ex.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_qspi.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sd.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sdram.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart_ex.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_fmc.d \
./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_sdmmc.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/STM32F7xx_HAL_Driver/Src/%.o Drivers/STM32F7xx_HAL_Driver/Src/%.su: ../Drivers/STM32F7xx_HAL_Driver/Src/%.c Drivers/STM32F7xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I/Display_Software/Drivers/Components/Inc -I"M:/SAE/Projects/GitHub_Data/Display/STemWin/inc" -I"M:/SAE/Projects/GitHub_Data/Display/MDM_Functions/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/MDM_GUI_LIB/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/DISPLAY_GUI/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/CAR_DATA/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-STM32F7xx_HAL_Driver-2f-Src

clean-Drivers-2f-STM32F7xx_HAL_Driver-2f-Src:
	-$(RM) ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc_ex.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc_ex.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc_ex.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_can.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_can.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_can.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc_ex.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc_ex.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc_ex.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dac.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dac.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dac.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dac_ex.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dac_ex.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dac_ex.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma2d.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma2d.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma2d.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma_ex.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma_ex.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma_ex.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dsi.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dsi.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dsi.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_exti.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_exti.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_exti.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash_ex.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash_ex.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash_ex.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c_ex.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c_ex.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c_ex.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_iwdg.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_iwdg.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_iwdg.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc_ex.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc_ex.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc_ex.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_qspi.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_qspi.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_qspi.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sd.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sd.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sd.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sdram.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sdram.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sdram.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart_ex.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart_ex.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart_ex.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_fmc.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_fmc.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_fmc.su ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_sdmmc.d ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_sdmmc.o ./Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_sdmmc.su

.PHONY: clean-Drivers-2f-STM32F7xx_HAL_Driver-2f-Src

