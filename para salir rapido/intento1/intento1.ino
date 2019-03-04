#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define sensorTierra2 A1
#define sensorTierra1 A0
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define extractor 13
#define bombaAgua 11
//#define luzLED 12
//#define unoMas 10
DHT dht(DHTPIN, DHTTYPE);


/*BANDERAS*/
bool bienvenidaState = false;


void setup() {
  pinMode (extractor, OUTPUT);
  digitalWrite(extractor, LOW);
  //pinMode (luzLED, OUTPUT);
  //digitalWrite(luzLED, LOW);
  pinMode (bombaAgua, OUTPUT);
  digitalWrite(bombaAgua, LOW);
  //pinMode (unoMas, OUTPUT);
  //digitalWrite(unoMas, LOW);

  lcd.init();
  lcd.backlight();
  dht.begin();
}

void loop() {
  if (bienvenidaState == false) {
    bienvenida();
  }

  seleccionarEstadio();
  

  //ATUOMATICAS
  //FOTOPERIODO DE 20HS LUZ 4HS OSCURIDAD
  
  
}
