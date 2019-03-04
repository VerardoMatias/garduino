int sensarHumMacetas() {
  int humedadTierra1Ahora1 = sensarTierra1();
  int humedadTierra1Ahora2 = sensarTierra2();
  promHumedadTierraAhora = (humedadTierra1Ahora1 + humedadTierra1Ahora2) / 2;
  Serial.println(promHumedadTierraAhora);
  return promHumedadTierraAhora;
}
