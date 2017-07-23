#include <Servo.h>
#define SERVO 9
#define SWITCH 10
#define trigPin 11
#define echoPin 12

Servo myServo;
boolean isOpen;
int switchInput;

void setup() {
  Serial.begin(9600);
  myServo.attach(SERVO);
  pinMode(SWITCH, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  isOpen = false;
  myServo.write(150);
}

void loop() {
  switchInput = digitalRead(SWITCH);
  
//manual
//    if (switchInput == LOW) {
//      if (isOpen) {
//        delay(500);
//        myServo.write(30);
//        isOpen = false;
//      } else {
//        delay(500);
//        myServo.write(150);
//        isOpen = true;
//      }
//    }

//auto
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2.0) / 29.1;
  Serial.println(distance);
  delay(200);

  if (distance <= 30) {
    delay(200);
    myServo.write(150);
  } else {
    delay(200);
    myServo.write(30);
  }

}
