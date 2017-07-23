#include <Servo.h>
#include <Wire.h>
#include <UnoWiFiDevEd.h>
#define SERVO 3
//#define SWITCH 10
#define trigPinA 6
#define echoPinA 7
#define trigPinB 11
#define echoPinB 12
#define CONNECTOR "rest"
#define SERVER_ADDR "158.108.165.223"
int people = 0;

String tmpWrite = "";
String tmpRead = "";
String doorMStatus="";
CiaoData data;

Servo myServo;
boolean isOpen;
int switchInput;

void setup() {
  Ciao.begin();
  Serial.begin(9600);
  myServo.attach(SERVO);
  //  pinMode(SWITCH, INPUT);
  pinMode(trigPinA, OUTPUT);
  pinMode(echoPinA, INPUT);
  pinMode(trigPinB, OUTPUT);
  pinMode(echoPinB, INPUT);
  //  isOpen = false;
  myServo.write(0);
}
long checkA()
{
  long duration, distanceA, distanceB;
  digitalWrite(trigPinA, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinA, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinA, LOW);
  duration = pulseIn(echoPinA, HIGH);
  distanceA = (duration / 2.0) / 29.1;
  Serial.print("A: ");
  Serial.println(distanceA);
  delay(500);

  return distanceA;
}
long checkB()
{
  long duration, distanceA, distanceB;
  digitalWrite(trigPinB, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinB, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinB, LOW);
  duration = pulseIn(echoPinB, HIGH);
  distanceB = (duration / 2.0) / 29.1;
  Serial.print("B: ");
  Serial.println(distanceB);
  delay(500);

  return distanceB;
}
void loop() {

  //
  //  manual
  //  if (switchInput == LOW) {
  //    if (isOpen) {
  //      delay(500);
  //      myServo.write(30);
  //      isOpen = false;
  //    } else {
  //      delay(500);
  //      myServo.write(150);
  //      isOpen = true;
  //    }
  //  }


  tmpRead = "/data/5910500147/doorm/";
  doorMStatus = read();

  if (doorMStatus == "0") { //close
    delay(500);
    myServo.write(0);
    isOpen = false;
  }
  else if (doorMStatus == "1") { //open
    delay(500);
    myServo.write(150);
    isOpen = true;
  }
  else if (doorMStatus == "2") { //auto
    if (checkA() < 10) {
      Serial.print("A: ");
      Serial.println(checkA());
      myServo.write(150);
      while (1)
      {
        Serial.print("A2: ");
        Serial.println(checkA());
        Serial.print("inwhile: ");
        delay(500);
        if (checkB() < 20) {
          Serial.print("B2: ");
          Serial.println(checkB());
          myServo.write(0);
          people++;
          Serial.print("People: ");
          Serial.println(people);
          Serial.print("out: ");
          break;
        }
      }
      delay(500);
    }
    else if (checkB() < 20 && people > 0) {
      Serial.print("B: ");
      Serial.println(checkB());
      myServo.write(150);
      while (1)
      {
        Serial.print("inwhile: ");
        if (checkA() < 10) {
          //delay(500);
          Serial.print("A: ");
          Serial.println(checkA());
          myServo.write(0);
          people--;
          Serial.print("People: ");
          Serial.println(people);
          Serial.print("out: ");
          break;
        }
      }
      delay(500);
    }
  }




  tmpWrite = "/data/5910500147/people/set/" + String(people);
  write();

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

