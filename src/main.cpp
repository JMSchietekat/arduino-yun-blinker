#include <Arduino.h>
#include <SoftwareSerial.h>
#include "time_slicer.h"
#include "serial_cli.h"

SoftwareSerial mySerial(10, 11); // RX, TX

void heart_beat()
{
	digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 1);
}

void task_1_hz()
{
	heart_beat();
}

void task_16_hz()
{
	// int light = map(analogRead(A0), 0, 1023, 8, 24);
	// static int cnt = 1;
	// if (light % cnt == 0)
	// {
	// digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 1); // toggle LED pin
	// 	cnt = 1;
	// }

	// cnt += 1;
}

void task_512_hz()
{
	Serial_CLI_loop();

	while (mySerial.available())
	{
		uint8_t input = mySerial.read();
		// if (display)
		// {
		// 	if (input == 0xAA)
		// 	{
		// 		Serial.println();
		// 	}

		// 	Serial.print(input, HEX);
		// 	Serial.print(' ');
		// }
	}
}

void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(A0, INPUT_PULLUP);

	mySerial.begin(2400);

	TimeSlicer_init();
	TimeSlicer_addTask({task_1_hz, 512});
	TimeSlicer_addTask({task_16_hz, 32});
	TimeSlicer_addTask({task_512_hz, 1});
}

void loop()
{
}