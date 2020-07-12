#include <Arduino.h>

char input = 0;

void initTimer1()
{
	noInterrupts(); // disable all interrupts
	TCCR1A = 0;		// Timer/Counter1 Control Register A
	TCCR1B = 0;		// Timer/Counter1 Control Register B
	TCNT1 = 0;		// Timer/Counter1

	OCR1A = 31250;			 // compare match register 16MHz/256/2Hz
	TCCR1B |= (1 << WGM12);	 // CTC mode
	TCCR1B |= (1 << CS12);	 // 256 prescaler
	TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt

	interrupts(); // enable all interrupts
}

ISR(TIMER1_COMPA_vect) // timer compare interrupt service routine
{
	digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 1); // toggle LED pin
}

void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);

	Serial.begin(9600);
	initTimer1();
}

void loop()
{

	while (Serial.available() > 0)
	{
		input = Serial.read() + 1;

		Serial.print(input);
	}
}