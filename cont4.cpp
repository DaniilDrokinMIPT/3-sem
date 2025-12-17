#include <iostream>
#include <map>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::map<int, int> frequency;
    std::vector<int> order;

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        if (frequency[num] == 0) {
            order.push_back(num);
        }
        frequency[num]++;
    }

    for (size_t i = 0; i < order.size(); ++i) {
        std::cout << order[i];
        if (i != order.size() - 1) std::cout << " ";
    }
    std::cout << "\n";

    for (size_t i = 0; i < order.size(); ++i) {
        std::cout << frequency[order[i]];
        if (i != order.size() - 1) std::cout << " ";
    }
    std::cout << "\n";

    return 0;
}
