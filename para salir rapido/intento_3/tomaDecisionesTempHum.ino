int tomaDecisionesTemp() {
  if (promDeTemps > tempMaxAUsar) {
    if (estadoExtractor == false) {
      digitalWrite(extractor, HIGH);
      Serial.println("temperatura alta");
      Serial.println("prendo extractor TEMP-");
      estadoExtractor = true;
    }
  }

  if (promDeTemps < tempMinAUsar) {
    if (estadoCaloventor == false) {
      digitalWrite(caloventor, HIGH);
      Serial.println("temperatura baja");
      Serial.println("prendo caloventor TEMP+");
      estadoCaloventor = true;
    }
  }
}
