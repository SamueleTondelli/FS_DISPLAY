################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/gui/src/model/Model.cpp 

OBJS += \
./TouchGFX/gui/src/model/Model.o 

CPP_DEPS += \
./TouchGFX/gui/src/model/Model.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/gui/src/model/%.o TouchGFX/gui/src/model/%.su TouchGFX/gui/src/model/%.cyclo: ../TouchGFX/gui/src/model/%.cpp TouchGFX/gui/src/model/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../TouchGFX/generated/videos/include -I../LIBJPEG/App -I../LIBJPEG/Target -I../Middlewares/Third_Party/LibJPEG/include -I"C:/Users/FS_DISPLAY/MMR_Hybrid_Display_v2.1/Code/Inc" -I"C:/Users/FS_DISPLAY/MMR_Hybrid_Display_v2.1/Code/Src" -I"C:/Users/FS_DISPLAY/MMR_Hybrid_Display_v2.1/ExtFlash/Inc" -I"C:/Users/FS_DISPLAY/MMR_Hybrid_Display_v2.1/ExtFlash/Src" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-gui-2f-src-2f-model

clean-TouchGFX-2f-gui-2f-src-2f-model:
	-$(RM) ./TouchGFX/gui/src/model/Model.cyclo ./TouchGFX/gui/src/model/Model.d ./TouchGFX/gui/src/model/Model.o ./TouchGFX/gui/src/model/Model.su

.PHONY: clean-TouchGFX-2f-gui-2f-src-2f-model

