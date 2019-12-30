#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
int Buzzer=8,temp[7],i,led=7;

#include <SoftwareSerial.h>
#include <ArduinoJson.h>
SoftwareSerial s(5,6);


void setup()
{
  pinMode(Buzzer,OUTPUT);
  //Serial.begin(9600);
  lcd.begin(16,2);
  lcd.backlight();

  Serial.begin(9600);
  s.begin(9600);
  
  Serial.println("CLEARDATA");
  Serial.println("LABEL,DATE,TIME,TEMPERATURE,HUMIDITY,SMOKE_VALUE");

  
}


StaticJsonBuffer<1000> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();


void loop()

{
i=0;
  while(Serial.available()>0){
    temp[i] = Serial.read();
    i++;
  }

int x = ((temp[0] - 48) *10) +  (temp[1] - 48) ;
int y = ((temp[2] - 48) *10) +  (temp[3] - 48) ;
int z = ((temp[4] - 48) *100) + ((temp[5] - 48) *10) + (temp[6] - 48) ;

/*Serial.print("x =");
Serial.println(x);


Serial.print("y =");
Serial.println(y);


Serial.print("z =");
Serial.println(z);
*/
Serial.write ("DATA,DATE,TIME,");
//Serial.print("the temperature is : ");
Serial.print(x);
Serial.print(",");
//Serial.print("the humidity is : ");
Serial.print(y);
Serial.print(",");
//Serial.print("the smoke value is : ");
Serial.print(z);
Serial.println();


delay (1000);

lcd.setCursor(0,0); 
lcd.write("Temp-");
lcd.write(temp[0]);
lcd.write(temp[1]);
lcd.write(' ');
//delay(1000);
//lcd.setCursor(0,1);
lcd.write("Hum-");
lcd.write(temp[2]);
lcd.write(temp[3]);
lcd.setCursor(0,1);
lcd.write("Smoke_value-");
lcd.write(temp[4]);
lcd.write(temp[5]);
lcd.write(temp[6]);
delay(1000);


  root["temp"] = x;
  root["hum"] = y;
  root["gasv"]= z;


/*if(s.available()>0)
{
 root.printTo(s);
}
*/

root.printTo(s);
if (temp[0] == 51 && temp[1] == 50){
  digitalWrite(Buzzer,HIGH);
  digitalWrite(led,LOW);
  delay(1000);
}
else {
    digitalWrite(Buzzer,LOW);
    digitalWrite(led,HIGH);

}
}
