################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DISPLAY_GUI/Src/DISPLAY_GUI.c \
../DISPLAY_GUI/Src/DisplayGui_Acceleration.c \
../DISPLAY_GUI/Src/DisplayGui_AntiStall.c \
../DISPLAY_GUI/Src/DisplayGui_CarSetup.c \
../DISPLAY_GUI/Src/DisplayGui_Debug.c \
../DISPLAY_GUI/Src/DisplayGui_Drive1.c \
../DISPLAY_GUI/Src/DisplayGui_Drive2.c \
../DISPLAY_GUI/Src/DisplayGui_HandlingCurevsTest.c \
../DISPLAY_GUI/Src/DisplayGui_Logo.c \
../DISPLAY_GUI/Src/DisplayGui_Old1.c \
../DISPLAY_GUI/Src/DisplayGui_Old2.c \
../DISPLAY_GUI/Src/DisplayGui_PowertrainData1.c \
../DISPLAY_GUI/Src/DisplayGui_Sponsor.c \
../DISPLAY_GUI/Src/DisplayGui_TestDrive.c \
../DISPLAY_GUI/Src/Display_DataLog.c \
../DISPLAY_GUI/Src/Display_DriveSTD.c \
../DISPLAY_GUI/Src/Display_Message.c \
../DISPLAY_GUI/Src/Display_OldRpmBar.c \
../DISPLAY_GUI/Src/Display_ThermalCam.c \
../DISPLAY_GUI/Src/Dsiplay_LaunchControlBar.c 

OBJS += \
./DISPLAY_GUI/Src/DISPLAY_GUI.o \
./DISPLAY_GUI/Src/DisplayGui_Acceleration.o \
./DISPLAY_GUI/Src/DisplayGui_AntiStall.o \
./DISPLAY_GUI/Src/DisplayGui_CarSetup.o \
./DISPLAY_GUI/Src/DisplayGui_Debug.o \
./DISPLAY_GUI/Src/DisplayGui_Drive1.o \
./DISPLAY_GUI/Src/DisplayGui_Drive2.o \
./DISPLAY_GUI/Src/DisplayGui_HandlingCurevsTest.o \
./DISPLAY_GUI/Src/DisplayGui_Logo.o \
./DISPLAY_GUI/Src/DisplayGui_Old1.o \
./DISPLAY_GUI/Src/DisplayGui_Old2.o \
./DISPLAY_GUI/Src/DisplayGui_PowertrainData1.o \
./DISPLAY_GUI/Src/DisplayGui_Sponsor.o \
./DISPLAY_GUI/Src/DisplayGui_TestDrive.o \
./DISPLAY_GUI/Src/Display_DataLog.o \
./DISPLAY_GUI/Src/Display_DriveSTD.o \
./DISPLAY_GUI/Src/Display_Message.o \
./DISPLAY_GUI/Src/Display_OldRpmBar.o \
./DISPLAY_GUI/Src/Display_ThermalCam.o \
./DISPLAY_GUI/Src/Dsiplay_LaunchControlBar.o 

C_DEPS += \
./DISPLAY_GUI/Src/DISPLAY_GUI.d \
./DISPLAY_GUI/Src/DisplayGui_Acceleration.d \
./DISPLAY_GUI/Src/DisplayGui_AntiStall.d \
./DISPLAY_GUI/Src/DisplayGui_CarSetup.d \
./DISPLAY_GUI/Src/DisplayGui_Debug.d \
./DISPLAY_GUI/Src/DisplayGui_Drive1.d \
./DISPLAY_GUI/Src/DisplayGui_Drive2.d \
./DISPLAY_GUI/Src/DisplayGui_HandlingCurevsTest.d \
./DISPLAY_GUI/Src/DisplayGui_Logo.d \
./DISPLAY_GUI/Src/DisplayGui_Old1.d \
./DISPLAY_GUI/Src/DisplayGui_Old2.d \
./DISPLAY_GUI/Src/DisplayGui_PowertrainData1.d \
./DISPLAY_GUI/Src/DisplayGui_Sponsor.d \
./DISPLAY_GUI/Src/DisplayGui_TestDrive.d \
./DISPLAY_GUI/Src/Display_DataLog.d \
./DISPLAY_GUI/Src/Display_DriveSTD.d \
./DISPLAY_GUI/Src/Display_Message.d \
./DISPLAY_GUI/Src/Display_OldRpmBar.d \
./DISPLAY_GUI/Src/Display_ThermalCam.d \
./DISPLAY_GUI/Src/Dsiplay_LaunchControlBar.d 


# Each subdirectory must supply rules for building sources it contributes
DISPLAY_GUI/Src/%.o DISPLAY_GUI/Src/%.su: ../DISPLAY_GUI/Src/%.c DISPLAY_GUI/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F769xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I/Display_Software/Drivers/Components/Inc -I"M:/SAE/Projects/GitHub_Data/Display/STemWin/inc" -I"M:/SAE/Projects/GitHub_Data/Display/MDM_Functions/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/MDM_GUI_LIB/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/DISPLAY_GUI/Inc" -I"M:/SAE/Projects/GitHub_Data/Display/CAR_DATA/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-DISPLAY_GUI-2f-Src

clean-DISPLAY_GUI-2f-Src:
	-$(RM) ./DISPLAY_GUI/Src/DISPLAY_GUI.d ./DISPLAY_GUI/Src/DISPLAY_GUI.o ./DISPLAY_GUI/Src/DISPLAY_GUI.su ./DISPLAY_GUI/Src/DisplayGui_Acceleration.d ./DISPLAY_GUI/Src/DisplayGui_Acceleration.o ./DISPLAY_GUI/Src/DisplayGui_Acceleration.su ./DISPLAY_GUI/Src/DisplayGui_AntiStall.d ./DISPLAY_GUI/Src/DisplayGui_AntiStall.o ./DISPLAY_GUI/Src/DisplayGui_AntiStall.su ./DISPLAY_GUI/Src/DisplayGui_CarSetup.d ./DISPLAY_GUI/Src/DisplayGui_CarSetup.o ./DISPLAY_GUI/Src/DisplayGui_CarSetup.su ./DISPLAY_GUI/Src/DisplayGui_Debug.d ./DISPLAY_GUI/Src/DisplayGui_Debug.o ./DISPLAY_GUI/Src/DisplayGui_Debug.su ./DISPLAY_GUI/Src/DisplayGui_Drive1.d ./DISPLAY_GUI/Src/DisplayGui_Drive1.o ./DISPLAY_GUI/Src/DisplayGui_Drive1.su ./DISPLAY_GUI/Src/DisplayGui_Drive2.d ./DISPLAY_GUI/Src/DisplayGui_Drive2.o ./DISPLAY_GUI/Src/DisplayGui_Drive2.su ./DISPLAY_GUI/Src/DisplayGui_HandlingCurevsTest.d ./DISPLAY_GUI/Src/DisplayGui_HandlingCurevsTest.o ./DISPLAY_GUI/Src/DisplayGui_HandlingCurevsTest.su ./DISPLAY_GUI/Src/DisplayGui_Logo.d ./DISPLAY_GUI/Src/DisplayGui_Logo.o ./DISPLAY_GUI/Src/DisplayGui_Logo.su ./DISPLAY_GUI/Src/DisplayGui_Old1.d ./DISPLAY_GUI/Src/DisplayGui_Old1.o ./DISPLAY_GUI/Src/DisplayGui_Old1.su ./DISPLAY_GUI/Src/DisplayGui_Old2.d ./DISPLAY_GUI/Src/DisplayGui_Old2.o ./DISPLAY_GUI/Src/DisplayGui_Old2.su ./DISPLAY_GUI/Src/DisplayGui_PowertrainData1.d ./DISPLAY_GUI/Src/DisplayGui_PowertrainData1.o ./DISPLAY_GUI/Src/DisplayGui_PowertrainData1.su ./DISPLAY_GUI/Src/DisplayGui_Sponsor.d ./DISPLAY_GUI/Src/DisplayGui_Sponsor.o ./DISPLAY_GUI/Src/DisplayGui_Sponsor.su ./DISPLAY_GUI/Src/DisplayGui_TestDrive.d ./DISPLAY_GUI/Src/DisplayGui_TestDrive.o ./DISPLAY_GUI/Src/DisplayGui_TestDrive.su ./DISPLAY_GUI/Src/Display_DataLog.d ./DISPLAY_GUI/Src/Display_DataLog.o ./DISPLAY_GUI/Src/Display_DataLog.su ./DISPLAY_GUI/Src/Display_DriveSTD.d ./DISPLAY_GUI/Src/Display_DriveSTD.o ./DISPLAY_GUI/Src/Display_DriveSTD.su ./DISPLAY_GUI/Src/Display_Message.d ./DISPLAY_GUI/Src/Display_Message.o ./DISPLAY_GUI/Src/Display_Message.su ./DISPLAY_GUI/Src/Display_OldRpmBar.d ./DISPLAY_GUI/Src/Display_OldRpmBar.o ./DISPLAY_GUI/Src/Display_OldRpmBar.su ./DISPLAY_GUI/Src/Display_ThermalCam.d ./DISPLAY_GUI/Src/Display_ThermalCam.o ./DISPLAY_GUI/Src/Display_ThermalCam.su ./DISPLAY_GUI/Src/Dsiplay_LaunchControlBar.d ./DISPLAY_GUI/Src/Dsiplay_LaunchControlBar.o ./DISPLAY_GUI/Src/Dsiplay_LaunchControlBar.su

.PHONY: clean-DISPLAY_GUI-2f-Src

