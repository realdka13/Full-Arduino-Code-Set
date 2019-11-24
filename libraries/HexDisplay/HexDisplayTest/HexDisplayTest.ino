#include <HexDisplay.h>;

HexDisplay hexDis(2,4,3,2);

void setup()
{
  hexDis.matrixSetup(2,8);
}

void loop()
{  
  hexDis.displayHex(0,0);
  hexDis.displayHex(1,0);
  delay(250);
  
  hexDis.displayHex(0,1);
  hexDis.displayHex(1,1);
  delay(250);

  hexDis.displayHex(0,2);
  hexDis.displayHex(1,2);
  delay(250);

  hexDis.displayHex(0,3);
  hexDis.displayHex(1,3);
  delay(250);

  hexDis.displayHex(0,4);
  hexDis.displayHex(1,4);
  delay(250);

  hexDis.displayHex(0,5);
  hexDis.displayHex(1,5);
  delay(250);

  hexDis.displayHex(0,6);
  hexDis.displayHex(1,6);
  delay(250);

  hexDis.displayHex(0,7);
  hexDis.displayHex(1,7);
  delay(250);

  hexDis.displayHex(0,8);
  hexDis.displayHex(1,8);
  delay(250);

  hexDis.displayHex(0,9);
  hexDis.displayHex(1,9);
  delay(250);

  hexDis.displayHex(0,10);
  hexDis.displayHex(1,10);
  delay(250);

  hexDis.displayHex(0,11);
  hexDis.displayHex(1,11);
  delay(250);

  hexDis.displayHex(0,12);
  hexDis.displayHex(1,12);
  delay(250);

  hexDis.displayHex(0,13);
  hexDis.displayHex(1,13);
  delay(250);

  hexDis.displayHex(0,14);
  hexDis.displayHex(1,14);
  delay(250);

  hexDis.displayHex(0,15);
  hexDis.displayHex(1,15);
  delay(250);
}
