################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STemWin/src/GUIConf.c \
../STemWin/src/GUI_X.c \
../STemWin/src/LCDConf.c \
../STemWin/src/buttons.c 

OBJS += \
./STemWin/src/GUIConf.o \
./STemWin/src/GUI_X.o \
./STemWin/src/LCDConf.o \
./STemWin/src/buttons.o 

C_DEPS += \
./STemWin/src/GUIConf.d \
./STemWin/src/GUI_X.d \
./STemWin/src/LCDConf.d \
./STemWin/src/buttons.d 


# Each subdirectory must supply rules for building sources it contributes
STemWin/src/%.o STemWin/src/%.su: ../STemWin/src/%.c STemWin/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I/Display_Software/Drivers/Components/Inc -I"M:/SAE/Projects/GitHub_Data/Display/STemWin/inc" -I"M:/SAE/Projects/GitHub_Data/Display/MDM_Functions/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/MDM_GUI_LIB/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/DISPLAY_GUI/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/CAR_DATA/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-STemWin-2f-src

clean-STemWin-2f-src:
	-$(RM) ./STemWin/src/GUIConf.d ./STemWin/src/GUIConf.o ./STemWin/src/GUIConf.su ./STemWin/src/GUI_X.d ./STemWin/src/GUI_X.o ./STemWin/src/GUI_X.su ./STemWin/src/LCDConf.d ./STemWin/src/LCDConf.o ./STemWin/src/LCDConf.su ./STemWin/src/buttons.d ./STemWin/src/buttons.o ./STemWin/src/buttons.su

.PHONY: clean-STemWin-2f-src

