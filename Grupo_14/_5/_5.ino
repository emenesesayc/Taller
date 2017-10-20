int aumento = 1;
int retraso = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i<256; i+=aumento){
    analogWrite(11,255-i);
    analogWrite(10,i);
    delay(retraso);
  }
  for (int i = 0; i<256; i+=aumento){
    analogWrite(10,255-i);
    analogWrite(9,i);
    delay(retraso);
  }
  for (int i = 0; i<256; i+=aumento){
    analogWrite(9,255-i);
    analogWrite(11,i);
    delay(retraso);
  }
        



}
