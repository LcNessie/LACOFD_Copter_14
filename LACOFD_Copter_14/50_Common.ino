/*
  Common functions
*/

// Synchronise clocks
void clocksSync() {
  beaconClock[0] = loopClock;
  beaconClock[1] = loopClock;
  beaconClock[2] = loopClock;
  flashClock = loopClock;
  flashBulbHeatClock = loopClock;
  strobeClock[0] = loopClock;
  strobeClock[1] = loopClock;
  return;
}

// Self test
void selfTest() {
  byte bulbs[] = {navPin[0], flashPin[0], flashPin[1], beaconPin[0], beaconPin[1], beaconPin[2], strobePin[0], strobePin[1]};
  bool bulbsOn = false;
  for (int j = 0; j < 2; j++) {
    delay(500);
    bulbsOn = !bulbsOn;
    for (int i = 0; i < (sizeof(bulbs) / sizeof(bulbs[0])); i++) {
      digitalWrite(bulbs[i], bulbsOn);
      delay(200);
    }
  }
  delay(500);
  return;
}

// setLoopClock
void setLoopClock() {
  // Check the loop clock for rollover, and take appropriate actions.
  unsigned long loopClockPrev = loopClock;
  loopClock = millis();
  if (loopClock < loopClockPrev) { // Loop clock rollover, resync all clocks.
    clocksSync();
  }
  return;
}
