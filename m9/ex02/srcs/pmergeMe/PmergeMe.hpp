#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <algorithm>
#include <limits>
#include <sstream>

class PmergeMe
{
    private:
        double _ftime;
        double _stime;
        std::vector<size_t> generateJacobsthal(size_t limit) const;

    public:
        PmergeMe();
        PmergeMe(PmergeMe const & other);
        PmergeMe& operator=(PmergeMe const & other);
        ~PmergeMe();

        std::vector<int> mergeInsertionSort(std::vector<int> &vec);
        std::deque<int> mergeInsertionSort(std::deque<int> &deq);

        std::vector<int> sortAndMeasureVec(std::vector<int> &vec);
        std::deque<int> sortAndMeasureDeq(std::deque<int> &deq);

        double getFtime() const;
        double getStime() const;
        void display(std::vector<int> &unsort_vec, std::vector<int> &sort_vec) const;
};

#endif