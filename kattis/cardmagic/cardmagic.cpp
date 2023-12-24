#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

const ll MOD = 1000000009;

ll n, t, k;
ll dp[101][5001];

ll count(ll deck, ll sum) {
    if (deck == n) {
        if (sum == 0) return 1;
        else return 0;
    }
    if (sum == 0) return 0;
    if (dp[deck][sum] != -1) return dp[deck][sum];
    ll ans = 0;
    for (int i = 1; i <= min(k, sum); i++) {
        ans += (count(deck + 1, sum - i) % MOD);
    }
    return dp[deck][sum] = ans % MOD;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> k >> t;
    cout << count(0, t) << endl;
    return 0;
}