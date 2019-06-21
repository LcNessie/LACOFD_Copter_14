/*
  Global variable declarations
*/

// Loop
unsigned long loopClock = 0;
unsigned long loopClockPrev = 0;
//unsigned long loopStart = 0;  // Only used for debugging
//unsigned long loopEnd = 0;    // Only used for debugging

// PWM
volatile unsigned long pwmRise[] = {0, 0};
volatile unsigned long pwmFall[] = {0, 0};
volatile bool pwmTrigger[] = {false, false};
int pwmWidth[] = {0, 0};

// Beacon lights
bool beaconControl = false;
bool beaconOn = false;
unsigned long beaconClock[] = {0, 0, 0};

// Flash lights
bool flashControl = false;
bool flashOn = false;
unsigned long flashClock = 0;
bool flashToggle = false;
int flashBulbHeat[] = {0, 0}; // The flash bulb filaments are cold.
unsigned long flashBulbHeatClock = 0;

// Nav lights
bool navControl = false;
bool navOn = false;

// Strobe lights
bool strobeControl = false;
bool strobeOn = false;
unsigned long strobeClock[] = {0, 0};
