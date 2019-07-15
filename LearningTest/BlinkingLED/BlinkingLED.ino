int led = 13;

void setup() {
  pinMode(led, OUTPUT); //Set pin 13 as output
}

void loop() {
  digitalWrite(led, HIGH); //LED On
  delay(50);
  
  digitalWrite(led, LOW); //LED Off
  delay(50);
}
