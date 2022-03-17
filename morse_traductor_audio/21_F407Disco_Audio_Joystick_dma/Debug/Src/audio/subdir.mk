################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/audio/MY_CS43L22.c 

OBJS += \
./Src/audio/MY_CS43L22.o 

C_DEPS += \
./Src/audio/MY_CS43L22.d 


# Each subdirectory must supply rules for building sources it contributes
Src/audio/%.o: ../Src/audio/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F407xx -I"C:/Users/louis/iot/21_F407Disco_Audio_Joystick_dma/21_F407Disco_Audio_Joystick_dma/Inc" -I"C:/Users/louis/iot/21_F407Disco_Audio_Joystick_dma/21_F407Disco_Audio_Joystick_dma/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/louis/iot/21_F407Disco_Audio_Joystick_dma/21_F407Disco_Audio_Joystick_dma/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/louis/iot/21_F407Disco_Audio_Joystick_dma/21_F407Disco_Audio_Joystick_dma/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Users/louis/iot/21_F407Disco_Audio_Joystick_dma/21_F407Disco_Audio_Joystick_dma/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Users/louis/iot/21_F407Disco_Audio_Joystick_dma/21_F407Disco_Audio_Joystick_dma/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/louis/iot/21_F407Disco_Audio_Joystick_dma/21_F407Disco_Audio_Joystick_dma/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


