################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Fonts/Calibri200.c \
../Fonts/Calibri20Balised4pp.c \
../Fonts/Calibri230Balised2pp_DigAndMaiusc.c \
../Fonts/Calibri230Balised4pp.c \
../Fonts/Calibri24Balised4pp.c \
../Fonts/Calibri250.c \
../Fonts/Calibri30alised4pp.c \
../Fonts/Calibri40alised4pp.c \
../Fonts/Calibri44Balised4pp.c \
../Fonts/Calibri50alised4pp.c \
../Fonts/GearboxFont112.c 

OBJS += \
./Fonts/Calibri200.o \
./Fonts/Calibri20Balised4pp.o \
./Fonts/Calibri230Balised2pp_DigAndMaiusc.o \
./Fonts/Calibri230Balised4pp.o \
./Fonts/Calibri24Balised4pp.o \
./Fonts/Calibri250.o \
./Fonts/Calibri30alised4pp.o \
./Fonts/Calibri40alised4pp.o \
./Fonts/Calibri44Balised4pp.o \
./Fonts/Calibri50alised4pp.o \
./Fonts/GearboxFont112.o 

C_DEPS += \
./Fonts/Calibri200.d \
./Fonts/Calibri20Balised4pp.d \
./Fonts/Calibri230Balised2pp_DigAndMaiusc.d \
./Fonts/Calibri230Balised4pp.d \
./Fonts/Calibri24Balised4pp.d \
./Fonts/Calibri250.d \
./Fonts/Calibri30alised4pp.d \
./Fonts/Calibri40alised4pp.d \
./Fonts/Calibri44Balised4pp.d \
./Fonts/Calibri50alised4pp.d \
./Fonts/GearboxFont112.d 


# Each subdirectory must supply rules for building sources it contributes
Fonts/%.o Fonts/%.su: ../Fonts/%.c Fonts/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I/Display_Software/Drivers/Components/Inc -I"M:/SAE/Projects/GitHub_Data/Display/STemWin/inc" -I"M:/SAE/Projects/GitHub_Data/Display/MDM_Functions/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/MDM_GUI_LIB/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/DISPLAY_GUI/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/CAR_DATA/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Fonts

clean-Fonts:
	-$(RM) ./Fonts/Calibri200.d ./Fonts/Calibri200.o ./Fonts/Calibri200.su ./Fonts/Calibri20Balised4pp.d ./Fonts/Calibri20Balised4pp.o ./Fonts/Calibri20Balised4pp.su ./Fonts/Calibri230Balised2pp_DigAndMaiusc.d ./Fonts/Calibri230Balised2pp_DigAndMaiusc.o ./Fonts/Calibri230Balised2pp_DigAndMaiusc.su ./Fonts/Calibri230Balised4pp.d ./Fonts/Calibri230Balised4pp.o ./Fonts/Calibri230Balised4pp.su ./Fonts/Calibri24Balised4pp.d ./Fonts/Calibri24Balised4pp.o ./Fonts/Calibri24Balised4pp.su ./Fonts/Calibri250.d ./Fonts/Calibri250.o ./Fonts/Calibri250.su ./Fonts/Calibri30alised4pp.d ./Fonts/Calibri30alised4pp.o ./Fonts/Calibri30alised4pp.su ./Fonts/Calibri40alised4pp.d ./Fonts/Calibri40alised4pp.o ./Fonts/Calibri40alised4pp.su ./Fonts/Calibri44Balised4pp.d ./Fonts/Calibri44Balised4pp.o ./Fonts/Calibri44Balised4pp.su ./Fonts/Calibri50alised4pp.d ./Fonts/Calibri50alised4pp.o ./Fonts/Calibri50alised4pp.su ./Fonts/GearboxFont112.d ./Fonts/GearboxFont112.o ./Fonts/GearboxFont112.su

.PHONY: clean-Fonts

