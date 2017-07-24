#include <Wire.h>
#include <UnoWiFiDevEd.h>

#define SWITCH_1 2
#define SWITCH_2 3
#define SWITCH_3 4
#define SWITCH_4 9
#define LED_1 5
#define LED_2 6
#define LED_3 7
#define LED_4 8
#define SWITCH1_PRESSED LOW
#define SWITCH2_PRESSED LOW
#define SWITCH3_PRESSED LOW
#define SWITCH4_PRESSED LOW

#define CONNECTOR "rest"
#define SERVER_ADDR "158.108.165.223"

int switchInput1;
int switchInput2;
int switchInput3;
int switchInput4;

boolean isSwitch_1_On;
boolean isSwitch_2_On;
boolean isSwitch_3_On;
boolean isSwitch_4_On;

CiaoData data;

void setup() {
  Ciao.begin();
  Serial.begin(9600);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(SWITCH_1, INPUT);
  pinMode(SWITCH_2, INPUT);
  pinMode(SWITCH_3, INPUT);
  pinMode(SWITCH_4, INPUT);

}

void loop() {
  int light = analogRead(A0);
  Serial.println(light);

  if (switchInput1 == SWITCH1_PRESSED) {
    digitalWrite(LED_1, HIGH);
    isSwitch_1_On = true;
  } else {
    isSwitch_1_On = false;
  }

  if (switchInput2 == SWITCH2_PRESSED) {
    digitalWrite(LED_2, HIGH);
    isSwitch_2_On = true;
  } else {
    isSwitch_2_On = false;
  }

  if (switchInput3 == SWITCH3_PRESSED) {
    digitalWrite(LED_3, HIGH);
    isSwitch_3_On = true;
  } else {
    isSwitch_3_On = false;
  }
  
  if (switchInput4 == SWITCH4_PRESSED) {
    digitalWrite(LED_4, HIGH);
    isSwitch_4_On = true;
  } else {
    isSwitch_4_On = false;
  }
  delay(200);
}
