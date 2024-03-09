################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Code/Src/Data/Data.c \
../Code/Src/Data/DataAlarms.c \
../Code/Src/Data/DataControls.c \
../Code/Src/Data/DataLapTime.c \
../Code/Src/Data/DataMechanics.c \
../Code/Src/Data/DataMessage.c \
../Code/Src/Data/DataScreen.c \
../Code/Src/Data/DataStatus.c \
../Code/Src/Data/DataThermalPressure.c \
../Code/Src/Data/DataTyres.c \
../Code/Src/Data/Dataset.c 

C_DEPS += \
./Code/Src/Data/Data.d \
./Code/Src/Data/DataAlarms.d \
./Code/Src/Data/DataControls.d \
./Code/Src/Data/DataLapTime.d \
./Code/Src/Data/DataMechanics.d \
./Code/Src/Data/DataMessage.d \
./Code/Src/Data/DataScreen.d \
./Code/Src/Data/DataStatus.d \
./Code/Src/Data/DataThermalPressure.d \
./Code/Src/Data/DataTyres.d \
./Code/Src/Data/Dataset.d 

OBJS += \
./Code/Src/Data/Data.o \
./Code/Src/Data/DataAlarms.o \
./Code/Src/Data/DataControls.o \
./Code/Src/Data/DataLapTime.o \
./Code/Src/Data/DataMechanics.o \
./Code/Src/Data/DataMessage.o \
./Code/Src/Data/DataScreen.o \
./Code/Src/Data/DataStatus.o \
./Code/Src/Data/DataThermalPressure.o \
./Code/Src/Data/DataTyres.o \
./Code/Src/Data/Dataset.o 


# Each subdirectory must supply rules for building sources it contributes
Code/Src/Data/%.o Code/Src/Data/%.su Code/Src/Data/%.cyclo: ../Code/Src/Data/%.c Code/Src/Data/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../TouchGFX/generated/videos/include -I../LIBJPEG/App -I../LIBJPEG/Target -I../Middlewares/Third_Party/LibJPEG/include -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/Code/Inc" -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/Code/Src" -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/Components/n25q128a" -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/ExtFlash/Inc" -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/ExtFlash/Src" -I"E:/Documenti/stmworkspace/FS_DISPLAY/MMR_Hybrid_Display_v2.1/Components/Common" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Code-2f-Src-2f-Data

clean-Code-2f-Src-2f-Data:
	-$(RM) ./Code/Src/Data/Data.cyclo ./Code/Src/Data/Data.d ./Code/Src/Data/Data.o ./Code/Src/Data/Data.su ./Code/Src/Data/DataAlarms.cyclo ./Code/Src/Data/DataAlarms.d ./Code/Src/Data/DataAlarms.o ./Code/Src/Data/DataAlarms.su ./Code/Src/Data/DataControls.cyclo ./Code/Src/Data/DataControls.d ./Code/Src/Data/DataControls.o ./Code/Src/Data/DataControls.su ./Code/Src/Data/DataLapTime.cyclo ./Code/Src/Data/DataLapTime.d ./Code/Src/Data/DataLapTime.o ./Code/Src/Data/DataLapTime.su ./Code/Src/Data/DataMechanics.cyclo ./Code/Src/Data/DataMechanics.d ./Code/Src/Data/DataMechanics.o ./Code/Src/Data/DataMechanics.su ./Code/Src/Data/DataMessage.cyclo ./Code/Src/Data/DataMessage.d ./Code/Src/Data/DataMessage.o ./Code/Src/Data/DataMessage.su ./Code/Src/Data/DataScreen.cyclo ./Code/Src/Data/DataScreen.d ./Code/Src/Data/DataScreen.o ./Code/Src/Data/DataScreen.su ./Code/Src/Data/DataStatus.cyclo ./Code/Src/Data/DataStatus.d ./Code/Src/Data/DataStatus.o ./Code/Src/Data/DataStatus.su ./Code/Src/Data/DataThermalPressure.cyclo ./Code/Src/Data/DataThermalPressure.d ./Code/Src/Data/DataThermalPressure.o ./Code/Src/Data/DataThermalPressure.su ./Code/Src/Data/DataTyres.cyclo ./Code/Src/Data/DataTyres.d ./Code/Src/Data/DataTyres.o ./Code/Src/Data/DataTyres.su ./Code/Src/Data/Dataset.cyclo ./Code/Src/Data/Dataset.d ./Code/Src/Data/Dataset.o ./Code/Src/Data/Dataset.su

.PHONY: clean-Code-2f-Src-2f-Data

