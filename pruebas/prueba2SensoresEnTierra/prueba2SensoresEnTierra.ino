#define sensor1 A2
#define sensor2 A3

void setup() {
  // put your setup code here, to run once:
pinMode(sensor1, INPUT);
pinMode(sensor2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int valorHumedad1 = analogRead(sensor1);
  int valorHumedad2 = analogRead(sensor2);
  
  Serial.print("Humedad1: ");
  Serial.print(valorHumedad1);
  Serial.println("%");

  Serial.print("Humedad2: ");
  Serial.print(valorHumedad2);
  Serial.println("%");
 
  delay(2000);
}
