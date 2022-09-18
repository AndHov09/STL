#ifndef _UNIQUE_PTR_HPP_
#define _UNIQUE_PTR_HPP_


template <typename T>
Unique_ptr<T>::Unique_ptr() : m_ptr{nullptr}
{}

template <typename T>
Unique_ptr<T>::Unique_ptr(std::nullptr_t) : m_ptr{nullptr}
{}

template <typename T>
Unique_ptr<T>::Unique_ptr(Unique_ptr<T>&& oth) : m_ptr{oth.m_ptr}
{
    oth.m_ptr = nullptr;
}

template <typename T>
Unique_ptr<T>::Unique_ptr(T* ptr) : m_ptr{ptr}
{}

template <typename T>
template <typename U>
Unique_ptr<T>::Unique_ptr(Unique_ptr<U>&& oth) : m_ptr(oth.m_ptr)
{
    oth.m_ptr = nullptr;
}

template <typename T>
Unique_ptr<T>::~Unique_ptr()
{
    if(m_ptr)
    {
        delete m_ptr;
        m_ptr = nullptr;
    }
}

template <typename T>
Unique_ptr<T>& Unique_ptr<T>::operator=(Unique_ptr<T>&& oth)
{
    std::swap(m_ptr, oth.m_ptr);
    return *this;
}

template <typename T>
Unique_ptr<T>& Unique_ptr<T>::operator=(std::nullptr_t)
{
    if(m_ptr)
    {
        delete m_ptr;
    }
    m_ptr = nullptr;
    return *this;
}

template <typename T>
template <typename U>
Unique_ptr<T>& Unique_ptr<T>::operator=(Unique_ptr<U>&& oth)
{
    std::swap(m_ptr,oth.m_ptr);
    return *this;
}

template <typename T>
T* Unique_ptr<T>::release()
{
    T* tmp = m_ptr;
    m_ptr = nullptr;
    return tmp;
}

template <typename T>
void Unique_ptr<T>::reset(T* ptr)
{
    if(m_ptr)
    {
        delete m_ptr;
    }
    m_ptr = ptr;
}

template <typename T>
void Unique_ptr<T>::swap(Unique_ptr<T>& oth)
{
    std::swap(m_ptr, oth.m_ptr);
}

template <typename T>
T* Unique_ptr<T>::get()
{
    return m_ptr;
}

template <typename T>
const T* Unique_ptr<T>::get() const
{
    return m_ptr;
}

template <typename T>
Unique_ptr<T>::operator bool() const
{
    return m_ptr;
}

template <typename T>
T& Unique_ptr<T>::operator*()
{
    return *m_ptr;
}

template <typename T>
const T& Unique_ptr<T>::operator*() const
{
    return *m_ptr;
}

template <typename T>
T* Unique_ptr<T>::operator->()
{
    return m_ptr;
}

template <typename T>
const T* Unique_ptr<T>::operator->() const
{
    return m_ptr;
}

template <typename T>
Unique_ptr<T[]>::Unique_ptr() : m_ptr{}
{}

template <typename T>
Unique_ptr<T[]>::Unique_ptr(std::nullptr_t) : m_ptr{}
{}

template <typename T>
Unique_ptr<T[]>::Unique_ptr(Unique_ptr<T[]>&& oth) : m_ptr{oth.m_ptr}
{
    oth.m_ptr = nullptr;
}

template <typename T>
template <typename U>
Unique_ptr<T[]>::Unique_ptr(U ptr) : m_ptr(ptr)
{}

template <typename T>
Unique_ptr<T[]>::~Unique_ptr()
{
    if (m_ptr)
    {
        delete[] m_ptr;
        m_ptr = nullptr;
    }
}

template <typename T>
Unique_ptr<T[]>& Unique_ptr<T[]>::operator=(Unique_ptr<T[]>&& oth)
{
    std::swap(m_ptr, oth.m_ptr); 
    return *this;
}

template <typename T>
Unique_ptr<T[]>& Unique_ptr<T[]>::operator=(std::nullptr_t)
{
    if(m_ptr)
    {
        delete[] m_ptr;
        m_ptr = nullptr;
    }
    return *this;
}

template <typename T>
template <typename U>
Unique_ptr<T[]>& Unique_ptr<T[]>::operator=(Unique_ptr<U>&& oth)
{
    std::swap(m_ptr, oth.m_ptr);
    return *this;
}

template <typename T>
T* Unique_ptr<T[]>::release()
{
    T* ptr= m_ptr;
    m_ptr = nullptr;
    return ptr;
}

template <typename T>
void Unique_ptr<T[]>::reset(std::nullptr_t ptr)
{
    if(m_ptr)
    {
        delete[] m_ptr;
    }
    m_ptr = ptr;
}

template <typename T>
template <typename U>
void Unique_ptr<T[]>::reset(U ptr)
{
    if(m_ptr)
    {
        delete[] m_ptr;
    }
    m_ptr = ptr;
}

template <typename T>
void Unique_ptr<T[]>::swap(Unique_ptr<T[]>& oth)
{
    std::swap(m_ptr, oth.m_ptr);
}

template <typename T>
T* Unique_ptr<T[]>::get()
{
    return m_ptr;
}

template <typename T>
const T* Unique_ptr<T[]>::get() const
{
    return m_ptr;
}

template <typename T>
Unique_ptr<T[]>::operator bool() const
{
    return m_ptr;
}

template <typename T>
T& Unique_ptr<T[]>::operator[](std::size_t index)
{
    return m_ptr[index];
}

template <typename T>
const T& Unique_ptr<T[]>::operator[](std::size_t index) const
{
    return m_ptr[index];
}

#endif /* _UNIQUE_PTR_HPP_ */
