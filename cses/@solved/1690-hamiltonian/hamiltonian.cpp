#include <bits/stdc++.h>
using namespace std;
 
#define LSOne(S) ((S) & (-S))
 
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;
 
const int MAX_N = 20;
const ll MOD = (ll)1e9 + 7;
 
int n, m;
 
// first state: bitmask representing the cities that I have visited
// second state: the last city i visited (order information, just for the last
// city I visited)
ll dp[1 << MAX_N][MAX_N];
int adj_matrix[MAX_N][MAX_N];
 
// bitmask:
// 9876543210
// 0000000001
 
ll count_paths(int bitmask, int lc) {
    // base case: I am at the first city
    if (bitmask == 1) return 1;
    if (dp[bitmask][lc] != -1) return dp[bitmask][lc];
    // otherwise: I have a partial set of cities visited, and I know the last
    // city visited; iterate through all the possible "second to the last cities"
    // visited
    ll ans = 0;
    // instead of going through each possible city number,
    // simply iterate through all set bits in bitmask using LSOne optimization
    for (int m = bitmask; m; m -= LSOne(m)) {
        int slc = __builtin_ctz(m); // Get the index of the least significant set bit
        // We're using an adjacency matrix to make adjacency checks faster.
        if (slc != lc && adj_matrix[slc][lc]) {
            int bitmask_without_lc = bitmask - (1 << lc);
            // More than one flight can exist between cities.
            // This is not usual for the typical HamPath problem.
            ans += ll(adj_matrix[slc][lc]) * count_paths(bitmask_without_lc, slc);
            ans %= MOD;
        }
    }
    dp[bitmask][lc] = ans;
    return ans;
}

 
int main() {
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    memset(adj_matrix, 0, sizeof(adj_matrix));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj_matrix[u][v]++;
    }
    cout << count_paths((1 << n) - 1, n - 1) << endl;
    return 0;
}