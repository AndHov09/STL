#ifndef _String_
#define _String_

#include <cstring>
#include <stdexcept>
#include <iostream>

class String
{
private:
    unsigned m_capa;
    unsigned m_size;
    char* m_buf;

public:
    String();
    String(char const*);
    String(const String&);
    String(String&&);
    ~String();

public:
    String& operator=(const String&);
    String& operator=(String&&);
    String operator+(const String&);
    char& operator[](unsigned);
    const char& operator[](unsigned) const;
    friend std::ostream& operator<<(std::ostream&, const String&);

public:
    unsigned size() const;
    unsigned length() const;
    void push_back(char);
    void pop_back();
    void insert(unsigned,char);
    char& at(unsigned);
    const char& at(unsigned) const;
};

#endif /*_String_*/
