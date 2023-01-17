/*
  wiring_digital.c - digital input and output functions
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2005-2006 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  Modified 28 September 2010 by Mark Sproul
*/

#define ARDUINO_MAIN
#include "wiring_private.h"
#include "pins_arduino.h"

void pinMode(uint8_t pin, uint8_t mode)
{
//    uint8_t bit = digitalPinToBitMask(pin);//_BV(n);
//    reg = portModeRegister(port);//DDRn
//    out = portOutputRegister(port);//PORTn
#if defined(MPAINO128)

    if (mode == INPUT) {
    }
    else if (mode == INPUT_PULLUP) {
    }
    else {
    }
#endif // defined(MPAINO128)
#if defined(MPAINO2560_S)
    if (mode == INPUT) {
    }
    else if (mode == INPUT_PULLUP) {
    }
    else {
    }
#endif
#if defined(MPAINO2560) || defined(MPINO128)
    uint8_t bit = digitalPinToBitMask(pin);
    uint8_t port = digitalPinToPort(pin);
    volatile uint8_t* reg, * out;

    if (port == NOT_A_PIN) return;

    // JWS: can I let the optimizer do this?
    reg = portModeRegister(port);
    out = portOutputRegister(port);

    if (mode == INPUT) {
        uint8_t oldSREG = SREG;
        cli();
        *reg &= ~bit;
        *out &= ~bit;
        SREG = oldSREG;
    }
    else if (mode == INPUT_PULLUP) {
        uint8_t oldSREG = SREG;
        cli();
        *reg &= ~bit;
        *out |= bit;
        SREG = oldSREG;
    }
    else {
        uint8_t oldSREG = SREG;
        cli();
        *reg |= bit;
        SREG = oldSREG;
    }

#endif

}

// Forcing this inline keeps the callers from having to push their own stuff
// on the stack. It is a good performance win and only takes 1 more byte per
// user than calling. (It will take more bytes on the 168.)
//
// But shouldn't this be moved into pinMode? Seems silly to check and do on
// each digitalread or write.
//
// Mark Sproul:
// - Removed inline. Save 170 bytes on atmega1280
// - changed to a switch statment; added 32 bytes but much easier to read and maintain.
// - Added more #ifdefs, now compiles for atmega645
//
//static inline void turnOffPWM(uint8_t timer) __attribute__ ((always_inline));
//static inline void turnOffPWM(uint8_t timer)
static void turnOffPWM(uint8_t timer)
{
  switch (timer)
  {
    // Timer1
    #if defined(TCCR1A) && defined(COM1A1)
      case TIMER1A:
        TCCR1A &= ~_BV(COM1A1);
        break;
    #endif
    #if defined(TCCR1A) && defined(COM1B1)
      case TIMER1B:
        TCCR1A &= ~_BV(COM1B1);
        break;
    #endif
    #if defined(TCCR1A) && defined(COM1C1)
      case TIMER1C:
        TCCR1A &= ~_BV(COM1C1);
        break;
    #endif
    
    // Timer2
    #if defined(TCCR2) && defined(COM21)
      case TIMER2:
        TCCR2 &= ~_BV(COM21);
        break;
    #endif
    #if defined(TCCR2A) && defined(COM2A1)
      case TIMER2A:
        TCCR2A &= ~_BV(COM2A1);
        break;
    #endif
    #if defined(TCCR2A) && defined(COM2B1)
      case TIMER2B:
        TCCR2A &= ~_BV(COM2B1);
        break;
    #endif

    // Timer3
    #if defined(TCCR3A) && defined(COM3A1)
      case TIMER3A:
        TCCR3A &= ~_BV(COM3A1);
        break;
    #endif
    #if defined(TCCR3A) && defined(COM3B1)
      case TIMER3B:
        TCCR3A &= ~_BV(COM3B1);
        break;
    #endif
    #if defined(TCCR3A) && defined(COM3C1)
      case TIMER3C:
        TCCR3A &= ~_BV(COM3C1);
        break;
    #endif

    // Timer4
    #if defined(TCCR4A) && defined(COM4A1)
      case TIMER4A:
        TCCR4A &= ~_BV(COM4A1);
        break;
    #endif
    #if defined(TCCR4A) && defined(COM4B1)
      case  TIMER4B:
        TCCR4A &= ~_BV(COM4B1);
        break;
    #endif
    #if defined(TCCR4A) && defined(COM4C1)
      case TIMER4C:
        TCCR4A &= ~_BV(COM4C1);
        break;
    #endif
    #if defined(TCCR4C) && defined(COM4D1)
      case TIMER4D:
        TCCR4C &= ~_BV(COM4D1);
        break;
    #endif

    // Timer5
    #if defined(TCCR5A)
      case TIMER5A:
        TCCR5A &= ~_BV(COM5A1);
        break;
      case TIMER5B:
        TCCR5A &= ~_BV(COM5B1);
        break;
      case TIMER5C:
        TCCR5A &= ~_BV(COM5C1);
        break;
    #endif

    // Timer0
    #if defined(TCCR0) && defined(COM01)
      case TIMER0:
        TCCR0 &= ~_BV(COM01);
        break;
      case TIMER0A:
        TCCR0 &= ~_BV(COM01);
        break;
    #endif
    #if defined(TCCR0A) && defined(COM0A1)
      case TIMER0A:
        TCCR0A &= ~_BV(COM0A1);
        break;
    #endif
    #if defined(TCCR0A) && defined(COM0B1)
      case TIMER0B:
        TCCR0A &= ~_BV(COM0B1);
        break;
    #endif
  }
}
#if defined(MPAINO128)
byte _MPAINO_OUT_DATA1[8] = {};
byte _MPAINO_OUT_DATA2[8] = {};
#endif // defined(MPAINO128)
#if defined(MPAINO2560_S)
byte _MPAINO_OUT_DATA1[8] = {};
#endif



int digitalRead(uint8_t pin)
{
#ifdef MPAINO128
    uint8_t p = pin;
    uint8_t moduleNumber = p / 8;
    uint8_t IONumber = p % 8;
    switch (moduleNumber)
    {
    case 0:
        PORTA &= ~(1 << 0);
        PORTA &= ~(1 << 1);
        PORTA &= ~(1 << 2);
        break;
    case 1:
        PORTA |= (1 << 0);
        PORTA &= ~(1 << 1);
        PORTA &= ~(1 << 2);
        break;
    case 2:
        PORTA &= ~(1 << 0);
        PORTA |= (1 << 1);
        PORTA &= ~(1 << 2);
        break;
    case 3:
        PORTA |= (1 << 0);
        PORTA |= (1 << 1);
        PORTA &= ~(1 << 2);
        break;
    case 4:
        PORTA &= ~(1 << 0);
        PORTA &= ~(1 << 1);
        PORTA |= (1 << 2);
        break;
    case 5:
        PORTA |= (1 << 0);
        PORTA &= ~(1 << 1);
        PORTA |= (1 << 2);
        break;
    case 6:
        PORTA &= ~(1 << 0);
        PORTA |= (1 << 1);
        PORTA |= (1 << 2);
        break;
    case 7:
        PORTA |= (1 << 0);
        PORTA |= (1 << 1);
        PORTA |= (1 << 2);
        break;
    }
    PORTE |= (1 << 6);
    switch (IONumber) {
    case 0:
        if (PINC & 0x40) {
            PORTE &= ~(1 << 6);
            return HIGH;
        }
        break;
    case 1:
        if (PINC & 0x80) {
            PORTE &= ~(1 << 6);
            return HIGH;
        }
        break;
    case 2:
        if (PING & 0x04) {
            PORTE &= ~(1 << 6);
            return HIGH;
        }
        break;
    case 3:
        if (PINA & 0x80) {
            PORTE &= ~(1 << 6);
            return HIGH;
        }
        break;
    case 4:
        if (PINA & 0x40) {
            PORTE &= ~(1 << 6);
            return HIGH;
        }
        break;
    case 5:
        if (PINA & 0x20) {
            PORTE &= ~(1 << 6);
            return HIGH;
        }
        break;
    case 6:
        if (PINA & 0x10) {
            PORTE &= ~(1 << 6);
            return HIGH;
        }
        break;
    case 7:
        if (PINA & 0x08) {
            PORTE &= ~(1 << 6);
            return HIGH;
        }
        break;
    }
    PORTE &= ~(1 << 6);
    return LOW;

#endif
#if defined(MPAINO2560_S)
    uint8_t p = pin;
    uint8_t moduleNumber = p / 8;
    uint8_t IONumber = p % 8;
    DDRC |= 0xFF;
    PORTC |= 0xFF;
    switch (moduleNumber)
    {
    case 0:
        PORTC &= ~(1 << 0);
        break;
    case 1:
        PORTC &= ~(1 << 1);
        break;
    case 2:
        PORTC &= ~(1 << 2);
        break;
    case 3:
        PORTC &= ~(1 << 3);
        break;
    case 4:
        PORTC &= ~(1 << 4);
        break;
    case 5:
        PORTC &= ~(1 << 5);
        break;
    case 6:
        PORTC &= ~(1 << 6);
        break;
    case 7:
        PORTC &= ~(1 << 7);
        break;
    }
    switch (IONumber) {
    case 0:
        if (PINH & 0x40) {
            PORTC |= 0xFF;
            return HIGH;
        }
        break;
    case 1:
        if (PINH & 0x20) {
            PORTC |= 0xFF;
            return HIGH;
        }
        break;
    case 2:
        if (PINH & 0x10) {
            PORTC |= 0xFF;
            return HIGH;
        }
        break;
    case 3:
        if (PINH & 0x08) {
            PORTC |= 0xFF;
            return HIGH;
        }
        break;
    case 4:
        if (PINE & 0x08) {//09
            PORTC |= 0xFF;
            return HIGH;
        }
        break;
    case 5:
        if (PING & 0x20) {//24
            PORTC |= 0xFF;
            return HIGH;
        }
        break;
    case 6:
        if (PINE & 0x20) {//21
            PORTC |= 0xFF;
            return HIGH;
        }
        break;
    case 7:
        if (PINE & 0x10) {//11
            PORTC |= 0xFF;
            return HIGH;
        }
        break;
    }
    return LOW;
#endif
#if defined(MPAINO2560) || defined(MPINO128)
    uint8_t timer = digitalPinToTimer(pin);
    uint8_t bit = digitalPinToBitMask(pin);
    uint8_t port = digitalPinToPort(pin);

    if (port == NOT_A_PIN) return LOW;

    // If the pin that support PWM output, we need to turn it off
    // before getting a digital reading.
    if (timer != NOT_ON_TIMER) turnOffPWM(timer);

    if (*portInputRegister(port) & bit) return HIGH;
    return LOW;
#endif
}


void digitalWrite(uint8_t pin, uint8_t val)
{
#if defined(MPAINO128)

    uint8_t oldSREG = SREG;
    //cli();
    uint8_t p = 0;
    if (pin <= 16) {
        if (val >= 1) {//HIGH
            switch (pin) {
            case 8:
                PORTG |= (1 << 0);
                break;
            case 9:
                PORTG |= (1 << 1);
                break;
            case 10:
                PORTC |= (1 << 0);
                break;
            case 11:
                PORTC |= (1 << 1);
                break;
            case 12:
                PORTC |= (1 << 2);
                break;
            case 13:
                PORTC |= (1 << 3);
                break;
            case 14:
                PORTC |= (1 << 4);
                break;
            case 15:
                PORTC |= (1 << 5);
                break;
            }
        }
        else {//LOW
            switch (pin) {
            case 8:
                PORTG &= ~(1 << 0);
                break;
            case 9:
                PORTG &= ~(1 << 1);
                break;
            case 10:
                PORTC &= ~(1 << 0);
                break;
            case 11:
                PORTC &= ~(1 << 1);
                break;
            case 12:
                PORTC &= ~(1 << 2);
                break;
            case 13:
                PORTC &= ~(1 << 3);
                break;
            case 14:
                PORTC &= ~(1 << 4);
                break;
            case 15:
                PORTC &= ~(1 << 5);
                break;
            }

        }
    }
    else if (pin == 20) {
        if (val >= 1) {
            PORTE |= (1 << 2);
        }
        else if (val == false) {
            PORTE &= ~(1 << 2);
        }
    }
    else if (pin >= 32 && pin <= 96) {
        p = pin - 32;
        uint8_t onoff = val;
        uint8_t moduleNumber = p / 8;
        uint8_t IONumber = p % 8;
        switch (moduleNumber) {
        case 0:
            PORTD &= ~(1 << 4);
            PORTD &= ~(1 << 5);
            PORTD &= ~(1 << 6);
            break;
        case 1:
            PORTD |= (1 << 4);
            PORTD &= ~(1 << 5);
            PORTD &= ~(1 << 6);
            break;
        case 2:
            PORTD &= ~(1 << 4);
            PORTD |= (1 << 5);
            PORTD &= ~(1 << 6);
            break;
        case 3:
            PORTD |= (1 << 4);
            PORTD |= (1 << 5);
            PORTD &= ~(1 << 6);
            break;
        case 4:
            PORTD &= ~(1 << 4);
            PORTD &= ~(1 << 5);
            PORTD |= (1 << 6);
            break;
        case 5:
            PORTD |= (1 << 4);
            PORTD &= ~(1 << 5);
            PORTD |= (1 << 6);
            break;
        case 6:
            PORTD &= ~(1 << 4);
            PORTD |= (1 << 5);
            PORTD |= (1 << 6);
            break;
        case 7:
            PORTD |= (1 << 4);
            PORTD |= (1 << 5);
            PORTD |= (1 << 6);
            break;
        }
        if (onoff == false) {
            if (IONumber <= 1) {
                _MPAINO_OUT_DATA1[moduleNumber] &= ~(1 << IONumber);//PG0, PG1
            }
            else {
                _MPAINO_OUT_DATA2[moduleNumber] &= ~(1 << IONumber - 2);//PC0~PC5
            }
        }
        else {
            if (IONumber <= 1) {
                _MPAINO_OUT_DATA1[moduleNumber] |= (1 << IONumber);//PG0, PG1
            }
            else {
                _MPAINO_OUT_DATA2[moduleNumber] |= (1 << IONumber - 2);//PC0~PC5
            }
        }

        PORTD |= (1 << 7);
        PORTG |= _MPAINO_OUT_DATA1[moduleNumber];
        PORTC |= _MPAINO_OUT_DATA2[moduleNumber];
        PORTD &= ~(1 << 7);

        PORTG &= ~(1 << 0);
        PORTG &= ~(1 << 1);
        PORTC &= ~(1 << 0);
        PORTC &= ~(1 << 1);
        PORTC &= ~(1 << 2);
        PORTC &= ~(1 << 3);
        PORTC &= ~(1 << 4);
        PORTC &= ~(1 << 5);
    }
    SREG = oldSREG;
    
#endif
#if defined(MPAINO2560_S)
    uint8_t p = pin - 32;
    uint8_t onoff = val;
    uint8_t moduleNumber = p / 8;
    uint8_t IONumber = p % 8;
    DDRK = 0xFF;
    DDRF = 0xFF;
    PORTK = 0x00;
    PORTF = 0x00;

    switch (moduleNumber) {
    case 0:
        PORTK |= (1 << 7);
        break;
    case 1:
        PORTK |= (1 << 6);
        break;
    case 2:
        PORTK |= (1 << 5);
        break;
    case 3:
        PORTK |= (1 << 4);
        break;
    case 4:
        PORTK |= (1 << 3);
        break;
    case 5:
        PORTK |= (1 << 2);
        break;
    case 6:
        PORTK |= (1 << 1);
        break;
    case 7:
        PORTK |= (1 << 0);
        break;
}
    if (onoff == true) {
        _MPAINO_OUT_DATA1[moduleNumber] |= (1 << 7 - IONumber);
    }
    else {
        _MPAINO_OUT_DATA1[moduleNumber] &= ~(1 << 7 - IONumber);
    }
    PORTF = _MPAINO_OUT_DATA1[moduleNumber];
    PORTK |= 0x00;
#endif
#if defined(MPAINO2560) || defined(MPINO128)
    uint8_t timer = digitalPinToTimer(pin);
    uint8_t bit = digitalPinToBitMask(pin);
    uint8_t port = digitalPinToPort(pin);
    volatile uint8_t* out;

    if (port == NOT_A_PIN) return;

    // If the pin that support PWM output, we need to turn it off
    // before doing a digital write.
    if (timer != NOT_ON_TIMER) turnOffPWM(timer);

    out = portOutputRegister(port);

    uint8_t oldSREG = SREG;
    cli();

    if (val == LOW) {
        *out &= ~bit;
    }
    else {
        *out |= bit;
    }

    SREG = oldSREG;
#endif


}

