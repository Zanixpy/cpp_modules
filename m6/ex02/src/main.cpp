#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"



Base* generate(void)
{
    Base *ptr = NULL;
    int random = rand() % 3;
    if (random == 0)
        ptr = new A;
    else if (random == 1)
        ptr = new B;
    else if (random == 2)
        ptr = new C;
    return ptr;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type of the object pointed to by p : A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "Type of the object pointed to by p : B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "Type of the object pointed to by p : C\n";
}

void identify(Base& p)
{
    try 
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type of the object reference to by p : A\n" ;
        return;
    } catch (std::exception&) {}
    try 
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type of the object reference to by p : B\n" ;
        return;
    } catch (std::exception&) {}
    try 
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type of the object reference to by p : C\n" ;
        return;
    } catch (std::exception&) {}
}

int main() 
{
    srand(time(0));

    Base* ptr = generate();

    identify(ptr);
    identify(*ptr);

    delete ptr;
    return 0;
}