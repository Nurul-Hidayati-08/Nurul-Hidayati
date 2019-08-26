#include <OneWire.h>
#include <DallasTemperature.h>

// Create a Onewire Referenca and assign it to pin 10 on your Arduino
OneWire oneWire(2);

// declare as sensor referenec by passing oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

// declare your device address
// YOUR ADDRESS GOES HERE!!!!
DeviceAddress tempSensor = {0x28, 0xE3, 0xE8, 0x3F, 0x0B, 0x00, 0x00, 0x99};

// A Variable to hold the temperature you retrieve
float tempC;


void setup(void)
{
  // start serial port
  Serial.begin(9600);
}


void loop(void)
{ 
  // Tell the Sensor to Measure and Remember the Temperature it Measured
  // set the resolution to 12 bit - Valid values are 9, 10, or 11 bit.
  sensors.setResolution(tempSensor, 12);
  // confirm that we set that resolution by asking the DS18B20 to repeat it back
  Serial.print("Sensor Resolution: ");
  Serial.println(sensors.getResolution(tempSensor), DEC); 
  Serial.println();
  
  sensors.requestTemperaturesByAddress(tempSensor); // Send the command to get temperatures
 
  // Get the temperature that you told the sensor to measure
  tempC = sensors.getTempC(tempSensor);
  
  Serial.print("Temp C: ");
  Serial.print(tempC,4);  // The four just increases the resolution that is printed
  delay(1000);
}
