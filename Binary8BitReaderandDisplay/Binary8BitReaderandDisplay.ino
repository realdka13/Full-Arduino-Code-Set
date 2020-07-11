#include <HexDisplay.h>

//
HexDisplay hexDis(2,4,3,2);

String Read4LSB()
{
  String BTwelv = "0";
  String BElev = "0";
  String BTen = "0";
  String BNine = "0";

  if(digitalRead(12)){BTwelv = "1";}
  if(digitalRead(11)){BElev = "1";}
  if(digitalRead(10)){BTen = "1";}
  if(digitalRead(9)){BNine = "1";}
  
  return (BNine + BTen + BElev + BTwelv);
}

String Read4MSB()
{
  String BEight = "0";
  String BSev = "0";
  String BSix = "0";
  String BFive = "0";

  if(digitalRead(8)){BEight = "1";}
  if(digitalRead(7)){BSev = "1";}
  if(digitalRead(6)){BSix = "1";}
  if(digitalRead(5)){BFive = "1";}
  
  return (BFive + BSix + BSev + BEight);
}

void setup() 
{
  hexDis.matrixSetup(2,8);

  //Setup reading pins
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
}

void loop() 
{
  String first4;
  String last4;
  
  //Set First Matrix
  first4 = Read4MSB();
  if(first4 == "0000"){hexDis.displayHex(0,0);}
  else if(first4 == "0001"){hexDis.displayHex(0,1);}
  else if(first4 == "0010"){hexDis.displayHex(0,2);}
  else if(first4 == "0011"){hexDis.displayHex(0,3);}
  else if(first4 == "0100"){hexDis.displayHex(0,4);}
  else if(first4 == "0101"){hexDis.displayHex(0,5);}
  else if(first4 == "0110"){hexDis.displayHex(0,6);}
  else if(first4 == "0111"){hexDis.displayHex(0,7);}
  else if(first4 == "1000"){hexDis.displayHex(0,8);}
  else if(first4 == "1001"){hexDis.displayHex(0,9);}
  else if(first4 == "1010"){hexDis.displayHex(0,10);}
  else if(first4 == "1011"){hexDis.displayHex(0,11);}
  else if(first4 == "1100"){hexDis.displayHex(0,12);}
  else if(first4 == "1101"){hexDis.displayHex(0,13);}
  else if(first4 == "1110"){hexDis.displayHex(0,14);}
  else if(first4 == "1111"){hexDis.displayHex(0,15);}
  
  //Set Last Matrix
  last4 = Read4LSB();
  if(last4 == "0000"){hexDis.displayHex(1,0);}
  else if(last4 == "0001"){hexDis.displayHex(1,1);}
  else if(last4 == "0010"){hexDis.displayHex(1,2);}
  else if(last4 == "0011"){hexDis.displayHex(1,3);}
  else if(last4 == "0100"){hexDis.displayHex(1,4);}
  else if(last4 == "0101"){hexDis.displayHex(1,5);}
  else if(last4 == "0110"){hexDis.displayHex(1,6);}
  else if(last4 == "0111"){hexDis.displayHex(1,7);}
  else if(last4 == "1000"){hexDis.displayHex(1,8);}
  else if(last4 == "1001"){hexDis.displayHex(1,9);}
  else if(last4 == "1010"){hexDis.displayHex(1,10);}
  else if(last4 == "1011"){hexDis.displayHex(1,11);}
  else if(last4 == "1100"){hexDis.displayHex(1,12);}
  else if(last4 == "1101"){hexDis.displayHex(1,13);}
  else if(last4 == "1110"){hexDis.displayHex(1,14);}
  else if(last4 == "1111"){hexDis.displayHex(1,15);}
}
