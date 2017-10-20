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
#define I2C_ADDR 0x27

String tiempo;
int minuto = 0;
String minuto2;
String sec;
int integrantes = 0;

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
  lcd.setCursor(0,0);
  if (integrantes == 0){
    lcd.write("Diego Carmona");
  }
  else if (integrantes == 1){
    lcd.write("Andrea Mancilla");  
  }
  else if (integrantes == 2){
    lcd.write("Enzo Meneses");
  }
  else {
    lcd.write("Leo Rodriquez");
  }

  lcd.setCursor(0,1);
  lcd.write("Tiempo");

  for (int i = 0; i < 32; i++){
    delay(200);
    sec = String(i%60);
    if (sec.length()==1){
      sec = "0" + sec;
    }
    minuto2 = String(minuto);
    tiempo = minuto2 + ":" + sec;
    lcd.setCursor(12,1);
    lcd.print(tiempo);
    if (sec == "59"){
      minuto++;
    
    }
    
  }
  integrantes = (integrantes +1)%4;
  lcd.clear();

 
  


}
    
  
    
  
  

