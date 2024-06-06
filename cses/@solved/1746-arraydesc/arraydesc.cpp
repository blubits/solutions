#include <bits/stdc++.h>
#define LSOne(S) ((S) & (-S))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;
const ll MOD = (1e9) + 7;

vector<int> v;
ll dp[100010][110];
int main() {
    int n, m;
    cin >> n >> m;
    v.resize(n);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) cin >> v[i];
    if (v[0] == 0) {
        for (int i = 1; i <= m; i++) dp[0][i] = 1;
    } else {
        dp[0][v[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (v[i] == 0) {
            for (int val = 1; val <= m; val++) {
                dp[i][val] += dp[i - 1][val];
                if (val - 1 > 0) dp[i][val] += dp[i - 1][val - 1];
                if (val + 1 <= m) dp[i][val] += dp[i - 1][val + 1];
                dp[i][val] %= MOD;
            }
        } else {
            dp[i][v[i]] += dp[i - 1][v[i]];
            if (v[i] - 1 > 0) dp[i][v[i]] += dp[i - 1][v[i] - 1];
            if (v[i] + 1 <= m) dp[i][v[i]] += dp[i - 1][v[i] + 1];
            dp[i][v[i]] %= MOD;
        }
    }
    ll ans = 0;
    for (int val = 1; val <= m; val++) {
        ans += dp[n - 1][val];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}