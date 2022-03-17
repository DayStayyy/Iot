################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/adc.c \
../Src/dac.c \
../Src/dma.c \
../Src/gpio.c \
../Src/i2c.c \
../Src/i2s.c \
../Src/main.c \
../Src/spi.c \
../Src/stm32f4xx_hal_msp.c \
../Src/stm32f4xx_it.c \
../Src/syscalls.c \
../Src/system_stm32f4xx.c \
../Src/tim.c \
../Src/usart.c \
../Src/usb_host.c \
../Src/usbh_conf.c \
../Src/usbh_platform.c 

OBJS += \
./Src/adc.o \
./Src/dac.o \
./Src/dma.o \
./Src/gpio.o \
./Src/i2c.o \
./Src/i2s.o \
./Src/main.o \
./Src/spi.o \
./Src/stm32f4xx_hal_msp.o \
./Src/stm32f4xx_it.o \
./Src/syscalls.o \
./Src/system_stm32f4xx.o \
./Src/tim.o \
./Src/usart.o \
./Src/usb_host.o \
./Src/usbh_conf.o \
./Src/usbh_platform.o 

C_DEPS += \
./Src/adc.d \
./Src/dac.d \
./Src/dma.d \
./Src/gpio.d \
./Src/i2c.d \
./Src/i2s.d \
./Src/main.d \
./Src/spi.d \
./Src/stm32f4xx_hal_msp.d \
./Src/stm32f4xx_it.d \
./Src/syscalls.d \
./Src/system_stm32f4xx.d \
./Src/tim.d \
./Src/usart.d \
./Src/usb_host.d \
./Src/usbh_conf.d \
./Src/usbh_platform.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DUSE_HAL_DRIVER -DSTM32F407xx -I"C:/Users/louis/iot/21_F407Disco_Audio_Joystick_dma/21_F407Disco_Audio_Joystick_dma/Inc" -I"C:/Users/louis/iot/21_F407Disco_Audio_Joystick_dma/21_F407Disco_Audio_Joystick_dma/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Users/louis/iot/21_F407Disco_Audio_Joystick_dma/21_F407Disco_Audio_Joystick_dma/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Users/louis/iot/21_F407Disco_Audio_Joystick_dma/21_F407Disco_Audio_Joystick_dma/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"C:/Users/louis/iot/21_F407Disco_Audio_Joystick_dma/21_F407Disco_Audio_Joystick_dma/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"C:/Users/louis/iot/21_F407Disco_Audio_Joystick_dma/21_F407Disco_Audio_Joystick_dma/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Users/louis/iot/21_F407Disco_Audio_Joystick_dma/21_F407Disco_Audio_Joystick_dma/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


