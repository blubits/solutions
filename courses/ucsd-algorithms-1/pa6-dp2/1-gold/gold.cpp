#include <algorithm>
#include <iostream>

using namespace std;

int max_val[10010][310];
int bars[310];

int knapsack(int W, int n) {
    if (max_val[W][n] != -1) {
        return max_val[W][n];
    }
    if (W - bars[n] >= 0) {
        max_val[W][n] = std::max(knapsack(W, n - 1),
                                 knapsack(W - bars[n], n - 1) + bars[n]);
    } else {
        max_val[W][n] = knapsack(W, n - 1);
    }

    return max_val[W][n];
}

int main() {
    int W, n;
    std::cin >> W >> n;

    for (int i = 0; i <= W; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                max_val[i][j] = 0;
            else
                max_val[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; i++) std::cin >> bars[i];
    std::cout << knapsack(W, n) << std::endl;
}
