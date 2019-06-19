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

#ifndef excontrol_ads7828_h
#define excontrol_ads7828_h

#include "Arduino.h"
#include <Wire.h> 



class Ads7828
{
public:
	Ads7828(int addr);
	void update();
	int Value[8] = {0,0,0,0,0,0,0,0};
private:
	int _I2C_address;
	const byte RegDir[8] = {0x8C,0xCC,0x9C,0xDC,0xAC,0xEC,0xBC,0xFC };
};


#endif
