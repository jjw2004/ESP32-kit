# Bluetooth DHT11 Project

This project uses two ESP32 boards to send temperature data over Bluetooth.

## Files
- `sender.ino` - Reads the DHT11 sensor and sends the temperature
- `reciever.ino` - Receives the data and displays it

## What you need
- 2 ESP32 boards
- DHT11 sensor
- OLED display (for the receiver)
- Arduino IDE

## How it works
1. The sender reads the temperature.
2. The sender sends the temperature over Bluetooth.
3. The receiver receives the data.

## Notes
- Make sure both boards are programmed correctly.
- The Bluetooth device names should match the code.

- I havent personally tested the range of the bluetooth either so if you are thinking to use this code for lets say a home monitor, maybe test how far you can send the data first.