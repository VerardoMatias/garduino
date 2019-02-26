int litrosMacetas() {
  sinLitrosMacetas = false;
  lcd.clear();
  lcd.print("Litros Macetas?");
  int cantLitrosMacetas = botones();
  lcd.clear();
  lcd.print("Guardado !");
  delay(1500);
  //EEPROM.write(espaciosMemoria, cantLitrosMacetas);
  espaciosMemoria++; 
  return cantLitrosMacetas;
}
