#include <SPI.h>
#include <LoRa.h>
/* */
#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 14
#define DIO0 26
// #define BAND 866E6

int counter = 0;

void setup() {
  
  Serial.begin(115200); 
  Serial.println("LoRa Sender");
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
  Serial.print("Sending packet: ");
  Serial.println(counter);

  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(500);
}
