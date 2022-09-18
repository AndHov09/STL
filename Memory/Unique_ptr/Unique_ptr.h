#ifndef _UNIQUE_PTR_H_
#define _UNIQUE_PTR_H_

#include <cstddef>

template <typename T>
class Unique_ptr
{
    public:
        Unique_ptr();
        Unique_ptr(std::nullptr_t);
        Unique_ptr(const Unique_ptr&) = delete;
        Unique_ptr(Unique_ptr&&);
        explicit Unique_ptr(T*);
        template <typename U>
        Unique_ptr(Unique_ptr<U>&&);
        ~Unique_ptr();
    public:
        Unique_ptr& operator=(const Unique_ptr) = delete;
        Unique_ptr& operator=(Unique_ptr&&);
        Unique_ptr& operator=(std::nullptr_t);
        template <typename U>
        Unique_ptr& operator=(Unique_ptr<U>&&);
    public:
        T* release();
        void reset(T* ptr = nullptr);
        void swap(Unique_ptr&);
        T* get();
        const T* get() const;
        operator bool() const;
        T& operator*();
        const T& operator*() const;
        T* operator->();
        const T* operator->() const;
    private:
        T* m_ptr;
};

template <typename T>
class Unique_ptr<T[]>
{
    public:
        Unique_ptr();
        Unique_ptr(std::nullptr_t);
        Unique_ptr(const Unique_ptr&) = delete;
        Unique_ptr(Unique_ptr&&);
        template <typename U>
        explicit Unique_ptr(U);
        ~Unique_ptr();
    public:
        Unique_ptr& operator=(const Unique_ptr) = delete;
        Unique_ptr& operator=(Unique_ptr&&);
        Unique_ptr& operator=(std::nullptr_t);
        template <typename U>
        Unique_ptr& operator=(Unique_ptr<U>&&);
    public:
        T* release();
        void reset(std::nullptr_t ptr = nullptr);
        template <typename U>
        void reset(U);
        void swap(Unique_ptr&);
        T* get();
        const T* get() const;
        operator bool() const;
        T& operator[](std::size_t);
        const T& operator[](std::size_t) const;
    private:
        T* m_ptr;
};

#include "Unique_ptr.hpp"

#endif /* _UNIQUE_PTR_H_ */
