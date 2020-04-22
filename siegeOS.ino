#include <LedControl.h>
#include <binary.h>
int lcDIN = 10;
int lcCS =  9;
int lcCLK = 8;

int lc2DIN = 7;
int lc2CS =  6;
int lc2CLK = 5;

LedControl lc = LedControl(lcDIN,lcCLK,lcCS,7); // DIN CLK CS DISPNUM
LedControl lc2 = LedControl(lc2DIN,lc2CLK,lc2CS,7); // DIN CLK CS DISPNUM

int dispBrightness = 15; // Adjust the brightness, maximum is 15

// Display States (Left Side)
byte dispMouth1[8] = {B00100000,B01111000,B11011110,B11000111,B11111111,B00000000,B00000000,B00000000};
byte dispMouth2[8] = {B00000000,B00000000,B00000000,B10000000,B11100000,B01111000,B00011110,B00000111};
byte dispMouth3[8] = {B00000000,B00000000,B00000000,B00000000,B00000111,B00011110,B01111000,B11100000};
byte dispMouth4[8] = {B00000000,B00000000,B00000000,B11100000,B11111000,B00011110,B00000111,B00000001};

byte dispEyeAngry1[8] = {B00000000,B00011111,B00111111,B00111111,B00011111,B00001111,B00000011,B00000000};
byte dispEyeAngry2[8] = {B00000000,B11111100,B11111110,B11111100,B11111000,B11100000,B10000000,B00000000};

byte dispEyeNormal1[8] = {B00001111,B00111111,B01111111,B11111111,B11110000,B01100000,B00000000,B00000000};
byte dispEyeNormal2[8] = {B00000000,B11100000,B11111000,B11111110,B00000111,B00000001,B00000000,B00000000};

byte dispEyeBleep1[8] = {B00000001,B00000111,B00000111,B00001111,B00001111,B00000111,B00000111,B00000001};
byte dispEyeBleep2[8] = {B10000000,B11100000,B11100000,B11110000,B11110000,B11100000,B11100000,B10000000};

byte dispNose[8] = {B00000000,B01111110,B00111111,B00000011,B00000011,B00000001,B00000000,B00000000};


// Display States (Right Side)
byte dispMouth1Mirror[8] = {B00000000,B00000000,B00000000,B00000111,B00011111,B01111000,B11100000,B10000000};
byte dispMouth2Mirror[8] = {B00000000,B00000000,B00000000,B00000000,B11100000,B01111000,B00011110,B00000111};
byte dispMouth3Mirror[8] = {B00000000,B00000000,B00000000,B00000001,B00000111,B00011110,B01111000,B11100000};
byte dispMouth4Mirror[8] = {B00000100,B00011110,B01111011,B11100011,B11111111,B00000000,B00000000,B00000000};

byte dispEyeAngry1Mirror[8] = {B00000000,B00111111,B01111111,B00111111,B00011111,B00000111,B00000001,B00000000};
byte dispEyeAngry2Mirror[8] = {B00000000,B11111000,B11111100,B11111100,B11111000,B11110000,B11000000,B00000000};

byte dispEyeNormal1Mirror[8] = {B00000000,B00000111,B00011111,B01111111,B11100000,B10000000,B00000000,B00000000};
byte dispEyeNormal2Mirror[8] = {B11110000,B11111100,B11111110,B11111111,B00001111,B00000110,B00000000,B00000000};

byte dispEyeBleep1Mirror[8] = {B00000001,B00000111,B00000111,B00001111,B00001111,B00000111,B00000111,B00000001};
byte dispEyeBleep2Mirror[8] = {B10000000,B11100000,B11100000,B11110000,B11110000,B11100000,B11100000,B10000000};

byte dispNoseMirror[8] = {B00000000,B01111110,B11111100,B11000000,B11000000,B10000000,B00000000,B00000000};


void setup(){

  Serial.begin(9600);

  // -- Display Initialization --
  
  // Display 1
  lc.shutdown(0,false);       
  lc.setIntensity(0,dispBrightness);
  lc.clearDisplay(0);    

  // Display 2
  lc.shutdown(1,false);       
  lc.setIntensity(1,dispBrightness);
  lc.clearDisplay(1);    

  // Display 3
  lc.shutdown(2,false);       
  lc.setIntensity(2,dispBrightness);
  lc.clearDisplay(2);    

  // Display 4
  lc.shutdown(3,false);       
  lc.setIntensity(3,dispBrightness);
  lc.clearDisplay(3);    

  // Display 5
  lc.shutdown(4,false);       
  lc.setIntensity(4,dispBrightness);
  lc.clearDisplay(4);    

  // Display 6
  lc.shutdown(5,false);       
  lc.setIntensity(5,dispBrightness);
  lc.clearDisplay(5);    

  // Display 7
  lc.shutdown(6,false);       
  lc.setIntensity(6,dispBrightness);
  lc.clearDisplay(6);    

  // -- Next Side --

  // Display 8
  lc2.shutdown(0,false);       
  lc2.setIntensity(0,dispBrightness);
  lc2.clearDisplay(0);    

  // Display 9
  lc2.shutdown(1,false);       
  lc2.setIntensity(1,dispBrightness);
  lc2.clearDisplay(1);    

  // Display 10
  lc2.shutdown(2,false);       
  lc2.setIntensity(2,dispBrightness);
  lc2.clearDisplay(2);    

  // Display 11
  lc2.shutdown(3,false);       
  lc2.setIntensity(3,dispBrightness);
  lc2.clearDisplay(3);    

  // Display 12
  lc2.shutdown(4,false);       
  lc2.setIntensity(4,dispBrightness);
  lc2.clearDisplay(4);    

  // Display 13
  lc2.shutdown(5,false);       
  lc2.setIntensity(5,dispBrightness);
  lc2.clearDisplay(5);    

  // Display 14
  lc2.shutdown(6,false);       
  lc2.setIntensity(6,dispBrightness);
  lc2.clearDisplay(6);     
}

void dispByte(int dispNum, byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(dispNum,i,character[i]);
  }
}


void dispByte2(int dispNum2, byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc2.setRow(dispNum2,i,character[i]);
  }
}

void loop(){     

  Serial.print("[DEBUG] Loop Begin");
  Serial.println(); 

  // -- DEFAULT --
  //Right
  dispByte(1,dispMouth1);   
  dispByte(2,dispMouth2); 
  dispByte(3,dispMouth3); 
  dispByte(4,dispMouth4); 
  dispByte(5,dispEyeNormal1);
  dispByte(6,dispEyeNormal2);
  dispByte(7,dispNose);

  //Left
  dispByte2(1,dispMouth1Mirror);    
  dispByte2(2,dispMouth2Mirror); 
  dispByte2(3,dispMouth3Mirror); 
  dispByte2(4,dispMouth4Mirror); 
  dispByte2(5,dispEyeNormal1Mirror);
  dispByte2(6,dispEyeNormal2Mirror);

  delay(1000);
  
  Serial.print("[DEBUG] Loop End");
  Serial.println(); 
}

/*
    Copyright © 2020 Titus Studios Media. To be distributed under the MIT Licence.

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/
