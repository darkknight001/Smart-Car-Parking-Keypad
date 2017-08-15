#include <Keypad.h> //include keypad library

const byte ROWS = 3; // Four rows
const byte COLS = 3; // Three columns

// Define the Keymap
char keys[ROWS][COLS] = {
  {'1', '2', '3'},  
  {'4', '5', '6'},
  {'7', '8', '9'}
};

byte rowPins[ROWS] = { 2, 3, 4 }; // Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.

byte colPins[COLS] = { 5, 6, 7 }; // Connect keypad COL0, COL1 and COL2 to these Arduino pins.


Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //make Keypad object


void setup()
{
  pinMode(8, OUTPUT);   //defining led pins
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

}

void loop()
{
  char key = kpd.getKey(); //get the key
  if (key) // Check for a valid key.
  {
    switch (key)
    {
      case '1':     //if key 1 is pressed
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        break;
      case '2':     //if key 1 is pressed
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        break;
      case '3':     //if key 3 is pressed
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        break;
      case '4':     //if key 4 is pressed
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        break;
      case '5':     //if key 5 is pressed
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        break;
      case '6':     //if key 6 is pressed
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        break;
      case '7':     //if key 7 is pressed
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        break;
      case '8':     //if key 8 is pressed
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        break;
      case '9':     //if key 1 is pressed
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        break;
      default:
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
    }
  }
}
