#include<SmartInventor.h>
int speed = 50;
int speedMeterL = 13;
int speedMeterR = 16;
void setup() {
  SmartInventor.DCMotorUse();
  SmartInventor.TVRemoconUse();
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
pinMode(14, OUTPUT);
pinMode(15, OUTPUT);
pinMode(16, OUTPUT);
pinMode(17, OUTPUT);
pinMode(18, OUTPUT);
digitalWrite(13, HIGH);
digitalWrite(14, HIGH);
digitalWrite(15, HIGH);
digitalWrite(16, HIGH);
}
void loop() {
  int keyData = SmartInventor.TVRemoconData();
  if(keyData == KEY_U)
  { SmartInventor.DCMotor(M1,CCW,speed);
    SmartInventor.DCMotor(M2,CCW,speed);
  }
  else if(keyData == KEY_L)
  {
SmartInventor.DCMotor(M1,CCW,speed);
SmartInventor.DCMotor(M2,CCW,speed);
  }
  else if(keyData == KEY_R)
  {
    SmartInventor.DCMotor(M1, CW, speed); SmartInventor.DCMotor(M2,CCW,speed);
  }
  else if (keyData == KEY_D)
  { SmartInventor.DCMotor(M1,CW,speed);
    SmartInventor.DCMotor(M2, CCW, speed);
  }
  else if(keyData == KEY_C)
  { SmartInventor.DCMotor(M1,CCW, 127);   SmartInventor.DCMotor(M2,CW,127);
  }
  else
{
  SmartInventor.DCMotor(M1, LOOSE,0);
  SmartInventor.DCMotor(M2, LOOSE, 0);
}
if(keyData == KEY_F1)
{
  if(speed <90)
  {
    speed = speed + 20;
    speedMeterL = speedMeterL - 1;
    speedMeterR = speedMeterR + 1;

    digitalWrite(speedMeterL, HIGH);
    digitalWrite(speedMeterR, HIGH);

    SmartInventor.Buzz(1160,2);
    delay(150);
  }
}
else if(keyData == KEY_F2)
{
  if(speed>30)
  {
    speed = speed - 20;
    digitalWrite(speedMeterL, LOW);
    digitalWrite(speedMeterR, LOW);
    speedMeterL = speedMeterL+1;
    speedMeterR = speedMeterR - 1;
    SmartInventor.Buzz(1160, 12);
    delay(150);
  }
}
 
 
