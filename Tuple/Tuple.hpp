#ifndef _TUPLE_HPP_
#define _TUPLE_HPP_

/* Implemetation Tuple<T> */
template <typename T>
Tuple<T>::Tuple(Tuple<T>& tp) : val{tp.val}
{}

template <typename T>
Tuple<T>::Tuple(const Tuple<T>&& tp) : val{tp.val}
{}

template <typename T>
Tuple<T>::Tuple(const T& value) : val{value}
{}

template <typename T>
Tuple<T>::Tuple(T& value) : val{value}
{}

template <typename T>
Tuple<T>::Tuple(T&& value) : val{std::move(value)}
{}

template <typename T>
Tuple<T>::Tuple(const T&& value) : val{value}
{}

template <typename T>
template <typename U>
Tuple<T>::Tuple(U&& value) : val{std::forward<U>(value)}
{}

template <typename T>
template <typename U>
Tuple<T>::Tuple(const Tuple<U>& oth) : val{oth.val}
{}

template <typename T>
template <typename U>
Tuple<T>::Tuple(Tuple<U>&& oth) : val{std::move(oth.val)}
{}

template <typename T>
Tuple<T>& Tuple<T>::operator=(Tuple<T>& tp)
{
    this->val = tp.val;
    return *this;
}

template <typename T>
Tuple<T>& Tuple<T>::operator=(const Tuple<T>&& tp)
{
    this->val = tp.val;
    return *this;
}

template <typename T>
Tuple<T>& Tuple<T>::operator=(const T& value)
{
    this->val = value;
    return *this;
}

template <typename T>
Tuple<T>& Tuple<T>::operator=(T&& value)
{
    this->val = std::move(value);
    return *this;
}

template <typename T>
template <typename U>
Tuple<T>& Tuple<T>::operator=(U&& value)
{
    this->val = std::forward<U>(value);
    return *this;
}

template <typename T>
template <typename U>
Tuple<T>& Tuple<T>::operator=(const Tuple<U>& oth)
{
    this->val = oth.val;
    return *this;
}

template <typename T>
template <typename U>
Tuple<T>& Tuple<T>::operator=(Tuple<U>& oth)
{
    this->val = oth.val;
    return *this;
}

template <typename T>
template <typename U>
Tuple<T>& Tuple<T>::operator=(Tuple<U>&& oth)
{
    this->val = std::move(oth.val);
    return *this;
}

template <typename T>
template <typename U>
Tuple<T>& Tuple<T>::operator=(const Tuple<U>&& oth)
{
    this->val = oth.val;
    return *this;
}
/* Tuple<T> End */

/* Tuple<T1,T2> Implemetion */
template <typename T1,typename T2>
Tuple<T1,T2>::Tuple(const std::pair<T1,T2>& pr) : first{pr.first},
                                                second{pr.second}
{}

template <typename T1,typename T2>
Tuple<T1,T2>::Tuple(std::pair<T1,T2>&& pr) : first{std::move(pr.first)},
                                                second{std::move(pr.second)}
{}

template <typename T1,typename T2>
Tuple<T1,T2>::Tuple(const T1& val1,const T2& val2) : first{val1},
                                                    second{val2}
{}

template <typename T1,typename T2>
Tuple<T1,T2>::Tuple(T1&& val1,T2&& val2) : first{std::move(val1)},
                                            second{std::move(val2)}
{}

template <typename T1,typename T2>
template <typename U1,typename U2>
Tuple<T1,T2>::Tuple(const Tuple<U1,U2>& oth) : first(oth.first),
                                                second(oth.second)
{}

template <typename T1,typename T2>
template <typename U1,typename U2>
Tuple<T1,T2>::Tuple(Tuple<U1,U2>&& oth) : first(std::move(oth.first)),
                                            second(std::move(oth.second))
{}

template <typename T1,typename T2>
template <typename U1,typename U2>
Tuple<T1,T2>::Tuple(const std::pair<U1,U2>& oth) : first(oth.first),
                                            second(oth.second)
{}

template <typename T1,typename T2>
template <typename U1,typename U2>
Tuple<T1,T2>::Tuple(std::pair<U1,U2>&& oth) : first(std::move(oth.first)),
                                            second(std::move(oth.second))
{}

template <typename T1,typename T2>
template <typename U1,typename U2,typename std::enable_if<
                                                !std::is_same<
                                                    typename std::decay<U1>::type,
                                                    typename std::decay<T1>::type
                                                >::value || !std::is_same<
                                                    typename std::decay<U2>::type,
                                                    typename std::decay<T2>::type
                                                >::value
                                            >::type
                                        >
Tuple<T1,T2>::Tuple(U1&& val1,U2&& val2) : first(std::forward<U1>(val1)),
                                            second(std::forward<U2>(val2))
{}

template <typename T1,typename T2>
Tuple<T1,T2>& Tuple<T1,T2>::operator=(const std::pair<T1,T2>& pr)
{
    this->first = pr.first;
    this->second = pr.second;
    return *this;
}

template <typename T1,typename T2>
Tuple<T1,T2>& Tuple<T1,T2>::operator=(std::pair<T1,T2>&& pr)
{
    this->first = std::move(pr.first);
    this->second = std::move(pr.second);
    return *this;
}

template <typename T1,typename T2>
template <typename U1,typename U2>
Tuple<T1,T2>& Tuple<T1,T2>::operator=(const Tuple<U1,U2>& oth)
{
    this->first = oth.first;
    this->second = oth.second;
    return *this;
}

template <typename T1,typename T2>
template <typename U1,typename U2>
Tuple<T1,T2>& Tuple<T1,T2>::operator=(Tuple<U1,U2>&& oth)
{
    this->first = std::move(oth.first);
    this->second = std::move(oth.second);
    return *this;
}

template <typename T1,typename T2>
template <typename U1,typename U2>
Tuple<T1,T2>& Tuple<T1,T2>::operator=(const std::pair<U1,U2>& pr)
{
    this->first = pr.first;
    this->second = pr.second;
    return *this;
}

template <typename T1,typename T2>
template <typename U1,typename U2>
Tuple<T1,T2>& Tuple<T1,T2>::operator=(std::pair<U1,U2>&& pr)
{
    this->first = std::move(pr.first);
    this->second = std::move(pr.second);
    return *this;
}
/* Tuple<T1,T2> End */

template <typename T,typename... Args>
Tuple<T,Args...>::Tuple(const T& par,const Args&... args) : val{par}, 
                                                        rest{args...}
{}

template <typename T,typename... Args>
Tuple<T,Args...>::Tuple(T&& par,Args&&... args) : val{std::move(par)},
                                        rest{(std::move(args),...)}
{}

template <typename T,typename... Args>
template <typename U,typename... Args1>
Tuple<T,Args...>::Tuple(const Tuple<U,Args1...>& oth) : val(oth.val),
                                                        rest(oth.rest)
{}

template <typename T,typename... Args>
template <typename U,typename... Args1>
Tuple<T,Args...>::Tuple(Tuple<U,Args1...>&& oth) : val(std::move(oth.val)),
                                                    rest(std::move(oth.rest))
{}

template <typename T,typename... Args>
template <typename U,typename... Args1>
Tuple<T,Args...>& Tuple<T,Args...>::operator=(const Tuple<U,Args1...>& oth) 
{
    this->val = oth.val;
    this->rest = oth.rest;
    return *this;
}

template <typename T,typename... Args>
template <typename U,typename... Args1>
Tuple<T,Args...>& Tuple<T,Args...>::operator=(Tuple<U,Args1...>&& oth) 
{
    this->val = std::move(oth.val);
    this->rest = std::move(oth.rest);
    return *this;
}


#endif /* _TUPLE_HPP_ */
