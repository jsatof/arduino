# compiler options
CC = avr-gcc
CFLAGS = -Os -DF_CPU=16000000UL -mmcu=atmega328p

all: blink.o

USBPORT:=$(shell ls /dev/tty.usbmodem*)

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

%.hex: %.o
	avr-objcopy -O ihex -R .eeprom $< $@

# upload to board
install.%: %.hex
	avrdude -F -V -c arduino -p ATMEGA328P -P ${USBPORT} -b 115200 -U flash:w:$<

clean:
	rm -f *.hex *.o
