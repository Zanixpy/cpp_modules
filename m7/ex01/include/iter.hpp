#ifndef  ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template< typename T, typename Func> 
void iter(T* array,  std::size_t const length, Func f)
{
    for (std::size_t i = 0; i < length; i++)
        f(array[i]);
}

#endif
