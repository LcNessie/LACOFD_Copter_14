/*
  Interrupt service routines
*/

// Interrupt service routine 0
void isrPwm0() {
  // Interrup service routine for PWM input 0
  if (digitalRead(pwmPin[0])) {
    pwmRise[0] = micros();
  }
  else {
    pwmFall[0] = micros();
    pwmTrigger[0] = true;
  }
}

// Interrupt service routine 1
void isrPwm1() {
  // Interrup service routine for PWM input 1
  if (digitalRead(pwmPin[1])) {
    pwmRise[1] = micros();
  }
  else {
    pwmFall[1] = micros();
    pwmTrigger[1] = true;
  }
}
