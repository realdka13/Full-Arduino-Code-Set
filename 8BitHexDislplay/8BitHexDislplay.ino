#include <LedControl.h>

LedControl lControl=LedControl(2,4,3,2);  // Pins: DIN,CLK,CS, # of Display connected

byte hex0[] ={B00000000,B01111100,B11111110,B10010010,B10001010,B11111110,B01111100,B00000000};
byte hex1[] ={B00000000,B10000000,B10001000,B11111110,B11111110,B10000000,B10000000,B00000000};
byte hex2[] ={B00000000,B11000100,B11100110,B10100010,B10010010,B10011110,B10001100,B00000000};
byte hex3[] ={B00000000,B01000100,B11000110,B10010010,B10010010,B11111110,B01101100,B00000000};
byte hex4[] ={B00000000,B00110000,B00101000,B00100100,B11111110,B11111110,B00100000,B00000000};
byte hex5[] ={B00000000,B01001110,B11001110,B10001010,B10001010,B11111010,B01110010,B00000000};
byte hex6[] ={B00000000,B01111100,B11111110,B10010010,B10010010,B11110110,B01100100,B00000000};
byte hex7[] ={B00000000,B00000110,B00000110,B11100010,B11111010,B00011110,B00000110,B00000000};
byte hex8[] ={B00000000,B01101100,B11111110,B10010010,B10010010,B11111110,B01101100,B00000000};
byte hex9[] ={B00000000,B01001100,B11011110,B10010010,B10010010,B11111110,B01111100,B00000000};
byte hexA[] ={B00000000,B11111100,B11111110,B00010010,B00010010,B11111110,B11111100,B00000000};
byte hexB[] ={B00000000,B11111110,B11111110,B10010010,B10010010,B11111110,B01101100,B00000000};
byte hexC[] ={B00000000,B01111100,B11111110,B10000010,B10000010,B11000110,B01000100,B00000000};
byte hexD[] ={B00000000,B11111110,B11111110,B10000010,B10000010,B11111110,B01111100,B00000000};
byte hexE[] ={B00000000,B11111110,B11111110,B10010010,B10010010,B10010010,B10000010,B00000000};
byte hexF[] ={B00000000,B11111110,B11111110,B00010010,B00010010,B00010010,B00000010,B00000000};

void displayHex(int matrixNumber, int hexCode)
{
  if(hexCode == 0)
  {
    for (int i = 0; i < 8; i++)  
    {
      lControl.setRow(matrixNumber,i,hex0[i]);
    }
  }
  else if(hexCode == 1)
  {
    for (int i = 0; i < 8; i++)  
    {
      lControl.setRow(matrixNumber,i,hex1[i]);
    }
  }
  else if(hexCode == 2)
  {
    for (int i = 0; i < 8; i++)  
    {
      lControl.setRow(matrixNumber,i,hex2[i]);
    }
  }
  else if(hexCode == 3)
  {
    for (int i = 0; i < 8; i++)  
    {
      lControl.setRow(matrixNumber,i,hex3[i]);
    }
  }
  else if(hexCode == 4)
  {
    for (int i = 0; i < 8; i++)  
    {
      lControl.setRow(matrixNumber,i,hex4[i]);
    }
  }
  else if(hexCode == 5)
  {
    for (int i = 0; i < 8; i++)  
    {
      lControl.setRow(matrixNumber,i,hex5[i]);
    }
  }
  else if(hexCode == 6)
  {
    for (int i = 0; i < 8; i++)  
    {
      lControl.setRow(matrixNumber,i,hex6[i]);
    }
  }
  else if(hexCode == 7)
  {
    for (int i = 0; i < 8; i++)  
    {
      lControl.setRow(matrixNumber,i,hex7[i]);
    }
  }
  else if(hexCode == 8)
  {
    for (int i = 0; i < 8; i++)  
    {
      lControl.setRow(matrixNumber,i,hex8[i]);
    }
  }
  else if(hexCode == 9)
  {
    for (int i = 0; i < 8; i++)  
    {
      lControl.setRow(matrixNumber,i,hex9[i]);
    }
  }
  else if(hexCode == 10)
  {
    for (int i = 0; i < 8; i++)  
    {
      lControl.setRow(matrixNumber,i,hexA[i]);
    }
  }
  else if(hexCode == 11)
  {
    for (int i = 0; i < 8; i++)  
    {
      lControl.setRow(matrixNumber,i,hexB[i]);
    }
  }
  else if(hexCode == 12)
  {
    for (int i = 0; i < 8; i++)  
    {
      lControl.setRow(matrixNumber,i,hexC[i]);
    }
  }
  else if(hexCode == 13)
  {
    for (int i = 0; i < 8; i++)  
    {
      lControl.setRow(matrixNumber,i,hexD[i]);
    }
  }
  else if(hexCode == 14)
  {
    for (int i = 0; i < 8; i++)  
    {
      lControl.setRow(matrixNumber,i,hexE[i]);
    }
  }
  else if(hexCode == 15)
  {
    for (int i = 0; i < 8; i++)  
    {
      lControl.setRow(matrixNumber,i,hexF[i]);
    }
  }
  else
  {}
}

void setup()
{
  lControl.shutdown(0,false);  // Wake up displays
  lControl.shutdown(1,false);
  lControl.setIntensity(0,5);  // Set intensity levels
  lControl.setIntensity(1,5);
  lControl.clearDisplay(0);  // Clear Displays
  lControl.clearDisplay(1);
}

void loop()
{
  displayHex(0,0);
  displayHex(1,0);
  delay(250);
  
  displayHex(0,1);
  displayHex(1,1);
  delay(250);

  displayHex(0,2);
  displayHex(1,2);
  delay(250);

  displayHex(0,3);
  displayHex(1,3);
  delay(250);

  displayHex(0,4);
  displayHex(1,4);
  delay(250);

  displayHex(0,5);
  displayHex(1,5);
  delay(250);

  displayHex(0,6);
  displayHex(1,6);
  delay(250);

  displayHex(0,7);
  displayHex(1,7);
  delay(250);

  displayHex(0,8);
  displayHex(1,8);
  delay(250);

  displayHex(0,9);
  displayHex(1,9);
  delay(250);

  displayHex(0,10);
  displayHex(1,10);
  delay(250);

  displayHex(0,11);
  displayHex(1,11);
  delay(250);

  displayHex(0,12);
  displayHex(1,12);
  delay(250);

  displayHex(0,13);
  displayHex(1,13);
  delay(250);

  displayHex(0,14);
  displayHex(1,14);
  delay(250);

  displayHex(0,15);
  displayHex(1,15);
  delay(250);
}
