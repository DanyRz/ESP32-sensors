/*

*/

#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(115200);
  while (!LoRa.begin(866E6)) {
    Serial.println();
    delay(500);
  }
  LoRa.setSyncWord(0xF5);
}

void loop() {

  while (LoRa.available()) {
      String LoRaData = LoRa.readString();
      Serial.print(LoRaData); 
    }
 
}
