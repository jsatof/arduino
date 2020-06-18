#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

int main() {
	DDRB |= 0b00100000; // pin mode for port B

	while(true) {
		PORTB |= 0b00100000;

		_delay_ms(BLINK_MS);

		PORTB &= ~0b0010000;
		_delay_ms(BLINK_MS);
	}


	return 0;
}
