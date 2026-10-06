
#include<print>
#include<mcu.hpp>
// #include<device.hpp>
#include<timer0.hpp>
#include <cassert>


using p = Port<OA7, OA6, OA5, OA4, OD3, OD2, OD1, OD0, OC7, OC6, OC5, OC4, OB7, OB6, OB5, OB4, OA3, OA2, OA1, OA0, OD7, OD6, OD5, OD4, OC3, OC2, OC1, OC0, OB3, OB2, OB1, OB0>;


inline volatile uint16_t testReg16{};

using TestReg16 =
    Register<uint16_t, &testReg16, 0xFFFF, 0xFFFF>;

using TestBit15 =
    RegisterBit<TestReg16, 15, true, true>;

using TestPort = Port<TestBit15>;

int main(void)
{
    // uint32_t val{0}; 
    // while(val < ~uint32_t{0})
    // {
    //     p::writePort(val);
    //     std::print("write value = {}", val);
    //     std::println(" read value = {}", p::readPort());
    //     val++;
    // }

    // return 0;

    // PA0::asOut();
    // PA0::asIn();

    // inA = 1;
    // bool state = PA0::read();  // true

// Augšējam reģistra bitam jākļūst par porta bitu 0.
    testReg16 = 0x8000;
    assert(TestPort::readPort() == 1);

    // Rakstīšanai jāsaglabā pārējie reģistra biti.
    testReg16 = 0x1234;
    TestPort::writePort(1);
    assert(testReg16 == 0x9234);

    TestPort::writePort(0);
    assert(testReg16 == 0x1234);

    // Citi reģistra biti nedrīkst ietekmēt nolasījumu.
    testReg16 = 0x7FFF;
    assert(TestPort::readPort() == 0);

    std::println("16 bitu reģistra tests: OK");

}