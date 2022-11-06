#include <Servo.h>

Servo s;

int const potPin = A0;

int potVal;
int angle;

void setup() {
  s.attach(9);
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(potPin);
  Serial.print("pot val: ");
  Serial.print(potVal);

  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(" -> angle: ");
  Serial.print(angle);
  Serial.println();

  s.write(angle);
  delay(15);
}
