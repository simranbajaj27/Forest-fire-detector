# Forest-fire-detector
Detecting forest fires in real-time using zigbee modules and arduino.

A circuit is kept in the forest area which consists of temperature,humidity and smoke sensors connected to arduino, and zigbee module is used for data transmission.The Zigbee module sends the data in packets.
Another circuit is kept in the operating side consisting of a zogbee module to receive the data, an arduino. Node-MCU is also connected to send the data to  server and view it in an android mobile. The data is also automatically stored in an excel sheet using PLX-DAQ library.

# Components Required
In this project, the hardware modules required are:
1. 2 zigbee modules for communication.
2. 2 arduino uno
3. Dht11 temperature ansd humidity sensor.
4. MQ2 smoke sensor.
5. Node-MCU (optional)- for getting the real time data in a blynk app.

# Connections

SENSOR SIDE:
Zigbee module connected to arduino using RX,TX pins.
DHT11 temperature sensor connected to pin 7 in arduino uno.
MQ2 smoke sensor connected to pin A0 in arduino uno.

OPERATING SIDE:
Zigbee module connected to arduino using RX,TX pins.
LCD screen: SCL connected to A5; SDA connected to A4.
Buzzer and led to pin 8.
Node-MCU: Pin D5,D6 to 5,6 in arduino uno.
