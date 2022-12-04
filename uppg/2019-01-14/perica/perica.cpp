#include <algorithm>
#include <cstdio>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    // fast calculate choose
    vector<vector<unsigned long long int>> C(n);
    for (int i = 0; i < n; i++) {
        C[i].resize(50);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= min(i, 49); j++) {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            // printf("C(%d, %d) = %d\n", i, j, C[i][j]);
        }
    }

    vector<unsigned long long int> nums;
    for (int i = 0; i < n; i++) {
        unsigned long long int a;
        scanf("%llu", &a);
        nums.push_back(a);
    }

    int ans = 0;
    sort(nums.begin(), nums.end());
    for (int i = k - 1; i < n; i++) {
        // printf("%d * C(%d, %d) [%d]\n", nums[i], i, k - 1, C[i][k - 1]);
        ans = (ans + ((nums[i] * C[i][k - 1]) % MOD)) % MOD;
    }

    printf("%d\n", ans);
    return 0;
}
