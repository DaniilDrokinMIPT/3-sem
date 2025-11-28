#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

int sumFromString(const std::string& str) {
    if (str.empty() || str.front() != '[' || str.back() != ']') {
        throw std::invalid_argument("Invalid string format");
    }

    std::string content = str.substr(1, str.size() - 2);

    if (content.empty()) {
        return 0;
    }

    std::stringstream ss(content);
    std::string token;
    int sum = 0;

    while (std::getline(ss, token, ',')) {
        token.erase(0, token.find_first_not_of(" \t"));
        token.erase(token.find_last_not_of(" \t") + 1);

        try {
            sum += std::stoi(token);
        } catch (const std::exception& e) {
            throw std::invalid_argument("Invalid number in string");
        }
    }

    return sum;
}

int main() {
    try {
        std::cout << sumFromString("[10, 20, 30, 40, 50]") << std::endl;
        std::cout << sumFromString("[4, 8, 15, 16, 23, 42]") << std::endl;
        std::cout << sumFromString("[20]") << std::endl;
        std::cout << sumFromString("[]") << std::endl;
        // Тест с ошибкой
        std::cout << sumFromString("[10, 20, abc]") << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
