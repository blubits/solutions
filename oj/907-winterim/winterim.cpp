#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int n, k;

int distances[601];
int memo[601][301];

int dp(int posn, int days_travelled) {
    cout << posn << " " << days_travelled << endl;
    if (posn == n) return 0;
    if (days_travelled == k) {
        int sum = 0;
        // Sum up all distances
        for (int i = posn; i < n; ++i)
            sum += distances[i];
        return sum;
    }
    if (memo[posn][days_travelled] != -1) return memo[posn][days_travelled];
    int best = INF, curr = distances[posn];
    for (int next_posn = posn + 1; next_posn <= n; next_posn++) {
        cout << best << " " << curr << " " << next_posn << endl;
        best = min(
            best,
            max(curr, dp(next_posn, days_travelled + 1))
        );
        curr += distances[next_posn];
    }
    return memo[posn][days_travelled] = best;
}

int main() {
    while (cin >> n >> k) {
        memset(memo, -1, sizeof memo);
        for (int i = 0; i <= n; i++) cin >> distances[i];
        cout << dp(0, 0) << endl;
    }
    return 0;
}