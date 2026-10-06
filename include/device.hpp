#ifndef __DEVICE_HPP__
#define __DEVICE_HPP__

#include<cstdint>
#include<pack.hpp>
#include<reg.hpp>
#include<type_traits>

template<class TRegBit, uint8_t TParamLine>
class ParamBit
{
    public:
        using regBit = TRegBit;
        using reg = TRegBit::reg;
        using reg_t = TRegBit::reg::type;
        static constexpr reg_t mask = (reg_t{1} << TParamLine);
        static constexpr int8_t offset = TRegBit::bit - TParamLine;
};

template<class TReg, auto V>
class RegValueFromParameter
{
    public:
        using reg = TReg;
        using reg_t = TReg::type;
        static constexpr reg_t value = V;
};

template<class TParam, uint8_t V>
class ParamValue
{
    public:
        using param = TParam;
        static constexpr auto paramValue = V;
        
        
};

template<class TReg, auto V, auto M>
class paramValueToReg
{
    public:
        using reg = TReg;
        using reg_t = TReg::type;
        static constexpr reg_t value = V;
        static constexpr reg_t mask = M;
};

// 

class Device
{
    public:
        static constexpr inline auto bitsOfAllParameters(auto...t)
        {
            constexpr auto bitsOfParameter = []<class...TParambit, auto V>(just_type<ParamValue<type_pack<TParambit...>, V>>)
            {
                constexpr auto params = (type_pack<typename decltype(t)::type::param>{} + ...);
                static_assert(!hasElemDuplicate(params),
                                "Duplicate Parameters"); 
                constexpr auto val = []<class T>(just_type<T>)-> T::reg_t
                    {
                        return ((T::offset > 0)?
                                    ((T::mask & V) << T::offset):
                                    ((T::offset < 0)?
                                        ((T::mask & V) >> T::offset):
                                        (T::mask & V)));
                    };
                return (type_pack<paramValueToReg<typename TParambit::reg, val(just_type<TParambit>{}), TParambit::mask>>{} + ...);
            };
            return (bitsOfParameter(decltype(t){}) + ...);
        }

        static constexpr inline auto usedRegisters = [](auto t)
        {
            return removeElemDuplicate([]<class...Ts>(type_pack<Ts...>){return (type_pack<typename Ts::reg>{} + ...);}(t));
        };

        static constexpr inline auto maskToRegister  = []<class TReg, class...Ts>(just_type<TReg>, type_pack<Ts...>)
        {
            return (((std::is_same_v<TReg, typename Ts::reg>)?(Ts::mask):(0)) | ...);
        };

        static constexpr inline auto valueToRegister = []<class TReg, class...Ts>(just_type<TReg>, type_pack<Ts...>)
        {
            return (((std::is_same_v<TReg, typename Ts::reg>)?(Ts::value):(0)) | ...);
        };

        static constexpr inline void writeRegisters(auto...t)
        {
            constexpr auto bits = bitsOfAllParameters(t...);
            constexpr auto regs = usedRegisters(bits);
            constexpr auto writeReg = []<class R>(just_type<R> r)
                {
                    constexpr auto mask = maskToRegister(r, bits);
                    constexpr auto newValue = valueToRegister(r, bits);
                    if constexpr(mask == R::fullWriteMask)
                    {
                        R::write(newValue);
                    }
                    else 
                    {    
                        R::write((R::read() & ~mask) | newValue);
                    }
                };
            [&]<class...TReg>(type_pack<TReg...>)
            {
                (writeReg(just_type<TReg>{}), ...);
            }(regs);
        }

        template<class...Ts>
        static constexpr inline auto readRegisters(type_pack<Ts...>)
        {
            using param = Port<typename Ts::regBit...>;
            return param::readPort();
        }



};

#endif