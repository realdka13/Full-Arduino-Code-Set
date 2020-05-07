//Shift Register Pins
//For Both SR
#define clr 8 //Active Low
#define outputClk 6
#define outputEn 7 //Active Low

//For Data SR
#define shiftDataClk 4
#define dataIn 2

//For Addr SR
#define shiftAddrClk 5
#define addrIn 3

//8 Bit Computer Pins
#define confirm 12 //Active Low
#define buttonPin 11

//Button Variables
int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;
bool turnedOnPreviously = 0;

//Time Variables
unsigned long previousMillis = 0;
const long interval = 3000; // In miliseconds (1000 ms = 1 s)

//Address Cycle Variables
int addr = -1;  //Start at -1 to account for iterating it the first time ie, make it zero the first time its passed to Cycle Adresses

//Programs Variable
const int numberOfProgramsSaved = 3;

//Programs
const byte TestSequence[] = {0x1D, 0x2E, 0x3F, 0xE0, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0A, 0x02, 0x08}; //Program 1
const byte Fibinachi[] = {0x51, 0x4E, 0x50, 0x4F, 0xE0, 0x1E, 0x2F, 0x4E, 0xE0, 0x1F, 0x2E, 0x70,0x63, 0x00, 0x00, 0x00}; //Program 2
const byte Multiply_14_8[] = {0x1E, 0x3C, 0x76, 0x1D, 0xE0, 0xF0, 0x4E, 0x1D, 0x2F, 0x4D, 0x60, 0x00, 0x01, 0x00, 0x0E, 0x08}; //Program 3

void setup() 
{
  pinMode(clr, OUTPUT);
  pinMode(outputClk, OUTPUT);
  pinMode(outputEn, OUTPUT);
  pinMode(shiftDataClk, OUTPUT);
  pinMode(dataIn, OUTPUT);
  pinMode(shiftAddrClk, OUTPUT);
  pinMode(addrIn, OUTPUT);
  pinMode(confirm, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  //Reset SR Data
  digitalWrite(clr, LOW);
  delay(1);
  digitalWrite(clr, HIGH);
  //Make sure Output is Disabled
  digitalWrite(clr, HIGH);
}

void loop() 
{ 
////***** Program *****
  ListenForButton();

  //***Cycle through Addresses if enough time has passed ()
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) 
  {
    previousMillis = currentMillis;
    if(addr == 15)
    {
      addr = 0;
    }
    else
    {
      addr += 1;
    }
    CycleAddresses(addr);
  }
}

void ListenForButton()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) 
  {
    turnedOnPreviously = 0;
    addr = -1; //Reset Address for cycle function if button state has changed
    if (buttonState == HIGH) 
    {
      if(buttonPushCounter == numberOfProgramsSaved)
      {
        buttonPushCounter = 0;
      }
      buttonPushCounter++;
    } 
    delay(50); // Delay to avoid bouncing
  }
  lastButtonState = buttonState;

  if (buttonPushCounter == 3 && !turnedOnPreviously && buttonState == HIGH) //*** On Press 3 *** This Is Where The program function call goes
  {                                                                                            //*** Copy/Paste the if staements and add the prgram function plus the amount of blinks desired, and on which button press
    digitalWrite(LED_BUILTIN, HIGH);                                                           //***MAKE SURE TO UPDATE numberOfProgramsSaved
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    turnedOnPreviously = 1;
    ProgramComp(Multiply_14_8);
  }
  else if (buttonPushCounter == 2 && !turnedOnPreviously && buttonState == HIGH) //*** On Press 2
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    turnedOnPreviously = 1;
    ProgramComp(Fibinachi);
  }
  else if(buttonPushCounter == 1 && !turnedOnPreviously && buttonState == HIGH) //*** On Press 1
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    turnedOnPreviously = 1;
    ProgramComp(TestSequence);
  }
}

void ProgrammingComplete()
{
  for(int i = 0; i < 6; i++)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(10);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
  }
}

void CycleAddresses(int addr)
{
    //Enable Output
    digitalWrite(outputEn,LOW);

    //Set Addr
    shiftOut(addrIn,shiftAddrClk,LSBFIRST,addr);

    //Load Output Reg on 595 Chip
    digitalWrite(outputClk,LOW);
    delay(1);
    digitalWrite(outputClk,HIGH);
    delay(1);
    digitalWrite(outputClk,LOW);
}

void ProgramComp(byte prgArray[])
{
  for(int addr = 0; addr <= 15;addr++)
  {
    shiftOut(addrIn,shiftAddrClk,LSBFIRST,addr);  //Set Addr
    shiftOut(dataIn,shiftDataClk,LSBFIRST,prgArray[addr]); //Set Data

        //Load Output Reg on 595 Chip
        digitalWrite(outputClk,LOW);
        delay(1);
        digitalWrite(outputClk,HIGH);
        delay(1);
        digitalWrite(outputClk,LOW);
      
        //Enable Output
        digitalWrite(outputEn,LOW);
      
        //Confirm On BB Computer
        digitalWrite(confirm,LOW);
        delay(1);
        digitalWrite(confirm,HIGH);
      
        //Reset
        digitalWrite(outputEn,HIGH);
        digitalWrite(clr, LOW);
        delay(1);
        digitalWrite(clr, HIGH);
  }
  ProgrammingComplete();
}
