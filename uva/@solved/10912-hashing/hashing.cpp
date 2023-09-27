#include <bits/stdc++.h>
#define INF 1e9
#define LLINF 4e18
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

// c: current char to consider
// L: number of chars left to add
// S: sum needed
// dp[L][S][c] = dp[L - 1][S - c][c + 1] + dp[L][S][c + 1]
// base cases:
//      - dp[0][S != 0][c] = 0
//      - dp[0][0][c] = 1
//      - dp[L != 0][0][c] = 0
int dp[30][500][26];

int count(int L, int S, int c) {
    if (L == 0 && S == 0) return 1;
    if (L == 0 && S != 0 || L != 0 && S == 0) return 0;
    if (L > 26 || S > 351 || c > 25) return 0;
    if (dp[L][S][c] != -1) return dp[L][S][c];
    if (S - c > 0) {
        return dp[L][S][c] = count(L - 1, S - c - 1, c + 1) + count(L, S, c + 1);
    } else {
        return dp[L][S][c] = count(L, S, c + 1);
    }
}

int main() {
    int L, S, c = 0;
    memset(dp, -1, sizeof(dp));
    while (cin >> L >> S && (L + S) != 0) {
        printf("Case %d: %d\n", ++c, count(L, S, 0));
    }
    return 0;
}