#include "BluetoothSerial.h"   // Bluetooth library for ESP32

BluetoothSerial SerialBT;      // create Bluetooth object

#define DEVICE_NAME "ESP32_RECEIVER" // name of this Bluetooth device

void setup() {
  Serial.begin(115200);                 // start serial monitor output
  SerialBT.begin("ESP32_RECEIVER", true); // start Bluetooth in client mode

  Serial.println("Connecting...");

  if (SerialBT.connect("ESP32_SENDER")) { // try to connect to the sender device
    Serial.println("Connected!");
  } else {
    Serial.println("Connection failed");
  }
}

void loop() {
  if (SerialBT.available()) { // check if any Bluetooth data has arrived
    String received = SerialBT.readStringUntil('\n'); // read until newline
    Serial.print("Received: ");
    Serial.println(received);
  }
}