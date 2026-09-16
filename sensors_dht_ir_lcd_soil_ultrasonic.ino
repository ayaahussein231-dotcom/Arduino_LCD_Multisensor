#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  


#include <DHT.h>
DHT dht(10, DHT11);

#include <NewPing.h>
NewPing u1(8,9,400);

int ir=2;



void setup()
{ 
  pinMode(ir,INPUT);
 Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  dht.begin();
}

void loop()
{ bool ir_v=digitalRead(ir);
   if(ir_v==1){
    lcd.setCursor(0,0);
    lcd.print("object");
   }else{
    lcd.print("no object");
   }
   
   int soil=analogRead(A0);
   if(soil>500){
    lcd.setCursor(10,0);
    lcd.print("WATER");
   }else{
    lcd.print("no water");
   }
   
   

  int h = dht.readHumidity();
  int t = dht.readTemperature();
  int distance=u1.ping_cm();
  delay(1000);
  lcd.clear();

   lcd.setCursor(0,1);
  lcd.print("distance=");
  lcd.print(distance);
  lcd.print(" cm  ");

  lcd.setCursor(9,1);
  lcd.print("temp=");
  lcd.print(t);
  lcd.print("C ");

  
  lcd.setCursor(9,1);
  lcd.print("hum=");
  lcd.print(h);
  lcd.print("%");
  lcd.print("    ");

}







