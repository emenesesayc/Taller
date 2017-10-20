void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(12,HIGH);
  delay(5000);
  digitalWrite(12,LOW);
  digitalWrite(7,HIGH);
  delay(8000);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  delay(2000);
  digitalWrite(8,LOW);

}
