#include <dht.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

dht DHT;
# define DHT11_PIN 2

int chk;
float t;
float h;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("Humedad:");
  lcd.setCursor(0,1);
  lcd.print("Temp:");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(12,0);
  lcd.print(DHT.humidity, 1);
  lcd.setCursor(12,1);
  lcd.print(DHT.temperature, 1);
   Serial.println(" Humidity ");
  Serial.println(DHT.humidity, 1);
  Serial.println(" Temperature ");
  Serial.println(DHT.temperature, 1);
  delay(2000);

}
