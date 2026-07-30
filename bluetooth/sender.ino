#include "BluetoothSerial.h" // ESP32 Bluetooth library
#include <DHT.h> // DHT sensor library

#define DHTPIN 5 // GPIO pin where the DHT11 is connected
#define DHTTYPE DHT11// tell the library we are using a DHT11 sensor

BluetoothSerial SerialBT; // create a Bluetooth object
DHT dht(DHTPIN, DHTTYPE); // create a DHT sensor object

void setup() {
  Serial.begin(115200); // start normal serial communication for debugging
  SerialBT.begin("ESP32_SENDER"); // start Bluetooth and give it a device name
  dht.begin(); // initialize the DHT sensor
  Serial.println("Bluetooth Started"); // print a message to the serial monitor
}

void loop() {
  float temperature = dht.readTemperature(); // read temperature in Celsius

  SerialBT.print("Temperature: "); // send text over Bluetooth
  SerialBT.print(temperature); // send the temperature value
  SerialBT.println(" °C");     // send the unit and end the line

  Serial.print("Sent: "); // print to USB serial for debugging
  Serial.println(temperature)

  delay(1000); // wait 1 second before taking another reading
}