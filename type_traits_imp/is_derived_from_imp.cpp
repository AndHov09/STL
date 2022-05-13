#include <iostream>
#include <type_traits>
#include <concepts>

struct A
{

};

struct B : A
{

};

int main()
{
    std::cout << std::derived_from<B,A> << std::endl;
}
