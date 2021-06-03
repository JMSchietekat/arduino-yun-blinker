#include <Arduino.h>
#include "time_slicer.h"
#include "serial_cli.h"
#include "serial_soft.h"

void heart_beat()
{
	digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 1);
}

void task_1_hz() {}

void task_2_hz()
{
	heart_beat();
}

void task_16_hz() {}

void task_512_hz()
{
	Serial_CLI_loop();
	Serial_soft_loop();
}

void setup()
{
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(A0, INPUT_PULLUP);

	Serial_CLI_init();
	Serial_soft_init();

	TimeSlicer_init();
	TimeSlicer_addTask({task_1_hz, 512});
	TimeSlicer_addTask({task_2_hz, 256});
	TimeSlicer_addTask({task_16_hz, 32});
	TimeSlicer_addTask({task_512_hz, 1});
}

void loop()
{
}