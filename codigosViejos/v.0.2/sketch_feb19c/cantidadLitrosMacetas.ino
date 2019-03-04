int cantidadDeMacetas() {
  sinMacetas == false;
  lcd.clear();
  lcd.print("Cant Macetas?");
  int cantidadMacetas = botones();
  lcd.clear();
  lcd.print("Guardado !");
  delay(1500);
  //EEPROM.write(espaciosMemoria, cantidadMacetas);
  espaciosMemoria++;
  return cantidadMacetas;
}
