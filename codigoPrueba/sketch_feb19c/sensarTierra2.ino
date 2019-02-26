int sensarTierra2() {
  int valorHumedad2 = analogRead(sensorTierra2);
  Serial.print(F("Humedad2: "));
  Serial.print(valorHumedad2);
  Serial.println("%");
  return valorHumedad2;
}
