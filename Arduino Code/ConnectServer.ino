#include <Wire.h>
#include <UnoWiFiDevEd.h>
#define CONNECTOR "rest"
#define SERVER_ADDR "158.108.165.223"
CiaoData data;
//char readADDR[] = "/data/5910500147/light";
String str;
void setup() {
  Ciao.begin();
  Serial.begin(9600);
}
void loop()
{
//  writelight("/data/5910500147/light/set/qwertyu");
//  read("/data/5910500147/light/");
  delay(10000);

}

void writelight(String a) {
  data = Ciao.write(CONNECTOR, SERVER_ADDR, a);
  Serial.println(str);
  if (data.isEmpty()) {
    Serial.println("False");
  }
  else {
    Serial.println(String(data.get(2)));
  }
}
void read(String a) {
  data = Ciao.read(CONNECTOR, SERVER_ADDR, a);
  str = "/data/5910500147/light/set/qwertyu" ;
  Serial.println(str);
  if (data.isEmpty()) {
    Serial.println("False");
  }
  else {
    Serial.println(String(data.get(2)));
  }
}

