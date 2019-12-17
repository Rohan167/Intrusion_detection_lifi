#include <Wire.h> 
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial GSerial(11,12); //Put the ldr digital pin to ~D11
char rec=0;

void setup()
{
  Serial.begin(9600);
  GSerial.begin(400);
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("___Intrusion___");
  lcd.setCursor(0, 1);
  lcd.print("____By Lifi____");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Presented By :");
  lcd.setCursor(0, 1);
  lcd.print("Rohan Kumar");
  delay(1000);
    lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Presented By :");
  lcd.setCursor(0, 1);
  lcd.print("Mahesh G");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Presented By :");
  lcd.setCursor(0, 1);
  lcd.print("Manjunath");
  delay(1000);
  lcd.clear();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("__No Intrusion__");
  lcd.setCursor(0, 1);
  lcd.print("____Detected____");
  Serial.println("No Intrusion Detected");
}

void loop()
{
  if(GSerial.available() != 0)
  {    
    rec = GSerial.read();
    int val= rec;

    Serial.print(rec);
    Serial.print("->");
    Serial.println(val);


    switch(val)
    {
      case 0 :
      lcd.setCursor(0, 0);
      lcd.print("___Intrusion___");
      lcd.setCursor(0, 1);
      lcd.print("____Detected____");
      Serial.println("Intrusion Detected");
      while(true){
        lcd.backlight();
        delay(1000);
        lcd.noBacklight();
        delay(1000);
        }
      break;


      default:
      if(val>0)
      {
      lcd.setCursor(0, 0);
      lcd.print("Warning !!");
      lcd.setCursor(0, 1);
      lcd.print("Intrusion Detected");
      Serial.println("Intrusion Detected");
      }else{
      lcd.print("No Intrusion Detected");
      Serial.println("No Intrusion Detected");
      break;
      }
    }
  }
}
