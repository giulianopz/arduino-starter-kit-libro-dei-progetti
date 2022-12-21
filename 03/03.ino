const int sensorPin = A0;
const int baselineTmp = 25.0;

void setup() {
  Serial.begin(9600);
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("sensor value: ");
  Serial.print(sensorVal);
  float voltage = (sensorVal / 1024.0) * 5.0;
  Serial.print(", volts: ");
  Serial.print(voltage);
  float temperature = (voltage - .5) * 100;
  Serial.print(", degrees C: ");
  Serial.print(temperature);
  Serial.println();

  if (temperature < baselineTmp + 2) {
    Serial.println("temperature < baselineTmp+2");
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTmp+4 && temperature < baselineTmp + 6) {
    Serial.println("temperature >= baselineTmp+4 && temperature < baselineTmp + 6");
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTmp+6) {
    Serial.println("temperature >= baselineTmp+6");
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);
}