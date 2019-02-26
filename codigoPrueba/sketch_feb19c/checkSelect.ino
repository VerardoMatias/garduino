void checkSelect() {
  select_buttonState = digitalRead(Select_buttonPin);

  // compare the buttonState to its previous state
  if (select_buttonState != select_lastButtonState) {
    // if the state has changed, increment the counter
    if (select_buttonState == LOW) {
      SPress = true;
      // if the current state is HIGH then the button went from off to on:
      Serial.println("on");

    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  select_lastButtonState = select_buttonState;
}
