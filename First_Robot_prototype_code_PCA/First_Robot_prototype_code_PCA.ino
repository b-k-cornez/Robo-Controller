#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 150
#define SERVOMAX 600
#define SERVO_FREQ 50  //freq the servos run at

uint8_t servoOne = 0;  //the servo is connected at 0
uint8_t servoTwo = 1;
uint8_t servoThree = 2;
uint8_t servoFour = 3;

int const potPin = A3;
int const potPin2 = A2;
int const potPin3 = A1;
int const potPin4 = A0;
int angle1;
int angle2;
int angle3;
int angle4;
int potVal;





void setup() {
  // put your setup code here, to run once:
  pinMode(A3, INPUT); //1
  pinMode(A2, INPUT); //2
  pinMode(A1, INPUT); //3
  pinMode(A0, INPUT); //4
  //pinMode(13, OUTPUT);


  Serial.begin(9600);

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);

  digitalWrite(13,HIGH);

  delay(10);
}

void loop() {

  potVal = analogRead(A3);
  angle1 = map(potVal, 0, 1023, SERVOMIN, SERVOMAX);
  pwm.setPWM(servoOne, 0, angle1);

  potVal = analogRead(A2);
  angle2 = map(potVal, 0, 1023, SERVOMIN, SERVOMAX);
  pwm.setPWM(servoTwo, 0, angle2);

  potVal = analogRead(A1);
  angle3 = map(potVal, 0, 1023, SERVOMIN, SERVOMAX);
  pwm.setPWM(servoThree, 0, angle3);

  potVal = analogRead(A0);
  angle4 = map(potVal, 0, 1023, SERVOMIN, SERVOMAX);
  pwm.setPWM(servoFour, 0, angle4);
  


  delay(5);
}
