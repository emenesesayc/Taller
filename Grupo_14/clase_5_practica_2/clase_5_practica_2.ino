long d;
long t;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(8,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(9,LOW);
  delayMicroseconds(5);
  digitalWrite(9,HIGH);
  delayMicroseconds(10);
  digitalWrite(9,LOW);

  t = pulseIn(8,HIGH);
  d = int(t*0.017);
 
  }
  else {
    Serial.print(d);
    Serial.print("cm\n");
  }
  delay(1000);
  

  

}
