#ifndef _MyVec_
#define _MyVec_

#include <initializer_list>
#include <exception>

template <typename T>
class MyVector
{
    private:

        unsigned m_capacity;
        unsigned m_size;
        T* m_buffer;

    public:

        MyVector();
        MyVector(const MyVector<T>&);
        MyVector(MyVector<T>&&);
        MyVector(unsigned);
        MyVector(unsigned,const T&);
        MyVector(unsigned,T&&);
        MyVector(const std::initializer_list<T>&);
        ~MyVector();
    public:

        MyVector<T>& operator=(const MyVector<T>&);
        MyVector<T>& operator=(MyVector<T>&&);
        T& operator[](unsigned);
        const T& operator[](unsigned) const;	

    public:

        void push_back(const T&);
        void push_back(T&&);
        void pop_back();
        void insert(unsigned,const T&);
        void insert(unsigned,T&&);
        void erase(unsigned);
        bool empty() const;
        unsigned size() const;
        void clear();
        T& at(unsigned);
        const T& at(unsigned) const;

    public:

        class iterator
        {
            public:
                iterator();
                iterator(const iterator&);
                iterator(T*);
                ~iterator();

            public:
                iterator& operator=(const iterator&) &;
                bool operator==(const iterator&) const;
                bool operator!=(const iterator&) const;
                bool operator<=(const iterator&) const;
                bool operator>=(const iterator&) const;
                bool operator<(const iterator&) const;
                bool operator>(const iterator&) const;
                iterator operator++(int) &;
                iterator& operator++() &;
                iterator operator--(int) &;
                iterator& operator--() &;
                T& operator[](int);
                const T& operator[](int) const;
                iterator& operator+=(int) &;
                iterator& operator-=(int) &;
                T& operator*();
                const T& operator*() const;
                T* operator->();
                const T* operator->() const;
                int operator-(const iterator&) const;
                iterator operator+(int) const;
                iterator operator-(int) const;               
                friend iterator operator+(int x,iterator y)
                {
                    iterator tmp(y);
                    tmp += x;
                    return tmp;
                }

                friend iterator operator-(int x,iterator y)
                {
                    iterator tmp(y);
                    tmp -= x;
                    return tmp;
                }
            private:
                T* _it;
        };

        iterator begin() const;
        iterator end() const;

    private:
        void copy(T*);
};


#include "Myvec.hpp"

#endif /* _MyVec_ */
