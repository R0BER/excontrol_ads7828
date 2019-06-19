// excontrol ads7828
// by excontrol <https://excontrol.es/>

// Demonstrates use of ads7828 library
// Created 19  April 2019

// This example code is in the public domain.


#include <excontrol_ads7828.h>

Ads7828 ads(0x48); //Start with default address 0x48 
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  while (!Serial) { ;  }
}

void loop()
{
  ads.update();//Update analog data
  for (int c=0;c<8;c++){
    Serial.print("AD Input A"); 
    Serial.print(c);
    Serial.print(" Value= ");
    Serial.println(ads.Value[c], DEC);  ///Print Value
 }
 Serial.println("-----------------------------------------");
 delay(500);
  
}
