#include <Arduino.h>
int lightPin = 6;
// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
  pinMode(lightPin, OUTPUT);
}

void loop() {
  digitalWrite(lightPin, HIGH);
  delay(1000);
  digitalWrite(lightPin, LOW);
  delay(1000);
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}