/*
  Tests the haptic sensor
*/
int hapticPin;

void setup() {
  Serial.begin(9600);
  hapticPin = 13;
  pinMode(hapticPin, OUTPUT);
}

void loop() {
  while(Serial.available()) {
    Serial.read();
    digitalWrite(hapticPin, HIGH);
    delay(2000);
    digitalWrite(hapticPin, LOW);
  }
}
