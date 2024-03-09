################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Code/Src/Button.c \
../Code/Src/ButtonHandler.c \
../Code/Src/CanFunctions.c \
../Code/Src/TimerHandler.c \
../Code/Src/Timers.c \
../Code/Src/lap_timer.c 

C_DEPS += \
./Code/Src/Button.d \
./Code/Src/ButtonHandler.d \
./Code/Src/CanFunctions.d \
./Code/Src/TimerHandler.d \
./Code/Src/Timers.d \
./Code/Src/lap_timer.d 

OBJS += \
./Code/Src/Button.o \
./Code/Src/ButtonHandler.o \
./Code/Src/CanFunctions.o \
./Code/Src/TimerHandler.o \
./Code/Src/Timers.o \
./Code/Src/lap_timer.o 


# Each subdirectory must supply rules for building sources it contributes
Code/Src/%.o Code/Src/%.su Code/Src/%.cyclo: ../Code/Src/%.c Code/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../TouchGFX/generated/videos/include -I../LIBJPEG/App -I../LIBJPEG/Target -I../Middlewares/Third_Party/LibJPEG/include -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/Code/Inc" -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/Code/Src" -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/Components/n25q128a" -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/ExtFlash/Inc" -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/ExtFlash/Src" -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/Components/Common" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Code-2f-Src

clean-Code-2f-Src:
	-$(RM) ./Code/Src/Button.cyclo ./Code/Src/Button.d ./Code/Src/Button.o ./Code/Src/Button.su ./Code/Src/ButtonHandler.cyclo ./Code/Src/ButtonHandler.d ./Code/Src/ButtonHandler.o ./Code/Src/ButtonHandler.su ./Code/Src/CanFunctions.cyclo ./Code/Src/CanFunctions.d ./Code/Src/CanFunctions.o ./Code/Src/CanFunctions.su ./Code/Src/TimerHandler.cyclo ./Code/Src/TimerHandler.d ./Code/Src/TimerHandler.o ./Code/Src/TimerHandler.su ./Code/Src/Timers.cyclo ./Code/Src/Timers.d ./Code/Src/Timers.o ./Code/Src/Timers.su ./Code/Src/lap_timer.cyclo ./Code/Src/lap_timer.d ./Code/Src/lap_timer.o ./Code/Src/lap_timer.su

.PHONY: clean-Code-2f-Src

