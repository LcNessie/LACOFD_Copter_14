/*
   LACOFD_Copter_14

   This sketch tries to mimick the lighting of "Copter 14", a Bell 412 helicopter owned by the Los Angeles County Fire Dept.

   The circuit:
   - RC inputs on pin D2 and D3 (Interrupt pins)
     - D2 controls nav and strobe lights (assumes 3-way switch)
     - D3 controls flash lights (assumes 2-way switch)
   - Beacon lights, three bright red leds that turn on for half a second, than remain quiet for about 2 seconds,
   - Flash lights, two high power warm white leds that turn on and off alternately, simulate incandescant filaments with a heatup and cooldown time,
   - Nav lights, four normal leds sharing a single channel that are pretty much either constantly on or off.
   - Strobe lights, two high power bright white (almost blue) leds that flash a fraction of a second, then remain quiet for about 2 seconds.

   Created: 5 Jun 2019
   by: Mathijs "LcNessie" Wijers
   Last edit: 21 Jun 2019

   License:
   This software is licensed under GNU GPL v3.0

   Disclaimer:
   - This code comes as is, without warranty.
   - This code is meant for hobby use only, specifically for use in hobby grade scale models.
   - I strongly suggest NOT using this code in critical applications without proper hardening, review and rigorous testing.
   - I will not stand for any damage, be it physical, mental, financial or otherwise, especially for using this code where it was not intended to be used.
   - I strongly suggest using this code only in properly isolated systems. For example:
     - I strongly suggest making sure that no conductive parts of a different system can touch any conductive parts on this system unintentially.
     - I strongly suggest using a separate powersupply for the system that runs this code.
     - I strongly suggest using proper protection for any system connected to the system running this code as an input or output.

   Known shortcomings:

   1: Millisecond clock rollover
   Every 50-ish days, the millisecond clock will roll over.
   To prevent a program malfunction, all clocks are reset to 0 when this is detected.
   This will probably cause a visible glitch in the operation of the lights.
   50 days of continuous use is very unlikely for the intended purpose of this program,
   that's why a smooth rollover routine has not (yet) been implemented.

   2: Microseccond clock rollover
   Every 70-ish minutes, the microseccond clock will roll over.
   This will probably result in an unrealistic reading for the RC inputs.
   The control routine is designed to ignore unrealistic values, and do nothing.
   When the next pulse is read, the control routine should pick up where it has left.
   This could take about 20 milliseconds. No visible glitch should be observed.
*/
