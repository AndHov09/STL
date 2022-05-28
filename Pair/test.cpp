#include <iostream>
#include <utility>
#include "Pair.h"
#include <vector>

template class Pair<long,double>;

int main()
{
    std::pair<int,int> pr;
    std::cout << sizeof(pr) << std::endl;
    Pair<int,int> p(std::make_tuple(4,5));
}
