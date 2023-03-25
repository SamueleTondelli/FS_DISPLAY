################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32f769bitx.s 

S_DEPS += \
./Core/Startup/startup_stm32f769bitx.d 

OBJS += \
./Core/Startup/startup_stm32f769bitx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -I"C:/Users/IlMio/Desktop/MMR_Hybrid/Display/New/Versioni/MMR_Hybrid_Display_v2.0/Code/Inc" -I"C:/Users/IlMio/Desktop/MMR_Hybrid/Display/New/Versioni/MMR_Hybrid_Display_v2.0/Code/Src" -I../Middlewares/ST/touchgfx/framework/include -I../TouchGFX/generated/fonts/include -I../TouchGFX/generated/gui_generated/include -I../TouchGFX/generated/images/include -I../TouchGFX/generated/texts/include -I../TouchGFX/gui/include -I../TouchGFX/generated/videos/include -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32f769bitx.d ./Core/Startup/startup_stm32f769bitx.o

.PHONY: clean-Core-2f-Startup

