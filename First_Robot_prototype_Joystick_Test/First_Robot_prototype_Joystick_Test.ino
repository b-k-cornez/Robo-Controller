#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define UMIN 600 //min and max pulse lengths
#define UMAX 2400
#define MIN_VAL 0
#define MAX_VAL 1023
#define SERVO_FREQ 50  //freq the servos run at

#define VRy A1 //pins for x and y of joystick
#define VRx A0


//angles
int x_angle = 90;
int y_angle = 90;

uint8_t servoOne = 0;
uint8_t servoTwo = 1;


void setup() {

  Serial.begin(9600);

  pinMode(7, INPUT);

  digitalWrite(13,HIGH);

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);

  pwm.setPWM(servoOne, 0, 10);
  pwm.setPWM(servoTwo, 0, 10);

  digitalWrite(2,HIGH); //???

  delay(10);
}

void loop() {

  // potVal = analogRead(VRx);
  // angle = map(potVal, 0, 1023, 600, 2400);

  int joystick_x_value = analogRead(VRx);
  int joystick_y_value = analogRead(VRy);

  if (joystick_x_value < 340){

    x_angle -= 2;

    delay(10);

  } else if (joystick_x_value > 680) {

    x_angle += 2;

    delay(10);
  }

  if (joystick_y_value < 340){

    y_angle -=2;

    delay(10);

  } else if (joystick_y_value > 680){

    y_angle += 2;

    delay(10);
  } 

  pwm.setPWM(servoOne, 0, x_angle);
  pwm.setPWM(servoTwo, 0, y_angle);

  Serial.println(joystick_x_value);

// if (def<1495) {



//   pwm.writeMicroseconds(servoOne, 600);

// } else if (def>1495){

//   pwm.writeMicroseconds(servoOne, 2400);https://forum.arduino.cc/t/servo-holding-position/352592/9
// }

/*so i want to increase decrease it for as long as i hold the direction

*/



// else if (potVal == 509){

// ;

// }



  // angle1 = map(potVal, 0, 1023, SERVOMIN, SERVOMAX);
  



  // pwm.setPWM(servoOne, 0, angle1);


 


}
