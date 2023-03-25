################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Code/Src/Data/Data.c \
../Code/Src/Data/DataDynamics.c \
../Code/Src/Data/DataHVElectronicsBMS.c \
../Code/Src/Data/DataHVElectronicsInverter.c \
../Code/Src/Data/DataLVElectronics.c \
../Code/Src/Data/DataLapTime.c \
../Code/Src/Data/DataMessagesErrors.c \
../Code/Src/Data/DataNotification.c \
../Code/Src/Data/DataPowerUnit.c \
../Code/Src/Data/DataScreen.c \
../Code/Src/Data/DataStatus.c \
../Code/Src/Data/DataThermalAereodinamics.c \
../Code/Src/Data/Dataset.c 

C_DEPS += \
./Code/Src/Data/Data.d \
./Code/Src/Data/DataDynamics.d \
./Code/Src/Data/DataHVElectronicsBMS.d \
./Code/Src/Data/DataHVElectronicsInverter.d \
./Code/Src/Data/DataLVElectronics.d \
./Code/Src/Data/DataLapTime.d \
./Code/Src/Data/DataMessagesErrors.d \
./Code/Src/Data/DataNotification.d \
./Code/Src/Data/DataPowerUnit.d \
./Code/Src/Data/DataScreen.d \
./Code/Src/Data/DataStatus.d \
./Code/Src/Data/DataThermalAereodinamics.d \
./Code/Src/Data/Dataset.d 

OBJS += \
./Code/Src/Data/Data.o \
./Code/Src/Data/DataDynamics.o \
./Code/Src/Data/DataHVElectronicsBMS.o \
./Code/Src/Data/DataHVElectronicsInverter.o \
./Code/Src/Data/DataLVElectronics.o \
./Code/Src/Data/DataLapTime.o \
./Code/Src/Data/DataMessagesErrors.o \
./Code/Src/Data/DataNotification.o \
./Code/Src/Data/DataPowerUnit.o \
./Code/Src/Data/DataScreen.o \
./Code/Src/Data/DataStatus.o \
./Code/Src/Data/DataThermalAereodinamics.o \
./Code/Src/Data/Dataset.o 


# Each subdirectory must supply rules for building sources it contributes
Code/Src/Data/%.o: ../Code/Src/Data/%.c Code/Src/Data/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../TouchGFX/generated/videos/include -I../LIBJPEG/App -I../LIBJPEG/Target -I../Middlewares/Third_Party/LibJPEG/include -I"C:/Users/IlMio/STM32CubeIDE/workspace_1.2.0/MMR_Hybrid_Display_v2.1/Code/Inc" -I"C:/Users/IlMio/STM32CubeIDE/workspace_1.2.0/MMR_Hybrid_Display_v2.1/Code/Src" -I"C:/Users/IlMio/STM32CubeIDE/workspace_1.2.0/MMR_Hybrid_Display_v2.1/Components/n25q128a" -I"C:/Users/IlMio/STM32CubeIDE/workspace_1.2.0/MMR_Hybrid_Display_v2.1/ExtFlash/Inc" -I"C:/Users/IlMio/STM32CubeIDE/workspace_1.2.0/MMR_Hybrid_Display_v2.1/ExtFlash/Src" -I"C:/Users/IlMio/STM32CubeIDE/workspace_1.2.0/MMR_Hybrid_Display_v2.1/Components/Common" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Code-2f-Src-2f-Data

clean-Code-2f-Src-2f-Data:
	-$(RM) ./Code/Src/Data/Data.d ./Code/Src/Data/Data.o ./Code/Src/Data/DataDynamics.d ./Code/Src/Data/DataDynamics.o ./Code/Src/Data/DataHVElectronicsBMS.d ./Code/Src/Data/DataHVElectronicsBMS.o ./Code/Src/Data/DataHVElectronicsInverter.d ./Code/Src/Data/DataHVElectronicsInverter.o ./Code/Src/Data/DataLVElectronics.d ./Code/Src/Data/DataLVElectronics.o ./Code/Src/Data/DataLapTime.d ./Code/Src/Data/DataLapTime.o ./Code/Src/Data/DataMessagesErrors.d ./Code/Src/Data/DataMessagesErrors.o ./Code/Src/Data/DataNotification.d ./Code/Src/Data/DataNotification.o ./Code/Src/Data/DataPowerUnit.d ./Code/Src/Data/DataPowerUnit.o ./Code/Src/Data/DataScreen.d ./Code/Src/Data/DataScreen.o ./Code/Src/Data/DataStatus.d ./Code/Src/Data/DataStatus.o ./Code/Src/Data/DataThermalAereodinamics.d ./Code/Src/Data/DataThermalAereodinamics.o ./Code/Src/Data/Dataset.d ./Code/Src/Data/Dataset.o

.PHONY: clean-Code-2f-Src-2f-Data

