#include <dht.h>
#include <LiquidCrystal.h>

//#include "DHT.h"
#define DHT_PIN A0
#define PWM 10
dht DHT;
LiquidCrystal lcd(7,8,9,6,4,3);



void setup() {
  // put your setup code here, to run once:
    analogWrite(PWM,0);
    lcd.begin(16,2);  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Use the dht function to read the temperature
  int chk = DHT.read11(DHT_PIN);
  int temp = DHT.temperature;
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);

  //Compare the room temperature with defined value to generate PWM
  if (temp<=22)
  {
    analogWrite(PWM, 255);
    lcd.print("Fan speed: Off");
  }

  else if(temp==23)
  {
    analogWrite(PWM, 140);
    lcd.print("Fan Speed: 40%");
  }
  
  else if(temp==24) 
  {
    analogWrite(PWM, 90);
    lcd.print("Fan Speed: 60%");
  }

  else if(temp==25)
  {
    analogWrite(PWM,50);
    lcd.print("Fan Speed: 80%");
  }

  else if(temp>=26)
  {
    analogWrite(PWM,0);
    lcd.print("Fan Speed: 100%");
    
  }

  
  //lcd.print("Humidity: ");
  //lcd.print(DHT.humidity);
  //lcd.print("%");
  delay(1000);

}
