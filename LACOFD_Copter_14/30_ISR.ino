/*
  Interrupt service routines and handlers
*/

// Interrupt service routine for PWM input 0
void isrPwm0() {
  if (digitalRead(pwmPin[0])) {
    pwmRise[0] = micros();
    return;
  }
  pwmFall[0] = micros();
  pwmTrigger[0] = true;
  return;
}

// Interrupt service routine for PWM input 1
void isrPwm1() {
  if (digitalRead(pwmPin[1])) {
    pwmRise[1] = micros();
    return;
  }
  pwmFall[1] = micros();
  pwmTrigger[1] = true;
  return;
}

void pwmHandler() {
  if (pwmTrigger[0]) {
    pwmTrigger[0] = false;
    pwmWidth[0] = pwmFall[0] - pwmRise[0];
    if (pwmWidth[0] < 750 && pwmWidth[0] > 2250) {  // Assume read error.
      // Nothing
    }
    else if (pwmWidth[0] < 1250) {                  // Switch set to low.
      beaconControl = false;
      strobeControl = false;
    }
    else if (pwmWidth[0] < 1750) {                  // Switch set to middle.
      beaconControl = true;
      strobeControl = false;
    }
    else { // if  (pwmWidth[0] < 2250) {            // Switch set to high.
      beaconControl = true;
      strobeControl = true;
    }
  }
  if (pwmTrigger[1]) {
    pwmTrigger[1] = false;
    pwmWidth[1] = pwmFall[1] - pwmRise[1];
    if (pwmWidth[1] < 750 && pwmWidth[1] > 2250) {  // Assume read error.
      // Nothing
    }
    else if (pwmWidth[1] < 1500) {                  // Switch set to low
      flashControl = false;
    }
    else // if (pwmWidth[1] < 2250) {               // Switch set to high.
      flashControl = true;
  }
  return;
}
