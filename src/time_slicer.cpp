#include "time_slicer.h"

#define MAX_TASKS 8

void time_ticker();

Task tasks[MAX_TASKS];
uint8_t task_count = 0;

void time_ticker()
{
	static uint16_t cnt = 0;

	cnt += 1;

	for (uint8_t i = 0; i < task_count; i++)
	{
		if (cnt % tasks[i].tick_512ths == 0)
		{
			tasks[i].task();
		}
	}
}

void TimeSlicer_init()
{
	TIMER_init_timer_1(512, *time_ticker);
}

void TimeSlicer_addTask(Task task)
{
	tasks[task_count++] = task;
}
