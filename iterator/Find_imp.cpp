#include <iostream>
#include <vector>

template <typename In_iter,typename T>
In_iter m_find(In_iter, In_iter, const T&);

int main()
{
    std::vector<int> vec{1,2,3,4,5,6};
    std::vector<int>::iterator It = m_find(vec.begin(),vec.end(),7);
    std::cout << *It << std::endl;
}

template <typename In_iter,typename T>
In_iter m_find(In_iter first,In_iter last,const T& val)
{
    for( ; first != last; ++first)
    {
        if(*first == val)
        {
            return first;
        }
    }
    return last;
}
