#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

bool vpu_comparator(std::pair<int, int> a, std::pair<int, int> b) {
    double vpu_a = a.first / double(a.second),
           vpu_b = b.first / double(b.second);
    return vpu_a > vpu_b;
}

double fractional_knapsack(int total_wt,
                           std::vector<std::pair<int, int>> items) {
    double total_val = 0;
    int idx = 0;
    std::sort(items.begin(), items.end(), vpu_comparator);
    while (idx < items.size()) {
        int val = items[idx].first, wt = items[idx].second;
        double vpu = val / double(wt);
        int wt_to_subtract = std::min(total_wt, wt);
        total_val += vpu * wt_to_subtract;
        total_wt -= wt_to_subtract;
        idx++;
        if (total_wt == 0) break;
    }
    return total_val;
}

int main() {
    int n, W;
    std::cin >> n >> W;
    std::vector<std::pair<int, int>> items(n);
    for (int i = 0; i < n; i++) {
        int val, wt;
        std::cin >> val >> wt;
        items[i] = std::make_pair(val, wt);
    }
    std::cout << std::fixed << std::setprecision(4)
              << fractional_knapsack(W, items) << std::endl;
    return 0;
}
