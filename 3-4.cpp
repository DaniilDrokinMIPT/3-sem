#include <iostream>
#include <string>
#include <vector>

int main() {

    int* intObj = new int(123);
    std::cout << *intObj << std::endl;
    delete intObj;


    std::string* stringObj = new std::string("Cats and Dogs");
    std::cout << *stringObj << std::endl;
    delete stringObj;


    int* intArray = new int[5]{10, 20, 30, 40, 50};
    for (int i = 0; i < 5; ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;
    delete[] intArray;

    std::vector<int>* vectorObj = new std::vector<int>{10, 20, 30, 40, 50};
    for (int val : *vectorObj) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    delete vectorObj;

    std::string* stringArray = new std::string[3]{"Cat", "Dog", "Mouse"};
    for (int i = 0; i < 3; ++i) {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;
    delete[] stringArray;

    return 0;
}
