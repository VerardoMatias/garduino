void hayQueRegar() {
  if (promHumedadTierraAhora >= 700) {
    digitalWrite(bombaAgua, HIGH);
    Serial.println("Regando..");
    lcd.clear();
    lcd.print("Regando...");
    delay(10500);
    digitalWrite(bombaAgua, LOW);
  }
  else {
    Serial.println("Tierra humeda");
  }
}
