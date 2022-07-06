#ifndef _FORWARD_LIST_HPP_
#define _FORWARD_LIST_HPP_

template <typename T>
Forward_list<T>::Node::Node(const T& val,typename Forward_list<T>::Node* nextt) :
                                        value{val}, next{nextt}
{}

template <typename T>
Forward_list<T>::Node::Node(T&& val,typename Forward_list<T>::Node* nextt) :
                                        value{std::move(val)}, next{nextt}
{}

template <typename T>
Forward_list<T>::iterator::iterator() : m_it{}
{}

template <typename T>
Forward_list<T>::iterator::iterator(const typename Forward_list<T>::iterator& oth) :
                                        m_it{oth.m_it}
{}

template <typename T>
Forward_list<T>::iterator::iterator(typename Forward_list<T>::Node* ptr) : 
                                        m_it{ptr}
{}

template <typename T>
typename Forward_list<T>::iterator& Forward_list<T>::iterator::operator=
                                    (const typename Forward_list<T>::iterator& oth)
{
    this->m_it = oth.m_it;
    return *this;
}

template <typename T>
typename Forward_list<T>::iterator& Forward_list<T>::iterator::operator++()
{
    this->m_it = this->m_it->next;
    return *this;
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::iterator::operator++(int) 
{
    typename Forward_list<T>::iterator tmp(*this);
    ++(*this);
    return tmp;
}

template <typename T>
T& Forward_list<T>::iterator::operator*()
{
    return m_it->value;
}

template <typename T>
const T& Forward_list<T>::iterator::operator*() const
{
    return m_it->value;
}

template <typename T>
T* Forward_list<T>::iterator::operator->()
{
    return &(m_it->value); 
}

template <typename T>
const T* Forward_list<T>::iterator::operator->() const
{
    return &(m_it->value);
}

template <typename T>
bool Forward_list<T>::iterator::operator==
            (const typename Forward_list<T>::iterator& oth) const
{
    return m_it == oth.m_it;
}

template <typename T>
bool Forward_list<T>::iterator::operator!=
            (const typename Forward_list<T>::iterator& oth) const
{
    return !(*this == oth);
}

template <typename T>
Forward_list<T>::const_iterator::const_iterator() : m_it{}
{}

template <typename T>
Forward_list<T>::const_iterator::const_iterator(const typename 
                                        Forward_list<T>::const_iterator& oth) :
                                            m_it{oth.m_it}
{}

template <typename T>
Forward_list<T>::const_iterator::const_iterator(const typename 
                                            Forward_list<T>::Node* ptr) : 
                                                m_it{ptr}
{}

template <typename T>
typename Forward_list<T>::const_iterator& Forward_list<T>::const_iterator::operator=(
                                const typename Forward_list<T>::const_iterator& oth)
{
    m_it = oth.m_it;
    return *this;
}

template <typename T>
const T& Forward_list<T>::const_iterator::operator*() const
{
    return m_it->value;
}

template <typename T>
const T* Forward_list<T>::const_iterator::operator->() const
{
    return &(m_it->value);
}

template <typename T>
bool Forward_list<T>::const_iterator::operator==(const typename 
                                        Forward_list<T>::const_iterator& rhs) const
{
    return m_it == rhs.m_it;
}

template <typename T>
bool Forward_list<T>::const_iterator::operator!=(const typename 
                                        Forward_list<T>::const_iterator& rhs) const
{
    return !(*this == rhs);
}

template <typename T>
Forward_list<T>::Forward_list() : m_head{}
{}

template <typename T>
Forward_list<T>::Forward_list(const Forward_list<T>& oth) : m_head{}
{
    if(!oth.empty())
    {
        m_head = new Node(oth.m_head->value);
        typename Forward_list<T>::Node* ptr1 = m_head;
        typename Forward_list<T>::Node* ptr2 = oth.m_head->next;
        while(ptr2)
        {
            ptr1->next = new Node(ptr2->value);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
}

template <typename T>
Forward_list<T>::Forward_list(Forward_list<T>&& oth) : m_head{}
{
    this->swap(oth);
}

template <typename T>
Forward_list<T>::Forward_list(std::initializer_list<T> init) : m_head{}
{
    if(init.size())
    {
        const T* ptr = init.begin();
        m_head = new Node(*ptr);
        typename Forward_list<T>::Node* node = m_head;
        ++ptr;
        while(ptr != init.end())
        {
            node->next = new Node(*ptr);
            ++ptr;
            node = node->next;
        }
    }
}

template <typename T>
template <typename Iter>
Forward_list<T>::Forward_list(Iter begin,Iter end) : m_head{}
{
    if(begin != end)
    {
        m_head = new Node(*begin);
        ++begin;
        typename Forward_list<T>::Node* ptr = m_head;
        while(begin != end)
        {
            ptr->next = new Node(*begin);
            ptr = ptr->next;
            ++begin;
        }
    }
}

template <typename T>
Forward_list<T>::Forward_list(size_t count) : m_head{}
{
    if(count)
    {
        m_head = new Node(T{});
        typename Forward_list<T>::Node* ptr = m_head;
        --count;
        while(count--)
        {
            ptr->next = new Node(T{});
            ptr = ptr->next;
        }
    }
}

template <typename T>
Forward_list<T>::Forward_list(size_t count,const T& val) : m_head{}
{
    if(count)
    {
        m_head = new Node(val);
        typename Forward_list<T>::Node* ptr = m_head;
        --count;
        while(count--)
        {
            ptr->next = new Node(val);
            ptr = ptr->next;
        }
    }
}

template <typename T>
Forward_list<T>::~Forward_list()
{
    this->clear();
}

template <typename T>
Forward_list<T>& Forward_list<T>::operator=(const Forward_list<T>& oth)
{
    if(this != &oth)
    {
        this->clear();
        Forward_list<T> tmp(oth);
        *this = std::move(tmp);
    }
    return *this;
}

template <typename T>
Forward_list<T>& Forward_list<T>::operator=(Forward_list<T>&& oth)
{
    if(this != &oth)
    {
        this->clear();
        this->swap(oth);
    }
    return *this;
}

template <typename T>
Forward_list<T>& Forward_list<T>::operator=(std::initializer_list<T> init)
{
    this->clear();
    Forward_list<T> tmp(init);
    *this = std::move(tmp);
    return *this;
}

template <typename T>
void Forward_list<T>::assign(size_t count,const T& val)
{
    this->clear();
    *this = Forward_list<T>(count,val);
}

template <typename T>
template <typename Iter>
void Forward_list<T>::assign(Iter begin,Iter end)
{
    this->clear();
    *this = Forward_list<T>(begin,end);
}

template <typename T>
T& Forward_list<T>::front()
{
    return m_head->value;
}

template <typename T>
const T& Forward_list<T>::front() const
{
    return m_head->value;
}

template <typename T>
bool Forward_list<T>::empty() const 
{
    return !m_head;
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::begin() const
{
    return typename Forward_list<T>::iterator(m_head);
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::end() const
{
    return typename Forward_list<T>::iterator(nullptr);
}

template <typename T>
void Forward_list<T>::clear()
{
    while(m_head)
    {
        typename Forward_list<T>::Node* ptr = m_head;
        m_head = m_head->next;
        delete ptr;
    }
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::insert_after
                                    (typename Forward_list<T>::iterator pos,
                                        const T& val)
{
    pos.m_it->next = new Node(val,pos.m_it->next);
    return ++pos;
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::insert_after
                                    (typename Forward_list<T>::iterator pos,
                                        T&& val)
{
    pos.m_it->next = new Node(std::move(val),pos.m_it->next);
    return ++pos;
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::insert_after
                                    (typename Forward_list<T>::iterator pos,
                                        size_t count,const T& val)
{
    typename Forward_list<T>::Node* ptr = pos.m_it;
    while(count--)
    {
        ptr->next = new Node(val,ptr->next);
    }
    return ++pos;
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::insert_after
                                    (typename Forward_list<T>::iterator pos,
                                        std::initializer_list<T> init)
{
   typename Forward_list<T>::Node* ptr = pos.m_it;
   for( const T& x : init)
   {
        ptr->next = new Node(x,ptr->next);
        ptr = ptr->next;
   }
   return ++pos;
}

template <typename T>
template <typename Iter>
typename Forward_list<T>::iterator Forward_list<T>::insert_after
                                (typename Forward_list<T>::iterator pos,
                                    Iter begin,Iter end)
{
    typename Forward_list<T>::Node* ptr = pos.m_it;
    while(begin != end)
    {
        ptr->next = new Node(*begin,ptr->next);
        ptr = ptr->next;
        ++begin;
    }
    return ++pos;
}

template <typename T>
template <typename... Ts>
typename Forward_list<T>::iterator Forward_list<T>::emplace_after
                                (typename Forward_list<T>::iterator pos,
                                    Ts&&... args)
{
    return this->insert_after(pos,T((std::forward<Ts>(args),...)));
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::erase_after
                                (typename Forward_list<T>::iterator pos)
{
    typename Forward_list<T>::Node* ptr = pos.m_it->next;
    pos.m_it->next = pos.m_it->next->next;
    delete ptr;
    return ++pos;
}

template <typename T>
typename Forward_list<T>::iterator Forward_list<T>::erase_after
                                (typename Forward_list<T>::iterator begin,
                                typename Forward_list<T>::iterator end)
{
    typename Forward_list<T>::Node* ptr = begin.m_it->next;
    begin.m_it->next = end.m_it;
    while(ptr != end.m_it)
    {
        typename Forward_list<T>::Node* tmp = ptr;
        ptr = ptr->next;
        delete tmp;
    }
    return end;
}

template <typename T>
void Forward_list<T>::push_front(const T& val)
{
    m_head = new Node(val, !m_head ? nullptr : m_head->next);
}

template <typename T>
void Forward_list<T>::push_front(T&& val)
{
    m_head = new Node(std::move(val), !m_head ? nullptr : m_head->next);
}

template <typename T>
template <typename... Ts>
void Forward_list<T>::emplace_front(Ts&&... args)
{
    this->pop_front(T((std::forward<Ts>(args),...)));
}

template <typename T>
void Forward_list<T>::pop_front()
{
    if(!this->empty())
    {
        typename Forward_list<T>::Node* ptr = m_head;
        m_head = m_head->next;
        delete ptr;
    }
}

template <typename T>
void Forward_list<T>::resize(size_t count)
{
    this->resize(count,T{});
    return;
}

template <typename T>
void Forward_list<T>::resize(size_t count,const T& val)
{
    typename Forward_list<T>::Node* ptr = m_head;
    typename Forward_list<T>::Node* ptr1 = m_head;
    size_t size{};
    while(ptr)
    {
        ++size;
        ptr1 = ptr;
        ptr = ptr->next;
    }
    if(size >= count)
    {
        return;
    }
    count -= size;
    while(count--)
    {
        ptr1->next = new Node(val);
        ptr1 = ptr1->next;
    }
}

template <typename T>
void Forward_list<T>::swap(Forward_list<T>& oth)
{
    typename Forward_list<T>::Node* tmp = oth.m_head;
    oth.m_head = this->m_head;
    this->m_head = tmp;
    tmp = nullptr;
}

template <typename T>
void Forward_list<T>::merge(Forward_list<T>& oth)
{
    if(oth.empty())
    {
        return;
    }else if(this->empty())
    {
        this->swap(oth);
        return;
    }
    typename Forward_list<T>::Node* new_head{};
    typename Forward_list<T>::Node* tmp{};
    if(m_head->value <= oth.m_head->value)
    {
        new_head = m_head;
        tmp = oth.m_head;
    }else{
        new_head = oth.m_head;
        tmp = m_head;
    }
    typename Forward_list<T>::Node* ptr = new_head;
    while(ptr->next && tmp)
    {
        if(ptr->next->value <= tmp->value)
        {
            ptr = ptr->next;            
        }else{
            typename Forward_list<T>::Node* ptr1 = tmp->next;
            tmp->next = ptr->next;
            ptr->next = tmp;
            tmp = ptr1;
        }
    }
    if(tmp)
    {
        ptr->next = tmp;
    }
    oth.m_head = nullptr;
    this->m_head = new_head;
}

template <typename T>
void Forward_list<T>::remove(const T& val)
{
    while(m_head && m_head->value == val)
    {
        typename Forward_list<T>::Node* ptr = m_head;
        m_head = m_head->next;
        delete ptr;
    }
    if(!m_head)
    {
        return;
    }
    typename Forward_list<T>::Node* ptr = m_head;
    while(ptr->next)
    {
        if(ptr->next->value == val)
        {
            typename Forward_list<T>::Node* tmp = ptr->next;
            ptr->next = ptr->next->next;
            delete tmp;
        }else{
            ptr = ptr->next;
        }
    }
}

template <typename T>
void Forward_list<T>::reverse()
{
    typename Forward_list<T>::Node* next = m_head;
    typename Forward_list<T>::Node* prev{};
    while(m_head)
    {
        next = m_head->next;
        m_head->next = prev;
        prev = m_head;
        m_head = next;
    }
    m_head = prev;
}

template <typename T>
void Forward_list<T>::unique()
{
    return;
}

template <typename T>
void Forward_list<T>::sort()
{
    return;
}

template <typename T>
bool operator==(const Forward_list<T>& lhs,const Forward_list<T>& rhs)
{
    typename Forward_list<T>::iterator it1 = lhs.begin();
    typename Forward_list<T>::iterator it2 = rhs.begin();
    while(it1 != lhs.end() && it2 != rhs.end())
    {
        if(*it1 != *it2)
        {
            return false;
        }
        ++it1;
        ++it2;
    }
    if(it1 == lhs.end() && it2 == rhs.end())
    {
        return true;
    }
    return false;
}

template <typename T>
bool operator!=(const Forward_list<T>& lhs,const Forward_list<T>& rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const Forward_list<T>& lhs,const Forward_list<T>& rhs)
{
    typename Forward_list<T>::iterator it1 = lhs.begin();
    typename Forward_list<T>::iterator it2 = rhs.begin();
    while(it1 != lhs.end() && it2 != rhs.end())
    {
        if(*it1 >= *it2)
        {
            return false;
        }
        ++it1;
        ++it2;
    }
    return true;
}

template <typename T>
bool operator>(const Forward_list<T>& lhs,const Forward_list<T>& rhs)
{
    return (rhs < lhs);
}

template <typename T>
bool operator>=(const Forward_list<T>& lhs,const Forward_list<T>& rhs)
{
    return (lhs == rhs) || (lhs > rhs);
}

template <typename T>
bool operator<=(const Forward_list<T>& lhs,const Forward_list<T>& rhs)
{
    return (lhs == rhs) || (lhs < rhs);
}

#endif // _FORWARD_LIST_HPP_
