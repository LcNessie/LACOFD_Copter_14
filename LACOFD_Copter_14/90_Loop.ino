/*
  Loop function
*/

// Loop
void loop() {
  // Debug
  //unsigned long loopStart = 0;  // Only used for debugging
  //unsigned long loopEnd = 0;    // Only used for debugging
  //loopStart = micros();         // Only used for debugging

  // Loop preparations
  setLoopClock();

  // Handle interrupt service routines.
  pwmHandler();

  // Handle light routines
  beaconRoutine();
  flashRoutine();
  navRoutine();
  strobeRoutine();

  // Debug
  //loopEnd = micros();                                 // Only used for debugging
  //Serial.print(String(loopEnd - loopStart) + "\n");   // Only used for debugging
}
