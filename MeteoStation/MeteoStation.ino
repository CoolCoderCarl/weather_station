#include "dht.h"
#define dht_apin A0

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

dht DHT;

const int blueLED = 8;
const int redLED = 9;

const int maxT = 25;
const int minT = 20;

void setup() {

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Temp:  Humidity:");

  pinMode(blueLED, OUTPUT);
  pinMode(blueLED, LOW);

  pinMode(redLED, OUTPUT);
  pinMode(redLED, LOW);
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

  if(DHT.temperature >= maxT){
    digitalWrite(redLED, HIGH);
    digitalWrite(blueLED, LOW);
  }
  else if(DHT.temperature <= minT){
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, HIGH);
  }
  else if((DHT.temperature < maxT) && (DHT.temperature > minT)){
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, LOW);
  }
}
