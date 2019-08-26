#include <OneWire.h>  


OneWire ds(2); 
int period = 5000;
unsigned long time_now = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  byte i;
  byte present = 0;

  byte data[12];
  byte addr[8];
  float Temp;

  time_now = millis();

  while(millis() < time_now + period){
    }
  
  if (!ds.search(addr)) {
    ds.reset_search();
    return;
  }

ds.reset();
  ds.select(addr);
  ds.write(0x44,1); // start conversion, with parasite power on at the end
  //delay(2000);

  present = ds.reset();
  ds.select(addr);
  ds.write(0xBE); // Read all data of Scratchpad

  for (i = 0; i < 9; i++) 
     data[i] = ds.read(); {
  }

  Temp=(data[1]<<8)+data[0]; // calculate the Celsius.
  Temp=Temp/16;
  
  Serial.print("\nC="); // Celsius output
  Serial.print(Temp);
  Serial.print(", ");
  
}
