//TODO
  //Listen For Bluetooth Data
  //Fire Button
  //Move Motors
  //Disconnect Detection (Auto Stop)
  //*****These will be finishing touches tasks
  //Detect Low Motor Voltage
  //Detect Low Arduino Voltage

#define FIRE_PIN 7
#define STATUS_LED_PIN 2

String bluetoothString;

void setup() 
{
  Serial.begin(9600);
  pinMode(FIRE_PIN, OUTPUT);
  pinMode(STATUS_LED_PIN, OUTPUT);
  digitalWrite(FIRE_PIN, LOW);
  digitalWrite(STATUS_LED_PIN, LOW);
}

void loop() 
{
  ReadBluetooth();
}

void ReadBluetooth()
{
  if(Serial.available() > 0)
  {
    bluetoothString = Serial.readStringUntil('!');
    Serial.println(bluetoothString);
    Serial.print("Serial.available at the start: ");
    Serial.println(Serial.available());
    if(bluetoothString == "f")
    {
     digitalWrite(FIRE_PIN, HIGH);
     delay(50);
     digitalWrite(FIRE_PIN, LOW);
    }
    else if(bluetoothString == "x")
    {
    }
    else if(bluetoothString.charAt(0) == "m")
    {
      Serial.println("motors Activated");
    }
     Serial.print("Serial.available at the end: ");
    Serial.println(Serial.available());
    bluetoothString = "";
   }
 }
