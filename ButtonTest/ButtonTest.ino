const int  buttonPin = 11;
const int ledPin = 13;

int buttonPushCounter = 0;
int buttonState = 0;
int lastButtonState = 0;
bool turnedOnPreviously = 0;

void setup() 
{
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}


void loop() 
{
  ListenForButton();
}

void ListenForButton()
{
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) 
  {
    turnedOnPreviously = 0;
    if (buttonState == HIGH) 
    {
      buttonPushCounter++;
    } 
    delay(50); // Delay to avoid bouncing
  }
  lastButtonState = buttonState;

  if (buttonPushCounter % 2 == 0 && !turnedOnPreviously && buttonState == HIGH) //*** On Press 2
  {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
    turnedOnPreviously = 1;
  }
  else if(buttonPushCounter % 1 == 0 && !turnedOnPreviously && buttonState == HIGH) //*** On Press 1
  {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
    turnedOnPreviously = 1;
  }
}
