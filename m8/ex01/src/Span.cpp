#include "../include/Span.hpp"

Span::Span( unsigned int N ) : m_max_n(N) {}

Span::Span( Span const & other ) 
{
    m_max_n = other.m_max_n;
    for (unsigned int i = 0; i < m_max_n; i++)
        m_storage.insert(m_storage.begin() + i, other.m_storage[i]);
}

Span& Span::operator=( Span const & other )
{
    if (this != &other)
    {
        while (!m_storage.empty())
            m_storage.pop_back();
        m_max_n = other.m_max_n;
        for (unsigned int i = 0; i < m_max_n; i++)
            m_storage.insert(m_storage.begin() + i, other.m_storage[i]);         
    }
    return *this;
}

Span::~Span()
{
    while (!m_storage.empty())
            m_storage.pop_back();    
}

void Span::addNumber( unsigned int n )
{
    if (m_storage.size() == m_max_n)
        throw std::runtime_error("Array is full");
    m_storage.push_back(n);
}

unsigned int Span::shortestSpan()
{
    if (m_storage.size() < 2)
        throw std::runtime_error("Not enough numbers");
    unsigned int nb = 0;
    unsigned int shortest_span = 0;
    if (m_storage[0] > m_storage[1])
        shortest_span = m_storage[0] - m_storage[1];
    else
        shortest_span = m_storage[1] - m_storage[0];
    for (size_t i = 0; i < m_storage.size(); i++)
    {
        for (size_t j = i + 1; j < m_storage.size(); j++)
        {
            if (m_storage[i] > m_storage[j]) 
                nb = m_storage[i] - m_storage[j];
            else
                nb = m_storage[j] - m_storage[i];
            if (nb < shortest_span)
                shortest_span = nb;
        }        
    }
    return shortest_span;
}

unsigned int Span::longestSpan()
{
    if (m_storage.size() < 2)
        throw std::runtime_error("Not enough numbers");
    unsigned int nb = 0;
    unsigned int longest_span = 0;
    if (m_storage[0] > m_storage[1])
        longest_span = m_storage[0] - m_storage[1];
    else
        longest_span = m_storage[1] - m_storage[0];
    for (size_t i = 0; i < m_storage.size(); i++)
    {
        for (size_t j = i + 1; j < m_storage.size(); j++)
        {
            if (m_storage[i] > m_storage[j]) 
                nb = m_storage[i] - m_storage[j];
            else
                nb = m_storage[j] - m_storage[i];
            if (nb > longest_span)
                longest_span = nb;
        }        
    }
    return longest_span;
}

