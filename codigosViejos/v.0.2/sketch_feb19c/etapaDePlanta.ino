int etapaDePlanta() {
  lcd.clear();
  lcd.print("1.Plantin 2.Vege");
  lcd.setCursor(0, 1);
  lcd.print("3.Flora 4.FloraT");
  etapaPlanta = botones();

  if (etapaPlanta == 1) {
    String stringEtapaPlanta = "Plantin";
    Serial.println(stringEtapaPlanta);
    Serial.println(etapaPlanta);
    lcd.clear();
    lcd.print(stringEtapaPlanta);
    delay(1500);
    //EEPROM.write(espaciosMemoria, cantidadMacetas);
    espaciosMemoria++;
  }
  if (etapaPlanta == 2) {
    String stringEtapaPlanta = "Vegetativo";
    Serial.println(stringEtapaPlanta);
    Serial.println(etapaPlanta);
    lcd.clear();
    lcd.print(stringEtapaPlanta);
    delay(1500);
    //EEPROM.write(espaciosMemoria, cantidadMacetas);
    espaciosMemoria++;
  }
  if (etapaPlanta == 3) {
    String stringEtapaPlanta = "Floracion";
    Serial.println(stringEtapaPlanta);
    Serial.println(etapaPlanta);
    lcd.clear();
    lcd.print(stringEtapaPlanta);
    delay(1500);
    //EEPROM.write(espaciosMemoria, cantidadMacetas);
    espaciosMemoria++;
  }
  if (etapaPlanta == 4) {
    String stringEtapaPlanta = "Floracion T";
    Serial.println(stringEtapaPlanta);
    Serial.println(etapaPlanta);
    lcd.clear();
    lcd.print(stringEtapaPlanta);
    delay(1500);
    //EEPROM.write(espaciosMemoria, cantidadMacetas);
    espaciosMemoria++;
  }
  return etapaPlanta;
}
