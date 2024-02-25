#include <bits/stdc++.h>
#define LSOne(S) ((S) & -(S))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

double dist[10][10];
int x[10], y[10];

double memo[10][512];
int nextv[10][512];

int fullmask = 0;

double tsp(int u, int mask) {
    if (mask == 0) return 0;
    double &ans = memo[u][mask];
    if (ans != -1) return ans;
    ans = INF;
    int m = mask;
    while (m) {
        int two_pow_v = LSOne(m);
        int v = __builtin_ctz(two_pow_v);
        double val = INF;
        if (mask == fullmask) {
            val = tsp(v, mask ^ two_pow_v);
        } else {
            val = dist[u][v] + tsp(v, mask ^ two_pow_v);
        }
        if (ans > val) {
            ans = val;
            nextv[u][mask] = v;
        }
        m -= two_pow_v;
    }
    return ans;
}

int main() {
    int T;
    int cs = 0;
    while (cin >> T && T) {
        fill(&memo[0][0], &memo[0][0] + 10*512, -1);
        for (int i = 0; i < T; i++) {
            cin >> x[i] >> y[i];
        }
        for (int i = 0; i < T; i++) {
            for (int j = 0; j < T; j++) {
                dist[i][j] = hypot(x[j] - x[i], y[j] - y[i]) + 16;
            }
        }
        fullmask = (1 << T) - 1;
        double ans = tsp(0, (1 << T) - 1);
        int sv = 0, n = 0, smask = (1 << T) - 1;
        printf("**********************************************************\n");
        printf("Network #%d\n", ++cs);
        vector<int> sequence;
        while (smask) {
            n = nextv[sv][smask];
            sequence.push_back(n);
            sv = n;
            smask = smask ^ (1 << n);
        }
        for (int i = 0; i < sequence.size() - 1; i++) {
            int idx = sequence[i], idx_next = sequence[i + 1];
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", x[idx], y[idx], x[idx_next], y[idx_next], dist[idx][idx_next]);
        }
        printf("Number of feet of cable required is %.2f.\n", ans);
    }    
    return 0;
}