#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define DHTPIN 5        // Pin connected to DHT11
#define DHTTYPE DHT11   // DHT11 sensor
#define OLED_ADDR   0x3C

Adafruit_SSD1306 display(128, 64, &Wire, -1);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.setTextSize(2);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  
  /*
  old serial displays
  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °C");
  */
  display.setCursor(0, 0);
  display.setTextColor(WHITE);
  display.display();
  display.clearDisplay();

  if (temperature > 25) {
    Serial.println(temperature);
    display.println("ITS HOT!!");
    display.println(temperature);
    } 
  else if (temperature < 25 && temperature > 15){
    Serial.println(temperature);
    display.println("its warm");
    display.println(temperature);
    }
  else {
    Serial.println(temperature);
    display.println("its cool");
    display.println(temperature);
  }

  delay(4000);

  /*
  display.setCursor(20, 20);
  display.clearDisplay();
  display.display();
  delay(4000);
  */
}