#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include <avr/interrupt.h>

#define PRESCALER 10 		// 10 bits...1024
#define CLOCK_RATE 15998976

// approximately number of ticks in a second
#define COUNTER_VALUE (CLOCK_RATE >> PRESCALER)

ISR(TIMER1_COMPA_vect) {
	PORTB ^= _BV(PORTB5);
}

int main() {
	// pin mode for port B, set to output mode
	DDRB |= _BV(PORTB5); 

	// output compare register 1, set to number of clock ticks for interrupt
	OCR1A = COUNTER_VALUE;

	// config the timer, (Timer Counter Config Register)
	TCCR1A = 0x00;
	TCCR1B |= (1 << WGM12); // clear timer on compare
	TCCR1B |= (1 << CS10) | (1 << CS12);

	// send the interrupt
	TIMSK1 |= (1 << OCIE1A);
	sei();	// enable interupts

	while(true) {
	
	}


	return 0;
}
