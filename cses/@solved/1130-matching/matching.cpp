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

int n;
vector<vi> graph;
vi memo[2];

int dp(int k, int v, int p) {
    if (memo[k][v] != -1) return memo[k][v];
    int ans = 0;
    if (k == 0) {
        for (int n: graph[v]) {
            if (n != p) {
                ans += max(dp(0, n, v), dp(1, n, v));
            }
        }
    } else {
        for (int n: graph[v]) {
            if (n != p) {
                ans = max(
                    ans,
                    dp(0, n, v) + 1 + dp(0, v, p) - max(dp(0, n, v), dp(1, n, v))
                );
            }
        }
    }
    return memo[k][v] = ans;
}

int main() {
    int n;
    cin >> n;
    memo[0].resize(n, -1);
    memo[1].resize(n, -1);
    graph.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        // Root at 0 arbitrarily
    }
    cout << max(dp(0, 0, -1), dp(1, 0, -1)) << endl;
    return 0;
}