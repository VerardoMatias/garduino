int mostrarTempHumInicial() {
  mostrarTempHumInicialState = true;
  tempAhora = sensarTemperatura();
  humAhora = sensarHumedad();

  mostrarTemperatura(tempAhora);
  mostrarHumedad(humAhora);
}
