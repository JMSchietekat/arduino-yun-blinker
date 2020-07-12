#include <Arduino.h>

char input = 0;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(50);
  digitalWrite(LED_BUILTIN, LOW);
  delay(50);

  while (Serial.available() > 0)
  {
    input = Serial.read() +1;

    Serial.print(input);
  }
}