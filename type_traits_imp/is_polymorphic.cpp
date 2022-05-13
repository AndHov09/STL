#include <iostream>

template <class T>
struct is_polymorphic
{
    struct D : public T
    {
        virtual ~D(){}
    };
    enum {value = sizeof(D) == sizeof(T)};
};

class A
{
    public:
        virtual void foo(){}
};

class B 
{};

int main()
{
    std::cout << is_polymorphic<A>::value << std::endl; 
    std::cout << is_polymorphic<B>::value << std::endl; 
}
