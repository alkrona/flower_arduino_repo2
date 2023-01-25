

void servo_move_in_limits(int servo, int angle) {
  int pulse = angle_to_limit_pwm(servo, angle);
  bloom[flower[servo].module].setPWM(flower[servo].address, 0, pulse);
}
