#include "String.h"

String::String() : m_capa{1}, m_size{},m_buf{}
{}

String::String(const char* arr)
{
    if(arr != nullptr)
    {
        m_size = strlen(arr);
        m_capa = m_size + 1;
        m_buf = new char[m_capa];
        for(int i = 0; i < m_capa; ++i)
        {
            m_buf[i] = arr[i];
        }
    }else
    {
        m_capa = 1;
        m_size = 0;
        m_buf = nullptr; 
    }
}

String::String(const String& oth)
{
    if(oth.m_buf != nullptr)
    {
        m_capa = oth.m_capa;
        m_size = oth.m_size;
        m_buf = new char[m_capa];
        for(int i = 0; i < m_capa; ++i)
        {
            m_buf[i] = oth.m_buf[i];
        }
    } else {
        m_capa = 1;
        m_size = 0;
        m_buf = nullptr;
    }
}

String::String(String&& tmp)
{
    if(tmp.m_buf != nullptr)
    {
        m_capa = tmp.m_capa;
        m_size = tmp.m_size;
        m_buf = tmp.m_buf;
        tmp.m_capa = 0;
        tmp.m_size = 0;
        tmp.m_buf = nullptr;
    } else {
        m_capa = 1;
        m_size = 0;
        m_buf = nullptr;
    }
}

String::~String()
{
    if(m_buf != nullptr)
    {
        delete[] m_buf;
    }
}

String& String::operator=(const String& rhs)
{
    if(this == &rhs)
    {
        return *this;
    } else if(m_buf)
    {
        delete[] m_buf;
    }
    m_capa = rhs.m_capa;
    m_size = rhs.m_size;
    m_buf = new char[m_capa];
    for(int i = 0; i < m_size; ++i)
    {
        m_buf[i] = rhs.m_buf[i];
    }
    m_buf[m_size] = '\0';
    return *this;
}

String& String::operator=(String&& tmp)
{
    if(m_buf)
    {
        delete[] m_buf;
    }
    m_capa = tmp.m_capa;
    m_size = tmp.m_size;
    m_buf = tmp.m_buf;
    tmp.m_capa = 0;
    tmp.m_size = 0;
    tmp.m_buf = nullptr;
    return *this;
}

String String::operator+(const String& rhs)
{
    String tmp(*this);
    for(int i = 0;i < rhs.m_size; ++i)
    {
        tmp.push_back(rhs.m_buf[i]);
    }
    return tmp;
}

char& String::operator[](unsigned pos)
{
    return m_buf[pos];
}

const char& String::operator[](unsigned pos) const
{
    return m_buf[pos];
}

void String::push_back(char ch)
{
    if(!m_buf)
    {
        m_buf = new char[m_capa];
    }else if(m_capa == m_size){
        m_capa *= 2;
        char* ptr = new char[m_capa];
        for(int i = 0; i < m_size; ++i)
        {
            ptr[i] = m_buf[i];
        }
        delete[] m_buf;
        m_buf = ptr;
        ptr = nullptr;
    }
    m_buf[m_size] = ch;
    ++m_size;
    m_buf[m_size] = '\0';
}

void String::pop_back()
{
    if(m_buf)
    {
        --m_size;
        m_buf[m_size] = '\0';
    }
}

char& String::at(unsigned pos)
{
    return pos > m_size ? throw std::out_of_range("") : m_buf[pos] ;
}

const char& String::at(unsigned pos) const 
{
    return pos > m_size ? throw std::out_of_range("") : m_buf[pos] ;
}

void String::insert(unsigned pos,char ch)
{
    if(pos > m_size || m_size == 0)
    {
        throw std::out_of_range("");
        return;
    }else if(m_size == m_capa)
    {
        m_capa *= 2;
        char* ptr = new char[m_capa];
        for(int i = 0; i < pos; ++i)
        {
            ptr[i] = m_buf[i];
        }
        ptr[pos] = ch;
        for(int i = pos + 1; i < m_size; ++i)
        {
            ptr[i + 1] = m_buf[i];
        }
        delete[] m_buf;
        m_buf = ptr;
        ptr = nullptr;
    } else {
        for(int i = m_size; i < pos; --i)
        {
            m_buf[i] = m_buf[i - 1];
        }
        m_buf[pos] = ch;
    }
    ++m_size;
    m_buf[m_size] = '\0';
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
    for(int i = 0; i <= str.m_size; ++i)
    {
        os << str[i];
    }
    return os;
}

unsigned String::size() const 
{
    return m_size;
}

unsigned String::length() const
{
    return m_size;
}
