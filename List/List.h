#ifndef _LIST_
#define _LIST_

#include <iostream>
#include <exception>
#include <initializer_list>
#include <iterator>
#include <utility>
#include <functional>

template <typename T>
class List
{
    struct Node
    {
        Node(const T&,Node* nptr = nullptr,Node* pptr = nullptr);
        template <typename... Ts>
        Node(Node* nptr = nullptr,Node* pptr = nullptr,Ts&&...);
        Node(const Node&);
        Node(Node&&);

        T value;
        Node* next;
        Node* prev;
    };
    public:
        class iterator : public std::iterator<std::bidirectional_iterator_tag,T>
        {
            public:
                iterator();
                iterator(const iterator&);
                iterator(Node* ptr);

                iterator& operator=(const iterator&);

                bool operator==(const iterator&) const;
                bool operator!=(const iterator&) const;

                T& operator*();
                const T& operator*() const;
                T* operator->();
                const T* operator->() const;

                iterator& operator++();
                iterator operator++(int) &;
                iterator& operator--();
                iterator operator--(int) &;

            private:
                Node* _it;
                friend class List<T>;
        };

    public:
        List();
        List(const List&);
        List(List&&);
        List(size_t, const T&);
        List(size_t);
        List(std::initializer_list<T> init);
        template <typename InputIt>
        List(InputIt,InputIt);
        ~List();
    public:
        List& operator=(const List&);
        List& operator=(List&&);
    public:
        void assign(size_t,const T&);
        void assign(std::initializer_list<T>);
        template <typename InputIt>
        void assign(InputIt,InputIt);
        void swap(List&);

        T& front();
        const T& front() const;
        T& back();
        const T& back() const;

        iterator begin();
        iterator end();

        bool empty() const;
        size_t size() const;

        void clear();
        void push_back(const T&);
        void push_back(T&&);
        void pop_back();
        void push_front(const T&);
        void push_front(T&&);
        void pop_front();
        iterator insert(iterator,const T&);
        iterator insert(iterator,T&&);
        iterator insert(iterator,size_t,const T&);
        template <typename InputIt>
        iterator insert(iterator,InputIt,InputIt);
        iterator insert(iterator,std::initializer_list<T>);
        template <typename... Ts>
        iterator emplace(iterator,Ts&&...);
        iterator erase(iterator);
        iterator erase(iterator,iterator);
        template <typename... Ts>
        void emplace_back(Ts&&...);
        template <typename... Ts>
        void emplace_front(Ts&&...);

        void resize(size_t);
        void resize(size_t,const T&);

        void merge(List&);
        void merge(List&&);
        template <class Compare>
        void merge(List&,Compare);
        template <class Compare>
        void merge(List&&,Compare);

        void splice(iterator,List&);
        void splice(iterator,List&&);
        void splice(iterator,List&,iterator);
        void splice(iterator,List&&,iterator);
        void splice(iterator,List&,iterator,iterator);
        void splice(iterator,List&&,iterator,iterator);

        void remove(const T&);
        template <class Predicate>
        void remove_if(Predicate);
        void reverse();
        void unique();
        template <class Predicate>
        void unique(Predicate);
        void sort();
        template <class Predicate>
        void sort(Predicate);
    private:
        Node* m_head;
        Node* m_tail;
};

template <typename T>
bool operator==(const List<T>&,const List<T>&);
template <typename T>
bool operator!=(const List<T>&,const List<T>&);
template <typename T>
bool operator<=(const List<T>&,const List<T>&);
template <typename T>
bool operator>=(const List<T>&,const List<T>&);
template <typename T>
bool operator<(const List<T>&,const List<T>&);
template <typename T>
bool operator>(const List<T>&,const List<T>&);

#include "List.hpp"

#endif /* _LIST_ */
