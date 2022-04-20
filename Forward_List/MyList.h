#ifndef _MyList_
#define _MyList_

#include <initializer_list>
#include <exception>

template <typename T>
class Forward_List
{
    public:
        Forward_List();
        Forward_List(const Forward_List<T>&);
        Forward_List(Forward_List<T>&&);
        Forward_List(unsigned ,const T&);
        Forward_List(unsigned);
        Forward_List(std::initializer_list<T>);
        ~Forward_List();

    public:
        Forward_List& operator=(const Forward_List<T>&);
        Forward_List& operator=(Forward_List<T>&&);
        T& front();
        const T& front() const;
        bool empty() const;
        void push_front(const T&);
        void push_front(T&&);
        void pop_front();
        void clear();
//        void reverse();

    private:
        struct List_Node
        {
            T value;
            List_Node* next;

            List_Node();
            List_Node(const T&,List_Node* ptr = nullptr);
        }*_head;

    public:
        class iterator
        {
            public:
                iterator();
                iterator(const Forward_List<T>::iterator&);
                iterator(List_Node* ptr) : _it{ptr} {};
                ~iterator();

            public:
                Forward_List<T>::iterator operator++(int);
                Forward_List<T>::iterator& operator++();

                bool operator==(const Forward_List<T>::iterator&) const;
                bool operator!=(const Forward_List<T>::iterator&) const;

                T& operator*();
                const T& operator*() const;
                T* operator->();
                const T* operator->() const;
                
                friend iterator Forward_List<T>::insert_after(Forward_List<T>::iterator,const T&);
                friend void Forward_List<T>::splice_after(iterator,Forward_List<T>&);

            private:
                List_Node* _it;
        };
        
        void splice_after(iterator,Forward_List<T>&);
        iterator insert_after(iterator,const T&);
        iterator begin() const;
        iterator end() const;
};

#include "MyList.hpp"

#endif // _MyList_
