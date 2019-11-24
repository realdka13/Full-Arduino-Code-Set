#include "Arduino.h"
#include "HexDisplay.h"
#include <LedControl.h>

HexDisplay::HexDisplay(int dataPin, int clockPin, int csPin,int numberOfDisplays){
  lControl = LedControl(dataPin,clockPin,csPin,numberOfDisplays);
  /*
  	hex0[] =	
	hex1[] =

	*/
}

void HexDisplay::matrixSetup(int numberOfDisplays, int intensity)
{
  for(int i = 0; i < numberOfDisplays; i++)
  {
    lControl.shutdown(i,false);
    lControl.setIntensity(i, intensity);
    lControl.clearDisplay(numberOfDisplays);
  }
}

void HexDisplay::displayHex(int matrixNumber, int hexCode)
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
