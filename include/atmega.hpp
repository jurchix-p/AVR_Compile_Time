#ifndef __ATMEGA_HPP__
#define __ATMEGA_HPP__

#include <reg.hpp>

class IOPinBase{ protected: ~IOPinBase() = default; };

template<class Tout, class Tddr, class Tin>
class IOPin final : public IOPinBase{
    public:
        IOPin() = delete;
        ~IOPin() = delete;
        using out = Tout;
        using ddr = Tddr;
        using in = Tin;
    
        static inline void asOut() noexcept 
        {
        ddr::reg() |= (typename ddr::reg::type{1} << ddr::bit);
        }

        static inline void asIn() noexcept 
        {
            ddr::reg() &= ~(typename ddr::reg::type{1} << ddr::bit);
        }

        static inline void high() noexcept 
        {
            out::reg() |= (typename out::reg::type{1} << out::bit);
        }

        static inline void low() noexcept 
        {
            out::reg() &= ~(typename out::reg::type{1} << out::bit);
        }

        static inline void toggle() noexcept 
        {
            out::reg() ^= (typename out::reg::type{1} << out::bit);
        }

        static inline bool read() noexcept 
        {
            return (in::reg() >> in::bit) & 1;
        }
};

class IOPortBase{ protected: ~IOPortBase() = default; };

template<class T>
concept TIOPIN =
    std::is_base_of_v<IOPinBase, T> &&
    requires {
        typename T::out;
        typename T::ddr;
        typename T::in;
    };


template<TIOPIN ...Ts>
class IO final : public IOPortBase{
    public:
        IO() = delete;
        ~IO() = delete;
        using out = Port<typename Ts::out ...>;
        using ddr = Port<typename Ts::ddr ...>;
        using in = Port<typename Ts::in ...>;
    
        static inline auto read() noexcept 
        {
            return in::readPort();
        }
        static inline void write(const auto& value) noexcept 
        {
            out::writePort(value);
        }
        static inline auto getOut() noexcept 
        {
            return out::readPort();
        }
        static inline auto getDdr() noexcept 
        {
            return ddr::readPort();
        }
        static inline void asOut() noexcept 
        {
            ddr::setPort();
        }
        static inline void asIn() noexcept 
        {
            out::clrPort(); ddr::clrPort();
        }
        static inline void asInPullUp() noexcept 
        {
            out::setPort(); ddr::clrPort();
        }
};

#endif