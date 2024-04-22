#include <bits/stdc++.h>
#define LSOne(S) ((S) & (-S))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const double INF = 1e9;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-3;

int n;
double m;

// define dp(mask, i) as the # of seconds it takes to 
// reach i, passing through the other mice in mask
// (where i should also be part of the mask, 
// unlike our tsp definition) 
double dp[1 << 15][15];
vector<double> mpow;
vector<iii> mice;
iii origin = {0, 0, 0};

double dist(iii a, iii b) {
    return hypot(get<1>(b) - get<1>(a), get<0>(b) - get<0>(a));
}

int hidetime(iii mouse) { return get<2>(mouse); }

bool can_eat(double v) {
    for (int mask = 0; mask < (1 << 15); mask++) {
        for (int i = 0; i < 15; i++) {
            dp[mask][i] = INF;
        }
    }
    // base cases:
    // dp({i}, i) = dist to i / velocity
    for (int i = 0; i < n; i++) {
        // note: v = d/t => t = d/v
        double t = dist(mice[i], origin) / v;
        if (t <= get<2>(mice[i]);) dp[(1 << i)][i] = t;
    }

    // in general:
    // dp(set, i) = 
    //     let prev = set \ {i}
    //     for all j in prev s.t. dp(prev, j) != INF:
    //         let cv = v * %^(|set| - 1)
    //         let t = dp(prev, j) + dist(j, i) * cv
    //         if t <= mice[j].time:
    //               dp(set, i) = min(dp(set, i)) 
    for (int mask = 1; mask < (1 << n); mask++) {
        int k = __builtin_popcount(mask);
        int temp_mask = mask;
        // select possible i; i must be in mask
        while (temp_mask) {
            int two_pow_i = LSOne(temp_mask);
            int i = __builtin_ctz(temp_mask);
            int previous = mask ^ two_pow_i;
            int temp_mask_2 = previous;
            while (temp_mask_2) {
                int two_pow_j = LSOne(temp_mask_2);
                int j = __builtin_ctz(temp_mask_2);
                if (dp[previous][j] != INF) {
                    double cv = v * mpow[k - 1];
                    // note: v = d/t => t = d/v
                    double t = dp[previous][j] + (dist(mice[j], mice[i]) / cv);
                    if (t <= get<2>(mice[i])) {
                        dp[mask][i] = min(dp[mask][i], t);
                    }
                }

                temp_mask_2 -= two_pow_j;
            }
            temp_mask -= two_pow_i;
        }
    }

    for (int i = 0; i < n; ++i) {
		if (dp[(1 << n) - 1][i] != INF) { return true; }
	}
    return false;

}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y, s;
        cin >> x >> y >> s;
        mice.push_back({x, y, s});
    }
    cin >> m;
    mpow.resize(n);
    mpow[0] = 1;
    for (int i = 1; i < n; i++) mpow[i] = mpow[i - 1] * m;
    // now do bsta
    double l = 0, r = 1e9;
    while (r - l > EPS) {
        double m = (l + r) / 2;
        if (can_eat(m)) r = m;
        else l = m;
    }
    cout << fixed << setprecision(16) << l << endl;
    return 0;
}