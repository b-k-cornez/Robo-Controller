#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVO_FREQ 40  //Amazons technical page said it has a max pulse period of 2.5ms so Freq=1/period gives the appropriate servo Freq
#define SERVOMIN 100   // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX 450   // This is the 'maximum' pulse length count (out of 4096)
#define UMIN 500       //min and max pulse lengths in microseconds
#define UMAX 2500

SoftwareSerial BT(0, 1);

String dataString;

//angles for servos to move to at initalisation(FEATURE NOT IMPLEMENTED REQUIRES FEEDBACK LOOP ON SERVO);
// int16_t x_ang_init_1 = 0;
// int16_t y_ang_init_1 = 180;

int16_t x_ang_1 = 0;
int16_t y_ang_1 = 90;
int16_t x_ang_2 = 90;


//servos
uint8_t servoOne = 0;
uint8_t servoTwo = 1;
uint8_t servoThree = 2;


//store the values into a struct for easier access
struct ReceivedData {
  byte x_1;  //joystick 1 x and y vals
  byte y_1;
  byte x_2;  //joystick 2 x and y vals
  byte y_2;
};

ReceivedData data;  //new instance of the struct called data

void setup() {

  Serial.begin(9600);

  while (!Serial)
    ;

  delay(1000);

  Serial.println("Initialised");  //just to check that everything is working

  BT.begin(38400);

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
  delay(10);
}

void loop() {


  if (BT.available()) {

    dataString = BT.readStringUntil('\n');  //thats why the \n was added to the data string in the controller (make sure you use single quotes here and not double)

    sscanf(dataString.c_str(), "%d,%d,%d,%d", &data.x_1, &data.y_1, &data.x_2, &data.y_2);
    //, &data.x_2, &data.y_2); //format the string and store their values in the struct

    //Serial.println(dataString);
    //check the angle and received data for the x value


    //checks if value received by controller is less than or equal to a certain amount
    if (data.x_1 < 90) {

      x_ang_1 -= 2;

      //delay(10);

    } else if (data.x_1 > 150) {

      x_ang_1 += 2;

      //delay(10);
    }

    if (data.y_1 < 100) {

      y_ang_1 -= 2;

      //delay(10);

    } else if (data.y_1 > 150) {

      y_ang_1 += 2;

      //delay(10);
    }

    if (data.x_2 < 100) {

      x_ang_2 -= 2;

      //delay(10);

    } else if (data.x_2 > 150) {

      x_ang_2 += 2;

      //delay(10);
    }
    //if statements to not let the user go into values past <0, and >180, so taht user input will always be reacted by servo.

    if (x_ang_1 < 0) {
      x_ang_1 = 0;
    } else if (x_ang_1 > 180) {
      x_ang_1 = 180;
    }

    if (y_ang_1 < 0) {
      y_ang_1 = 0;
    } else if (y_ang_1 > 180) {
      y_ang_1 = 180;
    }

    if (x_ang_2 < 0) {
      x_ang_2 = 0;
    } else if (x_ang_2 > 180) {
      x_ang_2 = 180;
    }




    //set the servos to that angle
    pwm.setPWM(servoOne, 0, ConvertAngleToPWMWidth(x_ang_1));
    pwm.setPWM(servoTwo, 0, ConvertAngleToPWMWidth(y_ang_1));
    pwm.setPWM(servoThree, 0, ConvertAngleToPWMWidth(x_ang_2));



    Serial.println(y_ang_1);
    delay(10);
    //delay(250); //Use this delay in setup so the robot doesn't kill itself or anyone else..
  }
}



int ConvertAngleToPWMWidth(int angle) {

  angle = map(angle, 0, 180, SERVOMIN, SERVOMAX);

  return angle;
}
