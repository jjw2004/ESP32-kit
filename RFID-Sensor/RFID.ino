#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 5
#define RST_PIN 21

MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);

  SPI.begin();        // Start SPI bus
  rfid.PCD_Init();    // Initialize RC522

  Serial.println("RFID reader ready...");
  Serial.println("Scan a card/tag");
}

void loop() {

  // Look for a new card
  if (!rfid.PICC_IsNewCardPresent()) {
    return;
  }

  // Select the card
  if (!rfid.PICC_ReadCardSerial()) {
    return;
  }

  Serial.print("Card UID: ");

  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(rfid.uid.uidByte[i], HEX);
  }

  Serial.println();

  // Stop reading this card
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  delay(1000);
}