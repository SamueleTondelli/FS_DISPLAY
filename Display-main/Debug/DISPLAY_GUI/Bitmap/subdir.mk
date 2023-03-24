################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DISPLAY_GUI/Bitmap/GEARBOX_1.c \
../DISPLAY_GUI/Bitmap/GEARBOX_1_116_Gray255.c \
../DISPLAY_GUI/Bitmap/GEARBOX_2.c \
../DISPLAY_GUI/Bitmap/GEARBOX_2_116_Gray255.c \
../DISPLAY_GUI/Bitmap/GEARBOX_3.c \
../DISPLAY_GUI/Bitmap/GEARBOX_3_116_Gray255.c \
../DISPLAY_GUI/Bitmap/GEARBOX_4.c \
../DISPLAY_GUI/Bitmap/GEARBOX_4_116_Gray255.c \
../DISPLAY_GUI/Bitmap/GEARBOX_N.c \
../DISPLAY_GUI/Bitmap/GEARBOX_N_116_Gray255.c \
../DISPLAY_GUI/Bitmap/LOGO_TECHBOARD_460_76_8888.c \
../DISPLAY_GUI/Bitmap/MMRLogo_296_164_8888.c \
../DISPLAY_GUI/Bitmap/MMRLogo_480_265_8888.c \
../DISPLAY_GUI/Bitmap/Scuderia_Ferrari_F1_2018.c \
../DISPLAY_GUI/Bitmap/antistall.c 

OBJS += \
./DISPLAY_GUI/Bitmap/GEARBOX_1.o \
./DISPLAY_GUI/Bitmap/GEARBOX_1_116_Gray255.o \
./DISPLAY_GUI/Bitmap/GEARBOX_2.o \
./DISPLAY_GUI/Bitmap/GEARBOX_2_116_Gray255.o \
./DISPLAY_GUI/Bitmap/GEARBOX_3.o \
./DISPLAY_GUI/Bitmap/GEARBOX_3_116_Gray255.o \
./DISPLAY_GUI/Bitmap/GEARBOX_4.o \
./DISPLAY_GUI/Bitmap/GEARBOX_4_116_Gray255.o \
./DISPLAY_GUI/Bitmap/GEARBOX_N.o \
./DISPLAY_GUI/Bitmap/GEARBOX_N_116_Gray255.o \
./DISPLAY_GUI/Bitmap/LOGO_TECHBOARD_460_76_8888.o \
./DISPLAY_GUI/Bitmap/MMRLogo_296_164_8888.o \
./DISPLAY_GUI/Bitmap/MMRLogo_480_265_8888.o \
./DISPLAY_GUI/Bitmap/Scuderia_Ferrari_F1_2018.o \
./DISPLAY_GUI/Bitmap/antistall.o 

C_DEPS += \
./DISPLAY_GUI/Bitmap/GEARBOX_1.d \
./DISPLAY_GUI/Bitmap/GEARBOX_1_116_Gray255.d \
./DISPLAY_GUI/Bitmap/GEARBOX_2.d \
./DISPLAY_GUI/Bitmap/GEARBOX_2_116_Gray255.d \
./DISPLAY_GUI/Bitmap/GEARBOX_3.d \
./DISPLAY_GUI/Bitmap/GEARBOX_3_116_Gray255.d \
./DISPLAY_GUI/Bitmap/GEARBOX_4.d \
./DISPLAY_GUI/Bitmap/GEARBOX_4_116_Gray255.d \
./DISPLAY_GUI/Bitmap/GEARBOX_N.d \
./DISPLAY_GUI/Bitmap/GEARBOX_N_116_Gray255.d \
./DISPLAY_GUI/Bitmap/LOGO_TECHBOARD_460_76_8888.d \
./DISPLAY_GUI/Bitmap/MMRLogo_296_164_8888.d \
./DISPLAY_GUI/Bitmap/MMRLogo_480_265_8888.d \
./DISPLAY_GUI/Bitmap/Scuderia_Ferrari_F1_2018.d \
./DISPLAY_GUI/Bitmap/antistall.d 


# Each subdirectory must supply rules for building sources it contributes
DISPLAY_GUI/Bitmap/%.o DISPLAY_GUI/Bitmap/%.su: ../DISPLAY_GUI/Bitmap/%.c DISPLAY_GUI/Bitmap/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I/Display_Software/Drivers/Components/Inc -I"M:/SAE/Projects/GitHub_Data/Display/STemWin/inc" -I"M:/SAE/Projects/GitHub_Data/Display/MDM_Functions/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/MDM_GUI_LIB/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/DISPLAY_GUI/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/CAR_DATA/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-DISPLAY_GUI-2f-Bitmap

clean-DISPLAY_GUI-2f-Bitmap:
	-$(RM) ./DISPLAY_GUI/Bitmap/GEARBOX_1.d ./DISPLAY_GUI/Bitmap/GEARBOX_1.o ./DISPLAY_GUI/Bitmap/GEARBOX_1.su ./DISPLAY_GUI/Bitmap/GEARBOX_1_116_Gray255.d ./DISPLAY_GUI/Bitmap/GEARBOX_1_116_Gray255.o ./DISPLAY_GUI/Bitmap/GEARBOX_1_116_Gray255.su ./DISPLAY_GUI/Bitmap/GEARBOX_2.d ./DISPLAY_GUI/Bitmap/GEARBOX_2.o ./DISPLAY_GUI/Bitmap/GEARBOX_2.su ./DISPLAY_GUI/Bitmap/GEARBOX_2_116_Gray255.d ./DISPLAY_GUI/Bitmap/GEARBOX_2_116_Gray255.o ./DISPLAY_GUI/Bitmap/GEARBOX_2_116_Gray255.su ./DISPLAY_GUI/Bitmap/GEARBOX_3.d ./DISPLAY_GUI/Bitmap/GEARBOX_3.o ./DISPLAY_GUI/Bitmap/GEARBOX_3.su ./DISPLAY_GUI/Bitmap/GEARBOX_3_116_Gray255.d ./DISPLAY_GUI/Bitmap/GEARBOX_3_116_Gray255.o ./DISPLAY_GUI/Bitmap/GEARBOX_3_116_Gray255.su ./DISPLAY_GUI/Bitmap/GEARBOX_4.d ./DISPLAY_GUI/Bitmap/GEARBOX_4.o ./DISPLAY_GUI/Bitmap/GEARBOX_4.su ./DISPLAY_GUI/Bitmap/GEARBOX_4_116_Gray255.d ./DISPLAY_GUI/Bitmap/GEARBOX_4_116_Gray255.o ./DISPLAY_GUI/Bitmap/GEARBOX_4_116_Gray255.su ./DISPLAY_GUI/Bitmap/GEARBOX_N.d ./DISPLAY_GUI/Bitmap/GEARBOX_N.o ./DISPLAY_GUI/Bitmap/GEARBOX_N.su ./DISPLAY_GUI/Bitmap/GEARBOX_N_116_Gray255.d ./DISPLAY_GUI/Bitmap/GEARBOX_N_116_Gray255.o ./DISPLAY_GUI/Bitmap/GEARBOX_N_116_Gray255.su ./DISPLAY_GUI/Bitmap/LOGO_TECHBOARD_460_76_8888.d ./DISPLAY_GUI/Bitmap/LOGO_TECHBOARD_460_76_8888.o ./DISPLAY_GUI/Bitmap/LOGO_TECHBOARD_460_76_8888.su ./DISPLAY_GUI/Bitmap/MMRLogo_296_164_8888.d ./DISPLAY_GUI/Bitmap/MMRLogo_296_164_8888.o ./DISPLAY_GUI/Bitmap/MMRLogo_296_164_8888.su ./DISPLAY_GUI/Bitmap/MMRLogo_480_265_8888.d ./DISPLAY_GUI/Bitmap/MMRLogo_480_265_8888.o ./DISPLAY_GUI/Bitmap/MMRLogo_480_265_8888.su ./DISPLAY_GUI/Bitmap/Scuderia_Ferrari_F1_2018.d ./DISPLAY_GUI/Bitmap/Scuderia_Ferrari_F1_2018.o ./DISPLAY_GUI/Bitmap/Scuderia_Ferrari_F1_2018.su ./DISPLAY_GUI/Bitmap/antistall.d ./DISPLAY_GUI/Bitmap/antistall.o ./DISPLAY_GUI/Bitmap/antistall.su

.PHONY: clean-DISPLAY_GUI-2f-Bitmap

