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

int N;
vector<int> color;

int memo[310][310];

int dp(int i, int j) {
    if (memo[i][j] != -1) return memo[i][j];
    if (i == j) return memo[i][j] = 1;
    int ans = INF;
    for (int k = i; k < j; k++) {
        ans = min(ans, dp(i, k) + dp(k + 1, j));
    }
    return memo[i][j] = ans - (color[i] == color[j]);
}

int main() {
    cin >> N;
    color.resize(N);
    for (int i = 0; i < N; i++) cin >> color[i];
    fill_n(&memo[0][0], sizeof(memo) / sizeof(memo[0][0]), -1);
    cout << dp(0, N - 1) << endl;
    return 0;
}