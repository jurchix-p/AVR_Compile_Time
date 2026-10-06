#ifndef __ATMEGA_328_HPP__
#define __ATMEGA_328_HPP__


#include<reg.hpp>

static volatile uint8_t pinb /*0x23*/,
                        ddrb /*0x24*/,
                        portb /*0x25*/,
                        pinc /*0x26*/,
                        ddrc /*0x27*/,
                        portc /*0x28*/,
                        pind /*0x29*/,
                        ddrd /*0x2A*/,
                        portd /*0x2B*/,
                        tifr0 /*0x35*/,
                        tifr1 /*0x36*/,
                        tifr2 /*0x37*/,
                        pcifr /*0x3B*/,
                        eifr /*0x3C*/,
                        eimsk /*0x3D*/,
                        gpior0 /*0x3E*/,
                        eecr /*0x3F*/,
                        eedr /*0x40*/,
                        eearl /*0x41*/,
                        eearh /*0x42*/,
                        gtccr /*0x43*/,
                        tccr0a /*0x44*/,
                        tccr0b /*0x45*/,
                        tcnt0 /*0x46*/,
                        ocr0a /*0x47*/,
                        ocr0b /*0x48*/,
                        gpior1 /*0x4A*/,
                        gpior2 /*0x4B*/,
                        spcr /*0x4C*/,
                        spsr /*0x4D*/,
                        spdr /*0x4E*/,
                        acsr /*0x50*/,
                        smcr /*0x53*/,
                        mcusr /*0x54*/,
                        mcucr /*0x55*/,
                        spmcsr /*0x57*/,
                        spl /*0x5D*/,
                        sph /*0x5E*/,
                        sreg /*0x5F*/,
                        wdtcsr /*0x60*/,
                        clkpr /*0x61*/,
                        prr /*0x64*/,
                        osccal /*0x66*/,
                        pcicr /*0x68*/,
                        eicra /*0x69*/,
                        pcmsk0 /*0x6B*/,
                        pcmsk1 /*0x6C*/,
                        pcmsk2 /*0x6D*/,
                        timsk0 /*0x6E*/,
                        timsk1 /*0x6D*/,
                        timsk2 /*0x6F*/,
                        adcl /*0x78*/,
                        adch /*0x79*/,
                        adcsra /*0x7A*/,
                        adcsrb /*0x7B*/,
                        admux /*0x7C*/,
                        didr0 /*0x7E*/,
                        didr1 /*0x7F*/,
                        tccr1a /*0x80*/,
                        tccr1b /*0x81*/,
                        tccr1c /*0x82*/,
                        tcnt1l /*0x84*/,
                        tcnt1h /*0x85*/,
                        icr1l /*0x86*/,
                        icr1h /*0x87*/,
                        ocr1al /*0x88*/,
                        ocr1ah /*0x89*/,
                        ocr1bl /*0x8A*/,
                        ocr1bh /*0x8B*/,
                        tccr2a /*0xB0*/,
                        tccr2b /*0xB1*/,
                        tcnt2 /*0xB2*/,
                        ocr2a /*0xB3*/,
                        ocr2b /*0xB4*/,
                        assr /*0xB6*/,
                        twbr /*0xB8*/,
                        twsr /*0xB9*/,
                        twar /*0xBA*/,
                        twdr /*0xBB*/,
                        twcr /*0xBC*/,
                        twamr /*0xBD*/,
                        ucsr0a /*0xC0*/,
                        ucsr0b /*0xC1*/,
                        ucsr0c /*0xC2*/,
                        ubrr0l /*0xC4*/,
                        ubrr0h /*0xC5*/,
                        udr0 /*0xC6*/;


using PINB = Register<uint8_t, &pinb, 0b11111111, 0b11111111>;
using DDRB = Register<uint8_t, &ddrb, 0b11111111, 0b11111111>;
using PORTB = Register<uint8_t, &portb, 0b11111111, 0b11111111>;
using PINC = Register<uint8_t, &pinc, 0b01111111, 0b01111111>;
using DDRC = Register<uint8_t, &ddrc, 0b01111111, 0b01111111>;
using PORTC = Register<uint8_t, &portc, 0b01111111, 0b01111111>;
using PIND = Register<uint8_t, &pind, 0b11111111, 0b11111111>;
using DDRD = Register<uint8_t, &ddrd, 0b11111111, 0b11111111>;
using PORTD = Register<uint8_t, &portd, 0b11111111, 0b11111111>;
using TIFR0 = Register<uint8_t, &tifr0, 0b00000111, 0b00000111>;
using TIFR1 = Register<uint8_t, &tifr1, 0b00100111, 0b00100111>;
using TIFR2 = Register<uint8_t, &tifr2, 0b00000111, 0b00000111>;
using PCIFR = Register<uint8_t, &pcifr, 0b00000111, 0b00000111>;
using EIFR = Register<uint8_t, &eifr, 0b0000011, 0b0000011>;
using EIMSK = Register<uint8_t, &eimsk, 0b0000011, 0b0000011>;
using GPIOR0 = Register<uint8_t, &gpior0, 0b11111111, 0b11111111>;
using EECR = Register<uint8_t, &eecr, 0b00111111, 0b00111111>;
using EEDR = Register<uint8_t, &eedr, 0b11111111, 0b11111111>;
using EEARL = Register<uint8_t, &eearl, 0b11111111, 0b11111111>;
using EEARH = Register<uint8_t, &eearh, 0b11111111, 0b11111111>;
using GTCCR = Register<uint8_t, &gtccr, 0b10000011, 0b10000011>;
using TCCR0A = Register<uint8_t, &tccr0a, 0b11110011, 0b11110011>;
using TCCR0B = Register<uint8_t, &tccr0b, 0b11001111, 0b11001111>;
using TCNT0 = Register<uint8_t, &tcnt0, 0b11111111, 0b11111111>;
using OCR0A = Register<uint8_t, &ocr0a, 0b11111111, 0b11111111>;
using OCR0B = Register<uint8_t, &ocr0b, 0b11111111, 0b11111111>;
using GPIOR1 = Register<uint8_t, &gpior1, 0b11111111, 0b11111111>;
using GPIOR2 = Register<uint8_t, &gpior2, 0b11111111, 0b11111111>;
using SPCR = Register<uint8_t, &spcr, 0b11111111, 0b11111111>;
using SPSR = Register<uint8_t, &spsr, 0b11000001, 0b11000001>;
using SPDR = Register<uint8_t, &spdr, 0b11111111, 0b11111111>;
using ACSR = Register<uint8_t, &acsr, 0b11111111, 0b11111111>;
using SMCR = Register<uint8_t, &smcr, 0b00001111, 0b00001111>;
using MCUSR = Register<uint8_t, &mcusr, 0b00001111, 0b00001111>;
using MCUCR = Register<uint8_t, &mcucr, 0b01110011, 0b01111111>;
using SPMCSR = Register<uint8_t, &spmcsr, 0b11011111, 0b11011111>;
using SPL = Register<uint8_t, &spl, 0b11111111, 0b11111111>;
using SPH = Register<uint8_t, &sph, 0b00000111, 0b00000111>;
using SREG = Register<uint8_t, &sreg, 0b11111111, 0b11111111>;
using WDTCSR = Register<uint8_t, &wdtcsr, 0b11111111, 0b11111111>;
using CLKPR = Register<uint8_t, &clkpr, 0b10001111, 0b10001111>;
using PRR = Register<uint8_t, &prr, 0b11101111, 0b11101111>;
using OSCCAL = Register<uint8_t, &osccal, 0b11111111, 0b11111111>;
using PCICR = Register<uint8_t, &pcicr, 0b00000111, 0b00000111>;
using EICRA = Register<uint8_t, &eicra, 0b00001111, 0b00001111>;
using PCMSK0 = Register<uint8_t, &pcmsk0, 0b11111111, 0b11111111>;
using PCMSK1 = Register<uint8_t, &pcmsk1, 0b01111111, 0b01111111>;
using PCMSK2 = Register<uint8_t, &pcmsk2, 0b11111111, 0b11111111>;
using TIMSK0 = Register<uint8_t, &timsk0, 0b00000111, 0b00000111>;
using TIMSK1 = Register<uint8_t, &timsk1, 0b00100111, 0b00100111>;
using TIMSK2 = Register<uint8_t, &timsk2, 0b00000111, 0b00000111>;
using ADCL = Register<uint8_t, &adcl, 0b11111111, 0b11111111>;
using ADCH = Register<uint8_t, &adch, 0b11111111, 0b11111111>;
using ADCSRA = Register<uint8_t, &adcsra, 0b11111111, 0b11111111>;
using ADCSRB = Register<uint8_t, &adcsrb, 0b01000111, 0b01000111>;
using ADMUX = Register<uint8_t, &admux, 0b11101111, 0b11101111>;
using DIDR0 = Register<uint8_t, &didr0, 0b00111111, 0b00111111>;
using DIDR1 = Register<uint8_t, &didr1, 0b00000011, 0b00000011>;
using TCCR1A = Register<uint8_t, &tccr1a, 0b11110011, 0b11110011>;
using TCCR1B = Register<uint8_t, &tccr1b, 0b11011111, 0b11011111>;
using TCCR1C = Register<uint8_t, &tccr1c, 0b11000000, 0b11000000>;
using TCNT1L = Register<uint8_t, &tcnt1l, 0b11111111, 0b11111111>;
using TCNT1H = Register<uint8_t, &tcnt1h, 0b11111111, 0b11111111>;
using ICR1L = Register<uint8_t, &icr1l, 0b11111111, 0b11111111>;
using ICR1H = Register<uint8_t, &icr1h, 0b11111111, 0b11111111>;
using OCR1AL = Register<uint8_t, &ocr1al, 0b11111111, 0b11111111>;
using OCR1AH = Register<uint8_t, &ocr1ah, 0b11111111, 0b11111111>;
using OCR1BL = Register<uint8_t, &ocr1bl, 0b11111111, 0b11111111>;
using OCR1BH = Register<uint8_t, &ocr1bh, 0b11111111, 0b11111111>;

using PINB0 = RegisterBit<PINB, 0, true, true>;
using PINB1 = RegisterBit<PINB, 1, true, true>;
using PINB2 = RegisterBit<PINB, 2, true, true>;
using PINB3 = RegisterBit<PINB, 3, true, true>;
using PINB4 = RegisterBit<PINB, 4, true, true>;
using PINB5 = RegisterBit<PINB, 5, true, true>;
using PINB6 = RegisterBit<PINB, 6, true, true>;
using PINB7 = RegisterBit<PINB, 7, true, true>;
using DDRB0 = RegisterBit<DDRB, 0, true, true>;
using DDRB1 = RegisterBit<DDRB, 1, true, true>;
using DDRB2 = RegisterBit<DDRB, 2, true, true>;
using DDRB3 = RegisterBit<DDRB, 3, true, true>;
using DDRB4 = RegisterBit<DDRB, 4, true, true>;
using DDRB5 = RegisterBit<DDRB, 5, true, true>;
using DDRB6 = RegisterBit<DDRB, 6, true, true>;
using DDRB7 = RegisterBit<DDRB, 7, true, true>;
using PORTB0 = RegisterBit<PORTB, 0, true, true>;
using PORTB1 = RegisterBit<PORTB, 1, true, true>;
using PORTB2 = RegisterBit<PORTB, 2, true, true>;
using PORTB3 = RegisterBit<PORTB, 3, true, true>;
using PORTB4 = RegisterBit<PORTB, 4, true, true>;
using PORTB5 = RegisterBit<PORTB, 5, true, true>;
using PORTB6 = RegisterBit<PORTB, 6, true, true>;
using PORTB7 = RegisterBit<PORTB, 7, true, true>;

using PINC0 = RegisterBit<PINC, 0, true, true>;
using PINC1 = RegisterBit<PINC, 1, true, true>;
using PINC2 = RegisterBit<PINC, 2, true, true>;
using PINC3 = RegisterBit<PINC, 3, true, true>;
using PINC4 = RegisterBit<PINC, 4, true, true>;
using PINC5 = RegisterBit<PINC, 5, true, true>;
using PINC6 = RegisterBit<PINC, 6, true, true>;
using DDRC0 = RegisterBit<DDRC, 0, true, true>;
using DDRC1 = RegisterBit<DDRC, 1, true, true>;
using DDRC2 = RegisterBit<DDRC, 2, true, true>;
using DDRC3 = RegisterBit<DDRC, 3, true, true>;
using DDRC4 = RegisterBit<DDRC, 4, true, true>;
using DDRC5 = RegisterBit<DDRC, 5, true, true>;
using DDRC6 = RegisterBit<DDRC, 6, true, true>;
using PORTC0 = RegisterBit<PORTC, 0, true, true>;
using PORTC1 = RegisterBit<PORTC, 1, true, true>;
using PORTC2 = RegisterBit<PORTC, 2, true, true>;
using PORTC3 = RegisterBit<PORTC, 3, true, true>;
using PORTC4 = RegisterBit<PORTC, 4, true, true>;
using PORTC5 = RegisterBit<PORTC, 5, true, true>;
using PORTC6 = RegisterBit<PORTC, 6, true, true>;

using PIND0 = RegisterBit<PIND, 0, true, true>;
using PIND1 = RegisterBit<PIND, 1, true, true>;
using PIND2 = RegisterBit<PIND, 2, true, true>;
using PIND3 = RegisterBit<PIND, 3, true, true>;
using PIND4 = RegisterBit<PIND, 4, true, true>;
using PIND5 = RegisterBit<PIND, 5, true, true>;
using PIND6 = RegisterBit<PIND, 6, true, true>;
using PIND7 = RegisterBit<PIND, 7, true, true>;
using DDRD0 = RegisterBit<DDRD, 0, true, true>;
using DDRD1 = RegisterBit<DDRD, 1, true, true>;
using DDRD2 = RegisterBit<DDRD, 2, true, true>;
using DDRD3 = RegisterBit<DDRD, 3, true, true>;
using DDRD4 = RegisterBit<DDRD, 4, true, true>;
using DDRD5 = RegisterBit<DDRD, 5, true, true>;
using DDRD6 = RegisterBit<DDRD, 6, true, true>;
using DDRD7 = RegisterBit<DDRD, 7, true, true>;
using PORTD0 = RegisterBit<PORTD, 0, true, true>;
using PORTD1 = RegisterBit<PORTD, 1, true, true>;
using PORTD2 = RegisterBit<PORTD, 2, true, true>;
using PORTD3 = RegisterBit<PORTD, 3, true, true>;
using PORTD4 = RegisterBit<PORTD, 4, true, true>;
using PORTD5 = RegisterBit<PORTD, 5, true, true>;
using PORTD6 = RegisterBit<PORTD, 6, true, true>;
using PORTD7 = RegisterBit<PORTD, 7, true, true>;























#endif