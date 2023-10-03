################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lcd_Driver/Lcd.c 

OBJS += \
./Lcd_Driver/Lcd.o 

C_DEPS += \
./Lcd_Driver/Lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Lcd_Driver/Lcd.o: ../Lcd_Driver/Lcd.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/kerollos course/unit 2/unit7/Section 3/Lcd_KeypadLab/Lcd_Keypad_Lab/Key_pad/inc" -I"D:/kerollos course/unit 2/unit7/Section 3/Lcd_KeypadLab/Lcd_Keypad_Lab/Lcd_Driver/inc" -I"D:/kerollos course/unit 2/unit7/Section 3/Lcd_KeypadLab/Lcd_Keypad_Lab/GPIO_Driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Lcd_Driver/Lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

