#ifndef _PAIR_
#define _PAIR_

#include <utility>
#include <tuple>

template <typename T1,typename T2>
class Pair
{
    public:
        Pair();
        Pair(T1&&,T2&&);
        template <typename U1, typename U2>
        Pair(U1&&,U2&&);
        template <typename U1, typename U2>
        Pair(const Pair<U1,U2>&);
        template <typename U1, typename U2>
        Pair(Pair<U1,U2>&&);
        Pair(const std::tuple<T1,T2>&);
        Pair(std::tuple<T1,T2>&&);
        template <typename U1,typename U2>
        Pair(const std::tuple<U1,U2>&);
        template <typename U1,typename U2>
        Pair(std::tuple<U1,U2>&&);
        template <typename... Args1,typename... Args2>
        Pair(std::piecewise_construct_t,std::tuple<Args1...>,std::tuple<Args2...>);
        Pair(const Pair<T1,T2>&) = default;
        Pair(Pair<T1,T2>&&) = default;
        ~Pair() = default;
    public:
        Pair<T1,T2>& operator=(const Pair<T1,T2>&) = default;
        Pair<T1,T2>& operator=(Pair<T1,T2>&&) = default;
        template <typename U1, typename U2>
        Pair<T1,T2>& operator=(const Pair<U1,U2>&);
        template <typename U1, typename U2>
        Pair<T1,T2>& operator=(Pair<U1,U2>&&);
        Pair<T1,T2>& operator=(const std::tuple<T1,T2>&);
        Pair<T1,T2>& operator=(std::tuple<T1,T2>&&);
        template <typename U1,typename U2>
        Pair<T1,T2>& operator=(const std::tuple<U1,U2>&);
        template <typename U1,typename U2>
        Pair<T1,T2>& operator=(std::tuple<U1,U2>&&);
    public:
        void swap(Pair<T1,T2>&);
    public:
        T1 first;
        T2 second;
    private:
/*        template <typename... Args1,typename... Args2,size_t... I1,size_t... I2>
        Pair(std::piecewise_construct_t,std::tuple<Args1...>,std::tuple<Args...>) : first{std::get<I1>,...},
                                                                                    second{std::get<I2>,...}
        {} */
};

template <typename T1,typename T2>
bool operator==(const Pair<T1,T2>&, const Pair<T1,T2>&);

template <typename T1,typename T2>
bool operator!=(const Pair<T1,T2>&, const Pair<T1,T2>&);

template <typename T1,typename T2>
bool operator<(const Pair<T1,T2>&, const Pair<T1,T2>&);

template <typename T1,typename T2>
bool operator>(const Pair<T1,T2>&, const Pair<T1,T2>&);

template <typename T1,typename T2>
bool operator>=(const Pair<T1,T2>&, const Pair<T1,T2>&);

template <typename T1,typename T2>
bool operator<=(const Pair<T1,T2>&, const Pair<T1,T2>&);

template <typename T1,typename T2>
Pair<typename std::decay<T1>::type, 
    typename std::decay<T2>::type> make_Pair(T1&&, T2&&);

#include "Pair.hpp"

#endif /* _PAIR_*/
