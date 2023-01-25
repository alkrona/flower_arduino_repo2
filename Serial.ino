// Read serial ------------------------------
//void read_serial() {

 // String input_string = get_string();

  //if (parse_data(input_string)) {
  //  update_flowers();
 // }
//}

//bool parse_data(String input_string) {


  //if (input_string.length() == NO_OF_MODULE + 1) {
   // int length = NO_OF_MODULE;

   // for (byte arrayPointer = 0; arrayPointer < length; arrayPointer++) {
    //  flower[arrayPointer].current_value = (int)input_string[arrayPointer + 1];
    //}

    // digitalWrite(LED, (bool)input_string[1]);
  //}

 // return 1;
//}
bool parse_data(int* valsRec) {
  // #ifdef DEBUGGING
  //   int length = min(input_string.length(), NO_OF_MODULE);
  // #else
  //   int length = NO_OF_MODULE;
  // #endif

  //if (input_string.length() == NO_OF_MODULE) {
  // int length = NO_OF_MODULE;

#ifdef DEBUGGING
    Serial.println("data = ");
#endif



for (byte arrayPointer = 0; arrayPointer < 16; arrayPointer++) {
  flower[arrayPointer].current_value = (int)valsRec[arrayPointer];
}
    return 1;
}




String get_string() {

  while (Serial.available() == 0) {}


  String input_string;

  do {
    input_string = Serial.readString();

  } while (((byte)input_string[0] == 240) || (input_string.length() == 0));

  return input_string;
}