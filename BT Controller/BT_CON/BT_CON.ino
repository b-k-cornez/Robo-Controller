#include <SoftwareSerial.h>
#include <Wire.h>

//joystick 1
#define VRX_1 A0
#define VRY_1 A1

//joystick 2
#define VRX_2 A3
#define VRY_2 A4


struct ReceivedData {
  byte x_1;  //joystick 1 x and y vals
  byte y_1;
  byte x_2;  //joystick 2 x and y vals
  byte y_2;
};

ReceivedData data;

SoftwareSerial BT(0, 1);  //RX, TX

void setup() {

  Serial.begin(9600);

  while (!Serial)
    ;

  delay(1000);

  Serial.println("Initialised");

  BT.begin(38400);
    
}

void loop() {
  // put your main code here, to run repeatedly:

  data.x_1 = ConvertTo8bit(analogRead(VRX_1));
  data.y_1 = ConvertTo8bit(analogRead(VRY_1));
  data.x_2 = ConvertTo8bit(analogRead(VRX_2));
  data.y_2 = ConvertTo8bit(analogRead(VRY_2));

  String dataSent;


  dataSent = dataSent + data.x_1 + "," + data.y_1 + "," + data.x_2 + "," + data.y_2 +"\n";

  // dataSent = dataSent + data.x_1 + ","
  //                     + data.y_1 + ","
  //                     + data.x_2 + ","
  //                     + data.y_2 + "\n";

  BT.print(dataSent);

  delay(10);

  //print test
  Serial.print(dataSent);
}

byte ConvertTo8bit(int signalIn) //simple function of converting 10bit to 8bit by dividing by 4.
{
  signalIn=signalIn/4;

   return signalIn;
}
