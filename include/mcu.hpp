#ifndef __MCU_HPP__
#define __MCU_HPP__

#include<atmega.hpp>

inline volatile uint8_t outA, outB, outC, outD;
inline volatile uint8_t inA, inB, inC, inD;
inline volatile uint8_t dirA, dirB, dirC, dirD;


using OutA = Register<uint8_t, &outA, 0xFF, 0xFF>;
using OutB = Register<uint8_t, &outB, 0xFF, 0xFF>;
using OutC = Register<uint8_t, &outC, 0xFF, 0xFF>;
using OutD = Register<uint8_t, &outD, 0xFF, 0xFF>;

using InA = Register<uint8_t, &inA, 0xFF, 0xFF>;
using InB = Register<uint8_t, &inB, 0xFF, 0xFF>;
using InC = Register<uint8_t, &inC, 0xFF, 0xFF>;
using InD = Register<uint8_t, &inD, 0xFF, 0xFF>;

using DdrA = Register<uint8_t, &dirA, 0xFF, 0xFF>;
using DdrB = Register<uint8_t, &dirB, 0xFF, 0xFF>;
using DdrC = Register<uint8_t, &dirC, 0xFF, 0xFF>;
using DdrD = Register<uint8_t, &dirD, 0xFF, 0xFF>;
//out
using OA0 = RegisterBit<OutA, 0, true, true>;
using OA1 = RegisterBit<OutA, 1, true, true>;
using OA2 = RegisterBit<OutA, 2, true, true>;
using OA3 = RegisterBit<OutA, 3, true, true>;
using OA4 = RegisterBit<OutA, 4, true, true>;
using OA5 = RegisterBit<OutA, 5, true, true>;
using OA6 = RegisterBit<OutA, 6, true, true>;
using OA7 = RegisterBit<OutA, 7, true, true>;

using OB0 = RegisterBit<OutB, 0, true, true>;
using OB1 = RegisterBit<OutB, 1, true, true>;
using OB2 = RegisterBit<OutB, 2, true, true>;
using OB3 = RegisterBit<OutB, 3, true, true>;
using OB4 = RegisterBit<OutB, 4, true, true>;
using OB5 = RegisterBit<OutB, 5, true, true>;
using OB6 = RegisterBit<OutB, 6, true, true>;
using OB7 = RegisterBit<OutB, 7, true, true>;

using OC0 = RegisterBit<OutC, 0, true, true>;
using OC1 = RegisterBit<OutC, 1, true, true>;
using OC2 = RegisterBit<OutC, 2, true, true>;
using OC3 = RegisterBit<OutC, 3, true, true>;
using OC4 = RegisterBit<OutC, 4, true, true>;
using OC5 = RegisterBit<OutC, 5, true, true>;
using OC6 = RegisterBit<OutC, 6, true, true>;
using OC7 = RegisterBit<OutC, 7, true, true>;

using OD0 = RegisterBit<OutD, 0, true, true>;
using OD1 = RegisterBit<OutD, 1, true, true>;
using OD2 = RegisterBit<OutD, 2, true, true>;
using OD3 = RegisterBit<OutD, 3, true, true>;
using OD4 = RegisterBit<OutD, 4, true, true>;
using OD5 = RegisterBit<OutD, 5, true, true>;
using OD6 = RegisterBit<OutD, 6, true, true>;
using OD7 = RegisterBit<OutD, 7, true, true>;
//in
using IA0 = RegisterBit<InA, 0, true, true>;
using IA1 = RegisterBit<InA, 1, true, true>;
using IA2 = RegisterBit<InA, 2, true, true>;
using IA3 = RegisterBit<InA, 3, true, true>;
using IA4 = RegisterBit<InA, 4, true, true>;
using IA5 = RegisterBit<InA, 5, true, true>;
using IA6 = RegisterBit<InA, 6, true, true>;
using IA7 = RegisterBit<InA, 7, true, true>;

using IB0 = RegisterBit<InB, 0, true, true>;
using IB1 = RegisterBit<InB, 1, true, true>;
using IB2 = RegisterBit<InB, 2, true, true>;
using IB3 = RegisterBit<InB, 3, true, true>;
using IB4 = RegisterBit<InB, 4, true, true>;
using IB5 = RegisterBit<InB, 5, true, true>;
using IB6 = RegisterBit<InB, 6, true, true>;
using IB7 = RegisterBit<InB, 7, true, true>;

using IC0 = RegisterBit<InC, 0, true, true>;
using IC1 = RegisterBit<InC, 1, true, true>;
using IC2 = RegisterBit<InC, 2, true, true>;
using IC3 = RegisterBit<InC, 3, true, true>;
using IC4 = RegisterBit<InC, 4, true, true>;
using IC5 = RegisterBit<InC, 5, true, true>;
using IC6 = RegisterBit<InC, 6, true, true>;
using IC7 = RegisterBit<InC, 7, true, true>;

using ID0 = RegisterBit<InD, 0, true, true>;
using ID1 = RegisterBit<InD, 1, true, true>;
using ID2 = RegisterBit<InD, 2, true, true>;
using ID3 = RegisterBit<InD, 3, true, true>;
using ID4 = RegisterBit<InD, 4, true, true>;
using ID5 = RegisterBit<InD, 5, true, true>;
using ID6 = RegisterBit<InD, 6, true, true>;
using ID7 = RegisterBit<InD, 7, true, true>;
//ddr
using DA0 = RegisterBit<DdrA, 0, true, true>;
using DA1 = RegisterBit<DdrA, 1, true, true>;
using DA2 = RegisterBit<DdrA, 2, true, true>;
using DA3 = RegisterBit<DdrA, 3, true, true>;
using DA4 = RegisterBit<DdrA, 4, true, true>;
using DA5 = RegisterBit<DdrA, 5, true, true>;
using DA6 = RegisterBit<DdrA, 6, true, true>;
using DA7 = RegisterBit<DdrA, 7, true, true>;

using DB0 = RegisterBit<DdrB, 0, true, true>;
using DB1 = RegisterBit<DdrB, 1, true, true>;
using DB2 = RegisterBit<DdrB, 2, true, true>;
using DB3 = RegisterBit<DdrB, 3, true, true>;
using DB4 = RegisterBit<DdrB, 4, true, true>;
using DB5 = RegisterBit<DdrB, 5, true, true>;
using DB6 = RegisterBit<DdrB, 6, true, true>;
using DB7 = RegisterBit<DdrB, 7, true, true>;

using DC0 = RegisterBit<DdrC, 0, true, true>;
using DC1 = RegisterBit<DdrC, 1, true, true>;
using DC2 = RegisterBit<DdrC, 2, true, true>;
using DC3 = RegisterBit<DdrC, 3, true, true>;
using DC4 = RegisterBit<DdrC, 4, true, true>;
using DC5 = RegisterBit<DdrC, 5, true, true>;
using DC6 = RegisterBit<DdrC, 6, true, true>;
using DC7 = RegisterBit<DdrC, 7, true, true>;

using DD0 = RegisterBit<DdrD, 0, true, true>;
using DD1 = RegisterBit<DdrD, 1, true, true>;
using DD2 = RegisterBit<DdrD, 2, true, true>;
using DD3 = RegisterBit<DdrD, 3, true, true>;
using DD4 = RegisterBit<DdrD, 4, true, true>;
using DD5 = RegisterBit<DdrD, 5, true, true>;
using DD6 = RegisterBit<DdrD, 6, true, true>;
using DD7 = RegisterBit<DdrD, 7, true, true>;

using PA0 = IOPin<OA0, DA0, IA0>;
using PA1 = IOPin<OA1, DA1, IA1>;
using PA2 = IOPin<OA2, DA2, IA2>;
using PA3 = IOPin<OA3, DA3, IA3>;
using PA4 = IOPin<OA4, DA4, IA4>;
using PA5 = IOPin<OA5, DA5, IA5>;
using PA6 = IOPin<OA6, DA6, IA6>;
using PA7 = IOPin<OA7, DA7, IA7>;

using PB0 = IOPin<OB0, DB0, IB0>;
using PB1 = IOPin<OB1, DB1, IB1>;
using PB2 = IOPin<OB2, DB2, IB2>;
using PB3 = IOPin<OB3, DB3, IB3>;
using PB4 = IOPin<OB4, DB4, IB4>;
using PB5 = IOPin<OB5, DB5, IB5>;
using PB6 = IOPin<OB6, DB6, IB6>;
using PB7 = IOPin<OB7, DB7, IB7>;

using PC0 = IOPin<OC0, DC0, IC0>;
using PC1 = IOPin<OC1, DC1, IC1>;
using PC2 = IOPin<OC2, DC2, IC2>;
using PC3 = IOPin<OC3, DC3, IC3>;
using PC4 = IOPin<OC4, DC4, IC4>;
using PC5 = IOPin<OC5, DC5, IC5>;
using PC6 = IOPin<OC6, DC6, IC6>;
using PC7 = IOPin<OC7, DC7, IC7>;

using PD0 = IOPin<OD0, DD0, ID0>;
using PD1 = IOPin<OD1, DD1, ID1>;
using PD2 = IOPin<OD2, DD2, ID2>;
using PD3 = IOPin<OD3, DD3, ID3>;
using PD4 = IOPin<OD4, DD4, ID4>;
using PD5 = IOPin<OD5, DD5, ID5>;
using PD6 = IOPin<OD6, DD6, ID6>;
using PD7 = IOPin<OD7, DD7, ID7>;



#endif 