LiquidCrystal-I2C
=================

This is a really small library to control a 16x2 LCD
character display over the I2C bus in Arduino.

You'll need an ATmega328 with the 8Mhz breadboard bootloader.

The ATmega328 works as a display controller for the really
common and available 16x2 screens based on the HD44780 paraller
interface.

Usage
================

Prepare your ATmega328 with the 8Mhz breadboard bootloader, for
doing this you can follow the instructions at this address:

http://arduino.cc/en/Tutorial/ArduinoToBreadboard

Look for the section "Minimal Circuit".

Wire the LCD screen as shown on the picture:

http://arduino.cc/en/Uploadas/Tutorial/LCD_bb.png

Connect the lines A4 and A5 between your Arduino and the
ATmega328 use a couple of 4.7K resistances to VCC..

Upload the Sketch "WireSlave" to the ATMega328.

Upload the Sketch "WireMaster" to your Arduino.

Enjoy!


License
=================

LiquidCrystal-I2C a simple way to control a 16x2 LCD display over I2C.
Copyright (C) 2014 Mario Gomez.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
any later version.

This rogram is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not write to the Free Software Foundation,
Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA


