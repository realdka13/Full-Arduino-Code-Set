#include <SoftwareSerial.h>

//Alpha Motor Pins
const int alphaDir = 12;
const int alphaPWM = 3;
const int alphaBrake = 9;

//Bravo Motor Pins
const int bravoDir = 13;
const int bravoPWM = 11;
const int bravoBrake = 8;

SoftwareSerial mySerial(4, 5); // RX, TX

void Forward(int); //speed(0-255)
void Stop();

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop()
{
//  if (mySerial.available())
//    Serial.write(mySerial.read());

  if (Serial.available())
    mySerial.write(Serial.read());


  if(!mySerial.available())
    return;
    
  char bluState = mySerial.read();

  if (bluState == 'w') {
    Forward(255);
  }

  else if (bluState == '\n');
  else{
    Stop();
  }
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

void Stop()
{
  digitalWrite(alphaBrake,HIGH);
  digitalWrite(bravoBrake,HIGH);  
}
