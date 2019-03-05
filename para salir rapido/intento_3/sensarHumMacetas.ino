int sensarHumMacetas() {

  int humedadTierra1Ahora1 = sensarTierra1();
  humedadTierraHist1 += humedadTierra1Ahora1;

  int humedadTierra1Ahora2 = sensarTierra2();
  humedadTierraHist2 += humedadTierra1Ahora2;

  contadorLecturas++;

  if (contadorLecturas = 2) {
    contadorLecturas = 0;
    promHumSensores = ( (humedadTierraHist1 / 3) + (humedadTierraHist1 / 3) ) / 2 ;
    humedadTierraHist1 = 0;
    humedadTierraHist2 = 0;

    return promHumSensores;
  }
}
/*


  promHumedadTierraAhora = (humedadTierra1Ahora1 + humedadTierra1Ahora2) / 2;
  Serial.println(promHumedadTierraAhora);
  String tierraLCD = (String)"hum tie: " + promHumedadTierraAhora + "%";
  lcd.clear();
  lcd.print(tierraLCD);
  delay(1500);
  return promHumedadTierraAhora;


*/
