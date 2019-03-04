int etapaDePlanta() {
  lcd.clear();
  lcd.print("1.Plantin 2.Vege");
  lcd.setCursor(0, 1);
  lcd.print("3.Flora 4.FloraT");
  etapaPlanta = botones();
    if (!etapaPlanta == 0) {
    lcd.clear();
    lcd.print(etapaPlanta);
    delay(1000);
  }
  else{
    lcd.clear();
    lcd.print("No register");
    delay(1000);
  }

  if (etapaPlanta == 1) {
    String stringEtapaPlanta = "Plantin";
    Serial.println(stringEtapaPlanta);
    Serial.println(etapaPlanta);
    lcd.clear();
    lcd.print(stringEtapaPlanta);
    delay(1500);
    //EEPROM.write(espaciosMemoria, cantidadMacetas);
    espaciosMemoria++;
    return etapaPlanta;
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
    return etapaPlanta;
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
    return etapaPlanta;
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
    return etapaPlanta;
  }

  else{
    lcd.clear();
    lcd.print("No valido!");
    delay(1000);
    etapaDePlanta();
  }
}
