#include <Servo.h>

//rojo: 5v
//cafe: gnd
//naranja: entrada desde arduino (9)

Servo servoMotor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servoMotor.attach(13);
  servoMotor.writeMicroseconds(1500);

}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 15; i<170; i+=1){
    servoMotor.write(i);
    delay(100);
  }
  for (int i = 170; i>15; i-=1){
    servoMotor.write(i);
    delay(100);
  }
}
