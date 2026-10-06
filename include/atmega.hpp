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

    private:
        using out_reg = typename out::reg;
        using in_reg  = typename in::reg;
    
    public:
        static inline void asOut() noexcept 
            requires (ddr::wr && ddr::rd)
        {
            ddr::set();
        }

        static inline void asIn() noexcept 
            requires (ddr::wr && ddr::rd)
        {
            ddr::clr();
        }

        static inline void high() noexcept 
            requires (out::wr && out::rd)
        {
            out::set();
        }

        static inline void low() noexcept 
            requires (out::wr && out::rd)
        {
            out::clr();
        }

        static inline void toggle() noexcept 
            requires (out::wr && out::rd)
        {
            using reg_t = typename out_reg::type;
            out_reg::write(
                out_reg::read() ^ (reg_t{1} << out::bit)
            );
        }

        static inline bool read() noexcept 
            requires (in::rd)
        {
            return ((in_reg::read() >> in::bit) & 1u) != 0;
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