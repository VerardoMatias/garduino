int checkHum() {
  for (int i = 0; i < 4; i++) {
    int valorH = sensarHumedad();
    sumaDeHums += valorH;
  }
  promDeHums = sumaDeHums / 4;
  Serial.println(promDeHums);
  tomaDecisionesHum();
  sumaDeHums = 0;
  mostrarHumedad(promDeHums);
}
