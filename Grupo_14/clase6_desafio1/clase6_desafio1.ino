int f=1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT );

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Valor Frecuencia: ");
  Serial.print(f);
  Serial.print(" Hz \n");
  for (float i = 0; i<5; i+=float(1.0/f)){
    digitalWrite(13,HIGH);
    delay(float(500/f));
    digitalWrite(13,LOW);
    delay(float(500/f));
  }
  f+=2;
   

}
