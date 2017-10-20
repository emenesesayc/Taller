#include <Servo.h>

Servo servoMotor;

int a;
int b;

void setup() {
  Serial.begin(9600);
  servoMotor.attach(9);
  servoMotor.writeMicroseconds(1500);

}

void loop() {
  a = analogRead(A0);
  b = map(a, 0, 1023, 25, 180);
  servoMotor.write(b);
  Serial.print("Posicion del potenciometro: ");
  Serial.print(a);
  Serial.print(", Angulo: ");
  Serial.print(b);
  Serial.print("\n");
  delay(200);
  
}
