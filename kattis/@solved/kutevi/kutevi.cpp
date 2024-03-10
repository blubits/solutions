#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

vector<int> degrees;
int memo[400];

int dp(int deg) {
    if (memo[deg] != -1) return memo[deg];
    memo[deg] = 1;
    for (auto d: degrees) {
        dp((deg + d) % 360);
        dp((((deg - d) % 360) + 360) % 360);
    }
    return memo[deg];
}

int main() {
    int n, k;
    cin >> n >> k;
    degrees.resize(n);
    for (int i = 0; i < n; i++) cin >> degrees[i];
    memset(memo, -1, sizeof(memo));
    dp(0);
    for (int i = 0; i < k; i++) {
        int deg;
        cin >> deg;
        if (memo[deg] == 1) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}