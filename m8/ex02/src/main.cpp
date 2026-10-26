// main.cpp
#include "../include/MutantStack.hpp"
#include <list>

int main() 
{
    std::cout << "=== Test MutantStack ===" << std::endl;

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    std::cout << "Iterating MutantStack:" << std::endl;
    while (it != ite) 
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << std::endl;

    std::cout << "=== Test avec std::list (comparaison) ===" << std::endl;

    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(17);
    std::cout << "Back: " << lst.back() << std::endl;

    lst.pop_back();
    std::cout << "Size after pop: " << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator itList = lst.begin();
    std::list<int>::iterator iteList = lst.end();

    ++it;
    --it;

    std::cout << "Iterating std::list:" << std::endl;
    while (itList != iteList) 
    {
        std::cout << *itList << std::endl;
        ++itList;
    }
    std::list<int> lst_copy(lst);
    return 0;
}
