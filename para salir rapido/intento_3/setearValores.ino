/*humMaxAUsar, humMinAUsar, tempMaxAUsar, tempMinAUsar, cantidadMacetas, cantLitrosMacetas, etapaPlanta*/

int setearValores(){
  //int segundosBombaAguaActivada = /*debe ser el 10% de la maceta, cantLitros sobre cantMacetas y sacar el 10%*/;

  if(etapaPlanta == 1){
    humMaxAUsar = humedadMaxStandardPlantin;
    humMinAUsar = humedadMinStandardPlantin;
    tempMaxAUsar = tempMaxStandardPlantin;
    tempMinAUsar = tempMinStandardPlantin;
    return humMaxAUsar, humMinAUsar, tempMaxAUsar, tempMinAUsar; 
  }

  if(etapaPlanta == 2){
    humMaxAUsar = humedadMaxStandardVege;
    humMinAUsar = humedadMinStandardVege;
    tempMaxAUsar = tempMaxStandardVege;
    tempMinAUsar = tempMinStandardVege;
    return humMaxAUsar, humMinAUsar, tempMaxAUsar, tempMinAUsar;
  }

  if(etapaPlanta == 3){
    humMaxAUsar = humedadMaxStandardFlora;
    humMinAUsar = humedadMinStandardFlora;
    tempMaxAUsar = tempMaxStandardFlora;
    tempMinAUsar = tempMinStandardFlora;
    return humMaxAUsar, humMinAUsar, tempMaxAUsar, tempMinAUsar;
  }

  if(etapaPlanta == 4){
    humMaxAUsar = humedadMaxStandardFloraT;
    humMinAUsar = humedadMinStandardFloraT;
    tempMaxAUsar = tempMaxStandardFloraT;
    tempMinAUsar = tempMinStandardFloraT;
    return humMaxAUsar, humMinAUsar, tempMaxAUsar, tempMinAUsar;
  }
}
