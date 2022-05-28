#ifndef _TUPLE_
#define _TUPLE_

#include <utility>
#include <type_traits>

template <typename... Args>
class Tuple;

template <typename T,typename... Args>
class Tuple<T,Args...>
{
    public:
        Tuple() = default;
        Tuple(const Tuple&) = default;
        Tuple(Tuple&&) = default;
        ~Tuple() = default;
        Tuple(const T&,const Args&...);
        Tuple(T&&,Args&&...);
        template <typename U,typename... Args1>
        Tuple(const Tuple<U,Args1...>&);
        template <typename U,typename... Args1>
        Tuple(Tuple<U,Args1...>&&);
    public:
        Tuple& operator=(const Tuple&) = default;
        Tuple& operator=(Tuple&&) = default;
        template <typename U,typename... Args1>
        Tuple& operator=(const Tuple<U,Args1...>&);
        template <typename U,typename... Args1>
        Tuple& operator=(Tuple<U,Args1...>&&);

    public:
        T val;
        Tuple<Args...> rest;
};

template <typename T1,typename T2>
class Tuple<T1,T2>
{
    public:
        Tuple() = default;
        ~Tuple() = default;
        Tuple(const Tuple&) = default;
        Tuple(const std::pair<T1,T2>&);
        Tuple(std::pair<T1,T2>&&);
        Tuple(const T1&,const T2&);
        Tuple(T1&&,T2&&);
        template <typename U1,typename U2>
        Tuple(const Tuple<U1,U2>&);
        template <typename U1,typename U2>
        Tuple(Tuple<U1,U2>&&);
        template <typename U1,typename U2>
        Tuple(const std::pair<U1,U2>&);
        template <typename U1,typename U2>
        Tuple(std::pair<U1,U2>&&);
        template <typename U1,typename U2,typename std::enable_if<
                                                !std::is_same<
                                                    typename std::decay<U1>::type,
                                                    typename std::decay<T1>::type
                                                >::value || 
                                                !std::is_same<
                                                    typename std::decay<U2>::type,
                                                    typename std::decay<T2>::type
                                                >::value
                                            >::type
                                        >
        Tuple(U1&&,U2&&);
    public:
        Tuple& operator=(const Tuple&) = default;
        Tuple& operator=(Tuple&&) = default;
        Tuple& operator=(const std::pair<T1,T2>&);
        Tuple& operator=(std::pair<T1,T2>&&);
        template <typename U1,typename U2>
        Tuple& operator=(const Tuple<U1,U2>&);
        template <typename U1,typename U2>
        Tuple& operator=(Tuple<U1,U2>&&);
        template <typename U1,typename U2>
        Tuple& operator=(const std::pair<U1,U2>&);
        template <typename U1,typename U2>
        Tuple& operator=(std::pair<U1,U2>&&);
    public:
        T1 first;
        T2 second;
};

template <typename T>
class Tuple<T>
{
    public:
        using val_type = T;
        using ref_type = T&;
    public:
        Tuple() = default;
        Tuple(const Tuple&) = default;
        Tuple(Tuple&);
        Tuple(Tuple&&) = default;
        Tuple(const Tuple&&);
        Tuple(const T&);
        Tuple(T&);
        Tuple(T&&);
        Tuple(const T&&);
        template <typename U>
        Tuple(U&&);
        template <typename U>
        Tuple(const Tuple<U>&);
        template <typename U>
        Tuple(Tuple<U>&&);
        ~Tuple() = default; 
    public:
        Tuple& operator=(const Tuple&) = default;
        Tuple& operator=(Tuple&);
        Tuple& operator=(Tuple&&) = default;
        Tuple& operator=(const Tuple&&);
        Tuple& operator=(const T&);
        Tuple& operator=(T&);
        Tuple& operator=(T&&);
        Tuple& operator=(const T&&);
        template <typename U>
        Tuple& operator=(const Tuple<U>&);
        template <typename U>
        Tuple& operator=(Tuple<U>&);
        template <typename U>
        Tuple& operator=(Tuple<U>&&);
        template <typename U>
        Tuple& operator=(const Tuple<U>&&);
        template <typename U>
        Tuple& operator=(U&&);
        T val;
};

template <>
class Tuple<>
{
    public:
        Tuple() = default;
        Tuple(const Tuple&) = default;
        Tuple(Tuple&&) = default;
        Tuple& operator=(const Tuple&) = default;
        Tuple& operator=(Tuple&&) = default;
        ~Tuple() = default;
};

/*
template< std::size_t I, class T >
struct tuple_element;
 
// recursive case
template< std::size_t I, class Head, class... Tail >
struct tuple_element<I, std::tuple<Head, Tail...>>
    : std::tuple_element<I-1, Tuple<Tail...>> { };
 
// base case
template< class Head, class... Tail >
struct tuple_element<0, Tuple<Head, Tail...>> {
   using type = Head;
};



template <size_t index,typename... Ts>
auto my_get(Tuple<Ts...>& tup) -> typename tuple_element<index,decltype(tup)>::type& 
{
    if constexpr(index == 0)
    {
        return tup.val;
    }else{
        return my_get<index - 1>(tup.rest);
    }
}

template <size_t index,typename T>
auto my_get(Tuple<T>& tup) -> typename tuple_element<0,decltype(tup)>::type&
{
    static_assert(index == 0);
    if constexpr (index == 0)
    {
        return tup.val;
    }
}
*/

#include "Tuple.hpp"

#endif /* _TUPLE_ */
