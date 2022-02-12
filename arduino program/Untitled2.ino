#include <LiquidCrystal.h>
//assigning analog Pins:
  const int tempsensor = A1;

 //assign LCD pins 
  const int rs = 12,en=11,d4=5,d5=4,d6=3,d7=2;
  LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

 //assing digital Pins(input and output)
  const int buzzer = 7;
  const int fan = 8;
  const int motionLED = 10;
  const int tempSensor = 10;
  const int motionSensor = 10;
  const int tempLED = 13;

   // declare other variables 
   float tempValue,vout;
   int motionValue;
   
void setup() {
  // put your setup code here, to run once:
  pinMode(tempSensor,INPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(motionSensor,INPUT);
  pinMode(fan,OUTPUT);
  pinMode(motionLED,OUTPUT);
  pinMode(tempLED,OUTPUT);
  Serial.begin(9600);
  delay(500);

  lcd.begin(16,2);

}

void loop() {
  // put your main code here, to run repeatedly:
vout=analogRead(tempSensor);
motionValue=digitalRead(motionSensor);
tempValue=(vout*500)/1023;

lcd.setCursor(0,1);
lcd.print(tempValue);
lcd.print(char(223));
lcd.print("C");

if(tempValue > 30)
{
  digitalWrite(buzzer,HIGH);
  digitalWrite(tempLED,HIGH);
  delay(1500);
  digitalWrite(buzzer,LOW);
  digitalWrite(tempLED,LOW);
   delay(500);
}
if (motionValue != 0)
{
  digitalWrite(motionLED,HIGH);
  digitalWrite(fan,HIGH);
  if (tempValue > 20)
  {
    digitalWrite(buzzer,HIGH);
    delay(100);
  }
  else
  {
    digitalWrite(buzzer,LOW);
    lcd.setCursor(0,0);
    lcd.print("Motion present!");
    delay(1500);
    lcd.clear();
   }
}
  else if(motionValue == 0)
  {
    digitalWrite(motionLED,LOW);
    digitalWrite(fan,LOW);
    if(motionValue ==0 && tempValue < 30)
    {
      digitalWrite(buzzer,LOW);
    }
    lcd.setCursor(0,0);
    lcd.print("Motion absent");
    delay(1500);
    lcd.clear();
 }
}
}