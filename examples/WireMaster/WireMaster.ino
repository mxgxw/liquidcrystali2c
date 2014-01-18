/**************************************************************************
 * LiquidCrystal-I2C a simple way to control a 16x2 LCD display over I2C. *
 * Copyright (C) 2014 Mario Gomez (info -at- teubi.co).                                       *
 *                                                                        *
 * This program is free software; you can redistribute it and/or modify   *
 * it under the terms of the GNU General Public License as published by   *
 * the Free Software Foundation; either version 3 of the License, or      *
 * any later version.                                                     *
 *                                                                        *
 * This rogram is distributed in the hope that it will be useful,         *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the           *
 * GNU General Public License for more details.                           *
 *                                                                        *
 * You should have received a copy of the GNU General Public License      *
 * along with this program; if not write to the Free Software Foundation, *
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA       * 
 *************************************************************************/
#include <Wire.h>
#include "LiquidCrystalI2C.h"

LiquidCrystalI2C lcdI2C;

void setup() {
  Wire.begin();
  
  lcdI2C = LiquidCrystalI2C(85);
  lcdI2C.clear();
}

int count = 0;
char buffer[16];

void loop() {
  lcdI2C.home();
  lcdI2C.print("Hola TeUbi.co!");
  lcdI2C.setCursor(0,1);
  itoa(count++,buffer,10);
  lcdI2C.print(buffer);
  delay(1000);
}



