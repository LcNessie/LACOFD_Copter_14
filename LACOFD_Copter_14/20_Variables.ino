/*
  Global variable declarations
*/

// Loop
unsigned long loopClock = 0;

// PWM
volatile unsigned long pwmRise[] = {0, 0};
volatile unsigned long pwmFall[] = {0, 0};
volatile bool pwmTrigger[] = {false, false};
int pwmWidth[] = {0, 0};

// Beacon lights
bool beaconOn = false;
unsigned long beaconClock[] = {0, 0, 0};

// Flash lights
bool flashOn = false;
unsigned long flashClock = 0;
unsigned long flashBulbHeatClock = 0;
bool flashToggle = false;
int flashBulbHeat[] = {0, 0}; // The flash bulb filaments are cold.

// Nav lights
bool navOn = false;

// Strobe lights
bool strobeOn = false;
unsigned long strobeClock[] = {0, 0};
