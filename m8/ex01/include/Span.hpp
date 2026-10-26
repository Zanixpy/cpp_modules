#ifndef  SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <exception>
#include <cstdlib>

class Span
{
    private:
        std::vector<int> m_storage;
        unsigned int m_max_n;
    public:
        Span( unsigned int N );
        Span( Span const & other );
        Span& operator=( Span const & other );
        ~Span();
        unsigned int shortestSpan();
        unsigned int longestSpan();
        void addNumber( unsigned int n);
        template <typename InputIt>
        void addNumbers(InputIt first, InputIt last)
        {
            unsigned int to_add = 0;
            for (InputIt it = first; it != last; ++it)
                to_add++;
            if (m_storage.size() + to_add > m_max_n)
                throw std::runtime_error("Span is full");
            m_storage.insert(m_storage.end(), first, last);
    }
};


#endif
