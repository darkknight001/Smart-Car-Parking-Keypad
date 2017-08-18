#include <Keypad.h> //include keypad library

const byte ROWS = 4; // Four rows
const byte COLS = 3; // Three columns
int v1;
int v2;
int v3;
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = { 2, 3 ,4, 5}; // Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.

byte colPins[COLS] = { 6, 7, 8}; // Connect keypad COL0, COL1 and COL2 to these Arduino pins.


Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); //make Keypad object

int num = 0;
int temp;
boolean flag = false;
void setup(){

Serial.begin(9600);


  
}


String check = "1234";

void loop()
{
   v1 = GetNumber();
   temp = check.toInt();
   Serial.print(temp);
   if(temp == v1 && flag == false){

    flag = true;
    Serial.println("Correct OTP: ");
   }
   
}

int GetNumber()
{
   
   char key1 = kpd.getKey();
   switch (key1)
   {
     case NO_KEY:
      break;

    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
      Serial.print(key1);
      num = num * 10 + (key1 - '0');
      break;

    case '*':
        Serial.println("");
        Serial.print("your pin is:");
        Serial.println(num);
        return num;
  
  
        break;

    case '#':
        num = 0;
        
        Serial.println("");
        
   }
}
