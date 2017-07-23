#include <dht.h>
#define DHT11 5
#define LED 6
#define SWITCH 7

dht DHT;
int dhtTemp;
int temperature;
int switchInput;
boolean isOn;


void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(SWITCH, INPUT);
  isOn = false;
}

void loop() {
  dhtTemp = DHT.read11(DHT11);
  temperature = (int) DHT.temperature;
  switchInput = digitalRead(SWITCH);
  Serial.print("temperature: ");
  Serial.println(temperature);
  delay(2000);

  if (temperature >= 25) {
    digitalWrite(LED, HIGH);
    isOn = true;
  } else {
    digitalWrite(LED, LOW);
    isOn = false;
  }

  if (switchInput == LOW) {
    digitalWrite(LED, HIGH);
    if (isOn) {
      isOn = false;
    } else {
      isOn = true;
    }
  }
}
