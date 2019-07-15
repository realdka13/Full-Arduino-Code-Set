#include <Servo.h>
Servo servo;

int angle = 0;

void setup() {
  servo.attach(10);
  servo.write(angle);
}

void loop() 
{ 
// // scan from 0 to 180 degrees
//  for(angle = 0; angle < 180; angle++)  
//  {                                  
//    servo.write(angle);               
//    delay(5);                   
//  } 
//  // now scan back from 180 to 0 degrees
//  for(angle = 180; angle > 0; angle--)    
//  {                                
//    servo.write(angle);           
//    delay(5);
//  } 
  servo.write(0);
  delay(350);
  servo.write(180);
  delay(350);
}
