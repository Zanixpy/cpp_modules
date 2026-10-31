// main.cpp
#include "pmergeMe/PmergeMe.hpp"

static bool isPositiveInt(std::string const &s) 
{
    if (s.empty())
        return false; 
    std::size_t i = 0;

    while (std::isspace(s[i])) 
        i++;

    if (s[i] == '+')
        ++i;
    if (i == s.length())
        return false;

    for (; i < s.length(); ++i) 
    {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
    }

    std::stringstream ss(s);
    double d;

    ss >> d; 
    if (ss.fail())
        return false;
    if (d > static_cast<double>(std::numeric_limits<int>::max())) 
        return false;
    return true;
}


int main(int ac, char ** av) 
{
    if (ac < 3)
    {
        std::cerr << "Usage: ./PmergeMe [int1] [int2] ...\n";
        return 1;
    }

    std::vector<int> vec;
    std::deque<int>  deq;

    for (int i = 1; av[i]; i++) 
    {
        if (isPositiveInt(av[i]) == false)
        {
            std::cerr << "Error: not a positive integer/overflow\n";
            return 1;
        }
        vec.push_back(atoi(av[i]));
        deq.push_back(atoi(av[i]));
    }

    PmergeMe test;
    std::vector<int> sort_vec = test.sortAndMeasureVec(vec);
    std::deque<int>  sort_deq = test.sortAndMeasureDeq(deq);
    test.display(vec, sort_vec);
    return 0;
}
