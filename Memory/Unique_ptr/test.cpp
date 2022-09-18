#include <iostream>
#include <memory>
#include "Unique_ptr.h"

class A
{
    public:
        A() {std::cout << 1 << std::endl;}
        ~A() {std::cout << 2 << std::endl;}
};

template class Unique_ptr<A>;
template class Unique_ptr<A[]>;

int main()
{
    {
        Unique_ptr<A> ptr(new A);
    }
    Unique_ptr<A[]> ptr1(new A[5]);
    std::unique_ptr<A[]> ptr(new A[4]);
}
