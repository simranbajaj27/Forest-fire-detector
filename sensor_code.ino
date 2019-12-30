#include <dht.h> //library for reading data from dht11 temperature and humidity sensor
dht DHT;
#define DHT11_PIN 7
int smokeA0 = A5;

void setup() 
{ 
pinMode(smokeA0, INPUT);
Serial.begin(9600); 
delay(1000); 
Serial.print('K'); 
delay(500);
}

void loop() 
{ 
  //if (Serial.available() >0){ 
    int analogSensor = analogRead(smokeA0);
    int chk = DHT.read11(DHT11_PIN);
    int t = DHT.temperature;
    int h = DHT.humidity;
    Serial.print(t);
    Serial.print(h);
    Serial.print(analogSensor);
    delay(5000);
    
} 
