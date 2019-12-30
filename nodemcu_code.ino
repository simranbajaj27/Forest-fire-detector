 #include <SoftwareSerial.h>
SoftwareSerial s(D6,D5);
#include <ArduinoJson.h>

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//#include <WiFi.h>
//#include <DHT.h>
BlynkTimer timer;
char auth[] = "QIp8dVGuHKVVX8pCG9OktGUIonOh7yCQ";

char ssid[] = "simran";
char pass[] = "qwertyuiop";

 
void setup() {
  // Initialize Serial port
  Serial.begin(9600);
  s.begin(9600);
  //while (!Serial) continue;
  Blynk.begin(auth, ssid, pass);
  
}
 
void loop() {
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(s);
 
  if (root == JsonObject::invalid())
  {
    return;
  }
  //Print the data in the serial monitor
  //Serial.println("JSON received and parsed");
  root.prettyPrintTo(Serial);
  //Serial.println("");
  //Serial.print("Temperature ");
  int data1=root["temp"];
  Serial.println(data1);
  //Serial.print("Humidity    ");
  int data2=root["hum"];
  Serial.println(data2);
  //Serial.print("Heat-index  ");
  //int data3=root["hi"];
  //Serial.println(data3);
  //Serial.print("gas sensor  ");
  int data4=root["gasv"];
  Serial.println(data4);
  //Serial.println("");
  //Serial.println("---------------------xxxxx--------------------");
 //Serial.println("");
  Blynk.run();
  timer.run();
  Blynk.virtualWrite(V5, data2);
  Blynk.virtualWrite(V6, data1);
  Blynk.virtualWrite(V7, data4);
  
}
