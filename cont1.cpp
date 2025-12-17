#include <iostream>
#include <list>

void josephus(int n, int m) {
    std::list<int> warriors;
    for (int i = 1; i <= n; ++i) {
        warriors.push_back(i);
    }

    auto it = warriors.begin();
    while (warriors.size() > 1) {
        for (int i = 1; i < m; ++i) {
            ++it;
            if (it == warriors.end()) {
                it = warriors.begin();
            }
        }
        std::cout << *it << " ";
        it = warriors.erase(it);
        if (it == warriors.end()) {
            it = warriors.begin();
        }
    }
    std::cout << "\n" << warriors.front() << "\n";
}

int main() {
    int n, m;
    while (std::cin >> n >> m) {
        josephus(n, m);
    }
    return 0;
}
