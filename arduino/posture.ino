/*
  Code to communicate with Python on laptop and buzz
*/

int flexPin;
int flexVal;
int hapticPin;
int counter;
char buzz;

void setup() {
  Serial.begin(9600);
  flexPin = 0;
  hapticPin = 13;
  counter=0;
  pinMode(hapticPin, OUTPUT);
}

void loop() {
  flexVal = analogRead(flexPin);
  Serial.println(flexVal);
  while(Serial.available()){
    Serial.read();
    digitalWrite(hapticPin, HIGH);
    delay(1000);
    digitalWrite(hapticPin, LOW);
  }
  delay(1000);
}
