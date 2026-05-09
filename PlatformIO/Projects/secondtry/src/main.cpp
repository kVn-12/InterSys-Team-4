#include <Arduino.h>
int lightPin = D6;
int touch = D0;
// put function declarations here:
int myFunction(int, int);

void touchInteraction();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(10000);
  int result = myFunction(2, 3);
  pinMode(lightPin, OUTPUT);
  pinMode(touch, INPUT);
  attachInterrupt(touch, touchInteraction, CHANGE);
}

void loop() {
  //int t = digitalRead(touch);
  //Serial.println(t);
  // digitalWrite(lightPin, HIGH);
  // delay(1);
  // digitalWrite(lightPin, LOW);
  // delay(1);
  // digitalWrite(lightPin, HIGH);
  // delay(1000);
  // digitalWrite(lightPin, LOW);
  // delay(1000);
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
};

void touchInteraction() {
  digitalWrite(lightPin, digitalRead(touch));
  Serial.println("interaction happened");
}
