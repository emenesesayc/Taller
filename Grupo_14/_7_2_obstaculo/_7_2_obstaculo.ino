float d;
float t;

void setup() {
  // put your setup code here, to run once:
  /*rueda izquierda:
      5 adelante
      4 atras
      3 PWM
   */
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(3,OUTPUT);
  /*rueda derecha:
      8 adelante
      10 atras
      11 PWM
  */
  pinMode(8,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

  /*
    12 trig
    13 echo
   */
  pinMode(12,OUTPUT);
  pinMode(13,INPUT);



}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(12,LOW);
  delayMicroseconds(5);
  digitalWrite(12,HIGH);
  delayMicroseconds(10);
  digitalWrite(12,LOW);
  
  t = pulseIn(13,HIGH);
  d = int(t*0.017);
  Serial.println(d);
  
  if (d>60 || d<1){
    digitalWrite(8,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(3,255);
    analogWrite(11,255);
  }
  else if(d>30){
    digitalWrite(8,HIGH);
    digitalWrite(5,HIGH);
    analogWrite(3,100);
    analogWrite(11,100);
  }
  else if (d<30){
    analogWrite(3,0);
    analogWrite(11,0);
    digitalWrite(8,HIGH);
    digitalWrite(5,LOW);
    delay(1000);
    digitalWrite(8,HIGH);
    digitalWrite(4,HIGH);
    analogWrite(3,255);
    analogWrite(11,255);
    delay(500);
    digitalWrite(8,HIGH);
    digitalWrite(4,LOW);
    analogWrite(3,0);
    analogWrite(11,0);
    delay(1000);
  }


  delay(1000);

  
}
