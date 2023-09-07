################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Clock_initLab.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Clock_initLab.list \

OBJCOPY_BIN += \
Clock_initLab.bin \


# All Target
all: Clock_initLab.elf secondary-outputs

# Tool invocations
Clock_initLab.elf: $(OBJS) $(USER_OBJS) D:\kerollos\ course\unit\ 2\unit6\lesson2\lab\ 2\Clock_initLab\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -o "Clock_initLab.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\kerollos course\unit 2\unit6\lesson2\lab 2\Clock_initLab\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Clock_initLab.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Clock_initLab.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Clock_initLab.list"
	@echo 'Finished building: $@'
	@echo ' '

Clock_initLab.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Clock_initLab.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
