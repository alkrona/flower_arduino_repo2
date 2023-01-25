
// //  Conversions  -----------------------------------------------------------------------------
// //--------------------------------------------------------------------------------------------

int angle_to_pwm(int angle) {
  int pwm = map(angle, SERVO_MIN, SERVO_MAX, PWM_MIN, PWM_MAX);
  return pwm;
}

//--------------------------------------------------------------------------------------------

int angle_to_limit_pwm(int module, int angle) {
  int pwm = map(angle, SERVO_MIN, SERVO_MAX, flower[module].mini, flower[module].max);
  return pwm;
}
