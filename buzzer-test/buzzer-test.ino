#define BUZZER_PIN 18

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  tone(BUZZER_PIN, 1000);
  delay(500);

  // Play a lower note (800 Hz) for 500 milliseconds
  tone(BUZZER_PIN, 800);
  delay(500);
}
