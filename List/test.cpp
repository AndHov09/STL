#include <iostream>
#include <list>
#include <initializer_list>
#include <utility>
#include "List.h"

int main()
{
    List<int> ls{1,3,5,7};
    List<int> ls1{9,11,13,15};
    ls.splice(++++ls.begin(),ls1);
    for(int x : ls)
    {
        std::cout << x << "  ";
    }
}
