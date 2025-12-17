#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::set<int> unique_numbers;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        unique_numbers.insert(num);
    }

    for (int num : unique_numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
