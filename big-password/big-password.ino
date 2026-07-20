//big password builder, going to add more sensors to it
#include <Keypad.h>

#define ROW_NUM 4
#define COLUMN_NUM 4
#define NOTE_C4  262
#define NOTE_G4  392
#define NOTE_E4  330
#define NOTE_C5  523
#define BUZZER_PIN 18

const int relayPin = 4;

String secretCode = "123ABC676921";
String userCodeGuess = "";

char keys[ROW_NUM][COLUMN_NUM] = {
 {'1', '2', '3', 'A'},
 {'4', '5', '6', 'B'},
 {'7', '8', '9', 'C'},
 {'*', '0', '#', 'D'}
};

byte pin_rows[ROW_NUM]   = {13, 12, 14, 27};
byte pin_column[COLUMN_NUM] = {26, 25, 33, 32};  

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();

  if (key){
    if ((key) != '#' && (key) != '*'){
      userCodeGuess += key;
      Serial.print(key);
    } else if ((key) == '#'){
        if ((userCodeGuess) == (secretCode)){

          Serial.println(" ");
          Serial.println("Correct Code");

          //playing the buzzer to turn on relay
          tone(BUZZER_PIN, NOTE_C4, 150); delay(150);
          tone(BUZZER_PIN, NOTE_E4, 150); delay(150);
          tone(BUZZER_PIN, NOTE_G4, 150); delay(150);
          tone(BUZZER_PIN, NOTE_C5, 400); delay(400);
          noTone(BUZZER_PIN);

          //turning on the relay
          digitalWrite(relayPin, HIGH);
          delay(6000);
          digitalWrite(relayPin, LOW);
          userCodeGuess.remove(0);


        } else {
            Serial.println(" ");
            Serial.println("Wrong Code");

            for(int i = 0; i < 3; i++) {
              tone(BUZZER_PIN, 800, 200);  delay(200);
              tone(BUZZER_PIN, 500, 200);  delay(200);
            }
            noTone(BUZZER_PIN);

            userCodeGuess.remove(0);
        } 
      } else if (key == '*'){
          userCodeGuess.remove(0);
          Serial.println(" ");
          Serial.println("Code Reset");

          tone(BUZZER_PIN, 1500, 50);
          tone(BUZZER_PIN, 1500, 50);
          noTone(BUZZER_PIN);
      } 
  }
         
}
