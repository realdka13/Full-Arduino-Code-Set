#include <Ephemeris.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

#define acceptButtonPin 19
#define backButtonPin 18
#define downButtonPin 3
#define upButtonPin 2

//State variables for navigation
bool monthSelected = false;
bool daySelected = false;
bool yearSelected = false;
bool hourSelected = false;
bool minuteSelected = false;

int planetCounter = 0; //0=Sun,1=Mercury,2=Venus,3=Earth,4=Mars,5=Jupiter,6=Saturn,7=Uranus,8=Neptune
int statCounter = 1; //1=...,2=...,3=...,4=...,5=...  *** Once I know how many there are, remember to change the amount in the button functions***
int monthCounter = 1;
int dayCounter = 1;
int yearCounter = 2020;
int hourCounter = 00;
int minuteCounter = 00;

int selectionScreen = 0; //0=Date Selection,1=PlanetSelection,2=statSelection
bool acceptButtonPressed = false;
bool backButtonPressed = false;
bool downButtonPressed = false;
bool upButtonPressed = false;

//Arrays
char *planets[] = {"Sun","Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune"};
char *stats[] = {"Stat1","Stat2","Stat3","Stat4","Stat5"};
int date[] = {01,01,2020};
int times[] = {00,00};

//Button Inturrupts, these should only debounce and set the button state variables
void acceptButton(){
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > 200) 
  {
    //************************************* Actions
    acceptButtonPressed = true;
    //*************************************
  }
  last_interrupt_time = interrupt_time;
}
void backButton(){
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > 200) 
  {
    //************************************* Actions
    backButtonPressed = true;
    //*************************************
  }
  last_interrupt_time = interrupt_time;
}
void downButton(){
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > 200) 
  {
    //************************************* Actions
    downButtonPressed = true;
    //*************************************
  }
  last_interrupt_time = interrupt_time;
}
void upButton(){
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  if (interrupt_time - last_interrupt_time > 200) 
  {
    //************************************* Actions
    upButtonPressed = true;
    //*************************************
  }
  last_interrupt_time = interrupt_time;
}

//Navigation Functions
void Accept(){
    if(selectionScreen == 0){
      if(monthSelected == false){
        date[0] = monthCounter;
        PrintLCD();
        monthSelected = true;
      }
      else if(daySelected == false){
        date[1] = dayCounter;
        PrintLCD();
        daySelected = true;
      }
      else if(yearSelected == false){
        date[2] = yearCounter;
        PrintLCD();
        yearSelected = true;
      }
      else if(hourSelected == false){
        times[0] = hourCounter;
        PrintLCD();
        hourSelected = true;
      }
      else if(minuteSelected == false){
        times[1] = minuteCounter;
        PrintLCD();
        minuteSelected = true;
        selectionScreen = 1;
      }
    }
    else if(selectionScreen == 1){selectionScreen = 2;}
    Serial.print("acceptButton Pressed : selectionScreen: ");
    Serial.println(selectionScreen);
    planetCounter = 0; //Reset to begining
    PrintLCD();
    acceptButtonPressed = false;
}
void Back(){
    if(selectionScreen == 2){
      selectionScreen = 1;
      statCounter = 1;//Reset to begining
    }
    else if(selectionScreen == 1){
      selectionScreen = 0;
      monthSelected = false;
      daySelected = false;
      yearSelected = false;
      hourSelected = false;
      minuteSelected = false;
      PrintLCD();
    }
    else if(selectionScreen == 0){
      if (hourSelected == true){
        hourSelected = false;
      }
      else if (yearSelected == true){
        yearSelected = false;
      }
      else if(daySelected == true){
        daySelected = false;
      }
      else if(monthSelected == true){
        dayCounter = 1;
        monthSelected = false;
      }
    }
    Serial.print("backButton Pressed : selectionScreen ");
    Serial.println(selectionScreen);
    PrintLCD();
    backButtonPressed = false;
}
void MoveDown(){
    if(selectionScreen == 0){
      if(monthSelected == false){
        if(monthCounter < 12){monthCounter += 1;}
        else {monthCounter = 1;}
      }
      else if(daySelected == false){
        if(monthCounter == 1 || monthCounter == 3 || monthCounter == 5 || monthCounter == 7 || monthCounter == 8 || monthCounter == 10 || monthCounter == 12)//Months with 31 days
        {
          if(dayCounter < 31){dayCounter += 1;}
          else {dayCounter = 1;}
        }
        else if(monthCounter == 4 || monthCounter == 6 || monthCounter == 9 || monthCounter == 11)//Months with 30 days
        {
          if(dayCounter < 30){dayCounter += 1;}
          else {dayCounter = 1;}
        }
        else //Month with 28 days
        {
          if(dayCounter < 28){dayCounter += 1;}
          else {dayCounter = 1;}
        }
      }
      else if(yearSelected == false){
        if(yearCounter < 2025){yearCounter += 1;}
        else {yearCounter = 2020;}
      }
      else if(hourSelected == false){
        if(hourCounter < 23){hourCounter += 1;}
        else {hourCounter = 0;}
      }
      else if(minuteSelected == false){
        if(minuteCounter < 59){minuteCounter += 1;}
        else {minuteCounter = 0;}
      }
    }
    else if(selectionScreen == 1)
    {
      if(planetCounter < 8){planetCounter+=1;}
      else{planetCounter = 0;}
      Serial.print("Planet Counter: ");
      Serial.println(planetCounter);
    }
    else if(selectionScreen == 2)
    {
      if(statCounter < 5){statCounter+=1;}
      else{statCounter = 1;}
      Serial.print("Stat Counter: ");
      Serial.println(statCounter);
    }
    PrintLCD();
    downButtonPressed = false;
}
void MoveUp(){
    if(selectionScreen == 0){
      if(monthSelected == false){
        if(monthCounter > 1){monthCounter -= 1;}
        else {monthCounter = 12;}
      }
      else if(daySelected == false){
        if(monthCounter == 1 || monthCounter == 3 || monthCounter == 5 || monthCounter == 7 || monthCounter == 8 || monthCounter == 10 || monthCounter == 12)//Months with 31 days
        {
          if(dayCounter > 1){dayCounter -= 1;}
          else {dayCounter = 31;}
        }
        else if(monthCounter == 4 || monthCounter == 6 || monthCounter == 9 || monthCounter == 11)//Months with 30 days
        {
          if(dayCounter > 1){dayCounter -= 1;}
          else {dayCounter = 30;}
        }
        else //Month with 28 days
        {
          if(dayCounter > 1){dayCounter -= 1;}
          else {dayCounter = 28;}
        }
      }
      else  if(yearSelected == false){
        if(yearCounter > 2020){yearCounter -= 1;}
        else {yearCounter = 2025;}
      }
      else if(hourSelected == false){
        if(hourCounter > 0){hourCounter -= 1;}
        else {hourCounter = 23;}
      }
      else if(minuteSelected == false){
        if(minuteCounter > 0){minuteCounter -= 1;}
        else {minuteCounter = 59;}
      }
    }
    if(selectionScreen == 1)
    {
      if(planetCounter > 0){planetCounter -= 1;}
      else{planetCounter = 8;}
      Serial.print("Planet Counter: ");
      Serial.println(planetCounter);
    }
    else if(selectionScreen == 2)
    {
      if(statCounter > 1){statCounter-=1;}
      else{statCounter = 5;}
      Serial.print("Stat Counter: ");
      Serial.println(statCounter);
    }
    PrintLCD();
    upButtonPressed = false;
}

//LCD Functions
void PrintLCD(){
  lcd.clear();
  if(selectionScreen == 0){
    if(monthSelected == false){
      lcd.setCursor(0,1);
      lcd.print("Month? ");
      lcd.print(monthCounter);
    }
    else if(daySelected == false){
      lcd.setCursor(0,1);
      lcd.print("Day? ");
      lcd.print(dayCounter);
    }
    else if(yearSelected == false){
      lcd.setCursor(0,1);
      lcd.print("Year? ");
      lcd.print(yearCounter);
    }
    else if(hourSelected == false){
      lcd.setCursor(0,1);
      lcd.print("Hour? ");
      lcd.print(hourCounter);
    }
    else if(minuteSelected == false){
      lcd.setCursor(0,1);
      lcd.print("Minute? ");
      lcd.print(minuteCounter);
    }
    else {Serial.println("Error");}
    lcd.setCursor(0,0);
    lcd.print(date[0]);
    lcd.print("/");
    lcd.print(date[1]);
    lcd.print("/");
    lcd.print(date[2]);
    lcd.print(" ");
    lcd.print(times[0]);
    lcd.print(":");
    lcd.print(times[1]);
  }
  else if(selectionScreen == 1){
    lcd.print(planets[planetCounter]);
    Serial.println(planets[planetCounter]);

    Serial.print("Date/Time Selected is: ");
    Serial.print(date[0]);
    Serial.print("/");
    Serial.print(date[1]);
    Serial.print("/");
    Serial.print(date[2]);
    Serial.print(" ");
    Serial.print(times[0]);
    Serial.print(":");
    Serial.println(times[1]);
  }
  else if(selectionScreen == 2){
    lcd.print(stats[statCounter - 1]);
  }
}





void setup() {
Serial.begin(9600);
lcd.init();
lcd.backlight();
lcd.setCursor(0,0);//(Col,Row)

pinMode(acceptButtonPin, INPUT_PULLUP);
pinMode(backButtonPin, INPUT_PULLUP);
pinMode(downButtonPin, INPUT_PULLUP);
pinMode(upButtonPin, INPUT_PULLUP);

attachInterrupt(digitalPinToInterrupt(acceptButtonPin),acceptButton,FALLING);
attachInterrupt(digitalPinToInterrupt(backButtonPin),backButton,FALLING);
attachInterrupt(digitalPinToInterrupt(downButtonPin),downButton,FALLING);
attachInterrupt(digitalPinToInterrupt(upButtonPin),upButton,FALLING);

int planetCounter = 0;
int stat = 0;
bool selectionScreen = true;

Serial.println("Starting...");
lcd.print("Starting...");
lcd.setCursor(0,1);
lcd.print("Press Back Button...");
}
void loop() {
  if(acceptButtonPressed == true){Accept();}
  else if(backButtonPressed == true){Back();}
  else if(downButtonPressed == true){MoveDown();}
  else if(upButtonPressed == true){MoveUp();}
}
