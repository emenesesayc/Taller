void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(4,HIGH);
  analogWrite(9,255);
  delay(2000);
  analogWrite(9,200);
  delay(2000);
  analogWrite(9,150);
  delay(2000);
  analogWrite(9,100);
  delay(2000);
  analogWrite(9,50);
  delay(2000);
  analogWrite(9,0);
  delay(2000);

  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  analogWrite(9,255);
  delay(2000);
  analogWrite(9,200);
  delay(2000);
  analogWrite(9,150);
  delay(2000);
  analogWrite(9,100);
  delay(2000);
  analogWrite(9,50);
  delay(2000);
  analogWrite(9,0);
  delay(2000);
  digitalWrite(5,LOW);

}
