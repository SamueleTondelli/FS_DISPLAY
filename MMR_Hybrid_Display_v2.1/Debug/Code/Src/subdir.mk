################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Code/src/alarms.cpp \
../Code/src/c_interface.cpp \
../Code/src/dash_utils.cpp \
../Code/src/data.cpp \
../Code/src/main_application.cpp \
../Code/src/popup_handler.cpp \
../Code/src/ps_code.cpp 

OBJS += \
./Code/src/alarms.o \
./Code/src/c_interface.o \
./Code/src/dash_utils.o \
./Code/src/data.o \
./Code/src/main_application.o \
./Code/src/popup_handler.o \
./Code/src/ps_code.o 

CPP_DEPS += \
./Code/src/alarms.d \
./Code/src/c_interface.d \
./Code/src/dash_utils.d \
./Code/src/data.d \
./Code/src/main_application.d \
./Code/src/popup_handler.d \
./Code/src/ps_code.d 


# Each subdirectory must supply rules for building sources it contributes
Code/src/%.o Code/src/%.su Code/src/%.cyclo: ../Code/src/%.cpp Code/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../TouchGFX/generated/videos/include -I../LIBJPEG/App -I../LIBJPEG/Target -I../Middlewares/Third_Party/LibJPEG/include -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/ExtFlash/Inc" -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/ExtFlash/Src" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Code-2f-src

clean-Code-2f-src:
	-$(RM) ./Code/src/alarms.cyclo ./Code/src/alarms.d ./Code/src/alarms.o ./Code/src/alarms.su ./Code/src/c_interface.cyclo ./Code/src/c_interface.d ./Code/src/c_interface.o ./Code/src/c_interface.su ./Code/src/dash_utils.cyclo ./Code/src/dash_utils.d ./Code/src/dash_utils.o ./Code/src/dash_utils.su ./Code/src/data.cyclo ./Code/src/data.d ./Code/src/data.o ./Code/src/data.su ./Code/src/main_application.cyclo ./Code/src/main_application.d ./Code/src/main_application.o ./Code/src/main_application.su ./Code/src/popup_handler.cyclo ./Code/src/popup_handler.d ./Code/src/popup_handler.o ./Code/src/popup_handler.su ./Code/src/ps_code.cyclo ./Code/src/ps_code.d ./Code/src/ps_code.o ./Code/src/ps_code.su

.PHONY: clean-Code-2f-src

