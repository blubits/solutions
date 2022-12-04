#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

int n;
int seq[201], lis_dp[201], pred[201];

void lis() {
    lis_dp[0] = 1;
    pred[0] = -1;
    for (int i = 1; i < n; i++) {
        int best_j = -1, best_lis = 1;
        for (int j = 0; j < i; j++) {
            if (seq[j] < seq[i] &&
                (best_lis < lis_dp[j] + 1 ||
                 (best_lis == lis_dp[j] + 1 && seq[best_j] > seq[j]))) {
                best_j = j;
                best_lis = lis_dp[j] + 1;
            }
        }
        lis_dp[i] = best_lis;
        pred[i] = best_j;
    }
}

int main() {
    while (scanf("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++) scanf("%d", &seq[i]);
        lis();
        int ans = 0, ans_i = 0;
        for (int i = 0; i < n; i++) {
            if (lis_dp[i] > ans || (lis_dp[i] == ans && seq[i] < seq[ans_i])) {
                ans = lis_dp[i];
                ans_i = i;
            }
        }
        stack<int> sequence;
        int p = ans_i;
        while (p != -1) {
            sequence.push(seq[p]);
            p = pred[p];
        }
        printf("%d", ans);
        while (!sequence.empty()) {
            printf(" %d", sequence.top());
            sequence.pop();
        }
        printf("\n");
    }
}
