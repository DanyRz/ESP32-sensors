/*

*/

#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <SparkFunHTU21D.h>
#include <SPI.h>
#include <LoRa.h>

#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 14
#define DIO0 26

HTU21D myHumidity;
Adafruit_BMP085 bmp;
  
void setup() {
  Serial.begin(115200);
  myHumidity.begin();
  bmp.begin(); 
  Serial.println("LoRa Sender");
  SPI.begin(SCK, MISO, MOSI, SS);  
  LoRa.setPins(SS, RST, DIO0);  
  LoRa.begin(866E6); 
  LoRa.setSyncWord(0xF5);
  if (!LoRa.begin(866E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }  
  Serial.println("LoRa Initializing OK!");
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
    Serial.println("Packet sent");
    delay(5000);
   
}
