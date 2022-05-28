// List Node //
template <typename T>
List<T>::Node::Node(const T& val,Node* nptr,Node* pptr) : value{val}, 
                                            next{nptr}, prev{pptr}
{}

template <typename T>
template <typename... Ts>
List<T>::Node::Node(Node* nptr, Node* pptr,Ts&&... ts) : 
                                value((std::forward<Ts>(ts),...)),
                                next{nptr}, prev{pptr}
{}

template <typename T>
List<T>::Node::Node(const Node& oth) : value{oth.value},
                        next{oth.next}, prev{oth.prev}
{}
template <typename T>
List<T>::Node::Node(Node&& oth) : value{std::move(oth.value)},
                                    next{oth.next},
                                    prev{oth.prev}
{
    oth.next = nullptr;
    oth.prev = nullptr;
}

// End List Node //

// iterator //

template <typename T>
List<T>::iterator::iterator() : _it{}
{}

template <typename T>
List<T>::iterator::iterator(const List<T>::iterator& oth) : _it{oth._it}
{}

template <typename T>
List<T>::iterator::iterator(List<T>::Node* ptr) : _it{ptr}
{}

template <typename T>
typename List<T>::iterator& List<T>::iterator::operator=(const List<T>::iterator& oth)
{
    this->_it = oth._it;
    return *this;
}

template <typename T>
bool List<T>::iterator::operator==(const List<T>::iterator& oth) const
{
    return this->_it == oth._it;
}

template <typename T>
bool List<T>::iterator::operator!=(const List<T>::iterator& oth) const
{
    return !(*this == oth);
}

template <typename T>
T& List<T>::iterator::operator*()
{
    return this->_it->value;
}

template <typename T>
const T& List<T>::iterator::operator*() const
{
    return this->_it->value;
}

template <typename T>
T* List<T>::iterator::operator->()
{
    return &(this->_it->value);
}

template <typename T>
const T* List<T>::iterator::operator->() const
{
    return &(this->_it->value);
}

template <typename T>
typename List<T>::iterator& List<T>::iterator::operator++() 
{
    _it = _it->next;
    return *this;
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator++(int) &
{
    typename List<T>::iterator tmp(*this);
    ++*this;
    return tmp;
}

template <typename T>
typename List<T>::iterator& List<T>::iterator::operator--() 
{
    _it = _it->prev;
    return *this;
}

template <typename T>
typename List<T>::iterator List<T>::iterator::operator--(int) &
{
    typename List<T>::iterator tmp(*this);
    --*this;
    return tmp;
}
/* End Iteraotrs */

template <typename T>
List<T>::List() : m_head{}, m_tail{}
{}

template <typename T>
List<T>::List(const List<T>& oth) : m_head{}, m_tail{}
{
    if(!oth.empty())
    {
        m_head = new Node(oth.front());
        Node* tmp1 = m_head;
        Node* tmp2 = oth.m_head->next;
        while(tmp2)
        {
            tmp1->next = new Node(tmp2->value,nullptr,tmp1);
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        m_tail = tmp1;
        tmp1 = tmp2 = nullptr;
    }
}

template <typename T>
List<T>::List(List<T>&& oth) : m_head{oth.m_head}, m_tail{oth.m_tail}
{
    oth.m_head = nullptr;
    oth.m_tail = nullptr;
}

template <typename T>
List<T>::List(size_t count,const T& val) : m_head{}, m_tail{}
{
    if(count)
    {
        m_head = new Node(val);
        Node* tmp = m_head;
        --count;
        while(count)
        {
            tmp->next = new Node(val,nullptr,tmp);
            tmp = tmp->next;
            --count;
        }
        m_tail = tmp;
    }
}

template <typename T>
List<T>::List(size_t count) : m_head{}, m_tail{}
{
    if(count)
    {
        m_head = new Node();
        Node* tmp = m_head;
        --count;
        while(count)
        {
            tmp->next = new Node(nullptr,tmp);
            tmp = tmp->next;
            --count;
        }
        m_tail = tmp;
    }
}

template <typename T>
List<T>::List(std::initializer_list<T> init) : m_head{}, m_tail{}
{
    if(init.size())
    {
        const T* arr = init.begin();
        m_head = new Node(*arr);
        Node* tmp = m_head;
        for(int i = 1; i < init.size(); ++i)
        {
            tmp->next = new Node(arr[i],nullptr,tmp);
            tmp = tmp->next;
        }
        m_tail = tmp;
        arr = nullptr;
    }
}

template <typename T>
template <typename InputIt>
List<T>::List(InputIt first,InputIt last)
{
    if(first != last)
    {
        m_head = new Node(*first);
        Node* tmp = m_head;
        ++first;
        while(first != last)
        {
            tmp->next = new Node(*first,nullptr,tmp);
            tmp = tmp->next;
            ++first;
        }
        m_tail = tmp;
    }
}

template <typename T>
List<T>::~List()
{
    this->clear();
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& oth)
{
    if(this == &oth)
    {
        return *this;
    }
    if(!this->empty())
    {
        this->clear();
    }
    m_head = new Node(oth.front());
    Node* tmp1 = m_head;
    Node* tmp2 = oth.m_head->next;
    while(tmp2)
    {
        tmp1->next = new Node(*tmp2,nullptr,tmp1);
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    m_tail = tmp1;
    tmp2 = tmp1 = nullptr;
    return *this;
}

template <typename T>
List<T>& List<T>::operator=(List<T>&& oth)
{
    if(this == &oth)
    {
        return *this;
    }
    this->clear();
    this->swap(oth);
    return *this;
}

template <typename T>
void List<T>::assign(size_t count,const T& val)
{
    this->clear();
    List<T> tmp(count,val);
    *this = std::move(tmp);
    return;
}

template <typename T>
void List<T>::assign(std::initializer_list<T> init)
{
    this->clear();
    List<T> tmp(init);
    *this = std::move(tmp);
    return;
}

template <typename T>
template <typename InputIt>
void List<T>::assign(InputIt first,InputIt last)
{
    this->clear();
    List<T> tmp(first,last);
    *this = std::move(tmp);
    return;
}

template <typename T>
void List<T>::swap(List& oth)
{
    std::swap(m_head,oth.m_head);
    std::swap(m_tail,oth.m_tail);
    return;
}

template <typename T>
T& List<T>::front()
{
    return m_head->value;
}

template <typename T>
const T& List<T>::front() const
{
    return m_head->value;
}

template <typename T>
T& List<T>::back()
{
    return m_tail->value;
}

template <typename T>
const T& List<T>::back() const
{
    return m_tail->value;
}

template <typename T>
typename List<T>::iterator List<T>::begin()
{
    return m_head;
}

template <typename T>
typename List<T>::iterator List<T>::end()
{
    return m_tail->next;
}

template <typename T>
bool List<T>::empty() const
{
    return !m_head;
}

template <typename T>
size_t List<T>::size() const
{
    Node* tmp = m_head;
    size_t m_size = 0;
    while(tmp)
    {
        ++m_size;
        tmp = tmp->next;
    }
    return m_size;
}

template <typename T>
void List<T>::clear()
{
    if(!this->empty())
    {
        while(m_head)
        {
            Node* tmp = m_head;
            m_head = m_head->next;
            delete tmp;
        }
        m_tail = nullptr;
    }
    return;
}

template <typename T>
void List<T>::push_back(const T& val)
{
    if(this->empty())
    {
        m_head = new Node(val);
        m_tail = m_head;
    } 
    else 
    {
        m_tail->next = new Node(val,nullptr,m_tail);
        m_tail = m_tail->next;
    }
    return;
}

template <typename T>
void List<T>::push_back(T&& val)
{
    if(this->empty())
    {
        m_head = new Node(std::move(val));
        m_tail = m_head;
    } 
    else 
    {
        m_tail->next = new Node(std::move(val),nullptr,m_tail);
        m_tail = m_tail->next;
    }
    return;

}

template <typename T>
void List<T>::pop_back()
{
    if(!this->empty())
    {
        Node* tmp = m_tail;
        m_tail = m_tail->prev;
        if(!m_tail)
        {
            m_head = nullptr;
        }
        delete tmp;
        tmp = nullptr;
    }
    return;
}

template <typename T>
void List<T>::push_front(const T& val)
{
    if(this->empty())
    {
        m_head = new Node(val);
        m_tail = m_head;
    }else{
        m_head = new Node(val,m_head);
    }
    return;
}

template <typename T>
void List<T>::push_front(T&& val)
{
    if(this->empty())
    {
        m_head = new Node(std::move(val));
        m_tail = m_head;
    }else{
        m_head = new Node(std::move(val),m_head);
    }
    return;
}

template <typename T>
void List<T>::pop_front()
{
    if(!this->empty())
    {
        Node* tmp = m_head;
        m_head = m_head->next;
        if(!m_head)
        {
            m_tail = nullptr;
        }
        delete tmp;
    }
    return;
}

template <typename T>
typename List<T>::iterator List<T>::insert(iterator pos,const T& val)
{
    if(this->empty())
    {
        m_head = new Node(val);
        m_tail = m_head;
        return m_head;
    }else{
        pos._it->prev = new Node(val,pos._it,pos._it->prev);
        if(pos._it->prev->prev)
        {
            pos._it->prev->prev->next = pos._it->prev;
        }else{
            m_head = pos._it->prev;
        }
        return pos._it->prev;
    }
}

template <typename T>
typename List<T>::iterator List<T>::insert(iterator pos,T&& val)
{
    if(this->empty())
    {
        m_head = new Node(std::move(val));
        m_tail = m_head;
        return m_head;
    }else{
        pos._it->prev = new Node(std::move(val),pos._it,pos._it->prev);
        if(pos._it->prev->prev)
        {
            pos._it->prev->prev->next = pos._it->prev;
        }else{
            m_head = pos._it->prev;
        }
        return pos._it->prev;
    }
}

template <typename T>
typename List<T>::iterator List<T>::insert(iterator pos,size_t count,const T& val)
{
    if(this->empty())
    {
        this->assign(count,val);
        return m_head;
    }
    while(count--)
    {
        pos = this->insert(pos,val);
    }
    return pos; 
}

template <typename T>
template <typename InputIt>
typename List<T>::iterator List<T>::insert(iterator pos,InputIt first,InputIt last)
{
    if(this->empty())
    {
        this->assign(first,last);
        return m_head;
    }
    while(first != last)
    {
        pos = this->insert(pos,*first);
        ++first;
    }
    return pos;
}

template <typename T>
typename List<T>::iterator List<T>::insert(iterator pos,std::initializer_list<T> init)
{
    if(this->empty())
    {
        this->assign(init);
        return m_head;
    }
    T* arr = init.begin();
    for(int i = 0; i < init.size(); ++i)
    {
        pos = this->insert(pos,arr[i]);
    }
    return pos;
}

template <typename T>
template <typename... Args>
typename List<T>::iterator List<T>::emplace(iterator pos,Args&&... args)
{
   if(this->empty())
   {
        m_head = new Node(nullptr,nullptr,(std::forward<Args>(args),...));
        m_tail = m_head;
        return m_head;
   }
   pos._it->prev = new Node(pos._it,pos._it->prev,args...);
   if(pos._it->prev->prev)
   {
        pos._it->prev->prev->next = pos._it->prev;
   }else
   {
        m_head = pos._it->prev;
   }
   return ++pos;
}

template <typename T>
typename List<T>::iterator List<T>::erase(iterator pos)
{
    if(!pos._it->prev)
    {
        Node* tmp = pos._it;
        ++pos;
        m_head = m_head->next;
        tmp->next->prev = nullptr; 
        delete tmp;
        tmp = nullptr;
        if(!m_head)
        {
            m_tail = nullptr;
        }
        return nullptr;
    }
    if(!pos._it->next)
    {
        Node* tmp = pos._it;
        --pos;
        m_tail = m_tail->prev;
        tmp->prev->next = nullptr;
        delete tmp;
        tmp = nullptr;
        return pos;
    }
    Node* tmp = pos._it;
    ++pos;
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    tmp->next = nullptr;
    tmp->prev = nullptr;
    delete tmp;
    tmp = nullptr;
    return pos;
}

template <typename T>
typename List<T>::iterator List<T>::erase(iterator first,iterator last)
{
    while(first != last)
    {
        first = this->erase(first);
    }
    return last;
}

template <typename T>
template <typename... Ts>
void List<T>::emplace_back(Ts&&... ts)
{
    if(this->empty())
    {
        m_head = new Node(nullptr,nullptr,(std::forward<Ts>(ts),...));
        m_tail = m_head;
    }else{
        m_tail->next = new Node(nullptr,m_tail,(std::forward<Ts>(ts),...));
        m_tail = m_tail->next;
    }
    return;
}

template <typename T>
template <typename... Ts>
void List<T>::emplace_front(Ts&&... ts)
{
    if(this->empty())
    {
        m_head = new Node(nullptr,nullptr,(std::forward<Ts>(ts),...));
        m_tail = m_head;
    }else{
        m_head->prev = new Node(m_head,nullptr,(std::forward<Ts>(ts),...));
        m_head = m_head->prev;
    }
    return;
}

template <typename T>
void List<T>::resize(size_t count)
{
    size_t tmp = count - this->size();
    while(tmp > 0)
    {
        this->push_back(T{});
        --tmp;
    }
    return;
}

template <typename T>
void List<T>::resize(size_t count,const T& val)
{
    size_t tmp = count - this->size();
    while(tmp > 0)
    {
        this->push_back(val);
        --tmp;
    }
    return ;
}

template <typename T>
void List<T>::merge(List<T>& oth)
{
    this->merge(oth,std::less<T>());
    return;
}

template <typename T>
void List<T>::merge(List<T>&& oth)
{
    this->merge(oth);
    return;
}

template <typename T>
template <class Compare>
void List<T>::merge(List<T>&& oth,Compare comp)
{
    this->merge(oth,comp);
    return;
}

template <typename T>
template <class Compare>
void List<T>::merge(List<T>& oth,Compare comp)
{
    if(this != &oth)
    {
        if(this->m_head == nullptr)
        {
            m_head = oth.m_head;
            m_tail = oth.m_tail;
            oth.m_head = nullptr;
            oth.m_tail = nullptr;
            return;
        }
        if(oth.m_head == nullptr)
        {
            return;
        }
        Node* m_tmp1 = m_head;
        Node* m_tmp2 = m_tail;
        Node* o_tmp1 = oth.m_head;
        Node* o_tmp2 = oth.m_tail;
        while(m_tmp1 != m_tmp2 && o_tmp1 != o_tmp2)
        {
            if(comp(m_tmp1->value,o_tmp1->value))
            {
                m_tmp1 = m_tmp1->next;
            }else
            {
                if(!m_tmp1->prev)
                {
                    m_head = o_tmp1;
                }
                m_tmp1->prev = o_tmp1;
                Node* tmp = o_tmp1;
                o_tmp1 = o_tmp1->next;
                tmp->next = m_tmp1;
                m_tmp1 = m_tmp1->next;
                
            }
        }
        while(o_tmp1)
        {
            m_tail->next = o_tmp1;
            o_tmp1->prev = m_tail;
            m_tail = m_tail->next;
            o_tmp1 = o_tmp1->next;
        }
        oth.m_head = nullptr;
        oth.m_tail = nullptr;
    }
    return;
}

template <typename T>
void List<T>::splice(iterator pos,List<T>& oth)
{
    if(pos == this->begin())
    {
        Node* tmp = m_head;
        m_head = oth.m_head;
        oth.m_tail->next = tmp;
        tmp->prev = oth.m_tail;
    }else if(pos == this->end())
    {
        Node* tmp = m_tail;
        m_tail = oth.m_tail;
        tmp->next = oth.m_head;
        oth.m_head->prev = tmp;
    }else
    {
        oth.m_head->prev = pos._it->prev;
        pos._it->prev->next = oth.m_head;
        pos._it->prev = oth.m_tail;
        oth.m_tail->next = pos._it;
        if(!pos._it->next)
        {
            m_tail = pos._it;
        }
    }
    oth.m_head = nullptr;
    oth.m_head = nullptr;
}

template <typename T>
void List<T>::splice(iterator pos,List<T>&& oth)
{
    this->splice(pos,oth);
    return;
}

