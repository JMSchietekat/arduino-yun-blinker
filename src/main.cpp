#include <Arduino.h>
#include "time_slicer.hpp"

char input = 0;

void timer_callback()
{
	digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 1); // toggle LED pin
}

void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);

	Serial.begin(9600);
	initTimer1(*timer_callback);
}

void loop()
{

	while (Serial.available() > 0)
	{
		input = Serial.read() + 1;

		Serial.print(input);
	}
}