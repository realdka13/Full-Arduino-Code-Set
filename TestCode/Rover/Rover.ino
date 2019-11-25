//Alpha Motor Pins
const int alphaDir = 12;
const int alphaPWM = 3;
const int alphaBrake = 9;

//Bravo Motor Pins
const int bravoDir = 13;
const int bravoPWM = 11;
const int bravoBrake = 8;

//LED Pin
const int ledPin = 5;

//Buzzer Pin
const int buzzerPin = 4;

//Button Pin
const int buttonPin = 2;
int buttonState = LOW;
bool buttonWasPressed = false;

//Function Prototypes
void TimeDelay(int); //Time(1 sec = 1000)
void ForwardGo(int); //speed(0-255)
void BackwardGo(int); //speed(0-255)
void Right(int); //speed(0-255)
void Left(int); //speed(0-255)
void Stop();
void LEDOn();
void LEDOff();
void BuzzerOn();
void BuzzerOff();
void CheckForButtonPress();

void setup() {
  Serial.begin(9600); //Print Communication with Arduino

  //Alpha Channel Motors
  pinMode(alphaDir,OUTPUT); // Direction Pin(HIGH = Forward, LOW = Backwards)
  pinMode(alphaBrake,OUTPUT); //Brake (Used to stop the motor from moving when HIGH)
  pinMode(alphaPWM,OUTPUT); //Alpha PWM (0-255)

  //Bravo Channel Motors
  pinMode(bravoDir,OUTPUT); // Direction Pin(HIGH = Forward, LOW = Backwards)
  pinMode(bravoBrake,OUTPUT); //Brake (Used to stop the motor from moving when HIGH)
  pinMode(bravoPWM,OUTPUT); //Bravo PWM (0-255)

  //LED Pin
  pinMode(ledPin,OUTPUT); //LED Pin (On is HIGH, Off is LOW)

  //Buzzer Pin
  pinMode(buzzerPin,OUTPUT); //Buzzer Pin (On is HIGH, Off is LOW)

  //Button Pin
  pinMode(buttonPin, INPUT);
  
  Serial.println("Setup Complete");
}

void loop() {
  LEDOn();
  BuzzerOn();
  TimeDelay(500);
  LEDOff();
  BuzzerOff();
  
  Forward(255);
  TimeDelay(1000);
  Backward(255);
  TimeDelay(1000);
  Right(255);
  TimeDelay(1000);
  Left(255);
  TimeDelay(1000);
  Stop();
  TimeDelay(300);
  Serial.println("Movement Complete");
}

void TimeDelay(int time)
{
  int currentTime = 0;
  while(currentTime < time)
  {
    if(!buttonWasPressed)
    {
      CheckForButtonPress();
    }
      delay(100);
      currentTime += 100;
  }
  buttonWasPressed = false;
}

void Forward(int speed)
{
  digitalWrite(alphaBrake,LOW);
  digitalWrite(bravoBrake,LOW);
  analogWrite(alphaPWM,speed);
  analogWrite(bravoPWM,speed);
  digitalWrite(alphaDir,HIGH);
  digitalWrite(bravoDir,HIGH);
}

void Backward(int speed)
{
  digitalWrite(alphaDir,LOW);
  digitalWrite(bravoDir,LOW);
  analogWrite(alphaPWM,speed);
  analogWrite(bravoPWM,speed);
  digitalWrite(alphaBrake,LOW);
  digitalWrite(bravoBrake,LOW);
}

void Right(int speed)
{
  digitalWrite(alphaDir,LOW);
  digitalWrite(bravoDir,HIGH);
  analogWrite(alphaPWM,speed);
  analogWrite(bravoPWM,speed);
  digitalWrite(alphaBrake,LOW);
  digitalWrite(bravoBrake,LOW);  
}

void Left(int speed)
{
  digitalWrite(alphaDir,HIGH);
  digitalWrite(bravoDir,LOW);
  analogWrite(alphaPWM,speed);
  analogWrite(bravoPWM,speed);
  digitalWrite(alphaBrake,LOW);
  digitalWrite(bravoBrake,LOW);  
}

void Stop()
{
  digitalWrite(alphaBrake,HIGH);
  digitalWrite(bravoBrake,HIGH);  
}

void LEDOn()
{
  digitalWrite(ledPin,HIGH);
}

void LEDOff()
{
  digitalWrite(ledPin,LOW);
}

void BuzzerOn()
{
  digitalWrite(buzzerPin,HIGH);
}

void BuzzerOff()
{
  digitalWrite(buzzerPin,LOW);
}

void CheckForButtonPress()
{
  buttonState = digitalRead(buttonPin); 
  if(buttonState == HIGH)
  {
      //Serial.println("Button was Hit");
      Stop();
      LEDOff();
      BuzzerOff();
      while(buttonState == HIGH) //Listening for button release
      {
        buttonState = digitalRead(buttonPin);  
      }
      while(buttonState == LOW) //Listening for button press
      {
        buttonState = digitalRead(buttonPin);
      }
      //Serial.println("Returning To Main");
      buttonState = LOW;
      buttonWasPressed = true;
  }
}
