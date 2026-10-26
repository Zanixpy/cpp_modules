#include <string>
#include "../include/Array.hpp"

int main() {
    std::cout << "=== Default constructor ===" << std::endl;
    Array<int> a;
    std::cout << "size of a = " << a.size() << std::endl;

    std::cout << "\n=== Construtor with n size ===" << std::endl;
    Array<int> b(5);
    std::cout << "size of b = " << b.size() << std::endl;
    for (unsigned int i = 0; i < b.size(); i++) {
        b[i] = static_cast<int>(i * 10);
    }
    for (unsigned int i = 0; i < b.size(); i++) {
        std::cout << "b[" << i << "] = " << b[i] << std::endl;
    }

    std::cout << "\n=== Copy constructor ===" << std::endl;
    Array<int> c(b);
    std::cout << "size of c = " << c.size() << std::endl;
    for (unsigned int i = 0; i < c.size(); i++) {
        std::cout << "c[" << i << "] = " << c[i] << std::endl;
    }

    std::cout << "\n Editing c to check if b dont change" << std::endl;
    if (c.size() > 0)
        c[0] = 42;
    std::cout << "b[0] = " << b[0] << std::endl;
    std::cout << "c[0] = " << c[0] << std::endl;

    std::cout << "\n=== Operator= ===" << std::endl;
    Array<int> d;
    d = b;
    std::cout << "size of d = " << d.size() << std::endl;
    for (unsigned int i = 0; i < d.size(); i++) {
        std::cout << "d[" << i << "] = " << d[i] << std::endl;
    }

    std::cout << "\nEditing d to check if b dont change" << std::endl;
    if (d.size() > 1)
        d[1] = 42;
    std::cout << "b[1] = " << b[1] << std::endl;
    std::cout << "d[1] = " << d[1] << std::endl;

    std::cout << "\n=== Test wit std::string ===" << std::endl;
    Array<std::string> s(3);
    s[0] = "hello";
    s[1] = "world";
    s[2] = "!";
    for (unsigned int i = 0; i < s.size(); i++) {
        std::cout << "s[" << i << "] = " << s[i] << std::endl;
    }

    std::cout << "\n=== Test wit out of range (exceptions) ===" << std::endl;
    try {
        std::cout << "b[10] = " << b[10] << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "s[-1] = " << s[static_cast<unsigned int>(-1)] << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
