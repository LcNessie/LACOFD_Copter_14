/*
   Nav functions
*/

void navRoutine() {
  if (navOn != navControl) {
    // If the nav lights are toggled, run this code once.
    navOn = !navOn;
    digitalWrite(navPin[0], navOn);
  }
  return;
}
