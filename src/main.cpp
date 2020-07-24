#include <Arduino.h>
#include "time_slicer.hpp"

#define N_TASKS (sizeof(tasks) / (sizeof(Task)))

void task_1_hz()
{
	// Serial.write("Hi\n");
	digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 1); // toggle LED pin
}

void task_16_hz()
{
	int light = map(analogRead(A0), 0, 1023, 8, 24);
	static int cnt = 1;
	if (light % cnt == 0)
	{
		digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 1); // toggle LED pin	
		cnt = 1;	
	}

	cnt += 1;
}

void task_512_hz()
{
	while (Serial.available() > 0)
	{
		char input = Serial.read();

		Serial.print(input);
	}
}

struct Task
{
	void (*task)(void);
	int16_t tick_512ths;
} typedef Task;

Task tasks[] = {
	{task_1_hz, 512},
	{task_16_hz, 32},
	{task_512_hz, 1}};

void time_ticker()
{
	static uint16_t cnt = 0;

	cnt += 1;

	for (uint8_t i = 0; i < N_TASKS; i++)
	{
		if (cnt % tasks[i].tick_512ths == 0)
		{
			tasks[i].task();
		}
	}
}

void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(A0, INPUT_PULLUP);

	Serial.begin(9600);
	initTimer1(512, *time_ticker);
}

void loop()
{
}