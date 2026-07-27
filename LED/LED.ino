const int ledPinRed = 14;
const int ledPinGreen = 13;

void setup() {
  pinMode(ledPinRed,OUTPUT);
  pinMode(ledPinGreen,OUTPUT); 
}

void loop() {
  digitalWrite(ledPinRed, HIGH); // Turn LED on
  digitalWrite(ledPinGreen, LOW);
  delay(1000);                // Wait 1 second
  digitalWrite(ledPinRed, LOW);  // Turn LED off
  digitalWrite(ledPinGreen, HIGH);
  delay(1000);                // Wait 1 second
}
