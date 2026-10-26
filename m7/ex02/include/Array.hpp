#ifndef  ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>
#include <string>

template< typename T> 
class Array
{
    private:
        T* m_data;
        unsigned int m_size;
    public:
        Array() : m_data(NULL), m_size(0) {};
        Array( unsigned int n ) : m_data(new T[n]), m_size(n) {};
        Array( Array const & other )
        {
            if (!other.m_data || other.m_size == 0)
            {
                m_data = NULL;
                m_size = 0;
            }
            else
            {
                m_size = other.m_size;
                m_data = new T[m_size];
                for (unsigned int i = 0; i < m_size; i++)
                    m_data[i] = other.m_data[i];
            }
        };
        Array& operator=( Array const & other )
        {
            if (this != &other)
            {
                delete[] m_data;
                if (!other.m_data || other.m_size == 0)
                {
                    m_data = NULL;
                    m_size = 0;
                }
                else
                {
                    m_size = other.m_size;
                    m_data = new T[m_size];
                    for (unsigned int i = 0; i < m_size; i++)
                        m_data[i] = other.m_data[i];
                }
            }
            return *this;
        };
        ~Array() {delete[] m_data;};
        T& operator[](unsigned int index)
        {
            if (index >= m_size)
                throw std::out_of_range("Index out of range");
            return m_data[index];
        };
        unsigned int size() const {return m_size;};
};

#endif
