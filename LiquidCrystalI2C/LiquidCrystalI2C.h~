/**************************************************************************
 * LiquidCrystal-I2C a simple way to control a 16x2 LCD display over I2C. *
 * Copyright (C) 2014 Mario Gomez (info -at- teubi.co).                                        *
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

#ifndef TwoWire_h
#include <Wire.h>
#endif

#include <inttypes.h>

// Commands to be decoded over I2C
#define LCDI2C_PRINT 0x01
#define LCDI2C_CLEAR 0x02
#define LCDI2C_HOME 0x03
#define LCDI2C_SETCURSOR 0x04
#define LCDI2C_DEBUG 0x99

class LiquidCrystalI2C {
  public:
    LiquidCrystalI2C();
    LiquidCrystalI2C(uint8_t address);
    void print(char *str);
    void clear();
    void home();
    void setCursor(uint8_t col, uint8_t row);
    void debug(uint8_t enable);
  private:
    uint8_t internal_address;
};

