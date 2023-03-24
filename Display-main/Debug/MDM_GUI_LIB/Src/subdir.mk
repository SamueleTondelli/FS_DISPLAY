################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MDM_GUI_LIB/Src/MDM_GUI_LIB.c 

OBJS += \
./MDM_GUI_LIB/Src/MDM_GUI_LIB.o 

C_DEPS += \
./MDM_GUI_LIB/Src/MDM_GUI_LIB.d 


# Each subdirectory must supply rules for building sources it contributes
MDM_GUI_LIB/Src/%.o MDM_GUI_LIB/Src/%.su: ../MDM_GUI_LIB/Src/%.c MDM_GUI_LIB/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I/Display_Software/Drivers/Components/Inc -I"M:/SAE/Projects/GitHub_Data/Display/STemWin/inc" -I"M:/SAE/Projects/GitHub_Data/Display/MDM_Functions/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/MDM_GUI_LIB/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/DISPLAY_GUI/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/CAR_DATA/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MDM_GUI_LIB-2f-Src

clean-MDM_GUI_LIB-2f-Src:
	-$(RM) ./MDM_GUI_LIB/Src/MDM_GUI_LIB.d ./MDM_GUI_LIB/Src/MDM_GUI_LIB.o ./MDM_GUI_LIB/Src/MDM_GUI_LIB.su

.PHONY: clean-MDM_GUI_LIB-2f-Src

