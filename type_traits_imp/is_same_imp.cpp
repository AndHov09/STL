#include <iostream>

template <typename T,typename U>
struct is_same
{
    enum {value = false};
};

template <typename T>
struct is_same<T,T>
{
    enum {value = true};
};

int main()
{
    std::cout << is_same<int,int*>::value << std::endl;
    std::cout << is_same<int,int>::value << std::endl;
}
