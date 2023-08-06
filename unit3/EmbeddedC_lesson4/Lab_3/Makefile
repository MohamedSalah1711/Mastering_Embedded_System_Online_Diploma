# Prepared By Mohamed salah 
CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
Project_Name=Lab_CortexM4
all: $(Project_Name).bin
	
%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@
	
%.o: %.c
	$(CC)gcc -c $(CFLAGS) $(INCS) $< -o $@

$(Project_Name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(ASOBJ) $(OBJ) -o $@ -Map=Map_file.map
	cp 	$(Project_Name).elf $(Project_Name).axf

$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all: 
	rm *.o *.elf *.bin
	echo "Every thing is clean"
clean: 
	rm *.elf *.bin
				