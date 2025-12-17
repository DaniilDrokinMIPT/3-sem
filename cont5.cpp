#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::set<int> cuts = {0, n};
    std::multiset<int> segments = {n};
    std::vector<int> results;

    for (int i = 0; i < k; ++i) {
        int cut_point;
        std::cin >> cut_point;

        auto it = cuts.upper_bound(cut_point);
        int right = *it;
        int left = *(--it);

        segments.erase(segments.find(right - left));
        segments.insert(cut_point - left);
        segments.insert(right - cut_point);

        cuts.insert(cut_point);

        results.push_back(*segments.rbegin());
    }

    for (size_t i = 0; i < results.size(); ++i) {
        std::cout << results[i];
        if (i != results.size() - 1) std::cout << " ";
    }
    std::cout << "\n";

    return 0;
}
