/*
  Setup function
*/

// Setup
void setup() {

  // Debug
  //Serial.begin(115200); // Open the serial port at 115200 bps for debugging purposes

  // set initial Pin states
  digitalWrite(pwmPin[0], LOW);
  digitalWrite(pwmPin[1], LOW);
  digitalWrite(beaconPin[0], LOW);
  digitalWrite(beaconPin[1], LOW);
  digitalWrite(beaconPin[2], LOW);
  digitalWrite(flashPin[0], LOW);
  digitalWrite(flashPin[1], LOW);
  digitalWrite(navPin[0], LOW);
  digitalWrite(strobePin[0], LOW);
  digitalWrite(strobePin[1], LOW);
  
  // set pin modes
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

  // Self test
  selfTest();

  // Enable interrupt service routines
  attachInterrupt(digitalPinToInterrupt(pwmPin[0]), isrPwm0, CHANGE);
  attachInterrupt(digitalPinToInterrupt(pwmPin[1]), isrPwm1, CHANGE);

  // Synchronize clocks
  loopClock = millis();
  clocksSync();
}
