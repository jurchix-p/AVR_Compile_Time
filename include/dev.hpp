#ifndef __DEV_HPP__
#define __DEV_HPP__

#include<pack.hpp>
#include<type_traits>
#include<cstdint>
#include<utility>





template<class T, volatile T* Taddr>
struct HWReg
{
    using reg_t = T;
    static constexpr inline auto& reg(){return *(reinterpret_cast<volatile *reg_t>(*TAddr));}
};

template<class TReg, uint8_t TBit, bool TW, bool TR>
struct Bit
{
    using reg = TReg;
    static constexpr auto bit = TBit;
    static constexpr auto wr = TW;
    static constexpr auto rd = TR;
};

template<class R, class...THWBit>
struct Reg : public R
{
    using reg = R;
    using reg_t = R::reg_t;
    static_assert(((std::is_same_v<reg_t, typename THWBit::reg::type>) || ...), "Illegal Bit");
    static constexpr auto size = type_pack<THWBit...>{}.size;
    static constexpr reg_t fullWriteMask = (((reg_t{1} & THWBit::wr) << THWBit::bit) | ...);
    static constexpr reg_t fullReadMask = (((reg_t{1} & THWBit::rd) << THWBit::bit) | ...);

    static constexpr inline void write(const reg_t& mask, const reg_t& val)
    {
        (mask == fullWriteMask)?
            (reg() = val):
            (reg() = ((reg() & (~mask))) | value);
    }
    static constexpr inline reg_t read(){return (reg() & fullReadMask);}
};


static volatile uint8_t reg1;
using hwregA = HWReg<uint8_t, &reg1>;


using A0 = Bit<hwregA, 0, true, true>;
using A1 = Bit<hwregA, 1, true, true>;
using A2 = Bit<hwregA, 2, true, true>;
using A3 = Bit<hwregA, 3, true, true>;
using A4 = Bit<hwregA, 4, true, true>;
using A5 = Bit<hwregA, 5, true, true>;
using A6 = Bit<hwregA, 6, true, true>;
using A7 = Bit<hwregA, 7, true, true>;

using A = Reg<hwregA, A7, A6, A5, A4, A3, A2, A1, A0>;



using t = A::reg_t;
static constexpr auto mw = A::fullWriteMask;
static constexpr auto mr = A::fullReadMask;
static constexpr auto s = A::size;
 








////////////////////////////////////
// template<class T>
// class A{
//     public:
//         using type = T;
// };

// using a1 = A<uint8_t>;
// using a2 = A<uint16_t>;


// template<class R, class T>
// class B: public R
// {
//     public:
//         using otherType = T;
// };

// using b1 = B<a1, uint64_t>;
// using b2 = B<a2, uint32_t>;



// using z11 = b1::type;
// using z12 = b1::otherType;
// using z21 = b2::type;
// using z22 = b2::otherType;
//////////////////////////////////////

volatile uint8_t tccr0a, tccr0b, timsk0, tifr0;

using TCCR0A = HWReg<uint8_t, &tccr0a>;
using TCCR0B = HWReg<uint8_t, &tccr0b>;
using TIMSK0 = HWReg<uint8_t, &timsk0>;
using TIFR0 = HWReg<uint8_t, &tifr0>;


using WGM00 = Bit<TCCR0A, 0, true, true>;
using WGM01 = Bit<TCCR0A, 1, true, true>;
using COM0B0 = Bit<TCCR0A, 4, true, true>;
using COM0B1 = Bit<TCCR0A, 5, true, true>;
using COM0A0 = Bit<TCCR0A, 6, true, true>;
using COM0A1 = Bit<TCCR0A, 7, true, true>;

using CS00 = Bit<TCCR0B, 0, true, true>;
using CS01 = Bit<TCCR0B, 1, true, true>;
using CS02 = Bit<TCCR0B, 2, true, true>;
using WGM02 = Bit<TCCR0B, 3, true, true>;
using FOC0B = Bit<TCCR0B, 6, false, true>;
using FOC0A = Bit<TCCR0B, 7, false, true>;

using TOIE0 = Bit<TIMSK0, 0, true, true>;
using OCIE0A = Bit<TIMSK0, 1, true, true>;
using OCIE0B = Bit<TIMSK0, 2, true, true>;

using TOV0 = Bit<TIFR0, 0, true, true>;
using OCF0A = Bit<TIFR0, 1, true, true>;
using OCF0B = Bit<TIFR0, 2, true, true>;




template<class TReg, auto TMask>
class ParamToReg
{
    using reg = Treg;
    using reg_t = reg::type;
    static constexpr reg_t regMask = TMask;
    // static constexpr reg_t offset = 
};

template<class TRegLine, uint8_t TPortLine>
struct ParamLine{
    using reg = TRegLine::reg;
    static constexpr auto regLine = TRegLine::bit;
    static constexpr auto portLine = TPortLine;
    static constexpr int8_t offset = portLine - regLine;
};

template<class...Ps>
class Param
{
    public:
        static constexpr auto usedRegs = removeElemDuplicate(type_pack<Ps::reg...>{});
        static constexpr auto paramLines = [](auto t)
        {
            return [&]<class...Ts, size_t ... Is>(type_pack<Ts...>, std::index_sequence<Is...>)
            {
                return (type_pack<ParamLine<Ts, t.size - Is - 1>...>{});
            }(t, std::make_index_sequence<t.size>{});
        }(type_pack<Ps...>{});
        
        static constexpr auto temp = []<class TReg>(just_type<TReg>)
        {
            constexpr auto regMask = []<class...Ts>(type_pack<Ts...>)
            {
                return (((std::is_same_v<TReg, Ts::reg>)?(1 << Ts::regline):(0)) | ...);
            }(paramLines);
            constexpr auto valueMask = []<class...Ts>(type_pack<Ts...>)
            {
                return (((std::is_same_v<TReg, Ts::reg>)?(1 << Ts::portLine):(0)) | ...);
            }(paramLines);
        };

};

using WGM = Param<WGM02, WGM01, WGM00>;
constexpr auto ur = WGM::usedRegs;
constexpr auto pl = WGM::paramLines;

using CS = Param<CS02, CS01, CS00>;
using COMA = Param<COM0A1, COM0A0>;
using COMB = Param<COM0B1, COM0B0>;
using TOIE = Param<TOIE0>;
using OCIEA = Param<OCIE0A>;
using OCIEB = Param<OCIE0B>;

template<class TParam, class TData, TData TValue>
class ParamValue
{
    using param = TParam;
    static constexpr TData = TValue; 
};


static constexpr auto WGM_NORMAL				    = just_type<ParamValue<WGM, uint8_t, 0>>{};
static constexpr auto WGM_PWM_PH_CORR_TOP_0XFF	    = just_type<ParamValue<WGM, uint8_t, 1>>{};
static constexpr auto WGM_CTC					    = just_type<ParamValue<WGM, uint8_t, 2>>{};
static constexpr auto WGM_FAST_PWM_TOP_0XFF		    = just_type<ParamValue<WGM, uint8_t, 3>>{};
static constexpr auto WGM_PWM_PH_CORR_TOP_OCRA	    = just_type<ParamValue<WGM, uint8_t, 5>>{};
static constexpr auto WGM_FAST_PWM_TOP_OCRA		    = just_type<ParamValue<WGM, uint8_t, 7>>{};
static constexpr auto COMA_NORMAL_DISCONNECTED		= just_type<ParamValue<COMA, uint8_t, 0>>{};
static constexpr auto COMA_TOGGLE_ON_COMPARE_MATCH	= just_type<ParamValue<COMA, uint8_t, 1>>{};
static constexpr auto COMA_CLEAR_ON_COMPARE_MATCH	= just_type<ParamValue<COMA, uint8_t, 2>>{};
static constexpr auto COMA_SET_ON_COMPARE_MATCH		= just_type<ParamValue<COMA, uint8_t, 3>>{};
static constexpr auto COMB_NORMAL_DISCONNECTED		= just_type<ParamValue<COMB, uint8_t, 0>>{};
static constexpr auto COMB_TOGGLE_ON_COMPARE_MATCH	= just_type<ParamValue<COMB, uint8_t, 1>>{};
static constexpr auto COMB_CLEAR_ON_COMPARE_MATCH	= just_type<ParamValue<COMB, uint8_t, 2>>{};
static constexpr auto COMB_SET_ON_COMPARE_MATCH		= just_type<ParamValue<COMB, uint8_t, 3>>{};
static constexpr auto CS_NO_CLOCK		            = just_type<ParamValue<CS, uint8_t, 0>>{};
static constexpr auto CS_NO_PRESC		            = just_type<ParamValue<CS, uint8_t, 1>>{};
static constexpr auto CS_DIV_8			            = just_type<ParamValue<CS, uint8_t, 2>>{};
static constexpr auto CS_DIV_64			            = just_type<ParamValue<CS, uint8_t, 3>>{};
static constexpr auto CS_DIV_256		            = just_type<ParamValue<CS, uint8_t, 4>>{};
static constexpr auto CS_DIV_1024		            = just_type<ParamValue<CS, uint8_t, 5>>{};
static constexpr auto CS_EXT_FALLING	            = just_type<ParamValue<CS, uint8_t, 6>>{};
static constexpr auto CS_EXT_RAISING	            = just_type<ParamValue<CS, uint8_t, 7>>{};
static constexpr auto TOVIRQ_DISABLE	            = just_type<ParamValue<TOIE, uint8_t, 0>>{};
static constexpr auto TOVIRQ_ENABLE		            = just_type<ParamValue<TOIE, uint8_t, 1>>{};
static constexpr auto OCAIRQ_DISABLE	            = just_type<ParamValue<OCIEA, uint8_t, 0>>{};
static constexpr auto OCAIRQ_ENABLE		            = just_type<ParamValue<OCIEA, uint8_t, 1>>{};
static constexpr auto OCBIRQ_DISABLE	            = just_type<ParamValue<OCIEB, uint8_t, 0>>{};
static constexpr auto OCBIRQ_ENABLE		            = just_type<ParamValue<OCIEB, uint8_t, 1>>{};

template<class...Ts>
constexpr auto temp(just_type<Ts>...)
{
    constexpr auto pack = type_pack<Ts...>{};
    constexpr auto paramPack = type_pack<typename Ts::param...>{};


    return paramPack;
    // return pack;
}

constexpr auto zzz = temp(WGM_PWM_PH_CORR_TOP_0XFF, CS_DIV_64, COMA_TOGGLE_ON_COMPARE_MATCH, COMB_NORMAL_DISCONNECTED, TOVIRQ_ENABLE);








#endif