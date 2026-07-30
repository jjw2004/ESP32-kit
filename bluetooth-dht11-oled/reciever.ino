#include "BluetoothSerial.h" // Bluetooth library for ESP32
#include <Wire.h> // I2C communication library for OLED
#include <Adafruit_GFX.h> // Core graphics library for OLED
#include <Adafruit_SSD1306.h> // OLED display library

BluetoothSerial SerialBT; // Create a Bluetooth object

#define DEVICE_NAME "ESP32_RECEIVER" // Name of this Bluetooth device
#define OLED_ADDR   0x3C // I2C address of the OLED display

Adafruit_SSD1306 display(128, 64, &Wire, -1); // Create the OLED display object

void setup() {

  Serial.begin(115200); // Start serial communication for debugging

  SerialBT.begin("ESP32_RECEIVER", true); // Start Bluetooth in client mode

  Serial.println("Connecting..."); // Print a message while trying to connect

  if (SerialBT.connect("ESP32_SENDER")) { // Try to connect to the sender device

    Serial.println("Connected!"); // Print success message if connected

  } else {

    Serial.println("Connection failed"); // Print failure message if not connected

  }

  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR); // Initialize the OLED display
  display.clearDisplay(); // Clear anything already on the screen
  display.setTextSize(2); // Set the text size for the display
}

void loop() {

  if (SerialBT.available()) { // Check if Bluetooth data is available

    String received = SerialBT.readStringUntil('\n'); // Read incoming data until newline

    Serial.print("Received: "); // Print a label to the serial monitor
    Serial.println(received); // Print the received message

    // OLED DISPLAY
    display.clearDisplay(); // Clear the OLED before drawing new text

    display.setCursor(0,0); // Move cursor to the top-left corner
    display.setTextSize(1); // Set text size for the OLED
    display.setTextColor(WHITE); // Set text color

    display.println(received); // Print the received message on the OLED

    display.display(); // Show the new contents on the screen
  }
}