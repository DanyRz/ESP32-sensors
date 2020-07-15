/*

*/

#include <Wire.h>
#include <Adafruit_BMP085.h>
#include "SparkFunHTU21D.h"
#include <SPI.h>
#include <LoRa.h>

HTU21D myHumidity;
Adafruit_BMP085 bmp;
  
void setup() {
  Serial.begin(115200);
  myHumidity.begin();
  bmp.begin();
  while (!LoRa.begin(866E6)) {
  Serial.println();
  delay(500);
}
  LoRa.setSyncWord(0xF5);
}
  
void loop() {

    float pres = bmp.readPressure();
    float temp1 = bmp.readTemperature();
    
    float humd = myHumidity.readHumidity();
    float temp2 = myHumidity.readTemperature();
    
    LoRa.beginPacket();
    LoRa.print("From BMP sensor: ");
    LoRa.print("Temperature = ");
    LoRa.print(temp1);
    LoRa.print("C ");
    LoRa.print("Pressure = ");
    LoRa.print(pres);
    LoRa.print(" Pa ");
    LoRa.print("From HTU sensor: ");
    LoRa.print("Temperature = ");
    LoRa.print(temp2);
    LoRa.print("C ");
    LoRa.print("Humidity = ");
    LoRa.print(humd);
    LoRa.print("% ");
    LoRa.endPacket();
    
    delay(5000);
   
}
