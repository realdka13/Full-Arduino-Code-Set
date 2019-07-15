#include <SoftwareSerial.h>
SoftwareSerial mySerial(4, 5); // RX, TX

int leftSpeed;  //Variable to store values in
int rightSpeed; //Variable 2


void setup() {
Serial.begin(9600);
mySerial.begin(9600);
}

void loop() {
if (Serial.available())
{
  mySerial.write(Serial.read());
}

if(!mySerial.available())
{
  return;
}

String input = String(mySerial.read()); //Input to split up


sscanf (input.c_str(),"%d:%d", &leftSpeed,&rightSpeed); //The Split Up (the string to split, how is it formatted, the variables to store it in)

//print
Serial.print("Left Speed:");
Serial.print(leftSpeed);
Serial.print(" Right Speed:");
Serial.print(rightSpeed);
Serial.println("");
}
