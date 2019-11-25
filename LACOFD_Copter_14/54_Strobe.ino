/*
   Strobe functions
*/

void strobePattern(byte bulb) {
  bool bulbOn = false;
  for (int i = 0; i < strobePatternLength; i++) {
    if (loopClock - strobeClock[bulb] < strobePatternOn[bulb][i]) {
      //bulbOn = false;
      break;
    }
    else if (loopClock - strobeClock[bulb] < strobePatternOff[bulb][i]) {
      bulbOn = true;
      break;
    }
  }
  digitalWrite(strobePin[bulb], bulbOn);
  if (loopClock - strobeClock[bulb] >= strobeTime[bulb]) {
    strobeClock[bulb] = loopClock;
  }
  return;
}

void strobeRoutine() {
  if (strobeOn != strobeControl) {
    // If the strobe lights are toggled, run this code once.
    strobeOn = !strobeOn;
    if (strobeOn) {
      // If the strobe lights are turned on, run this code once.
      strobeClock[0] = loopClock;
      strobeClock[1] = loopClock;
    }
    else { // if (!strobeOn)
      // If the strobe lights are turned off, run this code once.
      digitalWrite(strobePin[0], LOW);
      digitalWrite(strobePin[1], LOW);
    }
  }
  if (strobeOn) {
    // If the strobe lights are turned on, run this code every loop.
    strobePattern(0);
    strobePattern(1);
  }
  return;
}
