#include <vector>
#include <list>
#include "../include/easyfind.hpp"

int main()
{

    std::cout << "=== Test wit std::vector ===" << std::endl;
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    try
    {
        int res = easyfind(v, 30);
        std::cout << "Valeur trouvée dans vector: " << res << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        int res = easyfind(v, 99);
        std::cout << "Valeur trouvée dans vector: " << res << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    

    std::cout << "=== Test avec std::list ===" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);

    try
    {
        int res = easyfind(lst, 5);
        std::cout << "Valeur trouvée dans list: " << res << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
        {
        int res = easyfind(lst, 42);
        std::cout << "Valeur trouvée dans list: " << res << std::endl;
    }
    catch (std::exception const &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
