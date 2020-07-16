#include <SPI.h>
#include <LoRa.h>


int counter = 0;

void setup() {
  
  Serial.begin(115200);
 
  Serial.println("LoRa Sender");

  LoRa.begin(866E6);
   
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(500);
}
