int cantidadDeMacetas() {

  sinMacetas == false;
  lcd.clear();
  lcd.print("Cant Macetas?");
  int cantidadMacetas = botones();

  if (!cantidadMacetas <= 0) {
    lcd.clear();
    lcd.print(cantidadMacetas);
    delay(1000);
    String stringCantidadMacetas = (String)cantidadMacetas;
    lcd.clear();
    lcd.print("Guardado !");
    delay(1500);
    return cantidadMacetas;
  }

  else {
    lcd.clear();
    lcd.print("No register");
    delay(1000);
    cantidadDeMacetas();
  }
}
