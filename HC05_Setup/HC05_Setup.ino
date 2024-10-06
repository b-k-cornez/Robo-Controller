#include <SoftwareSerial.h>
SoftwareSerial BTserial(0, 1); // RX | TX

char c = ' ';

void setup()
{
  Serial.begin(9600);
  Serial.println("Arduino is communicating at 9600 baud rate");

  BTserial.begin(38400);
  Serial.println("HC05 is communicating at 38400 baud rate");
}

void loop()
{
  // Keep reading from HC-05 and send to Arduino Serial Monitor

  if (BTserial.available()) {
    Serial.write(BTserial.read());
  }
  if (Serial.available()) {
    BTserial.write(Serial.read());
  }

}