################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Code/Src/ButtonHandler.c \
../Code/Src/CanFunctions.c \
../Code/Src/SDcardHandler.c \
../Code/Src/SimulationMode.c \
../Code/Src/TimerHandler.c \
../Code/Src/Timers.c 

C_DEPS += \
./Code/Src/ButtonHandler.d \
./Code/Src/CanFunctions.d \
./Code/Src/SDcardHandler.d \
./Code/Src/SimulationMode.d \
./Code/Src/TimerHandler.d \
./Code/Src/Timers.d 

OBJS += \
./Code/Src/ButtonHandler.o \
./Code/Src/CanFunctions.o \
./Code/Src/SDcardHandler.o \
./Code/Src/SimulationMode.o \
./Code/Src/TimerHandler.o \
./Code/Src/Timers.o 


# Each subdirectory must supply rules for building sources it contributes
Code/Src/%.o: ../Code/Src/%.c Code/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../TouchGFX/generated/videos/include -I../LIBJPEG/App -I../LIBJPEG/Target -I../Middlewares/Third_Party/LibJPEG/include -I"C:/Users/IlMio/STM32CubeIDE/workspace_1.2.0/MMR_Hybrid_Display_v2.1/Code/Inc" -I"C:/Users/IlMio/STM32CubeIDE/workspace_1.2.0/MMR_Hybrid_Display_v2.1/Code/Src" -I"C:/Users/IlMio/STM32CubeIDE/workspace_1.2.0/MMR_Hybrid_Display_v2.1/Components/n25q128a" -I"C:/Users/IlMio/STM32CubeIDE/workspace_1.2.0/MMR_Hybrid_Display_v2.1/ExtFlash/Inc" -I"C:/Users/IlMio/STM32CubeIDE/workspace_1.2.0/MMR_Hybrid_Display_v2.1/ExtFlash/Src" -I"C:/Users/IlMio/STM32CubeIDE/workspace_1.2.0/MMR_Hybrid_Display_v2.1/Components/Common" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Code-2f-Src

clean-Code-2f-Src:
	-$(RM) ./Code/Src/ButtonHandler.d ./Code/Src/ButtonHandler.o ./Code/Src/CanFunctions.d ./Code/Src/CanFunctions.o ./Code/Src/SDcardHandler.d ./Code/Src/SDcardHandler.o ./Code/Src/SimulationMode.d ./Code/Src/SimulationMode.o ./Code/Src/TimerHandler.d ./Code/Src/TimerHandler.o ./Code/Src/Timers.d ./Code/Src/Timers.o

.PHONY: clean-Code-2f-Src

