void setup() 
{
  // put your setup code here, to run once:
    Serial.begin(9600);
}

void loop() 
{
  // put your main code here, to run repeatedly:
    static int counter = 32700;
    Serial.print("Count = ");
    Serial.println(counter);
    counter = counter + 1;
    delay(100);
}
