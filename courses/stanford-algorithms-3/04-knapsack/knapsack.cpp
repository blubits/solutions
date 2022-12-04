#include <algorithm>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const std::pair<T1, T2> &p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int knapsack_helper(
    int i, int W, std::vector<long long int> &wt,
    std::vector<long long int> &val,
    std::unordered_map<std::pair<int, int>, long long int, hash_pair> &mval) {
    auto p = std::make_pair(i, W);
    if (i == 0 || W <= 0) {
        mval[p] = 0;
        // std::cout << i << " " << W << " 0" << std::endl;
        return 0;
    }
    auto pn1 = std::make_pair(i - 1, W);
    if (mval.find(pn1) == mval.end()) {
        mval[pn1] = knapsack_helper(i - 1, W, wt, val, mval);
    }
    if (wt[i - 1] > W) {
        mval[p] = mval[pn1];
    } else {
        auto pn1nW = std::make_pair(i - 1, W - wt[i - 1]);
        if (mval.find(pn1nW) == mval.end()) {
            mval[pn1nW] = knapsack_helper(i - 1, W - wt[i - 1], wt, val, mval);
        }
        mval[p] = std::max(mval[pn1], mval[pn1nW] + val[i - 1]);
    }
    // std::cout << i << " " << W << " " << mval[p] << std::endl;
    return mval[p];
}

int knapsack(int N, int W, std::vector<long long int> &wt,
             std::vector<long long int> &val) {
    std::unordered_map<std::pair<int, int>, long long int, hash_pair> mval;
    return knapsack_helper(N, W, wt, val, mval);
}

int main() {
    std::ifstream infile;
    infile.open("knapsack_big.txt");
    // infile.open("knapsack_big.txt");

    int W, N;
    infile >> W >> N;
    std::vector<long long int> wt(N), val(N);
    for (int i = 0; i < N; i++) {
        infile >> val[i] >> wt[i];
    }
    std::cout << knapsack(N, W, wt, val) << std::endl;
    return 0;
}
