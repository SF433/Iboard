/***************************************************|
|            MEGACORE AVR 64-PIN PINOUT             |
|        https://github.com/MCUdude/MegaCore        |
|                                                   |
| This file is used when compiling for:             |
| ATmega2561/V                                      |
| ATmega1281/V                                      |
| ATmega128/A                                       |
| ATmega64/A                                        |
|                                                   |
|***************************************************/


#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>
#define MEGACORE
#define MCUDUDE_MEGACORE
//#define MPAINO_8A8R_S
#define MPAINO128

// Current pinout
#define MEGACORE_64_PIN_AVR_PINOUT

// Digital pins
#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__) || defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__)
#define NUM_DIGITAL_PINS           (54)
#elif defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
#define NUM_DIGITAL_PINS           (55)
#endif

// PWM pins
#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__) || defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__)
  #define digitalPinHasPWM(p)      (((p) >= 3 && (p) <= 5) || ((p) >= 12 && (p) <= 15))
#elif defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
  #define digitalPinHasPWM(p)      (((p) >= 3 && (p) <= 5) || ((p) >= 12 && (p) <= 15) || ((p) == 53))
#endif

// Builtin LED
#define LED_BUILTIN   (20)    //PE2
static const uint8_t LED = LED_BUILTIN;

// Analog pins
#define PIN_A0   (43)
#define PIN_A1   (44)
#define PIN_A2   (45)
#define PIN_A3   (46)
#define PIN_A4   (47)
#define PIN_A5   (48)
#define PIN_A6   (49)
#define PIN_A7   (38)
static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
static const uint8_t A6 = PIN_A6;
static const uint8_t A7 = PIN_A7;
#define NUM_ANALOG_INPUTS          (7)
#define analogInputToDigitalPin(p) (((p) < 7) ? (p) + 43 : -1)
#define analogPinToChannel(p)      ((p) < NUM_ANALOG_INPUTS ? (p) != 38 ? (p)  : (p)-12 : (p) >= 43 ? (p) - 43 : -1)

// SPI defs
#define PIN_SPI_SS    (53)
#define PIN_SPI_SCK   (52)
#define PIN_SPI_MOSI  (51)
#define PIN_SPI_MISO  (50)
static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t SCK  = PIN_SPI_SCK;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;

// i2c
#define PIN_WIRE_SCL  (18)
#define PIN_WIRE_SDA  (19)
static const uint8_t SCL = PIN_WIRE_SCL;
static const uint8_t SDA = PIN_WIRE_SDA;

// Interrupts
#define EXTERNAL_NUM_INTERRUPTS    (8)
#define digitalPinToInterrupt(p)   (((p) >= 24 && (p) <= 25) ? (p) - 18 : NOT_AN_INTERRUPT)

// PCINT
#if defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
#define digitalPinToPCICR(p)    ((((p) >= 8) && ((p) <= 15)) || ((p) == 0) ? (&PCICR) : ((uint8_t*)0))
#define digitalPinToPCICRbit(p) ((((p) >= 8) && ((p) <= 15)) ? 0 : ((((p) == 0)  ? 1 : 0)))
#define digitalPinToPCMSK(p)    ((((p) >= 8) && ((p) <= 15)) ? (&PCMSK0) : ((((p) == 0)  ? (&PCMSK1) : ((uint8_t*)0))))
#define digitalPinToPCMSKbit(p) ((((p) >= 8) && ((p) <= 15)) ? ((p) - 8) : (((p) ==  0) ? 1 : 0))
#endif


#define PIN_PC6 0
#define PIN_PC7 1
#define PIN_PG2 2
#define PIN_PA7 3
#define PIN_PA6 4
#define PIN_PA5 5
#define PIN_PA4 6
#define PIN_PA3 7
#define PIN_PA2 8
#define PIN_PA1 9
#define PIN_PA0 10
#define PIN_PE6 11
#define PIN_PD4 12
#define PIN_PD5 13
#define PIN_PD6 14
#define PIN_PD7 15
#define PIN_PE0 16
#define PIN_PE1 17
#define PIN_PD0 18
#define PIN_PD1 19
#define PIN_PE2 20
#define PIN_PE3 21
#define PIN_PE4 22
#define PIN_PE5 23
#define PIN_PD2 24
#define PIN_PD3 25
#define PIN_PB5 26
#define PIN_PB6 27
#define PIN_PB7 28
#define PIN_PF7 29
#define PIN_PG0 30
#define PIN_PG1 21
#define PIN_PC0 32
#define PIN_PC1 33
#define PIN_PC2 34
#define PIN_PC3 35
#define PIN_PC4 36
#define PIN_PC5 37
#define PIN_PF7 38
#define PIN_PB0 39
#define PIN_PB4 40
#define PIN_PG3 41
#define PIN_PG4 42
#define PIN_PF0 43
#define PIN_PF1 44
#define PIN_PF2 45
#define PIN_PF3 46
#define PIN_PF4 47
#define PIN_PF5 48
#define PIN_PF6 49
#define PIN_PB3 50
#define PIN_PB2 51
#define PIN_PB1 52
#define PIN_PE7 53
/*#define PIN_PF6 54
#if defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
  #define PIN_PG5 53
#endif
*/
#ifdef ARDUINO_MAIN

const uint16_t PROGMEM port_to_mode_PGM[] = {
  NOT_A_PORT,
  (uint16_t) &DDRA,
  (uint16_t) &DDRB,
  (uint16_t) &DDRC,
  (uint16_t) &DDRD,
  (uint16_t) &DDRE,
  (uint16_t) &DDRF,
  (uint16_t) &DDRG,
};

const uint16_t PROGMEM port_to_output_PGM[] = {
  NOT_A_PORT,
  (uint16_t) &PORTA,
  (uint16_t) &PORTB,
  (uint16_t) &PORTC,
  (uint16_t) &PORTD,
  (uint16_t) &PORTE,
  (uint16_t) &PORTF,
  (uint16_t) &PORTG,
};

const uint16_t PROGMEM port_to_input_PGM[] = {
  NOT_A_PIN,
  (uint16_t) &PINA,
  (uint16_t) &PINB,
  (uint16_t) &PINC,
  (uint16_t) &PIND,
  (uint16_t) &PINE,
  (uint16_t) &PINF,
  (uint16_t) &PING,
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] = {
  PC, // PC6 ** D34       **0
  PC, // PC7 ** D35       **1
  PG, // PG2 ** D36       **2
  PA, // PA7 ** D37       **3
  PA, // PA6 ** D38       **4
  PA, // PA5 ** D39       **5
  PA, // PA4 ** D40       **6
  PA, // PA3 ** D41       **7
  PA, // PA2 ** D42       **8
  PA, // PA1 ** D43       **9
  PA, // PA0 ** D44       **10
  PE, // PE6 ** D6        **11
  PD, // PD4 ** D22     **12
  PD, // PD5 ** D23     **13
  PD, // PD6 ** D24     **14
  PD, // PD7 ** D25     **15
  PE, // PE0 ** D0 ** RX0       **16
  PE, // PE1 ** D1 ** TX0       **17
  PD, // PD0 ** D18 ** SCL        **18
  PD, // PD1 ** D19 ** SDA        **19
  PE, // PE2 ** D2        **20
  PE, // PE3 ** D3 ** PWM       **21
  PE, // PE4 ** D4 ** PWM       **22
  PE, // PE5 ** D5 ** PWM       **23
  PD, // PD2 ** D20 ** RX1        **24
  PD, // PD3 ** D21 ** TX1        **25
  PB, // PB5 ** D13 ** PWM        **26
  PB, // PB6 ** D14 ** PWM        **27
  PB, // PB7 ** D15 ** PWM        **28
  PF, // PF7 ** D52 ** A7        **29
  PG, // PG0 ** D26        **30
  PG, // PG1 ** D27        **31
  PC, // PC0 ** D28        **32
  PC, // PC1 ** D29        **33
  PC, // PC2 ** D30        **34
  PC, // PC3 ** D31        **35
  PC, // PC4 ** D32        **36
  PC, // PC5 ** D33        **37
  PF, // PF7 ** D52 ** A7        **38
  PB, // PB0 ** D8 ** SS        **39
  PB, // PB4 ** D12 ** PWM        **40
  PG, // PG3 ** D16        **41
  PG, // PG4 ** D17        **42
  PF, // PF0 ** D45 ** A0        **43
  PF, // PF1 ** D46 ** A1        **44
  PF, // PF2 ** D47 ** A2        **45
  PF, // PF3 ** D48 ** A3        **46
  PF, // PF4 ** D49 ** A4        **47
  PF, // PF5 ** D50 ** A5        **48
  PF, // PF6 ** D51 ** A6        **49
  PB, // PB3 ** D11 ** MISO        **50
  PB, // PB2 ** D10 ** MOSI        **51
  PB, // PB1 ** D9 ** SCK        **52
  PE, // PE7 ** D7        **53
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
  _BV(6), // PC6 ** D34       **0
  _BV(7), // PC7 ** D35       **1
  _BV(2), // PG2 ** D36       **2
  _BV(7), // PA7 ** D37       **3
  _BV(6), // PA6 ** D38       **4
  _BV(5), // PA5 ** D39       **5
  _BV(4), // PA4 ** D40       **6
  _BV(3), // PA3 ** D41       **7
  _BV(2), // PA2 ** D42       **8
  _BV(1), // PA1 ** D43       **9
  _BV(0), // PA0 ** D44       **10
  _BV(6), // PE6 ** D6        **11
  _BV(4), // PD4 ** D22     **12
  _BV(5), // PD5 ** D23     **13
  _BV(6), // PD6 ** D24     **14
  _BV(7), // PD7 ** D25     **15
  _BV(0), // PE0 ** D0 ** RX0       **16
  _BV(1), // PE1 ** D1 ** TX0       **17
  _BV(0), // PD0 ** D18 ** SCL        **18
  _BV(1), // PD1 ** D19 ** SDA        **19
  _BV(2), // PE2 ** D2        **20
  _BV(3), // PE3 ** D3 ** PWM       **21
  _BV(4), // PE4 ** D4 ** PWM       **22
  _BV(5), // PE5 ** D5 ** PWM       **23
  _BV(2), // PD2 ** D20 ** RX1        **24
  _BV(3), // PD3 ** D21 ** TX1        **25
  _BV(5), // PB5 ** D13 ** PWM        **26
  _BV(6), // PB6 ** D14 ** PWM        **27
  _BV(7), // PB7 ** D15 ** PWM        **28
  _BV(7), // PF7 ** D52 ** A7       **29
  _BV(0), // PG0 ** D26     **30
  _BV(1), // PG1 ** D27     **31
  _BV(0), // PC0 ** D28     **32
  _BV(1), // PC1 ** D29     **33
  _BV(2), // PC2 ** D30       **34
  _BV(3), // PC3 ** D31       **35
  _BV(4), // PC4 ** D32       **36
  _BV(5), // PC5 ** D33       **37
  _BV(7), // PF7 ** D52 ** A7     **38
  _BV(0), // PB0 ** D8 ** SS        **39
  _BV(4), // PB4 ** D12 ** PWM        **40
  _BV(3), // PG3 ** D16       **41
  _BV(4), // PG4 ** D17       **42
  _BV(0), // PF0 ** D45 ** A0       **43
  _BV(1), // PF1 ** D46 ** A1       **44
  _BV(2), // PF2 ** D47 ** A2       **45
  _BV(3), // PF3 ** D48 ** A3       **46
  _BV(4), // PF4 ** D49 ** A4     **47
  _BV(5), // PF5 ** D50 ** A5     **48
  _BV(6), // PF6 ** D51 ** A6     **49
  _BV(3), // PB3 ** D11 ** MISO       **50
  _BV(2), // PB2 ** D10 ** MOSI       **51
  _BV(1), // PB1 ** D9 ** SCK       **52
  _BV(7), // PE7 ** D7        **53
/*  _BV(5), // PF5 ** D50 ** A5 
#if defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
  _BV(5), // PG5 ** D53 ** PWM
#endif*/
};

const uint8_t PROGMEM digital_pin_to_timer_PGM[] = {
  NOT_ON_TIMER, // PC6 ** D34       **0
  NOT_ON_TIMER, // PC7 ** D35       **1
  NOT_ON_TIMER, // PG2 ** D36       **2
  NOT_ON_TIMER, // PA7 ** D37       **3
  NOT_ON_TIMER, // PA6 ** D38       **4
  NOT_ON_TIMER, // PA5 ** D39       **5
  NOT_ON_TIMER, // PA4 ** D40       **6
  NOT_ON_TIMER, // PA3 ** D41       **7
  NOT_ON_TIMER, // PA2 ** D42       **8
  NOT_ON_TIMER, // PA1 ** D43       **9
  NOT_ON_TIMER, // PA0 ** D44       **10
  NOT_ON_TIMER, // PE6 ** D6      **11
  NOT_ON_TIMER, // PD4 ** D22     **12
  NOT_ON_TIMER, // PD5 ** D23     **13
  NOT_ON_TIMER, // PD6 ** D24     **14
  NOT_ON_TIMER, // PD7 ** D25     **15
  NOT_ON_TIMER, // PE0 ** D0 ** RX0       **16
  NOT_ON_TIMER, // PE1 ** D1 ** TX0       **17
  NOT_ON_TIMER, // PD0 ** D18 ** SCL      **18
  NOT_ON_TIMER, // PD1 ** D19 ** SDA      **19
  NOT_ON_TIMER, // PE2 ** D2      **20
  TIMER3A,      // PE3 ** D3 ** PWM       **21
  TIMER3B,      // PE4 ** D4 ** PWM       **22
  TIMER3C,      // PE5 ** D5 ** PWM       **23
  NOT_ON_TIMER, // PD2 ** D20 ** RX1      **24
  NOT_ON_TIMER, // PD3 ** D21 ** TX1      **25
  TIMER1A,      // PB5 ** D13 ** PWM      **26
  TIMER1B,      // PB6 ** D14 ** PWM      **27
  TIMER1C,      // PB7 ** D15 ** PWM      **28
  NOT_ON_TIMER, // PF7 ** D52 ** A7     **29
  NOT_ON_TIMER, // PG0 ** D26     **30
  NOT_ON_TIMER, // PG1 ** D27     **31
  NOT_ON_TIMER, // PC0 ** D28     **32
  NOT_ON_TIMER, // PC1 ** D29     **33
  NOT_ON_TIMER, // PC2 ** D30       **34
  NOT_ON_TIMER, // PC3 ** D31       **35
  NOT_ON_TIMER, // PC4 ** D32       **36
  NOT_ON_TIMER, // PC5 ** D33       **37
  NOT_ON_TIMER, // PF7 ** D52 ** A7     **38
  NOT_ON_TIMER, // PB0 ** D8 ** SS      **39
#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
  TIMER0,       // PB4 ** D12 ** PWM
#elif defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__) || defined(__AVR_AT90CAN32__) \
|| defined(__AVR_AT90CAN64__) || defined(__AVR_AT90CAN128__)
  TIMER2A,      // PB4 ** D12 ** PWM
#endif 
  NOT_ON_TIMER, // PG3 ** D16     **41
  NOT_ON_TIMER, // PG4 ** D17       **42
  NOT_ON_TIMER, // PF0 ** D45 ** A0       **43
  NOT_ON_TIMER, // PF1 ** D46 ** A1       **44
  NOT_ON_TIMER, // PF2 ** D47 ** A2       **45
  NOT_ON_TIMER, // PF3 ** D48 ** A3       **46
  NOT_ON_TIMER, // PF4 ** D49 ** A4       **47
  NOT_ON_TIMER, // PF5 ** D50 ** A5       **48
  NOT_ON_TIMER, // PF6 ** D51 ** A6     **49
  NOT_ON_TIMER, // PB3 ** D11 ** MISO     **50
  NOT_ON_TIMER, // PB2 ** D10 ** MOSI     **51
  NOT_ON_TIMER, // PB1 ** D9 ** SCK       **52
  NOT_ON_TIMER // PF5 ** D50 ** A5        **53
/*
#if defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
  TIMER0B,      // PG5 ** D53 ** PWM
#endif*/
};

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.

#define SERIAL_PORT_MONITOR         Serial
#define SERIAL_PORT_HARDWARE        Serial
#define SERIAL_PORT_HARDWARE_OPEN   Serial1
#define SERIAL_PORT_HARDWARE1       Serial1
#define SERIAL_PORT_HARDWARE_OPEN1  Serial1

/*
inline void digitalOut1(int p, bool onooff)
{
    for (int i = 4; i <= 7; i++) {
        DDRD |= (1 << i);
    }
    for (int i = 0; i <= 1; i++) {
        DDRG |= (1 << i);
    }
    for (int i = 0; i <= 5; i++) {
        DDRC |= (1 << i);
    }

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
    PORTD |= (1 << 7);
    if (IONumber <= 1) {
        PORTG |= (1 << IONumber);
    }
    else {
        PORTC |= (1 << IONumber-2);
    }
    PORTD &= ~(1 << 7);
    if (IONumber <= 1) {
        PORTG &= ~(1 << IONumber);
    }
    else {
        PORTC &= ~(1 << IONumber-2);
    }
}

/*
inline void digitalReset()
{
    for (int i = 12; i <= 15; i++) {
        pinMode(i, 1);
    }for (int i = 30; i <= 37; i++) {
        pinMode(i, 1);
    }
    digitalWrite(12, 0);
    digitalWrite(13, 0);
    digitalWrite(14, 0);
    digitalWrite(15, 1);
    for (int i = 30; i <= 37; i++) {
        digitalWrite(i, 0);
    }
    digitalWrite(15, 0);

    digitalWrite(12, 1);
    digitalWrite(13, 0);
    digitalWrite(14, 0);
    digitalWrite(15, 1);
    for (int i = 30; i <= 37; i++) {
        digitalWrite(i, 0);
    }
    digitalWrite(15, 0);

    digitalWrite(12, 0);
    digitalWrite(13, 1);
    digitalWrite(14, 0);
    digitalWrite(15, 1);
    for (int i = 30; i <= 37; i++) {
        digitalWrite(i, 0);
    }
    digitalWrite(15, 0);

    digitalWrite(12, 1);
    digitalWrite(13, 1);
    digitalWrite(14, 0);
    digitalWrite(15, 1);
    for (int i = 30; i <= 37; i++) {
        digitalWrite(i, 0);
    }
    digitalWrite(15, 0);

    digitalWrite(12, 0);
    digitalWrite(13, 0);
    digitalWrite(14, 1);
    digitalWrite(15, 1);
    for (int i = 30; i <= 37; i++) {
        digitalWrite(i, 0);
    }
    digitalWrite(15, 0);

    digitalWrite(12, 1);
    digitalWrite(13, 0);
    digitalWrite(14, 1);
    digitalWrite(15, 1);
    for (int i = 30; i <= 37; i++) {
        digitalWrite(i, 0);
    }
    digitalWrite(15, 0);

    digitalWrite(12, 0);
    digitalWrite(13, 1);
    digitalWrite(14, 1);
    digitalWrite(15, 1);
    for (int i = 30; i <= 37; i++) {
        digitalWrite(i, 0);
    }
    digitalWrite(15, 0);

    digitalWrite(12, 1);
    digitalWrite(13, 1);
    digitalWrite(14, 1);
    digitalWrite(15, 1);
    for (int i = 30; i <= 37; i++) {
        digitalWrite(i, 0);
    }
    digitalWrite(15, 0);


}

*/
#endif