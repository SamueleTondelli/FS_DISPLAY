################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/adc.c \
../Core/Src/can.c \
../Core/Src/crc.c \
../Core/Src/dac.c \
../Core/Src/dma2d.c \
../Core/Src/fmc.c \
../Core/Src/gpio.c \
../Core/Src/iwdg.c \
../Core/Src/ltdc.c \
../Core/Src/main.c \
../Core/Src/mcu_vrefInt.c \
../Core/Src/mpu_temperature.c \
../Core/Src/quadspi.c \
../Core/Src/sdmmc.c \
../Core/Src/stm32f7xx_hal_msp.c \
../Core/Src/stm32f7xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f7xx.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/adc.o \
./Core/Src/can.o \
./Core/Src/crc.o \
./Core/Src/dac.o \
./Core/Src/dma2d.o \
./Core/Src/fmc.o \
./Core/Src/gpio.o \
./Core/Src/iwdg.o \
./Core/Src/ltdc.o \
./Core/Src/main.o \
./Core/Src/mcu_vrefInt.o \
./Core/Src/mpu_temperature.o \
./Core/Src/quadspi.o \
./Core/Src/sdmmc.o \
./Core/Src/stm32f7xx_hal_msp.o \
./Core/Src/stm32f7xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f7xx.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/adc.d \
./Core/Src/can.d \
./Core/Src/crc.d \
./Core/Src/dac.d \
./Core/Src/dma2d.d \
./Core/Src/fmc.d \
./Core/Src/gpio.d \
./Core/Src/iwdg.d \
./Core/Src/ltdc.d \
./Core/Src/main.d \
./Core/Src/mcu_vrefInt.d \
./Core/Src/mpu_temperature.d \
./Core/Src/quadspi.d \
./Core/Src/sdmmc.d \
./Core/Src/stm32f7xx_hal_msp.d \
./Core/Src/stm32f7xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f7xx.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/adc.d ./Core/Src/adc.o ./Core/Src/adc.su ./Core/Src/can.d ./Core/Src/can.o ./Core/Src/can.su ./Core/Src/crc.d ./Core/Src/crc.o ./Core/Src/crc.su ./Core/Src/dac.d ./Core/Src/dac.o ./Core/Src/dac.su ./Core/Src/dma2d.d ./Core/Src/dma2d.o ./Core/Src/dma2d.su ./Core/Src/fmc.d ./Core/Src/fmc.o ./Core/Src/fmc.su ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/iwdg.d ./Core/Src/iwdg.o ./Core/Src/iwdg.su ./Core/Src/ltdc.d ./Core/Src/ltdc.o ./Core/Src/ltdc.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/mcu_vrefInt.d ./Core/Src/mcu_vrefInt.o ./Core/Src/mcu_vrefInt.su ./Core/Src/mpu_temperature.d ./Core/Src/mpu_temperature.o ./Core/Src/mpu_temperature.su ./Core/Src/quadspi.d ./Core/Src/quadspi.o ./Core/Src/quadspi.su ./Core/Src/sdmmc.d ./Core/Src/sdmmc.o ./Core/Src/sdmmc.su ./Core/Src/stm32f7xx_hal_msp.d ./Core/Src/stm32f7xx_hal_msp.o ./Core/Src/stm32f7xx_hal_msp.su ./Core/Src/stm32f7xx_it.d ./Core/Src/stm32f7xx_it.o ./Core/Src/stm32f7xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f7xx.d ./Core/Src/system_stm32f7xx.o ./Core/Src/system_stm32f7xx.su ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su

.PHONY: clean-Core-2f-Src

