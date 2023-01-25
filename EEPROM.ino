
void read_eeprom() {
  if (EEPROM.read(0) == NO_OF_MODULE) {
    int addr = 1;
    EEPROM.get(addr, motor);
  }
  update_pannel();
}

//--------------------------------------------------------------------------------------------

void update_pannel() {
  for (int i = 0; i < NO_OF_MODULE; i++) {
    flower[i].mini = angle_to_pwm(motor.mini[i]);
    flower[i].max = angle_to_pwm(motor.max[i]);

    flower[i].address = motor.addrs[i] % NO_OF_SERVOS_IN_A_BOARD;
    flower[i].module = motor.addrs[i] / NO_OF_SERVOS_IN_A_BOARD;
  }
}
