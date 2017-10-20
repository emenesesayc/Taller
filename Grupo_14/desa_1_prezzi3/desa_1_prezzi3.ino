
void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  for(int i = 0 ;i<255; i+=10){
    analogWrite(9,i);
    analogWrite(10,i);
    analogWrite(11,i);

    delay(100);
  }
  // put your main code here, to run repeatedly:

}
