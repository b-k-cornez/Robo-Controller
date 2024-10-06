#include <SoftwareSerial.h>
#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define UMIN 500 //min and max pulse lengths
#define UMAX 2500
#define MIN_VAL 0
#define MAX_VAL 1023
#define SERVO_FREQ 50

int x_angle = 45;
int y_angle = 45;

uint8_t servoOne = 0;
uint8_t servoTwo = 1;

int state;

void setup() {
  Serial.begin(9600);

  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);

  //pwm.setPWM(servoOne, 0, 10);
  //pwm.setPWM(servoTwo, 0, 10);

  delay(10);
}

void loop() {
Serial.println(state);
  while (Serial.available() > 0) {

    state = Serial.read(); // Reads the data from the serial port
    
    delay(15);

    if (state == 5){ //UP

      y_angle += 1;
      delay(10);
    }

    if (state == 2){ //DOWN

      y_angle -= 1;
      delay(10);
    }

    if (state == 3){ //RIGHT

      x_angle -= 1;
      delay(10);
    }

    if (state == 4){ //LEFT

      x_angle += 1;
      delay(10);

    }


  pwm.setPWM(servoOne, 0, x_angle);
  pwm.setPWM(servoTwo, 0, y_angle);
    
  }
  
}

  public int RemapAngleToPWM
  {

    
  }
