#include <I2CIO.h>
#include <LiquidCrystal_SR3W.h>
#include <LCD.h>
#include <LiquidCrystal_SR.h>
#include <FastIO.h>
#include <LiquidCrystal_SR2W.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <LCD.h>
#define I2C_ADDR 0x3F

String mensaje = "";

LiquidCrystal_I2C lcd(I2C_ADDR, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
void setup(){
  Serial.begin(9600);
  // put your setup code here, to run once:
  lcd.begin (16,2);
  for (int i = 0; i<3; i++){
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight();

  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available()>0){
    mensaje += char(Serial.read());
      
  }
  lcd.setCursor(0,1);
  lcd.print(mensaje);
  delay(1000);
  mensaje = "";
  lcd.clear();
}
    
  
    
  
  

