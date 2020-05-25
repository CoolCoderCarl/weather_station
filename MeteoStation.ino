#include "dht.h"
#define dht_apin A0

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

dht DHT;

void setup() {

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Temp:  Humidity:");

}

void loop() {

  DHT.read11(dht_apin);

  lcd.setCursor(0, 1);
  lcd.print(DHT.temperature);
  lcd.print("C ");
  
  lcd.setCursor(10, 1);
  lcd.print(DHT.humidity);
  lcd.print("%  ");

  delay(500);

}
