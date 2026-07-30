//im not too sure how this one works, i just wanted to test the screen and see how much animation can actually fit onto it
//i will read over it and update the comments appropriately and add it to the normal reciever for future projects

#include "BluetoothSerial.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

BluetoothSerial SerialBT;

#define DEVICE_NAME "ESP32_RECEIVER"
#define OLED_ADDR   0x3C

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {

  Serial.begin(115200);

  SerialBT.begin("ESP32_RECEIVER", true); // true = client mode

  Serial.println("Connecting...");

  if (SerialBT.connect("ESP32_SENDER")) {

    Serial.println("Connected!");

  } else {

    Serial.println("Connection failed");

  }

  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.setTextSize(2);

}

// Animation variable
static int animFrame = 0;

void updateOLED(float temperature) {

  display.clearDisplay();

  // -------- TOP: Bluetooth status --------
  display.setTextSize(1);
  display.setTextColor(WHITE);

  display.setCursor(0, 0);
  display.print("BT: CONNECTED");

  // animated dots
  display.setCursor(100, 0);

  for (int i = 0; i < animFrame; i++) {
    display.print(".");
  }


  // -------- MIDDLE: Temperature --------
  display.setTextSize(2);

  String tempText = String(temperature, 1) + " C";

  int16_t x = (128 - (tempText.length() * 12)) / 2;

  display.setCursor(x, 25);
  display.print(tempText);


  // -------- Bottom --------
  display.setTextSize(1);
  display.setCursor(45, 55);
  display.print("DHT11");


  display.display();


  // update animation
  animFrame++;

  if (animFrame > 3) {
    animFrame = 0;
  }
}



void loop() {

 if (SerialBT.available()) {

  String received = SerialBT.readStringUntil('\n');

  int start = received.indexOf(":") + 1;
  int end = received.indexOf("°");

  String tempValue = received.substring(start, end);

  float temperature = tempValue.toFloat();

  Serial.print("Temperature: ");
  Serial.println(temperature);


  updateOLED(temperature);
}

}