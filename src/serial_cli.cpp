#include "serial_cli.h"

bool display = false;

void print_help()
{
	Serial.println("Welcome to Justin's Arduino Yun");
	Serial.println("Valid commands are:");
	Serial.println("\th - Display help menu.");
	Serial.println("\ty - Display soft serial.");
	Serial.println("\tn - Disable soft serial.");
}

void Serial_CLI_init()
{
	Serial.begin(9600);
	print_help();
}

void Serial_CLI_loop()
{
	while (Serial.available())
	{
		char input = Serial.read();
		Serial.println(input);

		if (input == 'y')
		{
			display = true;
			Serial.println("Started displaying the soft serial input.");
		}
		else if (input == 'n')
		{
			display = false;
			Serial.println("Stopped displaying the soft serial input.");
		}
		else if (input == 'h')
		{
			print_help();
		}
	}
}