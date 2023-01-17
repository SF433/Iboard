/*
  main.cpp - Main loop for Arduino sketches
  Copyright (c) 2005-2013 Arduino Team.  All right reserved.

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

#include <Arduino.h>

// Declared weak in Arduino.h to allow user redefinitions.
int atexit(void (* /*func*/ )()) { return 0; }

// Weak empty variant initialization function.
// May be redefined by variant files.
void initVariant() __attribute__((weak));
void initVariant() { }

//void setupUSB() __attribute__((weak));
//void setupUSB() { }

int main(void)
{
  init();

  initVariant();

#if defined(USBCON)
  USBDevice.attach();
#endif

  digitalReset();

  setup();
    
  for (;;) {
    loop();
    if (serialEventRun) serialEventRun();
  }
        
  return 0;
}
void digitalReset()
{
#if defined(MPAINO128)
    //uint8_t oldSREG = SREG;
    //cli();
    //inputsel
    DDRA |= (1 << 0) | (1 << 1) | (1 << 2);
    DDRE |= (1 << 2) | (1 << 6); //(DDRE2 -> SLED)

    //PULLUP
    /*PORTC |= (1 << 6) | (1 << 7);
    PORTG |= (1 << 2);
    PORTA |= (1 << 3) | (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);*/
    //outsel
    DDRD |= (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);

    //output
    DDRG |= (1 << 0) | (1 << 1);
    DDRC |= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);



    for (int i = 0; i <= 1; i++) {
        PORTG &= ~(1 << i);
    }
    for (int i = 0; i <= 5; i++) {
        PORTC &= ~(1 << i);
    }
    PORTD &= ~(1 << 4);
    PORTD &= ~(1 << 5);
    PORTD &= ~(1 << 6);
    PORTD |= (1 << 7);

    PORTD |= (1 << 4);
    PORTD &= ~(1 << 5);
    PORTD &= ~(1 << 6);

    PORTD &= ~(1 << 4);
    PORTD |= (1 << 5);
    PORTD &= ~(1 << 6);

    PORTD |= (1 << 4);
    PORTD |= (1 << 5);
    PORTD &= ~(1 << 6);

    PORTD &= ~(1 << 4);
    PORTD &= ~(1 << 5);
    PORTD |= (1 << 6);

    PORTD |= (1 << 4);
    PORTD &= ~(1 << 5);
    PORTD |= (1 << 6);

    PORTD &= ~(1 << 4);
    PORTD |= (1 << 5);
    PORTD |= (1 << 6);

    PORTD |= (1 << 4);
    PORTD |= (1 << 5);
    PORTD |= (1 << 6);

    PORTD &= ~(1 << 7);
    //SREG = oldSREG;

#endif
#if defined(MPAINO2560_S)

   // uint8_t oldSREG = SREG;
    //cli();
    DDRK = 0xFF;
    DDRF = 0xFF;
    PORTK = 0xFF;
    PORTF = 0x00;
    PORTK = 0x00;
    //SREG = oldSREG;
#endif
}

