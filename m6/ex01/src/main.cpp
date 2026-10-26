// main.cpp

#include <iostream>
#include "../include/Serializer.hpp"

int main() {

    Data data;
    data.n = 42;
    data.str = "Hello 42!";
    data.flag = true;

    std::cout << "Data's memory address : " << &data << std::endl;
    std::cout << "Data's content :" << std::endl;
    std::cout << "  n    = " << data.n << std::endl;
    std::cout << "  str  = " << data.str << std::endl;
    std::cout << "  flag = " << (data.flag ? "true" : "false") << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "\nSerialize value (uintptr_t) : " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);

    std::cout << "\nPtr's memory address : " << ptr << std::endl;
    std::cout << "Ptr's content :" << std::endl;
    std::cout << "  n    = " << ptr->n << std::endl;
    std::cout << "  str  = " << ptr->str << std::endl;
    std::cout << "  flag = " << (ptr->flag ? "true" : "false") << std::endl;

    if (ptr == &data)
        std::cout << "\nOK: they're equal." << std::endl;
    else
        std::cout << "\nERREUR: they're not equal." << std::endl;

    return 0;
}
