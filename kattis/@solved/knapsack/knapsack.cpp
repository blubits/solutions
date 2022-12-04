#include <algorithm>
#include <cstdio>
#include <iostream>
#define INF 1000000000

using namespace std;

int n;
int val[2010], wt[2010];
int knap_dp[2010][2010];
int l_ans = 0;
int ans[2010];

int knapsack(int id, int w) {
    //
    // K[i][w] = max value considering first i items and a weight of w.
    //
    // We set K[0][w] to blank and K[i][w] to the first i items
    // instead of assigning K[0][w] to the first item
    // to lessen the number of cases ("excluding" the first item doesn't
    // need additional cases na).
    //
    // This assumes that the values and items are stored in w[1...n].
    for (int i = n; i >= 0; i--) {
        for (int j = 0; j <= w; j++) {
            if (j == 0 || i == n)
                knap_dp[i][j] = 0;
            else if (j < wt[i])
                knap_dp[i][j] = knap_dp[i + 1][j];
            else
                knap_dp[i][j] = max(knap_dp[i + 1][j],
                                    val[i] + knap_dp[i + 1][j - wt[i]]);
        }
    }
    return knap_dp[0][w];
}

int main() {
    double cap;
    while (scanf("%lf %d", &cap, &n) == 2) {
        int w = int(cap);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &val[i], &wt[i]);
        }
        for (int i = 0; i < 2010; i++) {
            for (int j = 0; j < 2010; j++) {
                knap_dp[i][j] = -1;
            }
        }
        int r = knapsack(0, w), wr = w;

        l_ans = 0;
        for (int i = 0; i < n && r > 0; i++) {
            if (r == knap_dp[i + 1][wr])
                continue;
            else {
                ans[l_ans++] = i;
                r = r - val[i];
                wr = wr - wt[i];
            }
        }
        printf("%d\n", l_ans);
        for (int i = l_ans - 1; i >= 0; i--) {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
}
