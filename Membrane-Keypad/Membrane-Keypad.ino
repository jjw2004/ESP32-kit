#include <Keypad.h>

#define ROW_NUM   4 // four rows
#define COLUMN_NUM 4 // four columns

String secretCode = "1234"; //set this to whatever

String userCodeGuess = "";

//lookup table for membrane keypad
char keys[ROW_NUM][COLUMN_NUM] = {
 {'1', '2', '3', 'A'},
 {'4', '5', '6', 'B'},
 {'7', '8', '9', 'C'},
 {'*', '0', '#', 'D'}
};

byte pin_rows[ROW_NUM]   = {13, 12, 14, 27}; // D13, D12, D14, D27 are used from esp32 for rows on the membrane keypad
byte pin_column[COLUMN_NUM] = {26, 25, 33, 32};  // D26, D25, D33, D32 are used from esp32 for columns on the membrane keypad

Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

void setup() {
 Serial.begin(115200);
}

void loop() {
 char key = keypad.getKey();

 //logic for keypad input
  if (key){
    if ((key) != '#' && (key) != '*'){
      userCodeGuess += key;
      Serial.print(key);
    } else if ((key) == '#'){
        if ((userCodeGuess) == (secretCode)){
        Serial.println(" ");
        Serial.println("Correct Code");
        userCodeGuess.remove(0);
        } else {
          Serial.println(" ");
          Serial.println("Wrong Code");
          userCodeGuess.remove(0);
        } 
      } else if (key == '*'){
        userCodeGuess.remove(0);
        Serial.println(" ");
        Serial.println("Code Reset");
      } 
  }

}
