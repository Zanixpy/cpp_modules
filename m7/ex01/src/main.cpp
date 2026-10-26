#include "../include/iter.hpp"

template <typename T>
void printElement(T const &x)
{
    std::cout << x << std::endl;
}

void increment(int &x)
{
    ++x;
}
int main()
{
    std::cout << "==== Int array ====" << std::endl;
    int tab[] = {0, 1, 2, 3, 4};
    std::size_t len = 5;

    std::cout << "Original:" << std::endl;
    ::iter(tab, len, printElement<int>);
    ::iter(tab, len, increment);

    std::cout << "After increment:" << std::endl;
    ::iter(tab, len, printElement<int>);
    
    std::cout << "==== Const int array ====" << std::endl;
    int const tabConst[] = {10, 20, 30, 40, 50};
    std::size_t lenConst = 5;
    ::iter(tabConst, lenConst, printElement<int>);

    std::cout << "==== String array ====" << std::endl;
    std::string tabStr[] = {"hello", "world", "42", "CPP"};
    std::size_t lenStr = 4;
    ::iter(tabStr, lenStr, printElement<std::string>);
    return 0;
}
