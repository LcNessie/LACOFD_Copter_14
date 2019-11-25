/*
  Settings (Global Constant declarations)
*/

// PWM
const byte pwmPin[] = {2, 3};                 // RC Receiver channels on pin D2 and D3, because they require interrupt capability.

// Beacon lights
const byte beaconPin[] = {7, 8, 9};           // Beacon lights on pin D7, D8 and D9, no special requirements.
const int beaconTime[] = {2235, 2270, 2305};  // Number of milliseconds per cycle.
const int beaconOnTime[] = {250, 250, 250};   // Number of milliseconds per cycle that beacon is lit.

// Flash lights
const byte flashPin[] = {5, 6};               // Flash lights on pin D5 and D6, because they require PWM capability.
const int flashTime = 1300;                   // Number of milliseconds per cycle.
const float flashCooldown[] = {1.02, 1.02};   // Cooldown factor. Higher number means faster cooldown.
const float flashHeatup[] = {1.07, 1.07};     // Heatup factor. Higher number means faster heatup.

// Nav lights
const byte navPin[] = {4};                    // Nav lights on pin D4, no special requirements.

// Strobe lights
const byte strobePin[] = {10, 11};            // Strobe lights on pin D10 and D11, no special requirements.
const int strobeTime[] = {2200, 2165};        // Number of milliseconds per cycle.
const byte strobePatternLength = 2;           // Number of flashes per cycle.
const int strobePatternOn[][strobePatternLength] = {{2049, 2149}, {2014, 2114}};    // Mind the zero-indexing.
const int strobePatternOff[][strobePatternLength] = {{ 2099, 2199 }, {2064, 2164}}; // Mind the zero-indexing.

/*
   Settings (Global variable declarations)
*/

// If true, turn on this set of lights by default. This may be overridden by the pwm handler functions.
bool beaconControl  = true;
bool flashControl   = true;
bool navControl     = true;
bool strobeControl  = true;
