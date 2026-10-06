#ifndef __TIMER0_HPP__
#define __TIMER0_HPP__

#include<cstdint>
#include<pack.hpp>
#include<reg.hpp>
#include<type_traits>
#include<device.hpp>

static volatile uint8_t tccr0a, tccr0b, timsk0, tifr0, ocr0a, ocr0b, tcnt0;


using TCCR0A = Register<uint8_t, &tccr0a, 0b11110011, 0b11111111>;
using TCCR0B = Register<uint8_t, &tccr0b, 0b11001111, 0b00111111>;
using TIMSK0 = Register<uint8_t, &timsk0, 0b00000111, 0b11111111>;
using TIFR0  = Register<uint8_t, &tifr0, 0b00000111, 0b11111111>;
using TCNT0  = Register<uint8_t, &tcnt0, 0b11111111, 0b11111111>;
using OCR0A  = Register<uint8_t, &ocr0a, 0b11111111, 0b11111111>;
using OCR0B  = Register<uint8_t, &ocr0b, 0b11111111, 0b11111111>;

using WGM00  = RegisterBit<TCCR0A, 0, true, true>;
using WGM01  = RegisterBit<TCCR0A, 1, true, true>;
using WGM02  = RegisterBit<TCCR0B, 3, true, true>;
using COM0A0 = RegisterBit<TCCR0A, 6, true, true>;
using COM0A1 = RegisterBit<TCCR0A, 7, true, true>;
using COM0B0 = RegisterBit<TCCR0A, 4, true, true>;
using COM0B1 = RegisterBit<TCCR0A, 5, true, true>;
using FOC0A  = RegisterBit<TCCR0B, 7, true, true>;
using FOC0B  = RegisterBit<TCCR0B, 6, true, true>;
using CS00   = RegisterBit<TCCR0B, 0, true, true>;
using CS01   = RegisterBit<TCCR0B, 1, true, true>;
using CS02   = RegisterBit<TCCR0B, 2, true, true>;
using TOIE0  = RegisterBit<TIMSK0, 0, true, true>;
using OCIE0A = RegisterBit<TIMSK0, 1, true, true>;
using OCIE0B = RegisterBit<TIMSK0, 2, true, true>;

using wgm00  = ParamBit<RegisterBit<TCCR0A, 0, true, true>, 0>;
using wgm01  = ParamBit<RegisterBit<TCCR0A, 1, true, true>, 1>;
using wgm02  = ParamBit<RegisterBit<TCCR0B, 3, true, true>, 2>;
using com0a0 = ParamBit<RegisterBit<TCCR0A, 6, true, true>, 0>;
using com0a1 = ParamBit<RegisterBit<TCCR0A, 7, true, true>, 1>;
using com0b0 = ParamBit<RegisterBit<TCCR0A, 4, true, true>, 0>;
using com0b1 = ParamBit<RegisterBit<TCCR0A, 5, true, true>, 1>;
using foc0a  = ParamBit<RegisterBit<TCCR0B, 7, true, true>, 0>;
using foc0b  = ParamBit<RegisterBit<TCCR0B, 6, true, true>, 0>;
using cs00   = ParamBit<RegisterBit<TCCR0B, 0, true, true>, 0>;
using cs01   = ParamBit<RegisterBit<TCCR0B, 1, true, true>, 1>;
using cs02   = ParamBit<RegisterBit<TCCR0B, 2, true, true>, 2>;
using toie0  = ParamBit<RegisterBit<TIMSK0, 0, true, true>, 0>;
using ocie0a = ParamBit<RegisterBit<TIMSK0, 1, true, true>, 0>;
using ocie0b = ParamBit<RegisterBit<TIMSK0, 2, true, true>, 0>;

using WGM0      = type_pack<wgm02, wgm01, wgm00>;
using COMA0	    = type_pack<com0a1, com0a0>;
using COMB0	    = type_pack<com0b1, com0b0>;
using CS0	    = type_pack<cs02, cs01, cs00>;
using TOIE00	= type_pack<toie0>;
using OCIEA0    = type_pack<ocie0a>;
using OCIEB0    = type_pack<ocie0b>;

static constexpr auto TIM0_WGM_NORMAL				        = just_type<ParamValue<WGM0, 0>>{};
static constexpr auto TIM0_WGM_PWM_PH_CORR_TOP_0XFF	        = just_type<ParamValue<WGM0, 1>>{};
static constexpr auto TIM0_WGM_CTC					        = just_type<ParamValue<WGM0, 2>>{};
static constexpr auto TIM0_WGM_FAST_PWM_TOP_0XFF		    = just_type<ParamValue<WGM0, 3>>{};
static constexpr auto TIM0_WGM_PWM_PH_CORR_TOP_OCRA	        = just_type<ParamValue<WGM0, 5>>{};
static constexpr auto TIM0_WGM_FAST_PWM_TOP_OCRA		    = just_type<ParamValue<WGM0, 7>>{};
static constexpr auto TIM0_COMA_NORMAL_DISCONNECTED		    = just_type<ParamValue<COMA0, 0>>{};
static constexpr auto TIM0_COMA_TOGGLE_ON_COMPARE_MATCH	    = just_type<ParamValue<COMA0, 1>>{};
static constexpr auto TIM0_COMA_CLEAR_ON_COMPARE_MATCH	    = just_type<ParamValue<COMA0, 2>>{};
static constexpr auto TIM0_COMA_SET_ON_COMPARE_MATCH		= just_type<ParamValue<COMA0, 3>>{};
static constexpr auto TIM0_COMB_NORMAL_DISCONNECTED		    = just_type<ParamValue<COMB0, 0>>{};
static constexpr auto TIM0_COMB_TOGGLE_ON_COMPARE_MATCH	    = just_type<ParamValue<COMB0, 1>>{};
static constexpr auto TIM0_COMB_CLEAR_ON_COMPARE_MATCH	    = just_type<ParamValue<COMB0, 2>>{};
static constexpr auto TIM0_COMB_SET_ON_COMPARE_MATCH		= just_type<ParamValue<COMB0, 3>>{};
static constexpr auto TIM0_CS_NO_CLOCK		                = just_type<ParamValue<CS0, 0>>{};
static constexpr auto TIM0_CS_NO_PRESC		                = just_type<ParamValue<CS0, 1>>{};
static constexpr auto TIM0_CS_DIV_8			                = just_type<ParamValue<CS0, 2>>{};
static constexpr auto TIM0_CS_DIV_64			            = just_type<ParamValue<CS0, 3>>{};
static constexpr auto TIM0_CS_DIV_256		                = just_type<ParamValue<CS0, 4>>{};
static constexpr auto TIM0_CS_DIV_1024		                = just_type<ParamValue<CS0, 5>>{};
static constexpr auto TIM0_CS_EXT_FALLING	                = just_type<ParamValue<CS0, 6>>{};
static constexpr auto TIM0_CS_EXT_RAISING	                = just_type<ParamValue<CS0, 7>>{};
static constexpr auto TIM0_TOVIRQ_DISABLE	                = just_type<ParamValue<TOIE00, 0>>{};
static constexpr auto TIM0_TOVIRQ_ENABLE		            = just_type<ParamValue<TOIE00, 1>>{};
static constexpr auto TIM0_OCAIRQ_DISABLE	                = just_type<ParamValue<OCIEA0, 0>>{};
static constexpr auto TIM0_OCAIRQ_ENABLE		            = just_type<ParamValue<OCIEA0, 1>>{};
static constexpr auto TIM0_OCBIRQ_DISABLE	                = just_type<ParamValue<OCIEB0, 0>>{};
static constexpr auto TIM0_OCBIRQ_ENABLE		            = just_type<ParamValue<OCIEB0, 1>>{};

template<class T>
concept Timer0params = std::is_same_v<typename T::param, WGM0> ||
                    std::is_same_v<typename T::param, COMA0> ||
                    std::is_same_v<typename T::param, COMB0> ||
                    std::is_same_v<typename T::param, CS0> ||
                    std::is_same_v<typename T::param, TOIE00> ||
                    std::is_same_v<typename T::param, OCIEA0> ||
                    std::is_same_v<typename T::param, OCIEB0>;

template<class T>
concept Timer0irq = std::is_same_v<typename T::param, TOIE0> ||
                    std::is_same_v<typename T::param, OCIEA0> ||
                    std::is_same_v<typename T::param, OCIEB0>;

template<class T>
concept Timer0wgm = std::is_same_v<typename T::param, WGM0>;
template<class T>
concept Timer0coma = std::is_same_v<typename T::param, COMA0>;
template<class T>
concept Timer0comb = std::is_same_v<typename T::param, COMB0>;
template<class T>
concept Timer0cs = std::is_same_v<typename T::param, CS0>;
template<class T>
concept Timer0toie = std::is_same_v<typename T::param, TOIE00>;
template<class T>
concept Timer0ociea = std::is_same_v<typename T::param, OCIEA0>;
template<class T>
concept Timer0ocieb = std::is_same_v<typename T::param, OCIEB0>;


class Timer0 : private Device
{
    public:
        // using Device::writeRegisters;

        template<Timer0params...Ts>
        static constexpr inline void configAll(just_type<Ts>... ts){ writeRegisters(ts...); }
        template<Timer0cs...Ts>
        static constexpr inline void configClock(just_type<Ts>... ts){ writeRegisters(ts...); }
        template<Timer0coma...Ts>
        static constexpr inline void configOC0A(just_type<Ts>... ts){ writeRegisters(ts...); }
        template<Timer0comb...Ts>
        static constexpr inline void configOCB(just_type<Ts>... ts){ writeRegisters(ts...); }
        template<Timer0wgm...Ts>
        static constexpr inline void configWGM(just_type<Ts>... ts){ writeRegisters(ts...); }
        template<Timer0irq...Ts>
        static constexpr inline void configIRQ(just_type<Ts>... ts){ writeRegisters(ts...); }

        static constexpr inline void enableOverFlowInterrupt(){ writeRegisters(TIM0_TOVIRQ_ENABLE); }
        static constexpr inline void disableOverFlowInterrupt(){ writeRegisters(TIM0_TOVIRQ_DISABLE); }
        static constexpr inline void enableOutputACompareMatchInterrupt(){ writeRegisters(TIM0_OCAIRQ_ENABLE); }
        static constexpr inline void disableOutputACompareMatchInterrupt(){ writeRegisters(TIM0_OCAIRQ_DISABLE); }
        static constexpr inline void enableOutputBCompareMatchInterrupt(){ writeRegisters(TIM0_OCBIRQ_ENABLE); }
        static constexpr inline void disableOutputBCompareMatchInterrupt(){ writeRegisters(TIM0_OCBIRQ_DISABLE); }

        static constexpr inline auto readConfig(auto t){ return readRegisters(t);}
        static constexpr inline auto readConfigWGM(){ return readRegisters(WGM0{});}
        static constexpr inline auto readConfigCOMA(){ return readRegisters(COMA0{});}
        static constexpr inline auto readConfigCOMB(){ return readRegisters(COMB0{});}
        static constexpr inline auto readConfigClock(){ return readRegisters(CS0{});}
        static constexpr inline auto readConfigOverFlowInterrupt(){ return readRegisters(TOIE00{});}
        static constexpr inline auto readConfigOutputACompareMatchInterrupt(){ return readRegisters(OCIEA0{});}
        static constexpr inline auto readConfigOutputBCompareMatchInterrupt(){ return readRegisters(OCIEB0{});}

};


using tim0 = Timer0;

#endif