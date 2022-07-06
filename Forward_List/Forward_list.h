#ifndef _FORWARD_LIST_H_
#define _FORWARD_LIST_H_

#include <iostream>
#include <iterator>
#include <utility>
#include <initializer_list>

template <typename T>
class Forward_list
{
    struct Node
    {
        Node(const T&,Node* nextt = nullptr);
        Node(T&&,Node* nextt = nullptr);

        T value;
        Node* next;
    };
    public:
    class iterator : public std::iterator<std::forward_iterator_tag,T>
    {
        public:
            iterator();
            iterator(const iterator&);
            iterator(Node*);

            iterator& operator=(const iterator&);
            
            iterator& operator++();
            iterator operator++(int);

            T& operator*();
            const T& operator*() const;
            T* operator->();
            const T* operator->() const;

            bool operator==(const iterator&) const;
            bool operator!=(const iterator&) const;
            
            friend class Forward_list<T>;
        private:
            Node* m_it;
    };

    class const_iterator : public std::iterator<std::forward_iterator_tag,T>
    {
        public:
            const_iterator();
            const_iterator(const const_iterator&);
            const_iterator(const Node*);

            const_iterator& operator=(const const_iterator&);

            const T& operator*() const;
            const T* operator->() const;

            bool operator==(const const_iterator&) const;
            bool operator!=(const const_iterator&) const;

            friend class Forward_list<T>;
        private:
            const Node* m_it;
    };

        using value_type = T;
        using reference = value_type&;
        using const_reference = const value_type&;

        Forward_list();
        Forward_list(const Forward_list&);
        Forward_list(Forward_list&&);
        Forward_list(std::initializer_list<T>);
        template <typename Iter>
        Forward_list(Iter,Iter);
        explicit Forward_list(size_t);
        Forward_list(size_t,const T&);
        ~Forward_list();

        Forward_list& operator=(const Forward_list&);
        Forward_list& operator=(Forward_list&&);
        Forward_list& operator=(std::initializer_list<T>);

        void assign(size_t,const T&);
        template <typename Iter>
        void assign(Iter,Iter);
        
        T& front();
        const T& front() const;
        bool empty() const;

        iterator begin() const;
        iterator end() const;

        void clear();
        iterator insert_after(iterator,const T&);
        iterator insert_after(iterator,T&&);
        iterator insert_after(iterator,size_t,const T&);
        iterator insert_after(iterator,std::initializer_list<T>);
        template <typename Iter>
        iterator insert_after(iterator,Iter,Iter);
        template <typename... Ts>
        iterator emplace_after(iterator,Ts&&...);
        iterator erase_after(iterator);
        iterator erase_after(iterator,iterator);
        void push_front(const T&);
        void push_front(T&&);
        template <typename... Ts>
        void emplace_front(Ts&&...);
        void pop_front();
        void resize(size_t);
        void resize(size_t,const T&);
        void swap(Forward_list&);

        void merge(Forward_list&);
        void merge(Forward_list&& oth)
        {
            this->merge(oth);
        }
        void remove(const T&);
        void reverse();
        void unique();
        void sort();

    private:
        Node* m_head;
};

template <typename T>
bool operator==(const Forward_list<T>&,const Forward_list<T>&);
template <typename T>
bool operator!=(const Forward_list<T>&,const Forward_list<T>&);
template <typename T>
bool operator<=(const Forward_list<T>&,const Forward_list<T>&);
template <typename T>
bool operator>=(const Forward_list<T>&,const Forward_list<T>&);
template <typename T>
bool operator<(const Forward_list<T>&,const Forward_list<T>&);
template <typename T>
bool operator>(const Forward_list<T>&,const Forward_list<T>&);

#include "Forward_list.hpp"

#endif // _FORWARD_LIST_H_
