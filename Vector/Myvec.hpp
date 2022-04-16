template <typename T>
MyVector<T>::MyVector() : m_capacity{1}, m_size{}, m_buffer{}
{}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& obj)
{
	if(!obj.empty()){
		m_capacity = obj.m_capacity;
		m_size = obj.m_size;
		copy(obj.m_buffer);
	}
}

template <typename T>
MyVector<T>::MyVector(MyVector<T>&& obj)
{
	m_capacity = obj.m_capacity;
	m_size = obj.m_size;
	m_buffer = obj.m_buffer;
	obj.m_capacity = 0;
	obj.m_size = 0;
	obj.m_buffer = nullptr;
}

template <typename T>
MyVector<T>::MyVector(unsigned capacity)
{
	m_capacity = capacity;
	m_size = 0;
	m_buffer = new T[m_capacity];

}

template <typename T>
MyVector<T>::MyVector(unsigned capacity,const T& value)
{
	m_capacity = capacity;
	m_size = m_capacity;
	m_buffer = new T[m_capacity];
	for (int i = 0; i < m_size; ++i)
	{
		m_buffer[i] = value;
	}
}

template <typename T>
MyVector<T>::MyVector(unsigned capacity,T&& value)
{
	m_capacity = capacity;
	m_size = m_capacity;
	m_buffer = new T[m_capacity];
	for (int i = 0; i < m_size; ++i)
	{
		m_buffer[i] = value;
	}
}

template <typename T>
MyVector<T>::MyVector(const std::initializer_list<T>& inlist)
{
	m_capacity = m_size = inlist.size();
	m_buffer = new T[m_capacity];
	int i = 0;
	for (const T& value : inlist)
	{
		m_buffer[i] = value;
		++i;
	}
}

template <typename T>
MyVector<T>::~MyVector()
{
	if (m_buffer != nullptr){
		delete[] m_buffer;
	}
}

template <typename T>
MyVector<T>& MyVector<T>::operator= (const MyVector<T>& obj)
{
	if(this != &obj)
	{
		if(!empty())
		{
			delete[] m_buffer;
		}
		m_size = obj.m_size;
		m_capacity = obj.m_capacity;
		copy(obj.m_buffer);
	}
	return *this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator= ( MyVector<T>&& obj )
{
	m_capacity = obj.m_capacity;
	m_size = obj.m_size;
	m_buffer = obj.m_buffer;
	obj.m_capacity = 0;
	obj.m_size = 0;
	obj.m_buffer = nullptr;
    return *this;
}

template <typename T>
T& MyVector<T>::operator[] (unsigned pos)
{
	return m_buffer[pos];
}

template <typename T>
const T& MyVector<T>::operator[] (unsigned pos) const
{
	return m_buffer[pos];
}

template <typename T>
void MyVector<T>::push_back(const T& value)
{
	if (empty())
	{
		m_buffer = new T[m_capacity];		
	}
	 else if(m_size == m_capacity)
	{
		m_capacity *= 2;
		T* ptr = new T[m_capacity];
		for (int i = 0; i < m_size; ++i)
		{
			ptr[i] = m_buffer[i];
		}
		delete[] m_buffer;
		m_buffer = ptr;
		ptr = nullptr;
	}
	m_buffer[m_size] = value;
	++m_size;
}

template <typename T>
void MyVector<T>::push_back(T&& value)
{
	if (empty())
	{
		m_buffer = new T[m_capacity];		
	}
	else if(m_size == m_capacity)
	{
		m_capacity *= 2;
		T* ptr = new T[m_capacity];
		for (int i = 0; i < m_size; ++i)
		{
			ptr[i] = m_buffer[i];
		}
		delete[] m_buffer;
		m_buffer = ptr;
		ptr = nullptr;
	}
	m_buffer[m_size] = value;
	++m_size;

}

template <typename T>
void MyVector<T>::pop_back()
{
	--m_size;
}

template <typename T>
void MyVector<T>::insert(unsigned pos,const T& value)
{
	if(pos >= m_size)
	{
		throw std::out_of_range("Error!");
	}
	else if (m_size == m_capacity)
	{
		m_capacity *= 2;
		T* ptr = new T[m_capacity];
		for (int i = 0; i < pos; ++i)
		{
			ptr[i] = m_buffer[i];
		}
		for (int i = m_size; i > pos; --i)
		{
			ptr[i] = m_buffer[i - 1];
		}
		ptr[pos] = value;
		delete[] m_buffer;
		m_buffer = ptr;
		ptr = nullptr;
		++m_size;
	}
	else
	{
		for(int i = m_size; i > pos; --i)
		{
			m_buffer[i] = m_buffer[i - 1];
		}
		m_buffer[pos] = value;
		++m_size;
	}
}

template <typename T>
void MyVector<T>::insert(unsigned pos,T&& value)
{
	if(pos >= m_size)
	{
		throw std::out_of_range("Error!");
	}
	else if (m_size == m_capacity)
	{
		m_capacity *= 2;
		T* ptr = new T[m_capacity];
		for (int i = 0; i < pos; ++i)
		{
			ptr[i] = m_buffer[i];
		}
		for (int i = m_size; i > pos; --i)
		{
			ptr[i] = m_buffer[i - 1];
		}
		ptr[pos] = value;
		delete[] m_buffer;
		m_buffer = ptr;
		ptr = nullptr;
		++m_size;
	}
	else
	{
		for(int i = m_size; i > pos; --i)
		{
			m_buffer[i] = m_buffer[i - 1];
		}
		m_buffer[pos] = value;
		++m_size;
	}
}

template <typename T>
void MyVector<T>::erase(unsigned pos)
{
	if (pos >= m_size)
	{
		throw std::out_of_range("Error!");
	}
	else
	{
		for (unsigned int i = pos; i < m_size - 1; ++i)
		{
			m_buffer[i] = m_buffer[i + 1];
		}
		--m_size;
	}
}

template <typename T>
bool MyVector<T>::empty() const 
{
	return !m_size;
}

template <typename T>
unsigned MyVector<T>::size() const
{
	return m_size;
}

template <typename T>
void MyVector<T>::clear()
{
	m_size = 0;
}

template <typename T>
T& MyVector<T>::at(unsigned pos)
{
	return pos < m_size ? m_buffer[pos] : throw std::out_of_range("");
}

template <typename T>
const T& MyVector<T>::at(unsigned pos) const
{
	return pos < m_size ? m_buffer[pos] : throw std::out_of_range("");
}

template <typename T>
void MyVector<T>::copy(T* ptr)
{
	m_buffer = new T[m_capacity];
	for (int i = 0; i < m_size; ++i)
	{
		m_buffer[i] = ptr[i];
	}
}

/* Iterator */
template <typename T>
MyVector<T>::iterator::iterator() : _it{}
{}

template <typename T>
MyVector<T>::iterator::iterator(const MyVector<T>::iterator& oth) : _it{oth._it}
{}

template <typename T>
MyVector<T>::iterator::iterator(T* ptr) : _it{ptr}
{}

template <typename T>
MyVector<T>::iterator::~iterator()
{}

template <typename T>
typename MyVector<T>::iterator& MyVector<T>::iterator::operator=(const MyVector<T>::iterator& oth) &
{
    this->_it = oth._it;
    return *this;
}

template <typename T>
bool MyVector<T>::iterator::operator==(const MyVector<T>::iterator& rhs) const
{
    return this->_it == rhs._it;
}

template <typename T>
bool MyVector<T>::iterator::operator!=(const MyVector<T>::iterator& rhs) const
{
    return !(*this == rhs);
}

template <typename T>
bool MyVector<T>::iterator::operator<=(const MyVector<T>::iterator& rhs) const
{
    return !(*this > rhs);
}

template <typename T>
bool MyVector<T>::iterator::operator>=(const MyVector<T>::iterator& rhs) const
{
    return !(*this < rhs);
}

template <typename T>
bool MyVector<T>::iterator::operator<(const MyVector<T>::iterator& rhs) const
{
    return this->_it < rhs._it;
}

template <typename T>
bool MyVector<T>::iterator::operator>(const MyVector<T>::iterator& rhs) const
{
    return this->_it > rhs._it;
}

template <typename T>
typename MyVector<T>::iterator MyVector<T>::iterator::operator++(int) &
{
    MyVector<T>::iterator tmp(*this);
    tmp += 1;
    return tmp;
}

template <typename T>
typename MyVector<T>::iterator& MyVector<T>::iterator::operator++() &
{
    return *this += 1;
}

template <typename T>
typename MyVector<T>::iterator MyVector<T>::iterator::operator--(int) &
{
    MyVector<T>::iterator tmp(*this);
    tmp -= 1;
    return tmp;
}


template <typename T>
typename MyVector<T>::iterator& MyVector<T>::iterator::operator--() &
{
    return *this -= 1;
}

template <typename T>
T& MyVector<T>::iterator::operator[](int _pos)
{
    return this->_it[_pos];
}

template <typename T>
const T& MyVector<T>::iterator::operator[](int _pos) const
{
    return this->_it[_pos];
}

template <typename T>
typename MyVector<T>::iterator& MyVector<T>::iterator::operator+=(int num) &
{
    this->_it += num;
    return *this;
}

template <typename T>
typename MyVector<T>::iterator& MyVector<T>::iterator::operator-=(int num) &
{
    this->_it -= num;
    return *this;
}

template <typename T>
T& MyVector<T>::iterator::operator*()
{
    return *this->_it;
}

template <typename T>
const T& MyVector<T>::iterator::operator*() const
{
    return *this->_it;
}

template <typename T>
T* MyVector<T>::iterator::operator->()
{
    return this->_it;
}

template <typename T>
const T* MyVector<T>::iterator::operator->() const 
{
    return this->_it;
}


template <typename T>
int MyVector<T>::iterator::operator-(const iterator& rhs) const 
{
    return this->_it - rhs._it;
}

template <typename T>
typename MyVector<T>::iterator MyVector<T>::iterator::operator+(int num) const
{
    MyVector<T>::iterator tmp(*this);
    tmp += num;
    return tmp;
}

template <typename T>
typename MyVector<T>::iterator MyVector<T>::iterator::operator-(int num) const
{
    MyVector<T>::iterator tmp(*this);
    tmp -= num;
    return tmp;
}

/* Iterator end */

template <typename T>
typename MyVector<T>::iterator MyVector<T>::begin() const
{
    MyVector<T>::iterator tmp(m_buffer);
    return tmp;
}

template <typename T>
typename MyVector<T>::iterator MyVector<T>::end() const
{
    MyVector<T>::iterator tmp(m_buffer + m_size);
    return tmp;
}
