#include <iostream>
#include "Myvec.h"

template class MyVector<int>;

int main()
{
	MyVector<int> vec{1,2,3,4,5,6,7};
    MyVector<int>::iterator it = vec.begin();
    MyVector<int>::iterator it1 = vec.end();
    it++;
    std::cout << *it++ << std::endl;
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << *(i + it) << "   ";
	}
	std::cout << std::endl;
	vec.erase(3);
	for (const int& a : vec)
	{
		std::cout << a << "   ";
	}
	std::cout << std::endl;
    for(auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
	return 0;
}
