int a = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(10,INPUT);
  pinMode(11,OUTPUT);
  

}

void loop() {
  if (digitalRead(10)==1){
    digitalWrite(11,LOW);
  }
  else{
    digitalWrite(11,HIGH);
  }
  // put your main code here, to run repeatedly:
  

}
