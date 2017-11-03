void setup() {
  // put your setup code here, to run once:
  /*rueda izquierda:
      5 adelante
      4 atras
   */
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  /*rueda derecha:
      8 adelante
      10 atras
  */
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);

  for (int i = 0; i<4;i++){
    digitalWrite(8,HIGH);
    digitalWrite(5,HIGH);
    delay(1000);
    digitalWrite(5,LOW);
    digitalWrite(8,LOW);
    delay(1000);
    digitalWrite(8,HIGH);
    digitalWrite(4,HIGH);
    delay(536);
    digitalWrite(8,LOW);
    digitalWrite(4,LOW);
    delay(1000);

  }

}

void loop() {
  // put your main code here, to run repeatedly:
  
}
