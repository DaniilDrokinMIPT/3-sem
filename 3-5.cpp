#include <iostream>
#include <string>
#include <new>

int main() {
    std::string stackStr = "Cat";
    std::cout << stackStr << std::endl;

    std::string* heapStr = new std::string("Dog");
    std::cout << *heapStr << std::endl;
    delete heapStr;

    char x[sizeof(std::string)];
    std::string* placementStr = new (x) std::string("Elephant");
    std::cout << *placementStr << std::endl;
    placementStr->~basic_string();

    return 0;
}
