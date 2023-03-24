################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MDM_Functions/Src/MDM_Functions.c 

OBJS += \
./MDM_Functions/Src/MDM_Functions.o 

C_DEPS += \
./MDM_Functions/Src/MDM_Functions.d 


# Each subdirectory must supply rules for building sources it contributes
MDM_Functions/Src/%.o MDM_Functions/Src/%.su: ../MDM_Functions/Src/%.c MDM_Functions/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I/Display_Software/Drivers/Components/Inc -I"M:/SAE/Projects/GitHub_Data/Display/STemWin/inc" -I"M:/SAE/Projects/GitHub_Data/Display/MDM_Functions/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/MDM_GUI_LIB/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/DISPLAY_GUI/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/CAR_DATA/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MDM_Functions-2f-Src

clean-MDM_Functions-2f-Src:
	-$(RM) ./MDM_Functions/Src/MDM_Functions.d ./MDM_Functions/Src/MDM_Functions.o ./MDM_Functions/Src/MDM_Functions.su

.PHONY: clean-MDM_Functions-2f-Src

