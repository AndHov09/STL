#include <iostream>
#include <type_traits>

template <typename T>
T&& forward(typename std::remove_reference<T>::type& tmp)
{
    return static_cast<T&&>(tmp);
}

template <typename T>
T&& forward(typename std::remove_reference<T>::type&& tmp)
{
    return static_cast<T&&>(tmp);
}

class A
{
    public:
    int _x;
};

void foo(A&){std::cout << 3 << std::endl;}
void foo(A&&){std::cout << 4 << std::endl;}

template <typename T>
void moo(T&& par)
{
    foo(forward<T>(par));
}

int main()
{
    A obj;
    moo(std::move(obj));
    moo(obj);
}
