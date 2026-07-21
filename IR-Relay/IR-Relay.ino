#include <IRremote.hpp>

#define IR_RECEIVE_PIN 4
#define RELAY_PIN 22

bool relayState = false;

unsigned long lastPowerPress = 0;
const unsigned long cooldown = 5000; // 5 seconds

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("System Ready");
}

void loop() {

  if (IrReceiver.decode()) {
    if (IrReceiver.decodedIRData.command == 0x45) {
      unsigned long currentTime = millis();
      // Only accept if 5 seconds have passed... this is to stop constant turning on and off with the dinky remote
      if (currentTime - lastPowerPress >= cooldown) {
        relayState = !relayState;
        digitalWrite(RELAY_PIN, relayState ? HIGH : LOW);
        if (relayState) {
          Serial.println("Relay ON");
        } else {
          Serial.println("Relay OFF");
        }
        lastPowerPress = currentTime;
      }
      else {
        Serial.println("Ignored - cooldown");
      }
    }
    IrReceiver.resume();
  }

}