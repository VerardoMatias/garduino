int sensarTierra2() {
  int contadorRafagaTierra2 = 0;
  int sumaLecturasRafagaTierra2 = 0;
  int promLecturaRafaga2 = 0;

  for (contadorRafagaTierra2 = 0; contadorRafagaTierra2 < 3; contadorRafagaTierra2++) {
    //contadorRafagaTierra2++;
    int valorHumedad2 = analogRead(sensorTierra2);
    Serial.print(F("Humedad2: "));
    Serial.print(valorHumedad2);
    Serial.println("%");
    sumaLecturasRafagaTierra2 += valorHumedad2;
    promLecturaRafaga2 = sumaLecturasRafagaTierra2 / 4;
    delay(3000);
  }
  Serial.println(promLecturaRafaga2);
  return promLecturaRafaga2;
}
