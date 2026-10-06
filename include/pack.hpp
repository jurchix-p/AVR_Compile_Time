#ifndef _PACK_HPP_
#define _PACK_HPP_
#include <cstdint>
#include<type_traits>

template<class...Ts> struct type_pack{
    static constexpr size_t size = sizeof...(Ts);
};
using empty_pack = type_pack<>;
template<typename ... Ts>
constexpr size_t size_of_pack (type_pack<Ts ...>){ return sizeof...(Ts); }


template<class T> struct just_type{using type = T;};

template<class T, class U> constexpr bool is_same_v(just_type<T>, just_type<U>){return false;}
template<class T> constexpr bool is_same_v(just_type<T>, just_type<T>){return true;}

template<class ... Ts, class ... Us>
constexpr type_pack<Ts..., Us...> operator+ (type_pack<Ts...>, type_pack<Us...>){return {};}
template<class T, class ... Us>
constexpr type_pack<T, Us...> operator+ (just_type<T>, type_pack<Us...>){return {};}
template<class T, class ... Us>
constexpr type_pack<Us..., T> operator+ (type_pack<Us...>, just_type<T>){return {};}
template<class T, class U>
constexpr type_pack<T, U> operator+ (just_type<T>, just_type<U>){return {};}

template<class T, class U> constexpr auto operator== (just_type<T>, just_type<U>){return false;}
template<class T> constexpr auto operator== (just_type<T>, just_type<T>){return true;}

template<class T, class U> constexpr auto operator!= (just_type<T>, just_type<U>){return true;}
template<class T> constexpr auto operator!= (just_type<T>, just_type<T>){return false;}

template<class ... T, class ... U> constexpr auto operator== (type_pack<T...>, type_pack<U...>){return false;}
template<class ... T> constexpr auto operator== (type_pack<T...>, type_pack<T...>){return true;}

template<class ... T, class ... U> constexpr auto operator!= (type_pack<T...>, type_pack<U...>){return true;}
template<class ... T> constexpr auto operator!= (type_pack<T...>, type_pack<T...>){return false;}

template<class T, class ... Ts> constexpr type_pack<T> head(type_pack<T, Ts...>){return {};}
template<class T, class ... Ts> constexpr type_pack<Ts...> tail(type_pack<T, Ts...>){return {};}

template <class... Ts>
constexpr auto dataType(type_pack<Ts...> tp)
{
	if constexpr (tp.size <= 8)
	    return just_type<uint8_t>{};
	else if constexpr (tp.size <= 16)
	    return just_type<uint16_t>{};
	else if constexpr (tp.size <= 32)
	    return just_type<uint32_t>{};
	else
	    return just_type<uint64_t>{};
}
 
inline constexpr auto hasElemDuplicate = [](this auto&& self, auto p) ->bool {
    if constexpr(p.size)
        return ([]<class T, class...Ts>(type_pack<T, Ts...>){return (std::is_same_v<T, Ts> || ...);}(p) || self(tail(p)));
    else
        return false;
};

inline constexpr auto removeElemDuplicate = [](this auto&& self, auto p) {
    if constexpr(p.size){
        if constexpr(!([]<class T, class...Ts>(type_pack<T, Ts...>){return (std::is_same_v<T, Ts> || ...);}(p)))
            return (head(p) + self(tail(p)));
        else
            return self(tail(p));
    }
    else 
        return type_pack<>{}; 
};


constexpr auto x1= removeElemDuplicate(type_pack<uint16_t, uint32_t, uint16_t>{});

#endif //_PACK_HPP_