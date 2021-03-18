template <class T>
Vector<T>::Vector()
	: m_capacity{2}
	, m_size{0}
{
    m_arr = new T[m_capacity];
}

template <class T>
Vector<T>::Vector(int capacity)
{
    m_capacity = capacity;
    m_size = 0;
    m_arr = new T[m_capacity];
}

template <class T>
Vector<T>::Vector(const Vector& other)
{
	this->m_size = other.m_size;
	this->m_capacity = other.m_capacity;
	this->m_arr = new T[other.m_capacity];
	for(int i = 0; i < other.m_size; ++i)
	{
		this->m_arr[i] = other.m_arr[i];
	}
}

template <class T>
Vector<T>::Vector(Vector&& other)
{
	this->m_size = other.m_size;
	this->m_capacity = other.m_capacity;
	for(int i = 0; i < other.m_size; ++i)
	{
		this->m_arr[i] = other.m_arr[i];
	}
	other.m_size = 0;
	other.m_capacity = 0;
	delete[] other.m_arr;	
}


template <class T>
Vector<T>::~Vector()
{
    delete [] m_arr;
}

template <class T>
void Vector<T>::push_back(const T& value)
{
    if(m_size == m_capacity)
    {
        Resize();
    }
    m_arr[m_size++] = value;
}

template <class T>
void Vector<T>::pop_back()
{
    --m_size;
}

template <class T>
int Vector<T>::GetSize() const
{
    return m_size;
}

template <class T>
void Vector<T>::Resize()
{
    m_capacity *= 2;
    T* tmp = new(std::nothrow) T[m_capacity];
    if(tmp == nullptr)
    {
        std::cout << "Failed!\n";
    }
    else
    {
        for(int i = 0; i < m_size; ++i)
        {
            tmp[i] = m_arr[i];
        }
        for(int i = m_size; i < m_capacity; ++i)
        {
            tmp[i] = ' ';
        }
        delete [] m_arr;
        m_arr = tmp;
    }
}
template <class T>
void Vector<T>::Erase(int index)
{
    for(int i = index; i < m_size; ++i)
    {
        m_arr[i] = m_arr[i + 1];
        --m_size;
    }
}
template <class T>
const T& Vector<T>::at(int index)
{
    if((index < m_size) && (index >= 0))
    {
        return m_arr[index];
    }
    throw std::out_of_range("terminating with uncaught exception of type std::out_of_range: vector");
    
}

template <class T>
T& Vector<T>::operator[](int index)
{
    return m_arr[index];
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
	delete[] m_arr;
	if(this == &other) { return *this; }
   	this->m_size = other.m_size;
	this->m_capacity = other.m_capacity;
    this->m_arr = new T[other.m_capacity];
    
    for(int i = 0; i < other.m_size; ++i)
    {
        this->m_arr[i] = other.m_arr[i];
    }
	return *this;
}








