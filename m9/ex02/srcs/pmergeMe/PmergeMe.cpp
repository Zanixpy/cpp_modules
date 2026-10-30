#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _ftime(0), _stime(0) {}
PmergeMe::PmergeMe(PmergeMe const & other) : _ftime(other._ftime), _stime(other._stime) {}
PmergeMe::~PmergeMe() {}
PmergeMe& PmergeMe::operator=(PmergeMe const & other) {
    if (this != &other) {
        _ftime = other._ftime;
        _stime = other._stime;
    }
    return *this;
}

std::vector<int> PmergeMe::sortAndMeasureVec(std::vector<int> &vec) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    std::vector<int> sorted = mergeInsertionSort(vec);
    
    gettimeofday(&end, NULL);
    _ftime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    return sorted;
}

std::deque<int> PmergeMe::sortAndMeasureDeq(std::deque<int> &deq) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    std::deque<int> sorted = mergeInsertionSort(deq);
    
    gettimeofday(&end, NULL);
    _stime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    return sorted;
}

std::vector<size_t> PmergeMe::generateJacobsthal(size_t limit) const {
    std::vector<size_t> seq;
    seq.push_back(1);
    seq.push_back(3);
    
    while (true) {
        size_t next = seq.back() + 2 * seq[seq.size() - 2];
        seq.push_back(next);
        if (next >= limit) break;
    }
    return seq;
}

std::vector<int> PmergeMe::mergeInsertionSort(std::vector<int> &vec) 
{
    if (vec.size() <= 1) return vec;

    std::vector<int> main_chain, pending;
    int straggler = -1;
    bool has_straggler = (vec.size() % 2 != 0);
    
    if (has_straggler) 
        straggler = vec.back();

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < vec.size(); i += 2) 
    {
        if (vec[i] > vec[i+1]) pairs.push_back(std::make_pair(vec[i], vec[i+1]));
        else pairs.push_back(std::make_pair(vec[i+1], vec[i]));
    }

    std::vector<int> larger_elements;
    for (size_t i = 0; i < pairs.size(); ++i) 
        larger_elements.push_back(pairs[i].first);

    main_chain = mergeInsertionSort(larger_elements);

    for (size_t i = 0; i < main_chain.size(); ++i) 
    {
        for (size_t j = 0; j < pairs.size(); ++j) 
        {
            if (main_chain[i] == pairs[j].first) 
            {
                pending.push_back(pairs[j].second);
                break;
            }
        }
    }

    if (!pending.empty()) 
        main_chain.insert(main_chain.begin(), pending[0]);

    std::vector<size_t> jacob_seq = generateJacobsthal(pending.size());
    size_t inserted_count = 1;

    for (size_t j = 0; j < jacob_seq.size() && inserted_count < pending.size(); ++j) 
    {
        size_t end_idx = std::min(jacob_seq[j], pending.size() - 1);
        
        for (size_t i = end_idx; i >= inserted_count; --i) 
        {
            int val = pending[i];
            std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), val);
            main_chain.insert(pos, val);
        }
        inserted_count = end_idx + 1;
    }

    if (has_straggler) 
    {
        std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
        main_chain.insert(pos, straggler);
    }

    return main_chain;
}

std::deque<int> PmergeMe::mergeInsertionSort(std::deque<int> &deq) 
{
    if (deq.size() <= 1) 
        return deq;

    std::deque<int> main_chain, pending;
    int straggler = -1;
    bool has_straggler = (deq.size() % 2 != 0);
    
    if (has_straggler) straggler = deq.back();

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < deq.size(); i += 2) 
    {
        if (deq[i] > deq[i+1]) pairs.push_back(std::make_pair(deq[i], deq[i+1]));
        else pairs.push_back(std::make_pair(deq[i+1], deq[i]));
    }

    std::deque<int> larger_elements;
    for (size_t i = 0; i < pairs.size(); ++i) 
        larger_elements.push_back(pairs[i].first);

    main_chain = mergeInsertionSort(larger_elements);

    for (size_t i = 0; i < main_chain.size(); ++i) 
    {
        for (size_t j = 0; j < pairs.size(); ++j) 
        {
            if (main_chain[i] == pairs[j].first) 
            {
                pending.push_back(pairs[j].second);
                break;
            }
        }
    }

    if (!pending.empty()) 
        main_chain.insert(main_chain.begin(), pending[0]);

    std::vector<size_t> jacob_seq = generateJacobsthal(pending.size());
    size_t inserted_count = 1;

    for (size_t j = 0; j < jacob_seq.size() && inserted_count < pending.size(); ++j) 
    {
        size_t end_idx = std::min(jacob_seq[j], pending.size() - 1);
        
        for (size_t i = end_idx; i >= inserted_count; --i) 
        {
            int val = pending[i];
            std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), val);
            main_chain.insert(pos, val);
        }
        inserted_count = end_idx + 1;
    }

    if (has_straggler) 
    {
        std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
        main_chain.insert(pos, straggler);
    }

    return main_chain;
}

void PmergeMe::display(std::vector<int> &unsort_vec, std::vector<int> &sort_vec) const {
    std::cout << "Before: ";
    for (size_t i = 0; i < unsort_vec.size(); ++i) std::cout << unsort_vec[i] << " ";
    std::cout << "\nAfter: ";
    for (size_t i = 0; i < sort_vec.size(); ++i) std::cout << sort_vec[i] << " ";
    std::cout << "\nTime to process a range of " << unsort_vec.size() << " elements with std::vector : " << _ftime << " ms\n";
    std::cout << "Time to process a range of " << unsort_vec.size() << " elements with std::deque : " << _stime << " ms\n";
}

double PmergeMe::getFtime() const { return _ftime; }
double PmergeMe::getStime() const { return _stime; }