/*
  Code sense bending movements in posture
*/

int flexPin;
int flexVal;
int hapticPin;

void setup() {
  // Serial.begin(9600);
  flexPin = 0;
  hapticPin = 13;
  pinMode(hapticPin, OUTPUT);
}

void loop() {
  flexVal = analogRead(flexPin);
  if(flexVal < 360) {
    digitalWrite(hapticPin, HIGH);
    delay(500);
    digitalWrite(hapticPin, LOW);
  }
  delay(300);
}
