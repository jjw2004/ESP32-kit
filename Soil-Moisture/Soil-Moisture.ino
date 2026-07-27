#define soil_moisture_pin 15

void setup() {
  Serial.begin(115200);
}

void loop() {
  int moisture = analogRead(soil_moisture_pin);

  // Convert the reading (0-4095) to a percentage (0-100)
  int moisturePercent = map(moisture, 0, 4095, 0, 100);

  // Keep the value between 0 and 100
  moisturePercent = constrain(moisturePercent, 0, 100);

  Serial.print("Raw Value: ");
  Serial.print(moisture);

  Serial.print("  Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  delay(500);
}