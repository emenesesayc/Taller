#include <dht.h>

dht DHT;
# define DHT11_PIN 8

int chk;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("inicio");

}

void loop() {
  // put your main code here, to run repeatedly:
  chk = DHT.read11(DHT11_PIN);
  Serial.println("  La Humedad es:  ");
  Serial.println(DHT.humidity, 1);
  Serial.println(" La Temperatura es");
  Serial.println(DHT.temperature, 1);
  delay(2000);
    

}
