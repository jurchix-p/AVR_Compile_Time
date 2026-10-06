#ifndef __REG_HPP__
#define __REG_HPP__

#include<cstdint>
#include<type_traits>
#include<pack.hpp>
#include<utility>

template<class TData, TData TMask>
struct Mask
{
    static constexpr TData mask = TMask;
};


struct BaseRegister { protected: ~BaseRegister() = default; };

template<class T>
concept RegisterDataType =
    std::is_same_v<T, uint8_t>  ||
    std::is_same_v<T, uint16_t> ||
    std::is_same_v<T, uint32_t> ||
    std::is_same_v<T, uint64_t>;

template<RegisterDataType T, volatile T* TAddr, T WriteMask, T ReadMask>
class Register : public BaseRegister{
    public:
        Register() = delete;
        ~ Register() = delete;
        static constexpr T fullWriteMask = WriteMask;
        static constexpr T fullReadMask = ReadMask;
        static constexpr inline auto& reg() noexcept {return *TAddr;}
        static constexpr inline void write(const T& val) noexcept {reg() = val;}
        static constexpr inline T read() noexcept {return reg();}
        using type = T;
};

template<class T>
concept Reg = std::is_base_of_v<BaseRegister, T>;

template<Reg TReg, uint8_t TBit, bool Twr, bool Trd>
class RegisterBit{
     static_assert(
        TBit < (sizeof(typename TReg::type) * 8),
        "RegisterBit index exceeds register width"
    );
    public:
        RegisterBit() = delete;
        ~RegisterBit() = delete;
        using reg = TReg;
        using reg_t = reg::type;
        static constexpr auto bit = TBit;
        static constexpr bool wr = Twr;
        static constexpr bool rd = Trd;

        static inline void set() noexcept requires (Twr && Trd)
        { 
            reg::write(reg::read() | (reg_t{1} << bit));
        }
        static inline void clr() noexcept requires (Twr && Trd)
        { 
            reg::write(reg::read() & (~(reg_t{1} << bit)));
        }
};

template<class T>
concept RegisterLine =
    requires {
        typename T::reg;
        { T::bit } -> std::convertible_to<uint8_t>;
    };

template<RegisterLine...TPortRegLine>
class Port{
    private:
        Port() = delete;
        ~Port() = delete;

        template<class TRegLine, uint8_t TPortLine>
        struct PortLine{
            using reg = TRegLine::reg;
            static constexpr auto regLine = TRegLine::bit;
            static constexpr auto portLine = TPortLine;
            static constexpr int8_t offset = portLine - regLine;
        };

        template<class TRegType, TRegType TRegMask, int8_t TOffset>
        struct Mapping{
            static constexpr auto regMask = TRegMask;
            static constexpr auto offset = TOffset;
            using type = TRegType;   
        };

        ////
        template<class TReg, uint8_t TBit>
        struct PhysicalLine {};

        static_assert(
            !hasElemDuplicate(
                type_pack<
                    PhysicalLine<
                        typename TPortRegLine::reg,
                        TPortRegLine::bit
                    >...
                >{}
            ),
            "Duplicate physical register bit in Port"
        );

        static_assert(
            sizeof...(TPortRegLine) > 0,
            "Port must contain at least one bit"
        );

        static_assert(
            sizeof...(TPortRegLine) <= 64,
            "Port cannot contain more than 64 bits"
        );

        static constexpr auto usedLines = type_pack<TPortRegLine...>{};

        static constexpr auto usedRegs = removeElemDuplicate([]<class...Ts>(type_pack<Ts...>)
        {
            return (type_pack<typename Ts::reg>{} + ...);
        }(usedLines));
       
        static constexpr auto portSize = usedLines.size;

        using portData_t = decltype(dataType(usedLines))::type;

        static constexpr auto portLines = [](auto t)
        {
            return [&]<class...Ts, size_t ... Is>(type_pack<Ts...>, std::index_sequence<Is...>)
            {
                return (type_pack<PortLine<Ts, t.size - Is - 1>...>{});
            }(t, std::make_index_sequence<t.size>{});
        }(usedLines);

        static constexpr auto linesOfRegister = [](auto reg)
        {return []<class...Ts>(type_pack<Ts...>){
            return ([]()
            {
                if constexpr(std::is_same_v<typename decltype(reg)::type, typename Ts::reg>) 
                    return type_pack<Ts>{};
                else 
                    return type_pack<>{};}() + ...);}(portLines);
        };

        template<class T1, class T2>
        static constexpr bool sameMapping = (T1::offset == T2::offset);
       
        static constexpr auto groupByOffsetAndDirection = [](auto reg)
        {
            constexpr auto regLinesPack = linesOfRegister(reg);
            return [](this auto&& self, auto sourcePack)
            {
                if constexpr(sourcePack.size == 0)
                    return empty_pack{};
                else if constexpr(sourcePack.size == 1)
                {
                    return []<class T>(type_pack<T>)
                    {
                        using reg_t = typename T::reg::type;
                        return type_pack<Mapping<reg_t, ((reg_t){1} << T::regLine), (T::offset)>>{};
                    }(sourcePack);
                }
                else
                {
                    constexpr auto first = []<class T, class...Ts>(type_pack<T, Ts...>){return just_type<T>{};}(sourcePack);
                    constexpr auto groupOffset = decltype(first)::type::offset;
                    using reg_t = decltype(first)::type::reg::type;
                
                    constexpr auto groupMask = []<class T, class...Ts>(type_pack<T, Ts...>)
                    {
                        return ((reg_t{1} << T::regLine) | (((sameMapping<T, Ts>)?(reg_t{1} << Ts::regLine):(0)) | ...));
                    }(sourcePack);
                
                    constexpr auto tempPack = []<class T, class...Ts>(type_pack<T, Ts...>)
                    {
                        return ([]()
                        {
                            if constexpr (!(sameMapping<T, Ts>)) return (type_pack<Ts>{}); else return (empty_pack{});
                        }() + ...);
                    }(sourcePack);
                
                    constexpr auto resultPack = type_pack<Mapping<reg_t, groupMask, groupOffset>>{};
                
                    return resultPack  + self(tempPack);
                }
            
            }(regLinesPack);
        };

        static constexpr auto dataToRegister =
            []<class... TReg, auto... U1, auto... U2>(
                type_pack<Mapping<TReg, U1, U2>...> ts,
                const auto& value)
        {
            if constexpr (ts.size)
            {
                using work_t = std::common_type_t<portData_t, TReg...>;
                const work_t v = static_cast<work_t>(value);
            
                return ([&]()
                {
                    constexpr work_t mask = static_cast<work_t>(U1);
                
                    if constexpr (U2 > 0)
                        return (v & (mask << U2)) >> U2;
                    else if constexpr (U2 < 0)
                        return (v & (mask >> (-U2))) << (-U2);
                    else
                        return v & mask;
                }() | ...);
            }
            else
            {
                return 0;
            }
        };

        static constexpr auto dataFromRegister =
            []<class... TReg, auto... U1, auto... U2>(
                type_pack<Mapping<TReg, U1, U2>...> ts,
                const auto& value) -> portData_t
        {
            if constexpr (ts.size)
            {
                using work_t = std::common_type_t<portData_t, TReg...>;
                const work_t v = static_cast<work_t>(value);
            
                return static_cast<portData_t>(
                    ([&]()
                    {
                        constexpr work_t mask = static_cast<work_t>(U1);
                    
                        if constexpr (U2 > 0)
                            return (v & mask) << U2;
                        else if constexpr (U2 < 0)
                            return (v & mask) >> (-U2);
                        else
                            return v & mask;
                    }() | ...)
                );
            }
            else
            {
                return 0;
            }
        };

        template<class...T, auto...U1, auto...U2>
        static constexpr auto combinedRegMask(type_pack<Mapping<T, U1, U2>...> ts) 
        {
            if constexpr (ts.size)
                return (static_cast<T>(U1) | ...);
            else
                return 0;
        }

        template<class T>
        static constexpr T fullRegMask() 
        {
            return static_cast<T>(~T{0});
        }

        template<class TReg>
        static constexpr inline void writeOrUpdateRegister(just_type<TReg>, const auto& portValue) 
        {
            using reg_t = typename TReg::type;

            constexpr auto mappingPack = groupByOffsetAndDirection(just_type<TReg>{});

            constexpr auto regMask = combinedRegMask(mappingPack);
            constexpr bool fullWrite = (regMask == TReg::fullWriteMask);

            const reg_t newBits =  static_cast<reg_t>(dataToRegister(mappingPack, portValue));

            if constexpr (fullWrite) {
                TReg::write(newBits);
            } 
            else
            {
                constexpr bool readable = []<class... Lines>(
                    type_pack<Lines...>)
                {
                    return (
                        (!std::is_same_v<typename Lines::reg, TReg>
                            || Lines::rd)
                        && ...
                    );
                }(usedLines);
            
                static_assert(
                    readable,
                    "Partial register write requires readable port bits"
                );
            
                const reg_t old = TReg::read();
                TReg::write((old & ~regMask) | newBits);
            }
        }

        template<class TReg>
        static constexpr inline portData_t readRegister(just_type<TReg>)
        {
            return dataFromRegister(groupByOffsetAndDirection(just_type<TReg>{}), TReg::read());
        }
        

    public:
        static constexpr inline void writePort(const auto& value) noexcept
            requires ((TPortRegLine::wr && ...))
        {
            [&]<class...TReg>(type_pack<TReg...>)
            {
                (writeOrUpdateRegister(just_type<TReg>{}, value), ...);
            }(usedRegs);
        }

        static constexpr inline portData_t readPort() noexcept
            requires ((TPortRegLine::rd && ...))
        {
            return []<class...TReg>(type_pack<TReg...>)
            {
                return (readRegister(just_type<TReg>{}) | ...);
            }(usedRegs);
        } 

        static constexpr inline void setPort() noexcept
            requires ((TPortRegLine::wr && ...))
        {
            writePort(~portData_t{0});
        }

        static constexpr inline void clrPort() noexcept
            requires ((TPortRegLine::wr && ...))
        {
            writePort(0);
        }
};

template<class... Ts>
class Dev
{
    using port = Port<Ts...>;

public:
    static inline void write(const auto& v) {
        port::writePort(v);
    }

    static inline auto read() {
        return port::readPort();
    }
};










#endif