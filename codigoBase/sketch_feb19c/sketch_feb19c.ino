#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

/*******************DHT22************************/
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
#define sensorTierra1 A0
#define sensorTierra2 A1
#define extractor 13
#define luzLED 12
#define bombaAgua 11
#define unoMas 10
DHT dht(DHTPIN, DHTTYPE);
/*******************DHT22************************/

/****************************************BOTONES**********************************************/
const int  Up_buttonPin   = 3;    // the pin that the pushbutton is attached to
const int  Down_buttonPin = 4;
const int  Select_buttonPin = 5;
int buttonPushCounter = 0;   // counter for the number of button presses

int up_buttonState = 0;         // current state of the up button
int up_lastButtonState = 0;     // previous state of the up button

int select_buttonState = 0;
int select_lastButtonState = 0;

int down_buttonState = 0;         // current state of the up button
int down_lastButtonState = 0;     // previous state of the up button

bool bPress = false;
bool SPress = false;
/****************************************BOTONES************************************************/

bool hayEEPROM = true;/****************modo debug**********************/
bool bienvenidaState = false;
bool sinMacetas = true;
bool sinLitrosMacetas = true;
bool etapaPlantaStatus = false;
int cantidadMacetas = 0;
int cantLitrosMacetas = 0;
int etapaPlanta = 3;
String stringEtapaPlanta = "as";


String temperaturaLCD = "";
String humedadLCD = "";
int tempAhora = 0;
int humAhora = 0; 
int promTemps = 0;
int promHums = 0;

int humedadTierra1Ahora1 = 0;
int humedadTierra1Ahora2 = 0;
int promHumedadTierraAhora = 0;



/*****************************************************************************************/
/**********************************HUMEDADES Y TEMPERATURAS*******************************/
/*****************************************************************************************/

/**********************************HUMEDADES Y TEMPERATURAS PLANTIN*******************************/
int humedadMaxStandardPlantin = 70;
int humedadMinStandardPlantin = 65;
int humedadMaxUsuarioPlantin = 0;
int humedadMinUsuarioPlantin = 0;

int tempMaxStandardPlantin = 25;
int tempMinStandardPlantin = 20;
int tempMaxUsuarioPlantin = 0;
int tempMinUsuarioPlantin = 0;

/**********************************HUMEDADES Y TEMPERATURAS VEGETATIVO*******************************/
int humedadMaxStandardVege = 70;
int humedadMinStandardVege = 40;
int humedadMaxUsuarioVege = 0;
int humedadMinUsuarioVege = 0;

int tempMaxStandardVege = 28;
int tempMinStandardVege = 22;
int tempMaxUsuarioVege = 0;
int tempMinUsuarioVege = 0;


/**********************************HUMEDADES Y TEMPERATURAS FLORACION*******************************/
int humedadMaxStandardFlora = 50;
int humedadMinStandardFlora = 40;
int humedadMaxUsuarioFlora = 0;
int humedadMinUsuarioFlora = 0;

int tempMaxStandardFlora = 26;
int tempMinStandardFlora = 20;
int tempMaxUsuarioFlora = 0;
int tempMinUsuarioFlora = 0;


/**********************************HUMEDADES Y TEMPERATURAS FLORA TARDIA*******************************/
int humedadMaxStandardFloraT = 40;
int humedadMinStandardFloraT = 30;
int humedadMaxUsuarioFloraT = 0;
int humedadMinUsuarioFloraT = 0;

int tempMaxStandardFloraT = 24;
int tempMinStandardFloraT = 18;
int tempMaxUsuarioFloraT = 0;
int tempMinUsuarioFloraT = 0;

/*****************************************************************************************/
/******************************FIN HUMEDADES Y TEMPERATURAS*******************************/
/*****************************************************************************************/

/*****************************************************************************************/
/***************************************VOID LOOP*****************************************/
/*****************************************************************************************/

void setup() {
  Serial.begin(9600);
  pinMode( Up_buttonPin , INPUT_PULLUP);
  pinMode( Down_buttonPin , INPUT_PULLUP);
  pinMode( Select_buttonPin , INPUT_PULLUP);
  pinMode(sensorTierra1, INPUT);
  pinMode(sensorTierra2, INPUT);

  pinMode (extractor, OUTPUT);
  digitalWrite(extractor, LOW);
  pinMode (luzLED, OUTPUT);
  digitalWrite(luzLED, LOW);
  pinMode (bombaAgua, OUTPUT);
  digitalWrite(bombaAgua, LOW);
  pinMode (unoMas, OUTPUT);
  digitalWrite(unoMas, LOW);
  
  lcd.init();
  lcd.backlight();
  dht.begin();
}
/*****************************************************************************************/
/***************************************VOID SETUP*****************************************/
/*****************************************************************************************/

/*****************************************************************************************/
/***************************************VOID LOOP*****************************************/
/*****************************************************************************************/
void loop() {

  /***********************BIENVENIDA*************************/
  if (bienvenidaState == false) {
    bienvenida();
  }

  while (hayEEPROM == false) { //chequear si hay datos almacenados en EEPROM
    /***********************CANTIDAD DE MACETAS*************************/
    if (sinMacetas == true) {
      sinMacetas = false;
      int cantidadMacetas = cantidadDeMacetas();
      lcd.clear();
      lcd.print("Guardado M!");
      delay(1500);
    }
    /***********************LITROS DE LAS MACETAS*************************/
    if (sinLitrosMacetas == true) {
      sinLitrosMacetas = false;
      int cantLitrosMacetas = litrosMacetas();
      lcd.clear();
      lcd.print("Guardado L!");
      delay(1500);
    }
    /***********************ETAPAS DE LAS PLANTAS*************************/
    if (etapaPlantaStatus == false) {
      etapaPlantaStatus = true;
      int etapaPlanta = etapaDePlanta();
      if (etapaPlanta == 1) {
        String stringEtapaPlanta = "Plantin";
        Serial.println(stringEtapaPlanta);
        Serial.println(etapaPlanta);
        lcd.clear();
        lcd.print(stringEtapaPlanta);
        delay(1500);
      }
      if (etapaPlanta == 2) {
        String stringEtapaPlanta = "Vegetativo";
        Serial.println(stringEtapaPlanta);
        Serial.println(etapaPlanta);
        lcd.clear();
        lcd.print(stringEtapaPlanta);
        delay(1500);
      }
      if (etapaPlanta == 3) {
        String stringEtapaPlanta = "Floracion";
        Serial.println(stringEtapaPlanta);
        Serial.println(etapaPlanta);
        lcd.clear();
        lcd.print(stringEtapaPlanta);
        delay(1500);
      }
      if (etapaPlanta == 4) {
        String stringEtapaPlanta = "Floracion T";
        Serial.println(stringEtapaPlanta);
        Serial.println(etapaPlanta);
        lcd.clear();
        lcd.print(stringEtapaPlanta);
        delay(1500);
      }
    }
    hayEEPROM = true;
  }
  /***********************************SENSAR TEMPERATURA Y HUMEDAD // MOSTRARLAS***************************************/

  sensarTempYHumAire();
  sensarHumMacetas();

  hayQueRegar();
  
  /*int tempAhora = sensarTemperatura();
  mostrarTemperatura(tempAhora);
  
  int humAhora = sensarHumedad();
  mostrarHumedad(humAhora);*/

  /***********************************SENSAR TEMPERATURA Y HUMEDAD // MOSTRARLAS***************************************/

  /***********************************SENSAR HUMEDAD EN TIERRA***************************************/

  /*int humedadTierra1Ahora1 = sensarTierra1();
  int humedadTierra1Ahora2 = sensarTierra2();*/

  /***********************************SENSAR HUMEDAD EN TIERRA***************************************/
}
/*****************************************************************************************/
/******************************************VOID LOOP**************************************/
/*****************************************************************************************/



/*****************************************************************************************/
/************************************FUNCIONES********************************************/
/*****************************************************************************************/


void hayQueRegar(){
  if(promHumedadTierraAhora >= 700){
    digitalWrite(bombaAgua, HIGH);
    Serial.println("Regando..");
    lcd.clear();
    lcd.print("Regando...");
    delay(10500);
    digitalWrite(bombaAgua, LOW);
  }
  else{
    Serial.println("Tierra humeda");
  }
}



int sensarHumMacetas(){
  int humedadTierra1Ahora1 = sensarTierra1();
  int humedadTierra1Ahora2 = sensarTierra2();
  promHumedadTierraAhora = (humedadTierra1Ahora1 + humedadTierra1Ahora2) /2;
  Serial.println(promHumedadTierraAhora);
  return promHumedadTierraAhora;
}


int sensarTierra1(){
  int valorHumedad1 = analogRead(sensorTierra1);
  Serial.print(F("Humedad1: "));
  Serial.print(valorHumedad1);
  Serial.println("%");
  return valorHumedad1;
}

int sensarTierra2(){
  int valorHumedad2 = analogRead(sensorTierra2);
  Serial.print(F("Humedad2: "));
  Serial.print(valorHumedad2);
  Serial.println("%");
  return valorHumedad2;
}


/*********************************MOSTRAR TEMPERATURA**********************************************/
void mostrarTemperatura(int valor){
  String temperaturaLCD = (String)"Temp: "+ valor + "C";
  lcd.setCursor(0,0);
  lcd.print(temperaturaLCD);
}
/*********************************MOSTRAR TEMPERATURA**********************************************/

/*********************************MOSTRAR HUMEDAD**********************************************/
void mostrarHumedad(int valor){
  String humedadLCD = (String)"Humedad: "+ valor + "%";
  lcd.setCursor(0,1);
  lcd.print(humedadLCD);
}
/*********************************MOSTRAR HUMEDAD**********************************************/

/*********************************SENSAR TEMPERATURA**********************************************/


int sensarTempYHumAire(){
  int tempAhora = sensarTemperatura();
  mostrarTemperatura(tempAhora);
  
  int humAhora = sensarHumedad();
  mostrarHumedad(humAhora);  
}

int sensarTemperatura(){
  delay(1500);
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Temperatura: "));
  Serial.println(t);  

  return t;
}
/*********************************SENSAR TEMPERATURA**********************************************/

/*********************************SENSAR HUMEDAD**********************************************/
int sensarHumedad(){
  delay(1500);
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.println(h);

  return h;
}
/*********************************SENSAR HUMEDAD**********************************************/

/*********************************ETAPA DE PLANTA**********************************************/
int etapaDePlanta() {
  lcd.clear();
  lcd.print("1.Plantin 2.Vege");
  lcd.setCursor(0, 1);
  lcd.print("3.Flora 4.FloraT");
  etapaPlanta = botones();
  return etapaPlanta;
}
/*********************************ETAPA DE PLANTA**********************************************/

/*********************************LITROS MACETAS**********************************************/
int litrosMacetas() {
  lcd.clear();
  lcd.print("Litros Macetas?");
  int cantLitrosMacetas = botones();
  return cantLitrosMacetas;
}
/*********************************LITROS MACETAS**********************************************/

/*********************************CANTIDAD MACETAS**********************************************/
int cantidadDeMacetas() {
  lcd.clear();
  lcd.print("CantidadMacetas?");
  int cantidadMacetas = botones();
  sinMacetas == false;

  return cantidadMacetas;
}
/*********************************CANTIDAD MACETAS**********************************************/

/*********************************BIENVENIDOS**********************************************/
void bienvenida() {
  lcd.clear();
  lcd.print("***PLANTATE!!***");
  bienvenidaState = true;
  delay(1000);
  lcd.clear();
}
/*********************************BIENVENIDOS**********************************************/


/*********************************BOTONERA**********************************************/
int botones() {
  SPress = false;
  do {
    checkUp();
    checkDown();
    checkSelect();

    if (bPress == true) {
      bPress = false;
      lcd.setCursor(2, 1);
      lcd.print("               ");
      lcd.setCursor(2, 1);
      lcd.print(buttonPushCounter);
      //imprimir en pantalla la cantidad
    }
  } while (SPress == false);
  return buttonPushCounter;
}
/*********************************BOTONERA**********************************************/

/*****************************************************************************************/
/**************************************CONFIGURACION BOTONES******************************/
/*****************************************************************************************/

void checkSelect() {
  select_buttonState = digitalRead(Select_buttonPin);

  // compare the buttonState to its previous state
  if (select_buttonState != select_lastButtonState) {
    // if the state has changed, increment the counter
    if (select_buttonState == LOW) {
      SPress = true;
      // if the current state is HIGH then the button went from off to on:
      Serial.println("on");

    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  select_lastButtonState = select_buttonState;
}

void checkUp()
{
  up_buttonState = digitalRead(Up_buttonPin);

  // compare the buttonState to its previous state
  if (up_buttonState != up_lastButtonState) {
    // if the state has changed, increment the counter
    if (up_buttonState == LOW) {
      bPress = true;
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  up_lastButtonState = up_buttonState;
}
void checkDown()
{
  down_buttonState = digitalRead(Down_buttonPin);

  // compare the buttonState to its previous state
  if (down_buttonState != down_lastButtonState) {
    // if the state has changed, increment the counter
    if (down_buttonState == LOW) {
      bPress = true;
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter--;

      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  down_lastButtonState = down_buttonState;
}
