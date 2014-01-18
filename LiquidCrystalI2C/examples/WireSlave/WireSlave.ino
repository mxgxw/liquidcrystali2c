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
#include <Wire.h>
#include <LiquidCrystal.h>
#include <Serial.h>
#include <inttypes.h>

void consumeData(int);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  Wire.begin(85);
  Wire.onReceive(consumeData);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16,2);
  
  Serial.begin(9600);
  
  Serial.println("Serial monitoring started");
}

// Commands to be decoded over I2C
#define LCDI2C_PRINT 0x01
#define LCDI2C_CLEAR 0x02
#define LCDI2C_HOME 0x03
#define LCDI2C_SETCURSOR 0x04
#define LCDI2C_DEBUG 0x99 // enables debug mode

volatile uint8_t debug = 0;

void consumeData(int dataSize) {
  
  if(!Wire.available()) {
    return; // Error detected. No data received
  }
  
  int i2c_command = Wire.read();
  uint8_t param1, param2, i;
  char *buffer;
  
  //Serial.println("Data received, comm:");
  //Serial.print(i2c_command,DEC);
  //Serial.print("Data size");
  //Serial.print(dataSize,DEC);
  //Serial.write("\r\n");
  switch(i2c_command) {
    case(LCDI2C_PRINT):
      
      buffer = (char*)malloc(dataSize); // create buffer
      i = 0;
      while(Wire.available()) {
        buffer[i++] = (char)Wire.read();
      }
      buffer[dataSize-1] = 0;
      lcd.print(buffer);
      
      free(buffer); // We don't want memory leaks
      
      break;
    case(LCDI2C_CLEAR):
      lcd.clear();
      break;
    case(LCDI2C_HOME):
      lcd.home();
      break;
    case(LCDI2C_SETCURSOR):
      if(dataSize<3) return; // wrong format, end inmediatly
      param1 = Wire.read();
      param2 = Wire.read();
      lcd.setCursor(param1,param2);
      break;
  }  
}

void loop() {
}
