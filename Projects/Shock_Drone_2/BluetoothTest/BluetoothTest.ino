String motorString;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  if(Serial.available() > 0)
  {
  motorString = Serial.readStringUntil('!');
  Serial.println(motorString);
  }
}
