void mostrarTemperatura(int valor) {
  String temperaturaLCD = (String)"Temperatura: " + valor + "C";
  lcd.setCursor(0, 0);
  lcd.print(temperaturaLCD);
}
