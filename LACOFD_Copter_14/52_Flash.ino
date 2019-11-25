/*
   Flash functions
*/

void flashBulbHeatCalc( byte bulb, bool bulbOn ) {
  if (bulbOn) {
    if (flashBulbHeat[bulb] < 255) {
      flashBulbHeat[bulb] = 255 - ( (254 - flashBulbHeat[bulb] ) / flashHeatup[bulb]);
    }
    return;
  }
  // else if (!bulbOn) {
  if (flashBulbHeat[bulb] > 0) {
    flashBulbHeat[bulb] /= flashCooldown[bulb];
  }
  return;
}

void flashRoutine() {
  // Routine for flash lights
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
  return;
}
