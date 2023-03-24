################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CAR_DATA/Src/CAR_DATA.c 

OBJS += \
./CAR_DATA/Src/CAR_DATA.o 

C_DEPS += \
./CAR_DATA/Src/CAR_DATA.d 


# Each subdirectory must supply rules for building sources it contributes
CAR_DATA/Src/%.o CAR_DATA/Src/%.su: ../CAR_DATA/Src/%.c CAR_DATA/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I/Display_Software/Drivers/Components/Inc -I"M:/SAE/Projects/GitHub_Data/Display/STemWin/inc" -I"M:/SAE/Projects/GitHub_Data/Display/MDM_Functions/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/MDM_GUI_LIB/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/DISPLAY_GUI/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/CAR_DATA/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CAR_DATA-2f-Src

clean-CAR_DATA-2f-Src:
	-$(RM) ./CAR_DATA/Src/CAR_DATA.d ./CAR_DATA/Src/CAR_DATA.o ./CAR_DATA/Src/CAR_DATA.su

.PHONY: clean-CAR_DATA-2f-Src

