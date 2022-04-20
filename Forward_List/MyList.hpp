#include "MyList.h"

// Node Ctors
template <typename T>
Forward_List<T>::List_Node::List_Node() : value{} , next{}
{}

template <typename T>
Forward_List<T>::List_Node::List_Node(const T& ob,List_Node* ptr) : value{ob}, next{ptr}
{}

// End Node Ctors

// iterator 
template <typename T>
Forward_List<T>::iterator::iterator() : _it{}
{}

template <typename T>
Forward_List<T>::iterator::iterator(const Forward_List<T>::iterator& oth) : _it{oth._it}
{}

template <typename T>
Forward_List<T>::iterator::~iterator()
{}

template <typename T>
typename Forward_List<T>::iterator Forward_List<T>::iterator::operator++(int)
{
    Forward_List<T>::iterator tmp(*this);
    ++*this;
    return tmp;
}

template <typename T>
typename Forward_List<T>::iterator& Forward_List<T>::iterator::operator++()
{
    this->_it = this->_it->next;
    return *this;
}

template <typename T>
bool Forward_List<T>::iterator::operator==(const Forward_List<T>::iterator& rhs) const
{
    return _it == rhs._it;
}

template <typename T>
bool Forward_List<T>::iterator::operator!=(const Forward_List<T>::iterator& rhs) const
{
    return _it != rhs._it;
}

template <typename T>
T& Forward_List<T>::iterator::operator*()
{
    return _it->value;
}

template <typename T>
const T& Forward_List<T>::iterator::operator*() const
{
    return _it->value;
}

template <typename T>
T* Forward_List<T>::iterator::operator->()
{
    return &_it->value;
}

template <typename T>
const T* Forward_List<T>::iterator::operator->() const
{
    return &_it->value;
}
// End iterators

template <typename T>
Forward_List<T>::Forward_List() : _head{}
{}

template <typename T>
Forward_List<T>::Forward_List(const Forward_List<T>& oth) : _head{}
{
    if (!oth.empty())
    {
        List_Node* ptr = oth._head;
        _head = new List_Node (ptr->value);
        ptr = ptr->next;
        List_Node* ptr1 = _head;
        while(ptr)
        {
            ptr1->next = new List_Node(ptr->value);
            ptr = ptr->next;
            ptr1 = ptr1->next;
        }
    }
}

template <typename T>
Forward_List<T>::Forward_List(Forward_List<T>&& tmp) : _head{}
{
    if (!tmp.empty())
    {
        _head = tmp._head;
        tmp._head = nullptr;
    }
}

template <typename T>
Forward_List<T>::Forward_List(unsigned count,const T& value) : _head{}
{
    _head = new List_Node(value);
    List_Node* ptr = _head;
    --count;
    while(count)
    {
        ptr->next = new List_Node(value);
        ptr = ptr->next;
        --count;
    }
}

template <typename T>
Forward_List<T>::Forward_List(unsigned  count) : _head{}
{
    _head = new List_Node();
    List_Node* ptr = _head;
    --count;
    while(count)
    {
        ptr->next = new List_Node();
        ptr = ptr->next;
        --count;
    }
}

template <typename T>
Forward_List<T>::Forward_List(std::initializer_list<T> init) : _head{}
{
    _head = new List_Node(*init.begin());
    List_Node* ptr = _head;
    const T* it = init.begin() + 1;
    for(; it != init.end(); ++it)
    {
        ptr->next = new List_Node(*it);
        ptr = ptr->next;
    }
}

template <typename T>
Forward_List<T>::~Forward_List()
{
    this->clear();
}

template <typename T>
void Forward_List<T>::clear()
{
    while (_head)
    {
        List_Node* care = _head->next;
        delete _head;
        _head = care;
    }
}

template <typename T>
Forward_List<T>& Forward_List<T>::operator=(const Forward_List<T>& rhs)
{
    if(this != &rhs)
    {
        this->clear();
        if (rhs.empty())
        {
           return *this; 
        }
        List_Node* ptr = rhs._head;
        _head = new List_Node(ptr->value);
        List_Node* ptr1 = _head;
        ptr = ptr->next;
        while(ptr)
        {
            ptr1->next = new List_Node(ptr->value);
            ptr1 = ptr1->next;
            ptr = ptr->next;
        }
    }

    return *this;
}

template <typename T>
Forward_List<T>& Forward_List<T>::operator=(Forward_List<T>&& tmp)
{
    if(this != &tmp)
    {
        this->clear();
        _head = tmp._head;
        tmp._head = nullptr;
    }
    return *this;
}

template <typename T>
T& Forward_List<T>::front()
{
    return *(this->begin());
}

template <typename T>
const T& Forward_List<T>::front() const 
{
    return *(this->begin());
}

template <typename T>
bool Forward_List<T>::empty() const
{
    return this->begin() == this->end();
}

template <typename T>
void Forward_List<T>::push_front(const T& val)
{
    if(this->empty())
    {
        _head = new List_Node(val);
    }else {
        _head = new List_Node(val,_head);
    }
}

template <typename T>
void Forward_List<T>::push_front(T&& val)
{
    if(this->empty())
    {
        _head = new List_Node(val);
    }else {
        _head = new List_Node(val,_head);
    }
}

template <typename T>
void Forward_List<T>::splice_after(Forward_List<T>::iterator _pos,Forward_List<T>& oth)
{
    Forward_List<T>::iterator tmp = _pos._it->next;
    _pos._it->next = oth._head;
    oth._head = nullptr;
    while(_pos._it->next)
    {
        ++_pos;
    }
    _pos._it->next = tmp._it;
}


template <typename T>
typename Forward_List<T>::iterator Forward_List<T>::insert_after(Forward_List<T>::iterator _pos,const T& value)
{
    _pos._it->next = new List_Node(value,_pos._it->next);
    return ++_pos;
}

template <typename T>
typename Forward_List<T>::iterator Forward_List<T>::begin() const
{
    Forward_List<T>::iterator it(_head);
    return it;
}

template <typename T>
typename Forward_List<T>::iterator Forward_List<T>::end() const 
{
    List_Node* ptr = _head;
    while(ptr)
    {
        ptr = ptr->next;
    }
    Forward_List<T>::iterator it(ptr);
    return it;
}

template <typename T>
void Forward_List<T>::pop_front()
{
    if(!this->empty())
    {
        List_Node* ptr = _head;
        _head = _head->next;
        delete ptr;
    }
}
