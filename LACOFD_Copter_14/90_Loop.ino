/*
  Loop function
*/

// Loop
void loop() {
  //loopStart = micros(); Only used for debugging
  // Handle interrupt service routine 0
  if (pwmTrigger[0]) {
    pwmTrigger[0] = false;
    pwmWidth[0] = pwmFall[0] - pwmRise[0];
    if (pwmWidth[0] < 750) { // Assume read error
      // Nothing
    }
    else if (pwmWidth[0] < 1250) { // Switch set to low
      beaconControl = false;
      strobeControl = false;
    }
    else if (pwmWidth[0] < 1750) { // Switch set to middle
      beaconControl = true;
      strobeControl = false;
    }
    else if (pwmWidth[0] < 2250) { // Switch set to high
      beaconControl = true;
      strobeControl = true;
    }
    else { // Assume read error
      // Nothing
    }
  }

  // Handle interrupt service routine 1
  if (pwmTrigger[1]) {
    pwmTrigger[1] = false;
    pwmWidth[1] = pwmFall[1] - pwmRise[1];
    if (pwmWidth[1] < 750) { // Assume read error
      // Nothing
    }
    else if (pwmWidth[1] < 1500) { // Switch set to low
      flashControl = false;
    }
    else if (pwmWidth[1] < 2250) { // Switch set to high
      flashControl = true;
    }
    else { // Assume read error
      // Nothing
    }
  }

  // Loop setup
  setLoopClock();

  // Beacon lights
  if (beaconOn != beaconControl) {
    // If the beacon lights are toggled, run this code once.
    beaconOn = !beaconOn;
    if (!beaconOn) {
      // If the beacon lights are turned off, run this code once.
      digitalWrite(beaconPin[0], LOW);
      digitalWrite(beaconPin[1], LOW);
      digitalWrite(beaconPin[2], LOW);
    }
  }
  if (beaconOn) {
    // If the beacon lights are turned on, run this code every loop.
    beaconPattern(0);
    beaconPattern(1);
    beaconPattern(2);
  }

  // Flash lights
  if (flashOn != flashControl) {
    // If the flash lights are toggled, run this code once.
    flashOn = !flashOn;
  }
  if (flashOn) {
    // If the flash lights are turned on, run this code every loop.
    if (loopClock - flashClock >= (flashTime / 2)) {
      flashToggle = !flashToggle;
      flashClock = loopClock;
    }
    if (loopClock - flashBulbHeatClock >= 5) {
      flashBulbHeatCalc( 0, flashToggle );
      flashBulbHeatCalc( 1, !flashToggle );
      flashBulbHeatClock = loopClock;
    }
  }
  else { // if (!flashOn)
    // If the flash lights are turned off, run this code every loop.
    if (loopClock - flashBulbHeatClock >= 5) {
      flashBulbHeatCalc( 0, false );
      flashBulbHeatCalc( 1, false );
      flashBulbHeatClock = loopClock;
    }
  }
  // Run this code every loop.
  analogWrite(flashPin[0], flashBulbHeat[0]);
  analogWrite(flashPin[1], flashBulbHeat[1]);

  // Nav lights
  if (navOn != navControl) {
    // If the nav lights are toggled, run this code once.
    navOn = !navOn;
    digitalWrite(navPin[0], navOn);
  }

  // Strobe lights
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

  //loopEnd = micros(); // Only used for debugging
  //Serial.print(String(loopEnd - loopStart) + "\n"); // Only used for debugging
}
