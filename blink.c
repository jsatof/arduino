#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#define BLINK_MS 150

int main() {
	// pin mode for port B, set to output mode
	DDRB |= _BV(PORTB5); 

	while(true) {
		// toggle LED on/off (as opposed to turn on, then turn off)
		PORTB ^= _BV(PORTB5);
		_delay_ms(BLINK_MS);
	}


	return 0;
}
