/*
  Functions
*/

// Self test
void selfTest() {
  byte bulbs[] = {navPin[0], flashPin[0], flashPin[1], beaconPin[0], beaconPin[1], beaconPin[2], strobePin[0], strobePin[1]};
  bool bulbsOn = true;
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < (sizeof(bulbs) / sizeof(bulbs[0])); i++) {
      digitalWrite(bulbs[i], bulbsOn);
      delay(200);
    }
    delay(500);
    bulbsOn = !bulbsOn;
  }
}

// setLoopClock
void setLoopClock() {
  // Check the loop clock for rollover, and take appropriate actions.
  loopClockPrev = loopClock;
  loopClock = millis();
  if (loopClock < loopClockPrev) { // Loop clock rollover, reset all clocks.
    beaconClock[0] = 0;
    beaconClock[1] = 0;
    beaconClock[2] = 0;
    flashClock = 0;
    flashBulbHeatClock = 0;
    strobeClock[0] = 0;
    strobeClock[1] = 0;
  }
}

// Beacon pattern
void beaconPattern(byte bulb) {
  if (loopClock - beaconClock[bulb] < beaconOnTime[bulb]) {
    // If the time is right, turn the bulb on.
    digitalWrite(beaconPin[bulb], HIGH);
  }
  else {
    // Else, turn the bulb off.
    digitalWrite(beaconPin[bulb], LOW);
  }
  // If the beacon clock exceeds beacon time, reset the clock.
  if (loopClock - beaconClock[bulb] >= beaconTime[bulb]) {
    beaconClock[bulb] = loopClock;
  }
}

// Flash bulb filament heat calculation
void flashBulbHeatCalc( byte bulb, bool bulbOn ) {
  if (bulbOn && flashBulbHeat[bulb] < 255) {
    flashBulbHeat[bulb] = 255 - ( (254 - flashBulbHeat[bulb] ) / flashHeatup[bulb]);
  }
  else if (flashBulbHeat[bulb] > 0) { // if (!bulbOn)
    flashBulbHeat[bulb] /= flashCooldown[bulb];
  }
}

// Strobe pattern
void strobePattern(byte bulb) {
  bool bulbOn = false;
  for (int i = 0; i < strobePatternLength; i++) {
    if (loopClock - strobeClock[bulb] < strobePatternOn[bulb][i]) {
      bulbOn = false;
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
}
