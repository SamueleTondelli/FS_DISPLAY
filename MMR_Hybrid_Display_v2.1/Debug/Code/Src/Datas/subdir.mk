################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Code/Src/Datas/Data.c \
../Code/Src/Datas/DataAlarm.c \
../Code/Src/Datas/DataCV.c \
../Code/Src/Datas/DataEV.c \
../Code/Src/Datas/DataGeneral.c \
../Code/Src/Datas/DataHV.c \
../Code/Src/Datas/DataInverter.c \
../Code/Src/Datas/DataLV.c \
../Code/Src/Datas/DataScreen.c \
../Code/Src/Datas/DataStatus.c \
../Code/Src/Datas/Dataset.c 

C_DEPS += \
./Code/Src/Datas/Data.d \
./Code/Src/Datas/DataAlarm.d \
./Code/Src/Datas/DataCV.d \
./Code/Src/Datas/DataEV.d \
./Code/Src/Datas/DataGeneral.d \
./Code/Src/Datas/DataHV.d \
./Code/Src/Datas/DataInverter.d \
./Code/Src/Datas/DataLV.d \
./Code/Src/Datas/DataScreen.d \
./Code/Src/Datas/DataStatus.d \
./Code/Src/Datas/Dataset.d 

OBJS += \
./Code/Src/Datas/Data.o \
./Code/Src/Datas/DataAlarm.o \
./Code/Src/Datas/DataCV.o \
./Code/Src/Datas/DataEV.o \
./Code/Src/Datas/DataGeneral.o \
./Code/Src/Datas/DataHV.o \
./Code/Src/Datas/DataInverter.o \
./Code/Src/Datas/DataLV.o \
./Code/Src/Datas/DataScreen.o \
./Code/Src/Datas/DataStatus.o \
./Code/Src/Datas/Dataset.o 


# Each subdirectory must supply rules for building sources it contributes
Code/Src/Datas/%.o: ../Code/Src/Datas/%.c Code/Src/Datas/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../TouchGFX/App -I../TouchGFX/target/generated -I../TouchGFX/target -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I"C:/Users/IlMio/STM32CubeIDE/workspace_1.2.0/MMR_Hybrid_Display_v2.0/Code/Inc" -I"C:/Users/IlMio/STM32CubeIDE/workspace_1.2.0/MMR_Hybrid_Display_v2.0/Code/Src" -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -I"C:/Users/IlMio/STM32CubeIDE/workspace_1.2.0/MMR_Hybrid_Display_v2.0/Components/n25q128a" -I"C:/Users/IlMio/STM32CubeIDE/workspace_1.2.0/MMR_Hybrid_Display_v2.0/ExtFlash/Inc" -I"C:/Users/IlMio/STM32CubeIDE/workspace_1.2.0/MMR_Hybrid_Display_v2.0/ExtFlash/Src" -I"C:/Users/IlMio/STM32CubeIDE/workspace_1.2.0/MMR_Hybrid_Display_v2.0/Components/Common" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

