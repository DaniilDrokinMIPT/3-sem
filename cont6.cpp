#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <utility>

template<typename Container>
auto make_pairs(const Container& container) {
    using ValueType = typename Container::value_type;
    std::vector<std::pair<ValueType, ValueType>> result;

    auto it = container.begin();
    while (it != container.end()) {
        ValueType first = *it;
        ++it;

        if (it != container.end()) {
            result.emplace_back(first, *it);
            ++it;
        } else {
            result.emplace_back(first, ValueType());
        }
    }

    return result;
}

int main() {

    std::vector<int> vec = {10, 20, 30, 40, 50};
    auto pairs1 = make_pairs(vec);
    std::cout << "Vector test:\n";
    for (const auto& p : pairs1) {
        std::cout << "{" << p.first << ", " << p.second << "} ";
    }
    std::cout << "\n\n";

    std::list<std::string> lst = {"cat", "dog", "mouse", "lion"};
    auto pairs2 = make_pairs(lst);
    std::cout << "List test:\n";
    for (const auto& p : pairs2) {
        std::cout << "{\"" << p.first << "\", \"" << p.second << "\"} ";
    }
    std::cout << "\n\n";

    std::string str = "Hello";
    auto pairs3 = make_pairs(str);
    std::cout << "String test:\n";
    for (const auto& p : pairs3) {
        std::cout << "{" << p.first << ", " << (p.second == '\0' ? "\\0" : std::string(1, p.second)) << "} ";
    }
    std::cout << "\n";

    return 0;
}
