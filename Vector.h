#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <iostream>
#include <stdlib.h>
#include <stdexcept>

template <class T>
class Vector
{
public:
    Vector();
    Vector(int);
	Vector(const Vector&);
	Vector(Vector&&);
    ~Vector();
    
public:
    void push_back(const T&);
    void pop_back();
    int GetSize() const;
    const T& at(int);
    void Erase(int);
    T& operator[](int);
    Vector<T>& operator=(const Vector&);

private:
    void Resize();
private:
    T* m_arr;
    int m_capacity;
    int m_size;
};

#include "Vector.tpp"
#endif
