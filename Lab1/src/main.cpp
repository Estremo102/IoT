#include <Arduino.h>
#include <OneWire.h>

#define LED D4
#define ONE_WIRE_BUS D2

int myFunction(int, int);

OneWire ds(ONE_WIRE_BUS);

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(ONE_WIRE_BUS, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // digitalWrite(LED, HIGH);
  // delay(1000);
  // digitalWrite(LED, LOW);
  // delay(1000);
  ds.reset();
  ds.write(0xCC); 
  ds.write(0x44); 
  delay(750); 
  ds.reset(); 
  ds.write(0xCC); 
  ds.write(0xBE); 
  uint8_t tempLSB = ds.read(); 
  uint8_t tempMSB = ds.read(); 
  int rawTemperature = (tempMSB << 8) | tempLSB; 
  float temperature = rawTemperature / 16.0;
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println(" C");
  digitalWrite(LED, temperature > 25 ? HIGH : LOW); 
}
