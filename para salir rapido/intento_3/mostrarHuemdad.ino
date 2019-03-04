void mostrarHumedad(int valor) {
  String humedadLCD = (String)"Humedad: " + valor + "%";
  lcd.setCursor(0, 1);
  lcd.print(humedadLCD);
}
