################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/gui/src/race_screen/RACEPresenter.cpp \
../TouchGFX/gui/src/race_screen/RACEView.cpp 

OBJS += \
./TouchGFX/gui/src/race_screen/RACEPresenter.o \
./TouchGFX/gui/src/race_screen/RACEView.o 

CPP_DEPS += \
./TouchGFX/gui/src/race_screen/RACEPresenter.d \
./TouchGFX/gui/src/race_screen/RACEView.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/gui/src/race_screen/%.o TouchGFX/gui/src/race_screen/%.su TouchGFX/gui/src/race_screen/%.cyclo: ../TouchGFX/gui/src/race_screen/%.cpp TouchGFX/gui/src/race_screen/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../TouchGFX/generated/videos/include -I../LIBJPEG/App -I../LIBJPEG/Target -I../Middlewares/Third_Party/LibJPEG/include -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/Code/Inc" -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/Code/Src" -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/ExtFlash/Inc" -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/ExtFlash/Src" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-gui-2f-src-2f-race_screen

clean-TouchGFX-2f-gui-2f-src-2f-race_screen:
	-$(RM) ./TouchGFX/gui/src/race_screen/RACEPresenter.cyclo ./TouchGFX/gui/src/race_screen/RACEPresenter.d ./TouchGFX/gui/src/race_screen/RACEPresenter.o ./TouchGFX/gui/src/race_screen/RACEPresenter.su ./TouchGFX/gui/src/race_screen/RACEView.cyclo ./TouchGFX/gui/src/race_screen/RACEView.d ./TouchGFX/gui/src/race_screen/RACEView.o ./TouchGFX/gui/src/race_screen/RACEView.su

.PHONY: clean-TouchGFX-2f-gui-2f-src-2f-race_screen

