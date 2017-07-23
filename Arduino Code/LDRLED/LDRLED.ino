#define LED 3

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int light = analogRead(A0);
  Serial.println(light);

  if (light >= 750) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  delay(500);
}
