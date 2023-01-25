#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <EEPROM.h>
#include <cvzone.h>
SerialData serialData(16,3);//(numofValsRec,digitsPerVal)
int valsRec[16];


#define NO_OF_BOARD 10              // total number of servos drivers
#define NO_OF_SERVOS_IN_A_BOARD 16  // total number of servos drivers
#define NO_OF_MODULE 16             // total number of servos


#define PWM_MIN 100
#define PWM_MAX 600

#define SERVO_MIN 0
#define SERVO_MAX 100

#define MAX 1
#define MINI 0
#define LED 13


// #define DEBUGGING

#define SERIAL_TIMEOUT 8  //Ms
#define SERIAL_BAURDRATE 9600


struct limits {
  uint8_t mini[NO_OF_MODULE];
  uint8_t max[NO_OF_MODULE];
  uint8_t addrs[NO_OF_MODULE];
};
limits motor;

struct flower_ {
  int mini;
  int max;
  uint8_t address;
  uint8_t module;
  uint8_t current_value;
};
flower_ flower[NO_OF_MODULE];


Adafruit_PWMServoDriver bloom[NO_OF_BOARD];
byte adr[NO_OF_BOARD] = { 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49 };

void bloom_init() {
  for (int i = 0; i < NO_OF_BOARD; i++) {
    bloom[i] = Adafruit_PWMServoDriver(adr[i]);
    bloom[i].begin();
    bloom[i].setPWMFreq(60);
  }
}


void setup() {
  Serial.begin(SERIAL_BAURDRATE);
  Serial.setTimeout(SERIAL_TIMEOUT);
  pinMode(LED, OUTPUT);

  bloom_init();
  read_eeprom();
}

void loop() {
  serialData.Get(valsRec);

if (parse_data(valsRec)) {
      update_flowers();
    }
}