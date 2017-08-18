#include <Password.h> //http://playground.arduino.cc/uploads/Code/Password.zip use password library
#include <Keypad.h> //http://www.arduino.cc/playground/uploads/Code/Keypad.zip  //tells to use keypad library
 //password to unlock box, can be changed

const byte ROWS = 4; // Four rows
const byte COLS = 3; // columns
// Define the Keymap
char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 2,3,4,5 };// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 6,7,8 };


// Create the Keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
 Password password;
void setup(){
  Serial.begin(9600);
  //Serial.write(254);
  Serial.write(0x01);
  Serial.print("Enter: ");
  delay(200); 
  pinMode(11, OUTPUT);  //green light
  pinMode(12, OUTPUT);  //red light
  keypad.addEventListener(keypadEvent); //add an event listener for this keypad
  String Test = "";   
  password  = Password(test);
  }
void loop(){
  keypad.getKey();
  
  }
  

  //take care of some special events
  void keypadEvent(KeypadEvent eKey){

  switch (keypad.getState()){
  case PRESSED:
  
  if(eKey == '#')
  Serial.println("Password Cleared!");
  else if(eKey == '*')
  Serial.print("");
  else
  Serial.print(eKey);
  
  
  delay(10);
  
  //Serial.write(254);
  
  switch (eKey){
    case '*': checkPassword(); Serial.println("");delay(1); break;
    
    case '#': password.reset(); delay(1); break;
    
     default: password.append(eKey); delay(1);
}
}
}
void checkPassword(){
  
if (password.evaluate()){  //if password is right open box
    Serial.println("");
    Serial.println("Accepted");
    delay(10);
    password.reset();
    //Add code to run if it works
    
        digitalWrite(11, HIGH);//turn on
    delay(1000); //wait 5 seconds
    digitalWrite(11, LOW);// turn off
    
    
}else{
    Serial.println("");
    Serial.println("Denied"); //if passwords wrong keep box locked
    //Serial.write(254);
    delay(10);
    password.reset();
    //add code to run if it did not work
    digitalWrite(12, HIGH); //turn on
    delay(1000); //wait 5 seconds
    digitalWrite(12, LOW);//turn off
    
}
}

