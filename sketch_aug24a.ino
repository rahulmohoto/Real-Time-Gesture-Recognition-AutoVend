#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int switchPin = 6;
char value;
unsigned int startTime;
boolean goNext=false;
char myArray[3];

void setup() {
  pinMode(switchPin,INPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);       // start serial communication at 9600bps
  lcd.begin(16,2);
  // Print a message to the LCD.
  lcd.print("hello, There!");
  lcd.setCursor(0,1);
  lcd.print("This is AutoVend");
  delay(3000);
  lcd.clear();
  lcd.print("  Let's Start!  ");
  delay(2000);
  lcd.clear();
  lcd.print("Let's Connect");
  delay(2000);
  while(1)       // if data is available to read
  {
    if(Serial.available()){
    lcd.clear();    
    lcd.print("We'r Connected");
    delay(1000);
    break;
    }
  }
  lcd.clear();    
  lcd.print("Press The Button!");
  lcd.setCursor(0, 1);
  lcd.print("To Wake Up!");
  delay(2000);
}

void loop() {
  while(1){
    if(digitalRead(switchPin)==1){
      lcd.clear();    
      lcd.print("Button Pressed");
      while(1){
        if(Serial.available()>0){
          startTime=millis();
          while(millis()-startTime<=3000){
            Serial.write('O');
            Serial.flush();
      }
       break;
       }
     }
    lcd.clear();
    lcd.print("We'r On!");
    lcd.setCursor(0,1);
    lcd.print("Let's Purchase..");
    delay(2000);
    goNext=true;
    while(goNext!=false)       // if data is available to read
    {
    if(Serial.available()){    
    value = Serial.read();         // read it and store it in 'val'
    lcd.clear();
    lcd.print("purchased prod:");
    lcd.setCursor(0,1);
    myArray[0]=value;
    delay(100);
    value = Serial.read();         // read it and store it in 'val'
    myArray[1]=value;
    myArray[2]='\0';
    lcd.print(myArray);
    delay(5000);
    lcd.clear();
    lcd.print("Proceed to Pay");
    lcd.setCursor(0,1);
    lcd.print("..Thanks..");
    delay(2000);
    }
    }
    }
  } 
}
