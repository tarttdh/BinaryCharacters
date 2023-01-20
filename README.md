/*
# BinaryCharacters
Follow code is in C flavored Arduino language. It Demonstrates the binary output of characters on keypad
Displaying Binary to LED 
Creator: Dillon Tartt H. 


Introduction
This project I designed a circuit that displays the binary notation of 4 bits. Using a 
green led light as the most significant bit and three blue led lights for the first three 
bits. The binary notation of 4 bits has a range from 0 – 15 decimal representation 
numbers. For this project I have constructed the keypad to implement 0-9 as well as A
– F for the following digits in range of 4 bit binary notation. In order to due this I had 
to reconstruct the keypad, convert asci-code characters into decimal notation. Convert 
decimal notation in to binary notation and display the correct binary notation in the
serial output data log. 

Ardunio Kit Components: 

Digital Pad
Arduino Board
4 positive wires
One ground wire
Circuit board
Three blue LED lights 
Once Green LED light 
4 Resistors 


Implementation: 


Step 2.1 

Displaying the Keypad correctly
Make sure to first represent the keypad with and E and a F for this to work to show all possible representation of 4-bit range binary code. 

  const byte ROWS = 4; //four rows
  const byte COLS = 4; //four columns
  //define the symbols on the buttons of the keypads
  char hexaKeys[ROWS][COLS] = {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    Had to convert ( # ) to ( E ) and ( * ) to (  F )
    {'F','0','E','D'} 
  };

Step 2.2 

Ascii-code to Decimal
I created a segment of code that changes the ascii-code of the character input from the keypad to its rightful representational decimal value. 

    Converts the ascii Value to a Decimal number.
  int asciiValueToDecimalNo(int asciiInput){
    used for the characters '0' - '9' since they have a asci – code from decimal 58 through 48.
	  if (asciiInput < 58){
  	  int j = asciiInput - 48;
  	  //convert characters to binary
	  return (toBinary(j));
	  }
	  else{
  	    used for the characters 'A' - 'F' since ‘A’  asci – code  starts at decimal 65 through .
  	  asciiInput = (asciiInput - 65);
  	  int p = asciiInput + 10;
  	  //convert characters to binary
  	  return (toBinary(p));
	  }



Step 2.3 


Decimal to binary

Next, I had to convert the decimal value to binary since the LED lights had to take
in each bit at a time in order to represent the binary notation. 
I constructed a recursive function in order to get the correct 
representation of binary notation.


  Takes in the decimal number to convert to binary notation.
    int toBinary(int decimalNo){
 
    I had to construct a base case for decimal digits 0 and 1
      if(decimalNo < 2){
      return decimalNo;
     }
 
      Keeps returning the rest of the decimal value until each recursion represents either a 0 or a 1 for the remainder.
      return toBinary(decimalNo / 2) * 10 + decimalNo %2;
      }

Step 2.4


Binary to Digit

In the segment I can across a problem. 
I knew that I could not display the entire
string of binary notation into each LED light. 
Therefore I separated each binary into separate digits. 


    for(int k = 0; k < 4; k++){
  	    separating each digit of binary output
         int digit = binary_name % 10;




Step 2.5 

Digit to Array of Digits


Even after separating each digit to binary the keypad serial output was still reading in the 
opposite direction. I then constructed
an array the pointed backwards and stored each digit into 
the array in order to display the correct binary notation. 


  Contstructing the Array needed.
    int myArray[4];
  	int y = 3;
 	  for(int k = 0; k < 4; k++){
  	…
	  Creates an array of digits to present the binary code correctly from right to left. 
	  myArray[y-k] = digit;
	  // Serial.print(digit); --> Used to test the output of digits.
 
… 	
  	}
  	for(int k = 0; k < 4; k++){
  Now Prints out the correct Binary notation.
  	Serial.print(myArray[k]);


*/
