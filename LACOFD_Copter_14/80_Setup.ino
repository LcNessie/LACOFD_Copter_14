/*
  Setup function
*/

// Setup
void setup() {
  //Serial.begin(115200); // Open the serial port at 115200 bps for debugging purposes
  pinMode(pwmPin[0], INPUT_PULLUP);
  pinMode(pwmPin[1], INPUT_PULLUP);
  pinMode(beaconPin[0], OUTPUT);
  pinMode(beaconPin[1], OUTPUT);
  pinMode(beaconPin[2], OUTPUT);
  pinMode(flashPin[0], OUTPUT);
  pinMode(flashPin[1], OUTPUT);
  pinMode(navPin[0], OUTPUT);
  pinMode(strobePin[0], OUTPUT);
  pinMode(strobePin[1], OUTPUT);

  selfTest();

  //beaconControl = true; // Turn on beacon lights by default
  //flashControl = true; // Turn on flash lights by default
  navControl = true; // Turn on nav lights by default
  //strobeControl = true; // Turn on strobe lights by default

  attachInterrupt(digitalPinToInterrupt(pwmPin[0]), isrPwm0, CHANGE);
  attachInterrupt(digitalPinToInterrupt(pwmPin[1]), isrPwm1, CHANGE);
}
