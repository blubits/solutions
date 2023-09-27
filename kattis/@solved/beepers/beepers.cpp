#include <bits/stdc++.h>
#define INF 1e9
#define LLINF 4e18
#define LSOne(S) ((S) & -(S))

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

vector<ii> positions;
int dist_matrix[20][20];
int memo[20][2000];

int dist(ii p1, ii p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int tsp(int u, int mask) {
    if (mask == 0) return dist_matrix[u][0];
    int &ans = memo[u][mask];
    if (ans != -1) return ans;
    ans = 2000000000;
    int m = mask;
    while (m) {
        int two_pow_v = LSOne(m);
        // but this is fast
        int v = __builtin_ctz(two_pow_v)+1;
        // offset v by +1
        ans = min(ans, dist_matrix[u][v] + tsp(v, mask^two_pow_v)); // keep the min
        m -= two_pow_v;
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        positions.clear();
        memset(memo, -1, sizeof memo);
        int i, j;
        cin >> i >> j; // irrelevant
        cin >> i >> j;
        positions.push_back({i, j});
        int b;
        cin >> b;
        for (int a = 0; a < b; a++) {
            cin >> i >> j;
            positions.push_back({i, j});
        }
        for (int i = 0; i < positions.size(); i++) {
            for (int j = 0; j < positions.size(); j++) {
                dist_matrix[i][j] = dist(positions[i], positions[j]);
            }
        }
        cout << tsp(0, (1 << b) - 1) << endl;
    }
    
    return 0;
}