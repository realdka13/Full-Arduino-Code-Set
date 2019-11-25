//Pins
#define D_DATA_PIN 10
#define K_DATA_PIN 9
#define A_DATA_PIN 8
#define ONE_DATA_PIN 7
#define THREE_DATA_PIN 6
#define SHIFT_CLOCK_PIN 11
#define OUTPUT_CLOCK_PIN 12
#define RESET_PIN 2
#define BUTTON_PIN 12

//Function Prototypes
void MyDelay();
void PulseOutputClock();
void PulseReset();
void PulseInputClock();
void InitPins();
void CycleLEDs();
void AlternatingLetters();
void SequenceLetters();
void LetterBuildUp();
void BreathLEDs();
void BreathBounce();

//Animation bools
bool cycleLED = true;
bool alternatingLetter = false;
bool sequenceLetter = false;
bool letterBuildUp = false;
bool breathLED = false;
bool breathBounceLED = false;

void setup() {
  Serial.begin(9600);
  InitPins();
}

void loop() 
{
  if(cycleLED == true)
  {
    CycleLEDs();
  }
  if(alternatingLetter == true)
  {
    AlternatingLetters();
  }
  if(sequenceLetter == true)
  {
    SequenceLetters();
  }
  if(letterBuildUp == true)
  {
    LetterBuildUp();
  }
  if(breathLED == true)
  {
    BreathLEDs();
  }
  if(breathBounceLED == true)
  {
    BreathBounce();
  }
}










//Functions
void ReadButton(bool &currentBool,bool &selectionBool)
{

}

void MyDelay(int timer, bool &currentBool, bool &selectionBool)
{
    for(int currentTime;currentTime < timer; currentTime += 5)
    {
      int buttonState = digitalRead(BUTTON_PIN);
      if(buttonState == HIGH)
      {
        currentBool = false;
        selectionBool = true;
      }
      delay(5);
    }
}

void PulseOutputClock()
{
  digitalWrite(OUTPUT_CLOCK_PIN, LOW);
  digitalWrite(OUTPUT_CLOCK_PIN, HIGH);
  digitalWrite(OUTPUT_CLOCK_PIN, LOW);
}

void PulseReset()
{
  digitalWrite(RESET_PIN, HIGH);
  digitalWrite(RESET_PIN, LOW);
  digitalWrite(RESET_PIN, HIGH);
}

void PulseInputClock()
{
  digitalWrite(SHIFT_CLOCK_PIN, LOW);
  digitalWrite(SHIFT_CLOCK_PIN, HIGH);
  digitalWrite(SHIFT_CLOCK_PIN, LOW);
}

void InitPins()
{
  //Set PinModes
  pinMode(D_DATA_PIN,OUTPUT);
  pinMode(K_DATA_PIN,OUTPUT);
  pinMode(A_DATA_PIN,OUTPUT);
  pinMode(ONE_DATA_PIN,OUTPUT);
  pinMode(THREE_DATA_PIN,OUTPUT);
  pinMode(SHIFT_CLOCK_PIN,OUTPUT);
  pinMode(OUTPUT_CLOCK_PIN,OUTPUT);
  pinMode(RESET_PIN,OUTPUT);

  PulseReset();
  
  //Init Clocks to Low
  digitalWrite(SHIFT_CLOCK_PIN,LOW);
  digitalWrite(OUTPUT_CLOCK_PIN, LOW);
}

void CycleLEDs()
{
  for (int pin = D_DATA_PIN; pin >= THREE_DATA_PIN; pin -= 1)
  {
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b10000000);
    PulseOutputClock();
    MyDelay(50,cycleLED,alternatingLetter);
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b01000000);
    PulseOutputClock();
    MyDelay(50,cycleLED,alternatingLetter);
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b00100000);
    PulseOutputClock();
    MyDelay(50,cycleLED,alternatingLetter);
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b00010000);
    PulseOutputClock();
    MyDelay(50,cycleLED,alternatingLetter);
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b00001000);
    PulseOutputClock();
    MyDelay(50,cycleLED,alternatingLetter);
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b00000100);
    PulseOutputClock();
    MyDelay(50,cycleLED,alternatingLetter);
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b00000010);
    PulseOutputClock();
    MyDelay(50,cycleLED,alternatingLetter);
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b00000001);
    PulseOutputClock();
    MyDelay(50,cycleLED,alternatingLetter);
  }
}

void AlternatingLetters()
{
  for(int iter = 0; iter < 4; iter += 1)
  {
    digitalWrite(D_DATA_PIN,HIGH);
    digitalWrite(K_DATA_PIN,HIGH);
    digitalWrite(A_DATA_PIN,HIGH);
    digitalWrite(ONE_DATA_PIN,HIGH);
    digitalWrite(THREE_DATA_PIN,HIGH);

    PulseInputClock();
    PulseOutputClock();

    MyDelay(100,alternatingLetter,sequenceLetter);
    
    digitalWrite(D_DATA_PIN,LOW);
    digitalWrite(K_DATA_PIN,LOW);
    digitalWrite(A_DATA_PIN,LOW);
    digitalWrite(ONE_DATA_PIN,LOW);
    digitalWrite(THREE_DATA_PIN,LOW);
    
    PulseInputClock();
    PulseOutputClock();

    MyDelay(100,alternatingLetter,sequenceLetter);
  }
}

void SequenceLetters()
{
  for (int pin = D_DATA_PIN; pin >= THREE_DATA_PIN; pin -=1)
  {
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b11111111);
    PulseOutputClock();
    MyDelay(150,sequenceLetter,letterBuildUp);
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b00000000);
    PulseOutputClock();
  }
}

void LetterBuildUp()
{
    for (int pin = D_DATA_PIN; pin >= THREE_DATA_PIN; pin -=1)
  {
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b11111111);
    PulseOutputClock();
    MyDelay(500,letterBuildUp,breathLED);
  }
    for (int pin = D_DATA_PIN; pin >= THREE_DATA_PIN; pin -=1)
  {
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b00000000);
  }
  PulseOutputClock();
  MyDelay(150,letterBuildUp,breathLED);
      for (int pin = D_DATA_PIN; pin >= THREE_DATA_PIN; pin -=1)
  {
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b11111111);
  }
  PulseOutputClock();
  MyDelay(150,letterBuildUp,breathLED);
      for (int pin = D_DATA_PIN; pin >= THREE_DATA_PIN; pin -=1)
  {
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b00000000);
  }
  PulseOutputClock();
  MyDelay(150,letterBuildUp,breathLED);
      for (int pin = D_DATA_PIN; pin >= THREE_DATA_PIN; pin -=1)
  {
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b11111111);
  }
  PulseOutputClock();
  MyDelay(150,letterBuildUp,breathLED);
      for (int pin = D_DATA_PIN; pin >= THREE_DATA_PIN; pin -=1)
  {
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b00000000);
  }
  PulseOutputClock();
  MyDelay(150,letterBuildUp,breathLED);
      for (int pin = D_DATA_PIN; pin >= THREE_DATA_PIN; pin -=1)
  {
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b11111111);
  }
  PulseOutputClock();
  MyDelay(150,letterBuildUp,breathLED);
      for (int pin = D_DATA_PIN; pin >= THREE_DATA_PIN; pin -=1)
  {
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b00000000);
  }
  PulseOutputClock();
  MyDelay(150,letterBuildUp,breathLED);
      for (int pin = D_DATA_PIN; pin >= THREE_DATA_PIN; pin -=1)
  {
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b11111111);
  }
  PulseOutputClock();
  MyDelay(150,letterBuildUp,breathLED);

  for (int pin = D_DATA_PIN; pin >= THREE_DATA_PIN; pin -=1)
  {
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b00000000);
  }
  PulseOutputClock();
  MyDelay(500,letterBuildUp,breathLED);
}

void BreathLEDs()
{
   for (int pin = D_DATA_PIN; pin >= THREE_DATA_PIN; pin -=1)
  {
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b11111111);
    PulseOutputClock();
    MyDelay(75,breathLED,breathBounceLED);
  }
        for (int pin = D_DATA_PIN; pin >= THREE_DATA_PIN; pin -=1)
  {
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b00000000);
    PulseOutputClock();
    MyDelay(75,breathLED,breathBounceLED);
  }
}

void BreathBounce()
{
   for (int pin = D_DATA_PIN; pin >= THREE_DATA_PIN; pin -=1)
  {
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b11111111);
    PulseOutputClock();
    MyDelay(50,breathBounceLED,cycleLED);
  }
   for (int pin = THREE_DATA_PIN; pin <= D_DATA_PIN; pin +=1)
  {
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b00000000);
  }
  PulseOutputClock();
   for (int pin = THREE_DATA_PIN; pin <= D_DATA_PIN; pin +=1)
  {
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b11111111);
    PulseOutputClock();
    MyDelay(50,breathBounceLED,cycleLED);
  }
     for (int pin = THREE_DATA_PIN; pin <= D_DATA_PIN; pin +=1)
  {
    shiftOut(pin, SHIFT_CLOCK_PIN, LSBFIRST, 0b00000000);
  }
  PulseOutputClock();
}
