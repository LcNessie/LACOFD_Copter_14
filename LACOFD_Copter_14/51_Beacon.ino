/*
  Beacon functions
*/

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
  return;
}

void beaconRoutine() {
  // Routine for beacon lights
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
  return;
}
