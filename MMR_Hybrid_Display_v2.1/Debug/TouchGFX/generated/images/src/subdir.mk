################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../TouchGFX/generated/images/src/BitmapDatabase.cpp \
../TouchGFX/generated/images/src/SVGDatabase.cpp \
../TouchGFX/generated/images/src/image_Rectangle_10.cpp \
../TouchGFX/generated/images/src/image_Rectangle_19.cpp \
../TouchGFX/generated/images/src/image_Rectangle_2.cpp \
../TouchGFX/generated/images/src/image_Rectangle_20.cpp \
../TouchGFX/generated/images/src/image_Rectangle_22.cpp \
../TouchGFX/generated/images/src/image_Rectangle_23.cpp \
../TouchGFX/generated/images/src/image_Rectangle_3.cpp \
../TouchGFX/generated/images/src/image_m22h.cpp \
../TouchGFX/generated/images/src/image_second_screen-min.cpp \
../TouchGFX/generated/images/src/image_steering_wheel.cpp 

OBJS += \
./TouchGFX/generated/images/src/BitmapDatabase.o \
./TouchGFX/generated/images/src/SVGDatabase.o \
./TouchGFX/generated/images/src/image_Rectangle_10.o \
./TouchGFX/generated/images/src/image_Rectangle_19.o \
./TouchGFX/generated/images/src/image_Rectangle_2.o \
./TouchGFX/generated/images/src/image_Rectangle_20.o \
./TouchGFX/generated/images/src/image_Rectangle_22.o \
./TouchGFX/generated/images/src/image_Rectangle_23.o \
./TouchGFX/generated/images/src/image_Rectangle_3.o \
./TouchGFX/generated/images/src/image_m22h.o \
./TouchGFX/generated/images/src/image_second_screen-min.o \
./TouchGFX/generated/images/src/image_steering_wheel.o 

CPP_DEPS += \
./TouchGFX/generated/images/src/BitmapDatabase.d \
./TouchGFX/generated/images/src/SVGDatabase.d \
./TouchGFX/generated/images/src/image_Rectangle_10.d \
./TouchGFX/generated/images/src/image_Rectangle_19.d \
./TouchGFX/generated/images/src/image_Rectangle_2.d \
./TouchGFX/generated/images/src/image_Rectangle_20.d \
./TouchGFX/generated/images/src/image_Rectangle_22.d \
./TouchGFX/generated/images/src/image_Rectangle_23.d \
./TouchGFX/generated/images/src/image_Rectangle_3.d \
./TouchGFX/generated/images/src/image_m22h.d \
./TouchGFX/generated/images/src/image_second_screen-min.d \
./TouchGFX/generated/images/src/image_steering_wheel.d 


# Each subdirectory must supply rules for building sources it contributes
TouchGFX/generated/images/src/%.o TouchGFX/generated/images/src/%.su TouchGFX/generated/images/src/%.cyclo: ../TouchGFX/generated/images/src/%.cpp TouchGFX/generated/images/src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../TouchGFX/generated/videos/include -I../LIBJPEG/App -I../LIBJPEG/Target -I../Middlewares/Third_Party/LibJPEG/include -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/ExtFlash/Inc" -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/ExtFlash/Src" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -femit-class-debug-always -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TouchGFX-2f-generated-2f-images-2f-src

clean-TouchGFX-2f-generated-2f-images-2f-src:
	-$(RM) ./TouchGFX/generated/images/src/BitmapDatabase.cyclo ./TouchGFX/generated/images/src/BitmapDatabase.d ./TouchGFX/generated/images/src/BitmapDatabase.o ./TouchGFX/generated/images/src/BitmapDatabase.su ./TouchGFX/generated/images/src/SVGDatabase.cyclo ./TouchGFX/generated/images/src/SVGDatabase.d ./TouchGFX/generated/images/src/SVGDatabase.o ./TouchGFX/generated/images/src/SVGDatabase.su ./TouchGFX/generated/images/src/image_Rectangle_10.cyclo ./TouchGFX/generated/images/src/image_Rectangle_10.d ./TouchGFX/generated/images/src/image_Rectangle_10.o ./TouchGFX/generated/images/src/image_Rectangle_10.su ./TouchGFX/generated/images/src/image_Rectangle_19.cyclo ./TouchGFX/generated/images/src/image_Rectangle_19.d ./TouchGFX/generated/images/src/image_Rectangle_19.o ./TouchGFX/generated/images/src/image_Rectangle_19.su ./TouchGFX/generated/images/src/image_Rectangle_2.cyclo ./TouchGFX/generated/images/src/image_Rectangle_2.d ./TouchGFX/generated/images/src/image_Rectangle_2.o ./TouchGFX/generated/images/src/image_Rectangle_2.su ./TouchGFX/generated/images/src/image_Rectangle_20.cyclo ./TouchGFX/generated/images/src/image_Rectangle_20.d ./TouchGFX/generated/images/src/image_Rectangle_20.o ./TouchGFX/generated/images/src/image_Rectangle_20.su ./TouchGFX/generated/images/src/image_Rectangle_22.cyclo ./TouchGFX/generated/images/src/image_Rectangle_22.d ./TouchGFX/generated/images/src/image_Rectangle_22.o ./TouchGFX/generated/images/src/image_Rectangle_22.su ./TouchGFX/generated/images/src/image_Rectangle_23.cyclo ./TouchGFX/generated/images/src/image_Rectangle_23.d ./TouchGFX/generated/images/src/image_Rectangle_23.o ./TouchGFX/generated/images/src/image_Rectangle_23.su ./TouchGFX/generated/images/src/image_Rectangle_3.cyclo ./TouchGFX/generated/images/src/image_Rectangle_3.d ./TouchGFX/generated/images/src/image_Rectangle_3.o ./TouchGFX/generated/images/src/image_Rectangle_3.su ./TouchGFX/generated/images/src/image_m22h.cyclo ./TouchGFX/generated/images/src/image_m22h.d ./TouchGFX/generated/images/src/image_m22h.o ./TouchGFX/generated/images/src/image_m22h.su ./TouchGFX/generated/images/src/image_second_screen-min.cyclo ./TouchGFX/generated/images/src/image_second_screen-min.d ./TouchGFX/generated/images/src/image_second_screen-min.o ./TouchGFX/generated/images/src/image_second_screen-min.su ./TouchGFX/generated/images/src/image_steering_wheel.cyclo ./TouchGFX/generated/images/src/image_steering_wheel.d ./TouchGFX/generated/images/src/image_steering_wheel.o ./TouchGFX/generated/images/src/image_steering_wheel.su

.PHONY: clean-TouchGFX-2f-generated-2f-images-2f-src

