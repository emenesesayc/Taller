#include <Key.h>
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {13, 12, 11, 10}; 
byte colPins[COLS] = {9, 8, 7, 6};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int nose = 0;
int num;

void setup(){
   Serial.begin(9600);
   lcd.init();
   lcd.backlight();
   delay(1000);
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
    if (nose == 0){
      num = int(key);
      nose = 1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(key);
      lcd.setCursor(1,0);
      lcd.print("+");
    }
    else {
      lcd.setCursor(2,0);
      lcd.print(key);
      lcd.setCursor(3,0);
      lcd.print("=");
      lcd.setCursor(4,0);
      lcd.print(int(key)+num-96);
      nose = 0;      
    }
    
  }
}
