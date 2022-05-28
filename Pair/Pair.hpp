#ifndef _PAIR_HPP_
#define _PAIR_HPP_

template <typename T1, typename T2>
Pair<T1,T2>::Pair() : first{}, second{}
{}

template <typename T1, typename T2>
Pair<T1,T2>::Pair(T1&& val1, T2&& val2) : 
                                first{std::forward<T1>(val1)},
                                second{std::forward<T2>(val2)}
{}

template <typename T1, typename T2>
template <typename U1, typename U2>
Pair<T1,T2>::Pair(U1&& val1, U2&& val2) :
                                first{std::forward<U1>(val1)},
                                second{std::forward<U2>(val2)}
{}

template <typename T1, typename T2>
template <typename U1, typename U2>
Pair<T1,T2>::Pair(const Pair<U1,U2>& oth) :
                                first{oth.first},
                                second{oth.second}
{}

template <typename T1, typename T2>
template <typename U1, typename U2>
Pair<T1,T2>::Pair(Pair<U1,U2>&& tmp) :
                                first{std::move(tmp.first)},
                                second{std::move(tmp.second)}
{}

template <typename T1,typename T2>
Pair<T1,T2>::Pair(const std::tuple<T1,T2>& tp) : first{std::get<0>(tp)},
                                                second{std::get<1>(tp)}
{}

template <typename T1,typename T2>
Pair<T1,T2>::Pair(std::tuple<T1,T2>&& tp) : first{std::move(std::get<0>(tp))},
                                                second{std::move(std::get<1>(tp))}
{}

template <typename T1,typename T2>
template <typename U1,typename U2>
Pair<T1,T2>::Pair(const std::tuple<U1,U2>& tp) : first(std::get<0>(tp)),
                                                second(std::get<1>(tp))
{}

template <typename T1,typename T2>
template <typename U1,typename U2>
Pair<T1,T2>::Pair(std::tuple<U1,U2>&& tp) : first(std::move(std::get<0>(tp))),
                                                second(std::move(std::get<1>(tp)))
{}

template <typename T1, typename T2>
template <typename... Args1, typename... Args2>
Pair<T1,T2>::Pair(std::piecewise_construct_t, std::tuple<Args1...> tp1,
                    std::tuple<Args2...> tp2) : first{}, second{}
{}

template <typename T1, typename T2>
template <typename U1, typename U2>
Pair<T1,T2>& Pair<T1,T2>::operator=(const Pair<U1,U2>& oth)
{
    this->first = oth.first;
    this->second = oth.second;
    return *this;
}

template <typename T1, typename T2>
template <typename U1, typename U2>
Pair<T1,T2>& Pair<T1,T2>::operator=(Pair<U1,U2>&& tmp)
{
    this->first = std::move(tmp.first);
    this->second = std::move(tmp.second);
    return *this;
}

template <typename T1,typename T2>
Pair<T1,T2>& Pair<T1,T2>::operator=(const std::tuple<T1,T2>& tp)
{
    this->first = std::get<0>(tp);
    this->second = std::get<1>(tp);
    return *this;
}

template <typename T1,typename T2>
Pair<T1,T2>& Pair<T1,T2>::operator=(std::tuple<T1,T2>&& tp)
{
    this->first = std::move(std::get<0>(tp));
    this->second = std::move(std::get<1>(tp));
    return *this;
}

template <typename T1,typename T2>
template <typename U1,typename U2>
Pair<T1,T2>& Pair<T1,T2>::operator=(const std::tuple<U1,U2>& tp)
{
    this->first = std::get<0>(tp);
    this->second = std::get<1>(tp);
    return *this;
}

template <typename T1,typename T2>
template <typename U1,typename U2>
Pair<T1,T2>& Pair<T1,T2>::operator=(std::tuple<U1,U2>&& tp)
{
    this->first = std::move(std::get<0>(tp));
    this->second = std::move(std::get<1>(tp));
    return *this;
}

template <typename T1,typename T2>
void Pair<T1,T2>::swap(Pair<T1,T2>& val)
{
    Pair<T1,T2> tmp = std::move(val);
    val = std::move(*this);
    *this = std::move(tmp);
}
template <typename T1,typename T2>
bool operator==(const Pair<T1,T2>& lhs,const Pair<T1,T2>& rhs)
{
    return (lhs.first == rhs.first) && (lhs.second == rhs.second);
}

template <typename T1,typename T2>
bool operator!=(const Pair<T1,T2>& lhs,const Pair<T1,T2>& rhs)
{
    return !(lhs == rhs);
}

template <typename T1,typename T2>
bool operator<(const Pair<T1,T2>& lhs,const Pair<T1,T2>& rhs)
{
    return (lhs.first < rhs.first) && (lhs.second < rhs.second);
}

template <typename T1,typename T2>
bool operator>(const Pair<T1,T2>& lhs,const Pair<T1,T2>& rhs)
{
    return !(lhs == rhs) && !(lhs < rhs);
}

template <typename T1,typename T2>
bool operator>=(const Pair<T1,T2>& lhs,const Pair<T1,T2>& rhs)
{
    return !(lhs < rhs);
}

template <typename T1,typename T2>
bool operator<=(const Pair<T1,T2>& lhs,const Pair<T1,T2>& rhs)
{
    return (lhs == rhs) || (lhs < rhs);
}

template <typename T1,typename T2>
Pair<typename std::decay<T1>::type, typename std::decay<T2>::type> make_Pair(T1&& val1,T2&& val2)
{
    return Pair<typename std::decay<T1>::type,
                typename std::decay<T2>::type>(std::forward<T1>(val1),
                                                std::forward<T2>(val2));
}

#endif /* _PAIR_HPP_ */
