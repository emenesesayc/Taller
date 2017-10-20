long d;
long t;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(8,INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

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
  if (d>300 || d<2){
    Serial.println("No se detectan objetos");  
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    d=300;
  }
  else if (d<100){
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
  }
  else {
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
  }
  delay(1000);
  
}
