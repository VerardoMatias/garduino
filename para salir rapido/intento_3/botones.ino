int botones() {
  SPress = false;
  do {
    checkUp();
    checkDown();
    checkSelect();

    if (bPress == true) {
      bPress = false;
      lcd.setCursor(2, 1);
      lcd.print("               ");
      lcd.setCursor(2, 1);
      lcd.print(buttonPushCounter);
      //imprimir en pantalla la cantidad
    }
  } while (SPress == false);
  return buttonPushCounter;
}
