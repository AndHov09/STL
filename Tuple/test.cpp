#include <iostream>
#include "Tuple.h"
#include <tuple>

int main()
{
    Tuple<double> t1(3.14);
    Tuple<long> t2(3l);
    Tuple<double> t3(t1);
    t2 = t3;
    long a = 4;
    Tuple<long> tp(a);
    std::cout << a << std::endl;
    Tuple<long> tp1(5l);
}
