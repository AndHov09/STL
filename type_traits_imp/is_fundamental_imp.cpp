#include <iostream>
#include <type_traits>

#include "is_void_imp.h"
#include "is_integral_imp.h"
#include "is_float_point_imp.h"

template <typename T>
struct is_fundamental
{
    enum {value = is_void<T>::value || is_integral<T>::value || is_float_point<T>::value || is_same<nullptr_t,T>::value};
};

int main()
{
    std::cout << is_fundamental<int16_t>::value << std::endl;
}
