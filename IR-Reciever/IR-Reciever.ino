#include <IRremote.hpp>

#define IR_RECEIVE_PIN 4

void setup() {
  Serial.begin(115200);

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  Serial.println("IR Receiver Ready");
}

void loop() {
  if (IrReceiver.decode()) {

    switch (IrReceiver.decodedIRData.command) {

      // Power / Media Controls
      case 0x45:
        Serial.println("POWER");
        break;

      case 0x46:
        Serial.println("VOL+");
        break;

      case 0x15:
        Serial.println("VOL -");
        break;

      case 0x44:
        Serial.println("PREVIOUS");
        break;

      case 0x43:
        Serial.println("SKIP");
        break;

      case 0x40:
        Serial.println("PAUSE/PLAY");
        break;

      case 0x47:
        Serial.println("FUNC/STOP");
        break;

      // Navigation
      case 0x09:
        Serial.println("UP");
        break;

      case 0x07:
        Serial.println("DOWN");
        break;

      // Special Buttons
      case 0x19:
        Serial.println("EQ");
        break;

      case 0x0D:
        Serial.println("ST/REPT");
        break;

      // Numbers
      case 0x16:
        Serial.println("0");
        break;
      
      case 0x0C:
        Serial.println("1");
        break;

      case 0x18:
        Serial.println("2");
        break;

      case 0x5E:
        Serial.println("3");
        break;

      case 0x08:
        Serial.println("4");
        break;

      case 0x1C:
        Serial.println("5");
        break;

      case 0x5A:
        Serial.println("6");
        break;

      case 0x42:
        Serial.println("7");
        break;

      case 0x52:
        Serial.println("8");
        break;

      case 0x4A:
        Serial.println("9");
        break;

      default:
        Serial.print("Unknown Command: 0x");
        Serial.println(IrReceiver.decodedIRData.command, HEX);
        break;
    }

    IrReceiver.resume();
  }
}