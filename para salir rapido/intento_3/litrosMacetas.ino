int litrosMacetas() {
  
  sinLitrosMacetas = false;
  lcd.clear();
  lcd.print("Litros Macetas?");
  int cantLitros = botones();
  
  if (!cantLitros == 0) {
    lcd.clear();
    lcd.print(cantLitros);
    delay(1000);
    String stringLitrosMacetas = (String)cantLitros;
    lcd.clear();
    lcd.print("Guardado !");
    delay(1500);
    return cantLitros;
  }
  else {
    lcd.clear();
    lcd.print("No register");
    delay(1000);
    litrosMacetas();
  }
}
