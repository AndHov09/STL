#include <iostream>
#include <iterator>
#include <vector>
#include <forward_list>
#include <list>

namespace detail
{
    template <typename It>
    void det_advance(It& iter,typename std::iterator_traits<It>::difference_type n, std::input_iterator_tag)
    {
        while(n > 0)
        {
            --n;
            ++iter;
        }
    }

    template <typename It>
    void det_advance(It& iter, typename std::iterator_traits<It>::difference_type n, std::bidirectional_iterator_tag)
    {
        while(n > 0)
        {
            --n;
            ++iter;
        }
        while(n < 0)
        {
            ++n;
            --iter;
        }
    }

    template <typename It>
    void det_advance(It& iter, typename std::iterator_traits<It>::difference_type n, std::random_access_iterator_tag)
    {
        iter += n;
    }
};

template <typename It,typename Dis>
void m_advance(It&,Dis);

int main()
{
    std::vector<int> vec{1,2,3,4,5,6};
    std::forward_list<int> for_list{1,2,3,4,5,6};
    std::list<int> lis{1,2,3,4,5,6};
    auto it1 = vec.begin();
    auto it2 = for_list.begin();
    auto it3 = lis.begin();
    m_advance(it1,4);
    m_advance(it2,3);
    m_advance(it3,5);
    std::cout << *it1 << std::endl;
    std::cout << *it2 << std::endl;
    std::cout << *it3 << std::endl;
}

template <typename It,typename Dis>
void m_advance(It& iter,Dis n)
{
    detail::det_advance(iter,typename std::iterator_traits<It>::difference_type(n),typename std::iterator_traits<It>::iterator_category());
}
