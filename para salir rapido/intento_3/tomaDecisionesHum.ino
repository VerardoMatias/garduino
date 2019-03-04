int tomaDecisionesHum() {
  if (promDeHums > humMaxAUsar) {
    if (estadoExtractor == false) {
      digitalWrite(extractor, HIGH);
      Serial.println("humedad alta");
      Serial.println("prendo extractor HUM-");
      estadoExtractor = true;
    }
  }

  if (promDeHums < humMinAUsar) {
    if (estadoHumidificador == false) {
      digitalWrite(humidificador, HIGH);
      Serial.println("humedad baja");

      estadoHumidificador = true;
    }
  }
  
}
