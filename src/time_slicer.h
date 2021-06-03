#include "timer.h"

typedef struct 
{
	void (*task)(void);
	uint16_t tick_512ths;
} Task;

void TimeSlicer_init();
void TimeSlicer_addTask(Task task);