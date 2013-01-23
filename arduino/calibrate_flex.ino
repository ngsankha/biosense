/*
  Code to calibrate the different flex sensor bendings
*/

int flexPin;
int flexVal;

void setup() {
  Serial.begin(9600);
  flexPin = 0;
}

void loop() {
  while(Serial.available()) {
    Serial.read();
    flexVal = analogRead(flexPin);
    Serial.println(flexVal);
  }
}
