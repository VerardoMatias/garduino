int checkTemp() {
  for (int i = 0; i < 4; i++) {
    int valorT = sensarTemperatura();
    sumaDeTemps += valorT;
  }
  promDeTemps = sumaDeTemps / 4;
  Serial.println(promDeTemps);
  tomaDecisionesTemp();
  sumaDeTemps = 0;
  mostrarTemperatura(promDeTemps);
}
