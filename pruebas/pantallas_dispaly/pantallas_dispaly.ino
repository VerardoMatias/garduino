/************************* Conexiones a display
 * SCL a A5
 * SDA a A4
*/
#include "DHT.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Inicia el LCD en la dirección 0x27, con 16 caracteres y 2 líneas

#define botonUp = 2;
#define botonDown = 3;
#define botonSelec = 4;
#define botonBack = 5;
#define DHTPIN 5
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
int cantidadMacetas = 0;
int litrosMacetas = 0;

void setup() {

  pinMode(2, INPUT);  //botonUp
  pinMode(3, INPUT);  //botonDown
  pinMode(4, INPUT);  //botonSelec
  pinMode(5, INPUT);  //botonBack

  lcd.backlight();
  lcd.init();
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
  
}

void loop() {

  //lcd.clear();
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  lcd.clear();
  lcd.print("Humedad: ");
  lcd.print(h);
  //lcd.setCursor(0,1);
  //lcd.print(h);
  lcd.print("Temperatura: ");
  lcd.print(t);
  
  //lcd.print(t);

  
  
 /* lcd.print("Cantidad macetas?");
  delay(5000);
  //Llamar funcion cantidad de macetas
  lcd.clear();
  
  lcd.print("Litros macetas?");
  delay(5000);
  //Llamar funcion litros macetas
  lcd.clear();
  
  lcd.print("Etapa plantas?");  
  lcd.setCursor(0,1);
  lcd.print("Flora");
  lcd.setCursor(7,1);
  lcd.print("Vege");
  delay(5000);
  lcd.clear();*/

  
  

  

  
  /*lcd.setCursor(0,1);
  lcd.print("GATO");*/
  
}
