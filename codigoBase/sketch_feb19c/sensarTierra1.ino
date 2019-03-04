int sensarTierra1() {
  int valorHumedad1 = analogRead(sensorTierra1);
  Serial.print(F("Humedad1: "));
  Serial.print(valorHumedad1);
  Serial.println("%");
  return valorHumedad1;
}
