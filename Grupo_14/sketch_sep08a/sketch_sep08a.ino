void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,INPUT);
  pinMode(12,OUTPUT);
  Serial.print("Calibrando");
  for (int i = 0; i<60; i++){
    Serial.print(".");
    delay(1000);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(13)==1){
    Serial.println("Alguien se mueve");
    digitalWrite(12,HIGH);
  }
  else {
    Serial.println("No se percibe movimiento");
    digitalWrite(12,LOW);
  }
  

}
