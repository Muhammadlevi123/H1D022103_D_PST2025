#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int SDA_pin = D3;
int SCL_pin = D4;


void setup() {
  
  Wire.begin(SDA_pin, SCL_pin);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Shubuh : 06.40");
  lcd.setCursor(0,1);
  lcd.print("Astagfirulllah!");
}

void loop() {
  
  lcd.scrollDisplayLeft();
  delay(500);
}

