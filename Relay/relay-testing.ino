//This is a test to see if the relay module is working, not complicated but just to get an understanding of how to code using it.

/*
PINS SETUP:
ESP32 <-> Relay Module

    VIN = +

    GND = -

    D26 = S

*/


const int relayPin = 26; // Define the GPIO pin connected to the relay's IN pin

void setup() {
  // Initialize the relay pin as an output
  pinMode(relayPin, OUTPUT);
}

void loop() {
  digitalWrite(relayPin, HIGH); // Turn the relay ON
  delay(2000);                  // Wait for 2 seconds
  
  digitalWrite(relayPin, LOW);  // Turn the relay OFF
  delay(2000);                  // Wait for 2 seconds
}