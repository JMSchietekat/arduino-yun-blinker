#include "serial_soft.h"

SoftwareSerial mySerial(10, 11); // RX, TX

void Serial_soft_init()
{
	mySerial.begin(2400);
}

void Serial_soft_loop()
{

	while (mySerial.available())
	{
		uint8_t input = mySerial.read();
		if (1)//display)
		{
			if (input == 0xAA)
			{
				Serial.println();
			}

			Serial.print(input, HEX);
			Serial.print(' ');
		}
	}
}