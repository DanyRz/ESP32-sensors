#include <SPI.h>
#include <LoRa.h>

#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 14
#define DIO0 26
// #define BAND 866E6

void setup() {
  Serial.begin(115200);
  Serial.println("LoRa Receiver");
  SPI.begin(SCK, MISO, MOSI, SS);
  LoRa.setPins(SS, RST, DIO0); 
  LoRa.begin(866E6); 
  LoRa.setSyncWord(0xF2);
  if (!LoRa.begin(866E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }  
  Serial.println("LoRa Initializing OK!");
}

void loop() {
 
  
    while (LoRa.available()) {
      
      int packetSize = LoRa.parsePacket();
      String LoRaData = LoRa.readString();
      Serial.print("Received packet '");
      Serial.print(LoRaData); 

      Serial.print("' with RSSI ");
      Serial.println(LoRa.packetRssi());
    }

      
  
  
}
