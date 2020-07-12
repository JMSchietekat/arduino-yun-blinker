#include <Arduino.h>
#include "time_slicer.h"

char input = 0;

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