
/* @file FinalProject.ino
|| @version 1.0
|| @author Dillon Tartt 
|| @contact tarttdh@g.cofc.edu
|| @Professor Kebin Xu 
|| @Class 250 Lab 
||
|| @description
|| | Demonstrates the binary output of characters on keypad. 
|| #
*/

#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  //Had to convert # to E and * to F
  {'F','0','E','D'}  
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

//create the led pins 
const int ledPin1 = 10;
const int ledPin2 = 11;
const int ledPin3 = 12;
const int ledPin4 = 13;

void setup(){
  Serial.begin(9600);
   // initialize digital pin LED_BUILTIN as an output.
  int i;
  for(i=10;i<14;i++){
  pinMode(i , OUTPUT);
  digitalWrite(i,LOW);
  }
}

//decimal number to binary number.
int toBinary(int decimalNo){

  //base case
   if(decimalNo < 2){
   return decimalNo;
  }

  //Recursive Case 
  return toBinary(decimalNo / 2) * 10 + decimalNo %2;
  }

// Converts the ascii Value to a Decimal number. 
int asciiValueToDecimalNo(int asciiInput){
  //for characters '0' - '9' 
    if (asciiInput < 58){
      int j = asciiInput - 48; 
      //convert characters to binary 
    return (toBinary(j));
    }
    else{
      //for characters 'A' - 'F' 
      asciiInput = (asciiInput - 65);
      int p = asciiInput + 10; 
      //convert characters to binary 
      return (toBinary(p));
    }
  }
  
void loop(){
  // intialized the data types for binary output 
  int binary_name;
  
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.print(customKey);
    Serial.print("; "); 
    // convert character to integer datatype
    int ch = customKey;
        // convert acciValue to binary output
     binary_name = (asciiValueToDecimalNo(ch));
     //Serial.print(binary_name);
     int myArray[4]; 
     int y = 3;
     for(int k = 0; k < 4; k++){
      //separating each digit of binary output 
     int digit = binary_name % 10; 
    binary_name = binary_name/10;
    //Creates an array of digits to present the binary code correctly from right to left.  
    myArray[y-k] = digit;
    // Serial.print(digit); --> Used to test the output of digits. 

     //LedPins light up to represent the binary output. 
      if(digit == 1 && k == 0){
        digitalWrite(ledPin1,HIGH);
      }
      else if(digit == 1 && k == 1){
        digitalWrite(ledPin2,HIGH);
      }
      else if(digit == 1 && k == 2){
        digitalWrite(ledPin3,HIGH);
      }
      else if(digit == 1 && k ==3){
        digitalWrite(ledPin4,HIGH);
      }
     
     }
     for(int k = 0; k < 4; k++){
     Serial.print(myArray[k]);
     }
     Serial.println();
     delay(1000);
     //To restart for next character input. 
      digitalWrite(ledPin1,LOW);
      digitalWrite(ledPin2,LOW);
      digitalWrite(ledPin3,LOW);
      digitalWrite(ledPin4,LOW);
  }
}
