#include <Wire.h>
#include <UnoWiFiDevEd.h>
#include <dht.h>
#define DHT11 5
#define AIR 6
//#define SWITCH 7
#define LIGHT 3
#define CONNECTOR "rest"
#define SERVER_ADDR "158.108.165.223"

dht DHT;
int dhtTemp;
int temperature;
//int switchInput;
//boolean isOn;

String lightMStatus;
String airMStatus;

String tmpWrite = "";
String tmpRead = "";

CiaoData data;
//char readADDR[] = "/data/5910500147/light";


void setup() {
  Ciao.begin();
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(LIGHT, OUTPUT);
  pinMode(AIR, OUTPUT);
  //  pinMode(SWITCH, INPUT);
  //isOn = false;

//  tmpWrite = "/data/5910500147/lightm/set/2";
//  write();
//  tmpWrite = "/data/5910500147/airm/set/2";
//  write();

}
void loop()
{
  int light = analogRead(A0);
  Serial.print(F("Light: "));
  Serial.println(light);
  Serial.print(F("light manual status: "));
  tmpRead = "/data/5910500147/lightm/";
  lightMStatus = read();
  delay(500);
  tmpWrite = "/data/5910500147/flux/set/" + String(light);
  write();
  delay(500);

  if (lightMStatus == "2") {
    if (light >= 500) {
      digitalWrite(LIGHT, HIGH);
      tmpWrite = "/data/5910500147/light/set/on";
      write();
      delay(500);
    }
    else {
      digitalWrite(LIGHT, LOW);
      tmpWrite = "/data/5910500147/light/set/off";
      write();
      delay(500);
    }
  }
  else if (lightMStatus == "1") {
    digitalWrite(LIGHT, HIGH);
  }
  else if (lightMStatus == "0") {
    digitalWrite(LIGHT, LOW);
  }

  //  writelight(" / data / 5910500147 / light / set / qwertyu");
  //  read(" / data / 5910500147 / light / ");



  dhtTemp = DHT.read11(DHT11);
  temperature = (int) DHT.temperature;
  //  switchInput = digitalRead(SWITCH);
  Serial.print(F("temperature: "));
  Serial.println(temperature);
  tmpWrite = "/data/5910500147/temperature/set/" + String(temperature) ;
  write();
  Serial.print(F("air manual status: "));
  tmpRead = "/data/5910500147/airm/";
  airMStatus = read();
  delay(500);
  if (airMStatus == "2") {

    if (temperature >= 25) {
      digitalWrite(AIR, HIGH);
      // isOn = true;
    } else {
      digitalWrite(AIR, LOW);
      // isOn = false;
    }

  }
  if (airMStatus == "0") {
    digitalWrite(AIR, LOW);
  }

  if (airMStatus == "1") {
    digitalWrite(AIR, HIGH);
  }
  tmpWrite = "";
  tmpRead = "";
  delay(3000);

}

void write() {
  data = Ciao.write(CONNECTOR, SERVER_ADDR, tmpWrite);
  Serial.print(F("Sended: "));
  Serial.println(tmpWrite);
}

String read() {

  data = Ciao.read(CONNECTOR, SERVER_ADDR, tmpRead);
  //str = " / data / 5910500147 / light / set / qwertyu" ;
  //Serial.println(str);
  if (data.isEmpty()) {
    Serial.println(F("False"));
  }
  else {
    Serial.println(String(data.get(2)));
    return String(data.get(2));
  }
}

