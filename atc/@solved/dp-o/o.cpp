#include <bits/stdc++.h>
#define LSOne(S) ((S) & (-S))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

bool compat[25][25];
int memo[3000000];
int n;

// Fix the male (given a set of still-matchable females S, 
// match male |S| with them.)
int dp(int mask) {
    //cout << bitset<3>(mask) << endl;
    if (mask == 0) return 1;
    int &ans = memo[mask];
    if (ans != -1) return ans;
    ans = 0;
    int i = __builtin_popcount(mask) - 1;
    int temp = mask;
    while (temp) {
        int two_pow_j = LSOne(temp);
        int j = __builtin_ctz(temp);
        // Match male `i` with female `j`.
        if (compat[i][j]) {
            ans = (ans + dp(mask ^ two_pow_j)) % MOD;
        }
        temp -= two_pow_j;
    }
    ans %= MOD;
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> compat[i][j];
        }
    }
    memset(memo, -1, sizeof(memo));
    cout << dp((1 << n) - 1) << endl;
    return 0;
}