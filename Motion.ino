
void update_flowers() {
  for (int i = 0; i < NO_OF_MODULE; i++) {
    servo_move_in_limits(i, flower[i].current_value);
  }
}