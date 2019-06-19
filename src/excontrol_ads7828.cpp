/*
   excontrol_ads7828.h - Library for ads7828.
  Copyright (c) 2019 ExControl. All rights reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/


#include "Arduino.h"
#include <Wire.h> 
#include <excontrol_ads7828.h>


/* Constructor */
Ads7828::Ads7828(int addr)
{	
	_I2C_address = addr;
}

void Ads7828::update()
{
	byte Adval_High, Adval_Low;    // Store A/D value (high byte, low byte)
	for (int i = 0; i <= 7; i++)
	{
		Wire.beginTransmission(_I2C_address);
		Wire.write(RegDir[i]);        // Configure the device to read each CH  
		if (Wire.endTransmission() == 0) {
			// Read A/D value
			Wire.requestFrom(_I2C_address, 2);
			if (Wire.available() == 2)         // Checkf for RegDira from slave
			{
				Adval_High = Wire.read();   // Receive A/D high byte
				Adval_Low = Wire.read();    // Receive A/D low byte
				Value[i] = (((int)Adval_High) << 8) | Adval_Low;
			}
			else { delay(10); }
		}
		else {delay(10);}
	}
}
