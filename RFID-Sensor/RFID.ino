#include <MFRC522v2.h>
#include <MFRC522DriverSPI.h>
#include <MFRC522DriverPinSimple.h>
#include <MFRC522Debug.h>

MFRC522DriverPinSimple ss_pin(5);
MFRC522DriverSPI driver{ss_pin};
MFRC522 mfrc522{driver};

byte welcomeCard[] = {
  0x9B, 0x54, 0x17, 0x07
};

byte welcomeFob[] = {
  0x8C, 0x0E, 0x32, 0x07
};


bool checkUID(byte *storedUID, byte storedSize) {

  if (mfrc522.uid.size != storedSize) {
    return false;
  }

  for (byte i = 0; i < storedSize; i++) {
    if (mfrc522.uid.uidByte[i] != storedUID[i]) {
      return false;
    }
  }

  return true;
}


void setup() {

  Serial.begin(115200);
  while (!Serial);

  mfrc522.PCD_Init();

  Serial.println("RFID Ready");
  Serial.println("Scan a card...");
}


void loop() {

  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }


  if (checkUID(welcomeCard, sizeof(welcomeCard))) {

    Serial.println("WELCOME CARD!");
    Serial.println("Access granted.");

  }

  else if (checkUID(welcomeFob, sizeof(welcomeFob))) {

    Serial.println("FOB NOT WELCOME!");
    Serial.println("Access denied.");

  }

  else {

    Serial.println("UNKNOWN RFID");
    Serial.println("Access denied.");

  }


  Serial.println("----------------");

  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();

  delay(2000);
}