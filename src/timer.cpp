#include "timer.h"

void (*fn)();

void TIMER_init_timer_1(double frequency_hz, void (*timeout_callback)())
{
	noInterrupts(); // disable all interrupts
	TCCR1A = 0;		// Timer/Counter1 Control Register A
	TCCR1B = 0;		// Timer/Counter1 Control Register B
	TCNT1 = 0;		// Timer/Counter1

	OCR1A = (int)(16e6 / (1.0 * frequency_hz)); // compare match register 16MHz/1/frequency_hz
	TCCR1B |= (1 << WGM12);						// CTC mode
	TCCR1B |= (0 << CS12);						// 1 prescaler
	TCCR1B |= (0 << CS11);
	TCCR1B |= (1 << CS10);
	TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt

	fn = timeout_callback;

	interrupts(); // enable all interrupts
}

ISR(TIMER1_COMPA_vect) // timer compare interrupt service routine
{
	fn();
}