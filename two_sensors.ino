/*
Мінімалістична програма для отримання даних з сенсорів BMP180 та HTU21D
з використанням бібліотек для даних сенорів у вільному доступі.
Напруга 3,3 V, сенсори підключені паралельно до одної лінії SLC і 
до одної лінїї SDA.
*/

#include <Wire.h>
#include <Adafruit_BMP085.h>
#include "SparkFunHTU21D.h"


HTU21D myHumidity;
Adafruit_BMP085 bmp;
  
void setup() {
  Serial.begin(9600);
  myHumidity.begin();
  bmp.begin();
}
  
void loop() {
    Serial.print("From BMP sensor: ");
    Serial.println();
    
    Serial.print("Temperature = ");
    Serial.print(bmp.readTemperature());
    Serial.println("C");
    
    Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

    Serial.println();
 
    float humd = myHumidity.readHumidity();
    float temp = myHumidity.readTemperature();

    Serial.print("From HTU sensor: ");
    Serial.println();
    
    Serial.print(" Temperature:");
    Serial.print(temp, 2);
    Serial.println("C");
    
    Serial.print(" Humidity:");
    Serial.print(humd, 2);
    Serial.println("%");
  
    Serial.println();
    
    delay(5000);
}
