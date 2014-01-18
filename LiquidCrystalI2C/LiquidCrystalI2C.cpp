/**************************************************************************
 * LiquidCrystal-I2C a simple way to control a 16x2 LCD display over I2C. *
 * Copyright (C) 2014 Mario Gomez (info -at- teubi.co).                   *
 *                                                                        *
 * This program is free software; you can redistribute it and/or modify   *
 * it under the terms of the GNU General Public License as published by   *
 * the Free Software Foundation; either version 3 of the License, or      *
 * any later version.                                                     *
 *                                                                        *
 * This program is distributed in the hope that it will be useful,        *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the           *
 * GNU General Public License for more details.                           *
 *                                                                        *
 * You should have received a copy of the GNU General Public License      *
 * along with this program; if not write to the Free Software Foundation, *
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA       * 
 *************************************************************************/
#include "LiquidCrystalI2C.h"
#include <Arduino.h>

LiquidCrystalI2C::LiquidCrystalI2C() {
}

LiquidCrystalI2C::LiquidCrystalI2C(uint8_t address) {
  internal_address = address;
}

void LiquidCrystalI2C::print(char *str) {
  Wire.beginTransmission(internal_address);
  Wire.write(LCDI2C_PRINT);
  Wire.write(str);
  Wire.endTransmission();
}

void LiquidCrystalI2C::clear() {
  Wire.beginTransmission(internal_address);
  Wire.write(LCDI2C_CLEAR);
  Wire.endTransmission();
}

void LiquidCrystalI2C::home() {
  Wire.beginTransmission(internal_address);
  Wire.write(LCDI2C_HOME);
  Wire.endTransmission();
}

void LiquidCrystalI2C::setCursor(uint8_t col, uint8_t row) {
  Wire.beginTransmission(internal_address);
  Wire.write(LCDI2C_SETCURSOR);
  Wire.write(col);
  Wire.write(row);
  Wire.endTransmission();
}


void LiquidCrystalI2C::debug(uint8_t enable) {
  Wire.beginTransmission(internal_address);
  Wire.write(LCDI2C_DEBUG);
  Wire.write(enable);
  Wire.endTransmission();
}
