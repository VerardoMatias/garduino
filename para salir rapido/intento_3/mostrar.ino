int mostrar(int cantidadMacetas, int cantLitrosMacetas, int etapaPlanta) {

  String stringCantidadMacetas = (String)"cant mac: " + cantidadMacetas ;
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(stringCantidadMacetas);
  delay(1000);

  String stringCantLitros = (String)"cant lit: " + cantLitrosMacetas + "L" ;
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(stringCantLitros);
  delay(1000);

  String stringEtapaPlanta = (String)"etapa : " + etapaPlanta  ;
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print(stringEtapaPlanta);
  delay(1000);
}
