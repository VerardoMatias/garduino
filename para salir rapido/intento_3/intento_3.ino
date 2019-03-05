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
#define caloventor 12
#define bombaAgua 11
#define humidificador 10
DHT dht(DHTPIN, DHTTYPE);

/*ESTADO APARATOS RELAY*/
bool estadoExtractor = false;
bool estadoCaloventor = false;
bool estadoBombaAgua = false;
bool estadoHumidificador = false;


/****************************************BOTONES**********************************************/
const int  Up_buttonPin   = 3;    // the pin that the pushbutton is attached to
const int  Down_buttonPin = 4;
const int  Select_buttonPin = 5;
int buttonPushCounter = 0;   // counter for the number of button presses

/*****UP*****/
int up_buttonState = 0;         // current state of the up button
int up_lastButtonState = 0;     // previous state of the up button

/*****SELECT*****/
int select_buttonState = 0;
int select_lastButtonState = 0;

/*****DOWN*****/
int down_buttonState = 0;         // current state of the up button
int down_lastButtonState = 0;     // previous state of the up button

bool bPress = false;//cambia de valor cuando se presiona UP o DOWN
bool SPress = false;//cambia de valor cuando se presiona SELECT

/**************************BANDERAS*****************************/
bool hayEEPROM = false;/***modo debug*** false para pasar por configuracion de usuario, true para ver hum y temp******************************************************************************************************************/
bool bienvenidaState = false;
bool mostrarTempHumInicialState = false;
bool sinMacetas = true;
bool sinLitrosMacetas = true;

/*INICIALIZO VARIABLES DEFAULT PARA QUE INGRESE EL USUARIO*/
bool etapaPlantaStatus = false;
int cantidadMacetas, cantLitros, etapaPlanta = 0 ;
String stringEtapaPlanta = "" ;
String stringCantidadMacetas = "" ;
String stringCantLitros = "" ;

/*DATOS TEMPERATURA*/
String temperaturaLCD, humedadLCD = "";
int tempAhora, humAhora, promTemps, promHums = 0;

/*DATOS TIERRA*/
int humedadTierra1Ahora1, humedadTierra1Ahora2, promHumedadTierraAhora = 0;
int contadorChequearTierra = 0;
int contadorLecturas = 0;
int humedadTierraHist1 = 0;
int humedadTierraHist2 = 0;
int promHumSensores = 0;

/*DATOS EEPROM*/
int espaciosMemoria = 0;

/**********************************MINIMA Y MAXIMA PARA PLANTIN*******************************/
/*DEFAULT*/
const int humedadMaxStandardPlantin = 70;
const int humedadMinStandardPlantin = 65;
const int tempMaxStandardPlantin = 24;/*25*/
const int tempMinStandardPlantin = 22;/*20*/

/*USUARIO*/
int humedadMaxUsuarioPlantin, humedadMinUsuarioPlantin, tempMaxUsuarioPlantin, tempMinUsuarioPlantin = 0;

/**********************************MINIMA Y MAXIMA PARA VEGETATIVO*******************************/
/*DEFAULT*/
const int humedadMaxStandardVege = 60;
const int humedadMinStandardVege = 50;
const int tempMaxStandardVege = 26;/*28*/
const int tempMinStandardVege = 24;/*22*/

/*USUARIO*/
int humedadMaxUsuarioVege, humedadMinUsuarioVege, tempMaxUsuarioVege, tempMinUsuarioVege = 0;

/**********************************MINIMA Y MAXIMA PARA FLORACION*******************************/
/*DEFAULT*/
const int humedadMaxStandardFlora = 50;
const int humedadMinStandardFlora = 40;
const int tempMaxStandardFlora = 24;/*26*/
const int tempMinStandardFlora = 22;/*20*/

/*USUARIO*/
int humedadMaxUsuarioFlora, humedadMinUsuarioFlora, tempMaxUsuarioFlora, tempMinUsuarioFlora = 0;

/**********************************MINIMA Y MAXIMA PARA FLORA TARDIA*******************************/
/*DEFAULT*/
const int humedadMaxStandardFloraT = 40;
const int humedadMinStandardFloraT = 30;
const int tempMaxStandardFloraT = 22;/*24*/
const int tempMinStandardFloraT = 20;/*18*/

/*USUARIO*/
int humedadMaxUsuarioFloraT, humedadMinUsuarioFloraT, tempMaxUsuarioFloraT, tempMinUsuarioFloraT = 0;

/*VARIABLES A USAR COMO VALIDAS PARA MANTENER EL CLIMA*/
int humMaxAUsar, humMinAUsar, tempMaxAUsar, tempMinAUsar = 0;

/*SEGUNDOS QUE ACTIVO BOMBA DE RIEGO*/
int segundosBombaAguaActivada = 0;

/*SUMAS Y PROMEDIO DE TEMPS Y HUMS*/
int sumaDeTemps, sumaDeHums, promDeTemps, promDeHums = 0;



void setup() {
  Serial.begin(9600);

  /*BOTONES*/
  pinMode( Up_buttonPin , INPUT_PULLUP);
  pinMode( Down_buttonPin , INPUT_PULLUP);
  pinMode( Select_buttonPin , INPUT_PULLUP);

  /*SENSORES TIERRA*/
  pinMode(sensorTierra1, INPUT);
  pinMode(sensorTierra2, INPUT);

  /*RELES*/
  pinMode (extractor, OUTPUT);
  digitalWrite(extractor, LOW);
  pinMode (caloventor, OUTPUT);
  digitalWrite(caloventor, LOW);
  pinMode (bombaAgua, OUTPUT);
  digitalWrite(bombaAgua, LOW);
  pinMode (humidificador, OUTPUT);
  digitalWrite(humidificador, LOW);

  /*CONFIGURACIONES BASICAS*/
  lcd.init();
  lcd.backlight();
  dht.begin();
}

void loop() {
  /***********************BIENVENIDA*************************/
  if (bienvenidaState == false) {
    bienvenida();
  }

  /*****************CHEQUEO DATOS DE EEPROM********************/
  if (hayEEPROM == true) { //chequear si hay datos almacenados en EEPROM
    int cantidadMacetas = cantidadDeMacetas();
    int cantLitrosMacetas = litrosMacetas();
    int etapaPlanta = etapaDePlanta();
    hayEEPROM = true;
    mostrar(cantidadMacetas, cantLitrosMacetas, etapaPlanta);
    setearValores();
  }
  /**********MUESTRO VALORES AL INICIAR***********/
  if (mostrarTempHumInicialState == false) {
    mostrarTempHumInicial();
  }
  /*****************BUCLE CORE*****************/
  checkTemp();
  checkHum();
  if (contadorChequearTierra == 1) {
    checkTierra();
  }
  contadorChequearTierra++;


}
