int sensarTierra1() {
  int contadorRafagaTierra1 = 0;
  int sumaLecturasRafagaTierra1 = 0;
  int promLecturaRafaga1 = 0;

  for (contadorRafagaTierra1 = 0; contadorRafagaTierra1 < 3; contadorRafagaTierra1++) {
    //contadorRafagaTierra1++;
    int valorHumedad1 = analogRead(sensorTierra1);
    Serial.print(F("Humedad1: "));
    Serial.print(valorHumedad1);
    Serial.println("%"); 
    sumaLecturasRafagaTierra1 += valorHumedad1;
    promLecturaRafaga1 = sumaLecturasRafagaTierra1 /4;
    delay(3000);
  }
  Serial.println(promLecturaRafaga1);
  return promLecturaRafaga1;
}
