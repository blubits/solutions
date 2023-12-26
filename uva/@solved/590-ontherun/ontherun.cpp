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

int memo[11][1000];

int lengths[11][11];
int flights[11][11][31];

int dp(int curr_city, int days_travelled) {
    if (days_travelled == k) {
        return curr_city == n - 1 ? 0 : INF;
    }
    if (memo[curr_city][days_travelled] != -1) {
        return memo[curr_city][days_travelled];
    }
    int ans = INF;
    for (int next_city = 0; next_city < n; next_city++) {
        if (next_city == curr_city) continue;
        int seq_length = lengths[curr_city][next_city];
        int cost = flights[curr_city][next_city][days_travelled % seq_length];
        if (cost == 0) continue;
        ans = min(ans, cost + dp(next_city, days_travelled + 1));
    }
    return memo[curr_city][days_travelled] = ans;
}

int main() {
    int sc = 1;
    while (cin >> n >> k && !(n == 0 && k == 0)) {
        memset(memo, -1, sizeof(memo));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int d;
                cin >> d;
                lengths[i][j] = d;
                for (int k = 0; k < d; k++) {
                    cin >> flights[i][j][k];
                }
            }
        }
        cout << "Scenario #" << sc++ << endl;
        int ans = dp(0, 0);
        if (ans >= INF) {
            cout << "No flight possible." << endl;
        } else {
            cout << "The best flight costs " << ans << "." << endl;
        }
        cout << endl;
    }
    return 0;
}