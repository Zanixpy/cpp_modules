#include "../include/Span.hpp"

int main()
{
    std::cout << "=== Basic tests ===" << std::endl;

    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span:  " << sp.longestSpan() << std::endl;
    try {
        sp.addNumber(42);
    }
    catch (std::exception const &e) {
        std::cout << "Expected exception : " << e.what() << std::endl;
    }

    try {
        Span s2(1);
        s2.addNumber(10);
        std::cout << "Shortest span: " << s2.shortestSpan() << std::endl;
    }
    catch (std::exception const &e) {
        std::cout << "Expected exception : " << e.what() << std::endl;
    }

    std::cout << "\n=== Range / iterator tests ===" << std::endl;

    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
        vec.push_back(i * 2);

    Span sp2(10);

    try {
        sp2.addNumbers(vec.begin(), vec.end());
        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp2.longestSpan() << std::endl;
    }
    catch (std::exception const &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Big test (10 000 numbers) ===" << std::endl;

    const unsigned int N = 10000;
    Span sp3(N);

    std::vector<int> bigVec;
    bigVec.reserve(N);
    for (unsigned int i = 0; i < N; i++)
        bigVec.push_back(i);

    try {
        sp3.addNumbers(bigVec.begin(), bigVec.end());
        std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp3.longestSpan() << std::endl;
    }
    catch (std::exception const &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
