#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int interval_point_count(std::vector<std::pair<int, int>> arr, int q) {
    int lo = 0, hi = arr.size() - 1;
    if (q < arr[lo].first) return 0;
    while (lo <= hi) {
        int mid = lo + ((hi - lo) / 2);
        if (arr[mid].first == q) {
            return arr[mid].second;
        } else if (arr[mid].first > q) {
            hi = mid - 1;
        } else if (arr[mid].first < q) {
            lo = mid + 1;
        }
    }
    return arr[hi].second;
}

int main() {
    int Ni, Nq;
    std::cin >> Ni >> Nq;
    std::vector<std::pair<int, int>> intervals(Ni);
    for (int i = 0; i < Ni; i++) {
        int a, b;
        std::cin >> a >> b;
        intervals[i] = std::make_pair(a, b);
    }
    std::vector<std::pair<int, int>> increases(2 * Ni);
    for (int i = 0; i < Ni; i++) {
        increases[2 * i] = std::make_pair(intervals[i].first, 1);
        increases[2 * i + 1] = std::make_pair(intervals[i].second + 1, -1);
    }
    intervals.clear();
    std::sort(increases.begin(), increases.end());
    std::vector<std::pair<int, int>> totals;
    int a = increases[0].first, b = increases[0].second;
    for (int i = 1; i < 2 * Ni; i++) {
        if (increases[i].first != a) {
            totals.push_back(std::make_pair(a, b));
            a = increases[i].first;
        }
        b += increases[i].second;
    }
    totals.push_back(std::make_pair(a, b));
    increases.clear();
    // for (auto p : totals) {
    //     std::cout << p.first << " " << p.second << std::endl;
    // }
    for (int i = 0; i < Nq; i++) {
        int q;
        std::cin >> q;
        std::cout << interval_point_count(totals, q) << " ";
    }
    std::cout << std::endl;
    return 0;
}
