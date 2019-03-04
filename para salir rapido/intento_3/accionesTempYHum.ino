int accionesTempYHum(){
  for (int i = 0; i<4; i++){
    int valorT = sensarTemperatura();
    sumaDeTemps += valorT;
    
    sensarHumedad();
    int valorH = sensarHumedad();
    sumaDeHums += valorH;
  }

  promDeTemps = sumaDeTemps / 4;
  promDeHums = sumaDeHums / 4;
  
  Serial.println(promDeTemps);
  Serial.println(promDeHums);
  tomaDecisionesTemp();
  //tomaDecisionesHum();
  
  sumaDeTemps = 0;
  sumaDeHums = 0;
}
